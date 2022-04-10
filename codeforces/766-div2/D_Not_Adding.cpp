#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=1e6+10;

bool dis[N];

int main()
{
	int n, x;
	scanf("%d", &n); 
	int ans = -n;
	while(n --)scanf("%d", &x), dis[x] = 1;
	for(int i = 1;i <= 1e6;i ++)
	{
		int t = 0;
		for(int j = i;j <= 1e6; j += i)
			if(dis[j])
			    t = __gcd(t, j);
		ans += t == i;
	}
	cout<<ans<<endl;
	return 0;
}
