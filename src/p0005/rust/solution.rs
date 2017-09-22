use std::cmp::min;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let (texts, n) = (s.as_bytes(), 2 * s.len());
        let asymmetric = |center, radius| {
            center < radius || center + radius > n || (center % 2 != radius % 2
                && texts[(center - radius) / 2] != texts[(center + radius) / 2])
        };
        let (mut pre_center, mut pre_radius) = (0, 0);
        let (mut max_center, mut max_radius) = (0, 0);
        let mut p = vec![0; n];
        for i in 1 .. n {
            let distance = i - pre_center; if distance <= pre_radius {
                p[i] = min(p[pre_center - distance], pre_radius - distance);
            }
            let (cur_center, cur_radius) = (i, &mut p[i]);
            while !asymmetric(cur_center, *cur_radius + 1) {
                *cur_radius += 1;
            }
            if pre_center + pre_radius < cur_center + *cur_radius {
                pre_center = cur_center; pre_radius = *cur_radius;
            }
            if max_radius < pre_radius {
                max_center = pre_center; max_radius = pre_radius;
            }
        }
        s[(max_center-max_radius)/2 .. (max_center+max_radius)/2].to_string()
    }
}
