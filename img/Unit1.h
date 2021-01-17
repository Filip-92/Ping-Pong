//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *paddle1;
        TImage *pilka;
        TTimer *pilka_Timer;
        TTimer *paddle1_gora;
        TTimer *paddle1_dol;
        TTimer *paddle2_gora;
        TTimer *paddle2_dol;
        TImage *paddle2;
        TButton *Button1;
        void __fastcall pilka_TimerTimer(TObject *Sender);
        void __fastcall paddle1_goraTimer(TObject *Sender);
        void __fastcall paddle1_dolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paddle2_goraTimer(TObject *Sender);
        void __fastcall paddle2_dolTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
