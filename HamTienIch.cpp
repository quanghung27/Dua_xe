#include<windows.h>
#include"HamTienIch.h"
void textcolor(int x)       //Hàm tô màu.
{
	HANDLE mau;
	mau=GetStdHandle
(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}


void gotoxy(int x,int y)    // Hàm dịch chuyển con trỏ đến tọa độ x, y.
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle
(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput ,
Cursor_an_Pos);
}


void XoaManHinh()       // Hàm Xóa Màn Hình
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle
(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);

}

