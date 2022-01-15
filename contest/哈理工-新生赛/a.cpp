#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int x; cin >> x;
    if(x == 1){
        cout << "You were studying Higher mathematics!";
    }
    else if(x == 2){
        cout << "You were studying Linear algebra!";
    }
    else if(x==3){
        cout << "You were studying Principle of computer composition!";
    }
    else if(x==4){
        cout << "You were studying Database system concept!";
    }
    else{
        cout << "You were playing games!";
    }
    

    return 0;
}
