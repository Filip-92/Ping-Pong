//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int punkty_gracz1;
int punkty_gracz2;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pilka_TimerTimer(TObject *Sender)
{
    pilka -> Left += x;
    pilka -> Top += y;

    //odbij od gornej sciany
    if (pilka -> Top - 5 <= tlo -> Top)
    y = -y;

    //odbij od dolnej sciany
    if (pilka -> Top + pilka -> Height + 10 >= tlo -> Height)
    y = -y;

    //punkt dla gracza pierwszego
    if(pilka -> Left -5 <= tlo -> Left)
    {
       pilka_Timer -> Enabled = false;
       pilka -> Visible = false;
       Button1 -> Visible = true;
       punkty_gracz2++;
    }  /*(pilka -> Left > paddle1 -> Left - pilka -> Width/2 &&
    pilka -> Left < paddle1 -> Left + paddle1 -> Width && pilka -> Top + pilka -> Height > paddle1 -> Left)*/
    else if ((pilka->Left < paddle1 ->Left + paddle1 ->Width &&
           pilka ->Top + pilka -> Height/2 <= paddle1 -> Top + paddle1 -> Height &&
           pilka ->Top + pilka -> Height/2 >= paddle1 -> Top))
    {
        if (y>0)
        x = -x;
        y = -y;
    }

    if(pilka -> Left + pilka -> Width + 5 >= tlo -> Width)
    {
       pilka_Timer -> Enabled = false;
       pilka -> Visible = false;
       Button1 -> Visible = true;
       punkty_gracz1++;
    }
    else if ((pilka -> Left + pilka -> Width >= paddle2 -> Left &&
           pilka -> Top + pilka -> Height/2 <= paddle2 -> Top + paddle2 -> Height &&
           pilka -> Top + pilka -> Height/2 >= paddle2 -> Top))
    {
        if (y>0)
        x = -x;
        y = -y;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1_goraTimer(TObject *Sender)
{
   if (paddle1 -> Top > 8)
   paddle1 -> Top -= 10;
}
void __fastcall TForm1::paddle1_dolTimer(TObject *Sender)
{
    if (paddle1 -> Top + paddle1 -> Height + 10 <= tlo -> Height)
    paddle1 -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 'A') paddle1_gora -> Enabled = true;
    if (Key == 'Z') paddle1_dol -> Enabled = true;
    if (Key == VK_UP) paddle2_gora -> Enabled = true;
    if (Key == VK_DOWN) paddle2_dol -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 'A') paddle1_gora -> Enabled = false;
    if (Key == 'Z') paddle1_dol -> Enabled = false;
    if (Key == VK_UP) paddle2_gora -> Enabled = false;
    if (Key == VK_DOWN) paddle2_dol -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2_goraTimer(TObject *Sender)
{
   if (paddle2 -> Top > 8)
   paddle2 -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2_dolTimer(TObject *Sender)
{
    if (paddle2 -> Top + paddle2 -> Height + 10 <= tlo -> Height)
    paddle2 -> Top += 10;
}
//---------------------------------------------------------------------------
