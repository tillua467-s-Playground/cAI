#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOUN 1
#define VERB 2
#define ADJ 3
#define ADV 4
#define PRON 5
#define OBJ 6
#define DET 7
#define PREP 8
#define CONJ 9
#define INTERJ 10

char *dictDir = "data/dictionary.txt";

int wordType(char *word);
void addNewWord(char *word, int type);

#endif