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

#ifndef _DATABASE_H_
#define _DATABASE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ID_LEN      64
#define MAX_PASSWD_LEN  64

typedef struct {
    char user[MAX_ID_LEN+1];
    char passwd[MAX_PASSWD_LEN+1];
    char serviceid[MAX_ID_LEN+1];
    int  handle;
} database_conn;

/*
 * Connect to the database using the arguments listed
 *
 * @return NULL when some error occurs
 *         non-NULL successfully
 */
database_conn *connect_to_database(const char *user,
                                const char *passwd,
                                const char *serviceid);

/*
 * Get the total count of records in some table
 *
 * @return -1 when some error occurs
 *         0  successfully
 */
int table_row_count(const database_conn *conn,
                    const char *table_name, 
                    int *total_count);


#ifdef __cplusplus
}
#endif

#endif /* _DATABASE_H_ */
