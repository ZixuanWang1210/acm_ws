#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
const int maxn = 1e6 + 10;
int a[maxn], idx;
bool st[maxn];

int get(int n){
    memset(st, 1, sizeof st); // 默然全部是质数
    for(int i = 2; i <= n; i++){
        if(st[i]){
            a[idx ++] = i;
        }
        for(int j = 0; a[j] <= n / i && j <= idx; j++){
            st[a[j] * i] = false;
            if(i % a[j] == 0) break;
        }
    }
    cout << idx;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;

    
    get(n);
        // for(int i = 0; i < idx; i++)
        // {
        //     cout << a[i] << ",";
        // }

    return 0;
}
