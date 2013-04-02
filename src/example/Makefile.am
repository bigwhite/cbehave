# Makefile.am

noinst_PROGRAMS = calculator_test text_editor_test string_test product_database_test mock_test

calculator_test_SOURCES = calculator_test.c calculator.c
calculator_test_LDADD = $(top_srcdir)/src/libcbehave.la

text_editor_test_SOURCES = text_editor_test.c
text_editor_test_LDADD = $(top_srcdir)/src/libcbehave.la

string_test_SOURCES = string_test.c
string_test_LDADD = $(top_srcdir)/src/libcbehave.la

product_database_test_SOURCES = product_database_test.c product_database.c database.h
product_database_test_LDADD = $(top_srcdir)/src/libcbehave.la

mock_test_SOURCES = mock_test.c
mock_test_LDADD = $(top_srcdir)/src/libcbehave.la

