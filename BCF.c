#include "BCF.h"

// Pomoćne funkcije za kreiranje čvorova

BCF* napravi_program(BCF* deklaracije, BCF* komande) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_PROGRAM;
    cvor->c_program.decl = napravi_let(deklaracije);
    cvor->c_program.comm = napravi_in(komande);
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

BCF* napravi_int_konst(int vrednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_INTID;
    cvor->int_value = vrednost;
    return cvor;
}

BCF* napravi_double_konst(double vrednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_DBLID;
    cvor->double_value = vrednost;
    return cvor;
}

BCF* napravi_string_konst(char* vrednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_STRID;
    cvor->string_value = strdup(vrednost);
    return cvor;
}

BCF* napravi_bool_konst(bool vrednost) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_BOOLID;
    cvor->bool_value = vrednost;
    return cvor;
}

BCF* napravi_identifikator(char* ime) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_IDENT;
    cvor->ident = strdup(ime);
    return cvor;
}

BCF* napravi_binarni_operator(int tip, BCF* levi, BCF* desni) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = tip;
    cvor->c_binarna_op.lijevi = levi;
    cvor->c_binarna_op.desni = desni;
    return cvor;
}

BCF* napravi_unarni_operator(int tip, BCF* cvor) {
    BCF* novi_cvor = (BCF*)malloc(sizeof(BCF));
    novi_cvor->tip = tip;
    novi_cvor->c_unarna_op.cvor = cvor;
    return novi_cvor;
}

BCF* napravi_if(BCF* uslov, BCF* onda_grana, BCF* inace_grana) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_IF;
    cvor->c_if.cond = uslov;
    cvor->c_if.branch_t = onda_grana;
    cvor->c_if.branch_e = inace_grana;
    return cvor;
}

BCF* napravi_while(BCF* uslov, BCF* telo) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_WHILE;
    cvor->c_while.cond = uslov;
    cvor->c_while.body = telo;
    return cvor;
}

BCF* napravi_for(BCF* init, BCF* uslov, BCF* telo) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_FOR;
    cvor->c_for.init = init;
    cvor->c_for.cond = uslov;
    cvor->c_for.for_body = telo;
    return cvor;
}

BCF* napravi_dodelu(BCF* levi, BCF* desni) {
    BCF* cvor = (BCF*)malloc(sizeof(BCF));
    cvor->tip = C_DODJELA;
    cvor->c_binarna_op.lijevi = levi;
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
        default: return "nepoznat_op";
    }
}

void rekurzivna_stampa(BCF* korijen, int dubina, int nivo) {
    if (!korijen) return;

    for (int i = 0; i < nivo; ++i) printf("  ");

    switch (korijen->tip) {
        case C_PROGRAM:
            printf("%d. nivo: PROGRAM\n", nivo);
            rekurzivna_stampa(korijen->c_program.decl, dubina + 1, nivo + 1);
            rekurzivna_stampa(korijen->c_program.comm, dubina + 1, nivo + 1);
            break;

        case C_LET:
            printf("%d. nivo: LET\n", nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], dubina + 1, nivo + 1);
            break;

        case C_IN:
            printf("%d. nivo: IN\n", nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], dubina + 1, nivo + 1);
            break;

        case C_END:
            printf("%d. nivo: END\n", nivo);
            break;

        case C_SKIP:
            printf("%d. nivo: SKIP\n", nivo);
            break;

        case C_IF:
            printf("%d. nivo: IF\n", nivo);
            rekurzivna_stampa(korijen->c_if.cond, dubina + 1, nivo + 1);
            printf("%d. nivo: THEN\n", nivo + 1);
            rekurzivna_stampa(korijen->c_if.branch_t, dubina + 2, nivo + 2);
            if (korijen->c_if.branch_e) {
                printf("%d. nivo: ELSE\n", nivo + 1);
                rekurzivna_stampa(korijen->c_if.branch_e, dubina + 2, nivo + 2);
            }
            break;

        case C_WHILE:
            printf("%d. nivo: WHILE\n", nivo);
            rekurzivna_stampa(korijen->c_while.cond, dubina + 1, nivo + 1);
            printf("%d. nivo: DO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_while.body, dubina + 2, nivo + 2);
            printf("%d. nivo: END\n", nivo);
            break;

        case C_FOR:
            printf("%d. nivo: FOR\n", nivo);
            rekurzivna_stampa(korijen->c_for.init, dubina + 1, nivo + 1);
            printf("%d. nivo: TO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_for.cond, dubina + 2, nivo + 2);
            printf("%d. nivo: DO\n", nivo + 1);
            rekurzivna_stampa(korijen->c_for.for_body, dubina + 2, nivo + 2);
            break;

        case C_READ:
            printf("%d. nivo: READ\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, dubina, nivo + 1);
            break;

        case C_WRITE:
            printf("%d. nivo: WRITE\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, dubina, nivo + 1);
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
            printf("%d. nivo: %s\n", nivo, dohvati_ime_operatora(korijen->tip));
            rekurzivna_stampa(korijen->c_binarna_op.lijevi, dubina + 1, nivo + 1);
            rekurzivna_stampa(korijen->c_binarna_op.desni, dubina + 1, nivo + 1);
            break;

        case C_NOT:
            printf("%d. nivo: NOT\n", nivo);
            rekurzivna_stampa(korijen->c_unarna_op.cvor, dubina + 1, nivo + 1);
            break;

        case C_IDENT:
            printf("%d. nivo: identifikator [%s]\n", nivo, korijen->ident);
            break;

        case C_INTID:
            printf("%d. nivo: int konstanta [%d]\n", nivo, korijen->int_value);
            break;

        case C_DBLID:
            printf("%d. nivo: double konstanta [%lf]\n", nivo, korijen->double_value);
            break;

        case C_STRID:
            printf("%d. nivo: string konstanta [%s]\n", nivo, korijen->string_value);
            break;

        case C_BOOLID:
            printf("%d. nivo: bool konstanta [%s]\n", nivo, korijen->bool_value ? "true" : "false");
            break;

        case C_SEK:
            rekurzivna_stampa(korijen->c_sek.cvorovi[0], dubina, nivo);
            rekurzivna_stampa(korijen->c_sek.cvorovi[1], dubina, nivo);
            break;

        default:
            printf("%d. nivo: NEPOZNAT ČVOR\n", nivo);
            break;
    }
}

void stampaj_stablo(BCF* korijen) {
    rekurzivna_stampa(korijen, 100, 0);
}
