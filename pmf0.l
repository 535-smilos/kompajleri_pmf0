%{
int kolona=1;//karakter u koloni
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%x KOMENTAR_ULINIJI
%x KOMENTAR_VISELINIJA

%option yylineno

%% 

[ \t]+       { kolona += yyleng; } //ucitavanje praznine sabira pomjeraj duzine broja praznina
\n          { kolona = 1; } //resetuje se jer smo presli u novi red, pa citamo ponovo od pocetka!

"//"        {BEGIN(KOMENTAR_ULINIJI);}
"/*"        {BEGIN(KOMENTAR_VISELINIJA);}

"STRING"        {printf("TYPE: STRING\n"); kolona+=yyleng;} //tipovi podataka
"BOOLEAN"       {printf("TYPE: BOOLEAN\n");kolona+=yyleng;}
"DOUBLE"        {printf("TYPE: DOUBLE\n");kolona+=yyleng;}
"INT"           {printf("TYPE: INT\n");kolona+=yyleng;}

"IF"        {printf("IF\n");kolona+=yyleng;}   
"THEN"      {printf("THEN\n");kolona+=yyleng;}
"ELSE"      {printf("ELSE\n");kolona+=yyleng;}
"FOR"       {printf("FOR\n");kolona+=yyleng;}
"WHILE"     {printf("WHILE\n");kolona+=yyleng;}
"FI"        {printf("FI\n");kolona+=yyleng;}
"DO"        {printf("DO\n");kolona+=yyleng;}
"BREAK"     {printf("BREAK\n");kolona+=yyleng;}
"WRITE"     {printf("WRITE\n");kolona+=yyleng;}
"TRUE"      {printf("TRUE\n");kolona+=yyleng;}
"FALSE"     {printf("FALSE\n");kolona+=yyleng;}
"SKIP"      {printf("SKIP\n");kolona+=yyleng;}
"READ"      {printf("READ\n");kolona+=yyleng;}
"LET"       {printf("LET\n");kolona+=yyleng;}
":="        {printf(":=\n");kolona+=yyleng;}
"RETURN"    {printf("RETURN\n");kolona+=yyleng;}
"IN"        {printf("IN\n");kolona+=yyleng;}
"END"       {printf("END\n");kolona+=yyleng;}

\"[^"\n]*\"     {printf("STRING: vrijednost %s\n", yytext); kolona+=yyleng;}    //regularni izrazi
0|[1-9][0-9]*   {printf("INT: vrijednost %s\n", yytext);kolona+=yyleng;}    //int 
(0X|0x)[1-9A-Fa-f][0-9A-Fa-f]*   {printf("HEX: vrijednost %s\n", yytext); kolona+=yyleng;} //heksadekadni
[0-9]+\.[0-9]* {printf("DOUBLE: vrijednost %s\n", yytext); kolona+=yyleng;} //double
[0-9]+\.[0-9]*[eE][+-]?[0-9]+ {printf("DOUBLE sa exp: vrijednost %s\n", yytext); kolona+=yyleng;} //double sa exp
[a-zA-Z_][a-zA-Z0-9_]{0,29}  {printf("IDENTIFIKATOR: vrijednost %s\n", yytext); kolona+=yyleng;} //identifikator 

"<="        {printf("operator: <=\n"); kolona+=yyleng;} //operatori
"<"         {printf("operator: <\n"); kolona+=yyleng;}
">="        {printf("operator: >=\n"); kolona+=yyleng;}
">"         {printf("operator: >\n"); kolona+=yyleng;}
"=="        {printf("operator: ==\n"); kolona+=yyleng;}
"!="        {printf("operator: !=\n"); kolona+=yyleng;}
"&&"        {printf("operator: &&\n"); kolona+=yyleng;}
"||"        {printf("operator: ||\n"); kolona+=yyleng;}

"+"     {printf("unarni op: +\n"); kolona+=yyleng;} //unarni operatori
"-"     {printf("unarni op: -\n"); kolona+=yyleng;} 
"*"     {printf("unarni op: *\n"); kolona+=yyleng;} 
"/"     {printf("unarni op: /\n"); kolona+=yyleng;} 
"="     {printf("unarni op: =\n"); kolona+=yyleng;} 

";"     {printf(";\n"); kolona+=yyleng;}//znaci interpunkcije
"."     {printf(".\n"); kolona+=yyleng;}
"!"     {printf("!\n"); kolona+=yyleng;}
","     {printf(",\n"); kolona+=yyleng;}
"("     {printf("(\n"); kolona+=yyleng;}
")"     {printf(")\n"); kolona+=yyleng;}

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

\"[^"\n]*$ { 
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

int main(){
    yylex();
    return 0;
}