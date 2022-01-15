#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
bool st[maxn];
int pirm[maxn];


int idx;
void get_pri(int x){
    memset(st, 0, sizeof st);
    for(int i = 2; i <= x; i++){
        if(!st[i]){
            pirm[idx ++] = i;
        }
        for(int j = 0; pirm[j] <= x / i; j ++){
            st[pirm[j] * i] = true;
            if(i % pirm[j] == 0) break;
        }
    }
    st[1] = true;
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ans = 0;
    int n; cin >> n;
    int a[maxn] = {0}, s[maxn] = {0};
    int _min = 0x3f3f3f3f, _max = -1;
    while(n--){
        int l, r; cin >> l >> r;
        a[l] ++;
        a[r + 1] --;
        _min = min(_min, l);
        _max = max(_max, r);
    }
    get_pri(_max);
    for(int i = _min; i <= _max; i++){
        s[i] = s[i - 1] + a[i];
        if(st[i] == false && s[i] != 0) ans ++;
    }
    cout << ans;
    return 0;
}
