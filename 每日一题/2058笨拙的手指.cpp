#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

char rev(char a){
    if(a == '1') return '0';
    else return '1';
}

int change(string s, int b){
    int ret = 0;
	int base = 1;
    for(int i = s.size() - 1; i >= 0; i --){
        int temp = s[i] - '0';
        ret = ret + (temp * base);
        base *= b;
    }
    return ret;
}

string s1, s2;
unordered_set<int> st;
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> s1 >> s2;
	string re = s1;
    for(int i = 0; i < s1.size(); i ++){
        s1[i] = rev(s1[i]);
		st.insert(change(s1, 2));
		s1 = re;
    }

	re = s2;
	for(int i = 0; i < s2.size(); i++){
		int temp = s2[i] - '0';
		for(int j = 1; j <= 2; j ++){
			temp = (temp + 1) % 3;
			s2[i] = temp + '0';
			if(st.find(change(s2, 3)) != st.end()){
				cout << change(s2, 3);
				return 0;
			}
		}
		s2 = re;
	}
    

    return 0;
}
