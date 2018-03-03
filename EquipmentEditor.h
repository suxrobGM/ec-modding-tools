//---------------------------------------------------------------------------

#ifndef EquipmentEditorH
#define EquipmentEditorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TEquipmentEditorForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TActionList *ActionList1;
	TMenuItem *File1;
	TAction *CreateNewEquipmentFile1;
	TAction *OpenEquipmentFile1;
	TMenuItem *CreateNewEquipmentFile2;
	TMenuItem *OpenEquipmentFile2;
	TStringGrid *StringGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit1;
	void __fastcall OpenEquipmentFile1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TEquipmentEditorForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEquipmentEditorForm1 *EquipmentEditorForm1;
//---------------------------------------------------------------------------
#endif
