//---------------------------------------------------------------------------

#ifndef UnitEditorH
#define UnitEditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class TUnitEditorForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Openunitfile1;
	TMenuItem *Createnewunitfile1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TActionList *ActionList1;
	TAction *OpenUnitTxtFile1;
	TAction *NewUnitTxtFile1;
private:	// User declarations
public:		// User declarations
	__fastcall TUnitEditorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUnitEditorForm *UnitEditorForm;
//---------------------------------------------------------------------------
#endif
