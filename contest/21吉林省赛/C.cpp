#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF=1e9;
int a,b,m,x1,y;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int bsgs(int a, int b, int p){
    if(1%p==b%b) return 0;
    int k=sqrt(p)+1;
    unordered_map<int,int> hash;
    for(int i=0, j=b%p; i<k; i++){
        hash[j]=i;
        j=1ll*j*a%p;
    }
    int ak=1;
    for(int i=0; i<k; i++) ak=1ll*ak*a%p;
    for(int i=1, j=ak; i<=k; i++){
        if(hash.count(j)) return i*k-hash[j];
        j = 1ll*j*ak%p;
    }
    return -INF;
}

int exbsgs(int a, int b, int p){
    b=(b%p+p)%p;
    if(1%p==b%p) return 0;
    int x,y;
    int d=exgcd(a,p,x,y);
    if(d>1){
        if(b%d) return -INF;
        exgcd(a/d, p/d, x,y);
        return exbsgs(a, 1ll*b/d*x%(p/d),p/d)+1;
    }
    return bsgs(a,b,p);
}

int ksm(int a, int b, int p){
    int res=1;
    while(b){
        if(b&1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        b >>= 1;
    }
    return res;
}

int inv(int a,int p){
    return ksm(a, p-2, p);
}


signed main()
{
    cin >> a >> b >> m >> x1 >> y;
    if(a==0) {
        if(x1==y || b==y) cout << "YES";
        else cout << "NO";
    }
    else if(a==1){
        if(b==0){
            if(y==x1) cout << "YES";
            else cout << "NO";
        }
        else 
            cout << "YES";
        
    }
    else{
        int C=1ll*b*inv(a-1,m)%m;
        if((x1+C)%m==0){
            if((m-C)%m==y) cout<< "YES";
            else cout << "NO";
        }
        else{
            int B=(y+C)%m;
            int x,y;
            // exgcd(x1+b)
            int r=exbsgs(a,1ll*B*inv((x1+C)%m,m),m)+1;
            if(r<0) cout << "NO";
            else cout << "YES";
        }
    }
    return 0;
}