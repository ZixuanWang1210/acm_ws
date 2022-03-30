#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii tuple<int,int,int>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=20;
int mp[maxn][maxn];
bool st[maxn][maxn];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pii start,end;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            char t; cin>>t;
            if(t=='.') mp[i][j]=1;
            else if(t=='B'){
                start=make_tuple(i,j,0);
                mp[i][j]=0;
            }
            else if(t=='L'){
                end=make_tuple(i,j,0);
                mp[i][j]=-1;
            }
            else{
                mp[i][j]=0;
            }
        }
    }
    
    queue<pii> q;
    q.push(start);
    st[get<0>(start)][get<1>(start)]=0;
    while(q.size()){
        int x=get<0>(q.front()),y=get<1>(q.front()),dis=get<2>(q.front());
        q.pop();

        if(st[x][y]) continue;
        st[x][y]=1;

        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(mp[xx][yy]==-1){
                cout<<dis<<endl;
                return 0;
            }
            if(!mp[xx][yy]) continue;
            q.push(make_tuple(xx,yy,dis+1));
        }
    }

    return 0;
}
