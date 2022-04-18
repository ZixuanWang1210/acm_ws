#pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

typedef long long ll;
const int N = 2e5 + 7, M = 1e5 + 7, INF = 0x3f3f3f3f;

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> tr;
int n, m;
ll k, ans;

int main(){
    cin>>n;
    for(int i = 1; i <= n; ++ i){
        int op; cin>>op;
        cin>>k;
        if(op == 1) tr.insert((k << 20) + i);
        if(op == 2) tr.erase(tr.lower_bound(k << 20));
        if(op == 3) printf("%d\n", tr.order_of_key(k << 20) + 1);
        if(op == 4) ans = *tr.find_by_order(k - 1), printf("%lld\n", ans >> 20);
        if(op == 5) ans = *-- tr.lower_bound(k << 20), printf("%lld\n", ans >> 20);
        if(op == 6) ans = *tr.upper_bound((k << 20) + n), printf("%lld\n", ans >> 20);
    }
    return 0;
}

