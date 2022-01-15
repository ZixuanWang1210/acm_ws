#include <bits/stdc++.h>

using namespace std;

int n, u, d, _time, delta, remain;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    while(scanf("%d %d %d", &n, &u, &d) && n != 0){
        if(n == 0) return 0;
        remain = n;
        int flag = 0;
        while(remain > u){
            if(flag = 1){
                remain += d;
                _time++;
            }
            flag = 1;           
            remain -= n;
            _time++;
        }
        _time++;
        cout << _time;
    }

    return 0;
}
