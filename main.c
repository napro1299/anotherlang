#include <stdio.h>
#include <string.h>

#include "lex.h"

int main(void) {
    const char *str = "123.123";
    lLex *lex = llex_new(str, strlen(str), 2);
    // lTok tok1 = llex_get_ident_tok(lex);
    lTok tok2 = llex_get_number_tok(lex);

    // printf("%d\n", tok1.size);
    printf("%d\n", tok2.size);
}