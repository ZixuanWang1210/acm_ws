#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0, re = -1, _max = -1, _max2 = -1, ans;
        while(n--){
            string opt; cin >> opt;
            int num; cin >> num;
            if(opt == "LOST"){
                if(sum > 0) _max2 = max(_max2, num);

                re = sum;
                sum -= num;
                if(re > 0 && sum < 0){
                    _max = max(_max, -sum);
                    sum = 0;
                }
                else if(sum < 0){
                    sum = 0;
                }
                
            }
            else{
                sum += num;
            }
        }

        if(_max == -1){
            ans = sum + _max2;
        }
        else{
            ans = sum + _max;
        }
        cout << ans << "\n"; 

    }
   

    return 0;
}
