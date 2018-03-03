//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include "EquipmentEditor.h"
#include "UnitEditor.h"
#include "CountryEditor.h"
#include "Option.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TMainForm *MainForm;
UnicodeString ModDirectory; // глобальный переменный сохраняет путь мода из main.h

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::CreateMDIChild(String Name)
{
	TMDIChild *Child;

	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = Name;
	if (FileExists (Name))
		Child->Memo1->Lines->LoadFromFile(Name);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
	if (OpenDialog->Execute())
		CreateMDIChild(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EuipmentEditor1Click(TObject *Sender)
{
	EquipmentEditorForm1->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::UnitEditor1Click(TObject *Sender)
{
    UnitEditorForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CountryEditor1Click(TObject *Sender)
{
	CountryEditorForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Option1Click(TObject *Sender)
{
	OptionsForm->ShowModal();
}
//---------------------------------------------------------------------------
