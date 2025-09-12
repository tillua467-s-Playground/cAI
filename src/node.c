#include "../headers/node.h"

Node genrateNode(char **dataarr, int arrMem, char *word)
{
    Node node = {0};
    int i = 0;
    int count = 0;
    node.word = strdup(word);
    while (i < arrMem)
    {
        if (count >= MAXNWORD)
            break;
        if (strcmp(dataarr[i], node.word) == 0)
        {
            if (strcmp(dataarr[i + 1], node.word) == 0)
            {
                i++;
                continue;
            }
            node.wordNext[count] = strdup(dataarr[i + 1]);
            count++;
        }
        i++;
    }

    return node;
}