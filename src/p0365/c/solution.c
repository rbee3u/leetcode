static int gcd(int n, int m) {
    if (m == 0) {
        return n;
    } else {
        return gcd(m, n%m);
    }
}

bool canMeasureWater(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) {
        return false;
    }

    int t; if (x < y) {
        t = x; x = y; y = t;
    }

    if (x == 0) {
        return z == 0;
    }

    return (z%gcd(x, y) == 0) && (z <= x+y);
}

