#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+20;
ll n,k,a[N],sum[N];
map<ll,ll> mp;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        sum[i]=sum[i]%k;
        mp[sum[i]]++;
    }
    mp[0]++;
    ll cnt=0;
    for(int i=0;i<=n;i++){
        cnt+=mp[sum[i]]-1;
    }
    cnt/=2;
    printf("%lld",cnt);
    return 0;
}