#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;

    int cnt=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            cout<<' ';
        }
        cnt--;
        for(int j=1;j<=2*i-1;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    cnt=2;
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=cnt;j++){
            cout<<' ';
        }
        cnt++;
        for(int j=1;j<=2*i-1;j++){
            cout<<'*';
        }
        cout<<endl;
    }

    cout<<"======================"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            cout<<' ';
        }
        cnt--;
        for(int j=1;j<=2*i-1;j++){
            if(j==1||j==2*i-1) cout<<'*';
            else cout<<' ';
        }
        cout<<endl;
    }
    cnt=3;
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=cnt;j++){
            cout<<' ';
        }
        cnt++;
        for(int j=1;j<=2*i-1;j++){
            if(j==1||j==2*i-1) cout<<'*';
            else cout<<' ';
        }
        cout<<endl;
    }


    return 0;
}
