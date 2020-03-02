LL extgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL g = extgcd(b, a % b, x, y);
    LL nextx = y, nexty = x-(a/b)*y;
    x = nextx; y = nexty;
    return g;
}