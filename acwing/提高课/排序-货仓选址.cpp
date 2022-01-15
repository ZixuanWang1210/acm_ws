#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 100010;
int a[maxn];
int res;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    int mid = 1 + n >> 1;

    for(int i = 1; i <= n; i++){
        res += abs(a[mid] - a[i]);
    }

    cout << res << endl;
    
    return 0;
}
