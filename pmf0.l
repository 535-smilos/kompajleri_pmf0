%{
int kolona=1;//karakter u koloni
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pmf0.tab.h"
#include "greske.h"

#define YYLTYPE yylloc

#define YY_USER_ACTION \
    kolona += yyleng;
%}

%x KOMENTAR_ULINIJI
%x KOMENTAR_VISELINIJA

%option yylineno
%option noyywrap

%% 

[ \t]+       { kolona += yyleng; } //ucitavanje praznine sabira pomjeraj duzine broja praznina
\n          { kolona = 1; } //resetuje se jer smo presli u novi red, pa citamo ponovo od pocetka!

"//"        {BEGIN(KOMENTAR_ULINIJI);}
"/*"        {printf("Komentar u vise linija!\n");BEGIN(KOMENTAR_VISELINIJA);}

"STRING"        {return STR_ID;} //tipovi promj
"BOOL"          {return BOOL_ID;}
"DOUBLE"        {return DOUBLE_ID;}
"INT"           {return INT_ID;}
"HEX"           {return HEX_ID;}

"IF"        {printf(yytext); return T_IF;}//kljucne rijeci
"THEN"      {printf(yytext); return T_THEN;}
"ELSE"      {printf(yytext); return T_ELSE;}
"FOR"       {printf(yytext); return T_FOR;}
"WHILE"     {printf(yytext); return T_WHILE;}
"FI"        {printf(yytext); return T_FI;}
"DO"        {printf(yytext); return T_DO;}
"BREAK"     {printf(yytext); return T_BREAK;}
"WRITE"     {printf(yytext); return T_WRITE;}
"SKIP"      {printf(yytext); return T_SKIP;}
"READ"      {printf(yytext); return T_READ;}
"LET"       {printf(yytext); return T_LET;}
"RETURN"    {printf(yytext); return T_RETURN;}
"IN"        {printf(yytext); return T_IN;}
"END"       {printf(yytext); return T_END;}

\"[^"\n]*\"     {char* s=malloc(yyleng-1);strncpy(s, yytext+1, yyleng-2); s[yyleng-2]='\0'; yylval.string_value=s; return T_STR;}    //regularni izrazi
-?0|[1-9][0-9]*   {yylval.int_value=atoi(yytext);return T_INT;}    //int 
(0X|0x)[1-9A-Fa-f][0-9A-Fa-f]*   {int a; sscanf(yytext+2, "%x", &a);yylval.hex_value=a; return T_HEX;} //heksadekadni
-?[0-9]+\.[0-9]* {double num; sscanf(yytext, "%lf", &num);yylval.double_value=num; return T_DOUBLE;} //double
-?[0-9]+\.[0-9]*[eE][+-]?[0-9]+ {double num; sscanf(yytext, "%lf", &num);yylval.double_exp=num; return T_DBLEXP;} //double sa exp
"true|false"    {yylval.bool_value=(strcmp(yytext, "true")==0); return T_BOOL;}
[a-zA-Z_][a-zA-Z0-9_]{0,29}  {yylval.ident=(char*)strdup(yytext); return T_ID;} //identifikator 

"<="        {return T_LEQ;} //operatori
"<"         {return T_LESS;}
">="        {return T_GEQ;}
">"         {return T_GREAT;}
"=="        {return T_ISEQ;}
"!="        {return T_NOTEQ;}
"&&"        {return T_AND;}
"||"        {return T_OR;}
"!"         {return T_NOT;}
":="        {return T_DODJELA;}

"+"     {return T_PLUS;} //operatori
"-"     {return T_MINUS;} 
"*"     {return T_MUL;} 
"/"     {return T_DIV;} 
"="     {return T_EQ;} 

";"     {return T_SC;}//znaci interpunkcije
"."     {return T_TACKA;}
","     {return T_ZAREZ;}
"("     {return T_LEFTP;}
")"     {return T_RIGHTP;}

    /*greske!*/

[a-zA-Z_][a-zA-Z0-9_]{0,29}[a-zA-Z0-9_]     {
    invalidanIdentifikator(yytext, yylineno, kolona-yyleng);
    return;
}

(0x|0X)[^a-fA-F0-9]   {
    invalidanHex1(yytext, yylineno, kolona-yyleng);
    return;
}

(0x|0X)[1-9A-Za-z][0-9A-Za-z]*      {
    invalidanHex2(yytext, yylineno, kolona-yyleng);
    return;
}

\.[0-9]+                      {
    invalidanDouble1(yytext, yylineno, kolona-yyleng);
    return;
}

[0-9]+(\.[0-9]+)?[eE][+-]?[0-9]+    {
    invalidanDExp1(yytext, yylineno, kolona-yyleng);
    return;
}

[0-9]+\.[0-9]*[eE][+-]? {
    invalidanDExp2(yytext, yylineno, kolona-yyleng);
    return;
}

\"[^"\n]* { 
    invalidanString(yytext, yylineno, kolona-yyleng);
    return;
 }

.       {
    printf("Greska! Invalidan karakter %c na liniji: %d, koloni: %d\n", yytext[0], yylineno, kolona-yyleng); return;}

<KOMENTAR_ULINIJI>{
"\n"    {printf("Komentar u liniji!\n");
         kolona=1;
         BEGIN(INITIAL);}
"//"    {invalidanKomentar(yylineno, kolona-yyleng); return;}
.       {kolona++;}
}

<KOMENTAR_VISELINIJA>{
"\n"    {kolona=1;}
"*/"    {BEGIN(INITIAL);}
"/*"    {invalidanKomentar(yylineno, kolona-yyleng); return;}
<<EOF>> {invalidanKomentar(yylineno, kolona-yyleng); return;}
.       {kolona++;}
}

%%
