#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

int n, ans = 1, cnt;
int p[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        p[cnt++] = a * 2, p[cnt++] = b * 2 + 1;
    }

    sort(p, p + cnt);

    int t = 0, _max = 1;
    for(int i = 0; i < cnt; i++){
        if(p[i] % 2 == 0) t ++;
        else t --;
        _max = max(_max, t);
    }

    cout << _max;
    return 0;
}