#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

#define pii pair<int, int>

unordered_map<string, pii> mp;
int n;
vector<pii> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        int time; cin >> time;
        auto tmp = mp.find(s);

        if(tmp == mp.end()){
            mp[s] = {time, i};
        }
        else{
            if(time > tmp->second.first){
                mp.erase(tmp);
                mp[s] = {time, i};
            }
        }
    }

    for(auto x : mp){
        v.push_back(x.second);
    }

    sort(v.begin(), v.end());

    for(auto x : v){
        cout << x.second << endl;
    }
    

    return 0;
}
