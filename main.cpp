#include <iostream>
#include <string.h>
#include<Windows.h>
#include <ctime>
using namespace std;
char map1[50][50];

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle
(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void Ve_Duong_Dua()
{
    for(int i=0;i<40;i++)
    {
        map1[i][0] ='|';
        map1[i][39]='|';
        map1[i][20]='|';
        for(int j=1;j<39 && j!=20;j++)
            {
                map1[i][j]=' ';
            }
    }
}
void In_Duong_Dua()
{
    for(int i=0;i<40;i++)
    {
        cout << "\t\t\t";
        for(int j=0;j<40;j++)
            {
                if(j==0||j==39)
                {
                    textcolor(14);
                    cout << map1[i][j];
                    textcolor(7);
                }
                else if(map1[i][j]== '$'||map1[i][j]=='I'||map1[i][j]=='O')
                {
                    textcolor(16);
                    cout << map1[i][j];
                    textcolor(7);
                }
                else
                {
                    cout << map1[i][j];
                }
            }
        cout << endl;
    }

}

void Ve_Xe(int x, int y)
{
    map1[x][y]    = '$'; // Giữa xe
    map1[x][y-1]  = 'I'; // Bên trái xe
    map1[x][y+1]  = 'I'; // Bên phải xe
    map1[x-1][y-1]= 'O';
    map1[x-1][y+1]= 'O';
    map1[x+1][y-1]= 'O'; // 4 Bánh xe
    map1[x+1][y-1]= 'O';
}

int main()
{
    int x =20, y=20;
    Ve_Xe(x, y);
    Ve_Duong_Dua();
    In_Duong_Dua();

    return 0;
}
