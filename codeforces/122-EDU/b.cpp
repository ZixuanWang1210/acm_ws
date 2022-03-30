#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

const int maxn=2e5+10;

void sol(){
	string s; cin>>s;
	vector<int> v;

	for(int i=0;i<s.length();i++){
		int x=s[i]-'0';
		v.push_back(x);
	}

	int cnt1=count(v.begin(),v.end(),1),cnt0=count(v.begin(),v.end(),0);

	
	if(cnt1!=cnt0){
		cout<<min(cnt1,cnt0)<<endl;
		return;
	}
	else{
		cout<<cnt1-1<<endl;
	}

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
