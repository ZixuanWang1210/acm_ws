#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int lowbit(int x){
    return x&-x;
}

void sol(){
    int x; cin>>x;
    int y; cin>>y;
    int mxx=-1,mxy=-1;

    if(x-lowbit(x)==0){
        cout<<x<<endl;
        return ;
    }
    if(y-lowbit(y)==0){
        cout<<y<<endl;
        return ;
    }
    while(x){
        int t=lowbit(x);
        mxx=max(t,mxx);
        x-=t;
    }
    while(y){
        int t=lowbit(y);
        mxy=max(t,mxy);
        y-=t;
    }
    // mxx<<=1,mxy<<=1;
    // cout<<mxx<<" "<<mxy<<endl;
    if(mxx==mxy){
        cout<<-1<<endl;
        return;
    }
    else{
        int t=min(mxx,mxy);
        cout<<(t<<1)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
