#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,m;
const int maxn=200;
int a[maxn],b[maxn],c[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=n;i>=1;i--) cin>>a[i];
    for(int i=n+m;i>=1;i--) cin>>c[i];

    for(int i=1;i<=m;i++){
        b[i]=c[i]/a[i]+
    }
    

    return 0;
}
