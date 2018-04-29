/**
 * Created by TGIfr on 12.02.2018.
 */

import static org.junit.jupiter.api.Assertions.*;
import org.junit.Test;

import java.util.Arrays;


public class MatrixTest {

    @Test
    public void constructorBySizeTest(){
        Matrix m = new Matrix(1, 1);
        assertEquals(m,  new Matrix( new double[1][1]));
    }

    @Test
    public void constructorByArrTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertEquals(m, new Matrix(arr));

    }
    @Test
    public void nullConstructorByArrExceptionTest(){
        assertThrows(NullPointerException.class, () -> new Matrix(null));
    }

    @Test
    public void minusSizeConstructorExceptionTest(){
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> new Matrix(0, -1));
        assertEquals("This size is not allowed", exception.getMessage());
    }

    @Test
    public void constructorExceptionTest() {
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8}};
        Throwable exception = assertThrows(IllegalArgumentException.class, () -> new Matrix(arr));
        assertEquals("Not equal row length", exception.getMessage());
    }


    @Test
    public void normalMatrixToStringTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertEquals("1.0 2.0 3.0 \n4.0 5.0 6.0 \n7.0 8.0 9.0 \n", m.toString());

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
        assertEquals( m.plus(m2), new Matrix(awaitedRes));
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
        assertEquals( m.multiply(2), new Matrix(awaitedRes));
    }

    @Test
    public void byZeroMatrixMultiplyTest(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        double [][] awaitedRes = {{0,0,0},{0,0,0},{0,0,0}};
        assertEquals(m.multiply(0), new Matrix(awaitedRes));
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
        assertEquals(m, m);
    }

    @Test
    public void equalsNullCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertNotEquals(m, null);
    }

    @Test
    public void equalsClassCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        assertNotEquals(m, 5);
    }

    @Test
    public void equalsNormalCheck(){
        double [][] arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        Matrix m = new Matrix(arr);
        Matrix m2 = new Matrix(arr);
        assertEquals(m, m2);
        assertEquals(m.getArray(), m2.getArray());
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
        assertEquals( 0, m.det());

        double [][] arr2 = {{1, 2, 3}, {4, 5, 6}, {8, 8, 9}};
        Matrix m2 = new Matrix(arr2);
        assertEquals( -3 , m2.det());
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

        assertEquals(expectedRes, m.special(m2, k));
        assertNotEquals(expectedRes, m2.special(m, k));
    }

    @Test
    public void nullMatrixSpecialExceptionTest(){
        Matrix m = new Matrix(0, 0);
        assertThrows(NullPointerException.class, () ->m.special(null, 0));
    }

}
