#include "../headers/phraser.h"

long wordCount(FILE *filestream, char *filename)
{
    long count = 0;
    int inWord = 0;
    char c;
    filestream = fopen(filename, "r");
    while ((c = fgetc(filestream)) != EOF)
    {
        if (isspace(c))
            inWord = 0;
        else if (!inWord)
        {
            inWord = 1;
            count++;
        }
    }
    fclose(filestream);

    return count;
}

// allocate enough memory the array before calling this function (wordCount * sizeof(char *))
void wordOrgnizer(FILE *fp, char *filename, char **arr)
{
    fp = fopen(filename, "r");
    size_t sbufffp = 1028;
    char *bufffp = malloc(sbufffp);
    int index = 0;

    while (fgets(bufffp, sbufffp, fp))
    {
        size_t len = strlen(bufffp);
        if (len > 0 && bufffp[len - 1] != '\n' && !feof(fp))
        {
            size_t rest = 0;
            int c;
            long pos = ftell(fp);

            while ((c = fgetc(fp)) != '\n' && c != EOF)
                rest++;

            fseek(fp, pos, SEEK_SET);
            bufffp = realloc(bufffp, len + rest + 2);
            fgets(bufffp + len, rest + 2, fp);
        }

        char *token = strtok(bufffp, " \t\r\n");
        while (token)
        {
            arr[index] = strdup(token);
            index++;
            token = strtok(NULL, " \t\r\n");
        }
    }
    free(bufffp);
    fclose(fp);
}

void freeArr(char **arr, int members)
{
    int i = 0;
    while (i < members)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}