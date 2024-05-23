#ifndef LOCATION_H
#define LOCATION_H

typedef struct YYLTYPE {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED 1

#endif