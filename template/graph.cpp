#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

struct graph {
    vector<int> e, h, w, ne;
    int n, idx;
    graph(int n) : e(2 * n + 1), h(n + 1), w(2 * n + 1), ne(2 * n + 1) {
        for (int i = 0; i < 2 * n + 1; i++) {
            e[i] = w[i] = ne[i] = 0;
            if (i <= n) h[i] = -1;
        }
    }
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    

    return 0;
}
