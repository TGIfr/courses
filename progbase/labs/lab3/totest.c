//
// Created by tgifr on 03.12.16.
//
#include "totest.h"
#include "dino.h"
#include "saves.h"
void test(){
    struct dino * arr = readFile("blah");
    assert(!writeFromStr(arr, "blah"));
    assert(!writeFromStr(arr, "blah 2 5 8 "));
    assert(!writeFromStr(arr, "blah 5 45 45 "));
    assert(!writeFromStr(arr, ""));
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i].age = 1;
    }
    assert(writeFromStr(arr, "blah"));

    struct dino din = {"vasya", 10, 10, &din, 0};
    struct dino din2 = {"vasya2", 150, 150, &din, 4};
    assert(!strcmp(writeInStr(&din2), "vasya2 150 150.000 0\n"));
    assert(strcmp(writeInStr(&din2), "vasygdshgkdsfghlkdhgsaa2 150 150.000 0\n"));
    assert(!strcmp(writeInStr(&din), "vasya 10 10.000 0\n"));
    assert(strcmp(writeInStr(&din), "vasya2 150 150.000 0\n"));
    din.friend = &din2;
    assert(!strcmp(writeInStr(&din), "vasya 10 10.000 4\n"));


    assert(writeFromText("vasya 10 10.000 4\n")[0].age == 10);
    assert(writeFromText("vasya 10 10.000 4\n")[2].age == 0);
    assert(writeFromText("vasya 10 10.000 4\n")[0].mass == 10.000);
    assert(writeFromText("vasya 10 10.000 4\n")[9].number == 9);
    assert(writeFromText("vasya 1550 10.000 4\n")[0].age == 1550);

    delete(arr, 1);
    delete(arr, 1);
    delete(arr, 2);
    delete(arr, 3);
    delete(arr, 6);
    assert(arr[1].age == 0);
    assert(arr[1].age == 0);
    assert(arr[2].age != 1);
    assert(arr[3].mass != 1);
    assert(arr[6].age == 0);

    assert(din.age == 10);
    changeField(&din, "age", "20", arr);
    assert(din.age == 20);
    changeField(&din, "name", "vas", arr);
    assert(!strcmp(din.name, "vas"));
    changeField(&din, "mass", "30.45", arr);
    assert(din.mass == 30.45);
    changeField(&din, "friend", "5", arr);
    assert(din.friend == &arr[5]);
    changeField(&din, "age", "20", arr);
    assert(din.age == 20);

    free(arr);


}
