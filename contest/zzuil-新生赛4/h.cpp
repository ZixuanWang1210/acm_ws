#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    while(n--){
        int t; cin >> t;
        unordered_set<string> s;
        for(int i = 1; i <= t; i++){
            string x; cin >> x;
            if(s.find(x) == s.end()) s.insert(x);
            else{
                s.erase(x);
            }
            
        }
        if(s.empty()){
            cout << "oh my pins" << endl;
            continue;
        }
        else{
            cout << s.size() << endl;
            for(auto k : s){
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
