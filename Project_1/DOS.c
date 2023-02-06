#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]) {
    bool flag = true;
    
    // Args from user
    char cmd[100];
    char* arg1;
    char* arg2;
    char buffer[1024];

    int c = 0;

    while(flag) {
        printf("Type Ctrl-C to exit\n");
        scanf("%s", cmd);
        char* token = strtok(cmd, " ");

        if(strcmp(cmd, "cd") == 0) {
            system("cd");

        } else if(strcmp(cmd, "dir") == 0) {
            system("ls");

        } else if(strcmp(cmd, "type") == 0) {
            system("cat");

        } else if(strcmp(cmd, "del") == 0) {
            token = strtok(NULL, " ");
            while(token) {
            snprintf(buffer, sizeof(buffer), "rm %s", token);
            token = strtok(NULL, " ");
            }
            printf("%s", buffer);
            //printf("%s", token);
            //snprintf(buffer, sizeof(buffer), "rm %s", token);
            system(buffer);

        } else if(strcmp(cmd, "ren") == 0) {
            system("mv");

        } else if(strcmp(cmd, "copy") == 0) {
            system("cp");

        } else {
            printf("Command Not Found\n");
            flag = false;
            exit(0);
        }
    }

    return 0;
}