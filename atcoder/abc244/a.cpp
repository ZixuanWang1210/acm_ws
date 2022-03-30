#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b,c,d; cin>>a>>b>>c>>d;
    if(a<c) cout<<"Takahashi"<<endl;
    if(a>c) cout<<"Aoki"<<endl;
    if(a==c) {
        if(b<=d)cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
    }
    

    return 0;
}
