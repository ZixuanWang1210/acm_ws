#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 2000 + 10;
int a[maxn];
int n, x1;
unsigned long long sum = 0;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> x1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        ll num = 1;
        while(x % x1 == 0){
            x = x / x1;
            num = (x) * num;
            sum = sum + x * num;
            
        }
    }

    cout << sum;
    

    return 0;
}
