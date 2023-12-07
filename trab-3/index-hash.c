#include <stdio.h>
#include <stdlib.h>
#include "file-reader.h"
#include "hash.h"

int main(int argc, char **argv){
    if(argc < 2){
        printf("Diretorio nao informado\n");	
    }

    char *dir = argv[1];
    char path[100], filename[50], filepath[200];

    sprintf(path, "%s/files.txt", dir);

    FILE *file_names = fopen(path, "r");

    while(!feof(file_names)){
        fscanf(file_names, "%s\n", filename);
        sprintf(filepath, "%s/files/%s", path, filename);

        FILE * data = fopen(filepath, "r");

    }

    fclose(file_names);
}