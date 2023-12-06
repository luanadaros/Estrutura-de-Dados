#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("Diretorio nao informado\n");	
    }

    char *dir = argv[1];
    char path[100];

    sprintf(path, "%s/files.txt", dir);

    FILE *file_names = fopen(path, "r");

}