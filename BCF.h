#ifndef BCF_H
#define BCF_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BCF BCF;

struct BCF {
    enum {
        C_PROGRAM, C_LET, C_IN, C_END, C_SKIP, C_IF, C_WHILE, C_FOR, C_OR, C_NOT,
        C_DODJELA, C_READ, C_WRITE, C_SEK, C_MOD, C_LEQ, C_LESS, C_GEQ, C_GREAT, 
        C_ISEQ, C_NOTEQ, C_AND, C_IDENT, C_PLUS, C_MINUS, C_MUL, C_DIV, C_INT, 
        C_DBL, C_BOOL, C_STR
    } tip;
    union {
        int int_value;
        char* string_value;
        double double_value;
        double double_exp;
        int hex_value;
        bool bool_value;
        char* ident;

        struct {
            struct BCF* comm;
            struct BCF* decl;
        } c_program;
        struct {
            struct BCF* cvorovi[2];
        } c_sek;
        struct {
            struct BCF* init;
            struct BCF* cond;
            struct BCF* for_body;
        } c_for;
        struct {
            struct BCF* cond;
            struct BCF* branch_e;
            struct BCF* branch_t;
        } c_if;
        struct {
            struct BCF* cvor;
        } c_unarna_op;
        struct {
            struct BCF* lijevi;
            struct BCF* desni;
        } c_binarna_op;
        struct {
            struct BCF* cond;
            struct BCF* body;
        } c_while;
    };
};

BCF* napravi_program(BCF* deklaracije, BCF* komande);
BCF* napravi_let(BCF* deklaracije);
BCF* napravi_in(BCF* komande);
BCF* napravi_end();
BCF* napravi_sekvencu(BCF* prvi, BCF* drugi);
BCF* napravi_int_konst(int vrijednost);
BCF* napravi_double_konst(double vrijednost);
BCF* napravi_string_konst(char* vrijednost);
BCF* napravi_bool_konst(int vrijednost);
BCF* napravi_identifikator(char* ime);
BCF* napravi_binarni_operator(int tip, BCF* lijevi, BCF* desni);
BCF* napravi_unarni_operator(int tip, BCF* cvor);
BCF* napravi_if(BCF* uslov, BCF* then_grana, BCF* else_grana);
BCF* napravi_while(BCF* uslov, BCF* tijelo);
BCF* napravi_for(BCF* init, BCF* uslov, BCF* tijelo);
BCF* napravi_dodjelu(BCF* lijevi, BCF* desni);
BCF* napravi_read(BCF* cvor);
BCF* napravi_write(BCF* cvor);
BCF* napravi_skip();
void rekurzivna_stampa(BCF *korijen, int nivo);
void stampaj_stablo(BCF *korijen);

#endif // BCF_H
