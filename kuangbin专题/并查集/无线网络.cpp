// #include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2000;
int g[maxn][maxn];
int n,d;
int p[maxn];
bool st[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

struct node{
    int id,x,y;
} point[maxn];

bool _get(node a, node b){
    int dx=a.x-b.x;
    int dy=a.y-b.y;
    double dis=sqrt(dx*dx+dy*dy);
    if(dis>d) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        point[i]={i,x,y};
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[j][i]=g[i][j]=_get(point[i],point[j]);
            // cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
        }
    }

    char op;
    while(cin>>op){
        if(op=='S'){
            int a,b; cin>>a>>b;
            a=find(a),b=find(b);
            if(a==b) cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
        else{
            int x; cin>>x;
            st[x]=true;
            for(int i=1;i<=n;i++){
                if(g[x][i]&&st[i]){
                    int a=x,b=i;
                    // cout<<a<<' '<<b<<endl;
                    a=find(a),b=find(b);
                    p[a]=b;
                }
            }
        }
    }


    

    return 0;
}
