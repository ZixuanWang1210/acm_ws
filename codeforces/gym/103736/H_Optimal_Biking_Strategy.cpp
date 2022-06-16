#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+20;
const int INF=1e9;
ll f[N][10];
ll a[N];
ll n,p,s,k;
int main(){
    scanf("%lld%lld%lld",&n,&p,&s);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&k);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            f[i][j]=INF;
        }
    }
    //f[0]清0
    for(int i=1;i<=n;i++){
        f[i][0]=f[i-1][0]+a[i]-a[i-1];
        for(int j=1;j<=k;j++){
            f[i][j]=f[i-1][j]+a[i]-a[i-1];
            for(int x=0;x<=j;x++){
                int dist=x*s;//能骑的距离
                int idx=-1,l=1,r=i-1;
                while(l<=r){//往左找
                    int mid=(l+r)>>1;
                    if(a[i]-a[mid]<=dist){
                        idx=mid;
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                if(idx==-1){
                    continue;
                }else{
                    f[i][j]=min(f[i][j],f[idx][j-x]);
                    //cout<<f[i][j]<<" "<<x<<endl;
                }
            }
        }
    }
    ll ans=INF;
    for(int i=1;i<=n;i++){
        ans=min(ans,f[i][k]+p-a[i]);
        //cout<<f[i][k]<<endl;
    }
    printf("%lld",ans);
    return 0;
}


