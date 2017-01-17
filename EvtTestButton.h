
#ifndef EVT_TEST_BUTTON_H
#define EVT_TEST_BUTTON_H

#include "Precompiled.h"



namespace LFE
{
namespace gui
{

class EvtTestButton : public wxButton
{
public:
    static long BUTTON_ID;

    EvtTestButton(wxWindow* parent, const wxString& label);
private:
    void onClickHandler_D(wxCommandEvent& event);
    void onClickHandler_S(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

}
}
#endif // EVT_TEST_BUTTON_H
