#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pii;
// typedef long long ll;


// ll me[10000000];

ll erfen(ll x){
    // cout << x << endl;
    ll l = 1, r = 10000000, ans = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        ll tmp = (mid * (mid + 1)) >> 1;
        if(tmp < x){
            l = mid + 1;
        }
        else r = mid - 1, ans = mid;;
    }
    return ans;
}

pii judge(ll x){
    // cout << x << endl;
    ll idx = 0, idx2 = 0;
    // do{
    //     idx ++;
    //     if(!me[idx]) me[idx] = idx * (idx + 1) / 2;
        
    // }while(me[idx] < x);

    // cout << x << endl;
    idx = erfen(x);
    // cout <<" 1 " << erfen(x) << endl << endl;

    ll res = (idx * (idx + 1) >> 1) - x;
    ll f_x, f_y;
    if(idx % 2 == 0) f_x = idx - res, f_y = res + 1;
    else f_y = idx - res, f_x = res + 1;
    pii ans;
    ans.first = f_x, ans.second = f_y;
    return ans;
}



int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    // cout << judge(15).first << " " << judge(15).second;

   int n; scanf("%d", &n);
   while(n--){
        ll a, b; scanf("%llu%llu", &a, &b);
        
        pair<ll, ll> x, y;
        x = judge(a);
        y = judge(b);
    //    cout << a << " " << b<< endl;
    //    cout << abs(x.first - y.first) + abs(x.second - y.second) << "\n";
        long long t_1 = x.first - y.first, t_2 = x.second - y.second;
        printf("%llu\n", abs(t_1) + abs(t_2));
    }

    return 0;
}