#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

int n, c, ans;
long long a[maxn];

int find(int x){
    int pos = lower_bound(a, a + n, x) - a;
    if(a[pos] == x){
        int num = 0;
        for(int i = pos; a[i] == x; i++){
            num ++;
        }
        return num;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    for(int i = 0; i < n; i++){
        int tmp = a[i] + c;
        int t = find(tmp);
        if(t) ans += t;
        if(tmp > a[n - 1]) break;
    }

    cout << ans;
    return 0;
}