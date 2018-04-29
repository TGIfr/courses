package com.company;

import java.util.Arrays;

/**
 * Created by TGIfr on 11.02.2018.
 */
public class Matrix {
    private double[][] arr;
    private int m, n;

    public Matrix(int m, int n) {
        if(m < 0 || n < 0) {
            throw new IllegalArgumentException("This size is not allowed");
        }
        this.m = m;
        this.n = n;
        arr = new double[m][n];
    }

    public Matrix(double[][] arr) {
        if(arr == null){
            throw new NullPointerException();
        }
        m = arr.length;
        n = arr[0].length;
        for (int i = 0; i < m; i++) {
            if (arr[i].length != n) {
                throw new IllegalArgumentException("Not equal row length");
            }
        }
        this.arr = arr;
    }

    public double[][] getArray () {
        return arr;
    }

    public Matrix plus (Matrix B) {
        if(B == null){
            throw new NullPointerException();
        }

        if (B.m != m || B.n != n) {
            throw new IllegalArgumentException("Matrices must have same dimensions");
        }

        Matrix res = new Matrix(m,n);
        double[][] resArray = res.getArray();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                resArray[i][j] = arr[i][j] + B.arr[i][j];
            }
        }
        return res;
    }

    public double special(Matrix B, double k){
        if(arr == null){
            throw new NullPointerException();
        }
        return this.plus(B.multiply(k)).det();
    }

    public Matrix multiply (double k) {
        Matrix res = new Matrix(m,n);
        double[][] C = res.getArray();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = k * arr[i][j];
            }
        }
        return res;
    }

    public String toString(){
        String res = "";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res += String.format("%s", arr[i][j]) + " ";
            }
            res += "\n";
        }
        if(res.equals(""))
            res = "Zero matrix\n";
        return res;
    }

    public boolean equals(Object o) {
        // self check
        if (this == o)
            return true;
        // null check
        if (o == null)
            return false;
        // type check and cast
        if (getClass() != o.getClass())
            return false;

        return (Arrays.deepEquals(arr, ((Matrix)o).getArray()));
    }

    public double det(){
        if (m != n) {
            throw new IllegalArgumentException("Matrix must have same dimensions");
        }
        return matrixDeterminant(arr);
    }

    private double matrixDeterminant (double[][] matrix) {
        double temporary[][];
        double result = 0;

        if(matrix.length == 0)
        {
            return 0;
        }
        if (matrix.length == 1) {
            result = matrix[0][0];
            return (result);
        }

        if (matrix.length == 2) {
            result = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
            return (result);
        }

        for (int i = 0; i < matrix[0].length; i++) {
            temporary = new double[matrix.length - 1][matrix[0].length - 1];

            for (int j = 1; j < matrix.length; j++) {
                for (int k = 0; k < matrix[0].length; k++) {
                    if (k < i) {
                        temporary[j - 1][k] = matrix[j][k];
                    } else if (k > i) {
                        temporary[j - 1][k - 1] = matrix[j][k];
                    }
                }
            }

            result += matrix[0][i] * Math.pow (-1, (double) i) * matrixDeterminant (temporary);
        }
        return (result);
    }
}
