#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        string s; cin>>s;
        int h, m; scanf("%d:%d", &h, &m);

        if(n >= 18){
            puts("Yes");
            continue;
        }
        else{
            if(s=="Fri" || s=="Sat" || s== "Sun"){
                if((h == 20){
                    puts("Yes");
                    continue;
                }
                else{
                    puts("No");
                    continue;
                }
            }
            else{
                puts("No");
                continue;
            }
        }
    }
   

    return 0;
}
