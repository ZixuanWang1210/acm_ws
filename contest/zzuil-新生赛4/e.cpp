#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
string t = "yuanwang";

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        string s;
        getline(cin, s);
        int len = s.length();
        bool flag = false;
        for(int i = 0; i < len; i++){
            if(s[i] == 'y'){
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if(flag = false){
            cout << "None" << endl;
        }
        
    }
    

    return 0;
}
