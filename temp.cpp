#include <iostream>

using namespace std;
const int N = 1e5 + 10;

int q[N];

int main() {
    int n;
    cin >> n;
    int hh = 0, tt = -1;
    while (n--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (op == "pop") {
            hh++;
        } else if (op == "empty") {
            if (hh <= tt)
                puts("NO");
            else
                puts("YES");
        } else {
            cout << q[hh] << endl;
        }
    }
}