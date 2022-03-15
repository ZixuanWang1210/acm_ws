#include<bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10;
int st[maxn][30];
int idx=0,re;
int m,D;

void update(int u){
    for(int i=1;u-(1<<i)>=0;i++) st[u][i]=max(st[u][i-1],st[u-(1<<(i-1))][i-1]);
}

ll find(int x,int y){
    double t=log(y-x+1)/log(2);
    int K=t;
    return max(st[y][K],st[x+(1<<K)-1][K]);
}

signed main(){
    memset(st,0,sizeof st);
    cin>>m>>D;
    while(m--){
        char op; cin>>op;
        if(op=='A'){
            int x; cin>>x;
            st[++idx][0]=(x+re)%D;
            update(idx);
        }
        else{
            int x; cin>>x;
            ll ans=0;
            if(x==1){
                cout<<st[idx][0]<<endl;
                re=st[idx][0];
                continue;
            }
            ans=find(idx-x+1,idx);
            cout<<ans<<endl;
            re=ans;
        }
    }

    return 0;
}