#include<bits/stdc++.h>
#define pii pair<int, pair<int, int>>
using namespace std;

const int maxn = 110;
int n;
vector<pii> v;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int _max = -1;
    while(n--){
        int t1, t2; cin >> t1 >> t2;
        int sum = t1 + t2;
        v.push_back({sum, {t1, t2}});
        // _max = max(_max, t2);
    }
    sort(v.begin(), v.end());

    long long ans = 0, b = 0;
    
    for(auto x : v){
        b += x.second.first;
        ans += b;
        b += x.second.second;
    }
    cout << ans;

    return 0;
}