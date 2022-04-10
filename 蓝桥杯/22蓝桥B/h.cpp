#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

const int maxn=20;
int p[maxn],siz[maxn];
int n,m;

int find(int x){
    if(x!=p[x]){
        int fa=find(p[x]);
        // siz[fa]+=siz[x];
        p[x]=fa;
    }
    return p[x];
}

void merge(int a,int b){
    a=find(a),b=find(b);
    if(a!=b){
        p[a]=b;
        siz[b]+=siz[a];
        // cout<<siz[b]<<endl;
    }
}

double get(int x1,int y1,int x2,int y2){
    double dx=x2-x1;
    double dy=y2-y1;
    return (double)sqrt(dx*dx+dy*dy);
}

struct node{
    int x,y,r;
} op[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*2;i++){
        p[i]=i; siz[i]=1;
    }
    for(int i=1;i<=n;i++){
        int x,y,r;
        cin>>x>>y>>r;
        op[i]={x,y,r};
    }


    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x1=op[i].x,y1=op[i].y,r1=op[i].r;
            int x2=op[j].x,y2=op[j].y,r2=op[j].r;

            double dis=get(x1,y1,x2,y2);
            if((double)r1+(double)r2>=dis){
                merge(i,j);
            }
        }
    }

    for(int i=1;i<=m;i++){
        int x,y,r; cin>>x>>y>>r;
        int bz=0;
        int ans=0;
        map<int,bool> mp;
        for(int j=1;j<=n;j++){
            int x1=op[j].x,y1=op[j].y,r1=op[j].r;
            double dis=get(x1,y1,x,y);
            if((double)r1+(double)r>=dis){
                int fath=find(j);
                if(mp[fath]!=1){
                    ans+=siz[fath];
                    mp[fath]=true;
                }
            }
        }
        cout<<ans<<endl;
    }

    

    return 0;
}