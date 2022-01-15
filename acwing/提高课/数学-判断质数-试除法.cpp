#include<bits/stdc++.h>
using namespace std;

int n;

bool is_pri(int x){
    if(x <= 1) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    
    if(is_pri(n)) cout << n;
    else{
        for(int i = n + 1; ; i++){
            if(is_pri(i)){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}