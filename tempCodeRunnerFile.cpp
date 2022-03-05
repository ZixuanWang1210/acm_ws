#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int a,b,c,x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>x;
    if(x<=a){
        cout<<fixed<<setprecision(12)<<1<<endl;
        return 0;
    }
    else if(x>a&&x<=b){
        double ans=(double)c/(double)(b-a);
        cout<<fixed<<setprecision(12)<<ans<<endl;
        return 0;
    }
    else{
        cout<<fixed<<setprecision(12)<<0<<endl;
        return 0;
    }
    

    return 0;
}
