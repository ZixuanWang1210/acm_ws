#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;
int x;
vector<int> v;

int n = -1;
const int maxn = 1e8 + 10;
int a[maxn], idx;
bool st[maxn];

int get(int n){
    memset(st, 1, sizeof st); 
    for(int i = 2; i <= n; i++){
        if(st[i]){
            a[idx ++] = i;
        }
        for(int j = 0; a[j] <= n / i && j <= idx; j++){
            st[a[j] * i] = false;
            if(i % a[j] == 0) break;
        }
    }
    return 0;
}

int getlen(int n){
    int cnt = 0; 
    while(n){   
        cnt ++;
        n >>= 1;
    }
    int ans = 1 << (cnt + 1);
    return ans;
}

int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    // cout << getlen(100);
    // cin >> t;
    // while(t--){
    //     cin >> x;
    //     n = max(n, x);
        
    //     v.push_back(x);
    // }
    // // cout << getlen(n);
    // get(getlen(n));

    // // for(int i = 0; i < n; i++){
    // //     cout << a[i] << " ";
    // // }
    // int cnt = 0;
    // for(auto x : v){
    //     int ans = 0;
    //     // int tt = getlen(x);
    //     for(int i = 0; a[i] < getlen(x); i++){
    //         // cout << a[i] << endl;
    //         // cnt ++;
    //         if(a[i] == 0) break;
    //         // int xx = a[i];
    //         int temp = x ^ a[i];

    //         if(temp < x) ans ++;
    //     }
    //     cout << ans << endl;
    // }
    // // cout << cnt;
    get(1e6);
    int cnt = 0;
    for(int j = 3; j < 1e6 + 10; j++){
        int ans = 0;
        // int tt = getlen(x);
        for(int i = 0; a[i] < getlen(j); i++){
            // cout << a[i] << endl;
            // cnt ++;
            if(a[i] == 0) break;
            // int xx = a[i];
            int temp = j ^ a[i];

            if(temp < j) ans ++;
        }
        cnt ++;
        cout << ans << ",";
        if(cnt > 10){
            cout << endl;
            cnt = 0;
        }
    }
    return 0;
}
