#include <bits/stdc++.h>
using namespace std;

void out(string s) {
    cout << s << endl;
}

void add() {
    int a, b;
    out("�������������a��b");
    cin >> a >> b;
    out("a+b��ֵΪ");
    cout << a + b << endl;
    out("�����ʮ������ʽ�ǣ�");
    cout << a + b << endl;
    out("����İ˽�����ʽ�ǣ�");
    cout << oct << a + b << endl;
    out("�����ʮ��������ʽ�ǣ�");
    cout << hex << a + b << endl;

    return;
}

void sub() {
    int a, b;
    out("�������������a��b");
    cin >> a >> b;
    out("a-b��ֵΪ");
    cout << a - b << endl;
    out("�����ʮ������ʽ�ǣ�");
    cout << a - b << endl;
    out("����İ˽�����ʽ�ǣ�");
    cout << oct << a - b << endl;
    out("�����ʮ��������ʽ�ǣ�");
    cout << hex << a - b << endl;
    return;
}

void mul() {
    double a, b;
    out("���������������a��b");
    cin >> a >> b;
    out("a*b��ֵΪ");
    cout << a * b << endl;
    out("�˷������ָ����ʽ�ǣ�");
    printf("%E\n", a * b);
    return;
}

void div() {
    int a, b;
    out("�������������a��b");
    cin >> a >> b;
    if (b == 0) {
        out("ע�⣡b����Ϊ0.����������");
        div();
        return;
    }
    out("a/b��ֵΪ");
    cout << (double)a / b << endl;
    out("�˷������ָ����ʽ�ǣ�");
    printf("%E\n", a / b);
    return;
}

void mod() {
    int a, b;
    out("�������������a��b");
    cin >> a >> b;
    if (b == 0) {
        out("ע�⣡b����Ϊ0.����������");
        mod();
        return;
    }
    out("a%b��ֵΪ");
    cout << a % b << endl;
    return;
}

void get_area() {
    int r;
    out("����Բ�İ뾶r");
    cin >> r;
    const double PI = 3.1415926;
    out("Բ�����Ϊ��");
    cout << (double)r * PI << endl;
    out("������λС���Ľ���ǣ�");
    cout << fixed << setprecision(2) << (double)r * PI << endl;
    return;
}

void split() {
    int x;
    out("��������Ҫ���в�ֵ�������");
    cin >> x;
    if (x < 0 || x > 999) {
        out("���벻�Ϸ���������������λ���ڵ�������");
        split();
        return;
    }
    string s[3] = {"�������ĸ�λΪ��", "��������ʮλΪ��", "�������İ�λΪ��"};
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
    out("������ѧ���ĳɼ�");
    cin >> x;
    cout << "ѧ���ĳɼ��ȼ�Ϊ";
    if (x < 0 || x > 100) {
        out("�������ݲ��Ϸ�������������");
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
    out("�����������������");
    int year;
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is ����" << endl;
    } else
        cout << year << " is ƽ��" << endl;
    return;
}

void get_sum1() {
    out("��������㷶Χ n");
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) sum += i;
    }
    cout << "1��������֮��������ͣ�" << sum << endl;
    return;
}

void get_sum2() {
    out("��������㷶Χ n");
    int n;
    cin >> n;
    int sum = 0;
    n++;
    while (n--) {
        if (!(n & 1)) sum += n;
    }
    cout << "1��������֮��������ͣ�" << sum << endl;
    return;
}

void get_sum3() {
    out("��������㷶Χ n");
    int n;
    cin >> n;
    int sum = 0;
    do {
        if (!(n & 3)) sum += n;
    } while (n--);
    cout << "1��������֮���3�ı����ĺͣ�" << sum << endl;
    return;
}

void get_from_to() {
    out("����������������ʾ���ķ�Χ");
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (!(i % 3) && !(i % 5)) {
            cout << "�������" << i << endl;
            return;
        }
    }
    cout << "�������Χ��û������������" << endl;
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
    out("ˮ�ɻ���Ϊ");
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
    out("�������������� a b");
    out("���������������нϴ��Ϊ");
    int a, b;
    cin >> a >> b;
    cout << get_max(a, b) << endl;
}

void bubble_sort() {
    out("������10����");
    int a[100];
    out("ð�������Ľ���ǣ�");
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
    out("������һ��3x4�ľ���");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> a[j][i];
        }
    }
    out("�þ����ת��Ϊ");
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
    out("������3x3�ľ���");
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
    out("������һ�仰");
    getline(cin, s);
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') cnt++;
    }
    out("���ʵĸ���ʱ��");
    cout << cnt++ << endl;
}

void home() {
    cout << R"( 
        ***********************************
                     СС������             
                     1 �ӷ�                 
                     2 ����                 
                     3 �˷�                 
                     4 ����   
                     5 ȡģ����
                     6 ����Բ���
                     7 �ж����ֵ�λ��                      
                     8 �ж�����                              
                     9 �ɼ�ת��                              
                     10 �����1��������֮��������� ��for��          
                     11 �����1��������֮���ż���� ��while��          
                     12 �����1��������֮������3�ı��� ��do-while��          
                     13 �󼴱�3�����ֱ�5��������          
                     14 ��ˮ�ɻ���
                     15 �������Сֵ 
                     16 ð������
                     17 ����ת��
                     18 ��Խ��ߺ�
                     19 ͳ�Ƶ��ʸ���
                     20 �˳�
        ***********************************
        )"
         << endl;
    return;
}

void opt() {
    int op;
    out("������ģʽ");
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
    out("����1����Ŀ¼,����2�˳�����");
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
