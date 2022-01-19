#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;
int n;
int tr[maxn], a[maxn], ans[maxn];

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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    add(1, 1);
    for(int i = 2; i <= n; i ++){
        cin >> a[i];
        add(i, 1);
    }

    for(int i = n; i >= 0; i --){
        int k = a[i] + 1;
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(ask(mid) >= k) r = mid;
            else l = mid + 1;
        }
        add(l, -1);
        ans[i] = l;
    }

    for(int i = 1; i <= n; i ++) cout << ans[i] << endl;

    return 0;
}
