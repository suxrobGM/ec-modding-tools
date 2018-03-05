//---------------------------------------------------------------------------

#ifndef CountryEditorH
#define CountryEditorH
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
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.FileCtrl.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <VCLTee.Series.hpp>
#include <Vcl.CheckLst.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TCountryEditorForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TActionList *ActionList1;
	TOpenTextFileDialog *OpenTextFileDialog;
	TMenuItem *File1;
	TMenuItem *OpenCountryFile1;
	TMenuItem *NewCountryFile1;
	TAction *NewCountryFile;
	TAction *OpenCountryFile;
	TValueListEditor *UniqueValueListEdit;
	TFileListBox *FileListBox1;
	TImage *BigFlagImg;
	TButtonGroup *ChooseScenario_B;
	TLabel *ScenarioLabel;
	TPanel *MainPanel;
	TPanel *Panel;
	TLabel *ShowCurrentScenario_L;
	TValueListEditor *LawsListEditor;
	TChart *IdeologyChart;
	TValueListEditor *PoliticsListEditor;
	TLabel *ShowPolitics_L;
	TButton *DrawGraphButton;
	TButton *ClearGraphButton;
	TPieSeries *IdeologiesSeries;
	TTeeGDIPlus *TeeGDIPlus1;
	TListBox *CountryListBox;
	TImageList *FlagImgList;
	TOpenPictureDialog *OpenPictureDialog;
	TToolBar *CEditorToolBar;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TImage *MediumFlagImg;
	TImage *SmallFlagImg;
    TLabel *FlagName_L;
	TAction *SaveCountryFile;
	void __fastcall OpenCountryFileExecute(TObject *Sender);
	void __fastcall GetTags();
	void __fastcall GetRegions();
	void __fastcall GetTechLevel();
	void __fastcall GetCountryLevel();
	void __fastcall GetFOGList();
	void __fastcall GetPSList();
	void __fastcall GetCorruptionLevel();
	void __fastcall GetEUIntegrationLevel();
	void __fastcall GetReligionLaws();
	void __fastcall GetMassMediaLaws();
	void __fastcall GetCivilLibertiesLaws();
	void __fastcall GetMobilizationLaws();
	void __fastcall GetSchoolSystemLaws();
	void __fastcall GetImmigrationLaws();
	void __fastcall GetEconomicMobLaws();
	void __fastcall GetEconomyLaws();
	void __fastcall GetTradeLaws();
	void __fastcall GetMarketLaws();
	void __fastcall GetIndustryFocusLaws();
	void __fastcall GetTaxesLaws();
	void __fastcall GetSocialSecLaws();
	void __fastcall GetLaborRightsLaws();
	void __fastcall GetIdeologies();
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall DrawGraphButtonClick(TObject *Sender);
	void __fastcall ClearGraphButtonClick(TObject *Sender);
	void __fastcall CountryListBoxDblClick(TObject *Sender);
	void __fastcall ReadFileData(UnicodeString CountryFileName);
	//void __fastcall WriteFileData(UnicodeString CountryFileName);
    void __fastcall InsertFileData(UnicodeString CountryFileName);
	void __fastcall BigFlagImgDblClick(TObject *Sender);
	void __fastcall LoadFlag(AnsiString TagName, AnsiString RulingParty);
	void __fastcall PoliticsListEditorValidate(TObject *Sender, int ACol, int ARow,
          const UnicodeString KeyName, const UnicodeString KeyValue);
	void __fastcall NewCountryFileExecute(TObject *Sender);
    void __fastcall ClearAllData();
	void __fastcall SaveCountryFileExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCountryEditorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCountryEditorForm *CountryEditorForm;
//---------------------------------------------------------------------------
#endif
