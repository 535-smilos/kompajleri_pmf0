#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greske.h"
#include "BCF.h"

int errNo=0;

void stampajGresku(char* text, int yylineno, int kolona){
    for(int i=0;i<strlen(text);i++){
        printf("%c", text[i]);
    }
    printf("Linija: %d --- Kolona: %d\n", yylineno, kolona);
}

void invalidanIdentifikator(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidna duzina identifikatora! ", yylineno, kolona); 
}

void invalidanHex1(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format hex broja! ", yylineno, kolona);
}

void invalidanHex2(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format hex broja! ", yylineno, kolona);
}

void invalidanDouble1(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format double broja! ", yylineno, kolona);
}

void invalidanDExp1(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format double broja sa exp! ", yylineno, kolona);
}

void invalidanDExp2(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format double broja sa exp! ", yylineno, kolona);    
}
void invalidanString(char* text, int yylineno, int kolona){
    errNo++;
    printf("%s ", text);
    stampajGresku("Invalidan format stringa! ", yylineno, kolona);
}

void invalidanKarakter(char ch, int yylineno, int kolona){
    errNo++;
    stampajGresku("Invalidan karakter! ", yylineno, kolona);
}

void invalidanKomentar(int yylineno, int kolona){
    errNo++;
    stampajGresku("Nepravilno zatvoren komentar! ", yylineno, kolona);
}

