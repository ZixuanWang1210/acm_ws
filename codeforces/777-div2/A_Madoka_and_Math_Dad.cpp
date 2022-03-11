#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


void sol(){
    int x;
    cin>>x;
    if(x==1){
        cout<<1<<endl;
        return;
    }
    else if(x==2){
        cout<<2<<endl;
        return;
    }
    else{
        if(x%3==1){
            cout<<1;
            x--;
            while(x){
                cout<<21;
                x-=3;
            }
        }
        else if(x%3==0){
            while(x){
                cout<<21;
                x-=3;
            }
        }
        else{
            cout<<2;
            x-=2;
            while(x){
                cout<<12;
                x-=3;
            }
        }
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
