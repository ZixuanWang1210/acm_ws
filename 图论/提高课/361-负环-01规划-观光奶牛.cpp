#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
int e[maxn],ne[maxn],h[maxn],idx,wp[maxn],wseg[maxn];
double dis[maxn];
int cnt[maxn];
bool st[maxn];
int L,P;

void add(int a,int b,int c){
    e[idx]=b,wseg[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa(double mid){
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    for(int i=1;i<=L;i++){
        q.push(i);
        st[i]=true;
    }
    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            // double v=j*mid
            if(dis[j]<dis[t]+wp[t]-mid*wseg[i]){
                dis[j]=dis[t]+wp[t]-mid*wseg[i];
                cnt[j]=cnt[t]+1;

                if(cnt[j]>=L) return true;

                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>L>>P;
    for(int i=1;i<=L;i++) cin>>wp[i];

    memset(h,-1,sizeof h);
    for(int i=1;i<=P;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
    }

    double l=0,r=1e7;
    while(r-l>1e-4){
        double mid=(l+r)/2;
        if(spfa(mid)) l=mid;
        else r=mid;
    }

    cout<<fixed<<setprecision(2)<<l;
    return 0;
}

