int fib_pos(int p) {
    int l = 1;
    int a = 1;
    int b = 1;
    int d = 10;
    int c;
    if (p <= 0) return -1;
    if (p <= 2) return 1;
    p -= 2;
    while (1) {
        c = a + b;
        a = b;
        b = c;
        while (c > d) {
            d *= 10;
            l += 1;
        }
        p -= l;
        if (p <= 0) {
            if (p < 0)
                p += l;
            for (; c; c /= 10) {
                if (p == 0) return c % 10;
                p -= 1;
            }
            return -1;
        }
    }
    return -1;
}
