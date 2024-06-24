%{
    #include "BCF.h"  // Uključite vašu biblioteku BCF
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    void yyerror(const char* s);  // Prototip funkcije za prijavu grešaka od strane Bison-a
%}

%union {
    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    int hex_value;
    bool bool_value;
    char* ident;
    BCF *cvor;
}

%token T_SC
%token <int_value>T_INT
%token <double_value>T_DOUBLE
%token <double_exp>T_DBLEXP
%token <hex_value>T_HEX
%token <bool_value>T_BOOL
%token <string_value>T_STR
%token <ident> T_ID INT_ID STR_ID BOOL_ID HEX_ID DOUBLE_ID
%token T_DODJELA
%token T_PLUS T_MINUS T_MUL T_DIV T_MOD
%token T_LESS T_GREAT T_LEQ T_GEQ T_ISEQ T_NOTEQ
%token T_AND T_OR T_NOT
%token T_ZAREZ T_TACKA
%token T_LEFTP T_RIGHTP
%token T_FOR T_WHILE T_BREAK T_IF T_ELSE T_THEN T_RETURN T_FI T_DO T_END
%token T_EQ
%token T_SKIP T_LET T_READ T_WRITE T_IN T_TO

%type <cvor> program declarations decl_list ident_decl comm_seq comm exp constant type

%left T_AND T_OR T_NOT
%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%nonassoc T_EQ T_NOTEQ T_ISEQ T_LESS T_LEQ T_GREAT T_GEQ

%start program

%%

program:
    T_LET declarations T_IN comm_seq T_END  { $$ = napravi_program($2, $4); stampaj_stablo($$); }
;

declarations:
    decl_list   { $$ = $1; }
    | declarations decl_list  { $$ = napravi_sekvencu($1, $2); }
;

decl_list:
    type ident_decl T_TACKA   { $$ = napravi_sekvencu($1, $2); }
;

ident_decl:
    T_ID  { $$ = napravi_identifikator($1); }
    | ident_decl T_ZAREZ T_ID   { $$ = napravi_sekvencu($1, napravi_identifikator($3)); }
;

comm_seq:
    comm  { $$ = $1; }
    | comm_seq comm  { $$ = napravi_sekvencu($1, $2); }
;

comm:
    T_SKIP T_SC  { $$ = napravi_skip(); }
    | T_ID T_DODJELA exp T_SC  { $$ = napravi_dodelu(napravi_identifikator($1), $3); }
    | T_IF exp T_THEN comm_seq T_ELSE comm_seq T_FI T_SC  { $$ = napravi_if($2, $4, $6); }
    | T_IF exp T_THEN comm_seq T_FI T_SC %prec T_ELSE  { $$ = napravi_if($2, $4, NULL); }
    | T_FOR T_ID T_DODJELA exp T_TO exp T_DO comm_seq T_END T_SC  { BCF* cvor = napravi_dodelu(napravi_identifikator($2), $4); $$ = napravi_for(cvor, $6, $8); }
    | T_WHILE exp T_DO comm_seq T_END T_SC  { $$ = napravi_while($2, $4); }
    | T_READ T_ID T_SC  { $$ = napravi_read(napravi_identifikator($2)); }
    | T_WRITE exp T_SC  { $$ = napravi_write($2); }
;

exp:
    constant  { $$ = $1; }
    | T_ID  { $$ = napravi_identifikator($1); }
    | T_LEFTP exp T_RIGHTP  { $$ = $2; }
    | exp T_PLUS exp  { $$ = napravi_binarni_operator(C_PLUS, $1, $3); }
    | exp T_MINUS exp  { $$ = napravi_binarni_operator(C_MINUS, $1, $3); }
    | exp T_MUL exp  { $$ = napravi_binarni_operator(C_MUL, $1, $3); }
    | exp T_DIV exp  { $$ = napravi_binarni_operator(C_DIV, $1, $3); }
    | exp T_MOD exp  { $$ = napravi_binarni_operator(C_MOD, $1, $3); }
    | exp T_ISEQ exp  { $$ = napravi_binarni_operator(C_ISEQ, $1, $3); }
    | exp T_NOTEQ exp  { $$ = napravi_binarni_operator(C_NOTEQ, $1, $3); }
    | exp T_LESS exp  { $$ = napravi_binarni_operator(C_LESS, $1, $3); }
    | exp T_LEQ exp  { $$ = napravi_binarni_operator(C_LEQ, $1, $3); }
    | exp T_GREAT exp  { $$ = napravi_binarni_operator(C_GREAT, $1, $3); }
    | exp T_GEQ exp  { $$ = napravi_binarni_operator(C_GEQ, $1, $3); }
    | exp T_AND exp  { $$ = napravi_binarni_operator(C_AND, $1, $3); }
    | exp T_OR exp  { $$ = napravi_binarni_operator(C_OR, $1, $3); }
    | T_NOT exp  { $$ = napravi_unarni_operator(C_NOT, $2); }
;

constant:
    T_INT  { $$ = napravi_int_konst($1); }
    | T_DOUBLE  { $$ = napravi_double_konst($1); }
    | T_DBLEXP  { $$ = napravi_double_konst($1); }
    | T_HEX  { $$ = napravi_int_konst($1); }
    | T_STR  { $$ = napravi_string_konst($1); }
    | T_BOOL  { $$ = napravi_bool_konst($1); }
;

type:
    INT_ID  { $$ = napravi_identifikator("int"); }
    | STR_ID  { $$ = napravi_identifikator("string"); }
    | DOUBLE_ID  { $$ = napravi_identifikator("double"); }
    | HEX_ID  { $$ = napravi_identifikator("hex"); }
    | BOOL_ID  { $$ = napravi_identifikator("bool"); }
;

%%

void yyerror(const char* s){
    printf("%s\n", s);
}

int main(){
    int res=yyparse();

    if(res==0){
        printf("Ulaz ispravan\n");
    } else printf("NEispravan\n");
    
    return 0;
}
