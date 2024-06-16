#include "BCF.h"

BCF_Node* createNode(char* label, int num_ch, ...){
    BCF_Node* new=malloc(sizeof(BCF_Node));
    new->label=strdup(label);
    new->num_Children=num_ch;
    new->children=malloc(sizeof(BCF_Node*)*num_ch);

    va_list args;
    va_start(args, num_ch);
    for(int i=0;i<num_ch;++i){
        new->children[i]=va_arg(args, BCF_Node*);
    }
    va_end(args);

    return new;
}

void print_tree(BCF_Node* tree, int lvl){
    for(int i=0;i<lvl;++i){
        printf("  ");
    }
    printf("%s\n", tree->label);
    for(int i=0;i<tree->num_Children;++i){
        print_tree(tree->children[i], lvl+1);
    }
}

void free_tree(BCF_Node* tree){
    for(int i=0;i<tree->num_Children;++i){
        free_tree(tree->children[i]);
    }

    free(tree->label);
    free(tree->children);
    free(tree);
}