#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

// const int maxn=10;
// int dp[maxn][3],mp[maxn][3];
// int dp1[maxn][3];

// void sol(){
//     int n; cin>>n;
//     string s; cin>>s;
//     int cnt0=0,cnt1=0;
//     // int n=s.length();
//     int bg=0x3f3f3f3f;
//     int dp[2*n][3]={0},mp[2*n][3]={0};
//     int dp1[2*n][3]={0};
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='*') mp[i+1][0]=1,cnt0++,bg=min(bg,i+1);
//     }
//     cin>>s;
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='*') mp[i+1][1]=1,cnt1++,bg=min(bg,i+1);
//     }

//     bool flag=(cnt1>=cnt0);
//     int ans=0;

//     if(flag){
//         if(mp[bg][1]&&mp[bg][0]) ans=1;
//         else if(mp[bg][1]) ans=0;
//         else ans=1;
//         for(int i=bg+1;i<=n;i++){
//             if(mp[i][1]&&mp[i][0]){
//                 ans++;
//                 ans++;
//             }
//             else if(mp[i][1]) ans++;
//             else if(mp[i][0]) ans+=2;
//             else ans++;
//         }
//     }
//     cout<<ans<<endl;
// }

void sol(){
    int n;cin>>n;
    string s[3];
    cin>>s[1]>>s[2];
    s[1]='*'+s[1],s[2]='*'+s[2];
    for(int i=0;i<=n;i++) {
        if(s[1][i]=='*')s[1][i]=1;
        else s[1][i]=0;
        if(s[2][i]=='*')s[2][i]=1;
        else s[2][i]=0;
    }
    int l=1,r=n;
    while(s[1][l]==0&&s[2][l]==0)l++;
    while(s[1][r]==0&&s[2][r]==0)r--;
    int flg=0;
    int ans=r-l;
    for(int i=l;i<=r;i++){
        if(s[1][i]==1&&s[2][i]==1)flg=1,ans++;
        else if(flg==1&&(s[1][i]==1||s[2][i]==1))flg=0;
        else if(flg==0&&(s[1][i]==1||s[2][i]==1)){
            if(s[1][i]!=s[1][i-1]&&s[2][i]!=s[2][i-1])ans++,flg=1;
        }
        else if(s[1][i]==0&&s[2][i]==0)s[1][i]=s[1][i-1],s[2][i]=s[2][i-1];
    }
    cout<<ans<<endl;
    s[1].clear();s[2].clear();
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
