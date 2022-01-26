#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(v) ((int)v.size())
#define fs first
#define sc second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
int n,le[110],a[110][5],res[1010],p;
int main(){
    cin>>n;
    rep(i,1,n){
        le[i]=4;
        rep(j,1,3){
            scanf("%d",&a[i][j]);
            if(a[i][j])    le[i]=min(le[i],j);
        }
    }
    rep(i,1,n){
        if(le[i]!=4){
            int j=p;
            while(res[j]!=i-le[i])    j--;
            int add=3-(p-j);
            rep(j,1,add)    res[++p]=0;
        }
        res[++p]=i;
    }
    printf("%d\n",p-n);
    return 0;
}