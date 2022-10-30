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

void sol(){
	int n; string s;
	bool ok=false;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0') ok=1;
	}
	if(!ok){
		cout<<0<<endl;
		return;
	}

	auto check=[&](int x){
		int res=0,f=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0') res++;
			else{
				if(!f){
					if(res>x) return 0;
					else if(res==x) res=1;
					else res=0;
					f=1;
				}
				else{
					if(res>2*x) return 0;
					else if(res==2*x) res=1;
					else res=0;
				}
			}
		}
		if(res>x) return 0;
		else return 1;
	};

	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}


signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int _=1;
	cin>>_;
	while(_--){
		sol();
	}

	return 0;
}
