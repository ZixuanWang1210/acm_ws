//思路：转化一下就是问是否存在正整数b，使得s1*b*b=s2。
//那么先暴力打表长度在7以内的答案，偶数长度就是以164开头的，后面位数不足再添0；
//奇数长度以1144开头，位数不足补0。

#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    if(n<=3) cout<<-1<<endl;
    else{
        if(n&1){
            cout<<16400;
            n-=5;
            for(int i=0;i<n;i++) cout<<0;
            cout<<endl;
        }
        else {
            cout<<1144;
            n-=4;
            for(int i=0;i<n;i++) cout<<0;
            cout<<endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
