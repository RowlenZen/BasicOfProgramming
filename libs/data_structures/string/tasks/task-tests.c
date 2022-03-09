#include <stdio.h>
#include "../string_.h"
#include "./tasks.c"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ ,__FUNCTION__ ,__LINE__)

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "Exception file: %s\n", fileName);
        fprintf(stderr, "Function: %s - line: %d\n", funcName, line);
        fprintf(stderr, "Got: \"%s\"\n", got);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
    } else
        fprintf(stderr, "%s - OK!\n", funcName);
}

void test_removeAdjacentEqualLetters_multipleSameChars() {
    char a[15] = "aaaabbbbcggg";
    removeAdjacentEqualLetters(a);
    ASSERT_STRING("abcg", a);
}

void test_removeAdjacentEqualLetters_emptyStr() {
    char a[15] = "";
    removeAdjacentEqualLetters(a);
    ASSERT_STRING("", a);
}

void test_removeAdjacentEqualLetters_twoSpaces() {
    char a[15] = "  ";
    removeAdjacentEqualLetters(a);
    ASSERT_STRING(" ", a);
}

void test_digitToEndRevers() {
    char a[15] = "54af 31da";
    digitToEndRevers(a);
    ASSERT_STRING("af45 da13", a);
}

void test_getWord() {
    char a[15] = "54af 31da";
    WordDescriptor wordDescriptor;
    getWord(a, &wordDescriptor);
    char b[15] = {0};
    copy(wordDescriptor.begin, wordDescriptor.end, b);
    ASSERT_STRING("54af", b);
}

void test_getWordReverse() {
    char a[15] = "54af 31da";
    WordDescriptor wordDescriptor;
    getWordReverse(a + 9, a, &wordDescriptor);
    char b[15] = {0};
    copy(wordDescriptor.begin, wordDescriptor.end, b);
    ASSERT_STRING("31da", b);
}

void test_replaceEachDigitBySpaces() {
    char a[15] = "a1bb2";
    replaceEachDigitBySpaces(a);
    ASSERT_STRING("a bb  ", a);
}

void test_string_tasks() {
    test_removeAdjacentEqualLetters_multipleSameChars();
    test_removeAdjacentEqualLetters_emptyStr();
    test_removeAdjacentEqualLetters_twoSpaces();
    test_digitToEndRevers();
    test_getWord();
    test_getWordReverse();
    test_replaceEachDigitBySpaces();
}