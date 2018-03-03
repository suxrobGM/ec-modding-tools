//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EquipmentEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEquipmentEditorForm1 *EquipmentEditorForm1;
//---------------------------------------------------------------------------
__fastcall TEquipmentEditorForm1::TEquipmentEditorForm1(TComponent* Owner)
	: TForm(Owner)
{
    StringGrid1->Cells[0][0] = "Equipment Name";
	StringGrid1->Cells[1][0] = "Breakthrough";
	StringGrid1->Cells[2][0] = "Hardness";
	StringGrid1->Cells[3][0] = "Armor value";
	StringGrid1->Cells[4][0] = "Defense";
	StringGrid1->Cells[5][0] = "Soft attack";
	StringGrid1->Cells[6][0] = "Hard attack";
	StringGrid1->Cells[7][0] = "Ap attack";
	StringGrid1->Cells[8][0] = "Air attack";
	StringGrid1->Cells[9][0] = "Reliability";
	StringGrid1->Cells[10][0] = "Maximum speed";
	StringGrid1->Cells[11][0] = "Lend lease";
	StringGrid1->Cells[12][0] = "Build cost ic";
	StringGrid1->Cells[13][0] = "Steel,Money";
}
//---------------------------------------------------------------------------
void __fastcall TEquipmentEditorForm1::OpenEquipmentFile1Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		//char symbol[20];
		//AnsiString equipment_txt_file;

		TStringList *text = new TStringList();
		String result = " ";
		text->LoadFromFile("G:\\C++ projects\\ConsoleProjects\\EC_00_army_salw.txt");
		for(int i=0; i < text->Count; i++)
		{
			if(text->Strings[i].Pos("breakthrough = ") !=0)
			result = text->Strings[i].SubString
			(
				text->Strings[i].Pos("breakthrough = ") + 15,
				text->Strings[i].Length() - text->Strings[i].Pos("breakthrough = ")
			);
		}
		StringGrid1->Cells[1][1]=result;
	}
}
//---------------------------------------------------------------------------

