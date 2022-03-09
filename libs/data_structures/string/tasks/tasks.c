#include <ctype.h>
#include "../string_.h"

void removeAdjacentEqualLetters(char *s) {
    if (*s == '\0')
        return;

    char *previousChar = s;
    s++;
    while (*s != '\0') {
        if (*previousChar != *s) {
            previousChar++;
            *previousChar = *s;
        }
        s++;
    }
    previousChar++;
    *previousChar = '\0';
}

void digitToEnd(WordDescriptor word) {

    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin,
                               isalpha);

    copyIfReverse(endStringBuffer - 1,
                  _stringBuffer - 1,
                  recPosition,
                  isdigit);
}

void digitToEndRevers(char *str) {

    char *beginStr = str;
    WordDescriptor word;

    while (getWord(beginStr, &word)) {
        digitToEnd(word);
        beginStr = word.end;
    }
}

void replaceEachDigitBySpaces(char *s) {

    char *strBufferEnd = copy(s, s + strlength_(s), _stringBuffer);
    char *strBufferStart = _stringBuffer;

    while (strBufferStart < strBufferEnd) {
        if (isdigit(*strBufferStart)) {
            int countSpaces = *strBufferStart - '0';
            for (int i = 0; i < countSpaces; ++i) {
                *s = ' ';
                s++;
            }
        } else {
            *s = *strBufferStart;
            s++;
        }
        strBufferStart++;
    }

    *s = '\0';
}