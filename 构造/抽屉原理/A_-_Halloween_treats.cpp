#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int c,n;
const int maxn=1e5+10;
int a[maxn],s[maxn];
int flag[maxn];

void sol(){
    memset(flag,-1,sizeof flag);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    flag[0]=0;
    for(int i=1;i<=n;i++){
        // cout<<s[i]<<' ';
        int t=s[i]%c;

        if(flag[t]!=-1){
            for(int j=flag[t]+1;j<=i;j++){
                cout<<j<<' ';
            }
            cout<<endl;
            return;
        }
        flag[t]=i;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(cin>>c>>n,c!=0&&n!=0) sol();

    return 0;
}
