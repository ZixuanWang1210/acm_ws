#include<bits/stdc++.h>
using namespace std;

string s1, s2, ans;
int op, n;

int main(){
    cin >> n; 
    cin >> s1;
    while(n--){
        cin >> op;
        if(op == 1){
            cin >> s2;
            s1 += s2;
            s2 = "";
            cout << s1 << endl;
        }
        else if(op == 2){
            int a, b; cin >> a >> b;
            for(int i = a; i < a + b; i++){
                if(i == s1.length()) break;
                s2 += s1[i];
            }
            s1 = s2;
            s2 = "";
            cout << s1 << endl;
        }
        else if(op == 3){
            int a;
            cin >> a >> s2;
            s1.insert(a, s2);
            s2 = "";
            cout << s1 << endl;
        }
        else{
            cin >> s2;
            if(s1.find(s2) == s1.npos) cout << -1 << endl;
            else cout << s1.find(s2) << endl;
            s2 = "";
        }
    } 

    return 0;
}