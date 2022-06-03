#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
char x[10][20];
int H[20];
int Z[20];
int h, v;//锟街憋拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟�
char ch = 'd';
int len = 3;
char f;
void getFood()//食锟斤拷
{
	h = rand() % 10;
	v = rand() % 20;
	if (x[h][v] == 1)
	{
		getFood();
	}
	else
		x[h][v] = 3;//锟斤拷锟斤拷ASCII锟斤拷为3
}
void print()
{
	for (int i = 0; i <len; i++)//锟斤拷锟斤拷锟斤拷锟叫硷拷录锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷全锟斤拷锟斤拷锟轿︼拷锟斤拷锟斤拷锟紸SCII锟斤拷为1锟斤拷
	{
		x[H[i]][Z[i]] = 1;
	}
	for (int i = 0; i < 10; i++)//锟矫憋拷锟斤拷锟斤拷锟斤拷式锟斤拷锟斤拷
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	Sleep(500);//锟斤拷锟斤拷0.5锟斤拷 锟洁当锟斤拷锟斤拷0.5锟诫动一锟斤拷
	system("cls");//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟皆便将锟斤拷锟斤拷锟斤拷锟铰伙拷锟斤拷
}
void getkey()//锟叫讹拷锟角凤拷锟铰硷拷锟斤拷
{
	if (_kbhit())//锟斤拷锟斤拷锟斤拷录锟斤拷蹋锟斤拷突锟街达拷锟斤拷锟斤拷锟斤拷锟斤拷
	{
		ch = _getch();//锟斤拷取锟斤拷锟斤拷值
		if (ch == f)//锟斤拷锟斤拷锟轿帮拷锟斤拷锟斤拷锟斤拷锟斤拷锟竭的凤拷锟斤拷一锟斤拷锟斤拷为锟斤拷效锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷取锟斤拷锟铰的硷拷锟斤拷值
		{
			getkey();
		}
		else if ((ch == 100 && f != 97) || ch == 119 && f != 115 || ch == 97 && f != 100 || ch == 115 && f != 119) //锟斤拷锟斤拷锟叫讹拷锟斤拷锟斤拷锟斤拷效锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷时锟斤拷锟斤拷锟斤拷锟戒朝锟斤拷锟竭等等ｏ拷
			f = ch;//锟斤拷锟斤拷锟斤拷效时锟斤拷ch锟斤拷值为f
		else
			getkey();//锟斤拷锟斤拷锟斤拷效时锟斤拷锟铰诧拷锟斤拷锟斤拷锟�
	}
}
void left()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//锟斤拷锟斤拷全锟斤拷前锟斤拷一锟斤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]--;
}
void right()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//锟斤拷锟斤拷全锟斤拷前锟斤拷一锟斤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]++;
}
void up()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len-1; i++)//锟斤拷锟斤拷全锟斤拷前锟斤拷一锟斤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]--;
}
void down()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//锟斤拷锟斤拷全锟斤拷前锟斤拷一锟斤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]++;
}
int main()
{
	f = ch;//锟斤拷锟斤拷始锟斤拷锟狡讹拷锟斤拷锟斤拷值锟斤拷f
	for (int i = 0; i < 10; i++) //锟斤拷锟街凤拷锟斤拷锟斤拷全锟斤拷锟斤拷'-'锟斤拷洌拷锟斤拷谐锟绞硷拷锟�
	{
		for (int j = 0; j < 20; j++)
		{
			x[i][j] = '-';
		}
	}
	for (int i = 0; i <10; i++)//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟饺拷锟斤拷锟斤拷锟�
	{
		Z[i] = 0;
		H[i] = 0;
	}
	for (int i = 0; i <len; i++)//锟斤拷录前3锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
		Z[i] = i;
	getFood();
	while (len<=19)//锟斤拷锟斤拷锟竭碉拷锟斤拷蟪ざ锟斤拷锟接拷锟斤拷锟较�
	{
		getkey();
		if (x[h][v]!=3)//食锟斤拷没锟斤拷锟剿才伙拷取食锟斤拷
		{
          getFood();
		}
		switch (f)
		{
		case 'w':
			  if(H[len-1]-1<0)
			 {
			  printf("锟斤拷锟斤拷锟斤拷墙锟斤拷\n");
		      return 0;
             }
			else if (H[len-1]-1==h&&Z[len-1]==v)//锟叫讹拷锟斤拷要锟竭碉拷锟铰革拷锟斤拷锟角凤拷锟斤拷食锟斤拷牡锟�
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
			printf("锟斤拷锟斤拷锟斤拷墙锟斤拷\n");
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
			printf("锟斤拷锟斤拷锟斤拷墙锟斤拷\n");
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
			printf("锟斤拷锟斤拷锟斤拷墙锟斤拷\n");
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
