#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a1,a2,n; 
    // int a[10000]={0};
    vector<int> a;
    int x;
    cin>>x;
    a.push_back(x);
    cin>>x;
    a.push_back(x);
    cin>>n;
    // for(int i=3;i<=n;i++){
    //     a[i]=a[i-1]*a[i-2];
    //     if(a[i]>10){
    //         a[i+1]=a[i]%10;
    //         a[i]/=10;
    //         i++;
    //     }
    //     if(a[n]!=0){
    //         for(int i=1;i<=n;i++){
    //             cout<<a[i]<<' ';
    //         }
    //         cout<<endl;
    //     }
    // }
    int idx=-1;
    while(a.size()<=n){
        idx++;
        int res=a[idx]*a[idx+1];
        if(res<10) a.push_back(res);
        else{
            a.push_back(res/10);
            a.push_back(res%10);
        }
    }
    for(int i=0;i<=n-1;i++){
        cout<<a[i];
        if(i!=n-1) cout<<' ';
    }
    // cout<<endl;

    return 0;
}
