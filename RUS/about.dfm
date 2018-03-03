object AboutBox: TAboutBox
  Left = 445
  Top = 127
  ActiveControl = OKButton
  BorderStyle = bsDialog
  Caption = 'About'
  ClientHeight = 268
  ClientWidth = 421
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 10
    Top = 10
    Width = 399
    Height = 198
    BevelOuter = bvLowered
    TabOrder = 0
    object ProgramIcon: TImage
      Left = 10
      Top = 10
      Width = 80
      Height = 80
      IsControl = True
    end
    object ProductName: TLabel
      Left = 108
      Top = 20
      Width = 284
      Height = 16
      Caption = 'Hearts of Iron IV: Economic Crisis modding tools'
      IsControl = True
    end
    object Version: TLabel
      Left = 108
      Top = 49
      Width = 69
      Height = 16
      Caption = 'Version: 0.1'
      IsControl = True
    end
    object Copyright: TLabel
      Left = 10
      Top = 98
      Width = 107
      Height = 16
      Caption = 'Author: SuxrobGM'
      IsControl = True
    end
    object Comments: TLabel
      Left = 10
      Top = 128
      Width = 64
      Height = 16
      Caption = 'Comments'
      WordWrap = True
      IsControl = True
    end
  end
  object OKButton: TButton
    Left = 172
    Top = 219
    Width = 80
    Height = 41
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    IsControl = True
  end
end
