#include <stdio.h>
#include <check.h>
#include "XmlLoader.h"
#include "list.h"

//Xml
START_TEST (saveToString_notCorrectStr_immideatelyReturns){
    char * test = NULL;
    XmlLoader_saveToString(test, NULL);
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
        XmlLoader_saveToString(test, teacher);
        ck_assert_str_eq(test ,  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                "<teachers>\n"
                "  <teacher>\n"
                "    <name>Vasya</name>\n"
                "    <age>10</age>\n"
                "    <score>5.520000</score>\n"
                "    <book name=\"Middlearth\">\n"
                "      <rating>1</rating>\n"
                "    </book>\n"
                "    <book name=\"Shaun of the Dead\">\n"
                "      <rating>2</rating>\n"
                "    </book>\n"
                "  </teacher>\n"
                "</teachers>\n");
        Teacher_free(&teacher);

    }
END_TEST
START_TEST (loadFromString_nullTeacher_immideatelyReturns){
        Teacher * teacher = NULL;
        XmlLoader_loadFromString(teacher, NULL);
        ck_assert(teacher == NULL);
    }
END_TEST
START_TEST (loadFromString_normalStr_correctTeacher){
        char * str = "<teachers>\n"
                "  <teacher>\n"
                "    <name>Vasya</name>\n"
                "    <age>10</age>\n"
                "    <score>5.520000</score>\n"
                "    <book name=\"Middlearth\">\n"
                "      <rating>1</rating>\n"
                "    </book>\n"
                "    <book name=\"Shaun of the Dead\">\n"
                "      <rating>2</rating>\n"
                "    </book>\n"
                "  </teacher>\n"
                "</teachers>\n";

        Teacher * teacher = Teacher_new();
        XmlLoader_loadFromString(teacher, str);
        char test[700] ;
        ck_assert(teacher->age == 10 && strcmp(teacher->name, "Vasya") == 0 && teacher->books[0].rating == 1);
        Teacher_free(&teacher);
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