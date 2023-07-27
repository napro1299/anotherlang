#include <stdlib.h>
#include <ctype.h>

#include "lex.h"
#include "common.h"

static char adv(lLex *l) {
    return l->data[l->pos++];
}

static char cur(lLex *l) {
    return l->data[l->pos];
}

static char peek(lLex *l) {
    return l->data[l->pos + 1];
}

static lLex *llex_new(const char *data, size_t size, size_t init_tokbuf_size) {
    lLex *lex = (lLex *) malloc(sizeof(lLex));

    lex->data = data;
    lex->data_size = size;
    lex->pos = 0;
    
    lex->toks.buf = (lTok *) malloc(sizeof(lTok) * init_tokbuf_size);
    lex->toks.capacity = init_tokbuf_size;
    lex->toks.size = 0;

    return lex;
}

static int llex_grow_toks(lLex *l, unsigned int grow_factor) {
    if (!l->toks.buf) {
        return FAIL;
    }

    l->toks.capacity *= grow_factor;
    l->toks.buf = (lTok *) realloc(l->toks.buf, sizeof(lTok) * l->toks.capacity);

    return OK;
}

static int llex_add_tok(lLex *l, lTok tok) {
    if (!l->toks.buf) {
        return FAIL;
    }

    if (l->toks.size == l->toks.capacity) {
        llex_grow_toks(l, 2);
    }

    l->toks.buf[l->toks.size] = tok;

    return OK;
}

static char is_identc(char c) {
    return isalnum(c) || c == '_';
}

static lTok llex_get_ident_tok(lLex *l) {
    size_t start = l->pos;

    while (is_identc(cur(l)))
        adv(l);

    return ltok_new(TOK_IDENT, &l->data[start], l->pos - start);
}

static lTok llex_get_number_tok(lLex *l) {
    size_t start = l->pos;

    while (isdigit(cur(l)))
        adv(l);

    if (cur(l) == '.') {
        adv(l);
        while (isdigit(cur(l)))
            adv(l);
    }

    return ltok_new(TOK_NUMBER, &l->data[start], l->pos - start);
}

static lTok llex_get_string_tok(lLex *l) {
    size_t start = l->pos;

    adv(l);
    while (cur(l) != '\"' || (cur(l) != '\\' && peek(l) != '\"'))
        adv(l);

    return ltok_new(TOK_STRING, &l->data[start], l->pos - start);
}

void llex_lex(lLex *l) {
    while (l->pos != l->data_size) {
        switch (cur(l)) {
            case '+': {
                if (peek(l) == '=') {
                    
                }
            }
        }
    }
}