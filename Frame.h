#ifndef FRAME_H
#define FRAME_H

#include "EvtTestButton.h"

#include <wx/app.h>


//wxDEFINE_EVENT(wxEVT_MY_CUSTOM_COMMAND, wxCommandEvent);

namespace LFE {
namespace gui {
class Frame : public wxFrame
{
    public:
        Frame(const wxString& title,
              const wxPointt& position,
              const wxSize& size,
              wxFrame* parent = 0);

        virtual ~Frame();

    protected:

    public:
        /** Slots **/
        void onExit(wxCommandEvent& event);
        void onAbout(wxCommandEvent& event);
        void onBind(wxCommandEvent& event);
        void onConnect(wxCommandEvent& event);
        void onDynamic(wxCommandEvent& event);
        void onSize(wxSizeEvent& event);
        void onPushEventhandler(wxCommandEvent&  event);
        void onPopEventhandler(wxCommandEvent& event);
        void onTest(wxCommandEvent& event);

        void onFireCustom(wxCommandEvent& event);
        void onProcessCustom(wxCommandEvent& event);

        void onUpdateUI_Pop(wxUpdateUIEvent& event);

        // regular event handlers used to highlight the events handling order
        void onClickDynamicFrame(wxCommandEvent& event);
        void onClickDynamicButton(wxCommandEvent& event);
        void onClickStaticFrame(wxCommandEvent& event);


    private:
        enum eStatusType
        {
            LF_sMain = 0,
            LF_sDynamic,
            LF_sStatic
        };

        void _updateDynamicStatus(bool isOn);

        /* number of pushed event handlers */
        unsigned _numPush;

        /* the button to whose event we connect dynamically */
        wxButton* _btnDynamic;

        /* the button used to highlight the event handlers execution order */
        EvtTestButton _testBtn;

        wxDECLARE_EVENT_TABLE();
};
}
}
#endif // FRAME_H
