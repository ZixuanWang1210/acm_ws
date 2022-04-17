#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

map<char,int> mp;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int a[100000]={0};
    int mx=0;
    while(n--){
        char c; cin>>c;
        a[c-'A']++;
        mx=max(a[c-'A'],mx);
    }
    for(char i='A';i!='Z';i++){
        if(mx==a[i-'A']){
            cout<<i<<endl;
            return 0;
        }
    }
    

    return 0;
}
