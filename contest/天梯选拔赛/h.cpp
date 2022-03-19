#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
#define pii pair<int,int>

bool a[1000];
int n;
int aa[1000][1000];

pii get(int a,int b){
    pii res={a*10+b,b*10+a};
    return res;
}
void get(int x,int y,int z){
    
    int res[10];
    res[1]=x,res[2]=y,res[3]=z;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                if(i==j||i==k||j==k) continue;
                int ans=res[i]*100+res[j]*10+res[k];
                // if(ans==88){
                //     cout<<11;
                // }
                a[ans]=true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            cin>>aa[i][j];
            a[aa[i][j]]=true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k1=1;k1<=6;k1++){
                for(int k2=1;k2<=6;k2++){
                    pii res=get(aa[i][k1],aa[j][k2]);
                    a[res.first]=true;
                    a[res.second]=true;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int k1=1;k1<=6;k1++){
                    for(int k2=1;k2<=6;k2++){
                        for(int k3=1;k3<=6;k3++){
                            get(aa[i][k1],aa[j][k2],aa[k][k3]);
                        }
                    }
                }
            }
        }
    }
    int re=0;
    for(int i=1;i<100;i++){
        if(a[i]) re=i;
        else break;
    }
    if(re==0) cout<<0<<endl;
    else cout<<re<<endl;
    return 0;
}
