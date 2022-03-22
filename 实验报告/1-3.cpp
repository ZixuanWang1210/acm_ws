#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x; cin>>x;
    if(x==100){
        cout<<"A";
    }
    else{
        x/=10;
        switch(x){
            case 9:
                cout<<"A";
                break;
            case 8:
                cout<<"B";
                break;
            case 7:
                cout<<"C";
                break;
            case 6:
                cout<<"D";
                break;
            default:
                cout<<"E";
                break;
        }
    }

    return 0;
}
