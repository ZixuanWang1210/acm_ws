#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    // cout<<1<<endl;
    int n; cin>>n;
    multiset<int> mp;
    // map<int,int> mp;
    int sum=0;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        sum+=t;
        mp.insert(t);
        // mp[t]++;
    }

    queue<int> q;
    q.push(sum);
    if(mp.count(sum)>=1){
        mp.erase(sum);
    }
    if(mp.size()==0){
        cout<<"Yes"<<endl;
        return;
    }
    while(q.size()&&n--){
        int t=q.front(); q.pop();
        int a=ceil(t/2),b=floor((t+1)/2);
        if(t%1){
            if(mp.count(a)>=1){
                mp.erase(a);
                if(mp.size()==0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
            else{
                q.push(a);
            }

            if(mp.count(b)>=1){
                mp.erase(b);
                if(mp.size()==0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
            else{
                q.push(b);
            }
        }
        else{
            if(mp.count(a)>=1){
                mp.erase(a);
                if(mp.size()==0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
            else{
                q.push(a);
            }
        }


    }
     
    cout<<"No"<<endl;
    return;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
