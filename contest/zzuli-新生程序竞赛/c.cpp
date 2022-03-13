#include<bits/stdc++.h>

#define pii pair<double,double>
#define int long long
using namespace std;

const int P=1000000007;

double _get(pii a,pii b){
    double dx=a.first-b.first;
    double dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

void sol(){
    int n,r; cin>>n>>r;
    vector<pii> v(2*n);
    for(int i=1;i<=n;i++){
        double x,y; cin>>x>>y;
        v[i]={x,y};
    }

    int soc=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        double x,y; cin>>x>>y;
        double len=_get(v[i],{x,y});
        if(len<0.2*r){
            cnt++;
            int ret=0;
            if(cnt<100){
                ret=300;
            }
            else if(cnt>=100&&cnt<200){
                ret=303;
            }
            else if(cnt>=100&&cnt<300){
                ret=306;
            }
            else if(cnt>=100&&cnt<400){
                ret=309;
            }
            else{
                ret=312;
            }
            soc+=ret;
        }
        else if(len<0.5*r){
            cnt++;
            int ret=0;
            if(cnt<100){
                ret=200;
            }
            else if(cnt>=100&&cnt<200){
                ret=202;
            }
            else if(cnt>=100&&cnt<300){
                ret=204;
            }
            else if(cnt>=100&&cnt<400){
                ret=206;
            }
            else{
                ret=208;
            }
            soc+=ret;
        }
        else if(len<r){
            cnt++;
            int ret=0;
            if(cnt<100){
                ret=100;
            }
            else if(cnt>=100&&cnt<200){
                ret=101;
            }
            else if(cnt>=100&&cnt<300){
                ret=102;
            }
            else if(cnt>=100&&cnt<400){
                ret=103;
            }
            else{
                ret=104;
            }
            soc+=ret;
        }
        else{
            cnt=0;
        }
    }
    cout<<soc<<endl;

}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}