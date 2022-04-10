#include<iostream>
#define int long long
using namespace std;

const int maxn=1000;
int a[maxn][maxn],s[maxn][maxn];
int m,n,k;

int get(int x1,int y1,int x2,int y2){
    int res=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
    return res;
}
int ans;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            // cout<<s[i][j]<<' ';
        }
        // cout<<endl;
    }
    // cout<<get(2,2,3,3)<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x1,y1,x2,y2;
            for(int sx=1;sx<=m;sx++){
                for(int sy=1;sy<=n;sy++){
                    int ex=sx+i-1,ey=sy+j-1;
                    if(ex>m||ey>n) break;
                    // cout<<sx<<' '<<sy<<' '<<ex<<' '<<ey<<endl;
                    if(get(sx,sy,ex,ey)<=k) ans++;
                }
            }
        }
    }
    cout<<ans<<endl;

    

    return 0;
}