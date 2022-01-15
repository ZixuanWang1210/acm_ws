#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a1, a2, b1, b2;
ll h, ans, total;

int main(){
    cin >> a1 >> b1 >> a2 >> b2 >> h;

    ll bt_ren, bt_bs;
    bt_ren = a1 - b2;
    bt_bs = a2 - b1;
    if(h <= 0){
        cout << 0;
        return 0;
    }
    if(bt_ren <= 0){
        cout << -1;
        return 0;
    }
    if(bt_bs <= 0){
        bt_bs = 0;
        cout << 0;
        return 0;
    }
    else{
        while(1){
            h -= bt_ren;
            if(h > 0) total += bt_bs;
            else{
                break;
            }
        }
    }
    cout << total;
    return 0;
}