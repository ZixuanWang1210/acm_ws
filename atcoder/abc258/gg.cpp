#include<bits/stdc++.h>
#define debug_(x) cerr << #x << " = " << x << ' '
#define debug(x) cerr << #x << " = " << x << '\n'

using namespace std;

typedef long long ll;

const int N = (int)3e3;

bitset<N> s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		s[i] = bitset<N>(str);
	}
	ll res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(s[i][j] == 1) {
				res += (s[i] & s[j]).count();
			}
		}
	}
	cout << res / 3 << '\n';
	
	return 0;
}