//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "CountryEditor.h"
#include "Option.h"

#include "fstream"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TCountryEditorForm *CountryEditorForm;

/** Lists */
TStringList *TagList = new TStringList(); //Список тегов
TStringList *RegionList = new TStringList(); //Список регионов ("ключ-значение")
TStringList *TechLevelList = new TStringList(); // ("Key-Value")
TStringList *CountryLevelList = new TStringList(); //List of laws such "Country Level" ("Key-Value")
TStringList *FOGList = new TStringList(); //List of laws such "Form of Government" ("Key-Value")
TStringList *PSList = new TStringList(); //List of laws such "Power Structure" ("Key-Value")
TStringList *CorruptionLevelList = new TStringList(); //List of laws such "Corruption Level" ("Key-Value")
TStringList *EULevelList = new TStringList(); //List of laws such "EU Integration Level"  ("Key-Value")
TStringList *ReligionLawsList = new TStringList();
TStringList *MassMediaLawsList = new TStringList();
TStringList *CivilLibertiesLawsList = new TStringList();
TStringList *MobilizationLawsList = new TStringList();
TStringList *SchoolSystemLawsList = new TStringList();
TStringList *ImmigrationLawsList = new TStringList();
TStringList *EconomicMobLawsList = new TStringList();
TStringList *EconomyLawsList = new TStringList();
TStringList *TradeLawsList = new TStringList();
TStringList *MarketLawsList = new TStringList();
TStringList *IndustryFocusLawsList = new TStringList();
TStringList *TaxesLawsList = new TStringList();
TStringList *SocialSecLawsList = new TStringList();
TStringList *LaborRightsLawsList = new TStringList();
TStringList *IdeologiesList = new TStringList();


