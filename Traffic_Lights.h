//---------------------------------------------------------------------------

#ifndef Traffic_LightsH
#define Traffic_LightsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TLabel *Label4;
	TLabel *Label9;
	TGroupBox *GroupBox1;
	TLabel *TimeLabel;
	TLabel *Label1;
	TButton *StartButton;
	TButton *CloseButton;
	TButton *Manual;
	TButton *StopButton;
	TButton *ClearButton;
	TGroupBox *GroupBox2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *GreenEdit;
	TEdit *RedEdit;
	TEdit *FlashEdit;
	TTimer *Timer1;
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall StopButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall ManualClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
Graphics::TBitmap * Field; //graphics Tbitmap, pointer named Field
Graphics::TBitmap * Field2;
TRect ProstField; // TRect class, name ProstField
TRect ProstField2;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void field_background();
	void field2_background();
	void redlight();
	void greenlight();
	void gray_redlight();
	void gray_greenlight();
	void refresh();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
