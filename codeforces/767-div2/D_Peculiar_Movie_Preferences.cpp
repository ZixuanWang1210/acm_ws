#include<bits/stdc++.h>
using namespace std;

int n;
//hash
auto cal = [](string& s)->int {
	int dx = 0;
	for (auto c : s) dx = dx * 27 + (c - 'a' + 1);
	return dx;
};
void solve() {
	cin >> n;
	vector<string>strs(n);
	for (int i = 0; i < n; ++i) cin >> strs[i];
	set<int>s[4];
	for (auto str : strs) {
		string t = str;
		reverse(t.begin(), t.end());
		//在长度相同的里面去查找反串是否存在
		if (t == str || s[str.size()].find(cal(t)) != s[str.size()].end()) {
			cout << "YES" << '\n';
			return;
		}
		//如果长度为2 要去长度为3里面查找长度为2的前缀和是否存在
		if (str.size() == 2 && s[3].find(cal(t)) != s[3].end()) {
			cout << "YES" << '\n';
			return;
		}
		s[str.size()].insert(cal(str));
		if(str.size() == 3) {
			//检验长度为3的后缀的反串是否在前面出现
			t = str.substr(1, 2);
			reverse(t.begin(), t.end());
			if (s[2].find(cal(t)) != s[2].end()) {
				cout << "YES" << endl;
				return;
			}
			//将前缀的hash值加入set
			t = str.substr(0, 2);
			s[3].insert(cal(t));
		}
	}
	cout << "NO" << endl;
	return;
}
