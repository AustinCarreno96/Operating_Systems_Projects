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

    int c = 0;

    // Checking number of cmd args
    // if(argc != 2) {
    //     printf("Incorrect arguments given.");
    //     exit(0);
    // }
    // cmd = "dir";
    while(flag) {
        printf("Type Ctrl-C to exit\n");
        scanf("%s", cmd);

        if(strcmp(cmd, "cd") == 0) {
            system("cd");

        } else if (strcmp(cmd, "dir") == 0) {
            system("ls");

        } else if (strcmp(cmd, "type") == 0) {
            system("cat");

        } else if (strcmp(cmd, "del") == 0) {
            system("rm");

        } else if (strcmp(cmd, "ren") == 0) {
            system("mv");

        } else if (strcmp(cmd, "copy") == 0) {
            system("cp");

        } else {
            printf("Command Not Found\n");
            flag = false;
            exit(0);
        }
    }

    return 0;
}