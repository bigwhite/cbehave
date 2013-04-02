/*
 * mock_test.c
 *
 * The test aims to show the usage of MOCKs macros
 */

#include <stdio.h>
#include <errno.h>
#include "cbehave.h"

int foo(int inparameter, int *outparameter) {
    (*outparameter) = (int)CBEHAVE_MOCK_ARG();
    return (int)CBEHAVE_MOCK_RETV();
}

int bar_invoke_foo_once(int *outparameter) {
    int i = 10;
    int ret = foo(5, &i);
    (*outparameter) = i;
    return ret;
}

int bar_invoke_foo_multi_times(int *outparameter) {
    int i, j, k;
    int r1, r2, r3;

    r1 = foo(5, &i);

    r2 = foo(5, &j);

    r3 = foo(5, &k);

    (*outparameter) = i + j + k;
    return r1 + r2 + r3;
}


FEATURE(1, "CBehave mock macros test")
    SCENARIO("Invoke bar_invoke_foo_once, within which foo would be invoked only once")
        int i;
        int ret;

        GIVEN("A function named foo, of which return value is 7, outparameter is 5")
            CBEHAVE_RETV_RETURN(foo, 7);
            CBEHAVE_ARG_RETURN(foo, 5);
        GIVEN_END

        WHEN("we call bar_invoke_foo_once")
            ret = bar_invoke_foo_once(&i);
        WHEN_END

        THEN("Bar_invoke_foo_once should return 7 and its outparameter should be 5!")
            SHOULD_INT_EQUAL(ret, 7);
            SHOULD_INT_EQUAL(i, 5);
        THEN_END

        GIVEN("A function named foo, of which return value is 13, outparameter is 17")
            CBEHAVE_RETV_RETURN(foo, 13);
            CBEHAVE_ARG_RETURN(foo, 17);
        GIVEN_END

        WHEN("we call bar_invoke_foo_once")
            ret = bar_invoke_foo_once(&i);
        WHEN_END

        THEN("Bar_invoke_foo_once should return 13 and its outparameter should be 17!")
            SHOULD_INT_EQUAL(ret, 13);
            SHOULD_INT_EQUAL(i, 17);
        THEN_END

    SCENARIO_END


    SCENARIO("Invoke bar_invoke_foo_multi_times")
        int i;
        int ret;

        GIVEN("A function named foo, we set its return value and out parameter by xx_RETURN_COUNT(with count is 3)")
            CBEHAVE_RETV_RETURN_COUNT(foo, 13, 3);
            CBEHAVE_ARG_RETURN_COUNT(foo, 17, 3);
        GIVEN_END

        WHEN("we call bar_invoke_foo_multi_times")
            ret = bar_invoke_foo_multi_times(&i);
        WHEN_END

        THEN("Bar_invoke_foo_multi_times should return 39 and its outparameter should be 51!")
            SHOULD_INT_EQUAL(ret, 39);
            SHOULD_INT_EQUAL(i, 51);
        THEN_END

    SCENARIO_END

    SCENARIO("Invoke bar_invoke_foo_multi_times and bar_invoke_foo_once mixedly")
        int i;
        int ret;

        GIVEN("A function named foo, we set its return value and out parameter by xx_RETURN_COUNT(with count is -1)")
            CBEHAVE_RETV_RETURN_COUNT(foo, 13, -1);
            CBEHAVE_ARG_RETURN_COUNT(foo, 17, -1);
        GIVEN_END

        WHEN("we call bar_invoke_foo_once")
            ret = bar_invoke_foo_once(&i);
        WHEN_END

        THEN("Bar_invoke_foo_once should return 13 and its outparameter should be 17!")
            SHOULD_INT_EQUAL(ret, 13);
            SHOULD_INT_EQUAL(i, 17);
        THEN_END

        WHEN("we call bar_invoke_foo_multi_times")
            ret = bar_invoke_foo_multi_times(&i);
        WHEN_END

        THEN("Bar_invoke_foo_multi_times should return 39 and its outparameter should be 51!")
            SHOULD_INT_EQUAL(ret, 39);
            SHOULD_INT_EQUAL(i, 51);
        THEN_END

    SCENARIO_END
FEATURE_END

int main() {
    cbehave_feature mock_test_features[] = {
        {feature_idx(1)},
    };

    return cbehave_runner("Mock test Features are as belows:", mock_test_features);
}
