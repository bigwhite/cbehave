/*
 * Copyright (c) 2005-2010 Tony Bai <bigwhite.cn@gmail.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */ 

#include <stdio.h>
#include "database.h"

int get_total_count_of_employee() {
    database_conn *conn = NULL;
    int retv = -1;
    int total_count = -1;

    conn = connect_to_database("tonybai", "tonybai", "mysql");
    if (!conn)
        return -1;

    retv = table_row_count(conn, "EMPLOYEE_TABLE", &total_count);
    if (retv < 0) 
        return -1;
    return total_count;
}

