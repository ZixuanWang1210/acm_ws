#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, x1;
    cin >> n >> x1;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.push_back(temp);
    }
    // cin >> x1;
    for(auto x : v){
        if(x % x1 == 0){
            int num = x / x1;
            for(int i = 0; i < num; i++){
                v.push_back(x / x1);
            }
        }
    }
    long long sum = 0;
    for(auto x : v){
        sum += x;
    }
    cout << sum;
    return 0;
}