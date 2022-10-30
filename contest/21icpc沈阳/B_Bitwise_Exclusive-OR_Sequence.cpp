// #include <bits/stdc++.h>
// #define endl "\n"
// #define debug(x) cout << #x << ": -----> " << x << endl;
// #define inf 0x3f3f3f3f
// #define pii pair<int,int>
// #define all(x) x.begin()+1,x.end()
// #define _all(x) x.begin(),x.end()
// #define mod 1000000007
// #define ll long long
// // #define int long long

// using namespace std;

// const int maxn=2e6+10;
// int p[maxn],d[maxn];
// void init(){
//     for(int i=0;i<2e5+10;i++) p[i]=i,d[i]=0;
// }
// int find(int x){
//     if(p[x]==x) return x;
//     int pp=find(p[x]);
//     d[x]+=d[p[x]];
//     return p[x]=pp;
// }
// int id(int x){
//     return (x%2+2)%2;
// }
// void merge(int x,int y,int v){
//     int px = find(x), py = find(y);
// 	if (px != py) {
// 		p[px]=py;
// 		d[px]=-d[x]+v+d[y];
// 	}
// }

// int a[maxn],t[maxn];
// struct node{
//     int x,y,z;
// };
// node ask[maxn];
// bool ok;

// void sol(){
//     int n,q; cin>>n>>q;
//     for(int i=1;i<=q;i++) cin>>ask[i].x>>ask[i].y>>ask[i].z;

//     for(int i=30;i>=0;i--){
//         init();

//         for(int j=1;j<=q;j++){
//             int val=(ask[j].z>>i)&1;
//             int x=ask[j].x,y=ask[j].y;
//             if(find(x)==find(y)){
//                 if(id(id(d[x])-id(d[y]))==!val) ok=true;
//             }
//             else merge(x,y,val);
//         }
//         for(int i=1;i<=n;i++) find(i);

//         if(ok){
//             cout<<-1<<endl;
//             return;
//         }
//         ok=false;


//         int cnt0=0,cnt1=0;
//         for(int j=1;j<=n;j++){
//             if(d[j]&1) cnt1++;
//             else cnt0++;
//         }
//         for(int j=1;j<=n;j++){

//             a[j]+=(1<<i)*((cnt1<cnt0&&d[j]&1)||(cnt1>cnt0&&(d[j]&1==0)));
//         }
//     }

//     long long sum=0;
//     for(int i=1;i<=n;i++) sum+=a[i];
//     cout<<sum<<endl;

// }

// signed main(){
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     int _=1;
//     // cin>>_;
//     while(_--){
//         sol();
//     }

//     return 0;
// }
// // 1 2 3      2 1
// // 2 3 1        1
// // 1 4 5    4   1
// // 4 5 2      2
// // 4 7 8  8
// // 2 6 4    4


#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;
const int  maxn=2e5+10;
vector<pii> g[maxn];
void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int ans=0;
    for(int i=0;i<30;i++){
        vector<int> vis(n+1,-1);
        for(int j=1;j<=n;j++){
            if(vis[j]!=-1) continue;
            int ans1=0,ans2=(1<<i);
            vis[j]=0;
            queue<int> q;
            q.push(j);
            while(q.size()){
                int tmp=q.front();
                q.pop();
                for(auto x:g[tmp]){
                    if(vis[x.first]==-1){
                        if(((x.second>>i)&1)==0) vis[x.first]=vis[tmp];
                        else vis[x.first]=!vis[tmp];
                        ans1+=((vis[x.first]*(1<<i)));
                        ans2+=((!vis[x.first]*(1<<i)));
                        q.push(x.first);
                    }
                    else if((vis[x.first]^vis[tmp])!=((x.second>>i)&1)){
                        cout<<-1<<endl;
                        return ;
                    }
                }
            }
            ans+=min(ans1,ans2);
        }
    }
    cout<<ans<<endl;

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
