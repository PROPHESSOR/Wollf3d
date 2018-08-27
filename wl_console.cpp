/**
 *Copyright (c) 2018 PROPHESSOR
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "wl_def.h"

/**
 * @returns: 0 - not found; >0 - end position
 */
int compareToken(const char *token, const char *command, int position = 0) {
    int pos = 0;
    while(token[pos] != '\0') {
        if(command[position + pos] == '\0') {
            printf("[compareToken]: Token is bigger than command!\n");
            return 0;
        }
        if(token[pos] != command[position + pos]) {
            printf("[compareToken]: Token ism't equal! Token symbol: %c; Command symbol: %c; Position: %i\n", token[pos], command[pos], pos);
            return 0;
        }
        pos++;
    }

    return pos;
}

void OpenConsole(char *buffer) {
    CenterWindow(30, 8);
    PrintY += 6;
    US_Print(" $  ");
    VW_UpdateScreen();
    US_LineInput (px, py, buffer, NULL, true, 100, 0);
    VW_UpdateScreen();
    printf("String: %s\n", buffer);
    printf("Number: %d\n", atoi (buffer));
}

void PrintConsole(const char *text) {
    CenterWindow(30, 8);
    PrintY += 6;
    char txt[50];
    sprintf(txt, " >> %s", text);
    US_Print(txt);
    IN_Ack();
}

void InterpretConsole(const char *buffer, int pos = 0) {
    if(pos = compareToken("help", buffer)) {
        printf("Is a help command\n");
        PrintConsole("It's help");
    } else
    if(pos = compareToken("exit", buffer)) {
        Quit(NULL);
    }
}

void ToggleConsole(void) {
    printf("ToggleConsole %d\n", rand());
    
    while(1) {
        char cmd[100] = "";
        OpenConsole(cmd);
        printf("Out string: %s\n", cmd);
        if(cmd[0] == '\0') {
            printf("Exit\n");
            break;
        }
        InterpretConsole(cmd);
    }
}