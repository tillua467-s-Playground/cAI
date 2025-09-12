#ifndef PHARSER_H
#define PHARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long wordCount(FILE *filestream, char *filename);
// allocate enough memory the array before calling this function (wordCount * sizeof(char *))
void wordOrgnizer(FILE *fp, char *filename, char **arr);
void freeArr(char **arr, int members);

#endif