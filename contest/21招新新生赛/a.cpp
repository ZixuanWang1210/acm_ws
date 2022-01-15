#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], s1[maxn], s2[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ++;
        b[n - i + 1] = a[i];
        s1[i] = s1[i - 1] + a[i];
    }
    for(int i = 1; i < n; i++){
        s2[i] = s2[i - 1] + b[i];
        if(s2[i] == s1[i]){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}
