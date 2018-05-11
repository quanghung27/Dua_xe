#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include"HamTienIch.h"
using namespace std;

char map[50][50];


void VeDuongDua_1()
{
	for(int i = 0; i < 30; i++)         // Đường đua dài rộng 30
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 == 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void VeDuongDua_2()
{
	for(int i = 0; i < 30; i++)          // Đường đua dài rộng 30
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 != 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void InDuongDua()
{
	for(int i = 0; i < 30; i++)
	{
		cout << "\t\t\t";
		for(int j = 0; j < 30; j++)
		{
			if(j == 0 || j == 29)           // In Đường Đua
			{
				textcolor(191);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}
			else if(j == 14)
			{
				textcolor(15);
				cout << map[i][j];
				textcolor(7);

				map[i][j] = ' ';            // Xóa đường giữa
			}

			else if(map[i][j] == 'I' || map[i][j] == 'O' || map[i][j] == '$') // In XePlayer
			{
				textcolor(14);              // Màu vàng
				cout << map[i][j];
				textcolor(7);               // Trở lại màu bình thường
			}

			else if(map[i][j] == '!')      // Xe chướng ngại vật
			{
				textcolor(200);
				cout << map[i][j];
				textcolor(7);
			}

			// Những ký tự không phải là xe.
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void VeXeNguoiChoi(int x, int y)
{
	map[x][y]         = '$'; // Thân xe.
	map[x][y - 1]     = 'I'; // Bên trái thân xe.
	map[x][y + 1]     = 'I'; // Bên phải thân xe.
	map[x - 1][y - 1] = 'O'; // Bánh xe trên bên trái.
	map[x + 1][y - 1] = 'O'; // Bánh xe dưới bên trái.
	map[x - 1][y + 1] = 'O'; // Bánh xe trên bên phải.
	map[x + 1][y + 1] = 'O'; // Bánh xe dưới bên phải.
}

void VeXeChuongNgaiVat(int x, int y)
{
	map[x][y]         = '!'; // Thân xe.
	map[x][y - 1]     = '!'; // Bên trái thân xe.
	map[x][y + 1]     = '!'; // Bên phải thân xe.
	map[x - 1][y - 1] = '!'; // Bánh xe trên bên trái.
	map[x + 1][y - 1] = '!'; // Bánh xe dưới bên trái.
	map[x - 1][y + 1] = '!'; // Bánh xe trên bên phải.
	map[x + 1][y + 1] = '!'; // Bánh xe dưới bên phải.
}

void XoaXe(int x, int y)
{
	map[x][y]         = ' '; // Thân xe.
	map[x][y - 1]     = ' '; // Bên trái thân xe.
	map[x][y + 1]     = ' '; // Bên phải thân xe.
	map[x - 1][y - 1] = ' '; // Bánh xe trên bên trái.
	map[x + 1][y - 1] = ' '; // Bánh xe dưới bên trái.
	map[x - 1][y + 1] = ' '; // Bánh xe trên bên phải.
	map[x + 1][y + 1] = ' '; // Bánh xe dưới bên phải.
}
void KiemTraVaCham(int &x, int &y){
    if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
        {
            exit(0);
        }

}

void DiChuyenXe(int &x, int &y)         // x, y là tọa độ hiện tại của xe.
{
	if(GetAsyncKeyState(VK_LEFT))       // Sang trái
	{
		if(y > 2)
		{
		    KiemTraVaCham(x,y);
			XoaXe(x,y);
			y--;                    // Giảm cột xuống.
			VeXeNguoiChoi(x, y);    // Vẽ lại xe.


		}

	}

	else if(GetAsyncKeyState(VK_RIGHT))     // Sang phải
	{
		if(y <= 26)
		{
		    KiemTraVaCham(x, y);
            XoaXe(x,y);
			y++;                    // Tăng cột lên.
			VeXeNguoiChoi(x, y);   // Vẽ lại xe.


		}
	}

	else if(GetAsyncKeyState(VK_UP))    // Đi lên tên
	{
		if(x > 1)
		{
		    KiemTraVaCham(x, y);
			XoaXe(x,y);
			x--;                    // Giảm dòng.
			VeXeNguoiChoi(x, y);    // Vẽ lại xe.
		}
	}

	else if(GetAsyncKeyState(VK_DOWN))      // Đi xuống
	{
		if(x <= 27)                         // Chạm biên dưới
		{
		    KiemTraVaCham(x, y);
			XoaXe(x,y);
			x++;                    // Tăng số dòng.
			VeXeNguoiChoi(x, y);    // Vẽ lại xe.
		}
	}
}



int main()
{
    int Diem=0;
    int timesleep=100;
	int x = 28, y = 14;     // Tọa độ của xe Player
	int x1 = 2, y1;         // Tọa độ xe chướng ngại vật động
	int x2 = 5, y2 = 10;    // Tọa độ xe chướng ngại vật tĩnh
	int a = 0;
	while(true)
	{
		a++;
		if(a % 2 != 0)
		{
			VeDuongDua_1();
		}
		else
		{
			VeDuongDua_2();
		}
		srand(time(0));             // Tạo số ngẫu nhiên
		y1 = 2 + rand() % 26;

		VeXeNguoiChoi(x, y);
		VeXeChuongNgaiVat(x1, y1);  // Xe động
		VeXeChuongNgaiVat(x2, y2);  // Xe tĩnh

		XoaManHinh();

		InDuongDua();

		DiChuyenXe(x, y);

		Sleep(timesleep);

		if(a >= 30)
		{
			a = 0;
		}
        KiemTraVaCham(x, y);
		XoaXe(x1, y1);
		x1++;                       // Xe động di chuyển
		if(x1 == 31)
		{
		    Diem=Diem+1;
		    timesleep=timesleep-1;
			x1 = 2;
		}

		XoaXe(x2, y2);              // Xe tĩnh
		x2++;
		if(x2 == 31)
		{
		    Diem=Diem+1;
		    timesleep=timesleep-1;
			x2 = 5;
			y2 = 2 + rand() % 26;
		}
    while(timesleep<0)
        timesleep=0;
	cout << "Diem cua ban: "<< Diem;
	}
	return 0;
}
