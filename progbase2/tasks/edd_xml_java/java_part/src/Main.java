import com.thoughtworks.xstream.XStream;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.*;

import static java.nio.file.StandardWatchEventKinds.ENTRY_CREATE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_DELETE;
import static java.nio.file.StandardWatchEventKinds.ENTRY_MODIFY;

//! XStream has problem with reading names of books(atribite)
public class Main {
    public static final String CONFIG = "configuration.xml";
    public static void main(String[] args) {

        root filepath = readPathXML();
        System.out.println("root found on: " + filepath.path);
        teacher tch = readTeacherXML(filepath.path);
        tch.print();
        try {
            //Paths.get("E:/Test/Download");
            WatchService watcher = FileSystems.getDefault().newWatchService();
            Path dirConfig = FileSystems.getDefault().getPath(System.getProperty("user.dir"));

            dirConfig.register(watcher, ENTRY_CREATE, ENTRY_DELETE, ENTRY_MODIFY);


            System.out.println("Watch Config Service registered for dir: " + dirConfig.getFileName());



            while (true) {
                WatchKey key;
                try {
                    key = watcher.take();
                } catch (InterruptedException ex) {
                    return;
                }

                for (WatchEvent<?> event : key.pollEvents()) {
                    WatchEvent.Kind<?> kind = event.kind();

                    @SuppressWarnings("unchecked")
                    WatchEvent<Path> ev = (WatchEvent<Path>) event;
                    Path fileNameConfig = ev.context();

                    System.out.println(kind.name() + ": " + fileNameConfig);

                    if (kind == ENTRY_MODIFY &&
                            fileNameConfig.toString().equals(CONFIG)) {
                        System.out.println(CONFIG + "has changed!!!");
                        filepath = readPathXML();
                        System.out.println("root found on: " + filepath.path);
                        tch = readTeacherXML(filepath.path);
                        tch.print();
                    }
                    if (kind == ENTRY_MODIFY &&
                            filepath.path.contains(fileNameConfig.toString())) {
                        System.out.println(fileNameConfig.toString() + "has changed!!!");
                        tch = readTeacherXML(filepath.path);
                        tch.print();
                    }
                }

                boolean valid = key.reset();
                if (!valid) {
                    break;
                }
            }

        } catch (IOException ex) {
            System.err.println(ex);
        }

    }

    public static String readFile(String filename){
        String result = "";

        // This will reference one line at a time
        String line = null;

        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(filename);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                result += line;
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            filename + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + filename + "'");
            // Or we could just do this:
            // ex.printStackTrace();
        }
        return result;
    }
    public static root readPathXML(){
        String rawXml = readFile(CONFIG);
        XStream xstream = new XStream();
        root path;
        path = (root)xstream.fromXML(rawXml);
        return path;
    }
    public static teacher readTeacherXML(String filename){
        String rawXml = readFile(filename);
        XStream xstream = new XStream();
        teacher tch = (teacher)xstream.fromXML(rawXml);
        return tch;
    }
}
