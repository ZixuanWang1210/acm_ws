//数据范围：20组 每个范围大
//原理：直接算组合数公式+lucas定理
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll p;

int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}

int C(int a,int b){
    // if(b>a) return 0;
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--){
        res=(ll)res*j%p;
        res=(ll)res*qmi(i,p-2)%p;
    }
    return res;
}

int lucas(ll a,ll b){
    if(a<p&&b<p) return C(a,b);
    return (ll)C(a%p,b%p)*lucas(a/p,b/p)%p;
}

int main(){
    int n; cin>>n;
    while(n--){
        ll a,b; cin>>a>>b>>p;

        cout<<lucas(a,b)<<endl;
    }

    return 0;
}