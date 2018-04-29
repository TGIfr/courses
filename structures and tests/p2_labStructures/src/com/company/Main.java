package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println("#1");
        List list = new SinglyLinkedList();
        System.out.println("List before operations");
        list.print();
        System.out.println("List after operations");
        Queue q = deleteUnevenElements(list);
        list.print();
        System.out.println("Queue after operations");
        q.print();

        System.out.println("#2");
        List list2 = new SinglyLinkedList();
        list2.add(Integer.toBinaryString(12));
        System.out.println("List2 before operations");
        list2.print();
        System.out.println("List2 after operations");
        Queue q2 = deleteUnevenElements(list2);
        list2.print();
        System.out.println("Queue2 after operations");
        q2.print();

        System.out.println("#3");
        List list3 = new SinglyLinkedList();
        list3.add(Integer.toBinaryString(11));
        list3.add(Integer.toBinaryString(13));
        System.out.println("List3 before operations");
        list3.print();
        System.out.println("List3 after operations");
        Queue q3 = deleteUnevenElements(list3);
        list3.print();
        System.out.println("Queue3 after operations");
        q3.print();

        System.out.println("#4");
        List list4 = new SinglyLinkedList();
        list4.add(Integer.toBinaryString(12));
        list4.add(Integer.toBinaryString(11));
        list4.add(Integer.toBinaryString(0));
        list4.add(Integer.toBinaryString(26));
        list4.add(Integer.toBinaryString(101));
        list4.add(Integer.toBinaryString(458484));
        list4.add(Integer.toBinaryString(87848845));
        list4.add(Integer.toBinaryString(4));
        list4.add(Integer.toBinaryString(-5));

        System.out.println("List4 before operations");
        list4.print();
        System.out.println("List4 after operations");
        Queue q4 = deleteUnevenElements(list4);
        list4.print();
        System.out.println("Queue4 after operations");
        q4.print();

    }
    public static Queue deleteUnevenElements(List list){
        Queue q = new ArrayQueue();
        /*int i = 0;
        String cur;
        while((cur = list.get(i)) != null){
            String lastChar = cur.substring((cur.length() - 1));
            if(lastChar.equals("1")){
                list.remove(i);
                i--;
            } else {
                q.enqueue(Integer.parseUnsignedInt(cur, 2));
            }
            i++;
        }*/
        for (int i = 0; i < list.size(); i ++){
            String cur = list.get(i);
            String lastChar = cur.substring((cur.length() - 1));
            if(lastChar.equals("1")){
                list.remove(i);
                i--;
            } else {
                q.enqueue(Integer.parseInt(cur, 2));
            }
        }
        return q;
    }
}
