#ifndef MAINFRAME_HPP_
#define MAINFRAME_HPP_

#include "dialog.hpp"
#include "modbus.h"
#include "modbus-rtu.h"
#include "modbus-private.h"
#include "modbus-rtu-private.h"


class mainFrame: public wxFrame
{
public:
    mainFrame(const wxString& title);
    void onButExit(wxCommandEvent& event);    
    Dial* d{nullptr};
    uint16_t holdRegs[10]={0};
private:
    void onButConnect(wxCommandEvent& event);
    void onButRead(wxCommandEvent& event);
    void onButWrite(wxCommandEvent& event); 
    wxStaticText* lab1{nullptr};
    wxStaticText* lab2{nullptr};
    wxStaticText* lab3{nullptr};
    wxButton* but{nullptr};
    wxButton* butConnect{nullptr};
    wxButton* but2{nullptr};
    wxButton* but3{nullptr};
    int modbus_init();
    modbus_t* ctx{nullptr};
    int rc{0};

    int modbusConnect();
    int modbusDisconnect();
    bool modbusConnectionFlag{false};
    int modbusRead();

    wxTimer* timer1{nullptr};
    void onTimer1(wxTimerEvent& timEvent);

    DECLARE_EVENT_TABLE()
};
#endif //MAINFRAME_HPP_