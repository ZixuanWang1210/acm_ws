#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n;
const int N=200,INF=1e20;
double g[N][N],d[N][N],maxd[N];
pii p[N];
char mp[N][N];

double get(pii a,pii b){
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int idx=0;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            if(i==j) d[i][j]=0;
            else if(mp[i][j]=='1') d[i][j]=get(p[i],p[j]);
            else d[i][j]=INF;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    double r1=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]<INF/2){
                maxd[i]=max(maxd[i],d[i][j]);
            }
        }
        r1=max(r1,maxd[i]);
    }

    double r2=INF;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(d[i][j]>INF/2){
                r2=min(r2,max(maxd[i]+maxd[j]+get(p[i],p[j]),max(maxd[i],maxd[j])));
            }
        }
    }
    // ans = min(ans,max(maxd[i] + maxd[j] + dist(p[i].x, p[i].y, p[j].x, p[j].y),max(ad[ds.find(i)], ad[ds.find(j)])));
    cout<<fixed<<setprecision(6)<<max(r1,r2);
    return 0;
}
