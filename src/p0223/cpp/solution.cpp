class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B), area2 = (G - E) * (H - F);
        int dx = 0, dy = 0;
        if (A <= E && E <= C) dx = min(C, G) - E;
        if (E <= A && A <= G) dx = min(C, G) - A;
        if (B <= F && F <= D) dy = min(D, H) - F;
        if (F <= B && B <= H) dy = min(D, H) - B;
        return area1 + area2 - dx * dy;
    }
};
