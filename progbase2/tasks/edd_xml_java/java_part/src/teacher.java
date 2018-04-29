/**
 * Created by tgifr on 18.03.17.
 */
public class teacher {

    public String name;
    public int age;
    public float score;
    public book[] books = new book[10];
    teacher(){
        for (int i = 0; i < 10; i++){
            books[i] = new book();
        }
    }

    public  void print(){
        System.out.println("Name: " + this.name + " Age: " + this.age + " Score: " + this.score);
        for (book book : books) {
            System.out.println("Name: " + book.name + " Rating: " + book.rating);
        }

    }
}
