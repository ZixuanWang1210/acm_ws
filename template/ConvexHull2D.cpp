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
