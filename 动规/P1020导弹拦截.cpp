//f(x) 是以a[x]为结尾的LIS
#include <bits/stdc++.h>
using namespace std;

int data[1000100], f[1000100], dp[1000100];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int temp, i = 1;
    while(cin >> temp){
        f[1] = 1, dp[1] = 1;
        data[i] = temp;
        for(int j = 1; j < i; j++){
            if(data[j] >= temp) f[i] = max(f[i], f[j]+1);
            if(data[j] < temp) dp[i] = max(dp[i], dp[j]+1);
        }
        i++;
    }
    //cout <<i;
    cout <<f[--i] << endl << dp[i];
    return 0;
}
