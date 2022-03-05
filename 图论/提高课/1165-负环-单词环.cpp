#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int w[maxn],h[maxn],ne[maxn],e[maxn],idx;
bool st[maxn];
double dis[maxn];
int cnt[maxn];
int n;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool check(int mid){
    memset(st,0,sizeof st);
    memset(dis,0,sizeof dis);
    memset(cnt,0,sizeof cnt);
    queue<int>q;

    for(int i=0;i<676;i++){
        q.push(i);
        st[i]=true;
    }
    int cnunt=0;
    while(q.size()){
        int t=q.front(); q.pop();
        st[t]=false;

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]<dis[t]+w[i]-mid){
                dis[j]=dis[t]=w[i]-mid;
                cnt[j]=cnt[t]+1;
                if(++cnunt>10000) return true;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }

            }
        }
    }
    return false;
}

int main(){
    string s;
    while(cin>>n,n){
        memset(h,-1,sizeof h);
        idx=0;
        for(int i=0;i<n;i++){
            cin>>s;
            int len=s.length();
            if(len>=2){
                int left=(s[0]-'a')*26+s[1]-'a';
                int right=(s[len-2]-'a')*26+s[len-1]-'a';
                add(left,right,len);
            }
        }
        if(!check(0)){
            cout<<"No solution"<<endl;
        }
        else{
            double l=0,r=1000;
            while(r-l>1e-4){
                double mid=(l+r)/2;
                if(check(mid)){
                    l=mid;
                }
                else r=mid;
            }
            cout<<fixed<<setprecision(6)<<r<<endl;
        }
    }


    return 0;
}
