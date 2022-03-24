#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=10;
int v[maxn],now[maxn];
int n;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1;i<=3;i++){
        cin>>v[i]>>now[i];
    }
    for(int i=0;i<100;i++){
        if(i%3==0){
            now[2]+=now[1];
            if(now[2]>v[2]) now[1]=now[2]-v[2],now[2]=v[2];
            else now[1]=0;
        }
        else if(i%3==1){
            now[3]+=now[2];
            if(now[3]>v[3]) now[2]=now[3]-v[3],now[3]=v[3];
            else now[2]=0;
        }
        else if(i%3==2){
            now[1]+=now[3];
            if(now[1]>v[1]) now[3]=now[1]-v[1],now[1]=v[1];
            else now[3]=0;
        }
    }
    for(int i=1;i<=3;i++){
        cout<<now[i]<<endl;
    }
    

    return 0;
}
