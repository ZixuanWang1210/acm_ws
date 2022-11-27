#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;
const int maxn = 5e6 + 10;

int C[maxn];
int A[maxn], B[maxn];
int n, m;
vector<int> res;
int p=0;
int s=0;

void sol() {
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        cin>>A[i];
    }
    for(int i=m;i>=1;i--){
        cin>>B[i];
    }
    for(int i=1;i<=max(n,m)+10;i++){
        s=A[i]+B[i]+p;
        p=s/(i+1);
        C[i]=s%(i+1);
    }
    bool z=0;
    for(int i=max(n,m)+10;i>=1;i--){
        if(C[i]) z=1;
        if(i>max(n,m)&&!z) continue;
        cout<<C[i]<<' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
