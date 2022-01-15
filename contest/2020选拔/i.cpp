#include<bits/stdc++.h>
using namespace std;

int a, b, t;
long long ans;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        for(int i = 1; i <= b; i++){
            ans *= a;
        }
        s = to_string(ans);
        cout << s[0] << " " << s[s.length()] << endl;
    }

    return 0;
}