public class BinarySearch {

    public static void main(String[] args) {
        int a[] = new int[]{1, 2, 3};
        int res = binarySearch(3, a);
        System.out.println(res);

        System.out.println(ranks(2, a));
    }

    public static int binarySearch(int key, int[] a) {
        int index = 0;
        int last = a.length - 1;
        while (index <= last) {
            int mid = index + (last - index) / 2;
            if (key < a[mid]) {
                last = mid - 1;
            }
            if (key > a[mid]) {
                index = mid + 1;
            } else
                return mid;
        }
        return -1;
    }

    /**
     * 递归
     */
    public static int ranks(int key, int[] a) {
        return rank(key, a, 0, a.length - 1);
    }

    public static int rank(int key, int[] a, int lo, int hi) {
        if (lo > hi)
            return -1;
        int mid = lo + (lo + hi) / 2;
        if (key < a[mid])
            return rank(key, a, lo, mid - 1);
        if (key > a[mid]) {
            return rank(key, a, mid - 1, hi);
        } else
            return mid;
    }


}
