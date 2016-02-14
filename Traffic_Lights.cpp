// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Traffic_Lights.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
// dane
int pointer_height, pointer_width, pointer_height2, pointer_width2, zmtimer,
	toggle = 0; // variable declarations
AnsiString TimeC, TimeZ, TimeM;
float counter = 0;
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	DoubleBuffered = True; // 2 objects
	Field = new Graphics::TBitmap;
	Field2 = new Graphics::TBitmap;
	// Ustawianie wymiarów
	pointer_height = Image1->Height;
	pointer_width = Image1->Width;
	Field->Width = pointer_width;
	Field->Height = pointer_height;

	pointer_height2 = Image2->Height;
	pointer_width2 = Image2->Width;
	Field2->Width = pointer_width2;
	Field2->Height = pointer_height2;
	// Functions
	field_background();
	field2_background();
	redlight();
	greenlight();
	// gray_redlight();
	// gray_greenlight();

	ProstField.left = 0;
	ProstField.top = 0;
	ProstField.right = pointer_height;
	ProstField.bottom = pointer_width;

	ProstField2.left = 0;
	ProstField2.top = 0;
	ProstField2.right = pointer_height;
	ProstField2.bottom = pointer_width;

	Image1->Canvas->CopyRect(ProstField, Field->Canvas, ProstField);
	Image2->Canvas->CopyRect(ProstField2, Field2->Canvas, ProstField2);
}

// ---------------------------------------------------------------------------
void TForm1::field_background() {
	Field->Canvas->Pen->Color = RGB(0, 0, 0);
	Field->Canvas->Pen->Width = 1;
	Field->Canvas->Brush->Color = RGB(110, 110, 110); // gray
	Field->Canvas->Rectangle(0, 0, 300, 300);
}

void TForm1::field2_background() {
	Field2->Canvas->Pen->Color = RGB(0, 0, 0);
	Field2->Canvas->Pen->Width = 1;
	Field2->Canvas->Brush->Color = RGB(110, 110, 110);
	Field2->Canvas->Rectangle(0, 0, 300, 300);
}

// ---------------------------------------------------------------------------
void TForm1::redlight() {
	Field->Canvas->Pen->Color = RGB(180, 48, 46);
	Field->Canvas->Pen->Width = 1;
	Field->Canvas->Brush->Color = RGB(218, 36, 25);
	// Head
	Field->Canvas->Ellipse(81, 32, 118, 69);
	// Body
	Field->Canvas->Rectangle(85, 72, 114, 114);
	// Arms
	Field->Canvas->Rectangle(69, 72, 83, 121);
	Field->Canvas->Rectangle(116, 72, 131, 121);
	// Legs
	Field->Canvas->Rectangle(85, 115, 98, 160);
	Field->Canvas->Rectangle(101, 115, 114, 160);

}

void TForm1::gray_redlight() {
	Field->Canvas->Pen->Color = RGB(130, 130, 130);
	Field->Canvas->Pen->Width = 1;
	Field->Canvas->Brush->Color = RGB(140, 140, 140);
	// Head
	Field->Canvas->Ellipse(81, 32, 118, 69);
	// Body
	Field->Canvas->Rectangle(85, 72, 114, 114);
	// Arms
	Field->Canvas->Rectangle(69, 72, 83, 121);
	Field->Canvas->Rectangle(116, 72, 131, 121);
	// Legs
	Field->Canvas->Rectangle(85, 115, 98, 160);
	Field->Canvas->Rectangle(101, 115, 114, 160);

}

// ---------------------------------------------------------------------------
void TForm1::greenlight() {
	Field2->Canvas->Pen->Color = RGB(30, 107, 61); // pióro
	Field2->Canvas->Pen->Width = 1;
	Field2->Canvas->Brush->Color = RGB(7, 142, 65);
	// Head
	Field2->Canvas->Ellipse(88, 34, 125, 71);
	// Body
	TPoint points[4];
	points[0] = Point(97, 73);
	points[1] = Point(115, 73);
	points[2] = Point(115, 117);
	points[3] = Point(97, 117);
	Field2->Canvas->Polygon(points, 3);
	// Arms
	// left
	TPoint points2[4];
	points2[0] = Point(85, 70);
	points2[1] = Point(96, 76);
	points2[2] = Point(85, 94);
	points2[3] = Point(63, 107);
	points2[4] = Point(57, 96);
	points2[5] = Point(75, 86);
	Field2->Canvas->Polygon(points2, 5);
	// right
	TPoint points3[4];
	points3[0] = Point(116, 77);
	points3[1] = Point(125, 68);
	points3[2] = Point(140, 92);
	points3[3] = Point(127, 116);
	points3[4] = Point(118, 109);
	points3[5] = Point(126, 92);
	Field2->Canvas->Polygon(points3, 5);
	// Legs
	// left
	TPoint points4[4];
	points4[0] = Point(95, 115);
	points4[1] = Point(104, 121);
	points4[2] = Point(79, 157);
	points4[3] = Point(65, 147);
	points4[4] = Point(69, 142);
	points4[5] = Point(74, 146);
	Field2->Canvas->Polygon(points4, 5);
	// right
	TPoint points5[4];
	points5[0] = Point(106, 121);
	points5[1] = Point(115, 116);
	points5[2] = Point(136, 155);
	points5[3] = Point(121, 162);
	points5[4] = Point(119, 157);
	points5[5] = Point(124, 154);
	Field2->Canvas->Polygon(points5, 5);
}

