#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn = 1e5 + 10;
// const int maxn = 10;
typedef pair<ll, ll> pii;

ll a[maxn], s[maxn];
ll n, ans;
vector<pii> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
        s[i] = s[i - 1] + a[i];
        v.push_back({s[i], i});
    }

    v.push_back({0, 0});
    sort(v.begin(), v.end());

    pii re = v[0], st = v[0];
    ll _max = -1;
    for(auto x : v){
        if(re.first != x.first){
            ll temp = re.second - st.second;
            _max = max(_max, temp);
            st = x;
        }
        re = x;
    }

    cout << _max;
    

    return 0;
}
