#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main(){
    int n,s;
    cin>>n>>s;
    stack<int> hz;
    vector<int> temp;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        temp.push_back(t);
    }
    for(int i=temp.size()-1;i>=0;i--){
        hz.push(temp[i]);
    }

    stack<int> wp;
    while(n>0){
        if(!wp.size()){
            for(int i=1;i<=min(n,s);i++){
                int t; cin>>t;
                wp.push(t);
            }
            n-=s;
        }
        while(wp.size()){
            int thz=hz.top(); hz.pop();
            int twp=wp.top(); wp.pop();
            mp[thz]=twp;
        }
    }
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        if(mp[x]==0) cout<<"Wrong Number"<<endl;
        else cout<<mp[x]<<endl;
    }

    return 0;
}