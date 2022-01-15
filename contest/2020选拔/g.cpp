#include<bits/stdc++.h>
using namespace std;

int n, x, ans;

int main(){
    cin >> n;
    while(n--){
        int x; cin >> x;
        if(x == 4){
            cout << '0' << endl;
            continue;
        }
        else if(x < 4){
            x ++;
        }
        if(x % 2 == 0){
            ans = x / 2;
            cout << ans << endl;
        }
        else{
            cout << 2 << endl;
        }
    }


    return 0;
}