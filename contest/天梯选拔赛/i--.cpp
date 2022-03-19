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

int judge(int a[],int b[]){
    int st=0;
    bool yy=0,zj=0,xz=0;
    for(int i=0;i<=3;i++){
        if(a[i]!=b[i]) yy=false;
        if(a[i]==0&&b[i]==1) zj=true;
    }
    if(yy) st=1;
    if(zj) st=2;
    
}


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
        // int bz=false,bz2=false;
        int now2[5]={0,0,0,0,0};
        for(int i=0;i<ss.length();i++){
            int num=ss[i]-'A';
            now2[num]=true;
        }
        int st=0;
        // bool yy=0,zj=0,xz=0,bh=1,bh2=1;
        bool bz1=1,bz2=1,bz3=1;
        for(int i=0;i<=3;i++){
            // if(now[i]!=now2[i]) yy=false;
            // if(now[i]==0&&now2[i]==1) zj=true;
            // if(now[i]==1&&now2[i]==0) bh=false;
            // if(now[i]==0&&now2[i]==1) bh2=false;
            if(now[i]==1&&now2[i]==0) bz1=false;
            if(now[i]==0&&now2[i]==1) bz2=false;
            if(now[i]!=now2[i]) bz3=false;
        }

        if(bz1==true) st=2;
        if(bz2==true) st=4;
        if(bz3==true) st=1;

        // if(zj) st=2;
        // if(yy) st=1;
        // if(bh&&st!=1) st=3;
        // if(bh2&&(st!=1||st==3)) st=4;
        if(st==1){
            cost=min(cost,x.first);
        }
        if(st==2){
            cost+=x.first;
            for(int i=0;i<=3;i++){
                if(now2[i]) now[i]=true;
            }
        }
        if(st==3){
            cost=x.first;
        }
        if(st==4) continue;
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
