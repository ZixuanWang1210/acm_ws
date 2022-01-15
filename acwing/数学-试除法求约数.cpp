#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        vector<int> v;
        for(int i = 1; i <= x / i; i++){
            if(x % i == 0){
                v.push_back(i);
                if(i != (x / i))
                    v.push_back(x / i);
            }
        }
        sort(v.begin(), v.end());
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }


    return 0;
}