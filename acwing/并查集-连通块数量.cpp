#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, m;
int p[maxn], siz[maxn];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        siz[i] = 1;
    }
    while(m--){
        string op; cin >> op;
        int a, b;

        if(op == "C"){
            cin >> a >> b;
            a = find(a), b = find(b);
            if(a != b){
                p[a] = b;
                siz[b] += siz[a];
            }
            // if(find(a) != find(b)){
            //     p[find(a)] = find(b);
            //     siz[find(b)] += siz[find(a)];
            // }

            // if(find(a) != find(b))
            // {p[find(a)] = find(b);
            // siz[find(b)] += siz[find(a)];}
        }
        else if(op == "Q1"){
            cin >> a >> b;
            //if(a == b) cout << "Yes" << endl;
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(op == "Q2"){
            cin >> a;
            cout << siz[find(a)] << endl;
        }
    }
    

    return 0;
}