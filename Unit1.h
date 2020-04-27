//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include "TntStdCtrls.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TServerSocket *ServerSocket1;
  TButton *btnServerSend;
  TClientSocket *ClientSocket1;
  TButton *btnClientSend;
  TButton *btnClientConnect;
  TTntMemo *TntMemo1;
  TTntEdit *TntEdit1;
  void __fastcall btnServerSendClick(TObject *Sender);
  void __fastcall ServerSocket1Accept(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
  void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ServerSocket1ClientWrite(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ServerSocket1Listen(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall btnClientSendClick(TObject *Sender);
  void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
  void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
  void __fastcall btnClientConnectClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
