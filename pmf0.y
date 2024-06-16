%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    struct Promjenljiva{
        char* id;
        int val;
        struct Promjenljiva* next;
    };

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

%left T_AND T_OR T_NOT
%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%nonassoc T_EQ T_NOTEQ T_ISEQ T_LESS T_LEQ T_GREAT T_GEQ

%%
//odje ide gramatika!!!

program:
    T_LET declarations T_IN comm_seq T_END  {}
;

declarations:
    decl_list   {}
    | declarations decl_list    {}
;

decl_list:
    type ident_decl T_TACKA     {}
;

ident_decl:
    T_ID                        {printf("%s ", $1);}
    | ident_decl T_ZAREZ T_ID   {printf("%s ", $3);}
;

comm_seq:
    comm
    | comm_seq comm  {}
;

comm:
    T_SKIP T_SC     {}
    | T_ID T_DODJELA exp T_SC   {printf("%s ", $1);}
    | T_IF exp T_THEN comm_seq T_ELSE comm_seq T_FI T_SC    {}
    | T_IF exp T_THEN comm_seq T_FI T_SC    {}
    | T_IF exp T_DO comm_seq T_END T_SC     {}
    | T_FOR T_LEFTP T_ID T_DODJELA exp T_SC exp T_SC T_ID T_DODJELA exp T_RIGHTP T_DO comm_seq T_END T_SC   {}
    | T_WHILE exp T_DO comm_seq T_END T_SC  {}
    | T_READ T_ID T_SC  {}
    | T_WRITE exp T_SC  {}
;

exp:
    constant    {}
    | T_ID      {printf("%s ", $1);}
    | T_LEFTP exp T_RIGHTP  {}
    | exp T_PLUS exp    {}
    | exp T_MINUS exp   {}
    | exp T_MUL exp     {}
    | exp T_DIV exp     {}
    | exp T_MOD exp     {}
    | exp T_ISEQ exp {}
    | exp T_NOTEQ exp   {}
    | exp T_LESS exp    {}
    | exp T_LEQ exp    {}
    | exp T_GREAT exp   {}
    | exp T_GEQ exp     {}
    | exp T_AND exp     {}
    | exp T_OR exp     {}
    | T_NOT exp         {}
;

constant:
    T_INT   {printf("%d\n", $1);}
    | T_DOUBLE {printf("%lf\n", $1);}
    | T_DBLEXP {printf("%lf\n", $1);}
    | T_HEX {printf("%x\n", $1);}
    | T_STR {printf("%s\n", $1);}
    | T_BOOL {printf("%s\n", $1);}
;

type:
    INT_ID  {printf("int ");}
    | STR_ID    {printf("string ");}
    | DOUBLE_ID     {printf("double ");}
    | HEX_ID    {printf("hex ");}
    | BOOL_ID   {printf("bool ");}
;

