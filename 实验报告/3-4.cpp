#include <bits/stdc++.h>
using namespace std;

char ch[10000], op;

int main() {
    gets(ch);
    cin >> op;
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] != op) cout << ch[i];
    }

    return 0;
}
