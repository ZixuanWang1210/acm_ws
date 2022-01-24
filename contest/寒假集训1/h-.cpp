#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 3e6 + 10;
int n;
long long ans;
vector<int> a;
bool st[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int t; cin >> t; a.push_back(t);
    }

    sort(a.begin(), a.end());
    ll re = 0;
    for(int i = 0; i < n; i ++){
        ll ans_hang = 0;
        if(st[a[i]]){
            ans += (re - abs(a[i-1]+a[i-1]-1000));
            continue;
        }
        for(int j = i; j < n; j++){
            ans_hang += abs(a[i]+a[j]-1000);
        }
        re = ans_hang;
        ans += ans_hang;
        st[a[i]] = 1;
    }
    
    cout << ans;

    return 0;
}
