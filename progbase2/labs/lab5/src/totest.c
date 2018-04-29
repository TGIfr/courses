//
// Created by tgifr on 03.12.16.
//
#include <check.h>
#include "../include/totest.h"
#include "../include/dino.h"
#include "../include/saves.h"
#include "../include/list.h"

START_TEST (createList_void_eqMAXSIZE){
    struct List * list1 = createDinoList();
    ck_assert( List_count(list1) == MAX_SIZE);
    List_free(&list1);
}
END_TEST

START_TEST (initializeList_void_eqNULL){
    struct List * list1 = createDinoList();
    initializeList(list1);
    ck_assert(List_elementAt(list1, 1) != NULL);
    List_free(&list1);
}
END_TEST

START_TEST (writeInStr_dino_eqZeroStr){
    struct List * list1 = createDinoList();
    initializeList(list1);
    char * tempStr = writeInStr(List_elementAt(list1, 0));
    ck_assert(!strcmp(tempStr, " 0 0.000 0\n"));
    List_free(&list1);
    free(tempStr);
}
END_TEST

START_TEST (writeFromStr_str_eqEnteredStr) {
    struct List * list1 = createDinoList();
    initializeList(list1);
    ck_assert(writeFromStr(list1, "Vasya 15 25 3") == 0);
        List_free(&list1);

}
END_TEST

START_TEST (writeFromStr_strUncorrect_AgeEqZero) {
    struct List * list1 = createDinoList();
    initializeList(list1);
    writeFromStr(list1, "Vasya a5 5 3");
    ck_assert(List_elementAt(list1, 0)->age == 0);
        List_free(&list1);
}
END_TEST

START_TEST (writeInStr_dino_eqEnteredStr){
    struct List * list1 = createDinoList();
    initializeList(list1);
    writeFromStr(list1, "Vasya 15 25 3");
    char * tempStr = writeInStr(List_elementAt(list1, 0));
    ck_assert(!strcmp(tempStr, "Vasya 15 25.000 3\n"));
    free(tempStr);
        List_free(&list1);
}
END_TEST


START_TEST (writeInStr_dinoWithUncorrectEnteredMass_MassIsZero){
    struct List * list1 = createDinoList();
    initializeList(list1);
    writeFromStr(list1, "Vasya 15 blah 3");
    char * tempStr = writeInStr(List_elementAt(list1, 0));
    ck_assert(!strcmp(tempStr, "Vasya 15 0.000 0\n"));
    free(tempStr);
        List_free(&list1);
}
END_TEST
        Suite *test_suite() {
    Suite *s = suite_create("Module");
    TCase *tc_sample;

    tc_sample = tcase_create("TestCase");
    tcase_add_test(tc_sample, createList_void_eqMAXSIZE);
    tcase_add_test(tc_sample, initializeList_void_eqNULL);
    tcase_add_test(tc_sample, writeInStr_dino_eqZeroStr);
    tcase_add_test(tc_sample, writeFromStr_str_eqEnteredStr);
    tcase_add_test(tc_sample, writeInStr_dino_eqEnteredStr);
    tcase_add_test(tc_sample, writeFromStr_strUncorrect_AgeEqZero);
    tcase_add_test(tc_sample, writeInStr_dinoWithUncorrectEnteredMass_MassIsZero);


    suite_add_tcase(s, tc_sample);

    return s;
}

void test(){

    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);


    srunner_free(sr);
    struct List * list1 = createDinoList();
    assert(List_count(list1) == MAX_SIZE);
    assert(List_elementAt(list1, 0) != NULL);
    List_elementAt(list1, 2 )->next->age = 10;
    assert(List_elementAt(list1, 3)->age == 10);

    initializeList(list1);
    assert(List_elementAt(list1, 2)->age == 0);
    assert(List_elementAt(list1, 3)->mass == 0.0);
    assert(List_elementAt(list1, 4)->friend == List_elementAt(list1, 0));
    assert(strcmp(List_elementAt(list1, 7)->name, "") == 0);



    assert(!writeFromStr(list1, "Vasya 10 15 1"));
    assert(List_elementAt(list1, 0)->age == 10);
    assert(List_elementAt(list1, 0)->mass == 15.0);
    assert(List_elementAt(list1, 0)->friend == List_elementAt(list1, 0)->next);
    assert(strcmp(List_elementAt(list1, 0)->name, "Vasya") == 0);
    char * tempStr = writeInStr(List_elementAt(list1, 0));
    assert(strcmp(tempStr, "Vasya 10 15.000 1\n") == 0);
    free(tempStr);


    rewrite(list1, 1, 0);
    assert(List_elementAt(list1, 1)->age == 10);
    assert(List_elementAt(list1, 1)->mass == 15.0);
    assert(List_elementAt(list1, 1)->friend == List_elementAt(list1, 1));
    assert(strcmp(List_elementAt(list1, 1)->name, "Vasya") == 0);
    tempStr = writeInStr(List_elementAt(list1, 1));
    assert(strcmp(tempStr, "Vasya 10 15.000 1\n") == 0);

    free(tempStr);


    List_free(&list1);
    assert(list1 == NULL);
}
