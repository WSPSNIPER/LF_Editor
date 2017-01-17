
#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Precompiled.h"

class EventHandler : public wxEvtHandler
{
public:
    EventHandler(size_t level)
        : _level(level) {}

    void onTest(wxCommandEvent& event)
    {
        wxLogMessage(wxT("This is the pushed test event handler \n"));
        event.Skip();
    }
private:
    unsigned _level;

    wxDECLARE_EVENT_TABLE();
};

#endif // EVENT_HANDLER_H
