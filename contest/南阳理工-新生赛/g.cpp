#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool st[30] = {false};
vector<pii> v;

bool cmp(pii &a, pii &b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, x, ans = 0;
    cin >> n >> x;
    while(n--){
        int l, m;
        cin >> l >> m;
        if(l >= 19) m -= x;
        else if(l <= 8) l = 8;
        if(m <= 0) continue;
        v.push_back({m, l});
    }   

    sort(v.begin(), v.end(), cmp);

    for(auto x : v){
        int idx = -1;
        for(int i = x.second; i <= 23; i++){
            if(!st[i]){
                idx = i;
                break;
            }
        }
        if(idx == -1) continue;
        st[idx] = true;

        ans += x.first;
    }

    cout << ans;

    return 0;
}