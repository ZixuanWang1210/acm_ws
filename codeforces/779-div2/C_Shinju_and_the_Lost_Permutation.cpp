#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
	int n; cin>>n;
	vector<int> v(2*n);
	int idx=-1;
	bool bz=true;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]==1){
			if(idx!=-1) bz=false;
			idx=i;
		}
	}
	if(!bz){
		cout<<"NO"<<endl;
		return; 
	}
	
	vector<int> nw;
	for(int i=idx;i<=n;i++) nw.push_back(v[i]);
	for(int i=1;i<idx;i++) nw.push_back(v[i]);
	
	for(int i=1;i<nw.size();i++){
		if(nw[i]-nw[i-1]>1){
			cout<<"NO"<<endl;
			return;
		} 
	}
	cout<<"YES"<<endl;
	
	
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
