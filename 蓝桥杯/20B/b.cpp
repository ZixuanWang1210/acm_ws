#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n; cin>>n;
	vector<int> v(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		sum+=v[i];
	} 
	cout<<*max_element(v.begin()+1,v.begin()+n+1)<<endl;
	cout<<*min_element(v.begin()+1,v.begin()+1+n)<<endl; 
	cout<<fixed<<setprecision(2)<<(double)sum/n<<endl;
	
}
