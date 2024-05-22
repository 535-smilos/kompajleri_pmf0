%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
        
    void yyerror(const char* s);

%}

%union{
    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    long hex_value;
    bool bool_value;
    char* ident;
}

%start S
%token T_SC
%token <int_value>T_INT
%token <double_value>T_DOUBLE
%token <double_exp>T_DBLEXP
%token <hex_value>T_HEX
%token <string_value>T_STR
%token <bool_value>T_BOOLT T_BOOLF
%token <ident>T_ID
%token T_PLUS T_MINUS
%token T_MUL T_DIV T_MOD
%token T_DIV2
%token T_MANJE T_VISE T_JEDNAKO T_MANJEJEDNAKO T_VISEJEDNAKO T_JEJEDNAKO T_RAZLICITO
%token T_AND
%token T_OR
%token T_NEGACIJA
%token T_ZAREZ
%token T_TACKA
%token T_LEFTP T_RIGHTP
%token T_FOR
%token T_WHILE
%token T_BREAK
%token T_IF
%token T_ELSE
%token T_INTID
%token T_STRID
%token T_BOOLID
%token T_DOUBLEID
%token T_RETURN
%token T_DO
%token T_END
%token T_EQ

%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%left T_MANJE T_MANJEJEDNAKO T_VISE T_VISEJEDNAKO
%left T_AND T_OR

%type <int_value>exp
%type <int_value>stat

%type <double_value>exp2
%type <double_value>stat2

%type <double_exp>exp3
%type <double_exp>stat3


%%
//odje ide gramatika!!!
S: S stat { }
    | S stat2 { }
    | S stat3 { }
    |
;

stat: exp T_SC {printf("%d\n", $1);}
    | T_ID T_EQ exp T_SC {printf("%s=%d\n", $1, $3);}
;

stat2: exp2 T_SC {printf("%f\n", $1);}
     | T_ID T_EQ exp2 T_SC {printf("%s=%f\n", $1, $3);} 
;

stat3: exp3 T_SC {printf("%e\n", $1);}
     | T_ID T_EQ exp3 T_SC {printf("%s=%e\n", $1, $3);}

exp:
    exp T_PLUS exp              { $$=$1+$3; }
    | exp T_MINUS exp           { $$=$1-$3; }
    | exp T_MUL exp             { $$=$1*$3; }
    | exp T_DIV exp             { $$=$1/$3; }
    | exp T_MOD exp             { $$=$1%$3; }
    | T_LEFTP exp T_RIGHTP      { $$=$2;}
    | T_INT                     { $$=$1;}
;

exp2:
    exp2 T_PLUS exp2              { $$=$1+$3; }
    | exp2 T_MINUS exp2           { $$=$1-$3; }
    | exp2 T_MUL exp2             { $$=$1*$3; }
    | exp2 T_DIV exp2             { $$=$1/$3; }
    | T_LEFTP exp2 T_RIGHTP       { $$=$2;}
    | T_DOUBLE                    { $$=$1;}
;

exp3:
    exp3 T_PLUS exp3              { $$=$1+$3; }
    | exp3 T_MINUS exp3           { $$=$1-$3; }
    | exp3 T_MUL exp3             { $$=$1*$3; }
    | exp3 T_DIV exp3             { $$=$1/$3; }
    | T_LEFTP exp3 T_RIGHTP       { $$=$2;}
    | T_DBLEXP                    { $$=$1;}
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