package com.company;

/**
 * Created by TGIfr on 12.02.2018.
 */

import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import org.junit.jupiter.api.Test;
//import  junit.framework.Assert;
//import static org.junit.jupiter.api.Assertions.assertThrows;
//import org.junit.Test;
//

//
//import static org.junit.Assert. *;
public class MatrixTest {

    @Test
    public void constructorBySizeTest(){
        Matrix m = new Matrix(1, 1);
        assertTrue(Arrays.deepEquals(m.getArray(), new double[1][1]));
    }

    @Test
    public void constructorByArrTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertTrue(Arrays.deepEquals(m.getArray(), arr));

    }
    @Test
    public void nullConstructorByArrExceptionTest(){
        assertThrows(NullPointerException.class, () -> new Matrix(null));
    }

    @Test
    public void zeroSizeConstructorExceptionTest(){
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> new Matrix(0, -1));
        assertEquals("This size is not allowed", exception.getMessage());
    }

    @Test
    public void constructorExceptionTest() {
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8}};
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> {new Matrix(arr);});
        assertEquals("Not equal row length", exception.getMessage());
    }


    @Test
    public void normalMatrixToStringTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertTrue(m.toString().equals("1.0 2.0 3.0 \n4.0 5.0 6.0 \n7.0 8.0 9.0 \n"));

    }

    @Test
    public void zeroMatrixToStringTest(){
        Matrix m = new Matrix(0, 0);
        assertEquals("Zero matrix\n", m.toString());
    }

    @Test
    public void notSameDimensionMatrixPlusExceptionTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        double [][] arr2 = {{1, 2, 3, 0}, {4, 5, 6, 0}, {7, 8, 9, 0}};
        Matrix m2 = new Matrix(arr2);
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> m.plus(m2));
        assertEquals("Matrices must have same dimensions", exception.getMessage());
    }
    @Test
    public void normalMatrixPlusTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        double [][] arr2 = {{1, 2, 3}, {4, 5, 6}, {-7, -8, 0}};
        double [][] awaitedRes = {{2, 4, 6},{8, 10, 12},{0, 0,9}};
        Matrix m2 = new Matrix(arr2);
        assertTrue(Arrays.deepEquals( m.plus(m2).getArray(), awaitedRes));
    }
    @Test
    public void zeroMatrixPlusTest(){
        Matrix m = new Matrix(0, 0);
        Matrix m2 = new Matrix(0, 0);
        assertEquals(m.plus(m2), new Matrix(0, 0));
    }

    @Test
    public void nullMatrixPlusExceptionTest(){
        Matrix m = new Matrix(0, 0);
        assertThrows(NullPointerException.class, () ->m.plus(null));
    }


    @Test
    public void matrixMultiplyTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        double [][] awaitedRes = {{2, 4, 6},{8, 10, 12},{14, 16,18}};
        assertTrue(Arrays.deepEquals( m.multiply(2).getArray(), awaitedRes));
    }

    @Test
    public void byZeroMatrixMultiplyTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        double [][] awaitedRes = {{0,0,0},{0,0,0},{0,0,0}};
        assertTrue(Arrays.deepEquals( m.multiply(0).getArray(), awaitedRes));
    }

    @Test
    public void zeroMatrixMultTest(){
        Matrix m = new Matrix(0, 0);
        int k = 25;
        assertEquals(m.multiply(k), new Matrix(0, 0));
    }

    @Test
    public void equalsSelfCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertTrue(m.equals(m));
    }

    @Test
    public void equalsNullCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertFalse(m.equals(null));
    }

    @Test
    public void equalsClassCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertFalse(m.equals(5));
    }

    @Test
    public void equalsNormalCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        Matrix m2 = new Matrix(arr);
        assertTrue(m.equals(m2));
    }

    @Test
    public void notSameDimensionMatrixDetTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}};
        Matrix m = new Matrix(arr);

        Throwable exception = assertThrows(IllegalArgumentException.class, () ->  m.det());
        assertEquals("Matrix must have same dimensions", exception.getMessage());

    }

    @Test
    public void normalMatrixDetTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {1, 2, 3}};
        Matrix m = new Matrix(arr);
        assertTrue( 0 == m.det());

        double [][] arr2 = {{1, 2, 3}, {4, 5, 6}, {8, 8, 9}};
        Matrix m2 = new Matrix(arr2);
        assertTrue( -3 == m2.det());
    }

    @Test
    public void zeroMatrixDetTest(){
        Matrix m = new Matrix(0, 0);
        double expected = 0;
        assertEquals(expected, m.det(), 0.0001);
    }

    @Test
    public void specialTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {1, 2, 3}};
        Matrix m = new Matrix(arr);
        double [][] arr2 = {{1, 2, 3}, {4, 5, 6}, {8, 8, 9}};
        Matrix m2 = new Matrix(arr2);
        int k = 2;

        int expectedRes = -54;

        assertTrue(m.special(m2, k) == expectedRes);
        assertFalse(m2.special(m, k) == expectedRes);
    }

    @Test
    public void nullMatrixSpecialExceptionTest(){
        Matrix m = new Matrix(0, 0);
        assertThrows(NullPointerException.class, () ->m.special(null, 0));
    }

}
