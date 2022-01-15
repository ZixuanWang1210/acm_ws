#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 10000 + 10;
int a[maxn];
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        q.push(temp);
    }

    int ans = 0;

    while(q.size() != 1){
        int fri = q.top(); q.pop();
        int se = q.top(); q.pop();

        q.push(fri + se);
        ans = ans + fri + se;
    }

    
    cout << ans;
    

    return 0;
}
