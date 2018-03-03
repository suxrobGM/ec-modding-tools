object UnitEditorForm: TUnitEditorForm
  Left = 0
  Top = 0
  Caption = 'Unit Editor'
  ClientHeight = 345
  ClientWidth = 489
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
  object MainMenu1: TMainMenu
    Left = 24
    Top = 312
    object File1: TMenuItem
      Caption = 'File'
      object Createnewunitfile1: TMenuItem
        Action = NewUnitTxtFile1
        Caption = 'New Unit File'
      end
      object Openunitfile1: TMenuItem
        Action = OpenUnitTxtFile1
        Caption = 'Open Unit File'
      end
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Filter = 'TXT Files|*.txt*'
    Encodings.Strings = (
      'UTF-8'
      'UTF-8 BOM'
      'ANSI')
    Left = 64
    Top = 312
  end
  object ActionList1: TActionList
    Left = 104
    Top = 312
    object OpenUnitTxtFile1: TAction
      Category = 'File'
      Caption = 'Open Unit Txt File'
    end
    object NewUnitTxtFile1: TAction
      Category = 'File'
      Caption = 'New Unit Txt File'
    end
  end
end
