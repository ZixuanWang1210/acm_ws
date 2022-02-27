//数据范围：2000
//原理：递推

#include<bits/stdc++.h>
using namespace std;

const int maxn=2010+10,P=1e9+7;
int c[maxn][maxn];

int main(){
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=i;j++){
            if(j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
        }
    }


    int n; cin>>n;
    while(n--){
        int a,b; cin>>a>>b;
        cout<<c[a][b]<<endl;
    }

    return 0;
}