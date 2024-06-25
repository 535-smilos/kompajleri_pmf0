#include "BCF.h"

BCF* napravi_program(BCF* deklaracije, BCF* komande) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_PROGRAM;
    cvor->c_sek.cvorovi[0] = napravi_let(deklaracije);
    cvor->c_sek.cvorovi[1] = napravi_in(komande);
    return cvor;
}

BCF* napravi_let(BCF* deklaracije) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_LET;
    cvor->c_sek.cvorovi[0] = deklaracije;
    return cvor;
}

BCF* napravi_in(BCF* komande) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_IN;
    cvor->c_sek.cvorovi[0] = komande;
    return cvor;
}

BCF* napravi_end() {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_END;
    return cvor;
}

BCF* napravi_sekvencu(BCF* prvi, BCF* drugi) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_SEK;
    cvor->c_sek.cvorovi[0] = prvi;
    cvor->c_sek.cvorovi[1] = drugi;
    return cvor;
}

BCF* napravi_int_konst(int vrijednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_INT;
    cvor->int_value = vrijednost;
    return cvor;
}

BCF* napravi_double_konst(double vrijednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_DBL;
    cvor->double_value = vrijednost;
    return cvor;
}

BCF* napravi_string_konst(char* vrijednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_STR;
    cvor->string_value = strdup(vrijednost);
    return cvor;
}

BCF* napravi_bool_konst(int vrijednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_BOOL;
    cvor->bool_value = vrijednost;
    return cvor;
}

BCF* napravi_identifikator(char* ime) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_IDENT;
    cvor->ident = strdup(ime);
    return cvor;
}

BCF* napravi_binarni_operator(int tip, BCF* lijevi, BCF* desni) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = tip;
    cvor->c_binarna_op.lijevi = lijevi;
    cvor->c_binarna_op.desni = desni;
    return cvor;
}

BCF* napravi_unarni_operator(int tip, BCF* cvor) {
    BCF* novi_cvor = (BCF*)malloc(sizeof(BCF));
    novi_cvor->tip = tip;
    novi_cvor->c_unarna_op.cvor = cvor;
    return novi_cvor;
}

BCF* napravi_if(BCF* uslov, BCF* then_grana, BCF* else_grana) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_IF;
    cvor->c_if.cond = uslov;
    cvor->c_if.branch_t = then_grana;
    cvor->c_if.branch_e = else_grana;
    return cvor;
}

BCF* napravi_while(BCF* uslov, BCF* body) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_WHILE;
    cvor->c_while.cond = uslov;
    cvor->c_while.body = body;
    return cvor;
}

BCF* napravi_for(BCF* init, BCF* uslov, BCF* body) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_FOR;
    cvor->c_for.init = init;
    cvor->c_for.cond = uslov;
    cvor->c_for.for_body = body;
    return cvor;
}

BCF* napravi_dodjelu(BCF* lijevi, BCF* desni) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_DODJELA;
    cvor->c_binarna_op.lijevi = lijevi;
    cvor->c_binarna_op.desni = desni;
    return cvor;
}

BCF* napravi_read(BCF* cvor) {
    BCF* novi_cvor = (BCF*)malloc(sizeof(BCF));
    novi_cvor->tip = C_READ;
    novi_cvor->c_unarna_op.cvor = cvor;
    return novi_cvor;
}

BCF* napravi_write(BCF* cvor) {
    BCF* novi_cvor = (BCF*)malloc(sizeof(BCF));
    novi_cvor->tip = C_WRITE;
    novi_cvor->c_unarna_op.cvor = cvor;
    return novi_cvor;
}

BCF* napravi_skip() {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_SKIP;
    return cvor;
}

