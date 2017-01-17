#ifndef PRECOMPILED_H
#define PRECOMPILED_H

#include <wx/app.h>
#include <wx/statline.h>
#include <wx/log.h>


enum
{
    LF_eQuit = 1,
    LF_eAbout,
    LF_eBind,
    LF_eConnect,
    LF_eDynamic,
    LF_ePush,
    LF_ePop,
    LF_eCustom,
    LE_eTest
};



/* defines a custom event type (will need to make matching call in .cpp file) */
wxDEFINE_EVENT(wxEVT_MY_CUSTOM_COMMAND, wxCommandEvent);


#endif // PRECOMPILED_H

//long LFE::gui::EvtTestButton::BUTTON_ID = wxNewId();
