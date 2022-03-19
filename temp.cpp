#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,k;
const int maxn=30;
int mp[maxn][maxn];
int a[maxn];
int x,ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int o=1;o<=k;o++){
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                mp[a[i]][a[j]]++;
                if(mp[a[i]][a[j]]==k) ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
