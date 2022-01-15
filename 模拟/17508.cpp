#include<bits/stdc++.h>
using namespace std;

int k,m;

struct cmp{
    bool operator ()(const int&u,const int&v){
        if(abs(u-v)<=k) return false;
        return u<v;
    }
};

set<int,cmp>s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>k;
    string str;
    int x;
    while(m--){
        cin>>str>>x;
        if(str=="add") s.insert(x);
        else if(str=="del") s.erase(x);
        else printf("%s\n" , s.find(x) != s.end() ? "Yes" : "No");
    }
    return 0;
}