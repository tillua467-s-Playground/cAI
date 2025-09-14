#include "../headers/dictionary.h"

int wordType(char *word)
{
    int type = -1;
    FILE *fp = fopen(dictDir, "r");
    size_t sbuff = 512;
    char *buff = malloc(sbuff);
    char *tmpbuff = NULL;

    while (fgets(buff, sbuff, fp))
    {
        size_t len = strlen(buff);
        if (len > 0 && buff[len - 1] != '\n' && !feof(fp))
        {
            size_t rest = 0;
            int c;
            long pos = ftell(fp);

            while ((c = fgetc(fp)) != '\n' && c != EOF)
                rest++;

            fseek(fp, pos, SEEK_SET);
            buff = realloc(buff, len + rest + 2);
            fgets(buff + len, rest + 2, fp);
        }

        tmpbuff = malloc(strlen(buff) + 1);
        strcpy(tmpbuff, buff);

        char *token = strtok(buff, ":");
        if (token && strcasecmp(token, word) == 0)
        {
            char *str = strrchr(tmpbuff, ':');
            if (str)
            {
                str++;
                while (*str == ' ')
                    str++;

                type = atoi(str);
            }
        }
    }

    free(buff);
    free(tmpbuff);
    fclose(fp);
    return type;
}

void addNewWord(char *word, int type)
{
    if (type < 1 || type > 10)
    {
        printf("The Value Is Out Of Bound!\n");
        return;
    }

    if (wordType(word) != -1)
    {
        printf("The Word Already Exist!\n");
        return;
    }
    char *buff;
    int size = snprintf(NULL, 0, "\n%s: %d", word, type);
    buff = malloc(size + 1);
    snprintf(buff, size + 1, "\n%s: %d", word, type);

    FILE *fp = fopen(dictDir, "a");
    fprintf(fp, buff);
    fclose(fp);
}