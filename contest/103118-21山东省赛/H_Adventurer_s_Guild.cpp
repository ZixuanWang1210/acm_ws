#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N=1005,M=305;
int n,m,v;
int h[N],s[N],w[N];
LL f[M][M];

int main()
{
    cin >> n >> m >> v;
    for(int i=1; i<=n; i++)
        cin >> h[i] >> s[i] >> w[i];

    for(int i=1; i<=n; i++)
        for(int j=m; j>0; j--)
            for(int k=v; k>=0; k--){
                LL &vv = f[j][k];
                int t = 0, tt=0;
                if(k<s[i]) t = s[i]-k;
                else tt = k-s[i];
                if(j-h[i]-t<=0) continue;
                vv = max(vv, f[j-h[i]-t][tt]+w[i]);
            }
    // cout << f[1][m][v] << endl;
    cout << f[m][v];

    return 0;
}