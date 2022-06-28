#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e2+10;
int a[maxn],b[maxn];
int n,m,k;
int nxt[maxn];



void sol(){
    cin>>n>>m>>k;
    for(int i=0;i<max(n,m);i++){
        a[i]=b[i]=nxt[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    // for(int i=n;i>=2;i--){
    //     a[i]=(a[i]%k-a[i-1]%k+k)%k;
    // }
    // for(int i=m;i>=1;i--){
    //     b[i]=(b[i]%k-b[i-1]%k+k)%k;
    // }
    for(int i=1;i<n;i++){
        a[i]=(a[i+1]%k-a[i]%k+k)%k;
        // cout<<a[i]<<' ';
    }
    // cout<<endl;
    for(int i=1;i<m;i++){
        b[i]=(b[i]%k-b[i+1]%k+k)%k;
        // cout<<b[i]<<' ';
    }
    // cout<<endl;
    n--,m--;

    for(int i=2;i<=m;i++){
        nxt[i]=nxt[i-1];
        while(nxt[i]&&b[i]!=b[nxt[i]+1]) nxt[i]=nxt[nxt[i]];
        nxt[i]+=(b[i]==b[nxt[i]+1]);
    }

    for(int i=1;i<=n;i++){
        cout<<nxt[i]<<' ';
    }
    // cout<<endl;

    int cnt=0;
    for(int i=1,j=1;i<=n+1;i++){
        while(j!=1&&a[i]!=b[j]) j=nxt[j-1]+1;
        if(a[i]==b[j]) j++,i++;
        else i++;
        if(j==m+1){
            cnt++;
            j=nxt[m]+1;
        }
    }
    cout<<cnt<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