//---------------------------------------------------------------------------
__fastcall TCountryEditorForm::TCountryEditorForm(TComponent* Owner)
	: TForm(Owner)
{

   // returns a handle to the DLL, otherwise NULL
   hWSQ_library = LoadLibrary(L"WSQ_library.dll");

   if (hWSQ_library == NULL)
   {Application->MessageBox( L"Error: WSQ_library.dll not found", L"Error", MB_OK);}
   pRegisterWSQ = (RegisterWSQ) GetProcAddress(hWSQ_library, "_RegisterWSQ");
   pCreateBMPFromFile = (CreateBMPFromFile) GetProcAddress(hWSQ_library, "_CreateBMPFromFile");
   pSaveBMPToFile = (SaveBMPToFile) GetProcAddress(hWSQ_library, "_SaveBMPToFile");
   pCreateBMPFromWSQByteArray = (CreateBMPFromWSQByteArray) GetProcAddress(hWSQ_library, "_CreateBMPFromWSQByteArray");
   pSaveWSQByteArrayToImageFile = (SaveWSQByteArrayToImageFile) GetProcAddress(hWSQ_library, "_SaveWSQByteArrayToImageFile");
   pSetShowFilePropertiesDialog = (SetShowFilePropertiesDialog) GetProcAddress(hWSQ_library, "_SetShowFilePropertiesDialog");
   pShowFileConverter = (ShowFileConverter) GetProcAddress(hWSQ_library, "_ShowFileConverter");
   pWSQ_decode_stream = (WSQ_decode_stream) GetProcAddress(hWSQ_library, "_WSQ_decode_stream");
   pWSQ_encode_stream = (WSQ_encode_stream) GetProcAddress(hWSQ_library, "_WSQ_encode_stream");
   pConvertHBITMAPtoGrayScale256 = (ConvertHBITMAPtoGrayScale256) GetProcAddress(hWSQ_library, "_ConvertHBITMAPtoGrayScale256");
   pSaveHBITMAPtoFileAsGrayScale256BMP = (SaveHBITMAPtoFileAsGrayScale256BMP) GetProcAddress(hWSQ_library, "_SaveHBITMAPtoFileAsGrayScale256BMP");



   if (pRegisterWSQ == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of RegisterWSQ failed", L"Error", MB_OK );}
   if (pCreateBMPFromFile == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of SaveBMPToFile failed", L"Error", MB_OK );}
   if (pSaveBMPToFile == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of CreateBMPFromFile failed", L"Error", MB_OK );}
   if (pCreateBMPFromWSQByteArray == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of CreateBMPFromWSQByteArray failed", L"Error", MB_OK );}
   if (pSaveWSQByteArrayToImageFile == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of SaveWSQByteArrayToImageFile failed", L"Error", MB_OK );}
   if (pSetShowFilePropertiesDialog == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of SetShowFilePropertiesDialog failed", L"Error", MB_OK );}
   if (pShowFileConverter == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of ShowFileConverter failed", L"Error", MB_OK );}
   if (pWSQ_decode_stream == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of WSQ_decode_stream failed", L"Error", MB_OK );}
   if (pWSQ_encode_stream == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of WSQ_encode_stream failed", L"Error", MB_OK );}
   if (pConvertHBITMAPtoGrayScale256 == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of ConvertHBITMAPtoGrayScale256 failed", L"Error", MB_OK );}
   if (pSaveHBITMAPtoFileAsGrayScale256BMP == NULL)
   {Application->MessageBox( L"Error: GetProcAddress of SaveHBITMAPtoFileAsGrayScale256BMP failed", L"Error", MB_OK );}

}

//---------------------------------------------------------------------------
//Функция для очистки поля данных
inline void __fastcall TCountryEditorForm::ClearAllData()
{
	for(int i=1; i<=UniqueValueListEdit->RowCount-1; i++)
	{
		UniqueValueListEdit->Cells[1][i] = "";
	}
	for(int i=1; i<=LawsListEditor->RowCount-1; i++)
	{
		LawsListEditor->Cells[1][i] = "";
	}
	for(int i=1; i<=PoliticsListEditor->RowCount-1; i++)
	{
		PoliticsListEditor->Cells[1][i] = "";
	}

	UnicodeString FileName = ProgrammPath+"Data\\large_flag_frame.png";
	ifstream LargeFlagFrame(FileName.w_str());
	if(BigFlagImg!=NULL && LargeFlagFrame)
	{
		BigFlagImg->Picture->LoadFromFile(ProgrammPath+"Data\\large_flag_frame.png");
	}
}

//---------------------------------------------------------------------------
//Функция для загрузки флага страны
void __fastcall TCountryEditorForm::LoadFlag(AnsiString TagName, AnsiString RulingParty)
{
	AnsiString FlagPath = AnsiString(ModDirectory+"\\gfx\\flags\\");
	HBITMAP hBMP_large = (pCreateBMPFromFile)(AnsiString(FlagPath+TagName+"_"+RulingParty+".tga").c_str());
	//HBITMAP hBMP_medium = (pCreateBMPFromFile)(AnsiString(FlagPath+"medium\\"+TagName+"_"+RulingParty+".tga").c_str());
	//HBITMAP hBMP_small = (pCreateBMPFromFile)(AnsiString(FlagPath+"small\\"+TagName+"_"+RulingParty+".tga").c_str());

	if(hBMP_large) //&& hBMP_medium && hBMP_small)
	{
		BigFlagImg->Picture->Bitmap->Handle = hBMP_large;
		FlagName_L->Caption = TagName+"_"+RulingParty+".tga";
		//MediumFlagImg->Picture->Bitmap->Handle = hBMP_medium;
		//SmallFlagImg->Picture->Bitmap->Handle = hBMP_small;
	}
	else{
		Application->MessageBoxW(L"Unable to load file", L"WSQ library error", MB_OK | MB_ICONERROR);
	}
}

//---------------------------------------------------------------------------
//Функция удаление пробелы, лишние символы из строки
inline UnicodeString DeleteSpace(UnicodeString _ValueStr)
{
	for(int i=0; i<_ValueStr.Length(); i++)
	{
		if(_ValueStr.Pos(" "))
		{
			_ValueStr = _ValueStr.Delete(_ValueStr.Pos(" "),1);
		}
		else if(_ValueStr.Pos("\t"))
		{
			_ValueStr = _ValueStr.Delete(_ValueStr.Pos("\t"),1);
		}
		else if(_ValueStr.Pos("\""))
		{
			_ValueStr = _ValueStr.Delete(_ValueStr.Pos("\""),1);
		}
		else if(_ValueStr.Pos("#"))
		{
			_ValueStr = _ValueStr.SubString(0,_ValueStr.Pos("#")-1) ;
		}
	}

	return _ValueStr;
}

//---------------------------------------------------------------------------
//Функция считывание данные из файл
void __fastcall TCountryEditorForm::ReadFileData(UnicodeString CountryFileName)
{
	TStringList *List = new TStringList; //Вспомогателыный лист

	UnicodeString ValueStr;
	List->LoadFromFile(CountryFileName);
	UnicodeString ScenarioDate = ShowCurrentScenario_L->Caption; //Текущий дата сценарии
	ScenarioDate = ScenarioDate.SubString(ScenarioDate.Pos(" ")+1,ScenarioDate.Length()-10);

	int StartPos = 0; //Индекс "2013.11.1 = {"
	int EndPos = 0;  //Индекс "}"
	bool ReadData[32] = {false}; //Read Laws and Ideologies list
	bool AllDataScaned = false;


	//Читаем тег
	for(int i=0; i<TagList->Count; i++)
	{
		if(CountryFileName.Pos(TagList->Strings[i]))
		{
			UniqueValueListEdit->Cells[1][2] = TagList->Strings[i];
			break;
		}
	}

	//Имя файла, например RUS - Russia.txt
	UnicodeString TagName = UniqueValueListEdit->Cells[1][2];
	CountryFileName = CountryFileName.SubString(CountryFileName.Pos(TagName), CountryFileName.Pos(TagName));
	UniqueValueListEdit->Cells[1][1] = CountryFileName;

	//Читаем столицу, вне зависимо от блока сценарии
	for(int i=0; i<List->Count; i++)
	{
		if(List->Strings[i].Pos("capital"))
		{
			ValueStr = List->Strings[i];
			ValueStr = DeleteSpace(ValueStr);
			ValueStr = ValueStr.Delete(ValueStr.Pos("capital="),8);
			//ValueStr = ValueStr.ToInt();

			for(int j=0; j<RegionList->Count; j++)
			{
				if(RegionList->Strings[j].Pos(ValueStr))
				{
					UniqueValueListEdit->Cells[1][3] = RegionList->Strings[j];
					break;
				}
			}
		}
	}


	//Читаем данные (законы, политика, лидеры и тп.) ТОЛЬКО в внутр блока сценарии
	for(int i=0; i<List->Count && !AllDataScaned; i++)
	{
		//Для Оптимизиации!!! Проверка работаспособности цикла
		for(int i=0; i<32 && !AllDataScaned; i++)
		{
			if(ReadData[i]==true)
			{
				AllDataScaned = true;
			}
			else{
				AllDataScaned = false;
			}
		}

		//Искаем индекс строки сценарии и конечный фигурная скобка "}"
		if(List->Strings[i].Pos(ScenarioDate))
		{
			StartPos = i+1; //Индекс начало блока
			for(int j=StartPos; j<List->Count; j++)
			{
				if(!List->Strings[j].Pos("\t}") && !List->Strings[j].Pos(" }") && List->Strings[j].Pos("}"))
				{
					EndPos = j; //Индекс конец блока
					break;
				}
			}
		}



		//ЧИТАЕМ! только внутр блока сцеарии! Например: 2013.11.1 = { ... }
		for(int j=StartPos; j<EndPos && !AllDataScaned; j++)
		{

			//Читаем tech level
			if(List->Strings[j].Pos("load_oob"))
			{
				ValueStr = List->Strings[j];
				for(int k=0; k<TechLevelList->Count && !ReadData[0]; k++)
				{
					if(ValueStr.Pos(TechLevelList->ValueFromIndex[k]))
					{
						LawsListEditor->Cells[1][1] = TechLevelList->Strings[k];
						ReadData[0] = true;
						break;
					}
				}
			}

			//Читаем oob
			if(!List->Strings[j].Pos("load_oob") && List->Strings[j].Pos("oob"))
			{
				ValueStr = List->Strings[j];
				ValueStr = DeleteSpace(ValueStr); //Удаляем лишные символы
				ValueStr = ValueStr.Delete(ValueStr.Pos("oob="),4);
				LawsListEditor->Cells[1][2] = ValueStr;
			}

			//add_political_power
			if(List->Strings[j].Pos("add_political_power"))
			{
				ValueStr = List->Strings[j];
				ValueStr = DeleteSpace(ValueStr);
				ValueStr = ValueStr.Delete(ValueStr.Pos("add_political_power="),20);
				LawsListEditor->Cells[1][3] = ValueStr;
			}

			//set_convoys
			if(List->Strings[j].Pos("set_convoys"))
			{
				ValueStr = List->Strings[j];
				ValueStr = DeleteSpace(ValueStr);
				ValueStr = ValueStr.Delete(ValueStr.Pos("set_convoys="),12);
				LawsListEditor->Cells[1][4] = ValueStr;
			}


			//Читаем Законы
			if(List->Strings[j].Pos("add_ideas"))
			{
				for(int k=j+1; k<EndPos && !AllDataScaned; k++)
				{
					ValueStr = List->Strings[k];
					ValueStr = DeleteSpace(ValueStr);

					for(int l=0; l<CountryLevelList->Count && !ReadData[1]; l++)
					{
						if(CountryLevelList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][5] = CountryLevelList->Strings[l];
							ReadData[1] = true;
							break;
						}
                        else{
							LawsListEditor->Cells[1][5] = "";
						}
					}
					for(int l=0; l<FOGList->Count && !ReadData[2]; l++)
					{
						if(FOGList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][6] = FOGList->Strings[l];
							ReadData[2] = true;
							break;
						}
                        else{
							LawsListEditor->Cells[1][6] = "";
						}
					}
					for(int l=0; l<PSList->Count && !ReadData[3]; l++)
					{
						if(PSList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][7] = PSList->Strings[l];
							ReadData[3] = true;
							break;
						}
                        else{
							LawsListEditor->Cells[1][7] = "";
						}
					}
					for(int l=0; l<CorruptionLevelList->Count && !ReadData[4]; l++)
					{
						if(CorruptionLevelList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][8] = CorruptionLevelList->Strings[l];
							ReadData[4] = true;
							 break;
						}
						else{
							LawsListEditor->Cells[1][8] = "";
						}
					}
					for(int l=0; l<EULevelList->Count && !ReadData[5]; l++)
					{
						if(EULevelList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][9] = EULevelList->Strings[l];
							ReadData[5] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][9] = "";
						}
					}
					for(int l=0; l<ReligionLawsList->Count && !ReadData[6]; l++)
					{
						if(ReligionLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][10] = ReligionLawsList->Strings[l];
							ReadData[6] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][10] = "";
						}
					}
					for(int l=0; l<MassMediaLawsList->Count && !ReadData[7]; l++)
					{
						if(MassMediaLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][11] = MassMediaLawsList->Strings[l];
							ReadData[7] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][11] = "";
						}
					}
					for(int l=0; l<CivilLibertiesLawsList->Count && !ReadData[8]; l++)
					{
						if(CivilLibertiesLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][12] = CivilLibertiesLawsList->Strings[l];
							ReadData[8] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][12] = "";
						}
					}
					for(int l=0; l<MobilizationLawsList->Count && !ReadData[9]; l++)
					{
						if(MobilizationLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][13] = MobilizationLawsList->Strings[l];
							ReadData[9] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][13] = "";
						}
					}
					for(int l=0; l<SchoolSystemLawsList->Count && !ReadData[10]; l++)
					{
						if(SchoolSystemLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][14] = SchoolSystemLawsList->Strings[l];
							ReadData[10] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][14] = "";
						}
					}
					for(int l=0; l<ImmigrationLawsList->Count && !ReadData[11]; l++)
					{
						if(ImmigrationLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][15] = ImmigrationLawsList->Strings[l];
							ReadData[11] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][15] = "";
						}
					}
					for(int l=0; l<EconomicMobLawsList->Count && !ReadData[12]; l++)
					{
						if(EconomicMobLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][16] = EconomicMobLawsList->Strings[l];
							ReadData[12] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][16] = "";
						}
					}
					for(int l=0; l<EconomyLawsList->Count && !ReadData[13]; l++)
					{
						if(EconomyLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][17] = EconomyLawsList->Strings[l];
							ReadData[13] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][17] = "";
						}
					}
					for(int l=0; l<TradeLawsList->Count && !ReadData[14]; l++)
					{
						if(TradeLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][18] = TradeLawsList->Strings[l];
							ReadData[14] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][18] = "";
						}
					}
					for(int l=0; l<MarketLawsList->Count && !ReadData[15]; l++)
					{
						if(MarketLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][19] = MarketLawsList->Strings[l];
							ReadData[15] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][19] = "";
						}
					}
					for(int l=0; l<IndustryFocusLawsList->Count && !ReadData[16]; l++)
					{
						if(IndustryFocusLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][20] = IndustryFocusLawsList->Strings[l];
							ReadData[16] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][20] = "";
						}
					}
					for(int l=0; l<TaxesLawsList->Count && !ReadData[17]; l++)
					{
						if(TaxesLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][21] = TaxesLawsList->Strings[l];
							ReadData[17] = true;
							break;
						}
						else{
							LawsListEditor->Cells[1][21] = "";
						}
					}
					for(int l=0; l<SocialSecLawsList->Count && !ReadData[18]; l++)
					{
						if(SocialSecLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][22] = SocialSecLawsList->Strings[l];
							ReadData[18] = true;
							break;
						}
                        else{
							LawsListEditor->Cells[1][22] = "";
						}
					}
					for(int l=0; l<LaborRightsLawsList->Count && !ReadData[19]; l++)
					{
						if(LaborRightsLawsList->Strings[l].Pos(ValueStr))
						{
							LawsListEditor->Cells[1][23] = LaborRightsLawsList->Strings[l];
							ReadData[19] = true;
							break;
						}
                        else{
							LawsListEditor->Cells[1][23] = "";
						}
					}
				}
			}

			//Читаем политики
			if(List->Strings[j].Pos("set_politics"))
			{
				for(int k=j+1; k<EndPos && !AllDataScaned; k++)
				{
					if(!ReadData[20] && List->Strings[k].Pos("democratic") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][1] = ValueStr;
						ReadData[20] = true;
					}
					if(!ReadData[21] && List->Strings[k].Pos("liberalism") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][2] = ValueStr;
						ReadData[21] = true;
					}
					if(!ReadData[22] && List->Strings[k].Pos("neutrality") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][3] = ValueStr;
						ReadData[22] = true;
					}
					if(!ReadData[23] && List->Strings[k].Pos("reformism") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][4] = ValueStr;
						ReadData[23] = true;
					}
					if(!ReadData[24] && List->Strings[k].Pos("communism") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][5] = ValueStr;
						ReadData[24] = true;
					}
					if(!ReadData[25] && List->Strings[k].Pos("fascism") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][6] = ValueStr;
						ReadData[25] = true;
					}
					if(!ReadData[26] && List->Strings[k].Pos("rad_islamists") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][7] = ValueStr;
						ReadData[26] = true;
					}
					if(!ReadData[27] && List->Strings[k].Pos("islamists") && List->Strings[k+1].Pos("popularity"))
					{
						ValueStr = List->Strings[k+1];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("popularity="),11);
						//ValueStr = ValueStr.ToInt();
						PoliticsListEditor->Cells[1][8] = ValueStr;
						ReadData[27] = true;
					}

					if(!ReadData[28] && List->Strings[k].Pos("ruling_party"))
					{
						ValueStr = List->Strings[k];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("ruling_party="),13);
						PoliticsListEditor->Cells[1][9] = ValueStr;
						ReadData[28] = true;
					}
					if(!ReadData[29] && List->Strings[k].Pos("last_election"))
					{
						ValueStr = List->Strings[k];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("last_election="),14);
						PoliticsListEditor->Cells[1][10] = ValueStr;
						ReadData[29] = true;
					}
					if(!ReadData[30] && List->Strings[k].Pos("election_frequency"))
					{
						ValueStr = List->Strings[k];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("election_frequency="),19);
						PoliticsListEditor->Cells[1][11] = ValueStr;
						ReadData[30] = true;
					}
					if(!ReadData[31] && List->Strings[k].Pos("elections_allowed"))
					{
						ValueStr = List->Strings[k];
						ValueStr = DeleteSpace(ValueStr);
						ValueStr = ValueStr.Delete(ValueStr.Pos("elections_allowed="),18);
						PoliticsListEditor->Cells[1][12] = ValueStr;
						ReadData[31] = true;
					}
				}
			}
		}
	}

    //Проверка ячейки идеологии, если она пуста, то она присваивается на 0
	for(int i=1; i<=8; i++)
	{
		if(PoliticsListEditor->Cells[1][i].IsEmpty())
		{
			PoliticsListEditor->Cells[1][i] = 0;
		}
	}

	delete List;
}

