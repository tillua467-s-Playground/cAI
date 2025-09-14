#ifndef NODE_H
#define NODE_H

#include <string.h>

#define MAXNWORD 20

typedef struct Node
{
    char *word;
    char *wordNext[MAXNWORD];
    int countN;
} Node;

Node genrateNode(char **dataarr, int arrMem, char *word);

#endif