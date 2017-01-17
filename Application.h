#ifndef APPLICATION_H
#define APPLICATION_H

#include "Frame.h"

namespace LFE{
namespace gui{

class Application : public wxApp
{
public:
    Application(wxApp* parent = 0);
    virtual ~Application();

    virtual bool OnInit() wxOVERRIDE;
    virtual int FilterEvent(wxEvent& event) wxOVERRIDE;

    /* regular event handlers used to highlight the events
          handling order */
    void onClickDynamicHandlerApp(wxCommandEvent& event);
    void onClickStaticHandlerApp(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();
};

}
}
#endif // APPLICATION_H
