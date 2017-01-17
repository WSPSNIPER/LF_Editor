#include "EvtTestButton.h"

using namespace std;
using namespace LTF;
using namespace gui;


long BUTTON_ID = 0;


EvtTestButton::EvtTestButton(wxWindow* parent, const wxString& label)
    : wxButton(parent, BUTTON_ID, label)
{
    //add a dynamic handler for this button event to button itsself
    Connect(wxEVT_BUTTON,
            wxCommandEventHandler(EvtTestButton::onClickHandler_D));
}


void EvtTestButton(::)onClickHandler_D(wxCommandEvent& event)
{
    wxLogMessage("Step 3 Dynamic");
    event.Skip();
}

void EvtTestButton(::)onClickHandler_S(wxCommandEvent& event)
{
    wxLogMessage("Step 4 bitch");
    event.Skip();
}

