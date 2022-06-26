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

const int maxn=110;
int st[maxn][maxn][4][maxn];
int n,m;
char mp[maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct node{
    int x,y,dis,op,cnt;
};

void sol(){
    cin>>n>>m;
    memset(st,0x3f,sizeof st);
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            mp[i][j]=s[j-1];
        }
    }
    queue<node> q;
    for(int i=0;i<4;i++) q.push({1,1,0,i,0});

    int ans=inf;
    while(q.size()){
        auto t=q.front();
        if(t.x==n&&t.y==n){
            ans=min(ans,t.dis);
        }
        q.pop();

        for(int i=0;i<4;i++){
            int xx=t.x+dx[i],yy=t.y+dy[i],dis=t.dis,op=t.op,cnt=t.cnt;
            if(xx<1||xx>n||yy<1||yy>n||mp[xx][yy]=='*') continue;
            if(i==op)  cnt++;
            else cnt=1,op=i;
            if()
            // if(st[xx][yy][op][cnt]) continue;
            // else st[xx][yy][op][cnt]=1;
            // q.push({xx,yy,dis+1,op,cnt});
        }
    }
    cout<<ans<<endl;
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
