#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* BT14 Me on the Guest List? */
int main()
{    
    FILE *fp;
    fp = fopen("names.txt", "r");
    char names[200][100];
        
    /* Get each name into names[] and replace \n with \0 (NULL) */
    int i=0;
    char *read;
    while((fgets(names[i],sizeof(names[i]), fp)) != NULL) {        
        /*****your code here*****/
        if ((read = strchr(names[i], '\n')) != NULL){
            *read = '\0';
        }
        i++;
    }
    fclose(fp);

    /*read keyword from the keyboard and remove the line break at the end*/
    printf("Name? ");
    char keyword[30];
    char *p;    
    if (fgets(keyword, sizeof(keyword), stdin) != NULL) {
        if ((p = strchr(keyword, '\n')) != NULL)
            *p = '\0';
    }

        
    /*perform a sequential search and output the line number if found*/
    int lines[200];
    int line = 0;
    for (int i = 0; i < 200; ++i ){
        if (strcmp(keyword, names[i])==0){
            lines[line++] = i + 1;
        }
    }
    /*****your code here*****/
    printf("number of lines: %d\n", line);
    if (line > 0){
        printf("%s is found in line:", keyword);
        for (int i = 0; i < line; i++){
            if (i+1 == line){
                printf(" %d\n", lines[i]);
            }else{
                printf(" %d,", lines[i]);
            }
        }
    }else{
        printf("%s not found\n", keyword);
    }

    //system("pause");
    return 0;
}