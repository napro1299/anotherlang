#include <stddef.h>

#include "token.h"

inline lTok ltok_unknown() {
    return (lTok) {
        .type = TOK_UNKNOWN,
        .slice = NULL,
        .size = 0,
    };
}

inline lTok ltok_new(lTokType type, char *slice, size_t size) {
    return (lTok) {
        .type = type,
        .slice = slice,
        .size = size
    };
}

inline lTok ltok_new_type(lTokType type) {
    return ltok_new(type, NULL, 0);
}