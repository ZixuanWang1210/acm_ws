#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef pair<int, int> pii;
typedef long long ll;

map<int, int> mp;
ll s[maxn], cnt[maxn], a[maxn];
int t, n, m;

int main(){
    cin >> t;
    while(t--){
        mp.clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]] ++;
            s[i] = 0;
            cnt[i] = 0;
        }

        for(auto &x : mp){
            cnt[x.second] ++;
        }

        for(int i = n - 1; i > 0; i--){
            cnt[i] += cnt[i + 1];
            s[i] = s[i + 1] + cnt[i];
        }

        int ans = -1;
        for(auto &x : mp){
            if(s[x.second] - 1 <= m) ans = max(ans, x.first);
        }
        cout << ans << "\n";
    }


    return 0;
}