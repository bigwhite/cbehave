/*
 * calculator_test.c
 */

#include "cbehave.h"

extern int add(int a, int b);
extern int subtract(int a, int b);
extern int multiply(int a, int b);
extern int divide(int a, int b);

FEATURE(1, "Addition")
    SCENARIO("Add two numbers")

        GIVEN("two numbers (a 11) and (b 12)")
            int a = 11;
            int b = 12;
            int r = 0;
        GIVEN_END

        WHEN("we invoke add function")
            r = add(a, b);
        WHEN_END

        THEN("We should get the result 23")
            SHOULD_INT_EQUAL(r, 23);
            SHOULD_BE_TRUE(r == 23);
        THEN_END

    SCENARIO_END
FEATURE_END

FEATURE(2, "Subtraction")
    SCENARIO("Subtract between two numbers")

        GIVEN("two pair of numbers (a 11), (b 12) and "
                "(c 13), (d 11)")
            int a = 11;
            int b = 12;
            int c = 13;
            int d = 11;
        GIVEN_END

        WHEN("we invoke sub function")

        WHEN_END

        THEN("We should get the result -1 and 2")
            SHOULD_INT_EQUAL(subtract(a, b), -1);
            SHOULD_INT_EQUAL(subtract(c, d), 2);
        THEN_END

    SCENARIO_END
FEATURE_END

FEATURE(3, "Divide")
    SCENARIO("Divide between two numbers")
        GIVEN("two numbers (a 12), (b 6)")
            int a = 12;
            int b = 6;
        GIVEN_END

        WHEN("we invoke divide function")

        WHEN_END

        THEN("We should get the result 2")
            SHOULD_INT_EQUAL(divide(a, b), 2);
        THEN_END

    SCENARIO_END

    SCENARIO("0 as the dividend")
        GIVEN("two numbers (a 0), (b 12)")
            int a = 0;
            int b = 12;
        GIVEN_END

        WHEN("we invoke divide function")

        WHEN_END

        THEN("We should get the result 0")
            SHOULD_INT_EQUAL(divide(a, b), 0);
        THEN_END

    SCENARIO_END
FEATURE_END

int main() {
    cbehave_feature calculator_features[] = {
        {feature_idx(1)},
        {feature_idx(2)},
        {feature_idx(3)},
    };

    return cbehave_runner("Calculator Features are as belows:", calculator_features);
}
