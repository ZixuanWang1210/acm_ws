重叠不会对区间的最大值产生影响

重叠不会对区间信息产生影响

## 原理

ST表

![image-20220119191810479](https://s2.loli.net/2022/01/19/BR9azt1Iwdhie5s.png)

## 维护最大值的位置

```cpp
namespace RMQ {
    void init(int n) {
        for (int i = 1; i <= n; i++) table[i][0] = i;
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                int x = table[i][j - 1], y = table[i + (1 << (j - 1))][j - 1];
                table[i][j] = sum[x] > sum[y] ? x : y;
            }
    }
    int query(int l, int r) {
        int k = log2(r - l + 1);
        int x = table[l][k], y = table[r - (1 << k) + 1][k];
        return sum[x] > sum[y] ? x : y;
    }
}
```

