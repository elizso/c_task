#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char input_string[BUFSIZ]; //BUFSIZ is a constant defined by the system.
    char target_string[BUFSIZ];
    int input_string_size = 0;

    printf ("Please enter a line of text, max %lu characters:\n", sizeof(input_string));

    //read a text string from the keyboard and remove the line break at the end
    char *p;
    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {

        if ((p = strchr(input_string, '\n')) != NULL)
        *p = '\0';  // the \n will be replaced by the NULL character
        input_string_size = strlen(input_string);   //find the length of the text string (\0 included)
    }

        //process the input string
    int i=0, j=0;
    int space_count = 0;

    while (i < input_string_size) {

        /*COMPLETE THE CODE HERE*/
        char check = input_string[i];
        printf("%c\n", check);
        if (check != 32){
            if (space_count > 0){
                char temp = check;
                check = '-';
                j += space_count - 1;
                space_count = 0;
                if (strlen(target_string) == 0){
                    strcpy(target_string, &check);
                }else{
                    strcat(target_string, &check);
                }
                check = temp;
                printf("space to -\n");
            }
            if (check >= 97 && check <=122){
                check -= 32;
                printf("capitalise \n");
            } 
            if (strlen(target_string) == 0){
                strcpy(target_string, &check);
            }else{
                strcat(target_string, &check);
            }
        }else{
            space_count++; 
            printf("space count \n");
        }
        
        i++;
        printf("%s %d\n", target_string, i);

    }      
    i-=j;
    target_string[i] = '\0'; //add NULL character to end the string

    printf("\nNo. of characters: %lu\n", strlen(input_string));

    /*COMPLETE THE CODE*/
    //printf("No. of words: %d\n\n", __________ );

    printf("Output string: %s \n",target_string);
    printf("No. of characters now: %lu\n\n", strlen(target_string));

    system("pause");
    return 0;
}