#include<string.h>
#include<iostream>
#define Mod 1000000007
using namespace std; 
int main(){
    int n;
    long long a[42];
    long long dp[42][42][3][1602];     // dp[i][j][1][k]代表当前 处理到第i个且值为j 在递减序列中第 1个前i个和为k 
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    //初始化
    if(a[1]==-1) {for(int i=0;i<=40;i++)dp[1][i][1][i]=1;}
    else dp[1][a[1]][1][a[1]]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==-1){//若当前数为 -1 即可为任何数
             for(int j=0;j<=40;j++){//枚举当前可能的数 0~40
               for(int L=0;L<=40;L++){ //枚举当前前一个（i-1）可能的数 0~40
                 for(int k=j*(i-1);k<=1600-j;k++){//枚举前(i-1)个满足条件的和k 
                    if(j>=L){//若当前大于前一个数 即打破递减序列的条件 
                        dp[i][j][1][k+j]=(dp[i][j][1][k+j]+dp[i-1][L][1][k])%Mod;
                        dp[i][j][1][k+j]=(dp[i][j][1][k+j]+dp[i-1][L][2][k])%Mod;
                    }else dp[i][j][2][k+j]=(dp[i][j][2][k+j]+dp[i-1][L][1][k])%Mod;                      }
               }
             }
        }else{//若为具体的大小 
                for(int L=0;L<=40;L++){//枚举上一个数的大小
                     for(int k=a[i]*(i-1);k<=1600-a[i];k++){//枚举前(i-1)个满足条件的和k 
                       if(a[i]>=L){
                           dp[i][a[i]][1][k+a[i]]=(dp[i][a[i]][1][k+a[i]]+dp[i-1][L][1][k])%Mod;
                           dp[i][a[i]][1][k+a[i]]=(dp[i][a[i]][1][k+a[i]]+dp[i-1][L][2][k])%Mod;
                       }else dp[i][a[i]][2][k+a[i]]=(dp[i][a[i]][2][k+a[i]]+dp[i-1][L][1][k])%Mod;
                     }
                }
        }
    }
        long long sum=0;
            for(int j=0;j<=40;j++){//枚举 可能的大小
             for(int k=j*n;k<=1600;k++){//枚举可能的和
              sum=(sum+dp[n][j][1][k])%Mod;
              //当前数大小为j且在递减位置1 和为k的美丽序列数
              sum=(sum+dp[n][j][2][k])%Mod;
             }
            }
    cout <<sum<<endl;
    return 0;
}