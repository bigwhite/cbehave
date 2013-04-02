/*
 * string_test.c
 */

#include <stdio.h>
#include <errno.h>
#include "cbehave.h"

FEATURE(1, "strstr")
    SCENARIO("The strstr finds the first occurrence of the substring in the source string")

        GIVEN("A source string: Lionel Messi is a great football player")
            char *str = "Lionel Messi is a great football player";
        GIVEN_END

        WHEN("we use strstr to find the first occurrence of [football]")
            char *p = strstr(str, "football");
            
        WHEN_END

        THEN("We should get the string: [football player]")
            SHOULD_STR_EQUAL(p, "football player");
            
        THEN_END

    SCENARIO_END

    SCENARIO("If strstr could not find the first occurrence of the substring, it will return NULL")

        GIVEN("A source string: FC Barcelona is a great football club.")
            char *str = "FC Barcelona is a great football club";
        GIVEN_END

        WHEN("we use strstr to find the first occurrence of [AC Milan]")
            char *p = strstr(str, "AC Milan");
        WHEN_END

        THEN("We should get no string but a NULL")
            SHOULD_STR_EQUAL(p, NULL);
        THEN_END
    SCENARIO_END

FEATURE_END

int main() {
    cbehave_feature strstr_features[] = {
        {feature_idx(1)},
    };

    return cbehave_runner("Strstr Features are as belows:", strstr_features);
}
