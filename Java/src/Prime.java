
/**
 * 素数
 */
public class Prime {

    public static void main(String[] args) { 
        
//        System.out.println(isPrime(5)); 
        getPrime();
    }

    /**
     * 平方�?
     * 
     * @param x 
     * @return
     */
    public static boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void getPrime() {
        for (int i = 0; i < 100; i++) {
            if (isPrime(i)) {
                System.out.println(i);
            }

        }
    }

    public static double sqrt(double c) {
        if (c < 0) {
            return Double.NaN;
        }
        double err = 1e-15;
        double t = c;
        while (Math.abs(t - c / t) > err * t) {
            t = (c / t + t) / 2.0;
        }
        return t;
    }

}
