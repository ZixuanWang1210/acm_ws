#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
	int x; cin>>x;
	if(x%7==0){
		cout<<x<<endl;
		return;
	}
	x/=10;
	x*=10;
	for(int i=0;i<=9;i++){
		int nn=x+i;
		if(nn%7==0){
			cout<<nn<<endl;
			return;
		}
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
