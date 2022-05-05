#include<bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x){
    return x&-x;
}

vector<pair<int,int>> aaa;

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int k;
    cin>>k;
    int idx=1;
    while(k){
        int t=lowbit(k-1);
        if(k==t+1){
            int root=idx;
            int cnt_s=0;
            while(t){
                cnt_s++;
                t>>=1;
            }
            cnt_s--;
            for(int i=1;i<=cnt_s;i++){
                // cout<<root<<' '<<++idx<<endl;
                aaa.push_back({root,++idx});
            }
            break;
        }
        // cout<<idx<<' '<<++idx<<endl;
        aaa.push_back({idx,idx+1});
        idx++;
        k--;
    }
    int siz=aaa.size();
    cout<<siz+1<<endl;
    for(auto x:aaa){
        cout<<x.first<<' '<<x.second<<endl;
    }

    return 0;
}

void solve(){
	ll k;
	scanf("%lld",&k);
	idx=1;
	while(k){
		if(k==2) break;
		if(k==3) {
			ans[++tot]={idx,idx+1};
			idx++;
			break;
		}
		if(k&1) {
			ans[++tot]={idx,idx+1};
			ans[++tot]={idx,idx+2};
			idx+=2;
			k=(k-1)/2;
			continue;
		}
		else {
			ans[++tot]={idx,idx+1};
			idx++;
			k--;
		}
	}
	printf("%d\n",idx);
	for(int i=1;i<=tot;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}