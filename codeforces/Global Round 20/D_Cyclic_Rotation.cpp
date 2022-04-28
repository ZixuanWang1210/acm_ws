#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

// void sol(){
//     int n; cin>>n;
//     multiset<int> mts;
//     for(int i=1;i<=n;i++){
//         int x; cin>>x;
//         mts.insert(x);
//     }
//     vector<int> v(n+1);
//     for(int i=1;i<=n;i++) cin>>v[i];
//     int idx=1;
//     for(auto x:mts){
//         while(v[idx]!=x){
//             auto tt=x;
//             mts.erase(x);
//             auto id=mts.lower_bound(tt);
//             mts.insert(id,x);
//         }
//         idx++;
//     }

// }

const int maxn = 2e6 + 10;
int v1[maxn], v2[maxn], cnt[maxn];

void sol() {
    int n;
    cin >> n;
    // vector<int> v1(maxn), v2(maxn);
    // vector<int> cnt(maxn);
    for (int i = 1; i <= n; i++) cin >> v1[i];
    for (int i = 1; i <= n; i++) cin >> v2[i], cnt[i] = 0;
    if (v1[n] != v2[n]) {
        cout << "NO" << endl;
        return;
    }

    int i = 1, j = 1;
    while (i <= n && j <= n) {
        if (v1[i] == v2[j]) {
            if (cnt[v1[i]])
                cnt[v1[i]]--;
            else
                i++;
            j++;
        } else {
            cnt[v1[i]]++;
            i++;
        }
    }
    if (i <= n || j <= n)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
