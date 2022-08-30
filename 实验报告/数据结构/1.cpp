#include <bits/stdc++.h>
using namespace std;

signed main(){
    srand((unsigned)time(NULL));
    int n; cin>>n;
    set<int> a,b;
    for(int i=1;i<=n;i++){
        a.insert(rand());
        b.insert(rand());
    }

    set<int> _union,_join,_except; // 并 交 差
    for(auto x:a){
        _union.insert(x);
        _except.insert(x);
    }   
    for(auto x:b){
        _union.insert(x);
        if(_except.count(x)) _except.erase(x);
        if(a.count(x)) _join.insert(x);
    }

    for(auto x:_union) cout<<x<<' '; cout<<endl; // A 与 B 的并
    for(auto x:_except) cout<<x<<' '; cout<<endl; // A 中删去 B 的差
    for(auto x:_join) cout<<x<<' '; cout<<endl; // A 与 B 的交集

    return 0;
}
