#ifndef BCF_H
#define BCF_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct BCF_Node{
    char* label;
    int num_Children;
    struct BCF_Node** children;
} BCF_Node;

BCF_Node* createNode(char* label, int num_ch, ...);
void print_tree(BCF_Node* tree, int lvl);
void free_tree(BCF_Node* tree);
#endif //BCF_H