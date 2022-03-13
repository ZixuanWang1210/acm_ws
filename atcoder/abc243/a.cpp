#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v,a,b,c;
    cin>>v>>a>>b>>c;
    // cout<<100000%3<<' ';
    v%=(a+b+c);
    if(v<a){
        cout<<'F';
    }
    else if(v<a+b){
        cout<<'M';
    }
    else {
        cout<<'T';
    }
    

    return 0;
}
