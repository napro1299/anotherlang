#ifndef LEX_H
#define LEX_H

#include <stddef.h>

#include "token.h"

typedef struct {
    const char *data;
    size_t data_size;

    size_t pos;

    struct {
        lTok *buf;
        size_t size;
        size_t capacity;
    } toks;
} lLex;

static lLex *llex_new(const char *data, size_t size, size_t init_tokbuf_size);
static int llex_grow_toks(lLex *l, unsigned int grow_factor);
static int llex_add_tok(lLex *l, lTok tok);

static lTok llex_get_ident_tok(lLex *l);
static lTok llex_get_number_tok(lLex *l);
static lTok llex_get_string_tok(lLex *l);

void llex_lex(lLex *l);


#endif