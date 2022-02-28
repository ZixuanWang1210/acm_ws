#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;
int mm,yy,dd;
string s;
int mo[30]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        int s; cin>>s;
        int day; cin>>day;
        int del; cin>>del;
        yy=s/10000;
        mm=s/100-yy*100;
        dd=s-(yy*10000+mm*100);
        // cout<<yy<<' ' <<mm<<' ' <<dd<<endl;
        if(yy%4==0) mo[2]=29;
        else mo[2]=28;
        for(int i=1;i<=del;i++){
            dd++; day++;
            if(day==8) day=1;
            if(dd==mo[mm]+1){
                // cout<<mm<<' '<<mo[mm]<<endl;
                dd=1;
                mm++;
                if(mm==13) mm=1,yy++;
                if(yy%4==0) mo[2]=29;
                else mo[2]=28;
            }
        }
        cout<<yy<<setfill('0')<<setw(2)<<mm<<setw(2)<<dd<< ' '<<day<<endl;
    }

    return 0;
}
