#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

map<int, int> mp;
int a[110];
int b[10001] {};
int cnt;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(a[i] == a[j] + a[k] && i != j && i !=k && j != k){
                    int s = a[j] + a[k];
                    b[s] ++;
                }
            }
        }
    }
    
    for(int i = 0; i < 10001; i++){
        if(b[i]){
            cnt ++;
        }
    }

    cout << cnt;

    return 0;
}