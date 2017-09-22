var sd = [...]string{"", "M", "MM", "MMM"}
var sc = [...]string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
var sx = [...]string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
var si = [...]string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}

func intToRoman(i int) string {
	return sd[i/1000] + sc[i%1000/100] + sx[i%100/10] + si[i%10]
}
