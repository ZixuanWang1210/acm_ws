#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, hc, dc, hm, dm;
int k, w, a;
bool check(int b, int a)
{
	int t = hm / a + (hm % a == 0 ? 0 : 1);
	t --;
	if (t == 0)	return true;
	if (b / t + (b % t == 0 ? 0 : 1) > dm)	return true;
	else return false;
}
signed main() {
    cin >> T;
    while (T -- ) {
    	cin >> hc >> dc;
    	cin >> hm >> dm;
    	cin >> k >> w >> a;
    	bool flag = 0;
    	for (int i = 0; i <= k; i ++ ) {
    		int _hc = i * a + hc;
    		int _dc = (k - i) * w + dc;
    		if (check(_hc, _dc)) {
    			flag = 1;
    			break;
    		}
    	}
    	if (flag)	cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    return 0;
}
