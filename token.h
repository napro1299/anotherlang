#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOK_IDENT = 0,
    TOK_NUMBER,
    TOK_STRING,

    TOK_PLUS,
    TOK_MINUS,
    TOK_MUL,
    TOK_DIV,
    TOK_MOD,
    TOK_AND,
    TOK_OR,
    TOK_XOR,
    TOK_BITNOT,
    TOK_ASSIGN_PLUS,
    TOK_ASSIGN_MINUS,
    TOK_ASSIGN_MUL,
    TOK_ASSIGN_DIV,
    TOK_ASSIGN_MOD,
    TOK_ASSIGN_AND,
    TOK_ASSIGN_OR,
    TOK_ASSIGN_XOR,
    TOK_ASSIGN_BITNOT,

    TOK_LEFT_PAREN,
    TOK_RIGHT_PAREN,
    TOK_LEFT_BRACKET,
    TOK_RIGHT_BRACKET,
    TOK_LEFT_BRACE,
    TOK_RIGHT_BRACE,

    TOK_DOT,
    TOK_COMMA,
    TOK_COLON,
    TOK_SEMICOLON,
    TOK_QUESTION_MARK,
    TOK_BANG,

    TOK_ASSIGN,
    TOK_EQUALS,
    TOK_NOT_EQUALS,
    TOK_GREATER,
    TOK_LESS,
    TOK_GREATER_EQ,
    TOK_LESS_EQ,

    // Keywords
    TOK_FUNC,
    TOK_IMPORT,
    TOK_IF,
    TOK_IF_ELSE,
    TOK_ELSE,
    TOK_FOR,
    TOK_WHILE,
    TOK_LOOP,
    TOK_CONTINUE,
    TOK_BREAK,
    TOK_BLOB,

    TOK_UNKNOWN,
} lTokType;

typedef struct {
    lTokType type;
    char *slice;
    size_t size;
} lTok;

lTok ltok_unknown();

lTok ltok_new(lTokType type, char *slice, size_t size);
lTok ltok_new_type(lTokType type);

#endif