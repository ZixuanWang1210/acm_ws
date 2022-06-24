#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e18
#define int long long
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long

using namespace std;

const int maxn=2e3+10;
struct chong{
	int x,y,h,flag;
};
struct ren{
	int x,y,k,r,si;
};
int n;
chong a[maxn];
ren b[maxn];
int cnt_c,cnt_r;
int re[maxn];

int get(pii a,pii b){
	int dx=a.first-b.first;
	int dy=a.second-b.second;
	return (dx*dx+dy*dy);
}

void sol(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int op; cin>>op;
		re[i]=op;
		if(op==1){
			int x,y,h; cin>>x>>y>>h;
			a[++cnt_c]={x,y,h,1};
		}
		else{
			int x,y,atk,r; cin>>x>>y>>atk>>r;
			b[++cnt_r]={x,y,atk,r,1};
			int idx=0,mn=inf;
			for(int j=1;j<=cnt_c;j++){
				int dis=get({x,y},{a[j].x,a[j].y});
				if(dis<mn&&a[j].h>0){
					mn=dis;
					idx=j;
				}
			}
			if(mn!=inf){
				int xx=a[idx].x,yy=a[idx].y;
				// b[cnt_r].x=xx,b[cnt_r].y=yy;
				for(int j=1;j<=cnt_c;j++){
					int dis=get({xx,yy},{a[j].x,a[j].y});
					if(r*r>=dis&&a[j].h>0){
						a[j].h-=3*b[cnt_r].k;
						if(a[j].h>0){
							b[cnt_r].si=0;
						}
					}
				}
				
			}
		}
	}
	int nc_chong=0,nc_ren=0;
	for(int i=1;i<=n;i++){
		if(re[i]==1){
			nc_chong++;
			if(a[nc_chong].h>0) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else{
			nc_ren++;
			if(b[nc_ren].si) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int _=1;
	while(_--){
		sol();
	}

	return 0;
}
