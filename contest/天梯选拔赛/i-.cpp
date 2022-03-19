#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,string>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
vector<pii> v;
bool a[10];
int ans;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int c; string s;
        cin>>c>>s;
        v.push_back({c,s});
    }    
    sort(v.begin(),v.end());

    int cost=0;
    int now[5]={0,0,0,0,0};
    for(auto x:v){
        string ss=x.second;
        int bz=false,bz2=false;
        int now2[5]={0,0,0,0,0};
        for(int i=0;i<ss.length();i++){
            int num=ss[i]-'A';
            now2[num]=true;
            if(now[num]==0) bz=true;

        }
        if(bz){
            cost+=x.first;
            for(int i=0;i<ss.length();i++){
                int num=ss[i]-'A';
                now[num]=1;
            }
        }
        if(now==now2){
            cost=min(cost,x.first);
        }

    }
    for(int i=0;i<=3;i++){
        if(now[i]==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<cost;

    return 0;
}
