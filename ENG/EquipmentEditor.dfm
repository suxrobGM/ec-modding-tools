object EquipmentEditorForm1: TEquipmentEditorForm1
  Left = 0
  Top = 0
  Caption = 'Equipment Editor'
  ClientHeight = 323
  ClientWidth = 1058
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 178
    Top = 73
    Width = 225
    Height = 18
    Align = alCustom
    Caption = 'Defensive Abilities ('#1054#1073#1086#1088#1086#1085#1072')'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 0
    Top = 73
    Width = 148
    Height = 18
    Align = alCustom
    Caption = 'Name('#1048#1084#1103' '#1069#1082#1074#1080#1087#1072')'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 433
    Top = 73
    Width = 254
    Height = 18
    Align = alCustom
    Caption = 'Offensive Abilities('#1053#1072#1089#1090#1091#1087#1083#1077#1085#1080#1077')'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 704
    Top = 73
    Width = 100
    Height = 18
    Align = alCustom
    Caption = 'Misc Abilities'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 831
    Top = 73
    Width = 86
    Height = 18
    Align = alCustom
    Caption = 'Cost('#1062#1077#1085#1072')'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 959
    Top = 73
    Width = 78
    Height = 18
    Align = alCustom
    Caption = 'Resources'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 90
    Width = 1058
    Height = 233
    ParentCustomHint = False
    Align = alBottom
    ColCount = 14
    DoubleBuffered = False
    FixedCols = 0
    RowCount = 10
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing]
    ParentDoubleBuffered = False
    TabOrder = 0
    ExplicitTop = 52
    ColWidths = (
      171
      73
      59
      66
      59
      64
      64
      64
      64
      64
      64
      64
      64
      82)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Edit1: TEdit
    Left = 334
    Top = 0
    Width = 353
    Height = 31
    Align = alCustom
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Verdana'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    Text = 'Edit1'
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 192
    object File1: TMenuItem
      Caption = 'File'
      object CreateNewEquipmentFile2: TMenuItem
        Action = CreateNewEquipmentFile1
      end
      object OpenEquipmentFile2: TMenuItem
        Action = OpenEquipmentFile1
      end
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Filter = 'Txt Files|*.txt*'
    Encodings.Strings = (
      'UTF-8'
      'UTF-8 BOM'
      'ANSI')
    Left = 40
    Top = 192
  end
  object ActionList1: TActionList
    Left = 72
    Top = 192
    object CreateNewEquipmentFile1: TAction
      Category = 'File'
      Caption = 'Create New Equipment File'
    end
    object OpenEquipmentFile1: TAction
      Category = 'File'
      Caption = 'Open Equipment File'
      OnExecute = OpenEquipmentFile1Click
    end
  end
end
