#include "Frame.h"

using namespace std;
using namespace LFE;
using namespace gui;

Frame::Frame(const wxString& title,
             const wxPoint& position,
             const wxSize& size, wxFrame* parent)
    : wxFrame(parent, wxID_ANY, title, position, size),
      _numPush(0),
      _btnDynamic(NULL)
{
   // SetIcon(wxICON(sample));
    wxMenu* menuFile = new wxMenu;

    menuFile->Append(LF_eAbout, wxT("&About\tCtrl-A"), wxT("Show about Dialog"));

    menuFile->AppendSeparator();

    menuFile->Append(LF_eQuit, wxT("E&xit\tAlt-X", wxT("Quit this program"));

    wxMenu* menuEvent = new wxMenu;
    menuEvent->AppendCheckItem(LF_eBind, wxT("&Bind"), wxT("Bind or Ubind");
    menuEvent->AppendCheckItem(LF_eBind, wxT("&Bind"), wxT("Bind or Ubind");
    menuEvent->Append(LF_eDynamic, wxT("&Dynamic event"), wxT("works only after connect"));

    menuEvent->AppendSeparator();

    menuEvent->Append(LF_ePush, wxt("&Push"), wxT("Push evt handler for test event"));
    menuEvent->Append(LF_eTest, wxt("&Test"), wxT("Test event called"));

    menuEvent->AppendSeparator();

    menuEvent->Append(LF_eCustom, wxt("&Custom"), wxT("Generated a custom event"));

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, wxT("&Filw"));
    menuBar->Append(menuEvent, wxT("&Event"));

    SetMenuBar(menuBar);

    CreateStatusBar(3);
    SetStatusText(wxT("Welcome to  wxWidgets events"));
    SetStatusText(wxT("Dynamic: off"), LF_sDynamic);
    SetStatusText(wxT("Push count: 0"), LF_sMain);

    wxPanel* const panel = new wxPanel(this);
    wxSixer* const mainSizer = new wxBoxSizer(wxVERTICAL);
    wxSizer* const sizer = new wxBoxSizer(wxHORIZONTAL);

    const wxSizerFlags centreY(wxSizerFlags().Centre.Border());

    sizer->Add(new wzStaticText(panel, wxID_ANY, "This button  only works dynamically"),
                                centreY);
    _btnDynamic = new wxButton(panel, LF_eDynamic, "&Dynamic Button");
    sizer->Add(_btnDynamic, centreY);

    mainSizer->Add(sizer, 1, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);

    _testBtn = new EvtTestButton(panel, "Test Button");


    Connect(_testBtn->GetId(), wxEVT_BUTTON,
            wxCommentEventHandler(Frame::onClickDynamicFrame));


    _testBtn->Connect(wxEVT_BUTTON,
                      wxCommandEventHandler(Frame::onClickDynamicButton),
                      NULL, this);

    mainSizer->Add(_testBtn);

    panel->SetSizer(mainSizer);

}

Frame::~Frame()
{
    while(_numPush != 0)
    {
        PopEventHandler(true);
        _numPush--;
    }
}



void Frame::_updateDyamicStatus(bool on)
{
    if(on)
    {
        SetStatusText("You can now use \"Dynamic\" item in the menu\n");
        SetStatusText("Dynamic set to: ON ", LF_sDynamic);
    }
    else
    {
        SetStatusText("You can no longer use \"Dynamic\" item in the menu");
        SetStatisText("Dynamic set to: OFF ", LF_sDynamic);
    }
}


///@Socket code is below

void Application::onClickDynamicFrame(wxCommandEvent& event)
{
}
void Application::onClickDynamicButton(wxCommandEvent& event)
{
}
void Application::onClickStaticFrame(wxCommandEvent& event)
{
}

/** ********* EVENT TABLE ******************************************/

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(wxID_EXIT, Frame::onExit)
    EVT_MENU(DO_TEST, Frame::doTest)
    EVT_SIZE(Frame::onSize)
    EVT_BUTTON(BUTTON_ONE, Frame::onButtonOne)
wxEND_EVENT_TABLE()

/** *************************************************************/



/** @SOCKET @onFuckyourself ------------------------------------*/
void Application::onQuit(wxCommandEvent& event)
{
    Close(true);
    event.Skip();
}
void Application::onAbout(wxCommandEvent& event)
{
    wxLogMessage("Go fuck yourself", "Bitch", "FAG",
                 wxOK | wxICON_INFORMATION, this);
                event.Skip();
}
void Application::onBind(wxCommandEvent& event)
{
    if(event.IsChecked())
    {
        _btnDynamic->Bind(wxEVT_BUTTON, &Frame::onDynamic, this);

        Bind(wxEVT_MENU, &Frame::onDynamic, this, LF_eDynamic);
    }
    else
    {
        _btnDynamic->Unbind(wxEVT_BUTTON, &Frame::onDynamic,
                            this);
        Unbind(wxEVT_MENU, &Frame::onDynamic, this, LF_eDynamic);
    }

    _updateDynamicStatus(event.IsChecked());
}
void Application::onConnect(wxCommandEvent& event)
{
    if(event.IsChecked())
    {
        _btnDynamic->Connect(wxID_ANY, wxEVT_BUTTON, wxCommandEventHandler(Frame::onDynamic));
        Connect(LF_eDynamic, wxEVT_MENU, wxCommandEventHandler(Frame::onDynamic));
    }
    else
    {
        _btnDynamic->Disonnect(wxID_ANY, wxEVT_BUTTON,
            wxCommandEventHandler(Frame::onDynamic), NULL, this);

        Disconnect(LF_eDynamic, wxEVT_MENU,
            wxCommandEventHandler(Frame::onDyamic));
    }
    _updateDynamicStatus(event.IsChecked());
}
void Application::onDynamic(wxCommandEvent& event)
{
    wxString origin;
    if(event.GetEventObject()==this)
        origin = "menu item";
    else if(event.GetEventObject() == _btnDynamic)
        origin = "button";
    else
        origin="unknoown";

    wxMessageBox("This MSG box is shown from they dynamically connected "
                "event hadler :" + origin, "wxWidgets Dynamic Event Handling",
                wxOK | wxICON_INFORMATION, this);
    event.Skip();

}
void Application::onPushEventhandler(wxCommandEvent& event)
{
    PushEventHandler(new EventHandler(++_numPush()));
    SetStatusText(wxString::Format(wxT("Push count: %u"), _numPush),
                  LF_sPush);
    event.Skip();
}
void Application::onPopEventhandler(wxCommandEvent& event)
{
    wxCHECK_RET(_numPush, wxT("this command should be disabled"));

    PopEventHandler(true);
    _numPush--;

    SetStatusText(wxString::Format(wxT("Push count: %u"), _numPush),
                  LF_sPush);

    event.Skip();

}
void Application::onTest(wxCommandEvent& event)
{
    wxLogMessage(wxT("FUCFK this shit)"));
    event.Skip();
}
void Application::onSize(wxSizeEvent& event)
{
    /// FIGuret oujt
}
void Application::onFireCustom(wxCommandEvent& event)
{
    wxCommandEvent eventCustom(wxEVT_MY_CUSTOM_COMMAND);
    wxPostEvent(this, eventCustom);
    event.Skip();
}
void Application::onProcessCustom(wxCommandEvent& event)
{
    wxLogMessage(wxT("Got a custom event!"));
    event.Skip();
}
void Application::onUpdateUI_Pop(wxCommandEvent& event)
{
    event.Enable(_numPush > 0);
    //event.Skip();
}
/** @END @SOCKET -----------------------------------------------*/
