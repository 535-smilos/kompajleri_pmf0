#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greske.h"


void stampajGresku(char* text, int yylineno, int kolona){
    for(int i=0;i<strlen(text);i++){
        printf("%c", text[i]);
    }
    printf("Linija: %d --- Kolona: %d\n", yylineno, kolona);
}

void invalidanIdentifikator(char* text, int yylineno, int kolona){
    stampajGresku("Invalidna duzina identifikatora!\n", yylineno, kolona); 
}

void invalidanHex1(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format hex broja!\n", yylineno, kolona);
}

void invalidanHex2(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format hex broja!\n", yylineno, kolona);
}

void invalidanDouble1(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format double broja!\n", yylineno, kolona);
}

void invalidanDExp1(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format double broja sa exp!\n", yylineno, kolona);
}

void invalidanDExp2(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format double broja sa exp!\n", yylineno, kolona);    
}
void invalidanString(char* text, int yylineno, int kolona){
    stampajGresku("Invalidan format stringa!\n", yylineno, kolona);
}

void invalidanKarakter(char ch, int yylineno, int kolona){
    stampajGresku("Invalidan karakter!\n", yylineno, kolona);
}

