/**
 *
 * 最大公约数
 */
public class Gcd {

    public static void main(String[] args) {
        int gcd = gcd(2,4);
        System.out.println(gcd);
    }

    public static int gcd(int p, int q) {
        if (q == 0)
            return p;
        int r = p % q;
        return gcd(q,r);
    }
}
