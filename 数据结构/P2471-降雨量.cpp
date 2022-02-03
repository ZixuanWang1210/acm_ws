#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

int n,m;
const int N=5e4+10;
map<int,int> mp;
int st[N][20];

void build(){
    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int yy=0;
        cin>>yy>>st[i][0];
        mp[yy]=i;
    }
    build();
    cin>>m;
    while(m--){
        int x,y;cin>>x>>y;
        if(y<=x){
            cout<<"false"<<endl;
            continue;
        }
        bool kx=mp.count(x),ky=mp.count(y),flag;
        if(!kx&&!ky){
            cout<<"maybe"<<endl;
            continue;
        }
        int xx,yy;
        auto yyy=mp.lower_bound(y);
        auto xxx=mp.lower_bound(x);
        if(yyy==mp.end()){
            cout<<"maybe"<<endl;
            continue;
        }
        yy=yyy->second;
        xx=xxx==mp.end()?mp.size()+1:yyy->second;
        if(!ky) yy--;
        int rmq=yy+1<=

    }
    

    return 0;
}
