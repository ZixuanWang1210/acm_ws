PDD p[N];
int stk[N], top;
bool used[N];
//used数组表示这个点是否已经在底边上了，如果在了，就不用考虑把他放在顶边上了。
//注意在我们在求顶的时候，要把used[0]变成false
//因为我们求的闭包长度 【首是0 末是0 闭环】

//重载加减  叉积
PDD operator+(PDD a,PDD b){
    return {a.x+b.x,a.y+b.y};
}
PDD operator-(PDD a,PDD b){
    return {a.x - b.x,a.y-b.y};
}
double operator*(PDD a,PDD b){
    return a.x*b.y - a.y*b.x;
}

//判断顺时针还是逆时针 有向面积
double area(PDD a, PDD b, PDD c) {
    return (b - a) * (c - a);
}

double dis(PDD a, PDD b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}


//Andrew算法
double getConvex() {
    // pair 默认对first升序，当first相同时对second升序；
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        while (top >= 2 && area(p[stk[top - 1]], p[stk[top]], p[i]) <= 0) {
            if (area(p[stk[top - 1]], p[stk[top]], p[i]) < 0) { //不共线直接删掉
                used[stk[top--]] = false;
            } else {
                top--;//共线删掉，但不要置false因为在底边上
            }
        }
        stk[++top] = i;//加入当前栈
        used[i] = true;//置true
    }

    used[0] = false;//第一个点置false
    for (int i = n - 1; i >= 0; i--) {
        if (used[i]) continue;
        while (top >= 2 && area(p[stk[top - 1]], p[stk[top]], p[i]) <= 0) {
            top--;
        }
        stk[++top] = i;
    }

    double res = 0;
    for (int i = 0; i < top; i++) {
        res += dis(p[stk[i]], p[stk[i + 1]]);
    }

    return res;
}
