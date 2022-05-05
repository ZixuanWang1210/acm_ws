#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

struct node{
    int like,sou,id;
    bool operator<(const node &t) const{
        if(like==t.like){
            return sou<t.sou;
        }
        else return like<t.like;
    }
};

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    string s; cin>>s;

    vector<node> vec(n+1);
    for(int i=0;i<s.length();i++){

        int lik=s[i]-'0';
        vec[i+1]={lik,v[i+1],i+1};
    }
    sort(vec.begin()+1,vec.begin()+1+n);
    vector<int> ans(n+1);

    for(int i=1;i<=n;i++){
        ans[vec[i].id]=i;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
