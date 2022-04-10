##include<bits/stdc++.n>
using namespace std;
#defind pdd pair<double,double>
int main(){
	int n; cin>>n;
	int cnt=0;
	vector<pdd> v;
	vector<pii> ask;
	for(int i=1;i<=n;i++){
		int a,b; cin>>a>>b;
		for(int j=0;j<ask.size();j++){
			double x=(double)(ask[j].second-b)/(double)(a-ask[i].frist])
			double y=a*x+b;
			int bz=true;
			for(int k=0;k<v.size();k++){
				if(abs(v[k].first-x)<1e-3&&abs(v[k].second-y)<1e-3) bz=false;
			} 
			if(bz) v.push_back({x,y});
			else cnt++;
		}
		ask.push_back({a,b});
	}
	
	
	
	
	return 0;
} 
