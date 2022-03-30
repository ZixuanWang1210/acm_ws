#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=5005;

int t,n,x,sum[N],mx[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i=1;i<=n;i++) sum[i]=0,mx[i]=-inf; 
		for(int i=1;i<=n;i++){
			cin>>sum[i];
			sum[i]+=sum[i-1]; 
		}
		int ans=0;
		for(int len=1;len<=n;len++){ 
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				mx[len]=max(mx[len],sum[r]-sum[l-1]); //每种长度的最大子段和 
				ans=max(ans,mx[len]); //这是最开始 
			}
		}
		for(int k=0;k<=n;k++){ //
			for(int len=1;len<=n;len++) ans=max(ans,mx[len]+x*min(k,len));
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
	return 0;
}