/*
//stara gramatika
S: S stat { }
    | S stat2 { }
    | S stat3 { }
    | S stat4 { }
    | S stat5 { }
    | S stat6 { }
    |
;

stat: exp T_SC {printf("%d\n", $1);}
    | T_ID T_EQ exp T_SC {printf("%s=%d\n", $1, $3);
                            struct Promjenljiva* prom=findVariable($1);
                            setVariableValue(prom, $1, $3);
                         }
;

stat2: exp2 T_SC {printf("%f\n", $1);}
     | T_ID T_EQ exp2 T_SC {printf("%s=%f\n", $1, $3);} 
;

stat3: exp3 T_SC {printf("%e\n", $1);}
     | T_ID T_EQ exp3 T_SC {printf("%s=%e\n", $1, $3);}
;

stat4: exp4 T_SC {printf("%x\n", $1);}
     | T_ID T_EQ exp4 T_SC {printf("%s=%x\n", $1, $3);}
;

stat5: exp5 T_SC {printf("%d\n", $1);}
     | T_ID T_EQ exp5 T_SC {printf("%s=%d\n", $1, $3);}
;

stat6: exp6 T_SC {printf("%s\n", $1);}
     | T_ID T_EQ exp6 T_SC {printf("%s=%s\n", $1, $3);}
;

exp:
    exp T_PLUS exp              { $$=$1+$3; }
    | exp T_MINUS exp           { $$=$1-$3; }
    | exp T_MUL exp             { $$=$1*$3; }
    | exp T_DIV exp             { $$=$1/$3; }
    | exp T_MOD exp             { $$=$1%$3; }
    | exp T_JEJEDNAKO exp       { $$=$1==$3; }
    | exp T_MANJE exp           { $$=$1<$3; }
    | exp T_VISE exp            { $$=$1>$3; }
    | exp T_MANJEJEDNAKO exp    { $$=$1<=$3; }
    | exp T_VISEJEDNAKO exp     { $$=$1>=$3; }
    | exp T_RAZLICITO exp       { $$=$1!=$3; }
    | T_LEFTP exp T_RIGHTP      { $$=$2;}
    | T_INT                     { $$=$1;}
    | T_ID                   { $$=getVariableValue($1); }
;

exp2:
    exp2 T_PLUS exp2              { $$=$1+$3; }
    | exp2 T_MINUS exp2           { $$=$1-$3; }
    | exp2 T_MUL exp2             { $$=$1*$3; }
    | exp2 T_DIV exp2             { $$=$1/$3; }
    | exp2 T_JEJEDNAKO exp2       { $$=$1==$3; }
    | exp2 T_MANJE exp2           { $$=$1<$3; }
    | exp2 T_VISE exp2            { $$=$1>$3; }
    | exp2 T_MANJEJEDNAKO exp2    { $$=$1<=$3; }
    | exp2 T_VISEJEDNAKO exp2     { $$=$1>=$3; }
    | exp2 T_RAZLICITO exp2       { $$=$1!=$3; }
    | T_LEFTP exp2 T_RIGHTP       { $$=$2;}
    | T_DOUBLE                    { $$=$1;}
;

exp3:
    exp3 T_PLUS exp3              { $$=$1+$3; }
    | exp3 T_MINUS exp3           { $$=$1-$3; }
    | exp3 T_MUL exp3             { $$=$1*$3; }
    | exp3 T_DIV exp3             { $$=$1/$3; }
    | exp3 T_JEJEDNAKO exp3       { $$=$1==$3; }
    | exp3 T_MANJE exp3           { $$=$1<$3; }
    | exp3 T_VISE exp3            { $$=$1>$3; }
    | exp3 T_MANJEJEDNAKO exp3    { $$=$1<=$3; }
    | exp3 T_VISEJEDNAKO exp3     { $$=$1>=$3; }
    | exp3 T_RAZLICITO exp3       { $$=$1!=$3; }
    | T_LEFTP exp3 T_RIGHTP       { $$=$2;}
    | T_DBLEXP                    { $$=$1;}
;

exp4:
    exp4 T_PLUS exp4              { $$=$1+$3; }
    | exp4 T_MINUS exp4           { $$=$1-$3; }
    | exp4 T_MUL exp4             { $$=$1*$3; }
    | exp4 T_DIV exp4             { $$=$1/$3; }
    | exp4 T_JEJEDNAKO exp4       { $$=$1==$3; }
    | exp4 T_MANJE exp4           { $$=$1<$3; }
    | exp4 T_VISE exp4            { $$=$1>$3; }
    | exp4 T_MANJEJEDNAKO exp4    { $$=$1<=$3; }
    | exp4 T_VISEJEDNAKO exp4     { $$=$1>=$3; }
    | exp4 T_RAZLICITO exp4       { $$=$1!=$3; }
    | T_LEFTP exp4 T_RIGHTP       { $$=$2;}
    | T_HEX                       { $$=$1;}
;

exp5:
    T_BOOLT     { $$=$1; }
    | T_BOOLF   { $$=$1; }
;

exp6:
    T_STR { $$=strdup($1); }
;

*/
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