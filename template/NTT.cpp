namespace NTT {
const long long g = 3;
const long long p = 998244353;
long long wn[35];
long long pow2(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void getwn() {
    for (int i = 0; i < 25; i++) wn[i] = pow2(g, (p - 1) / (1LL << i));
}
void ntt(long long *a, int len, int f) {
    long long i, j = 0, t, k, w, id;
    for (i = 1; i < len - 1; i++) {
        for (t = len; j ^= t >>= 1, ~j & t;)
            ;
        if (i < j) std::swap(a[i], a[j]);
    }
    for (i = 1, id = 1; i < len; i <<= 1, id++) {
        t = i << 1;
        for (j = 0; j < len; j += t) {
            for (k = 0, w = 1; k < i; k++, w = w * wn[id] % p) {
                long long x = a[j + k], y = w * a[j + k + i] % p;
                a[j + k] = (x + y) % p;
                a[j + k + i] = (x - y + p) % p;
            }
        }
    }
    if (f) {
        for (i = 1, j = len - 1; i < j; i++, j--) swap(a[i], a[j]);
        long long inv = pow2(len, p - 2);
        for (i = 0; i < len; i++) a[i] = a[i] * inv % p;
    }
}
void mul(long long *a, long long *b, int l1, int l2) {
    int len, i;
    for (len = 1; len <= l1 + l2; len <<= 1)
        ;
    for (i = l1 + 1; i <= len; i++) a[i] = 0;
    for (i = l2 + 1; i <= len; i++) b[i] = 0;
    ntt(a, len, 0);
    ntt(b, len, 0);
    for (i = 0; i < len; i++) a[i] = a[i] * b[i] % p;
    ntt(a, len, 1);
}
};   // namespace NTT