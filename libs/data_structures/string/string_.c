#include <ctype.h>
#include <memory.h>
#include "string_.h"

size_t strlength_(char *begin) {

    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {

    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {

    while (isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {

    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {

    while (rbegin > rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {

    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {

    while (*lhs == *rhs && *lhs != '\0') {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {

    unsigned int countBytes = endSource - beginSource;
    memcpy(beginDestination, beginSource, countBytes);

    return beginDestination + countBytes;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {

    while (beginSource < endSource) {

        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {

        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

int getWord(char *beginSearch, WordDescriptor *word) {

    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {

    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend)
        return 0;

    word->begin = findSpaceReverse(word->end, rend);
    word->begin++;
    word->end++;
    return 1;
}
