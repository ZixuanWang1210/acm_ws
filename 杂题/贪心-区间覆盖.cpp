#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, s, t, ans;
bool success;
vector<pii> v;

int main(){
    cin >> s >> t;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        int j = i,tmp = s;
        while(v[j].first <= s && j < n){
            tmp = max(tmp, v[j].second);
            j++;
        }
        if(s == tmp || tmp < s){
            ans = -1;
            break;
        }
        ans++;
        if(tmp >= t){
            success = true;
            break;
        }
        s = tmp;
        i = j - 1;
    }

    if(success)cout<<ans;
    else cout <<-1;

    return 0;
}
