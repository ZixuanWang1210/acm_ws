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
    long long base = 1;
   for(auto x : a){
       sum += x;
       if(x % x1 == 0){
           
       }
   }

    cout << sum;
    return 0;
}