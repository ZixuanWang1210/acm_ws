#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define int long long 
// typedef unsigned long long ull;

using namespace std;

// void sol(){
//     int n; cin>>n;
//     vector<int> v(2*n),s(2*n);
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//         v[i]++;
//     }
//     sort(v.begin()+1,v.begin()+1+n);
//     for(int i=1;i<=n;i++){
//         s[i]=s[i-1]+v[i];
//     }
//     if(n%2){
//         int mid=1+n>>1;
//         if(s[mid]<s[n]-s[mid]) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     else{
//         int mid=1+n>>1; mid++;
//         if(s[mid]<s[n]-s[mid]) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//         // cout<<s[mid] <<' '<<s[n]-s[mid]<<endl;
//     }
//     // if(v[1]+v[2]>=v[n]) cout<<"NO"<<endl;
//     // else cout<<"YES"<<endl;
// }
void sol(){
    int n; cin>>n;
    vector<int> v(n*3),a(n*3);   
    int mid=(n+1)/2;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(int i=1;i<=n;i++){
        a[i]=v[i]-v[i-1];
        // cout<<a[i]<<' ';
        if(i<=mid) cnt1+=a[i];
        else cnt2+=a[i];
    }
    if(cnt1>cnt2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
