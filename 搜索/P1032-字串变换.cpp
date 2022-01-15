#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<string, string> 

using namespace std;

vector<pii> v;
struct p{
    string s;
    int cnt;
};
queue<p> q;
int ans = 0x3f3f3f3f;
string a, b, c, d;
map<string, int> mp;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> a >> b;
    while(cin >> c >> d){
        v.push_back({c, d});
    }
    q.push({a, 0});

    while(!q.empty()){
        auto top = q.front();
        q.pop();
        if(top.s == b){
            ans = min(ans, top.cnt);
            if(ans > 10){
                cout << "NO ANSWER!";
                return 0;
            }
            else{
                cout << ans;
                return 0;
            }
        }

        for(auto x : v){
            string pp = top.s, pa;
            int t = pp.find(x.first);
            while(t != pp.npos){
                pa = pp.substr(0, t);
                pa = pa + x.second;
                int ka = 0;
                pa += pp.substr(t + x.first.size());
                if(top.cnt + 1 < mp[pa] || mp[pa] == 0){
                    q.push({pa, top.cnt + 1});
                    mp[pa] = top.cnt + 1;
                }
                t = pp.find(x.first, t + 1);
            }
        }

    }
    cout << "NO ANSWER!";

    return 0;
}
