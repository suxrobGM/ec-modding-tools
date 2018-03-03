object OptionsForm: TOptionsForm
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 201
  ClientWidth = 457
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = 0
    Top = 0
    Width = 457
    Height = 201
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 240
    ExplicitTop = 112
    ExplicitWidth = 185
    ExplicitHeight = 41
    object DirMod_L: TLabel
      Left = 8
      Top = 68
      Width = 120
      Height = 13
      Caption = 'Directory of the mod:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ChooseLang_L: TLabel
      Left = 8
      Top = 8
      Width = 102
      Height = 13
      Caption = 'Choose Language:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SetDirEdit: TEdit
      Left = 8
      Top = 83
      Width = 145
      Height = 21
      TabOrder = 0
    end
    object SetDirButton: TButton
      Left = 8
      Top = 110
      Width = 75
      Height = 25
      Caption = 'Set Directory'
      TabOrder = 1
      OnClick = SetDirButtonClick
    end
    object DirectoryListBox1: TDirectoryListBox
      Left = 208
      Top = 8
      Width = 243
      Height = 185
      TabOrder = 2
    end
    object ChangeLanguage_CB: TComboBox
      Left = 8
      Top = 24
      Width = 145
      Height = 21
      Style = csDropDownList
      TabOrder = 3
      OnChange = ChangeLanguage_CBChange
      Items.Strings = (
        'English'
        'Russian')
    end
  end
end
