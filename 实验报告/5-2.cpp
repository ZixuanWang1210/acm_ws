#include <iostream>
using namespace std;
void paixu(int *a) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            int t;
            if (*(a + j) < *(a + j + 1)) {
                t = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = t;
            }
        }
    }
}
int main() {
    int a[3];
    cout << "请输入3个整数" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    paixu(a);
    cout << "排序好的数组是：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
