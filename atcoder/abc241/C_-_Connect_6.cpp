// #include <bits/stdc++.h>
// #define endl "\n"
// #define debug(x) cout << #x << ": -----> " << x << endl;
// // typedef long long ll;
// // typedef unsigned long long ull;

// using namespace std;

// const int maxn=30;
// int dp[maxn][maxn][4];
// int n;
// int mp[maxn][maxn];

// void _debug(int op){
//     cout<<endl<<endl;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cout<<dp[i][j][op]<<' ';
//         }
//         cout<<endl;
//     }
// }

// int _get(int x,int y,int op){
//     int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
//     int res=0;
//     for(int i=0;i<8;i++){
//         int xx=x+dx[i],yy=y+dy[i];
//         if(xx<1||xx>n||yy<1||yy>n) continue;
//         res=max(res,dp[xx][yy][op]);
//     }
//     // cout<<res<<endl;
//     return res;
// }

// int _get(int x,int y){
//     int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
//     int res=0;
//     for(int i=0;i<8;i++){
//         int xx=x+dx[i],yy=y+dy[i];
//         if(xx<1||xx>n||yy<1||yy>n) continue;
//         res=max(res,mp[xx][yy]);
//     }
//     // cout<<res<<endl;
//     return res;
// }

// int main(){
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             char t; cin>>t;
//             if(t=='.') dp[i][j][2]=0,mp[i][j]=0;
//             else dp[i][j][2]=1,mp[i][j]=1;
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             // dp[i][j][2]=_get(i,j,2);
//             // dp[i][j][1]=_get(i,j,1);
//             // dp[i][j][0]=_get(i,j,0);
//             if(dp[i][j][2]==0){
//                 // dp[i][j][1]=dp[i][j][2]+1;
//                 // dp[i][j][0]=dp[i][j][1]+1;
//                 dp[i][j][1]=_get(i,j,2)+1;
//                 dp[i][j][0]=_get(i,j,1)+1;
//             }
//             else{
//                 // dp[i][j][2]++;
//                 // dp[i][j][1]++;
//                 // dp[i][j][0]++;
//                 dp[i][j][2]=_get(i,j)+1;
//                 dp[i][j][1]=_get(i,j,1)+1;
//                 dp[i][j][0]=_get(i,j,0)+1;
//             }
//     // _debug(0);
//             ans=max(ans,max(dp[i][j][0],max(dp[i][j][1],dp[i][j][2])));
//         }
//     }
//     cout<<ans<<endl;
    
    

//     return 0;
// }


