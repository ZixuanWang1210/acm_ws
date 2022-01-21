#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

int n;
const int maxn = 5e5 + 10;
int tr[maxn], a[maxn], bk[maxn];
unordered_map<int, int> mp;

int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(; x <= n; x += lowbit(x)) tr[x] += k;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

int get(){
    int idx = 1;
    memcpy(bk, a, sizeof a);
    sort(a, a + n + 1);
    for(int i = 1; i <= n; i ++){
        mp[a[i]] = idx ++;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    get();

    for(int i = n; i; i --){
        int t = mp[bk[i]];
        add(t, 1);
        ans += ask(t - 1);
    }
    
    cout << ans;
    return 0;
}
