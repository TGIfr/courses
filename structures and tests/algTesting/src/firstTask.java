import java.util.Random;

public class firstTask {

    public static void main(String[] args) {

        int increment = 20000;

        int numSteps = 1000;

        int start = 50000;

        for (int numToCheck = start;

             numToCheck < numSteps * increment + start;

             numToCheck += increment) {

            System.out.print(numToCheck + "\t");

            int[] ar = new int[numToCheck];
            Random r = new Random();

            for (int i = 0; i < ar.length; i++) {

                ar[i] = i;

            }
            long startTime = System.nanoTime();
            int repeat = 20;
            for (int i = 0; i < repeat; i ++){
                long randomTimeStart = System.nanoTime();
                int key =  r.nextInt(numToCheck);
                long randomTimeEnd = System.nanoTime();
                startTime += randomTimeEnd - randomTimeStart;

                interpolationSearch(ar, key);
            }


            long endTime = System.nanoTime();

            double estTime = (endTime - startTime) / (1000000000.0 * repeat);

            System.out.println(estTime);
        }
    }


    private static int interpolationSearch(int[] ar, int key) {
        int mid;
        int low = 0;
        int high = ar.length - 1;

        while (low <= high) {
            mid = low + (high - low) * ((key - ar[low]) / (ar[high] - ar[low]));

            if (ar[mid] < key)
                low = mid + 1;
            else if (ar[mid] > key)
                high = mid - 1;
            else
                return mid;
        }

        return -1; // Not found
    }
}



