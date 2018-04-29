package com.company;





public abstract class Main {
    private static final int INF = (int)(Integer.MAX_VALUE / 2);

    private static void printMatrix(int[][] matrix, char zero){
        //вывести матрицу на экран
        for (int[] aMatrix : matrix) {
            for (int anAMatrix : aMatrix)
                if (anAMatrix <= -1 || anAMatrix == INF) System.out.print(" ∞ ");
                else if (anAMatrix == 0) System.out.format(" %c ", zero);
                else System.out.format("%2d ", anAMatrix);
            System.out.println("");
        }
        System.out.println("");
    }

    private static int[] getMinDistanceVector(int aMatrix[][], int start){
        //рассчитать минимальные расстояния от точки start алгоритмом Дейкстры
        int size = aMatrix.length;
        int[] res = new int[size];
        int[] visited = new int[size];
        int visitedAmount = 0;
        for (int i = 0; i<size; i++)
            res[i]=(i==start)?0:INF;
        while (visitedAmount != size){
            for (int j = 0; j<size; j++)
                if (visited[start] == 0 && aMatrix[start][j]>0)
                    if (res[start]+aMatrix[start][j] < res[j])
                        res[j]=res[start]+aMatrix[start][j];

            visited[start] = 1;
            int minIndex = -1;
            for (int i = 0; i<size; i++)
                if (visited[i] == 0 && res[i]< INF)
                    if ( minIndex == -1 || res[minIndex] > res [i]  )
                        minIndex = i;
            if (minIndex == -1) break;
            start = minIndex;
            visitedAmount++;
        }
        return res;
    }

    private static void printVector(int[] arr){
        //вывести минимальные расстояния списком
        for (int i = 0; i<arr.length; i++)
            System.out.format("M%d: %s\n",i+1,(arr[i] <= -1)?"∞ ":(arr[i]+" "));
    }
    private static void printVector(int[] arr, int[] rebuiltSequence){
        //вывести максимальные расстояния списком
        int size = arr.length;
        int[] oldSequenceArr = new int[arr.length];
        for (int i = 0; i<size; i++)
            oldSequenceArr[rebuiltSequence[i]] = arr[i];
        for (int i = 0; i<arr.length; i++)
            System.out.format("M%d: %s\n",i+1,(oldSequenceArr[i] <= -1)?"∞ ":(oldSequenceArr[i]+" "));
    }

//    private static int[][] minDistanceMatrix(int[][] matrix){
//        //получить матрицу минимальных расстояний
//        int size = matrix.length;
//        int[][] res = new int[size][size];
//        for (int i = 0; i<size; i++){
//            int row[] = getMinDistanceVector(matrix, i);
//            System.arraycopy(row, 0, res[i], 0, size);
//        }
//        return res;
//    }

//    private static int[][] maxDistanceMatrix(int[][] matrix, int[] rebuiltSequence){
//        //получить матрицу максимальных расстояний
//        int size = matrix.length;
//        int[][] res = new int[size][size];
//        for (int i = 0; i<size; i++){
//            int[] newSequence = getNewSequence(matrix);
//            int[][] triangleMatrix = getTriangleMatrix(matrix, newSequence);
//            int [] row = getMaxDistanceVector(triangleMatrix, i);
//            System.arraycopy(row, 0, res[i], 0, size);
//        }
//        int [][] oldSequenceMatrix = new int[size][size];
//        for (int i = 0; i<size; i++)
//            for (int j = 0; j<size; j++)
//                oldSequenceMatrix[rebuiltSequence[i]][rebuiltSequence[j]] = res[i][j];
//        return oldSequenceMatrix;
//    }

    private static int[] getNewSequence(int[][] matrix){
        //получить новую последовательность вершин в треугольной матрице
        int size = matrix.length;
        int[] newSequence = new int[size];
        int newSequenceIterator = 0;
        boolean[] crossed = new boolean[size];
        while (newSequenceIterator != size)
            for (int j = 0; j<size; j++){
                if (!crossed[j]){
                    boolean toCross = true;
                    for (int i = 0; i < size; i++)
                        if (matrix[i][j] > 0 && !crossed[i] && !crossed[j]) toCross = false;
                    if (toCross){
                        crossed[j] = true;
                        newSequence[newSequenceIterator++] = j;
                    }
                }
            }

        return newSequence;
    }

    private static int[][] getTriangleMatrix(int[][] matrix, int[] newSequence){
        //получить треугольную матрицу
        int size = matrix.length;
        int[][] rebuilt = new int[size][size];
        for (int i = 0; i<size; i++)
            for (int j = 0; j<size; j++)
                rebuilt[i][j] = matrix[newSequence[i]][newSequence[j]];
        return rebuilt;
    }

    private static int [] getMaxDistanceVector(int[][] matrix, int start){
        //рассчитать максимальные расстояния от точки start методом Фалкерсона
        int size = matrix.length;
        int res[] = new int[size];
        res[start] = 0;
        for (int j = 0; j<size; j++){
            if (j != start){
                int max = -INF;
                for (int i = 0; i<size; i++){
                    if (matrix[i][j] > 0){
                        max = (res[i] + matrix[i][j] > max)?(res[i] + matrix[i][j]):max;
                    }
                }
                res[j] = max;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] matrixForMinWays = {
                {0,-1,7,12,-1,10,-1},
                {-1,0,-1,-1,6,13,-1},
                {-1,5,0,4,5,6,-1},
                {-1,-1,-1,0,-1,-1,4},
                {-1,-1,-1,8,0,5,9},
                {-1,-1,-1,-1,-1,0,6},
                {-1,-1,-1,-1,-1,-1,0}
        };
        System.out.println("Input matrix:");
        printMatrix(matrixForMinWays,'-');

        int startPointOfMinDistance = 1;
        System.out.format("Minimal distances from point №%d:\n",startPointOfMinDistance);
        printVector(getMinDistanceVector(matrixForMinWays,startPointOfMinDistance-1));

        //System.out.println("\nMatrix of min distances:");

        // printMatrix(minDistanceMatrix(matrix),'0');
//        int[][] matrixForMaxWays = {
//                {0,6,11,5,-1,-1},
//                {-1,0,-1,-1,7,2},
//                {-1,5,0,-1,6,-1},
//                {-1,-1,-1,0,4,5},
//                {-1,-1,-1,-1,0,7},
//                {-1,-1,-1,-1,-1,0}
//        };
        int[] newSequence = getNewSequence(matrixForMinWays);
        int[][] triangleMatrix = getTriangleMatrix(matrixForMinWays, newSequence);
        System.out.println("Triangle matrix:");
        printMatrix(triangleMatrix,'-');

        int startPointOfMaxDistance = 1;
        System.out.format("Maximal distances from point №%d:\n",startPointOfMaxDistance);
        printVector(getMaxDistanceVector(triangleMatrix, startPointOfMaxDistance -1), newSequence);
//        System.out.println("\nMatrix of max distances:");
//        printMatrix(maxDistanceMatrix(matrix, newSequence),'0');
    }
}

