#include<bits/stdc++.h>
using namespace std;

set<int> s;

int main(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    while(q--){
        int opt; cin >>opt;
        if(opt == 1){
            int x; cin >> x;
            s.insert(x);
            auto i = s.end();
            i--;
            cout << *i << endl;
        }
        else{
            int x; cin >> x;
            s.erase(x);
            auto i = s.end();
            i--;
            cout << *i << endl;
        }
    }

    return 0;
}