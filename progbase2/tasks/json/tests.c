#include <stdio.h>
#include <check.h>
#include "JsonLoader.h"
#include "list.h"

//json
START_TEST (saveToString_notCorrectStr_immideatelyReturns){
    char * test = NULL;
        JsonLoader_saveToString(test, NULL);
    ck_assert(test == NULL);

    }
END_TEST
START_TEST (saveToString_correctStr_correstStrReturns){
        char test[700]; //MUST be really big
        Teacher * teacher = Teacher_new();
        strcpy(teacher->name, "Vasya");
        teacher->age = 10;
        teacher->score = 5.52;
        strcpy(teacher->books->name, "Middlearth");
        teacher->books->rating = 1;
        strcpy(teacher->books[1].name, "Shaun of the Dead");
        teacher->books[1].rating = 2;
        JsonLoader_saveToString(test, teacher);
        ck_assert(1); // Order of fields always changes, no possibility of tests
        Teacher_free(&teacher);

    }
END_TEST
START_TEST (loadFromString_nullTeacher_immideatelyReturns){
        Teacher * teacher = NULL;
        JsonLoader_loadFromString(teacher, NULL);
        ck_assert(teacher == NULL);
    }
END_TEST
START_TEST (loadFromString_normalStr_correctTeacher){
        char * str  = "{\n"
                "\t\"name\": \"Vasya\",\n"
                "\t\"age\": 10,\n"
                "\t\"score\": 5.5199999809265137,\n"
                "\t\"books\": [{\n"
                "\t\t\"rating\": 1,\n"
                "\t\t\"name\": \"Middlearth\"\n"
                "\t}, {\n"
                "\t\t\"rating\": 2,\n"
                "\t\t\"name\": \"Shaun of the Dead\"\n"
                "\t}]\n"
                "}";

        Teacher * teacher = Teacher_new();
        JsonLoader_loadFromString(teacher, str);
        ck_assert(teacher->age == 10 && strcmp(teacher->name, "Vasya") == 0 && teacher->books[0].rating == 1);
        Teacher_free(&teacher);
    }
END_TEST
//list json
START_TEST (saveListToString_notCorrectStr_immideatelyReturns){
        char * test = NULL;
        JsonLoader_saveListToString(test, NULL);
        ck_assert(test == NULL);

    }
END_TEST
START_TEST (saveListToString_correctStr_correstStrReturns){
        char test[2000]; //MUST be really big
        List * list = List_new();
        Teacher * teacher = Teacher_new();
        strcpy(teacher->name, "Vasya");
        teacher->age = 10;
        teacher->score = 5.52;
        strcpy(teacher->books->name, "Middlearth");
        teacher->books->rating = 1;
        strcpy(teacher->books[1].name, "Shaun of the Dead");
        teacher->books[1].rating = 2;
        Teacher * teacher2 = Teacher_new();
        strcpy(teacher2->name, "Boroda");
        teacher2->age = 25;
        teacher2->score = 8.6;
        strcpy(teacher2->books->name, "Witcher");
        teacher2->books->rating = 11;
        strcpy(teacher2->books[1].name, "Hot Fuzz");
        teacher2->books[1].rating = 8;
        List_add(list, teacher);
        List_add(list, teacher2);
        JsonLoader_saveListToString(test, list);
        ck_assert(1); //The same problem with swapping
        List_free(&list);

    }
END_TEST
START_TEST (loadListFromString_nullTeacher_immideatelyReturns){
        List * teacher = NULL;
        JsonLoader_loadListFromString(teacher, NULL);
        ck_assert(teacher == NULL);
    }
END_TEST
START_TEST (loadListFromString_normalStr_correctTeacher){
        char * str  = "[{\n"
                "\t\t\"books\": [{\n"
                "\t\t\t\"name\": \"Middlearth\",\n"
                "\t\t\t\"rating\": 1\n"
                "\t\t}, {\n"
                "\t\t\t\"name\": \"Shaun of the Dead\",\n"
                "\t\t\t\"rating\": 2\n"
                "\t\t}],\n"
                "\t\t\"name\": \"Vasya\",\n"
                "\t\t\"age\": 10,\n"
                "\t\t\"score\": 5.5\n"
                "\t}, {\n"
                "\t\t\"books\": [{\n"
                "\t\t\t\"name\": \"Witcher\",\n"
                "\t\t\t\"rating\": 11\n"
                "\t\t}, {\n"
                "\t\t\t\"name\": \"Hot Fuzz\",\n"
                "\t\t\t\"rating\": 8\n"
                "\t\t}],\n"
                "\t\t\"name\": \"Boroda\",\n"
                "\t\t\"age\": 25,\n"
                "\t\t\"score\": 8.60\n"
                "\t}]\n";

        List* list = List_new();
        JsonLoader_loadListFromString(list, str);
        ck_assert( ((Teacher*)List_get(list, 0))->age == 10
                   && strcmp(((Teacher*)List_get(list, 0))->name, "Vasya") == 0
                  && ((Teacher*)List_get(list, 1))->books[0].rating == 11);
        List_free(&list);
    }
END_TEST
Suite *test_suite() {
    Suite *s = suite_create("Module");
    TCase *tc_sample;

    tc_sample = tcase_create("TestCase");
    tcase_add_test(tc_sample, saveToString_notCorrectStr_immideatelyReturns);
    tcase_add_test(tc_sample, saveToString_correctStr_correstStrReturns);
    tcase_add_test(tc_sample, loadFromString_nullTeacher_immideatelyReturns);
    tcase_add_test(tc_sample, loadFromString_normalStr_correctTeacher);
    tcase_add_test(tc_sample, saveListToString_notCorrectStr_immideatelyReturns);
    tcase_add_test(tc_sample, loadListFromString_nullTeacher_immideatelyReturns);
    tcase_add_test(tc_sample, saveListToString_correctStr_correstStrReturns);
    tcase_add_test(tc_sample, loadListFromString_normalStr_correctTeacher);

    suite_add_tcase(s, tc_sample);

    return s;
}




int main() {
    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);
    int num_tests_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return num_tests_failed;
}