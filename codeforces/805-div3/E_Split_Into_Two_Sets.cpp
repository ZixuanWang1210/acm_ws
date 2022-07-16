#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

struct DSU {
    std::vector<int> p, siz;
    DSU(int n) : p(n+1), siz(n+1, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        p[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

void sol(){
    // int n; cin>>n;
    // unordered_map<int,int> mp;
    unordered_map<int,int> cnt;
    // vector<pii> vec;
    // set<pii> st;
    // for(int i=1;i<=n;i++){
    //     int a,b; cin>>a>>b;
    //     cnt[a]++,cnt[b]++;
    //     if(a>b) swap(a,b);
    //     st.insert({a,b});
    // }
    // for(auto x:st){
    //     // int a,b; cin>>a>>b;
    //     int a=x.first,b=x.second;
    //     if(mp[a]){
    //         vec.push_back({mp[a],b});
    //     }
    //     if(mp[b]){
    //         vec.push_back({mp[b],a});
    //     }
    //     mp[a]=b;
    //     mp[b]=a;
    // }

    // for(auto x:cnt){
    //     if(x.second!=2){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    int n; cin>>n;
    DSU plt(n);
    bool ok=false;
    for(int i=1;i<=n;i++){
        // int a=x.first,b=x.second;
        int a,b; cin>>a>>b;
        cnt[a]++,cnt[b]++;
        int pa=plt.find(a),pb=plt.find(b);
        if(pa!=pb){
            plt.merge(a,b);
        }
    }
    for(int i=1;i<=n;i++){
        if(plt.size(i)&1&&plt.find(i)==i){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(auto x:cnt){
        if(x.second&1){
            cout<<"NO"<<endl;
            return;
        }
    }
    // for(auto x:vec){
    //     int a=x.first,b=x.second;
    //     int pa=plt.find(a),pb=plt.find(b);
    //     if(pa!=pb){
    //         plt.merge(a,b);
    //     }
    //     else{
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    cout<<"YES"<<endl;

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
