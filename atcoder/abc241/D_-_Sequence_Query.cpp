#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

multiset<long long> se;
int q;

void work(){
    int op,x; cin>>op>>x;
    if(op==1){
        se.insert(x);
        return;
    }
    else if(op==2){
        int k; cin>>k;
        auto res=se.upper_bound(x);
        // res--;
        while(k--){
            res=prev(res);
            if(res==se.begin()&&k){
                cout<<-1<<endl;
                return;
            }
        }
        cout<<*res<<endl;
        return;
    }
    else{
        int k; cin>>k;
        auto res=se.lower_bound(x);
        res--;
        while(k--){
            res++;
            auto ed=prev(se.end());
            
            // cout<<res-se.begin()<<' '<<se.end()<<endl;
            if(res==ed&&k){
                cout<<-1<<endl;
                return;
            }
        }
        cout<<*res<<endl;
        return;
    }


}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
        work();
    }
    

    return 0;
}
