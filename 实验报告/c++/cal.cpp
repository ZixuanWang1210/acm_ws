#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
char x[10][20];
int H[20];
int Z[20];
int h, v;//闁跨喕顢滈幉瀣闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿燂拷
char ch = 'd';
int len = 3;
char f;
void getFood()//妞嬬喖鏁撻弬銈嗗
{
	h = rand() % 10;
	v = rand() % 20;
	if (x[h][v] == 1)
	{
		getFood();
	}
	else
		x[h][v] = 3;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚笰SCII闁跨喐鏋婚幏铚傝礋3
}
void print()
{
	for (int i = 0; i <len; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻崣顐ゃ€嬮幏宄扮秿闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏宄板弿闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔诲▏椤庮垽璁ｉ幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撶槐绐糃II闁跨喐鏋婚幏铚傝礋1闁跨喐鏋婚幏锟�
	{
		x[H[i]][Z[i]] = 1;
	}
	for (int i = 0; i < 10; i++)//闁跨喓鐓幉瀣闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲绱￠柨鐔告灮閹风兘鏁撻弬銈嗗
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%c", x[i][j]);
		}
		printf("\n");
	}
	Sleep(500);//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�0.5闁跨喐鏋婚幏锟� 闁跨喐纾ヨぐ鎾绘晸閺傘倖瀚归柨鐔告灮閹凤拷0.5闁跨喕顕犻崝銊ょ闁跨喐鏋婚幏锟�
	system("cls");//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔烘畷娓氬灝鐨㈤柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸闁鹃绱幏鐑芥晸閺傘倖瀚�
}
void getkey()//闁跨喎褰ㄧ拋瑙勫闁跨喕顫楅崙銈嗗闁跨喖鎽涵閿嬪闁跨喐鏋婚幏锟�
{
	if (_kbhit())//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲缍嶉柨鐔告灮閹风柉绠ｉ柨鐔告灮閹烽鐛婇柨鐔活敎鏉堢偓瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚�
	{
		ch = _getch();//闁跨喐鏋婚幏宄板絿闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崐锟�
		if (ch == f)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔诲▏鐢喗瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔侯仾閻ㄥ嫬鍤栭幏鐑芥晸閺傘倖瀚规稉鈧柨鐔告灮閹风兘鏁撻弬銈嗗娑撴椽鏁撻弬銈嗗閺佸牓鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崣鏍晸閺傘倖瀚归柨鐔兼應閻ㄥ嫮銆嬮幏鐑芥晸閺傘倖瀚归崐锟�
		{
			getkey();
		}
		else if ((ch == 100 && f != 97) || ch == 119 && f != 115 || ch == 97 && f != 100 || ch == 115 && f != 119) //闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔峰建鐠佽瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏閿嬫櫏闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱妞傞柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閹存帗婀為柨鐔告灮閹风兘鏁撶粩顓犵搼缁涘缍囬幏锟�
			f = ch;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱鏅ラ弮鍫曟晸閺傘倖瀚筩h闁跨喐鏋婚幏宄扳偓闂磋礋f
		else
			getkey();//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹烽攱鏅ラ弮鍫曟晸閺傘倖瀚归柨鐔兼應鐠囇勫闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐕傛嫹
	}
}
void left()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崗銊╂晸閺傘倖瀚归崜宥夋晸閺傘倖瀚规稉鈧柨鐔告灮閹凤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]--;
}
void right()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崗銊╂晸閺傘倖瀚归崜宥夋晸閺傘倖瀚规稉鈧柨鐔告灮閹凤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]++;
}
void up()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len-1; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崗銊╂晸閺傘倖瀚归崜宥夋晸閺傘倖瀚规稉鈧柨鐔告灮閹凤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]--;
}
void down()
{
	x[H[0]][Z[0]] = '-';
	for (int i = 0; i <len - 1; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归崗銊╂晸閺傘倖瀚归崜宥夋晸閺傘倖瀚规稉鈧柨鐔告灮閹凤拷
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]++;
}
int main()
{
	f = ch;//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚规慨瀣晸閺傘倖瀚归柨鐔哄珱鐠佽瀚归柨鐔告灮閹风兘鏁撻弬銈嗗閸婂ジ鏁撻弬銈嗗f
	for (int i = 0; i < 10; i++) //闁跨喐鏋婚幏鐑芥晸鐞涙鍤栭幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲鍙忛柨鐔告灮閹风兘鏁撻弬銈嗗'-'闁跨喐鏋婚幏閿嬬３椤掑﹥瀚归柨鐔告灮閹风柉鐨柨鐔虹哺绾攱瀚归柨鐕傛嫹
	{
		for (int j = 0; j < 20; j++)
		{
			x[i][j] = '-';
		}
	}
	for (int i = 0; i <10; i++)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撴渚亾閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏鐑芥晸閿燂拷
	{
		Z[i] = 0;
		H[i] = 0;
	}
	for (int i = 0; i <len; i++)//闁跨喐鏋婚幏宄扮秿閸擄拷3闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹风兘鏁撻弬銈嗗闁跨喐鏋婚幏锟�
		Z[i] = i;
	getFood();
	while (len<=19)//闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔侯仾绾板瀚归柨鐔告灮閹风柉鐓妵鏍晸閺傘倖瀚归柨鐔稿复椤曞棙瀚归柨鐔告灮閹风兘鏁撴潏鍐挎嫹
	{
		getkey();
		if (x[h][v]!=3)//妞嬬喖鏁撻弬銈嗗濞岋繝鏁撻弬銈嗗闁跨喎澹欓幍宥勭串閹峰嘲褰囨鐔兼晸閺傘倖瀚�
		{
          getFood();
		}
		switch (f)
		{
		case 'w':
			  if(H[len-1]-1<0)
			 {
			  printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲顣鹃柨鐔告灮閹风﹥n");
		      return 0;
             }
			else if (H[len-1]-1==h&&Z[len-1]==v)//闁跨喎褰ㄧ拋瑙勫闁跨喐鏋婚幏鐤洣闁跨喓顏喊澶嬪闁跨喖鎽棃鈺傚闁跨喐鏋婚幏鐑芥晸鐟欐帒鍤栭幏鐑芥晸閺傘倖瀚规鐔兼晸閺傘倖瀚归悧锟犳晸閿燂拷
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
			printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲顣鹃柨鐔告灮閹风﹥n");
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
			printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲顣鹃柨鐔告灮閹风﹥n");
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
			printf("闁跨喐鏋婚幏鐑芥晸閺傘倖瀚归柨鐔告灮閹峰嘲顣鹃柨鐔告灮閹风﹥n");
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
}

void get_from_to() {
    out("请输入两个整数表示数的范围");
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (!(i % 3) && !(i % 5)) {
            cout << "这个数是" << i << endl;
            return;
        }
    }
    cout << "在这个范围中没有树满足条件" << endl;
    return;
}

bool narcissus(int a) {
    int sum = 0;

    int x1 = a / 100;
    int x2 = a % 100 / 10;
    int x3 = a % 10;
    sum = x1 * x1 * x1 + x2 * x2 * x2 + x3 * x3 * x3;
    if (sum == a)
        return 1;
    else
        return 0;
}

void ppdi() {
    out("水仙花数为");
    for (int i = 100; i <= 999; i++) {
        if (narcissus(i)) cout << i << ' ';
    }
}

int get_max(int &a, int &b) {
    if (a > b) {
        int t = b;
        b = a, a = t;
    }
    return b;
}

void get_max() {
    out("请输入两个整数 a b");
    out("请输入两个整数中较大的为");
    int a, b;
    cin >> a >> b;
    cout << get_max(a, b) << endl;
}

void bubble_sort() {
    out("请输入10个数");
    int a[100];
    out("冒泡排序后的结果是：");
    for (int i = 1; i <= 10; i++) cin >> a[i];
    for (int i = 1; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
        cout << a[i] << ' ';
    }
}

void trans() {
    int a[10][10];
    out("请输入一个3x4的矩阵");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> a[j][i];
        }
    }
    out("该矩阵的转置为");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

