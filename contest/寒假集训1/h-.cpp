#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N],ans[N];
ll s[N];
vector<int> p;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++ )
    {
        scanf("%d",&a[i]);
        ans[a[i]] ++;
    }

    ll sum = 0;
    ll cnt;
    for(int i = 0; i <= 1000; i ++ )
        for(int j = i; j <= 1000; j ++)
        {
            if(i != j) cnt =ans[i] * ans[j];
            else cnt = (1ll*ans[i] * (ans[i] - 1) / 2 + ans[i]);
            sum += 1ll*cnt * abs(i + j - 1000);
        }
    printf("%lld\n",sum);
    return 0;
}