#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;

int main(){
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        char s[5]; scanf("%s", s);
        int h, m; scanf("%d:%d", &h, &m);

        if(n >= 18){
            puts("Yes");
            continue;
        }
        else{
            if(strcmp(s, "Fri") || strcmp(s, "Sat") || strcmp(s, "Sun")){
                if(h >= 20 && h <= 21){
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
