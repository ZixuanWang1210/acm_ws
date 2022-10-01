#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
const int maxn=5e5+10;
int a[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		while(q--){
			int k,l,r;
			cin>>k>>l;
			if(k==1){
				cin>>r;
				int len=r-l+1;
				int fl=r+1;
				for(int j=n;j>=fl;j--){
					a[j]=a[j-len];
				}
			}
			else{
				ans^=a[l];
			}
		}
		cout<<ans<<endl;
	}
}
