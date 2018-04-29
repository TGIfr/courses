import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) {
        MxLangEnvironment env = new MxLangEnvironment();
        Scanner reader = new Scanner(System.in);
        System.out.println("Enter 'exit' to cancel");
        Pattern exitPattern = Pattern.compile("exit", Pattern.CASE_INSENSITIVE);
        while (true) {
            String line = reader.nextLine();
            if (exitPattern.matcher(line).matches()) {
                break;
            }
            System.out.println(env.exec(line));
        }
    }
}

