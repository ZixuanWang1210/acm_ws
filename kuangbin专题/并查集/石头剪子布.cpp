#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>

#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int maxn = 2100;
int p[maxn];
int dis[maxn];
int n, m;

struct node {
    int a, b, type;
} ask[maxn];

int find(int x) {
    if (x == p[x]) return x;
    int root = find(p[x]);
    dis[x] += dis[p[x]];
    dis[x] %= 3;
    return p[x] = root;
}

bool merge(int x, int y, int op) {
    int px = find(x), py = find(y);
    if (px == py) {
        int t = (dis[y] - dis[x] + op) % 3;
        if (t) return false;
    } else {
        p[px] = py;
        dis[px] = dis[y] - dis[x] + op;
        dis[py] %= 3;
        return true;
    }
    return true;
}

void sol() {
    for (int i = 0; i < m; i++) {
        int a, b;
        char op;
        scanf("%d%c%d", &a, &op, &b);
        if (op == '<')
            ask[i] = {a, b, -1};
        else if (op == '>')
            ask[i] = {a, b, 1};
        else
            ask[i] = {a, b, 0};
    }
    int cnt = 0, who = -1, t = 0;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) p[j] = j, dis[j] = 0;
        for (int j = 0; j < m; j++) {
            // 如果有裁判参与则去掉
            if (ask[j].a == i || ask[j].b == i) continue;
            if (!merge(ask[j].a, ask[j].b, ask[j].type)) flag = 0, t = max(t, j);
            if (!flag) break;
        }
        if (flag) cnt++, who = i;
    }
    if (cnt > 1)
        cout << "Can not determine" << endl;
    else if (cnt == 0)
        cout << "Impossible" << endl;
    else
        printf("Player %d can be determined to be the judge after %d lines\n", who, t + (t != 0));
}

signed main() {
    while (cin >> n >> m) {
        sol();
    }

    return 0;
}
