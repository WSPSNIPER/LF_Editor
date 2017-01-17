#include "Application.h"

using namespace std;
using namespace LFE;
using namespace gui;

Application::Application(wxApp* parent)
{

}

Application::~Application()
{
    //dtor
}


bool Application::OnInit()
{
    if(!wxApp::OnInit())
        return false;
    Frame* window = new Frame(wxT("wxWidgets Learning"), wxPoint(145,145),
                              wxSize(800,600), NULL);

    window->Show(true);

    Connect(EvtTestButton::BUTTON_ID, wxEVT_BUTTON,
            wxCommandEventHandler(Application::onClickDynamicFrame));
    return true;
}

int Application::FillerEvent(wxEvent& event)
{
    if(event.GetEventType() == wxEVT_BUTTON &&
       event.GetId() == EvtTestButton::BUTTON_ID)
    {
        wxLogMessage("Step 0: Application::FilterEvent)");
    }
    return wxApp::FilterEvent(event);
}

void Application::onClickDynamicButton(wxCommandEvent& event)
{
    wxLogMessage("Step 7: Application::Dynamic Handler in Application Table");
    event.Skip();
}

void Application::onClickStaticFrame(wxCommandEvent& event)
{
    wxLogMessage("Button click processed, no  more messages about"
                 "Event Handling \n\n");
    wxLog::FlushActive();
    event.Skip();
}

/** EVENT TABLES BEING CALLED HERE **********************************/

/** @BEGIN @TABLE ----------------------------------**/
wxBEGIN_EVENT_TABLE(Application, wxApp)
    EVT_BUTTON(EvtTestButton::BUTTON_ID, Application::onClassStaticHandlerApp)
wxEND_EVENT_TABLE()
/** @END @TABLE  ------------------------------------**/



/** @Begin @Table ------------------------------------**/
wxBEGIN_EVENT_TABLE(EvtTestButton, wxButton)
    EVT_BUTTON(LFE::gui::EvtTestButton::BUTTON_ID,EvtTestButton::onClickHandler_S)
wxEND_EVENT_TABLE()
/** @End @Table --------------------------------------**/



/** @Begin @Table ------------------------------------**/
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(LF_eQuit, Frame::onQuit)
    EVT_MENU(LF_eQuit, Frame::onAbout)

    EVT_MENU(LF_eQuit, Frame::onBind)
    EVT_MENU(LF_eQuit, Frame::onConnect)

    EVT_MENU(LF_eQuit, Frame::onDynamic)
    EVT_MENU(LF_eQuit, Frame::onPushEventhandler)
    EVT_MENU(LF_eQuit, Frame::onPopEventhandler)
    EVT_MENU(LF_eQuit, Frame::onTest)

    EVT_SIZE(Frame::onSize)

    EVT_UPDATE_UI(LF_ePop, Frame::onUpdateUI_Pop)

    EVT_MY_CUSTOM_COMMAND(wxID_ANY, Frame::onProcessCustom)

    EVT_BUTTON(EvtTestButton::BUTTON_ID, Frame::onClickStaticFrame)
wxEND_EVENT_TABLE()
/** @End @Table --------------------------------------**/



/** @Begin @Table ------------------------------------**/
wxBEGIN_EVENT_TABLE(EventHandler, wxEvtHandler)
    EVT_MENU(LF_eTest, EventHandler::onTest)
wxEND_EVENT_TABLE()
/** @End @Table --------------------------------------**/
/** ******************************************************************/

IMPLEMENT_APP(Application)
