#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long
#define fir(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

// int n,f;
const int maxn=1e5+10;
// double a[maxn],s[maxn],smin[maxn],sid[maxn];

// // int check(double mid){
// //     for(int i=1;i<=n;i++){
// //         s[i]=a[i]-mid;
// //         s[i]+=s[i-1];
// //     }
// //     double ans=-1e8,minn=1e8;
// //     for(int i=f;i<=n;i++){
// //         minn=min(minn,s[i-f]);
// //         ans=max(ans,s[i]-minn);
// //     }
// //     return ans<=0?0:1;
// // }
// int check(double mid)
// {
//     fir(i,1,n)
//         s[i]=a[i]-mid,s[i]+=s[i-1];
//     double ans=-1e8,min_val=1e8;
//     fir(i,f,n)
//     {
//         min_val=min(min_val,s[i-f]);
//         ans=max(ans,s[i]-min_val);
//     }
//     return ans<=0?0:1;
// }

// void sol(){
//     cin>>n>>f;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }

//     double l=-1e6,r=1e6;
//     while(r-l>1e-6){
//         cout<<1<<endl;
//         int mid=(l+r)/2;
//         if(check(mid)) l=mid;
//         else r=mid;
//     }
//     cout<<l<<endl;
// }

// signed main(){
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     int _=1;
//     // cin>>_;
//     while(_--){
//         sol();
//     }

//     return 0;
// }
int n,f;
double min_val,ans,l,r,mid,a[maxn],s[maxn];
int check(double mid)
{
    fir(i,1,n)
        s[i]=a[i]-mid,s[i]+=s[i-1];
    ans=-1e8,min_val=1e8;
    fir(i,f,n)
    {
        min_val=min(min_val,s[i-f]);
        ans=max(ans,s[i]-min_val);
    }
    return ans<=0?0:1;
}
int main()
{
    cin>>n>>f;   
    fir(i,1,n)
        cin>>a[i];
    l=-1e6,r=1e6;
    while(r-l>1e-5)
    {
        mid=(l+r)/2;
        if (check(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<(long long)(r*1000);
}