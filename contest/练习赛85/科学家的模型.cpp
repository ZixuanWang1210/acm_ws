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
const int maxn=8;
char mp[maxn][maxn]={'0'};
int n;

void sol(){
    // cin>>n;
	n=5;
    for(int i=1;i<=n;i++){
		string s; cin>>s;
        for(int j=1;j<=n;j++){
            mp[i][j]=s[j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='1'&&mp[i-1][j]=='1'&&mp[i+1][j]=='1'&&mp[i][j-1]=='1') ans++;
            if(mp[i][j]=='1'&&mp[i-1][j]=='1'&&mp[i+1][j]=='1'&&mp[i][j+1]=='1') ans++;
            // if(mp[i][j]=='1') cnt++;
            // if(mp[i+1][j]=='1') cnt++;
            // if(mp[i][j+1]=='1') cnt++;
            // if(mp[i+1][j+1]=='1') cnt++;
            // if(cnt==3) ans++;
        }
    }
    // cout<<ans<<endl;
    if(ans==1) cout<<9 ;
    else if(ans==2)  cout<<8;
    else cout<<0;

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
