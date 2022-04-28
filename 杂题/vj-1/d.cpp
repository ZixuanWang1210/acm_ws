#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s;
    // getline(cin,s);
    getline(cin,s);
    int res[2000000]={0};
    int lst=0;
    for(int i=0;i<s.length();i++){
        res[i]=s[i];
        vector<int> v;
        for(int j=0;j<8;j++){
            int tt=(res[i]>>j)&1;
            if(tt) v.push_back(1);
            else v.push_back(0);
        }
        res[i]=0;
        reverse(v.begin(),v.end());
        int base=1;
        for(int j=0;j<8;j++){
            if(v[j]) res[i]+=base;
            base*=2;
        }
        cout<<(lst-res[i]+256)%256 <<endl;
        lst=res[i];
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
