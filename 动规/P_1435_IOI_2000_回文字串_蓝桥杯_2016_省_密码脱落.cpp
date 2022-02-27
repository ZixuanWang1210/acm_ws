#include<bits/stdc++.h>
using namespace std;

const int maxn=1100;
char s1[maxn],s2[maxn];
int dp[maxn][maxn];

int main(){
    cin>>s1+1;
    int len=strlen(s1+1);
    for(int i=1;i<=len;i++) s2[i]=s1[len-i+1];
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<len-dp[len][len]<<endl;

    return 0;
}