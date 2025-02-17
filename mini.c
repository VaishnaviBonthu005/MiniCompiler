#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 10

char *keywords[MAX_KEYWORDS] = {"int", "float", "if", "else", "while", "return", "for", "do", "char", "void"};

int isKeyword(char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void analyzeLexically(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char ch, buffer[50];
    int i = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) { 
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(file))) 
                buffer[i++] = ch;
            buffer[i] = '\0';
            i = 0;
            
            if (isKeyword(buffer))
                printf("[Keyword] %s\n", buffer);
            else
                printf("[Identifier] %s\n", buffer);
            ungetc(ch, file);
        } 
        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(file))) 
                buffer[i++] = ch;
            buffer[i] = '\0';
            i = 0;
            printf("[Number] %s\n", buffer);
            ungetc(ch, file);
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>') {
            printf("[Operator] %c\n", ch);
        } 
        else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',') {
            printf("[Symbol] %c\n", ch);
        }
    }

    fclose(file);
}

int main() {
    char filename[30];
    printf("Enter source code filename: ");
    scanf("%s", filename);
    
    analyzeLexically(filename);
    return 0;
}
