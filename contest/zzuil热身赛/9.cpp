#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,pair<int,int>>
using namespace std;

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

void sol(){

    int ans=0;
    int mp[8][8]={
            {0,0,0,0,0,0,0},
            {0,1,1,0,1,1,0},
            {0,0,1,1,1,0,0},
            {0,0,1,1,1,0,0},
            {0,0,1,1,1,0,0},
            {0,1,1,0,1,1,0},
            {0,0,0,0,0,0,0}};
    bool st[8][8];
    memset(st,0,sizeof st);

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(mp[i][j]){
                int tt; cin>>tt;
                mp[i][j]=ceil((double)tt/(double)6);
            }
            else mp[i][j]=-1;
        }
    }
    int tot; cin>>tot;

    int ttt=tot-mp[1][1];
    if(ttt<0){
        cout<<0<<endl;
        return;
    }
    else{
        tot=ttt;
        ans++;
    }
    priority_queue<pii> pq;
    pq.push({mp[1][1],{1,1}});


    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int x=t.second.first,y=t.second.second;
        int cost=t.first;
        st[x][y]=true;

        for(int i=0;i<4;i++){
            int xx=dx[i]+x,yy=dy[i]+y;
            if(xx<1||xx>5||yy<1||yy>5||mp[xx][yy]==-1||st[xx][yy]) continue;
            int temp=tot-cost;
            if(temp>=0){
                tot=temp;
                ans++;
                st[xx][yy]=true;
                pq.push({mp[xx][yy],{xx,yy}});
            }
            else{
                cout<<ans<<endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
