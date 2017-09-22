/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x < 0 || y < 0 || z < 0) {
        return false;
    }
    
    if (x < y) {
        let t = x; x = y; y = t;
    }

    if (x === 0) {
        return z === 0;
    }

    let gcd = function (n, m) {
        if (m === 0) {
            return n;
        } else {
            return gcd(m, n%m)
        }
    }

    return (z%gcd(x, y) === 0) && (z <= x+y);
};

