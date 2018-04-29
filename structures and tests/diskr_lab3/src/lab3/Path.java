package lab3;

/**
 * Created by Dell on 13.05.2017.
 */

public class Path {
    public Element[] elemArray;
    public int size;
    public int count = 0;

    public Path(int size){
        //конструктор класса, хранящий отрезки пути
        this.size = size;
        elemArray = new Element[size];
    }

    public void add(Element elem){
        //добавление в массив отрезков
        elemArray[count++] = elem;
    }

    public boolean checkForEquality(int a, int b) {
        //проверка, нет ли уже в массиве отрезков такого отрезка
        for (int i = 0; i < count; i++) {
            if ((elemArray[i].a == a && elemArray[i].b == b)
                    || (elemArray[i].a == b && elemArray[i].b == a)) {
                return true;
            }
        }
        return false;
    }

    public void printElems() {
        //вывод элементов пути
        for (int i = 0; i < count; i++) {
            System.out.format("%d - %d\n",elemArray[i].a + 1,elemArray[i].b + 1);
        }
    }

    public String getPath(int[][] matrix){
        //получить путь поэлементно
        int cur = 0;
        String res = new String();
        res += Integer.toString(cur + 1) + " - ";
        for (int i = 0; i < count; i++){
            for (int j = 0; j<count; j++){
                if (elemArray[j].a == cur){
                    cur = elemArray[j].b;
                    if (i != count - 1){
                        res += Integer.toString(cur + 1) + " - ";
                    }
                    else res += Integer.toString(cur + 1);
                    break;
                }
            }
        }
        return res;
    }

    public int getLength(int[][] matrix){
        //получить длину пути
        int cur = 0;
        int len = 0;
        for (int i = 0; i < count; i++){
            for (int j = 0; j<count; j++){
                if (elemArray[j].a == cur){
                    len += matrix[cur][elemArray[j].b];
                    cur = elemArray[j].b;
                    break;
                }
            }
        }
        return len;
    }




}
