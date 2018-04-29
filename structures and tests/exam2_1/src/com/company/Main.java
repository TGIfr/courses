package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<Character> list1 = new ArrayList<Character>();
        ArrayList<Character> list2 = new ArrayList<Character>();

        assert list1.equals(list2);
        System.out.println("TEST 1");
        System.out.println(list1);
        DoubleArrayListData(list1);
        System.out.println(list1);

        assert list1.equals(list2);

        list1.add('a');
        list2.add('a');
        list2.add('a');

        assert !list1.equals(list2);

        System.out.println("TEST 2");
        System.out.println(list1);
        DoubleArrayListData(list1);
        System.out.println(list1);

        assert list1.equals(list2);

        list1.clear();
        list1.add('a');
        list1.add('b');
        list1.add('c');
        list1.add('c');
        list1.add('d');

        list2.add('b');
        list2.add('b');
        list2.add('c');
        list2.add('c');
        list2.add('c');
        list2.add('c');
        list2.add('d');
        list2.add('d');
        assert !list1.equals(list2);

        System.out.println("TEST 3");
        System.out.println(list1);

        DoubleArrayListData(list1);
        assert list1.equals(list2);

        System.out.println(list1);


    }

    public static void DoubleArrayListData(ArrayList list){
        for(int i = list.size() - 1; i >= 0; i --){
            Object toDouble = list.get(i);
            list.add(i, toDouble);
        }
    }
}
