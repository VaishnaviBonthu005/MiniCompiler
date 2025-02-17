);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 10
#define MAX_LINES 100
#define MAX_LENGTH 500

char *keywords[MAX_KEYWORDS] = {"int", "float", "if", "else", "while", "return", "for", "do", "char", "void"};

int isKeyword(char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void analyzeLexically(char *code) {
    char ch, buffer[50];
    int i = 0;

    while (*code) {
        ch = *code;
        
        if (isalpha(ch)) { 
            buffer[i++] = ch;
            while (isalnum(*(++code))) 
                buffer[i++] = *code;
            buffer[i] = '\0';
            i = 0;
            
            if (isKeyword(buffer))
                printf("[Keyword] %s\n", buffer);
            else
                printf("[Identifier] %s\n", buffer);
        } 
        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while (isdigit(*(++code))) 
                buffer[i++] = *code;
            buffer[i] = '\0';
            i = 0;
            printf("[Number] %s\n", buffer);
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>') {
            printf("[Operator] %c\n", ch);
        } 
        else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',') {
            printf("[Symbol] %c\n", ch);
        }
        code++;
    }
}

int main() {
    char code[MAX_LINES][MAX_LENGTH];
    char fullCode[MAX_LINES * MAX_LENGTH] = "";
    int line = 0;

    printf("Enter your source code (Press Enter after each line, type 'END' to finish input):\n");

    while (line < MAX_LINES) {
        fgets(code[line], MAX_LENGTH, stdin);
        if (strncmp(code[line], "END", 3) == 0)
            break;  
        strcat(fullCode, code[line]);
        line++;
    }

    printf("\nLexical Analysis Output:\n");
    analyzeLexically(fullCode);
    return 0;
}
