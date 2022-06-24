#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;
const int maxn=1e7+10;
ll b[maxn]={0};
ll cnt[30]={0};
vector<ll> mp[30];
int d1,d2,d3;

int ml[maxn],mr[maxn];
int sl[maxn],sr[maxn];
int vis[200];
int idx=3;
int n,m;

// priority_queue<ll> pq;

void sol(){
	cin>>n>>m;
	string s; cin>>s;
	s=' '+s;
	int l=1,r=1;
	while(r<=n&&l<=r){
		vis[s[r]-'a']++;
		while(vis[s[l]-'a']>m){
			vis[s[l]-'a']--;
			l++;
		}
		ml[r]=max(ml[r-1],(r-l)+1);
		r++;
	}
	memset(vis,0,sizeof vis);
	l=n,r=n;
	while(l<=n&&r<=n){
		vis[s[r]-'a']++;
		while(vis[s[l]-'a']>m){
			vis[s[l]-'a']--;
			l++;
		}
		ml[r]=max(ml[r-1],(r-l)+1);
		r++;
	}
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
