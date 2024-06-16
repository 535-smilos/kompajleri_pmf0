%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "BCF.h"

    struct Promjenljiva{
        char* id;
        int val;
        struct Promjenljiva* next;
    };

    BCF_Node* root=NULL;

    void yyerror(const char* s);

    struct Promjenljiva* glava_tabele=0;

    void addNewNode(char* id, int val){
        struct Promjenljiva* new_node=(struct Promjenljiva*)malloc(sizeof(struct Promjenljiva));
        new_node->id=(char*)strdup(id);
        new_node->val=val;
        new_node->next=glava_tabele;
        glava_tabele=new_node;
    }

    struct Promjenljiva* findVariable(char* id){
        struct Promjenljiva* curr=glava_tabele;
        while(curr!=0){
            if(strcmp(id, curr->id)==0){
                return curr;
            }
            curr=curr->next;
        }
        return 0;
    }
    
    void setVariableValue(struct Promjenljiva* prom, char* id, int val){
        if(prom==0){
            addNewNode(id, val);
        } else{
            prom->val=val;
        }
    }

    int getVariableValue(char* id){
        struct Promjenljiva* prom=findVariable(id);
        if(prom==0) return 0;
        return prom->val;
    }


%}

%union{
    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    int hex_value;
    bool bool_value;
    char* ident;
    BCF_Node* node;
}

%start program
%token T_SC
%token T_INT
%token T_DOUBLE
%token T_DBLEXP
%token T_HEX
%token T_STR
%token T_BOOL
%token T_ID INT_ID BOOL_ID STR_ID DOUBLE_ID HEX_ID
%token T_DODJELA

%token T_PLUS T_MINUS
%token T_MUL T_DIV T_MOD
%token T_LESS T_GREAT T_LEQ T_GEQ T_ISEQ T_NOTEQ
%token T_AND T_OR T_NOT
%token T_ZAREZ T_TACKA
%token T_LEFTP T_RIGHTP
%token T_FOR T_WHILE T_BREAK T_IF T_ELSE T_THEN T_RETURN T_FI T_DO T_END
%token T_EQ
%token T_SKIP T_LET 
%token T_READ T_WRITE
%token T_IN

%type <int_value>T_INT
%type <double_value>T_DOUBLE
%type <double_exp>T_DBLEXP
%type <hex_value>T_HEX
%type <bool_value>T_BOOL
%type <string_value>T_STR
%type <ident> T_ID INT_ID STR_ID BOOL_ID HEX_ID DOUBLE_ID
%type <node> program declarations decl_list ident_decl comm_seq comm exp constant type


%left T_AND T_OR T_NOT
%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%nonassoc T_EQ T_NOTEQ T_ISEQ T_LESS T_LEQ T_GREAT T_GEQ

%%
//odje ide gramatika!!!

program:
    T_LET declarations T_IN comm_seq T_END  {
        $$=create_node("program", 2, $2, $4);
    }
;

declarations:
    decl_list   {$$=create_node("declarations", 1, $1);}
    | declarations decl_list    {$$=create_node("declarations", 2, $1, $2);}
;

decl_list:
    type ident_decl T_TACKA     {$$=create_node("decl_list", 2, $1, $2);}
;

ident_decl:
    T_ID                        {$$=create_node("ident_decl", 0);}
    | ident_decl T_ZAREZ T_ID   {$$=create_node("ident_decl", 1, $1);}
;

comm_seq:
    comm            {$$=create_node("comm_seq", 1, $1);}
    | comm_seq comm  {
        $$=create_node("comm_seq", 2, $1, $2);
    }
;

comm:
     T_SKIP T_SC  { $$ = create_node("comm", 0); }
    | T_ID T_DODJELA exp T_SC  { $$ = create_node("comm", 1, $3); }
    | T_IF exp T_THEN comm_seq T_ELSE comm_seq T_FI T_SC  { $$ = create_node("comm", 2, $2, $4); }
    | T_IF exp T_THEN comm_seq T_FI T_SC  { $$ = create_node("comm", 1, $2); }
    | T_IF exp T_DO comm_seq T_END T_SC  { $$ = create_node("comm", 2, $2, $4); }
    | T_FOR T_LEFTP T_ID T_DODJELA exp T_SC exp T_SC T_ID T_DODJELA exp T_RIGHTP T_DO comm_seq T_END T_SC  { $$ = create_node("comm", 3, $5, $7, $12); }
    | T_WHILE exp T_DO comm_seq T_END T_SC  { $$ = create_node("comm", 2, $2, $4); }
    | T_READ T_ID T_SC  { $$ = create_node("comm", 0); }
    | T_WRITE exp T_SC  { $$ = create_node("comm", 1, $2); }
;

exp:
    constant  { $$ = create_node("exp", 1, $1); }
    | T_ID  { $$ = create_node("exp", 0); }
    | T_LEFTP exp T_RIGHTP  { $$ = create_node("exp", 1, $2); }
    | exp T_PLUS exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_MINUS exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_MUL exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_DIV exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_MOD exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_ISEQ exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_NOTEQ exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_LESS exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_LEQ exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_GREAT exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_GEQ exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_AND exp  { $$ = create_node("exp", 2, $1, $3); }
    | exp T_OR exp  { $$ = create_node("exp", 2, $1, $3); }
    | T_NOT exp  { $$ = create_node("exp", 1, $2); }
;

constant:
     T_INT  { $$ = create_node("constant", 0); }
    | T_DOUBLE  { $$ = create_node("constant", 0); }
    | T_DBLEXP  { $$ = create_node("constant", 0); }
    | T_HEX  { $$ = create_node("constant", 0); }
    | T_STR  { $$ = create_node("constant", 0); }
    | T_BOOL  { $$ = create_node("constant", 0); }
;

type:
    INT_ID  { $$ = create_node("type", 0); }
    | STR_ID  { $$ = create_node("type", 0); }
    | DOUBLE_ID  { $$ = create_node("type", 0); }
    | HEX_ID  { $$ = create_node("type", 0); }
    | BOOL_ID  { $$ = create_node("type", 0); }
;

%%

void yyerror(const char* s){
    printf("%s\n", s);
}

int main(){
    int res=yyparse();
    print_tree(root, 0);
    free_tree(root);
    if(res==0){
        printf("Ulaz ispravan\n");
    } else printf("NEispravan\n");
    
    return 0;
}