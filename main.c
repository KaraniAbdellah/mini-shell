#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int *argc, char **argv) {
    
    while (1) {
        pid_t proc = fork();
        if (proc == 0) {
            printf("My_Shell$ ");
            // Get The Input
            char *input = (char *) malloc(sizeof(char) * 100); // suppose are number of characters 100
            scanf("%[^\n]", input);
            
            // Store Input At In Matrix
            char *token = strtok(input, " ");
            char **args = (char **) malloc(sizeof(char *) * 10); // 10 is number of words in input
            for (int i = 0; i < 10; i++) args[i] = NULL;
            int index = 0;
            while(token != NULL) {
                args[index] = (char *) malloc(sizeof(char));
                strcpy(args[index], token);
                token = strtok(NULL, " ");
                index++;
            }
            // Execute The Programm
            execvp(args[0], args);
        } else {
            wait(NULL);
        }
    }
    
    return 0;
}


// execlp("cd", "cd", "tt", NULL);


/*
    // Test
    printf("inputs = ");
    for (int i = 0; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
*/


// two commands [ ls & cd ];







// Another Functions
// execlp("ls", "ls", "-l", NULL);
// execl("\bin\ls", "ls", "-l", NULL);














