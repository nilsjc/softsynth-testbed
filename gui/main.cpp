#include "wx/wx.h"
#include "wx/slider.h"
#include <wx/event.h>
#include <iostream>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);


private:
    void OnSlChanged(wxCommandEvent &event);
    wxStaticText *label10 = new wxStaticText(this, 20010, "50");
    wxSlider* sliders[8]={
        new wxSlider(this,10001,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10002,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10003,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10004,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10005,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10006,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10007,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator),
        new wxSlider(this,10008,50,1,100,wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL, wxDefaultValidator)
    };
};

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxGridSizer *grid = new wxGridSizer(3, 8, 0, 0);

    // bind sliders to function
    for(int x=0; x <8; x++)
    {
        sliders[x]->Bind(wxEVT_SLIDER, &MyFrame::OnSlChanged, this);
    }
    
    // add sliders to grid
    for(int x=0; x <8; x++)
    {
        grid->Add(sliders[x],1, wxEXPAND | wxALL);
    }

    grid->Add(new wxStaticText(this, 20008, "input"));
    grid->Add(new wxStaticText(this, 20002, "diffuse"));
    grid->Add(new wxStaticText(this, 20003, "length"));
    grid->Add(new wxStaticText(this, 20004, "damp"));
    grid->Add(new wxStaticText(this, 20005, "random"));
    grid->Add(new wxStaticText(this, 20006, "pitch"));
    grid->Add(new wxStaticText(this, 20007, "one"));
    grid->Add(new wxStaticText(this, 20008, "two"));

    grid->Add(new wxStaticText(this, 20008, "Value:"));
    grid->Add(label10, 1, wxEXPAND | wxALL);

    this->SetSizer(grid);
    grid->Layout();

}

void MyFrame::OnSlChanged(wxCommandEvent &event)
{
    int value = sliders[(event.GetId() - 10001)]->GetValue();
    label10->SetLabel(std::to_string(value));
    event.Skip();
}


class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Experimental audio...", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
