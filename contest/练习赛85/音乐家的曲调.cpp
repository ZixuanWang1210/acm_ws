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

// priority_queue<ll> pq;

void sol(){
    int n,m; cin>>n>>m;
    string s;  cin>>s;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        mp[x].push_back(i);
    }

    for(int i=0;i<n;i++){
        int x=s[i]-'a';
        b[i]=(cnt[x]+1>=n||cnt[x]==mp[x].size()-1)?n:mp[x][cnt[x]+1];
		cnt[x]++;
    }
	ll siz=0;
	ll now=inf;
	for(int i=0;i<n;i++){
		if(now<b[i]){ 
			// pq.push(siz);
            if(siz>d1){
                d3=d2;
                d2=d1;
                d1=siz;
            }
            else if(siz>d2){
                d3=d2;
                d2=siz;
            }
            else if(siz>d3){
                d3=siz;
            }
			siz=1;
			now=b[i];
		}
		else siz++,now=b[i];
	}
    cout<<d1+d2+d3<<endl;
	// pq.push(siz);
	// int xx=3;
	// ll res=0;
	// while(pq.size()&&xx){
	// 	res+=pq.top();
	// 	pq.pop();
	// 	xx--;
	// }
	// cout<<res<<endl;
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
