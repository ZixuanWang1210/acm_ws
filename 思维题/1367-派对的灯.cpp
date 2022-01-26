#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int a[8][7]=
{0,0,0,0,0,0,0,
1, 0,0,1,1,1,0,
2, 0,1,0,1,0,1,
3, 0,1,1,0,1,1,
4, 1,0,0,1,0,0,
5, 1,0,1,0,1,0,
6, 1,1,0,0,0,1,
7, 1,1,1,1,1,1};

int n,c;
vector<int> v;
int st[110];
int cnt;

bool pd(int i){
    bool falg=true;
    for(int j=1;j<=6;j++){
        if(st[j]==-1)continue;
        if(st[j]!=a[i][j]){
            falg=false;
            break;
        }
    }
    if(falg){
        cnt++;
        for(int j=1,cnt=1;cnt<=n;j++,cnt++){
            cout<<a[i][j];
            if(j==6) j=0;
        }
        cout << endl;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>c;
    
    int t;
    memset(st,-1,sizeof st);
    while(cin>>t,t!=-1){
        // if(t!=6)    
        t%=6;
        if(t==0)t=6;
        st[t]=1;
    }

    while(cin>>t,t!=-1){
        // if(t!=6)
        t%=6;
        if(t==0)t=6;
        st[t]=0;
    }

    if(c==0){
        pd(7);
        if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
    }
    
    else if(c==1){
        pd(0);pd(2);pd(3);pd(5);
        if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
    }

    else if(c==2){
        pd(0);pd(1);pd(2);pd(4);pd(5);pd(6);pd(7);
        if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
    }

    else{
        for(int i=0;i<8;i++) pd(i);
        if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
