#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s;
vector<string> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    getline(cin,s);
    getline(cin,s);
    stringstream ssin(s);
    string word;
    while(ssin>>word){
        v.push_back(word);
    }

    for(auto x:v){
        int len=0;
        len+=x.length();
        if(len>k){
            cout<<endl;
            len=0;
        }
        cout<<x<<' ';
    }
    

    return 0;
}
