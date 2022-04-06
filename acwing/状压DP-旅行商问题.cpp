#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


const int N=20,M=1<<N;
int n;
int w[N][N];
int f[M][N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    for(int i=1;i<(1<<n);i+=2){
        for(int j=0;j<n;j++){
            if(i>>j&1){
                for(int k=0;k<n;k++){
                    if(j==k) continue;
                    if(!(i>>k&1)) continue;
                    if((i-(1<<j))>>k&1){
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    // cout<<f[(1<<n)-1][n-1];
    int minn=0X3F3F3F3F;
	for(int i=0;i<=n-1;++i)	{
		minn=min(minn,f[(1<<n)-1][i]+w[i][0]);
	}
	cout<<minn;//所有点走完，最后停在n-1点上


    return 0;
}
