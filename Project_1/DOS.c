#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Prototypes
void dosSystem(char* cmd, char* buffer[3]);
void infiniteLoop();

int main(int argc, char* argv[]) {
    infiniteLoop();
    return 0;
}

void infiniteLoop() {
    // Variables
    char cmd[20];
    char* buffer[3] = {NULL, NULL, NULL};

    while(true) {
        int size = 0;
        int index = 0;

        // Getting User Input
        printf("Type Ctrl-C to exit\n");
        scanf("%[^\n]%*c", cmd);

        // Switching backslashes to forward slashes
        for(int i = 0; i < sizeof(cmd); i++) {
            if(cmd[i] == '\\') {
                cmd[i] = '/';
            }
        }
        
        // Tokenizing String
        char* token = strtok(cmd, " ");
        while(token != NULL) {
            buffer[index] = (char*)malloc(sizeof(token));
            strcpy(buffer[index], token);
            token = strtok(NULL, " ");
            index++;
        }

        dosSystem(cmd, buffer);

        buffer[0] = NULL;
        buffer[1] = NULL;
        buffer[2] = NULL;
    }// end while loop
}

void dosSystem(char* cmd, char* buffer[3]) {
    char* command;
    // Finding correct command to run
    // cd
    if(strcmp(cmd, "cd") == 0) {
        size_t size = sizeof(buffer[1]) + sizeof(buffer[2]) + 115;
        command = (char*)malloc(size);

        if(buffer[1] == NULL) {
            printf("Too few arguments.\n");
        } else if(buffer[2] != NULL) {
            printf("Too many arguments.\n");
        } else {
            snprintf(command, size, "cd %s", buffer[1]);
        }

        system(command);
    // dir
    } else if(strcmp(buffer[0], "dir") == 0) {
        size_t size = sizeof(buffer[1]) + 20;
        command = (char*)malloc(size);

        if(buffer[2] != NULL) {
            printf("Too many arguments.\n");
        } else if (buffer[1] != NULL) {
            snprintf(command, size, "ls %s", buffer[1]);
        } else {
            snprintf(command, 3, "ls");
        }

        system(command);
    // type
    } else if(strcmp(buffer[0], "type") == 0) {
        size_t size = sizeof(buffer[1]) + 100;
        command = (char*)malloc(size);

        if(buffer[1] == NULL) {
            printf("Too few arguments.\n");
        } else if(buffer[2] != NULL) {
            printf("Too many arguments.\n");
        } else {
            snprintf(command, size, "cat %s", buffer[1]);
        }

        system(command);
    // del
    } else if(strcmp(buffer[0], "del") == 0) {
        size_t size = sizeof(buffer[1]) + sizeof(buffer[2]) + 4;
        command = (char*)malloc(size);

        if(buffer[1] == NULL) {
            printf("Too few arguments.\n");
        } else if(buffer[2] == NULL) {
            snprintf(command, size, "rm %s", buffer[1]);
        } else {
            snprintf(command, size, "rm %s %s", buffer[1], buffer[2]);
        }

        system(command);
    // ren
    } else if(strcmp(cmd, "ren") == 0) {
        size_t size = sizeof(buffer[1]) + sizeof(buffer[2]) + 5;
        command = (char*)malloc(size);

        if(buffer[1] == NULL || buffer[2] == NULL) {
            printf("Too few arguments.\n");
        } else {
            snprintf(command, size, "mv %s %s", buffer[1], buffer[2]);
        }

        system(command);
    // copy
    } else if(strcmp(cmd, "copy") == 0) {
        size_t size = sizeof(buffer[1]) + sizeof(buffer[2]) + 5;
        command = (char*)malloc(size);

        if(buffer[1] == NULL || buffer[2] == NULL) {
            printf("Too few arguments.\n");
        } else {
            snprintf(command, size, "cp %s %s", buffer[1], buffer[2]);
        }

        system(command);
    } else {
        printf("Command Not Found\n");
    }
}