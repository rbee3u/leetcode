/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int x;
        do {
            x = (rand7() - 1) * 7 + rand7();
        } while (x < 4 || x >= 44);
        return x / 4;
    }
}
