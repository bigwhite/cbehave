/*
 * string_test.c
 */

#include <stdio.h>
#include <errno.h>
#include "cbehave.h"
#include "database.h"

extern int get_total_count_of_employee();

/* the mock implementations of database interfaces */
database_conn *connect_to_database(const char *user,
        const char *passwd,
        const char *serviceid) {
    return (database_conn*)CBEHAVE_MOCK_RETV();
}

int table_row_count(const database_conn *conn,
        const char *table_name,
        int *total_count) {
    (*total_count) = (int)CBEHAVE_MOCK_ARG();
    return (int)CBEHAVE_MOCK_RETV();
}

FEATURE(1, "Get the total count of employees")
    SCENARIO("Get the total count of employees")
        GIVEN("The db connection is ready and there are 5 employees in total");
            CBEHAVE_RETV_RETURN(connect_to_database, 0x1234);
            CBEHAVE_ARG_RETURN(table_row_count, 5);
            CBEHAVE_RETV_RETURN(table_row_count, 0);
        GIVEN_END

        WHEN("We call get_total_count_of_employee");
            int count = get_total_count_of_employee();
            
        WHEN_END

        THEN("The total count of employees we read from db should be 5")
            SHOULD_INT_EQUAL(count, 5);
        THEN_END

    SCENARIO_END

    SCENARIO("We should get -1 from the execution when the db connection is unavailable")
        GIVEN("The db connection is unavailable")
            CBEHAVE_RETV_RETURN(connect_to_database, NULL);
        GIVEN_END

        WHEN("We call get_total_count_of_employee");
            int count = get_total_count_of_employee();
            
        WHEN_END

        THEN("We won't get the count, but -1 for the unavailable db connection")
            SHOULD_INT_EQUAL(count, -1);
        THEN_END
    SCENARIO_END

FEATURE_END

int main() {
    cbehave_feature product_db_features[] = {
        {feature_idx(1)},
    };

    return cbehave_runner("Product Database Features are as belows:", product_db_features);
}