const char* dohvati_ime_operatora(int tip) {
    switch (tip) {
        case C_PLUS: return "+";
        case C_MINUS: return "-";
        case C_MUL: return "*";
        case C_DIV: return "/";
        case C_MOD: return "%";
        case C_LEQ: return "<=";
        case C_GEQ: return ">=";
        case C_LESS: return "<";
        case C_GREAT: return ">";
        case C_ISEQ: return "==";
        case C_NOTEQ: return "!=";
        case C_AND: return "&&";
        case C_OR: return "||";
        case C_NOT: return "!";
        case C_DODJELA: return ":=";
        default: return "nepoznat_operator";
    }
}

void rekurzivna_stampa(BCF* korijen, int nivo) {
    if (!korijen) return;
    
    switch (korijen->tip) {
        case C_PROGRAM:
            printf("Nivo %d: PROGRAM\n", nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], nivo + 1);  
            rekurzivna_stampa(korijen->c_sek.cvorovi[1], nivo + 1);  
            printf("Nivo %d: END\n", nivo);
            break;

        case C_LET:
            printf("Nivo %d: LET\n", nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], nivo + 1);
            break;

        case C_IN:
            printf("Nivo %d: IN\n", nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], nivo + 1);
            break;

        case C_END:
            printf("Nivo %d: END\n", nivo);
            break;

        case C_SKIP:
            printf("Nivo %d: SKIP\n", nivo);
            break;

        case C_IF:
            printf("Nivo %d: IF\n", nivo);
            rekurzivna_stampa(korijen->c_if.cond, nivo + 1);
            printf("Nivo %d: THEN\n", nivo + 1);
            rekurzivna_stampa(korijen->c_if.branch_t, nivo + 2);
            if (korijen->c_if.branch_e) {
                printf("Nivo %d: ELSE\n", nivo + 1);
                rekurzivna_stampa(korijen->c_if.branch_e, nivo + 2);
            }
            break;

        case C_WHILE:
            printf("Nivo %d: WHILE\n", nivo);
            rekurzivna_stampa(korijen->c_while.cond, nivo + 1);
            printf("Nivo %d: DO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_while.body, nivo + 2);
            printf("Nivo %d: END\n", nivo);
            break;

        case C_FOR:
            printf("Nivo %d: FOR\n", nivo);
            rekurzivna_stampa(korijen->c_for.init, nivo + 1);
            printf("Nivo %d: TO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_for.cond, nivo + 2);
            printf("Nivo %d: DO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_for.for_body, nivo + 2);
            break;

        case C_READ:
            printf("Nivo %d: READ\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, nivo + 1);
            break;

        case C_WRITE:
            printf("Nivo %d: WRITE\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, nivo + 1);
            break;

        case C_DODJELA:
        case C_PLUS:
        case C_MINUS:
        case C_MUL:
        case C_DIV:
        case C_MOD:
        case C_LEQ:
        case C_GEQ:
        case C_LESS:
        case C_GREAT:
        case C_ISEQ:
        case C_NOTEQ:
        case C_AND:
        case C_OR:
            printf("Nivo %d: %s\n", nivo, dohvati_ime_operatora(korijen->tip));
            rekurzivna_stampa(korijen->c_binarna_op.lijevi, nivo + 1);
            rekurzivna_stampa(korijen->c_binarna_op.desni, nivo + 1);
            break;

        case C_NOT:
            printf("Nivo %d: NOT\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, nivo + 1);
            break;

        case C_IDENT:
            printf("Nivo %d: identifikator %s\n", nivo, korijen->ident);
            break;

        case C_INT:
            printf("Nivo %d: int %d\n", nivo, korijen->int_value);
            break;

        case C_DBL:
            printf("Nivo %d: double  %lf\n", nivo, korijen->double_value);
            break;

        case C_STR:
            printf("Nivo %d: string %s\n", nivo, korijen->string_value);
            break;

        case C_BOOL:
            printf("Nivo %d: bool %s\n", nivo, korijen->bool_value?"true":"false");
            break;

        case C_SEK:
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[1], nivo);
            break;

        default:
            printf("Nivo %d: Nepoznato\n", nivo);
            break;
    }
}

void stampaj_stablo(BCF* korijen) {
    rekurzivna_stampa(korijen, 0);
}
