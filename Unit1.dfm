object Form1: TForm1
  Left = 581
  Top = 170
  Width = 773
  Height = 416
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object btnServerSend: TButton
    Left = 488
    Top = 80
    Width = 97
    Height = 25
    Caption = 'Server Send'
    TabOrder = 0
    OnClick = btnServerSendClick
  end
  object btnClientSend: TButton
    Left = 488
    Top = 224
    Width = 97
    Height = 25
    Caption = 'Client Send'
    TabOrder = 1
    OnClick = btnClientSendClick
  end
  object btnClientConnect: TButton
    Left = 488
    Top = 192
    Width = 97
    Height = 25
    Caption = 'Client connect'
    TabOrder = 2
    OnClick = btnClientConnectClick
  end
  object TntMemo1: TTntMemo
    Left = 16
    Top = 8
    Width = 465
    Height = 329
    Lines.Strings = (
      'TntMemo1')
    TabOrder = 3
  end
  object TntEdit1: TTntEdit
    Left = 488
    Top = 16
    Width = 193
    Height = 24
    TabOrder = 4
    Text = 'Hello, '#20320#22909' '#12363#12431#12355' '#21737#36032' 1234'
    Text_UTF7 = 'Hello, +T2BZfQ +MEswjzBD +VOmMwA 1234'
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnListen = ServerSocket1Listen
    OnAccept = ServerSocket1Accept
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientWrite = ServerSocket1ClientWrite
    OnClientError = ServerSocket1ClientError
    Left = 504
    Top = 32
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 512
    Top = 152
  end
end
