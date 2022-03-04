#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;

unordered_map<string,int> mp;
int idx;
int d[maxn];
int p[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

bool join(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return false;
    p[a]=b;
    return true;
}

int get(string s){
    if(mp[s]==0) mp[s]=++idx;
    return mp[s];
}

int main(){
    for(int i=0;i<=maxn;i++) p[i]=i;
    int cnt=0;
    string s1,s2;
    while(cin>>s1>>s2){
        int a=get(s1),b=get(s2);
        d[a]++,d[b]++;
        if(join(a,b)) cnt++;
    }
    if(cnt<idx-1){
        cout<<"Impossible"<<endl;
        return 0;
    }
    cnt=0;
    for(int i=1;i<=idx;i++){
        if(d[i]&1){
            cnt++;
            if(cnt>2){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}