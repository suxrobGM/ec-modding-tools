//---------------------------------------------------------------------------

#ifndef OptionH
#define OptionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TOptionsForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel;
	TEdit *SetDirEdit;
	TButton *SetDirButton;
	TDirectoryListBox *DirectoryListBox1;
	TComboBox *ChangeLanguage_CB;
	TLabel *DirMod_L;
	TLabel *ChooseLang_L;
    void __fastcall SetDirButtonClick(TObject *Sender);
	void __fastcall ChangeLanguage_CBChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TOptionsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsForm *OptionsForm;
//---------------------------------------------------------------------------
#endif
