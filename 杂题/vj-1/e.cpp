#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

long long c[2010][2010];


void sol(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=i;j++){
            if(j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1]);
        }
    }

    int n,m,t;
    cin>>n>>m>>t;
    cout<<c[m+n][t]-c[n][t]-c[m][t]-c[n][1]*c[m][t-1]-c[n][2]*c[m][t-2]-c[n][3]*c[m][t-3]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
