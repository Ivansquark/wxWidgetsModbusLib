#include <wx/wx.h>
#include "mainframe.hpp"
class MyApp : public wxApp
{
public:
	virtual bool OnInit()
	{		
		mainFrame *frame = new mainFrame(wxT("opa"));
		frame->Show(true);
		return true;
	}
};
//void (*InterruptManager::IsrVi[10])()={nullptr};
IMPLEMENT_APP(MyApp)

