#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;
unsigned long long sum = 0;

int main(){
    int n, x1;
    cin >> n >> x1;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        a.push_back(temp);
    }

    int idx = 1;
    while(idx != 0){
        b.clear();
        idx = 0;
        for(auto x : a){
            if(x % x1 == 0){
                int num = x / x1;
                for(int i = 0; i < num; i++){
                    b.push_back(num);
                    idx ++;
                }
            }
            sum += x;
        }
        a = b;
    }

    cout << sum;
    return 0;
}