#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 3e6 + 10;
int n;
long long ans;
vector<int> a,s;
map<int,int> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int t; cin >> t; a.push_back(t);
        mp[a[i]] ++;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int pos = lower_bound(a.begin(),a.end(),500) - a.begin();

    cout << pos;
    int re = 0;
    s.push_back(0);
    for(auto x : a){
        int t = x + re;
        re = x;
        s.push_back(t);
    }

    n = a.size();
    ans = (n-pos+1)*(s[n-1]-s[pos-1]);

    


    
    // cout << ans;

    return 0;
}
