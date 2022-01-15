#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, h;
    set<int>s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> h;
            s.insert(h);
        }
        cout << s.size() << endl;
        s.clear();
    }
    
    return 0;
}