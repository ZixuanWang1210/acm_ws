#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +10;

int n, m;
int p[maxn], siz[maxn];

bool is_primer(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        if(!is_primer(i)){
            siz[i] = -1;
            p[i] = i;
            continue;
        }
        p[i] = i;
        siz[i] = 1;
    }

    while(m--){
        string op; cin >> op;
        int a, b;

        if(op == "Z"){
            cin >> a >> b;
            if(!is_primer(a) || !is_primer(b)) continue;

            a = find(a), b = find(b);
    
            p[a] = b;
            siz[b] += siz[a];
        }

        else if(op == "D"){
            cin >> a >> b;
            if(!is_primer(a) || !is_primer(b)) cout << "No" << endl;
            if(find(a) == find(b)) cout << "Yeah" << endl;
            else cout << "No" << endl;
        }
        else if(op == "Y"){
            cin >> a;
            if(!is_primer(a)) continue;
            else cout << siz[find(a)] << endl;

        }
    }

    return 0;
}