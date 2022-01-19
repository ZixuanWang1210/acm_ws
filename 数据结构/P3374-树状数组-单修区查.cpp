#include <bits/stdc++.h>
#define endl "\n"
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 5e5 + 10;
int tr[maxn];
int a[maxn];
int n, m;

int lowbit(int x){
    return x & -x;
}

void add(int x, int b){
    for(; x <= n; x += lowbit(x)) tr[x] += b;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        add(i, a[i]);
    }
    while(m -- ){
        int op; cin >> op;
        if(op == 1){
            int a, b; cin >> a >> b;
            add(a, b);
        }
        else{
            int a, b; cin >> a >> b;
            cout << ask(b) - ask(a - 1) << endl;
        }
    }


    return 0;
}
