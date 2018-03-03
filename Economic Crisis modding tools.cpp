//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------
USEFORM("MAIN.CPP", MainForm);
USEFORM("EquipmentEditor.cpp", EquipmentEditorForm1);
USEFORM("UnitEditor.cpp", UnitEditorForm);
USEFORM("CHILDWIN.CPP", MDIChild);
USEFORM("about.cpp", AboutBox);
USEFORM("CountryEditor.cpp", CountryEditorForm);
USEFORM("Option.cpp", OptionsForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TUnitEditorForm), &UnitEditorForm);
		Application->CreateForm(__classid(TEquipmentEditorForm1), &EquipmentEditorForm1);
		Application->CreateForm(__classid(TCountryEditorForm), &CountryEditorForm);
		Application->CreateForm(__classid(TOptionsForm), &OptionsForm);
		Application->Run();
	return 0;
}
//---------------------------------------------------------------------
