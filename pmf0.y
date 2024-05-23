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

    struct Promjenljiva* glava=0;

    void addNewNode(char* id, int val){
        struct Promjenljiva* new_node=(struct Promjenljiva*)malloc(sizeof(struct Promjenljiva));
        new_node->id=(char*)strdup(id);
        new_node->val=val;
        new_node->next=glava;
        glava=new_node;
    }

    struct Promjenljiva* findVariable(char* id){
        struct Promjenljiva* curr=glava;
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

%start S
%token T_SC
%token <int_value>T_INT
%token <double_value>T_DOUBLE
%token <double_exp>T_DBLEXP
%token <hex_value>T_HEX
%token <string_value>T_STR
%token <bool_value>T_BOOLT T_BOOLF
%token <ident> T_ID T_INTID T_BOOLID T_STRID T_DOUBLEID

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
%token T_RETURN
%token T_DO
%token T_END
%token T_EQ

%left T_PLUS T_MINUS
%left T_MUL T_DIV T_MOD
%nonassoc T_EQ T_RAZLICITO T_JEJEDNAKO
%left T_MANJE T_MANJEJEDNAKO T_VISE T_VISEJEDNAKO
%left T_AND T_OR

%type <int_value>exp
%type <int_value>stat

%type <double_value>exp2
%type <double_value>stat2

%type <double_exp>exp3
%type <double_exp>stat3

%type <hex_value>exp4
%type <hex_value>stat4

%type <bool_value>exp5
%type <bool_value>stat5

%type <string_value>exp6
%type <string_value>stat6

%%
//odje ide gramatika!!!
S: S stat { }
    | S stat2 { }
    | S stat3 { }
    | S stat4 { }
    | S stat5 { }
    | S stat6 { }
    |
;

stat: exp T_SC {printf("%d\n", $1);}
    | T_ID T_EQ exp T_SC {/*printf("%s=%d\n", $1, $3);*/
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