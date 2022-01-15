#define INF 0x3f3f3f3f
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int a[10010];
int sum[10010];
int solve()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        a[0]=1;
        sum[0]=1;
        int i,j,k,d=0;
        for(k=2; k<=n; k++)
        {
            for(j=0; j<=d; j++)
                a[j]*=k;
            for(j=0; j<=d; j++)
            {
                if(a[j]>=10)
                {
                    a[j+1]+=a[j]/10;
                    a[j]=a[j]%10;
                    if(j==d)
                        d++;
                }
            }
           
            for(i=0; i<=d; i++)
                sum[i]+=a[i];
            for(i=0; i<=d; i++)
            {
                if(sum[i]>=10)
                {
                    sum[i+1]+=sum[i]/10;
                    sum[i]=sum[i]%10;
                    if(j==d)
                        d++;
                }
            }
        }
        for(i=d; i>=0; i--)
            printf("%d",sum[i]);
        //printf("\n");
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    solve();

    return 0;
}
