#include <bits/stdc++.h>
using namespace std;

void out(string s) {
    cout << s << endl;
}

void add() {
    int a, b;
    out("请输出两个整数a和b");
    cin >> a >> b;
    out("a+b的值为");
    cout << a + b << endl;
    out("结果的十进制形式是：");
    cout << a + b << endl;
    out("结果的八进制形式是：");
    cout << oct << a + b << endl;
    out("结果的十六进制形式是：");
    cout << hex << a + b << endl;

    return;
}

void sub() {
    int a, b;
    out("请输出两个整数a和b");
    cin >> a >> b;
    out("a-b的值为");
    cout << a - b << endl;
    out("结果的十进制形式是：");
    cout << a - b << endl;
    out("结果的八进制形式是：");
    cout << oct << a - b << endl;
    out("结果的十六进制形式是：");
    cout << hex << a - b << endl;
    return;
}

void mul() {
    double a, b;
    out("请输出两个浮点数a和b");
    cin >> a >> b;
    out("a*b的值为");
    cout << a * b << endl;
    out("乘法结果的指数形式是：");
    printf("%E\n", a * b);
    return;
}

void div() {
    int a, b;
    out("请输出两个整数a和b");
    cin >> a >> b;
    if (b == 0) {
        out("注意！b不能为0.请重新输入");
        div();
        return;
    }
    out("a/b的值为");
    cout << (double)a / b << endl;
    out("乘法结果的指数形式是：");
    printf("%E\n", a / b);
    return;
}

void mod() {
    int a, b;
    out("请输出两个整数a和b");
    cin >> a >> b;
    if (b == 0) {
        out("注意！b不能为0.请重新输入");
        mod();
        return;
    }
    out("a%b的值为");
    cout << a % b << endl;
    return;
}

void get_area() {
    int r;
    out("请输圆的半径r");
    cin >> r;
    const double PI = 3.1415926;
    out("圆的面积为：");
    cout << (double)r * PI << endl;
    out("保留两位小数的结果是：");
    cout << fixed << setprecision(2) << (double)r * PI << endl;
    return;
}

void split() {
    int x;
    out("请输入需要进行拆分的正整数");
    cin >> x;
    if (x < 0 || x > 999) {
        out("输入不合法，请重新输入三位以内的正整数");
        split();
        return;
    }
    string s[3] = {"该整数的个位为：", "该整数的十位为：", "该整数的百位为："};
    int idx = 0;
    while (x) {
        int t = x % 10;
        cout << s[idx] << t << endl;
        idx++;
        x /= 10;
    }
    return;
}

void grade() {
    int x;
    out("请输入学生的成绩");
    cin >> x;
    cout << "学生的成绩等级为";
    if (x < 0 || x > 100) {
        out("输入数据不合法，请重新输入");
        grade();
        return;
    }
    if (x == 100) {
        cout << "A";
    } else {
        x /= 10;
        switch (x) {
            case 9:
                cout << "A";
                break;
            case 8:
                cout << "B";
                break;
            case 7:
                cout << "C";
                break;
            case 6:
                cout << "D";
                break;
            default:
                cout << "E";
                break;
        }
    }
    return;
}

void judge_leap() {
    out("请输入所需计算的年份");
    int year;
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is 闰年" << endl;
    } else
        cout << year << " is 平年" << endl;
    return;
}

void get_sum1() {
    out("请输入计算范围 n");
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) sum += i;
    }
    cout << "1到输入数之间的奇数和：" << sum << endl;
    return;
}

void get_sum2() {
    out("请输入计算范围 n");
    int n;
    cin >> n;
    int sum = 0;
    n++;
    while (n--) {
        if (!(n & 1)) sum += n;
    }
    cout << "1到输入数之间的奇数和：" << sum << endl;
    return;
}

void get_sum3() {
    out("请输入计算范围 n");
    int n;
    cin >> n;
    int sum = 0;
    do {
        if (!(n & 3)) sum += n;
    } while (n--);
    cout << "1到输入数之间的3的倍数的和：" << sum << endl;
    return;
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

// int get_max(int a,int b){
//     return a>b?a:b;
// }

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
                     20 退出
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
