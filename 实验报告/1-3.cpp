#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
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

    return 0;
}
