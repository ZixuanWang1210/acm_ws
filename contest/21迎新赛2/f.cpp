#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n, t; cin >> t;
    while(t--){
        cin >> m >> n;
        int res = 0;
        while(!res)
        {
            if(m == n)
                res = m;
            else if(m > n)
            {
                m /= 2;
            }
            else
            {
                n /= 2;
            }
        }
        cout << res << "\n";
    }

    return 0;
}