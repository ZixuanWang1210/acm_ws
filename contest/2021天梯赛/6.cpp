#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s[50];
    cin>>n>>m;
    string t1="qiandao",t2="easy";
    vector<int> v;
    getline(cin,t1);
    for(int i=1;i<=n;i++){
        getline(cin,s[i]);
        if(s[i].find("qiandao")!=s[i].npos||s[i].find("easy")!=s[i].npos){
        }
        else{
            v.push_back(i);
        }
    }
    if(m>=v.size()||m>n){
        cout<<"Wo AK le"<<endl;
    }
    else{
        cout<<s[v[m]]<<endl;
    }
    

    return 0;
}
