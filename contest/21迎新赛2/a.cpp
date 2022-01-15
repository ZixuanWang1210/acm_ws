#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e6 + 10;
using namespace std;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    int st = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(st < a[i]){
            cnt ++;
        }
        st = a[i];
    }
   
    cout << cnt;
    return 0;
}
