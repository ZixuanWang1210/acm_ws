#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

unordered_map<string, int> age, ord = {{"Ox", 0}, {"Tiger",  1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
string s[8];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    age["Bessie"]=0;
    int n; cin>>n;
    while(n--){
        for(int i=0;i<8;i++){
            cin>>s[i];
        }

        if(s[3]=="previous"){
            int x=age[s[7]],y=ord[s[4]];
            int r=((x-y)%12+12)%12;
            if(!r) r=12;
            age[s[0]]=x-r;
        }
        else{
            int x=age[s[7]],y=ord[s[4]];
            int r=((y-x)%12+12)%12;
            if(!r) r=12;
            age[s[0]]=x+r;
        }
    }
    cout<<abs(age["Elsie"])<<endl;
    return 0;
}
