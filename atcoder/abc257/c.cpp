#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 5;
const ll mod = 998244353;
ll a[N];
int s1[N], s2[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>v1,v2;
	vector<int>ww;
	map<int, int>mp1,mp2;
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		if(s[i] == '0')
		v1.push_back(x), mp1[x] ++;
		else v2.push_back(x), mp2[x] ++;
		ww.push_back(x);
	}
	sort(ww.begin(), ww.end());
	ww.erase(unique(ww.begin(),ww.end()),ww.end());
	int len = ww.size();
	int c1 = 0, c2 = 0;
	for (int i = 0; i < len; i ++ ) {
		int x = ww[i];
		c1 += mp1[x];
		c2 += mp2[x];
		s1[i] = c1, s2[i] = c2;
	}
	int ans = 0;
	for (int i = 0;i < len; i ++ ) {
		int x = ww[i];
		// 设x不包括小孩
		int temp ;
		if(i == 0) temp = s2[len-1];
		else temp = s1[i-1] + s2[len-1] - s2[i-1];
		ans = max(ans, temp);
		
                // 设x包括小孩
		if(i == 0) temp = s2[len-1] - s2[i] + s1[i]; 
		else temp = s1[i] + s2[len-1] - s2[i];
		ans = max(ans, temp);
	}
	cout << ans;
}