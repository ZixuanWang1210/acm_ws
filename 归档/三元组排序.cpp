#include <bits/stdc++.h>
using namespace std;

struct node{
    int a;
    double b;
    string c;
    bool operator<(const node &t) const{
        return a<t.a;
    }
} ;

const int maxn=1e4+10;
node arr[maxn];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    }
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++){
        node x=arr[i];
        cout<<x.a<<' '<<fixed<<setprecision(2)<<x.b<<' '<<x.c<<endl;
    }
    // vector<node> v;
    // for(int i=1;i<=n;i++){
    //     node x; cin>>x.a>>x.b>>x.c;
    //     v.push_back(x);
    // }ort(v.begin(),v.end());
    // s
    // for(auto x:v){
    //     cout<<x.a<<' '<<fixed<<setprecision(2)<<x.b<<' '<<x.c<<endl;
    // }
    
    return 0;
}