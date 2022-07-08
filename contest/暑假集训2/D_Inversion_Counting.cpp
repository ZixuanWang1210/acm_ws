#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define LL long long
#define int long long

using namespace std;

const int maxn=3e5+10;
int tmp[maxn],q[maxn];
int n;

LL merge_sort(int l, int r){
    if(l>=r) return 0;
    LL s=0;

    int mid=l+r>>1;
    s=merge_sort(l, mid)+merge_sort(mid+1, r);

    int i=l, j=mid+1, k=0;
    while(i<=mid && j<=r){
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else {
            s+= mid-i+1;
            tmp[k++]=q[j++];
        }
    }
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];

    for(int i=l, k=0;i<=r;i++, k++) q[i]=tmp[k];
    return s;
}
int cnt[maxn];
int m;

void sol(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    // for(int i=0;i<n;i++){
    //     cnt[i]=merge_sort(0,i);
    // }
    int al=merge_sort(0,n-1);
    // cout<<al<<endl;
    al=al&1;
    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        
        // int yuanlai=cnt[r]-cnt[l-1];
        int ccc=r-l+1;
        ccc=ccc*(ccc-1)/2;
        if(ccc&1){
            al^=1;
            if(al==1) cout<<"odd"<<endl;
            else cout<<"even"<<endl;
        }
        else{
            if(al==1) cout<<"odd"<<endl;
            else cout<<"even"<<endl;
        }
        // yuanlai=ccc-yuanlai;
        // if((al-yuanlai+ccc)&1){
        //     cout<<"odd"<<endl;
        // }
        // else cout<<"even"<<endl;
        // if(yuanlai&1==al&1){
        //     if(yuanlai&1) cout<<"odd"<<endl;
        //     else cout<<"even"<<endl;
        // }
        // else{
        //     if(yuanlai&1==0) cout<<"odd"<<endl;
        //     else cout<<"even"<<endl;
        // }
    }


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
