#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
char x[10][20];
int H[20];
int Z[20];
int h, v;//閿熻鎲嬫嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
char ch = 'd';
int len = 3;
char f;
void getFood()//椋熼敓鏂ゆ嫹
{
	h = rand() % 10;
	v = rand() % 20;
	if (x[h][v] == 1)
	{
		getFood();
	}
	else
		x[h][v] = 3;//閿熸枻鎷烽敓鏂ゆ嫹ASCII閿熸枻鎷蜂负3
}
void print()
{
	for (int i = 0; i <len; i++)//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鍙》鎷峰綍閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰叏閿熸枻鎷烽敓鏂ゆ嫹閿熻娇顎讣鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓绱窼CII閿熸枻鎷蜂负1閿熸枻鎷�
	{
		x[H[i]][Z[i]] = 1;
	}
	for (int i = 0; i < 10; i++)//閿熺煫鎲嬫嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰紡閿熸枻鎷烽敓鏂ゆ嫹
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	Sleep(500);//閿熸枻鎷烽敓鏂ゆ嫹0.5閿熸枻鎷� 閿熸磥褰撻敓鏂ゆ嫹閿熸枻鎷�0.5閿熻鍔ㄤ竴閿熸枻鎷�
	system("cls");//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熺殕渚垮皢閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓閾颁紮鎷烽敓鏂ゆ嫹
}
void getkey()//閿熷彨璁规嫹閿熻鍑ゆ嫹閿熼摪纭锋嫹閿熸枻鎷�
{
	if (_kbhit())//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰綍閿熸枻鎷疯箣閿熸枻鎷风獊閿熻杈炬嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
	{
		ch = _getch();//閿熸枻鎷峰彇閿熸枻鎷烽敓鏂ゆ嫹鍊�
		if (ch == f)//閿熸枻鎷烽敓鏂ゆ嫹閿熻娇甯嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熺鐨勫嚖鎷烽敓鏂ゆ嫹涓€閿熸枻鎷烽敓鏂ゆ嫹涓洪敓鏂ゆ嫹鏁堥敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鍙栭敓鏂ゆ嫹閿熼摪鐨勭》鎷烽敓鏂ゆ嫹鍊�
		{
			getkey();
		}
		else if ((ch == 100 && f != 97) || ch == 119 && f != 115 || ch == 97 && f != 100 || ch == 115 && f != 119) //閿熸枻鎷烽敓鏂ゆ嫹閿熷彨璁规嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋晥閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋椂閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鎴掓湞閿熸枻鎷烽敓绔瓑绛夛綇鎷�
			f = ch;//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋晥鏃堕敓鏂ゆ嫹ch閿熸枻鎷峰€间负f
		else
			getkey();//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋晥鏃堕敓鏂ゆ嫹閿熼摪璇ф嫹閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
	}
}
void left()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//閿熸枻鎷烽敓鏂ゆ嫹鍏ㄩ敓鏂ゆ嫹鍓嶉敓鏂ゆ嫹涓€閿熸枻鎷�
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]--;
}
void right()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//閿熸枻鎷烽敓鏂ゆ嫹鍏ㄩ敓鏂ゆ嫹鍓嶉敓鏂ゆ嫹涓€閿熸枻鎷�
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]++;
}
void up()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len-1; i++)//閿熸枻鎷烽敓鏂ゆ嫹鍏ㄩ敓鏂ゆ嫹鍓嶉敓鏂ゆ嫹涓€閿熸枻鎷�
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]--;
}
void down()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//閿熸枻鎷烽敓鏂ゆ嫹鍏ㄩ敓鏂ゆ嫹鍓嶉敓鏂ゆ嫹涓€閿熸枻鎷�
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]++;
}
int main()
{
	f = ch;//閿熸枻鎷烽敓鏂ゆ嫹濮嬮敓鏂ゆ嫹閿熺嫛璁规嫹閿熸枻鎷烽敓鏂ゆ嫹鍊奸敓鏂ゆ嫹f
	for (int i = 0; i < 10; i++) //閿熸枻鎷烽敓琛楀嚖鎷烽敓鏂ゆ嫹閿熸枻鎷峰叏閿熸枻鎷烽敓鏂ゆ嫹'-'閿熸枻鎷锋磳顒婃嫹閿熸枻鎷疯皭閿熺粸纭锋嫹閿燂拷
	{
		for (int j = 0; j < 20; j++)
		{
			x[i][j] = '-';
		}
	}
	for (int i = 0; i <10; i++)//閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓楗侯偓鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
	{
		Z[i] = 0;
		H[i] = 0;
	}
	for (int i = 0; i <len; i++)//閿熸枻鎷峰綍鍓�3閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷�
		Z[i] = i;
	getFood();
	while (len<=19)//閿熸枻鎷烽敓鏂ゆ嫹閿熺纰夋嫹閿熸枻鎷疯煪銇栭敓鏂ゆ嫹閿熸帴顕嗘嫹閿熸枻鎷烽敓杈冿拷
	{
		getkey();
		if (x[h][v]!=3)//椋熼敓鏂ゆ嫹娌￠敓鏂ゆ嫹閿熷壙鎵嶄紮鎷峰彇椋熼敓鏂ゆ嫹
		{
          getFood();
		}
		switch (f)
		{
		case 'w':
			  if(H[len-1]-1<0)
			 {
			  printf("閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰閿熸枻鎷穃n");
		      return 0;
             }
			else if (H[len-1]-1==h&&Z[len-1]==v)//閿熷彨璁规嫹閿熸枻鎷疯閿熺纰夋嫹閿熼摪闈╂嫹閿熸枻鎷烽敓瑙掑嚖鎷烽敓鏂ゆ嫹椋熼敓鏂ゆ嫹鐗￠敓锟�
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			up();
			break;
		case 'a':
			if(Z[len-1]-1<0)
			{
			printf("閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰閿熸枻鎷穃n");
		    return 0;
			}
            else if (H[len-1]==h&&Z[len-1]-1==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			left();
			break;
		case 's':
			if(H[len-1]+1>=10)
			{
			printf("閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰閿熸枻鎷穃n");
		    return 0;
			}
			if (H[len-1]+1==h&&Z[len-1]==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			down();
			break;
		case 'd':
			if(Z[len-1]+1>=20)
			{
			printf("閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰閿熸枻鎷穃n");
		    return 0;
			}
			if (H[len-1]==h&&Z[len-1]+1==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			right();
			break;
		}
		print();
	}
    printf("You win!\n");
	system("pause");
	return 0;
}
