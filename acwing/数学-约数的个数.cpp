// (a1 + 1)(a2 + 1)....(a_n + 1)
#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


const int P = 1e9 + 7;

int get(int n){
    int cnt = 0;
    for(int i = 1; i <= n / i; i++){
        if(n % i == 0){
            cnt ++;
            if(i != n / i) cnt ++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    long long temp = 1;
    while(n--){
        int x; cin >> x;
        for(int i = 2; i <= x / i; i++){
            while(x % i == 0){
                mp[i] ++;
                x /= i;
            }
        }
        if(x > 1) mp[x] ++;
    }
    for(auto x : mp){
        temp = temp * (x.second + 1) % P;
    }

    cout << temp;

    return 0;
}
