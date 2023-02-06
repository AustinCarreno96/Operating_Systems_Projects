#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// TODO: Seems that final variables are not holding full Strings. Check buffer and tokens later
int main(int argc, char* argv[]) {
    // Variables
    char cmd[20];
    char* command = NULL;
    char* arg1 = NULL;
    char* arg2 = NULL;
    char* buffer[3] = {NULL, NULL, NULL};
    char* final_command;

    while(true) {
        int size = 0;
        int index = 0;

        // Getting User Input
        printf("Type Ctrl-C to exit\n");
        scanf("%[^\n]%*c", cmd);

        // Tokenizing String
        char* token = strtok(cmd, " ");
        while(token) {
            buffer[index] = (char*)malloc(sizeof(token));
            strcpy(buffer[index], token);
            token = strtok(NULL, " ");
            index++;
        }

        // Adding tokens to correct variable
        if(buffer[0] != NULL) {
            command = (char*)malloc(sizeof(buffer[0]));
            strcpy(command, buffer[0]);
        }
        if(buffer[1] != NULL) {
            arg1 = (char*)malloc(sizeof(buffer[1]));
            strcpy(arg1, buffer[1]);
        }

        if(buffer[2] != NULL) {
            arg2 = (char*)malloc(sizeof(buffer[2]));
            strcpy(arg2, buffer[2]);
        }

        printf("Buffer[0]: %s\tsize: %lu\nBuffer[1]: %s\tsize: %lu\nBuffer[2]: %s\tsize: %lu\narg1: %s\tsize: %lu\narg2: %s\tsize: %lu\n\n", buffer[0], sizeof(buffer[0]), buffer[1], sizeof(buffer[1]), buffer[2], sizeof(buffer[2]), arg1, sizeof(arg1), arg2, sizeof(arg2));
        // Finding correct command to run
        // cd
        if(strcmp(cmd, "cd") == 0) {
            size_t size = sizeof(arg1) + sizeof(arg2) + 115;
            final_command = (char*)malloc(size);

            if(arg1 == NULL) {
                printf("Too few arguments.\n");
            } else if(arg2 != NULL) {
                printf("Too many arguments.\n");
            } else {
                snprintf(final_command, size, "cd %s", arg1);
            }

            system(final_command);

        // dir
        } else if(strcmp(cmd, "dir") == 0) {
            size_t size = sizeof(arg1) + 20;
            final_command = (char*)malloc(size);

            if(arg2 != NULL) {
                printf("Too many arguments.\n");
            } else if (arg1 != NULL) {
                snprintf(final_command, size, "ls %s", arg1);
            } else {
                snprintf(final_command, 3, "ls");
            }

            system(final_command);

        // type
        } else if(strcmp(cmd, "type") == 0) {
            size_t size = sizeof(arg1) + 100;
            final_command = (char*)malloc(size);

            if(arg1 == NULL) {
                printf("Too few arguments.\n");
            } else if(arg2 != NULL) {
                printf("Too many arguments.\n");
            } else {
                snprintf(final_command, size, "cat %s", arg1);
            }

            system(final_command);

        // del
        } else if(strcmp(command, "del") == 0) {
            size_t size = sizeof(arg1) + sizeof(arg2) + 4;
            final_command = (char*)malloc(size);

            if(arg1 == NULL) {
                printf("Too few arguments.\n");
            } else if(arg2 == NULL) {
                snprintf(final_command, size, "rm %s", arg1);
            } else {
                snprintf(final_command, size, "rm %s %s", arg1, arg2);
            }

            system(final_command);

        // ren
        } else if(strcmp(cmd, "ren") == 0) {
            size_t size = sizeof(arg1) + sizeof(arg2) + 5;
            final_command = (char*)malloc(size);

            if(arg1 == NULL || arg2 == NULL) {
                printf("Too few arguments.\n");
            } else {
                snprintf(final_command, size, "mv %s %s", arg1, arg2);
            }

            system(final_command);

        // copy
        } else if(strcmp(cmd, "copy") == 0) {
            size_t size = sizeof(arg1) + sizeof(arg2) + 5;
            final_command = (char*)malloc(size);

            if(arg1 == NULL || arg2 == NULL) {
                printf("Too few arguments.\n");
            } else {
                snprintf(final_command, size, "cp %s %s", arg1, arg2);
            }

            system(final_command);

        } else {
            printf("Command Not Found\n");
        }

        command = NULL;
        arg1 = NULL;
        arg2 = NULL;
        buffer[0] = NULL;
        buffer[1] = NULL;
        buffer[2] = NULL;
    }

    return 0;
}