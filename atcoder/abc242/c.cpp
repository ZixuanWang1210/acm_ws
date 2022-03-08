#include<bits/stdc++.h>
#define P 998244353
using namespace std;

const int maxn=1e6+10;
int dp[maxn][100];//前i位以j结尾数字的答案
int n;

int main(){
    cin>>n;
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=9;j++){
            // if(j==1) dp[i][j]+=dp[i-1][j+1]%=P;
            // else if(j==9) dp[i][j]+=dp[i-1][j-1]%=P;
            // else{
            //     dp[i][j]+=dp[i-1][j+1]%=P;
            //     dp[i][j]+=dp[i-1][j-1]%=P;
            // } 
            if(j!=9) (dp[i][j]+=dp[i-1][j+1])%=P;
            if(j!=1) (dp[i][j]+=dp[i-1][j-1])%=P;
            (dp[i][j]+=dp[i-1][j])%=P;
            
        }
    }

    int res=0;
    for(int i=1;i<=9;i++){
        res+=dp[n][i];
        res%=P;
    }
    cout<<res;
    return 0;
}