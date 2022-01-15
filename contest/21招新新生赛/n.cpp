#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    // if(n == 1 && m == 1) puts("zynb");
    // else if(n % 3 == 0){
    //     n = n % 3;
    //     if(m % 2 == 0) puts("zynb");
    //     else puts("whrnb");
    // }
    
    // else{
    //     n = n % 3;
    //     m = m + n % 3;
    //     if(m % 2 == 0) puts("whrnb");
    //     else puts("whrnb");
    // }
    n = n % 3;

    if(n == 0 && m % 2 != 1) puts("zynb");
    else if(n == 1 && m % 2 == 1) puts("zynb");
    else puts("whrnb");

    return 0;
}
