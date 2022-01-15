#include<bits/stdc++.h>
using namespace std;

int n;
string s;
char ans[1000];
int x, y;

int main(){
    cin >> n;
    char st;
    while(n--){
        cin >> s;
        if(isalpha(s[0])){
            cin >> x >> y;
            st = s[0];   
        }
        else{
            x = stoi(s);
            cin >> y;
        }
        if(st == 'a'){
            sprintf(ans, "%d+%d=%d", x, y, x + y);
        }
        else if(st == 'c'){
            sprintf(ans, "%d*%d=%d", x, y, x * y);
        }
        else if(st == 'b'){
            sprintf(ans, "%d-%d=%d", x, y, x - y);
        }
        cout << ans << endl << strlen(ans) << endl;
    }

    return 0;
}