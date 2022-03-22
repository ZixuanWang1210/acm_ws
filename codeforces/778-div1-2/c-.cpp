#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    // cout<<1<<endl;
    int n; cin>>n;
    multiset<int> st;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        st.insert(t);
    }

    queue<multiset<int>> q;
    q.push(st);
    while(q.size()){
        auto t=q.front(); q.pop();
        if(t.size()==1){
            cout<<"Yes"<<endl;
            return;
        }
        for(auto x=st.begin();x!=prev(st.end());x++){
            auto now=x,nex=++x;x--;
            if(abs(*now-*nex)<=1){
                auto temp=t;
                temp.erase(now);
                temp.erase(nex);
                q.push(temp);
                if(temp.size()==1||temp.size()==0){
                    cout<<"Yes"<<endl;
                    temp.~multiset();
                    t.~multiset();
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
