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

bool st[110][11000];
// bool st[11000];
const int maxn=110;
int a[maxn],b[maxn];
int n;
int x;
void sol(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    memset(st,0,sizeof st);
    st[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            if(st[i-1][j]) st[i][j+a[i]]=true,st[i][j+b[i]]=true;
        }
    }
    if(st[n][x]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
