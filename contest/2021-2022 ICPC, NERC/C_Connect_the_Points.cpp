#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

struct N{
	int x,y;
}p[5];
struct S{
	int a,b,c,d;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<S> v;
    for(int i=1;i<=3;i++){
        int a,b; cin>>a>>b;
        p[i]={a,b};
    }
    sort(p+1,p+4,[](N x,N y){return x.y<y.y;});
    int mid=p[2].y;
    sort(p+1,p+4,[](N x,N y){return x.x<y.x;});
    v.push_back({p[1].x,mid,p[3].x,mid});

    for(int i=1;i<=3;i++){
        if(mid==p[i].y) continue;
        v.push_back({p[i].x,mid,p[i].x,p[i].y});
    }
    cout<<v.size()<<endl;
    for(auto x:v){
        cout<<x.a<<' '<<x.b<<' '<<x.c<<' '<<x.d<<endl;
    }

    return 0;
}
