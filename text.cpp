#include <cstdio>
#include <queue>
#include <cmath> 
#include <cstring>
using namespace std;
const int N = 240, M = N << 1;
struct E {
    int v, next;
} e[M];
int n, m, t, len, root, u, v, dep[N], f[N][17], h[N];
void add(int u, int v) {
    e[++len].v = v; e[len].next = h[u]; h[u] = len;
}
void bfs() {
    queue<int> q;
    q.push(root);
    dep[root] = 1, dep[0] = 0; //超出了的都是0 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = h[u]; j; j = e[j].next) {
            int v = e[j].v;
            if (dep[v]) continue;
            dep[v] = dep[u] + 1; //层数增加
            q.push(v);
            //求解f数组
            f[v][0] = u; //跳2^0就是u 
            for (int k = 1; k <= t; k++) f[v][k] = f[f[v][k - 1]][k - 1];
        }
    }
}
int lca(int x, int y) {
    //1.使x和y在同一层 相差的层数肯定能通过logn次得到 
    if (dep[y] > dep[x]) swap(x, y); 
    for (int i = t; i >= 0; i--) {
        //若跳到f[x][i]这个点 深度还是大于等于y, 那么代表可以跳 
        if (dep[f[x][i]] >= dep[y]) x = f[x][i]; 
    }
    if (x == y) return x; //同一层时 发现y就是祖先
    //2.跳到最近祖先的下一层
    for (int i = t; i >= 0; i--) {
        //若跳到某层的点不相同代表可以跳到这层 相等的话就是祖先，不能跳这层 
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    } 
}
int main() {
    scanf("%d", &n);
    t = int(log(n)/log(2)) + 1;//能跳的最高层数 
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &u, &v);
        if (v == -1) root = u;
        else add(u, v), add(v, u); 
    }
    bfs(); //初始化dep 和 fa数组 
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        int ans = lca(u, v);
        if (ans == u) printf("1\n");
        else if (ans == v) printf("2\n");
        else printf("0\n");
    }
    return 0;
}
