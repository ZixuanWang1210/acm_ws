#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    int now=n;
    vector<long long> v(2*n);
    long long sum=0;
    multiset<int> mst;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
        mst.insert(v[i]);
    }

    queue<long long> q;
    q.push(sum);
    while(q.size()&&--now){
        long long t=q.front();
        q.pop();

        long long _max=*max_element(mst.begin(),mst.end());
        if(_max>t){
            cout<<"No"<<endl;
            return;
        }

        if(t==1){
            continue;
        }
        long long a=ceil((double)t/2),b=floor((double)t/2);
        
        // if(a!=b){
        if(mst.count(a)>=1){
            mst.erase(lower_bound(mst.begin(),mst.end(),a));
            if(mst.size()==0){
                cout<<"YES"<<endl;
                return;
            }
        }
        else{
            q.push(a);
        }
        if(mst.count(b)>=1){
            mst.erase(lower_bound(mst.begin(),mst.end(),b));
            if(mst.size()==0){
                cout<<"YES"<<endl;
                return;
            }
        }
        else{
            q.push(b);
        }
        // }
        // else{
        //     if(mst.count(a)>=1){
        //         mst.erase(a);
        //         if(mst.size()==0){
        //             cout<<"YES"<<endl;
        //             return;
        //         }
        //     }
        //     else{
        //         q.push(a);
        //     }
        // }

    }
    if(n==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}


void solve(){
    
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        m[a[i]]++;
    }
    if(n==1) {
        cout<<"YES"<<endl;
        return;
    }
    priority_queue<int> p;
    p.push(s);
    while(p.size()<n){
        int x = p.top();
        p.pop();
        int q = x/2, w = (x+1)/2;
        if(m.count(q)){
            m[q]--;
            n--;
        }
        else{
            p.push(q);
        }
        if(m[q] == 0) m.erase(q);
        if(m.count(w)){
            m[w]--;
            n--;
        }
        else{
            p.push(w);
        }
        if(m[w] == 0) m.erase(w);
        
    }
    if(p.size() == 0){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
 
}



signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        solve();
    }
    

    return 0;
}
