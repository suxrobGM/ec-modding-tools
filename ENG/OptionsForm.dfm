object SettingsForm: TSettingsForm
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 185
  ClientWidth = 477
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 461
    Height = 169
    BorderStyle = bsSingle
    TabOrder = 0
    object DirMod_L: TLabel
      Left = 14
      Top = 65
      Width = 129
      Height = 14
      Caption = 'Directory of the mod'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ChooseLang_L: TLabel
      Left = 14
      Top = 3
      Width = 113
      Height = 14
      Caption = 'Choose Language:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SetDirButton: TButton
      Left = 81
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Set Directory'
      TabOrder = 0
      OnClick = SetDirButtonClick
    end
    object SetDirEdit: TEdit
      Left = 14
      Top = 85
      Width = 225
      Height = 21
      TabOrder = 1
    end
    object DirectoryListBox1: TDirectoryListBox
      Left = 256
      Top = 1
      Width = 200
      Height = 163
      Align = alRight
      AutoComplete = False
      DoubleBuffered = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 2
    end
    object ChangeLanguage_CB: TComboBox
      Left = 14
      Top = 22
      Width = 145
      Height = 21
      Style = csDropDownList
      TabOrder = 3
      OnChange = ChangeLanguage_CBChange
      Items.Strings = (
        #1056#1091#1089#1089#1082#1080#1081
        'English')
    end
  end
end
