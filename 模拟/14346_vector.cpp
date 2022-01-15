#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t, n;
    vector<int>v;

    cin >> t;
    for(int i = 0; i < t; i++){
        int num, temp;
        cin >> num;
        for(int j = 0; j < num; j++){
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        auto n = unique(v.begin(), v.end());
        v.erase(n, v.end());
        cout << v.size() << endl;
        v.clear();
    }


    return 0;
}