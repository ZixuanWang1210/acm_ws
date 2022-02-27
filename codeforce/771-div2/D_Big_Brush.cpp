#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
using namespace std;

const int maxn=10;
int mp[maxn][maxn];
bool st[maxn][maxn];
int n,m;
vector<int> ans1,ans2,ans3;
queue<pii> q;

int find(int x,int y){
    if(mp[x][y]==0&&mp[x+1][y]==0&&mp[x][y+1]==0&&mp[x+1][y+1]==0) return 0;
    int col;
    for(int i=x;i<=x+1;i++) for(int j=y;j<=y+1;j++) if(mp[i][j]!=0) col=mp[i][j];
    for(int i=x;i<=x+1;i++) for(int j=y;j<=y+1;j++) if(mp[i][j]!=0&&mp[i][j]!=col) return -1;
    
    return col;
}

void erase(int x,int y,int col){
    mp[x][y]=mp[x+1][y]=mp[x][y+1]=mp[x+1][y+1]=0;
    ans1.push_back(x);
    ans2.push_back(y);
    ans3.push_back(col);
}

void _debug(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j]<<' ';
        }
        cout<<endl;
    }
    
    cout<<"-----------"<<endl;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cout<<"ok"<<endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(find(i,j)>=0){
                q.push({i,j});
                st[i][j]=true;
            }
        }
    }

    while(q.size()){
        auto t=q.front(); q.pop();
        if(find(t.first,t.second)==0) continue;
        erase(t.first,t.second,find(t.first,t.second));
        // _debug();
        for(int i=t.first-1;i<=t.first+1;i++){
            for(int j=t.second-1;j<=t.second+1;j++){
                if(i==n||j==m||i==0||j==0) continue;
                if(find(i,j)==-1||st[i][j]) continue;
                // if(mp[i][j]==0) continue;
                st[i][j]=true;
                q.push({i,j});
            }
        }
    }

    bool flag=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!st[i][j]) flag=false;
        }
    }
    if(!flag){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans1.size()<<endl;
    for(int i=ans1.size()-1;i>=0;i--){
        cout<<ans1[i]<<' '<<ans2[i]<<' '<<ans3[i]<<endl;
    }
    

    return 0;
}
