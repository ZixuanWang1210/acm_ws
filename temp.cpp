#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int manx=1e5+10;
priority_queue<int> pq;
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    string s;
    cin>>s;
    vector<int> v,b(2*n);
    v.push_back(0);
    int sum=0;
    // int re=1;
    int cnt=0;
    bool bz=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            bz=true;
            if(cnt) pq.push(cnt);
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    
    if(cnt) pq.push(cnt);
    if(bz==false){}

    int t=pq.top(); pq.pop();
    int a=ceil((double)t/2),bb=floor((double)t/2);
    pq.push(a);
    pq.push(bb);
    
    t=pq.top(); pq.pop();
    a=ceil((double)t/2),bb=floor((double)t/2);
    pq.push(a);
    pq.push(bb);
    cout<<pq.top();


    // if(cnt) v.push_back(cnt);
    // sort(v.begin()+1,v.end());

    // for(int i=2;i<=v.size()-1;i++){
    //     b[i]=v[i]-v[1];
    //     sum+=b[i];
    // }
    // if(sum>=2){
    //     cout<<v[1]<<endl;
    // }
    // if(sum==1){
    //     cout<<v[1]-1<<endl;
    // }
    // if(sum==0){
    //     cout<<v[1]-2<<endl;
    // }



    return 0;
}

