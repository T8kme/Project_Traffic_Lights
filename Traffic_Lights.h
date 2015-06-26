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
