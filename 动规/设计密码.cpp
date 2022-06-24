#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=60,mod=1e9+7;
int n,m;
char s[maxn];
int dp[maxn][maxn],ne[maxn];


void sol(){
    cin>>n>>s+1;
    m=strlen(s+1);
    for(int i=2,j=0;i<=m;i++){
        while(j&&s[i]!=s[j+1]) j=ne[j];
        if(s[i]==s[j+1]) j++;
        ne[i]=j;
    }

    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(char ch='a';ch<='z';ch++){
                int idx=j;
                while(idx&&s[idx+1]!=ch) idx=ne[idx];
                if(s[idx+1]==ch) ++idx;
                dp[i+1][idx]=(dp[i+1][idx]+dp[i][j])%mod;
            }
        }
    }

    int res=0;
    for(int j=0;j<m;j++){
        res=(res+dp[n][j])%mod;
    }
    cout<<res<<endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;/
    while(_--){
        sol();
    }

    return 0;
}