void mat_sum() {
    int a[100][100];
    int sum = 0;
    out("请输入3x3的矩阵");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            if (i == j) sum += a[i][j];
        }
    }
    cout << sum << endl;
    return;
}

void word_cnt() {
    string s;
    out("请输入一句话");
    getline(cin, s);
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') cnt++;
    }
    out("单词的个数时：");
    cout << cnt++ << endl;
}

void grade_sort() {
    struct Stu {
        int Sno;
        string Sname;
        int Sgrade;
        bool operator<(const Stu &t) {
            return Sgrade < t.Sgrade;
        }
    };
    Stu arr[20];
    out("请依次输入每位学生的：学号、姓名、成绩");
    for (int i = 1; i <= 10; i++) {
        int Sno, Sgrade;
        string name;
        cin >> Sno >> name >> Sgrade;
        arr[i] = {Sno, name, Sgrade};
    }
    int sum = 0, avg = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = i; j <= 10; j++) {
            if (arr[j] < arr[i]) swap(arr[i], arr[j]);
        }
        sum += arr[i].Sgrade;
    }
    for (int i = 1; i <= 10; i++) {
        cout << "学生姓名：	" << arr[i].Sname << endl;
        cout << "学生学号：	" << arr[i].Sno << endl;
        cout << "学生成绩：	" << arr[i].Sgrade << endl;
        cout << endl << endl;
    }
    cout << "学生的总成绩为：	" << sum << endl;
    cout << "学生的平均成绩为：	" << (double)sum / 10 << endl;
}

