#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn = 5e5 + 10;
int n;
int a[maxn], _and[maxn], _or[maxn];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> _and[i];
    }
    for(int i = 0; i < n; i++){
        cin >> _or[i];
    }

    for(int i = 0; i <= n; i++){
        if(i == 0) cout << 0 << ' ';
        else {
            a[i] = _and[i - 1] + _or[i - 1] - a[i - 1];
            cout << _and[i - 1] + _or[i - 1] - a[i - 1] << " ";
            
            
        }
        
    }
    return 0;
}
