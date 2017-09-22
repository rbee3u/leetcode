impl Solution {
    const SD: &'static [&'static str] = &["", "M", "MM", "MMM"];
    const SC: &'static [&'static str] = &["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    const SX: &'static [&'static str] = &["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    const SI: &'static [&'static str] = &["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
    pub fn int_to_roman(i: i32) -> String {
        let mut result = String::new();
        let i = i as usize;
        result.push_str(Self::SD[i / 1000]);
        result.push_str(Self::SC[i % 1000 / 100]);
        result.push_str(Self::SX[i % 100 / 10]);
        result.push_str(Self::SI[i % 10]);
        return result
    }
}