void up_grade() {
    FILE *fp;
    fp = fopen("D:\\my.txt", "r+");
    if (fp == NULL) {
        out("不能找到文件，请检查文件是否已经创建");
    }
    int grade[100] = {0};

    for (int i = 1; i <= 10; i++) {
        int soc = 0;
        fscanf(fp, "%d", &soc);
        grade[i] = soc;
    }
    rewind(fp);
    for (int i = 1; i <= 10; i++) {
        fprintf(fp, "%d\n", grade[i] + 10);
    }
    out("成绩输出完成，请打开文件检查输出");
    fclose(fp);
    return;
}

int init_chain() {
    struct Student {
        int num;
        float score;
        struct Student *next;
    };
    struct Student a, b, c, *head, *p;
    a.num = 101;
    a.score = 89.5;
    b.num = 103;
    b.score = 90;
    c.num = 107;
    c.score = 85;
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    p = head;
    do {
        printf("%1d %5.1f\n", p->num, p->score);
        p = p->next;
    } while (p != NULL);
    return 0;
}

void home() {
    cout << R"( 
        ***********************************
                     小小计算器             
                     1 加法                 
                     2 减法                 
                     3 乘法                 
                     4 除法   
                     5 取模运算
                     6 计算圆面积
                     7 判断数字的位数                      
                     8 判断闰年                              
                     9 成绩转换                              
                     10 计算从1到输入数之间的奇数和 （for）          
                     11 计算从1到输入数之间的偶数和 （while）          
                     12 输出从1到输入数之间所有3的倍数 （do-while）          
                     13 求即被3整除又被5整除的数          
                     14 求水仙花数
                     15 求最大最小值 
                     16 冒泡排序
                     17 矩阵转置
                     18 求对角线和
                     19 统计单词个数
                     20 创建静态链表
                     21 输出静态链表
                     22 学生成绩排序 
                     23 学生成绩普涨10分 
                     25 退出
        ***********************************
        )"
         << endl;
    return;
}

void opt() {
    int op;
    out("请输入模式");
    cin >> op;
    system("cls");
    if (op == 1)
        add();
    else if (op == 2)
        sub();
    else if (op == 3)
        mul();
    else if (op == 4)
        div();
    else if (op == 5)
        mod();
    else if (op == 6)
        get_area();
    else if (op == 7)
        split();
    else if (op == 8)
        judge_leap();
    else if (op == 9)
        grade();
    else if (op == 10)
        get_sum1();
    else if (op == 11)
        get_sum2();
    else if (op == 12)
        get_sum3();
    else if (op == 13)
        get_from_to();
    else if (op == 14)
        ppdi();
    else if (op == 15)
        get_max();
    else if (op == 16)
        bubble_sort();
    else if (op == 17)
        trans();
    else if (op == 18)
        mat_sum();
    else if (op == 19)
        word_cnt();
    else if (op == 22)
        grade_sort();
    else if (op == 23)
        up_grade();
    else if (op == 20)
        init_chain();
    else if (op == 21)
        init_chain();
    else {
        exit(0);
    }
    cout << endl;
    out("====================");
    out("输入1返回目录,输入2退出程序");
    cout << "====================" << endl;

    int t;
    cin >> t;
    if (t == 1) {
        system("cls");
        return;
    } else {
        exit(0);
    }
}

int main() {
    while (1) {
        home();
        opt();
    }

    return 0;
}
