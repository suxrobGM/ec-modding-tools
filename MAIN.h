//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include "ChildWin.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>

// File access routines
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
//----------------------------------------------------------------------------

//WSQ image library declaration of functions
typedef int (*RegisterWSQ)();
typedef HBITMAP (*CreateBMPFromFile)( const char *filename);
typedef int (*SaveBMPToFile)(HBITMAP hBitmap, const char *filename, int filetype);
typedef HBITMAP (*CreateBMPFromWSQByteArray)(unsigned char *input_wsq_byte_array, int size_of_input_wsq_byte_array);
typedef int (*SaveWSQByteArrayToImageFile)(unsigned char *input_wsq_byte_array, int size_of_input_wsq_byte_array, const char *filename, int filetype);
typedef int (*SetShowFilePropertiesDialog)(int file_properties_dialog);
typedef int (*ShowFileConverter)();
typedef int (*WSQ_decode_stream)(unsigned char *input_data_stream, const int input_stream_length, unsigned char **output_data_stream, int *width, int *height, int *ppi, char **comment_text);
typedef int (*WSQ_encode_stream)(unsigned char *input_data_stream, const int width, const int height, const double bitrate, const int ppi, char *comment_text, unsigned char **output_data_stream, int *output_stream_length);
typedef HBITMAP (*ConvertHBITMAPtoGrayScale256)(HBITMAP hBitmap);
typedef int (*SaveHBITMAPtoFileAsGrayScale256BMP)(HBITMAP hBitmap, const char *filename);


RegisterWSQ pRegisterWSQ;
CreateBMPFromFile  pCreateBMPFromFile;
SaveBMPToFile  pSaveBMPToFile;
CreateBMPFromWSQByteArray pCreateBMPFromWSQByteArray;
SaveWSQByteArrayToImageFile pSaveWSQByteArrayToImageFile;
SetShowFilePropertiesDialog pSetShowFilePropertiesDialog;
ShowFileConverter pShowFileConverter;
WSQ_decode_stream pWSQ_decode_stream;
WSQ_encode_stream pWSQ_encode_stream;
ConvertHBITMAPtoGrayScale256 pConvertHBITMAPtoGrayScale256;
SaveHBITMAPtoFileAsGrayScale256BMP pSaveHBITMAPtoFileAsGrayScale256BMP;


HINSTANCE hWSQ_library;
//HBITMAP hBitMap; // = NULL;

//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
	TStatusBar *StatusBar;
	TActionList *ActionList1;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TAction *FileNew1;
	TAction *FileSave1;
	TAction *FileExit1;
	TAction *FileOpen1;
	TAction *FileSaveAs1;
	TWindowCascade *WindowCascade1;
	TWindowTileHorizontal *WindowTileHorizontal1;
	TWindowArrange *WindowArrangeAll1;
	TWindowMinimizeAll *WindowMinimizeAll1;
	TAction *HelpAbout1;
	TWindowClose *FileClose1;
	TWindowTileVertical *WindowTileVertical1;
	TMenuItem *WindowTileItem2;
	TToolBar *MainToolBar;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TImageList *StdIconList;
	TMenuItem *Editors1;
	TMenuItem *UnitEditor1;
	TMenuItem *CountryEditor1;
	TMenuItem *Settings1;
	TMenuItem *Option1;
	void __fastcall FileNew1Execute(TObject *Sender);
	void __fastcall FileOpen1Execute(TObject *Sender);
	void __fastcall HelpAbout1Execute(TObject *Sender);
	void __fastcall FileExit1Execute(TObject *Sender);
	void __fastcall UnitEditor1Click(TObject *Sender);
    void __fastcall EuipmentEditor1Click(TObject *Sender);
	void __fastcall CountryEditor1Click(TObject *Sender);
	void __fastcall Option1Click(TObject *Sender);
private:
	void __fastcall CreateMDIChild(const String Name);
public:
	virtual __fastcall TMainForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
extern TMDIChild *__fastcall MDIChildCreate(void);
extern UnicodeString ModDirectory; // глобальный переменный сохраняет путь мода
extern UnicodeString ProgrammPath = ExtractFilePath(ParamStr(0)); //получаем путь к каталогу программы
//----------------------------------------------------------------------------
#endif
