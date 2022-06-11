#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

struct node{
    int l;
    mutable int v;
    bool operator<(const node &o) const { return l < o.l; }
};
set<node>st;
void add(int id, int x) {
    st.insert({ id,x });
    auto it = st.find({ id,x });
    it->v = x;
    if (it != st.begin() && prev(it)->v <= x) {
        st.erase(it);
        return;
    }
    while (next(it) != st.end() && x <= next(it)->v) {
        st.erase(next(it));
    }
}

const int maxn=1e5+10;
int n, m, a[maxn], d, k;
void sol() {
    st.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i], add(i, a[i]);
    vector<int>ans;
    while (m--) {
        cin >> k >> d;
        a[k] -= d;
        add(k, a[k]);
        ans.push_back(st.size());
    }
    for (int x : ans)cout << x << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
