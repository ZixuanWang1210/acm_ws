#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int maxn = 1e8 + 10;

int n, ans, idx;
bool st[maxn];
int pirm[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    memset(st, 0, sizeof st);
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            pirm[idx++] = i;
        }
        for(int j = 0; pirm[j] <= n / i; j++){
            st[pirm[j] * i] = true;
            if(i % pirm[j] == 0) break;
        }
    }

    cout << idx;
      

    return 0;
}
