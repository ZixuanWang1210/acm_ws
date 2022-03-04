#include<bits/stdc++.h>
using namespace std;

const int maxn=50;
int din[maxn],dout[maxn];
int ans[maxn],cnt;
bool st[maxn];
int p[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

bool sol(){
    memset(din,0,sizeof din);
    memset(dout,0,sizeof dout);
    memset(st,0,sizeof st);
    int n; cin>>n;

    for(int i=0;i<26;i++) p[i]=i;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        int a=s[0]-'a',b=s[s.length()-1]-'a';
        din[b]++,dout[a]++;
        st[a]=st[b]=1;
        p[find(a)]=find(b);
    }

    //除起点之外，其他点 入度==出度
    int start=0,end=0;
    for(int i=0;i<26;i++){
        if(din[i]!=dout[i]){
            if(din[i]==dout[i]+1) end++;
            else if(din[i]+1==dout[i]) start++;
            else{
                return false;
            }
        }
    }
    if(!(end==0&&start==0||end==1&&start==1)) return false;

    //孤立点判断
    int anc=-1;
    for(int i=0;i<26;i++){
        if(st[i]){
            if(anc==-1){
                anc=find(i);
            }
            else if(anc!=find(i)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int _; cin>>_;
    while(_--){
        if(!sol()) puts("The door cannot be opened.");
        else puts("Ordering is possible.");

    }

    return 0;
}