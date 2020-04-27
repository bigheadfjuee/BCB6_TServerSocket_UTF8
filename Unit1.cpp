//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#define CLIENT_PORT 6668
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TntStdCtrls"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
  ServerSocket1->Port = CLIENT_PORT;
  ServerSocket1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnServerSendClick(TObject *Sender)
{
  TntMemo1->Lines->Add("==================");
  TntMemo1->Lines->Add("btnServerSendClick");
  WideString ws = TntEdit1->Text + "\r\n";

  for (int i = 0; i < ServerSocket1->Socket->ActiveConnections; i++)
  {
   UTF8String utf8 = UTF8Encode(ws);
   ServerSocket1->Socket->Connections[i]->SendBuf(utf8.c_str(), utf8.Length());
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
                                            TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1Accept: " + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
                                                   TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1ClientConnect: " + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
                                                      TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1ClientDisconnect: " + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
                                                 TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1ClientError: " + str);
  TntMemo1->Lines->Add(AnsiString(ErrorEvent) + "," + IntToStr(ErrorCode));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
                                                TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1ClientRead: " + str);

  int get_size = Socket->ReceiveLength();
    //多加1 Byte的0在結尾，避免轉字串時錯誤
  char *Buf = new char[get_size + 1];
  memset(Buf, 0, get_size + 1);

  Socket->ReceiveBuf(Buf, get_size);
  UTF8String utf8 = UTF8String(Buf);
  TntMemo1->Lines->Add(UTF8Decode(utf8));

  delete[] Buf;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientWrite(TObject *Sender,
                                                 TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ServerSocket1ClientWrite:" + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1Listen(TObject *Sender,
                                            TCustomWinSocket *Socket)
{
  TntMemo1->Lines->Add("ServerSocket1Listen: " + IntToStr(Socket->LocalPort));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnClientSendClick(TObject *Sender)
{
  TntMemo1->Lines->Add("==================");
  TntMemo1->Lines->Add("btnClientSendClick");

  WideString ws = TntEdit1->Text + "\r\n";

  if (ClientSocket1->Socket->Connected)
  {
   UTF8String utf8 = UTF8Encode(ws);
   ClientSocket1->Socket->SendBuf(utf8.c_str(), utf8.Length());
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ClientSocket1Connect:" + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ClientSocket1Connect:" + str);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
  AnsiString str = Socket->RemoteAddress;
  TntMemo1->Lines->Add("ClientSocket1Error:" + str);
  TntMemo1->Lines->Add(AnsiString(ErrorEvent) +"," + IntToStr(ErrorCode));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
  AnsiString str; //= Format("%s(%i)", Socket->RemoteAddress, Socket->ReceiveLength())];
  str.sprintf("%s(%i)", Socket->RemoteAddress, Socket->ReceiveLength());
  TntMemo1->Lines->Add("ClientSocket1Read:" + str);

  int get_size = Socket->ReceiveLength();
    //多加1 Byte的0在結尾，避免轉字串時錯誤
  char *Buf = new char[get_size + 1];
  memset(Buf, 0, get_size + 1);

  Socket->ReceiveBuf(Buf, get_size);
  UTF8String utf8 = UTF8String(Buf);
  TntMemo1->Lines->Add(UTF8Decode(utf8));

  delete[] Buf;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnClientConnectClick(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Host = "127.0.0.1";
  ClientSocket1->Port = 6668;
  ClientSocket1->Active = true;
}
//---------------------------------------------------------------------------

