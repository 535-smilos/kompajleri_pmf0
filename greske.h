#ifndef GRESKE_H
#define GRESKE_H

int errNo;
void stampajGresku(char* text, int yylineno, int kolona);
void invalidanIdentifikator(char* text, int yylineno, int kolona);
void invalidanHex1(char* text, int yylineno, int kolona);
void invalidanHex2(char* text, int yylineno, int kolona);
void invalidanDouble1(char* text, int yylineno, int kolona);
void invalidanDExp1(char* text, int yylineno, int kolona);
void invalidanDExp2(char* text, int yylineno, int kolona);
void invalidanString(char* text, int yylineno, int kolona);
void invalidanKarakter(char ch, int yylineno, int kolona);
void invalidanKomentar(int yylineno, int kolona);

#endif
