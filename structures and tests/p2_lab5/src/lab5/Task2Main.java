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
        for( Student st : studs){
            dict.put(st.getkey(), st);
        }
        System.out.println("add all\n\n");
        dict.printTree();
        dict.printDictionary();

        System.out.println(" remove by variant\n\n");
        dict.removeByVariant();
        dict.printTree();
        dict.printDictionary();


    }

}