//---------------------------------------------------------------------------
//Функция для извлечение "значение" из строки типа "Ключ=Значение"
inline UnicodeString GetValueString(UnicodeString KeyValueString)
{
	if(KeyValueString.Pos("="))
	{
		KeyValueString = KeyValueString.SubString(KeyValueString.Pos("=")+1, KeyValueString.Length()-KeyValueString.Pos("="));
	}
	return KeyValueString;
}

//---------------------------------------------------------------------------
//Функция для извлечение "ключ" из строки типа "Ключ=Значение"
inline UnicodeString GetKeyString(UnicodeString KeyValueString)
{
	if(KeyValueString.Pos("="))
	{
		KeyValueString = KeyValueString.SubString(1, KeyValueString.Pos("=")-1);
	}
	return KeyValueString;
}

//---------------------------------------------------------------------------
//Функция для замены значение в сущесвующего файлы
void __fastcall TCountryEditorForm::InsertFileData(UnicodeString CountryFileName)
{
	TStringList *Buffer = new TStringList();
	Buffer->LoadFromFile(ModDirectory+"\\history\\countries\\"+CountryFileName);
    UnicodeString tString; //временный переменный
	UnicodeString ValueStr;
	UnicodeString KeyStr;

	for(int i=0; i<Buffer->Count; i++)
	{
		if(Buffer->Strings[i].Pos("capital"))
		{
			tString = Buffer->Strings[i];
			tString = DeleteSpace(tString);
			KeyStr = GetKeyString(tString);
			ValueStr = GetValueString(UniqueValueListEdit->Cells[1][3]);
			Buffer->Strings[i] = KeyStr+"="+ValueStr;
        }
	}

	ShowMessage(Buffer->GetText());
	delete Buffer;
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::FormActivate(TObject *Sender)
{
	GetTags();
	GetRegions();
	GetTechLevel();
	GetCountryLevel();
	GetFOGList();
	GetPSList();
    GetCorruptionLevel();
	GetEUIntegrationLevel();
	GetReligionLaws();
	GetMassMediaLaws();
	GetCivilLibertiesLaws();
	GetMobilizationLaws();
	GetSchoolSystemLaws();
	GetImmigrationLaws();
	GetEconomicMobLaws();
	GetEconomyLaws();
	GetTradeLaws();
	GetMarketLaws();
	GetIndustryFocusLaws();
	GetTaxesLaws();
	GetSocialSecLaws();
	GetLaborRightsLaws();
	GetIdeologies();

	FileListBox1->Directory = ModDirectory + "\\history\\countries\\";
	CountryListBox->Items->AddStrings(FileListBox1->Items);
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::GetTags()
{
    /**                          *
	 *                           *
	 *	Получение список тегов   *
	 *                           *
	 *                           */
	TStringList *ListTag = new TStringList; //Вспомогателыный лист
	UnicodeString TAG;
	UnicodeString CountryTagsFile = ModDirectory + "\\common\\country_tags\\00_countries.txt";

	try{
		ListTag->LoadFromFile(CountryTagsFile.w_str()); //Загружаем тег
	}
	catch(EFOpenError&)
	{
		ShowMessage("Invalid directory of the mod or it does not exists");
	}

	int StringCount = ListTag->Count;
	for(int i=0; StringCount>0; i++)
	{
		TAG = ListTag->Strings[i].SubString(0,3);
		if(!TAG.Pos("#")) //Игнорировать хеш тег
		{
		   TagList->Add(TAG); //Добавляем тег
		}
		StringCount--;
	}
	TagList->Sort();
	UniqueValueListEdit->ItemProps[1]->PickList->AddStrings(TagList);

	delete ListTag; //Больше не нужно, освобождаем память
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::GetRegions()
{
    /**                           *
	 *                            *
	 *	Получение список регионов *
	 *                            *
	 *                            */
	TStringList *ListReg = new TStringList;
	FileListBox1->Directory = ModDirectory + "\\history\\states\\"; //Получаем путь к файлы регионов
	ListReg->AddStrings(FileListBox1->Items);
	UnicodeString Key; //Ключ это имени регионов
	UnicodeString Value; //Значение это id региона

	for(int i=0; i<ListReg->Count; i++)
	{
		int initPos = ListReg->Strings[i].Pos("-"); //Позиция знака "-"
		if( //Проверка на разделитель пробела " " пред или после знака "-"
			ListReg->Strings[i].IsDelimiter(" ",initPos-1) ||
			ListReg->Strings[i].IsDelimiter(" ",initPos+1)
		  )
		{
			Key = ListReg->Strings[i].Delete(1, initPos+1); //удаляем цифры
		}
		else{
			Key = ListReg->Strings[i].Delete(1, initPos); //удаляем цифры
		}
		Key = Key.SubString(0,Key.Pos(".txt")-1); //удаляем ".txt" из строки
		Value = ListReg->Strings[i].SubString(0,4);
		if(Value.Pos("-"))
		{
			Value = Value.SubString(0,Value.Pos("-")-1); //удаляем символ "-"
			Value = Value.TrimRight(); //удаляем пробелы
			//Value = Value.ToInt(); //конвертируем в int
		}
		else{
			Value = Value.TrimRight();
			//Value = Value.ToInt();
		}
		RegionList->AddPair(Key,Value); //Добавляем пара "ключ-значение"
		RegionList->Sort();
   }
   UniqueValueListEdit->ItemProps[2]->PickList->AddStrings(RegionList);
   UniqueValueListEdit->ItemProps[2]->ReadOnly = true;

   delete ListReg;
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::GetTechLevel()
{
	/**                                            	*
	 *                                              *
	 *	Парсинг "техи" на листе "Technology Level" 	*
	 *                                              *
	 *												*/
	TStringList *List = new TStringList; //Вспомогателыный лист
	UnicodeString Key;
	UnicodeString Value;
	FileListBox1->Directory = ModDirectory + "\\history\\units\\";
	List->AddStrings(FileListBox1->Items);


	for(int i=0; i<List->Count; i++)
	{
		if(List->Strings[i].Pos("_tech"))
		{
			Key = List->Strings[i].SubString(0,List->Strings[i].Pos(".txt")-1);
			if (!(List->Strings[i].Pos("USA_tech") || List->Strings[i].Pos("RUS_tech"))) //игнорировать
			{
				Key = Key.Delete(1,6); //удаляем приставка "_tech_"
			}

            //Заменим символ "_" на пробел " "
			for(int j=0; j<Key.Length(); j++)
			{
				if(Key.Pos("_"))
				{
					Key = Key.Insert(" ",Key.Pos("_"));
					Key = Key.Delete(Key.Pos("_"),1);
				}
            }

			Value = List->Strings[i].SubString(0,List->Strings[i].Pos(".txt")-1);
			TechLevelList->AddPair(Key,Value);
        }
	}
	LawsListEditor->ItemProps[0]->PickList->AddStrings(TechLevelList);

	delete List;
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetCountryLevel()
{
	CountryLevelList->AddPair("Superstate", "superstate");
	CountryLevelList->AddPair("Major country", "major_country");
	CountryLevelList->AddPair("Regional country", "regional_country");
	CountryLevelList->AddPair("Minor country", "minor_country");
	CountryLevelList->AddPair("Partially recognized country", "partially_recognized_country");
	CountryLevelList->AddPair("Not recognized country", "not_recognized_country");
	CountryLevelList->AddPair("Small country", "small_country");
	CountryLevelList->AddPair("Insurgent country", "fighting_country");
	LawsListEditor->ItemProps[4]->PickList->AddStrings(CountryLevelList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetFOGList() //FOG - Form of Government
{
	 FOGList->AddPair("Dictatorship state", "dictatorship_state");
	 FOGList->AddPair("Single-party state", "single-party_state");
	 FOGList->AddPair("Directorial republic", "directorial_republic");
	 FOGList->AddPair("Presidential republic", "presidential_republic");
	 FOGList->AddPair("Semi-presidential republic", "semi-presidential_republic");
	 FOGList->AddPair("Parliamentary republic", "parliamentary_republic");
	 FOGList->AddPair("Parliamentary monarchy", "parliamentary_monarchy");
	 FOGList->AddPair("Semi-parliamentary monarchy", "semi-parliamentary_monarchy");
	 FOGList->AddPair("Absolute monarchy", "absolute_monarchy");
	 FOGList->AddPair("Caliphate", "caliphate");
	 LawsListEditor->ItemProps[5]->PickList->AddStrings(FOGList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetPSList() //PS - Power Structure
{
	 PSList->AddPair("Confederation", "confederation");
	 PSList->AddPair("Federation", "federation");
	 PSList->AddPair("Administrative federation", "administrative_federation");
	 PSList->AddPair("National federation", "national_federation");
	 PSList->AddPair("Unitary state with devolution", "unitary_state_with_devolution");
	 PSList->AddPair("Unitary state", "unitary_state");
	 LawsListEditor->ItemProps[6]->PickList->AddStrings(PSList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetCorruptionLevel()
{
	 CorruptionLevelList->AddPair("Corruption discounted", "corruption_discounted");
	 CorruptionLevelList->AddPair("Low corruption", "low_corruption");
	 CorruptionLevelList->AddPair("Average corruption", "average_corruption");
	 CorruptionLevelList->AddPair("High corruption", "high_corruption");
	 CorruptionLevelList->AddPair("Oligarchy", "oligarchy");
	 LawsListEditor->ItemProps[7]->PickList->AddStrings(CorruptionLevelList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetEUIntegrationLevel()
{
	 EULevelList->AddPair("Fully integrated in EU", "fully_integrated_in_EU");
	 EULevelList->AddPair("EU membership", "EU_membership");
	 EULevelList->AddPair("candidate on EU membership", "candidate_EU_membership");
	 EULevelList->AddPair("EU access negotiations", "EU_accession_negotiations");
	 LawsListEditor->ItemProps[8]->PickList->AddStrings(EULevelList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetReligionLaws()
{
	 ReligionLawsList->AddPair("State Atheism", "state_atheism");
	 ReligionLawsList->AddPair("Secular state", "secular_state");
	 ReligionLawsList->AddPair("Preference religion", "preference_religion");
	 ReligionLawsList->AddPair("State religion", "state_religion");
	 ReligionLawsList->AddPair("Theocracy", "theocracy");
	 LawsListEditor->ItemProps[9]->PickList->AddStrings(ReligionLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetMassMediaLaws()
{
	 MassMediaLawsList->AddPair("Free media", "free_media");
	 MassMediaLawsList->AddPair("Commercial media", "commercial_media");
	 MassMediaLawsList->AddPair("Mixed media", "mixed_media");
	 MassMediaLawsList->AddPair("Cencored media", "cencored_media");
	 MassMediaLawsList->AddPair("State media only", "state_media_only");
     MassMediaLawsList->AddPair("State propaganda media", "state_propaganda_media");
	 LawsListEditor->ItemProps[10]->PickList->AddStrings(MassMediaLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetCivilLibertiesLaws()
{
	 CivilLibertiesLawsList->AddPair("Fully guranted liberties", "fully_guranted_liberties");
	 CivilLibertiesLawsList->AddPair("Respect of liberties", "respect_of_liberties");
	 CivilLibertiesLawsList->AddPair("Suspended liberties", "suspended_liberties");
	 CivilLibertiesLawsList->AddPair("Limitation of liberties", "limitation_of_liberties");
	 CivilLibertiesLawsList->AddPair("Lack of liberties", "lack_of_liberties");
	 CivilLibertiesLawsList->AddPair("Emergency law", "emergency_law");
	 CivilLibertiesLawsList->AddPair("Martial law", "martial_law");
	 CivilLibertiesLawsList->AddPair("Sharia law", "sharia_law");
	 LawsListEditor->ItemProps[11]->PickList->AddStrings(CivilLibertiesLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetMobilizationLaws()
{
	 MobilizationLawsList->AddPair("Disarmed nation", "disarmed_nation");
	 MobilizationLawsList->AddPair("Volunteer only", "volunteer_only");
	 MobilizationLawsList->AddPair("Limited conscription", "limited_conscription");
	 MobilizationLawsList->AddPair("Service by requirement", "service_by_requirement");
	 MobilizationLawsList->AddPair("Extensive conscription", "extensive_conscription");
	 MobilizationLawsList->AddPair("Reservists conscription", "reservists_conscription");
	 MobilizationLawsList->AddPair("Militia formation", "militia_formation");
	 MobilizationLawsList->AddPair("All adults serve", "all_adults_serve");
     MobilizationLawsList->AddPair("Scraping the barrel", "scraping_the_barrel");
	 LawsListEditor->ItemProps[12]->PickList->AddStrings(MobilizationLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetSchoolSystemLaws()
{
	 SchoolSystemLawsList->AddPair("Mixed schools", "mixed_schools");
	 SchoolSystemLawsList->AddPair("Professional schools", "professional_schools");
	 SchoolSystemLawsList->AddPair("Religious schools", "religious_schools");
	 SchoolSystemLawsList->AddPair("Military schools", "military_schools");
	 SchoolSystemLawsList->AddPair("Technical schools", "tech_schools");
	 SchoolSystemLawsList->AddPair("Reservists conscription", "reservists_conscription");
	 SchoolSystemLawsList->AddPair("Militia formation", "militia_formation");
	 SchoolSystemLawsList->AddPair("All adults serve", "all_adults_serve");
	 SchoolSystemLawsList->AddPair("Scraping the barrel", "scraping_the_barrel");
	 LawsListEditor->ItemProps[13]->PickList->AddStrings(SchoolSystemLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetImmigrationLaws()
{
	 ImmigrationLawsList->AddPair("Close borders", "close_borders");
	 ImmigrationLawsList->AddPair("Restricted immigration", "restricted_immigration");
	 ImmigrationLawsList->AddPair("Open immigration", "open_immigration");
	 ImmigrationLawsList->AddPair("Attract immigrants", "attract_immigrants");
	 ImmigrationLawsList->AddPair("Schengen area immigration", "schengen_area_immigration");
	 LawsListEditor->ItemProps[14]->PickList->AddStrings(ImmigrationLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetEconomicMobLaws()
{
	 EconomicMobLawsList->AddPair("Civilian economy", "civilian_economy");
	 EconomicMobLawsList->AddPair("Low economic mobilisation", "low_economic_mobilisation");
	 EconomicMobLawsList->AddPair("Partial economic mobilisation", "partial_economic_mobilisation");
	 EconomicMobLawsList->AddPair("War economy", "war_economy");
	 EconomicMobLawsList->AddPair("Total economic mobilisation", "tot_economic_mobilisation");
	 LawsListEditor->ItemProps[15]->PickList->AddStrings(EconomicMobLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetEconomyLaws()
{
	 EconomyLawsList->AddPair("Market economy", "market_economy");
	 EconomyLawsList->AddPair("Mixed_economic", "mixed_economic");
	 EconomyLawsList->AddPair("Planned economy", "planned_economy");
	 EconomyLawsList->AddPair("Traditional_economy", "traditional_economy");
	 LawsListEditor->ItemProps[16]->PickList->AddStrings(EconomyLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetTradeLaws()
{
	 TradeLawsList->AddPair("Export focus", "export_focus");
	 TradeLawsList->AddPair("Free trade", "free_trade");
	 TradeLawsList->AddPair("Limited exports", "limited_exports");
	 TradeLawsList->AddPair("Closed economy", "closed_economy");
	 TradeLawsList->AddPair("Isolation", "isolation");
     TradeLawsList->AddPair("Undisturbed isolation", "undisturbed_isolation");
	 LawsListEditor->ItemProps[17]->PickList->AddStrings(TradeLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetMarketLaws()
{
	 MarketLawsList->AddPair("Free market", "free_market");
	 MarketLawsList->AddPair("State-owned enterprise", "state-owned_enterprise");
	 MarketLawsList->AddPair("Nationalization of extractive industries", "nationalization_of_extractive_industries");
	 MarketLawsList->AddPair("Nationalization of heavy industry", "nationalization_of_heavy_industry");
	 MarketLawsList->AddPair("Total nationalization of industry", "total_nationalization_of_industry");
	 MarketLawsList->AddPair("Ban on private enterprise", "ban_on_private_enterprise");
	 LawsListEditor->ItemProps[18]->PickList->AddStrings(MarketLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetIndustryFocusLaws()
{
	 IndustryFocusLawsList->AddPair("Light industry focus", "light_industry_focus");
	 IndustryFocusLawsList->AddPair("Electronics industry focus", "electronics_industry_focus");
	 IndustryFocusLawsList->AddPair("Balanced_industry", "balanced_industry");
	 IndustryFocusLawsList->AddPair("Extractive industries focus", "extractive_industries_focus");
	 IndustryFocusLawsList->AddPair("Heavy industry focus", "heavy_industry_focus");
	 IndustryFocusLawsList->AddPair("Military_industry_focus", "military_industry_focus");
	 LawsListEditor->ItemProps[19]->PickList->AddStrings(IndustryFocusLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetTaxesLaws()
{
	 TaxesLawsList->AddPair("Very low taxes", "very_low_taxes");
	 TaxesLawsList->AddPair("Low taxes", "low_taxes");
	 TaxesLawsList->AddPair("Normal_taxes", "normal_taxes");
	 TaxesLawsList->AddPair("High taxes", "high_taxes");
	 TaxesLawsList->AddPair("Very high taxes", "very_high_taxes");
	 LawsListEditor->ItemProps[20]->PickList->AddStrings(TaxesLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetSocialSecLaws()
{
	 SocialSecLawsList->AddPair("Total social security", "total_social_security");
	 SocialSecLawsList->AddPair("National social security", "national_social_security");
	 SocialSecLawsList->AddPair("Middle social security", "middle_social_security");
	 SocialSecLawsList->AddPair("Base social security", "base_social_security");
	 SocialSecLawsList->AddPair("No social security", "no_social_security");
	 LawsListEditor->ItemProps[21]->PickList->AddStrings(SocialSecLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetLaborRightsLaws()
{
	 LaborRightsLawsList->AddPair("Didn`t labor rights protection", "no_labor_rights_protection");
	 LaborRightsLawsList->AddPair("Prohibition of child labor", "prohibition_of_child_labor");
	 LaborRightsLawsList->AddPair("Prohibition of forced_labour", "prohibition_of_forced_labour");
	 LaborRightsLawsList->AddPair("Normal working time", "normal_working_time");
	 LaborRightsLawsList->AddPair("Minimum wage", "minimum_wage");
	 LaborRightsLawsList->AddPair("Pensions", "pensions");
	 LawsListEditor->ItemProps[22]->PickList->AddStrings(LaborRightsLawsList);
}

//---------------------------------------------------------------------------
inline void __fastcall TCountryEditorForm::GetIdeologies()
{
	 IdeologiesList->AddPair("Conservatism", "democratic");
	 IdeologiesList->AddPair("Liberalism", "liberalism");
	 IdeologiesList->AddPair("Centrism", "neutrality");
	 IdeologiesList->AddPair("Reformism", "reformism");
	 IdeologiesList->AddPair("Socialism", "communism");
	 IdeologiesList->AddPair("Nationalism", "fascism");
	 IdeologiesList->AddPair("Radical Islamism", "rad_islamists");
	 IdeologiesList->AddPair("Islamism", "islamists");

	 PoliticsListEditor->ItemProps[8]->PickList->AddStrings(IdeologiesList);
	 PoliticsListEditor->ItemProps[8]->ReadOnly = true;

	 PoliticsListEditor->ItemProps[11]->PickList->Add("yes");
	 PoliticsListEditor->ItemProps[11]->PickList->Add("no");
	 PoliticsListEditor->ItemProps[11]->ReadOnly = true;
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::OpenCountryFileExecute(TObject *Sender)
{
	if(OpenTextFileDialog->Execute())
	{
		ReadFileData(OpenTextFileDialog->FileName);
	}
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::DrawGraphButtonClick(TObject *Sender)
{
	bool IsEmpty = false;
	for(int i=1; i<=8; i++) //Проверка ячейки ideologies
	{
		if(PoliticsListEditor->Cells[1][i].IsEmpty())
		{
			ShowMessage("Please set the value of "+PoliticsListEditor->Cells[0][i]);
			IsEmpty = true;
			break;
		}
	}

	if(!IsEmpty)
	{
		IdeologiesSeries->MandatoryValueList->Value[0] = StrToInt(PoliticsListEditor->Cells[1][1]);
		IdeologiesSeries->MandatoryValueList->Value[1] = StrToInt(PoliticsListEditor->Cells[1][2]);
		IdeologiesSeries->MandatoryValueList->Value[2] = StrToInt(PoliticsListEditor->Cells[1][3]);
		IdeologiesSeries->MandatoryValueList->Value[3] = StrToInt(PoliticsListEditor->Cells[1][4]);
		IdeologiesSeries->MandatoryValueList->Value[4] = StrToInt(PoliticsListEditor->Cells[1][5]);
		IdeologiesSeries->MandatoryValueList->Value[5] = StrToInt(PoliticsListEditor->Cells[1][6]);
		IdeologiesSeries->MandatoryValueList->Value[6] = StrToInt(PoliticsListEditor->Cells[1][7]);
		IdeologiesSeries->MandatoryValueList->Value[7] = StrToInt(PoliticsListEditor->Cells[1][8]);
		IdeologyChart->Update();
	}

}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::ClearGraphButtonClick(TObject *Sender)
{
	for(int i=0; i<8; i++)
	{
		IdeologiesSeries->MandatoryValueList->Value[i] = 0;
    }
	IdeologyChart->Update();
}

//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::CountryListBoxDblClick(TObject *Sender)
{
	ReadFileData( ModDirectory+"\\history\\countries\\"+CountryListBox->Items->Strings[CountryListBox->ItemIndex] );

	if(UniqueValueListEdit->Cells[1][1]!="" && PoliticsListEditor->Cells[1][9]!="")
	{
		AnsiString TagName = UniqueValueListEdit->Cells[1][2];
		AnsiString RulingParty = PoliticsListEditor->Cells[1][9];
		LoadFlag(TagName, RulingParty);
	}
	else{
		ShowMessage("Error can not load the flag, please check the ceil of tag and ruling party");
	}
}

//---------------------------------------------------------------------------

void __fastcall TCountryEditorForm::BigFlagImgDblClick(TObject *Sender)
{
	if(OpenPictureDialog->Execute())
	{
		HBITMAP hBitMap = (pCreateBMPFromFile)(AnsiString(OpenPictureDialog->FileName).c_str());

		if(hBitMap)
		{
			BigFlagImg->Picture->Bitmap->Handle = hBitMap;
		}
		else{
			Application->MessageBoxW(L"Unable to load file", L"WSQ library error", MB_OK | MB_ICONERROR);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TCountryEditorForm::PoliticsListEditorValidate(TObject *Sender, int ACol,
		  int ARow, const UnicodeString KeyName, const UnicodeString KeyValue)
{
	if(ACol==1 && ARow==9)
	{
		AnsiString TagName = UniqueValueListEdit->Cells[1][2];
		AnsiString RulingParty = KeyValue;
		RulingParty = RulingParty.Delete(1,RulingParty.Pos("="));
		LoadFlag(TagName, RulingParty);
		//ShowMessage(RulingParty);
	}
}
//---------------------------------------------------------------------------
void __fastcall TCountryEditorForm::NewCountryFileExecute(TObject *Sender)
{
	ClearAllData();
	UniqueValueListEdit->Cells[1][1] = "TAG - CountryName.txt";
	//ShowMessage(UniqueValueListEdit->RowCount);
}

//---------------------------------------------------------------------------

void __fastcall TCountryEditorForm::SaveCountryFileExecute(TObject *Sender)
{
	UnicodeString FileName = UniqueValueListEdit->Cells[1][1];
	bool FileName_In_ListBox = false;

	for(int i=0; i<CountryListBox->Count; i++)
	{
		if(FileName==CountryListBox->Items->Strings[i])
		{
			FileName_In_ListBox = true;
			break;
        }
	}

	if(FileName!="" && FileName_In_ListBox)
	{
		InsertFileData(FileName);
		//ShowMessage(GetKeyString(LawsListEditor->Cells[1][1]));
	}
	else{
		ShowMessage("ERROR: can not save, because "+FileName+" file do not excited in the List Box");
    }

}
//---------------------------------------------------------------------------

