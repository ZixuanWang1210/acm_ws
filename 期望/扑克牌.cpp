#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e20
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=14;
double f[maxn][maxn][maxn][maxn][maxn][maxn];
int A,B,C,D;

double dp(int a,int b,int c,int d,int x,int y){
    if(a>13||b>13||c>13||d>13) return inf;

    double &v=f[a][b][c][d][x][y];
    if(v>=0) return v;
    int as=a+(x==0)+(y==0);
    int bs=b+(x==1)+(y==1);
    int cs=c+(x==2)+(y==2);
    int ds=d+(x==3)+(y==3);
    if(as>=A&&bs>=B&&cs>=C&&ds>=D) return v=0;

    int sum=a+b+c+d+(x!=4)+(y!=4);
    sum=54-sum;
    if(sum<=0) return v=inf;

    v=1;
    if(a<13) v+=(13.0-a)/sum*dp(a+1,b,c,d,x,y);
    if(b<13) v+=(13.0-b)/sum*dp(a,b+1,c,d,x,y);
    if(c<13) v+=(13.0-c)/sum*dp(a,b,c+1,d,x,y);
    if(d<13) v+=(13.0-d)/sum*dp(a,b,c,d+1,x,y);

    if(x==4){
        double t=inf;
        for(int i=0;i<4;i++) t=min(t,1.0/sum*dp(a,b,c,d,i,y));
        v+=t;
    }
    if(y==4){
        double t=inf;
        for(int i=0;i<4;i++) t=min(t,1.0/sum*dp(a,b,c,d,x,i));
        v+=t;
    }
    return v;

}

void sol(){
    cin>>A>>B>>C>>D;
    memset(f,-1,sizeof f);
    double t=dp(0,0,0,0,4,4);
    if(t>inf/2) t=-1;
    printf("%.3lf\n", t);

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
