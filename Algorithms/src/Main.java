public class Main {
    public static void main(String[] args) {


        int[] a = new int[]{1, 2, 3};

        int[] a1 =reserveArray(a);
        for (int i = 0 ;i<a1.length;i++){
            System.out.println(a1[i]);
        }
        System.out.println("Hello world!");
    }

    public static int searchMax(int[] a) {
        int max = 0;
        for (int j : a) {
            if (max < j) {
                max = j;
            }
        }
        return max;
    }

    public static int avg(int[] a) {
        int sum = 0;
        for (int j : a) {
            sum += j;
        }
        return sum / a.length;
    }

    public static int[] reserveArray(int[] a) {
        int n = a.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        return a;
    }
}