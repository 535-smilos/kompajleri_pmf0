%{
int kolona=1;//karakter u koloni
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pmf0.tab.h"
%}

%x KOMENTAR_ULINIJI
%x KOMENTAR_VISELINIJA

%option yylineno
%option noyywrap

%% 

[ \t]+       { kolona += yyleng; } //ucitavanje praznine sabira pomjeraj duzine broja praznina
\n          { kolona = 1; } //resetuje se jer smo presli u novi red, pa citamo ponovo od pocetka!

"//"        {BEGIN(KOMENTAR_ULINIJI);}
"/*"        {BEGIN(KOMENTAR_VISELINIJA);}

"STRING"        {printf("TYPE: STRING\n"); kolona+=yyleng;} //tipovi podataka
"BOOLEAN"       {printf("TYPE: BOOLEAN\n");kolona+=yyleng;}
"DOUBLE"        {printf("TYPE: DOUBLE\n");kolona+=yyleng;}
"INT"           {printf("TYPE: INT\n");kolona+=yyleng;}

"IF"        {kolona+=yyleng; return T_IF;}   
"THEN"      {printf("THEN\n");kolona+=yyleng;}
"ELSE"      {kolona+=yyleng; return T_ELSE;}
"FOR"       {kolona+=yyleng; return T_FOR;}
"WHILE"     {kolona+=yyleng; return T_WHILE;}
"FI"        {printf("FI\n");kolona+=yyleng;}
"DO"        {kolona+=yyleng; return T_DO;}
"BREAK"     {kolona+=yyleng; return T_BREAK;}
"WRITE"     {printf("WRITE\n");kolona+=yyleng;}
"true"      {bool a; sscanf(yytext, "%d", &a); yylval.bool_value=a; kolona+=yyleng; return T_BOOLT;}
"false"     {bool a; sscanf(yytext, "%d", &a); yylval.bool_value=a; kolona+=yyleng; return T_BOOLF;}
"SKIP"      {printf("SKIP\n");kolona+=yyleng;}
"READ"      {printf("READ\n");kolona+=yyleng;}
"LET"       {printf("LET\n");kolona+=yyleng;}
":="        {printf(":=\n");kolona+=yyleng;}
"RETURN"    {printf("RETURN\n");kolona+=yyleng;}
"IN"        {printf("IN\n");kolona+=yyleng;}
"END"       {kolona+=yyleng; return T_END;}

\"[^"\n]*\"     {yylval.string_value=yytext; kolona+=yyleng; return T_STR;}    //regularni izrazi
0|[1-9][0-9]*   {yylval.int_value=atoi(yytext);kolona+=yyleng; return T_INT;}    //int 
(0X|0x)[1-9A-Fa-f][0-9A-Fa-f]*   {int a; sscanf(yytext+2, "%x", &a);yylval.hex_value=a; kolona+=yyleng; return T_HEX;} //heksadekadni
[0-9]+\.[0-9]* {double num; sscanf(yytext, "%lf", &num);yylval.double_value=num; kolona+=yyleng;return T_DOUBLE;} //double
[0-9]+\.[0-9]*[eE][+-]?[0-9]+ {double num; sscanf(yytext, "%lf", &num);yylval.double_exp=num; kolona+=yyleng; return T_DBLEXP;} //double sa exp
[a-zA-Z_][a-zA-Z0-9_]{0,29}  {yylval.ident=(char*)strdup(yytext); kolona+=yyleng; return T_ID;} //identifikator 

"<="        {kolona+=yyleng; return T_MANJEJEDNAKO;} //operatori
"<"         {kolona+=yyleng; return T_MANJE;}
">="        {kolona+=yyleng; return T_VISEJEDNAKO;}
">"         {kolona+=yyleng; return T_VISE;}
"=="        {kolona+=yyleng; return T_JEJEDNAKO;}
"!="        {kolona+=yyleng; return T_RAZLICITO;}
"&&"        {kolona+=yyleng; return T_AND;}
"||"        {kolona+=yyleng; return T_OR;}

"+"     {kolona+=yyleng; return T_PLUS;} //unarni operatori
"-"     {kolona+=yyleng; return T_MINUS;} 
"*"     {kolona+=yyleng; return T_MUL;} 
"/"     {kolona+=yyleng; return T_DIV;} 
"="     {kolona+=yyleng; return T_EQ;} 

";"     {kolona+=yyleng; return T_SC;}//znaci interpunkcije
"."     {kolona+=yyleng; return T_TACKA;}
","     {kolona+=yyleng; return T_ZAREZ;}
"("     {kolona+=yyleng; return T_LEFTP;}
")"     {kolona+=yyleng; return T_RIGHTP;}
"!"     {kolona+=yyleng; return T_NEGACIJA;}

    /*greske!*/

[a-zA-Z_][a-zA-Z0-9_]{0,29}[a-zA-Z0-9_]     {
    printf("Greska! Identifikator: %s prevazilazi duzinu od 30 karaktera na liniji: %d, koloni:%d\n", yytext, yylineno, kolona); 
    kolona+=yyleng;}

(0x|0X)[^a-fA-F0-9]   {
    printf("Greska! Invalidan heksadecimalni broj na liniji(ne sadrzi nista posle 0x/X): %d, koloni: %d\n", yylineno, kolona); 
    kolona+=yyleng;}

(0x|0X)[1-9A-Za-z][0-9A-Za-z]*      {
    printf("Greska! Invalidan heksadecimalni broj na liniji: %d, koloni: %d\n", yylineno, kolona); 
    kolona+=yyleng;}

\.[0-9]+                      {
    printf("Greska! Invalidan double broj bez vodece nule na liniji: %d, koloni: %d\n", yylineno, kolona); 
    kolona+=yyleng;}

[0-9]+(\.[0-9]+)?[eE][+-]?[0-9]+    {
    printf("Greska! Invalidan double broj sa exp na liniji: %d, koloni: %d\n", yylineno, kolona);
    kolona+=yyleng;}

[0-9]+\.[0-9]*[eE][+-]? {
    printf("Greska! Invalidan double broj sa exp na liniji: %d, koloni: %d\n", yylineno, kolona);
    kolona+=yyleng;}

\"[^"\n]* { 
    printf("Greska! Nezatvoren string: %s na liniji: %d, koloni: %d\n", yytext, yylineno, kolona); 
    kolona+=yyleng; }

.       {
    printf("Greska! Invalidan karakter %c na liniji: %d, koloni: %d\n", yytext[0], yylineno, kolona); kolona+=yyleng;}

<KOMENTAR_ULINIJI>{
"\n"    {printf("Komentar u liniji!\n");
         kolona=1;
         BEGIN(INITIAL);}
.       {kolona++;}
}

<KOMENTAR_VISELINIJA>{
"\n"    {printf("Komentar u vise linija!\n"); kolona=1;}
"*/"    {BEGIN(INITIAL);}
.       {kolona++;}
}

%%
