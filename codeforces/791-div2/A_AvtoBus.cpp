#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int x; cin>>x;

    int cnt=x/2;
    if(x%2||x==2) {cout<<-1<<endl; return;}
    else{
        if(cnt%3==0) cout<<cnt/3<<' ';
        else{
            if(cnt%3==2) cout<<(cnt-2)/3+1<<' ';
            if(cnt%3==1)  cout<<(cnt-4)/3+2<<' ';
        }

        if(cnt%2==0) cout<<cnt/2<<endl;
        else cout<<(cnt-1)/2<<endl;
    }


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
