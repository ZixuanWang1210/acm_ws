#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    int t; cin >> t;
    while(t--){
        int m, n; cin >> m >> n;
        cout << m << " " << (n + 1) / 2  << endl;

        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(down.empty() || x <= down.top()) down.push(x);
            else up.push(x);

            if(down.size() > up.size() + 1) up.push(down.top()), down.pop();
            if(up.size() > down.size()) down.push(up.top()), up.pop();

            if(i % 2){
                cout << down.top() << " ";
                if( ++ cnt % 10 == 0) cout << endl;
            }
        }
        if(cnt % 10) cout << endl;
    }

    return 0;
}
