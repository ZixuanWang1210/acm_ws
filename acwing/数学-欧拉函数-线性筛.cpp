#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e6 + 10;
int pri[maxn], cnt;
bool st[maxn];
int phi[maxn];

long long get(int n){
    phi[1] = 1;
    memset(st, 1, sizeof st);
    for(int i = 2; i <= n; i++){
        if(st[i]){
            pri[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; pri[j] <= n / i; j++){
            st[pri[j] * i] = false;
            if(i % pri[j] == 0){
                phi[pri[j] * i] = phi[i] * pri[j];
                break;
            }
            phi[pri[j] * i] = phi[i] * (pri[j] - 1);
        }
    }
    long long res = 0;
    for(int i = 1; i <= n; i++){
        res += phi[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n;
    cin >> n;

    cout << get(n);

    return 0;
}
