//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
#include "resources.rh"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int punkty_gracz1 = 0;  //points_player1
int punkty_gracz2 = 0;  //points_player2
int odbicie = 0;        //bounce

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
          ShowMessage("Witaj w grze Ping Pong. Jest to gra przeznaczona dla dw�ch graczy.\n"
			"Gracz 1 porusza lew� paletk� za pomoc� klawiszy A (g�ra) i Z (d�).\n"
                        "Gracz 2 porusza praw� paletk� za pomoc� strza�ki w d� i w g�r�.\n"
                        "\n"
			"Celem rozgrywki jest zdobycie 10 punkt�w przed przeciwnikiem.\n"
                        "Po ka�dym odbiciu, pr�dko�� pi�ki ro�nie, a� do wygranej kt�rego� z graczy.\n"
			"Aby rozpocz�� gr�, wci�nij przycisk Nowa Gra.\n"
                        "Po ka�dym punkcie, mo�esz kontynuowa� gr� za pomoc� przycisku 'Kolejna Runda' lub\n"
                        "rozpocz�� gr� od nowa za pomoc� przycisku 'Nowa Gra'.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::pilka_TimerTimer(TObject *Sender)
{
    pilka -> Left += x;  //ball
    pilka -> Top += y;

    //odbij od gornej sciany
    if (pilka -> Top - 5 <= tlo -> Top)
    y = -y;

    //odbij od dolnej sciany
    if (pilka -> Top + pilka -> Height + 5 >= tlo -> Top + tlo -> Height)
    y = -y;

    //punkt dla gracza drugiego
    if(pilka -> Left <= paddle1 -> Left - 15)
    {
       if (punkty_gracz2 < 10)
       {
       pilka_Timer -> Enabled = false;
       pilka -> Visible = false;
       BitBtn1 -> Visible = true;
       BitBtn1 -> DragCursor = crHandPoint;
       Button3 -> Visible = true;
       punkty_gracz2++;
       PlaySound(MAKEINTRESOURCE(ID_WAV2), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
       Label1 -> Visible = true;
       Label1 -> Caption = " Wygrywa gracz prawy > ";
       Label2 -> Visible = true;
       Label2 -> Caption = IntToStr(punkty_gracz1) + " : " + IntToStr(punkty_gracz2);
       Button2 -> Visible = true;
       Button2 -> Caption = "Liczba odbi�: " +IntToStr(odbicie);
       }

       if (punkty_gracz2 == 10)
       {
       pilka_Timer -> Enabled = false;   //ball_Timer
       pilka -> Visible = false;
       BitBtn1 -> Visible = false;
       Label1 -> Visible = true;
       Label1 -> Caption = " Gracz 2 zwyci�y�! > ";
       PlaySound(MAKEINTRESOURCE(ID_WAV2), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
       Button3 -> Visible = true;
       Label2 -> Caption = IntToStr(punkty_gracz1) + " : " + IntToStr(punkty_gracz2);
       Button2 -> Visible = true;
       Button2 -> Caption = "Liczba odbi�: " +IntToStr(odbicie);
       }
    }
    else if ((pilka -> Left <= paddle1 -> Left + paddle1 -> Width &&
           pilka -> Top + pilka -> Height >= paddle1 -> Top &&
           pilka -> Top <= paddle1 -> Top + paddle1 -> Height))
    {
        if (y>0 || y<0)
        x = -x;
        odbicie++;
        while (pilka_Timer -> Interval > 1)
        {
        pilka_Timer -> Interval--;
        }
        PlaySound(MAKEINTRESOURCE(ID_WAV1), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
    }

    //punkt dla gracza pierwszego
    if(pilka -> Left > paddle2 -> Left)
    {

       if (punkty_gracz1 < 10)
       {
       pilka_Timer -> Enabled = false;
       pilka -> Visible = false;
       BitBtn1 -> Visible = true;
       BitBtn1 -> DragCursor = crHandPoint;
       Button3 -> Visible = true;
       punkty_gracz1++;
       PlaySound(MAKEINTRESOURCE(ID_WAV2), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
       Label1 -> Visible = true;
       Label1 -> Caption = " < Wygrywa gracz lewy ";
       Label2 -> Visible = true;
       Label2 -> Caption = IntToStr(punkty_gracz1) + " : " + IntToStr(punkty_gracz2);
       Button2 -> Visible = true;
       Button2 -> Caption = "Liczba odbi�: " +IntToStr(odbicie);
       }

       if (punkty_gracz1 == 10)
       {
       pilka_Timer -> Enabled = false;
       pilka -> Visible = false;
       BitBtn1 -> Visible = false;
       Label1 -> Visible = true;
       Label1 -> Caption = " < Gracz 1 zwyci�y�! ";
       PlaySound(MAKEINTRESOURCE(ID_WAV2), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
       Button3 -> Visible = true;
       Label2 -> Caption = IntToStr(punkty_gracz1) + " : " + IntToStr(punkty_gracz2);
       Button2 -> Visible = true;
       Button2 -> Caption = "Liczba odbi�: " +IntToStr(odbicie);
       }
    }
    else if ((pilka -> Left + pilka -> Width >= paddle2 -> Left &&
           pilka -> Top + pilka -> Height >= paddle2 -> Top &&
           pilka -> Top <= paddle2 -> Top + paddle2 -> Height))
    {
        if (y>0 || y<0)
        x = -x;
        odbicie++;
        while (pilka_Timer -> Interval > 1)
        {
        pilka_Timer -> Interval--;
        }
        PlaySound(MAKEINTRESOURCE(ID_WAV1), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1_goraTimer(TObject *Sender)
{
   if (paddle1 -> Top > 8)
   paddle1 -> Top -= 10;
}
//---------------------------------------------------------------------------
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


void __fastcall TForm1::Button3Click(TObject *Sender)
{
   if ((punkty_gracz1 != 0 || punkty_gracz2 != 0) || (punkty_gracz1 != 0 && punkty_gracz2 != 0) ||
   (punkty_gracz1 == 10 || punkty_gracz2 == 10))
   {
      if(Application->MessageBox("Czy na pewno rozpocz�� now� gr�?","Potwierd�",
      MB_YESNO | MB_ICONQUESTION) == IDYES)
      {
      Form1 -> Label1 -> Caption = "Runda rozpocznie si� za: 2";
      Application -> ProcessMessages(); Sleep(1000);
      Form1 -> Label1 -> Caption = "Runda rozpocznie si� za: 1";
      Application -> ProcessMessages(); Sleep(1000);
      
      pilka -> Left = 528;
      pilka -> Top = 256;

      pilka -> Visible = true;
      x = -8; y = -8;

      odbicie = 0;
      punkty_gracz1 = 0;
      punkty_gracz2 = 0;

      Label1 -> Visible = false;
      Label2 -> Visible = false;
      BitBtn1 -> Visible = false;
      Button2 -> Visible = false;
      Button3 -> Visible = false;

      pilka_Timer -> Enabled = true;
      }
   }
   else
   {
      Form1 -> Label1 -> Caption = "Runda rozpocznie si� za: 2";
      Application -> ProcessMessages(); Sleep(1000);
      Form1 -> Label1 -> Caption = "Runda rozpocznie si� za: 1";
      Application -> ProcessMessages(); Sleep(1000);

      pilka -> Left = 528;
      pilka -> Top = 256;

      pilka -> Visible = true;
      x = -8; y = -8;

      odbicie = 0;
      punkty_gracz1 = 0;
      punkty_gracz2 = 0;

      Label1 -> Visible = false;
      Label2 -> Visible = false;
      BitBtn1 -> Visible = false;
      Button2 -> Visible = false;
      Button3 -> Visible = false;

      pilka_Timer -> Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
      pilka -> Left = 528;
      pilka -> Top = 256;
      pilka_Timer -> Interval = 16;

      pilka -> Visible = true;
      x = -8; y = -8;

      odbicie = 0;

      Label1 -> Visible = false;
      Label2 -> Visible = false;
      BitBtn1 -> Visible = false;
      Button2 -> Visible = false;
      Button3 -> Visible = false;

      pilka_Timer -> Enabled = true;
}
//---------------------------------------------------------------------------