void TForm1::gray_greenlight() {
	Field2->Canvas->Pen->Color = RGB(130, 130, 130); // brush
	Field2->Canvas->Pen->Width = 1;
	Field2->Canvas->Brush->Color = RGB(140, 140, 140);
	// Head
	Field2->Canvas->Ellipse(88, 34, 125, 71);
	// Body
	TPoint points[4];
	points[0] = Point(97, 73);
	points[1] = Point(115, 73);
	points[2] = Point(115, 117);
	points[3] = Point(97, 117);
	Field2->Canvas->Polygon(points, 3);
	// Arms
	// left
	TPoint points2[4];
	points2[0] = Point(85, 70);
	points2[1] = Point(96, 76);
	points2[2] = Point(85, 94);
	points2[3] = Point(63, 107);
	points2[4] = Point(57, 96);
	points2[5] = Point(75, 86);
	Field2->Canvas->Polygon(points2, 5);
	// right
	TPoint points3[4];
	points3[0] = Point(116, 77);
	points3[1] = Point(125, 68);
	points3[2] = Point(140, 92);
	points3[3] = Point(127, 116);
	points3[4] = Point(118, 109);
	points3[5] = Point(126, 92);
	Field2->Canvas->Polygon(points3, 5);
	// Legs
	// left
	TPoint points4[4];
	points4[0] = Point(95, 115);
	points4[1] = Point(104, 121);
	points4[2] = Point(79, 157);
	points4[3] = Point(65, 147);
	points4[4] = Point(69, 142);
	points4[5] = Point(74, 146);
	Field2->Canvas->Polygon(points4, 5);
	// right
	TPoint points5[4];
	points5[0] = Point(106, 121);
	points5[1] = Point(115, 116);
	points5[2] = Point(136, 155);
	points5[3] = Point(121, 162);
	points5[4] = Point(119, 157);
	points5[5] = Point(124, 154);
	Field2->Canvas->Polygon(points5, 5);
}

void TForm1::refresh() {
	Image1->Canvas->CopyRect(ProstField, Field->Canvas, ProstField); // 1
	Image2->Canvas->CopyRect(ProstField2, Field2->Canvas, ProstField2);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::CloseButtonClick(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ManualClick(TObject *Sender) {

	if (toggle == 0) {
		gray_greenlight();
		redlight();
		refresh();
		toggle = 1;
	}
	else {
		gray_redlight();
		greenlight();
		refresh();
		toggle = 0;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::StartButtonClick(TObject *Sender) {
	Timer1->Enabled = True; // start timer
	StartButton->Enabled = False; // blocking items
	ClearButton->Enabled = False;
	Manual->Enabled = False;
	RedEdit->Enabled = False;
	GreenEdit->Enabled = False;
	FlashEdit->Enabled = False;

	TimeC = RedEdit->Text; // read contents from editboxes
	TimeZ = GreenEdit->Text;
	TimeM = FlashEdit->Text;

	if (RedEdit->Text < 0) { // cannot be ' '
		RedEdit->Text = 0;
		TimeC = 0;
	}
	if (GreenEdit->Text < 0) {
		GreenEdit->Text = 0;
		TimeZ = 0;
	}
	if (FlashEdit->Text < 0) {
		FlashEdit->Text = 0;
		TimeM = 0;
	}

	gray_greenlight(); // greenlight
	gray_redlight(); // redlight
	refresh();
	toggle = 0;
}

// -----------------------TIMER----------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	TimeLabel->Caption = 1 + (zmtimer++ / 100);
	counter++;

	if (toggle == 0 && StrToInt(TimeC) != 0) { // change on redlight
		if ((counter / 100) == StrToInt(TimeC)) {
			gray_redlight(); // gray redlight
			refresh();
			counter = 0;
			toggle = 1;
		}
		else { // greenlight
			redlight();
			refresh();
		}
	}
	else { // zmiana na greenlight
		if ((counter / 100) == (StrToInt(TimeZ) + StrToInt(TimeM)))
		{ // preparing to change
			gray_greenlight(); // gray greenlight
			refresh();
			counter = 0;
			toggle = 0;
		}
		else { // greenlight
			if ((counter / 100) < (StrToInt(TimeZ))) {
				greenlight();
				refresh();
			}
			else { // flashing
				if (fmod((((counter / 100) - StrToInt(TimeZ))), 1)
					> 0.5 && StrToInt(TimeM) != 0) {
					greenlight();
					refresh();
				}
				else {
					gray_greenlight();
					refresh();
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::StopButtonClick(TObject *Sender) {
	Timer1->Enabled = False; // timer stop
	StartButton->Enabled = True; // unable items
	Manual->Enabled = True;
	ClearButton->Enabled = True;
	RedEdit->Enabled = True;
	GreenEdit->Enabled = True;
	FlashEdit->Enabled = True;
	toggle = 0;
	counter = 0;
}
// --------------------------------------------a-------------------------------

void __fastcall TForm1::ClearButtonClick(TObject *Sender) {
	zmtimer = 0;
	counter = 0;
	toggle = 0;
	TimeLabel->Caption = 0;
	GreenEdit->Text = 1;
	RedEdit->Text = 1;
	FlashEdit->Text = 1;

}
// ---------------------------------------------------------------------------

