class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (stk.empty()) {
                stk.push(s.charAt(i));
            } else {
                if (isMatch(stk.peek(), s.charAt(i))) {
                    stk.pop();
                } else {
                    stk.push(s.charAt(i));
                }
            }
        }
        return stk.empty();
    }

    static boolean isMatch(char p, char q) {
        return (p == '(' && q == ')') ||
                (p == '[' && q == ']') ||
                (p == '{' && q == '}');
    }
}
