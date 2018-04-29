package lab5;

import java.io.File;
import java.util.List;

public class Task2Main {
    // name of file which stores data about students
    private static String fileName = "students2.csv";

    // path to the current directory that contains directory "data"
    private static String currenDir = System.getProperty("user.dir")
            + File.separatorChar + "data";

    public static void main(String[] args) {
        //remove by variant
        StudentReader reader = new StudentReader(fileName, currenDir);

        List<Student> studs = reader.read();
        StudentDictionary<Student> dict = new BSTree<>();
        System.out.println("TEST 1");

        dict.printTree();
        dict.printTreeLevel(0);

        for( Student st : studs){
            dict.put(st.getkey(), st);
        }
        System.out.println("TEST 2");

        System.out.println("add all\n\n");
        dict.printTree();

        dict.printTreeLevel(0);
        dict.printTreeLevel(1);
        dict.printTreeLevel(2);
        dict.printTreeLevel(3);
        dict.printTreeLevel(4);
        dict.printTreeLevel(5);
        dict.printTreeLevel(6);
        dict.printTreeLevel(7);

//        System.out.println("TEST 3\n\n");
//        dict.removeByVariant();
//
//        dict.printTree();
//
//        dict.printTreeLevel(0);
//        dict.printTreeLevel(1);
//        dict.printTreeLevel(2);
//        dict.printTreeLevel(5);
//        dict.printTreeLevel(6);


    }

}

