#include "caryon.h"
#include <bits/stdc++.h>
// #define 1000000000 1000000000
using namespace std;
using namespace ca;   // namespace
graph<int> example;
int main() {
    dataname = "";   // dataname
    maxtime = 1000;
    makein(6, 6) {
        csh();
        int n=cyrand(1,1000),s=cyrand(1,1000),m=cyrand(n-1,50000);
        int u=cyrand(1,n),v=cyrand(1,n);


        // n=1000;
        // m=1300;

        // inint(n),inspace();
        // inint(m),inspace();
        inint(u),inspace();
        inint(v),inspace();
        inint(s),inspace();
        inendl();
        
        int f[10000];
        for(int i=1;i<=n;i++){
            f[i]=cyrand(1,1000000000);
            inint(f[i]);
            inspace();
        }
        inendl();


        example=rand_graph(n,m,1,1000000000,cyrand);
        // if (cyrand(0, 1) > 0) {
        //     example = rand_graph(10, 10, 1, 10, cyrand);
        // } else {
        //     do {
        //         example = rand_graph(10, 10, 1, 10, cyrand);
        //     } while (!example.is_connect());
        // }
        ingraph(example);
        // Please finish these rows
    }
    makeout(1, 10);
    return 0;
}