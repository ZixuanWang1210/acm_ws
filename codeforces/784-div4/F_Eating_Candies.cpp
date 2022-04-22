#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=2e5+10;

// void sol(){
//     int n; cin>>n;
//     vector<int> v(n+1),sum1(n+1),sum2(n+2);
//     set<int> st;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         sum1[i]=sum1[i-1]+v[i];
//         st.insert(sum1[i]);
//     }
//     int ans2=0;
//     int tt=0;
//     for(int i=n;i>=1;i--){
//         sum2[i]=sum2[i+1]+v[i];
//         if(st.count(sum2[i])!=0){
//             ans2=n-i+1;
//             tt=sum2[i];
//         }
//     }
//     int ans1=lower_bound(v.begin()+1,v.begin()+1+n,tt)-v.begin();

//     cout<<ans1+ans2<<endl;

// }

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int l=1,r=n;
    int ans=0;
    int sum1=v[1],sum2=v[n];
    while(l<r){
        if(sum1<sum2){
            l++;
            sum1+=v[l];
        }
        else if(sum1>sum2){
            r--;
            sum2+=v[r];
        }
        else{
            ans=l+(n-r+1);
            l++,r--;
            sum2+=v[r];
            sum1+=v[l];
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
