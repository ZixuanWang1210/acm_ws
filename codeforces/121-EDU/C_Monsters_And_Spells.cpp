#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

// void sol(){
//     int n; cin>>n;
//     vector<int> k(n+1),h(n+1),a(n+1);
//     for(int i=1;i<=n;i++) cin>>k[i];
//     for(int i=1;i<=n;i++) cin>>h[i];

//     for(int i=1;i<=n;i++){
//         a[i]=k[i]-h[i]+1;
//     }
//     int _min=0x3f3f3f3f;
//     for(int i=n;i>=1;i--){
//         _min=min(_min,a[i]);
//         a[i]=_min;
//     }
//     for(int i=1;i<=n;i++){
//         // cout<<a[i]<<' ';
//         if(k[i+1]-k[i]==a[i+1]-a[i]&&h[i]!=1){
//             a[i+1]=a[i];
//         }
//     }
//     int re=a[1];
//     long long ans=0;
//     for(int i=1;i<=n;i++){
//         if(a[i]!=re){
//             int det=k[i-1]-a[i-1];
//             ans+=((1+det+1)*(det+1)/2);
//             re=a[i];
//         }
//     }
//     int det=k[n]-a[n];
//     ans+=((1+det+1)*(det+1)/2);
//     re=a[n];
//     cout<<ans<<endl;

// }

void sol() {
	int n(0);
	cin >> n;
	vector<int>k(n + 1, 0), h(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> k[i];
	for (int i = 1; i <= n; ++i) cin >> h[i];
	long long res = 0;
	int need = 0;
	int idx = n;
	while(idx){
		need = k[idx] - h[idx] + 1;
		long long dx = k[idx];
		--idx;
		while (idx && k[idx] >= need) {
			int dy = k[idx] - h[idx] + 1;
			need = min(need, dy);
			--idx;
		}
		dx = dx - need + 1;
		res += dx * (dx + 1) >> 1;
	}
	cout << res << '\n';
	return;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
