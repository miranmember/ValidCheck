#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef struct StackStruct
{
    char*    darr;  /* pointer to dynamic array  */
    int     size;  /* amount of space allocated */
    int     inUse; /* top of stack indicator
		   - counts how many values are on the stack   */
} Stack;

void init (Stack* s)
{
    s->size = 4;
    s->darr = (char*) malloc ( sizeof (char) * s->size );
    s->inUse  = 0;
}

void push (Stack* s, char val,int debugMode)
{

    if(s->size <= s->inUse) {
        int oldSize = s->size;
        s->size = s->size + 4;
        if(debugMode == TRUE)
            printf("The stack has grown from %d to %d, and atotalof %dvalues were copied into the larger array.\n", oldSize, s->size, s->inUse);
    }
    s->darr[s->inUse] = val;
    s->inUse = s->inUse + 1;
}

int isEmpty (Stack* s)
{
    if ( s->inUse == 0)
        return TRUE;
    else
        return FALSE;
}

char top (Stack* s)
{
    return (  s->darr[s->inUse-1] );
}

void pop (Stack* s)
{
    s->inUse = s->inUse - 1;
}

void reset (Stack* s)
{
    free(s->darr);
    s->inUse = 0;
    s->size = 4;
}

void ValidCheck(char *S, int *G, int debugMode){
    Stack ST;
    init (&ST);
    char L, T, V = 'N', A[8];
    int C = 0, E = 0;
    for(int i = 0; i < strlen(S); i++) {
        L = tolower(S[i]);
        T = tolower(top(&ST));
        if (L == 'a' || L == 'b' || L == 'c' || L == 'd') {
            if(debugMode == TRUE)
                printf("Character %c was popped from the stack.\n", L);
            push(&ST, L, debugMode);
            V = 'Y';
        } else if(L == 'm') {
            if (T == 'a') {
                A[C] = T;
                C++;
                if(debugMode == TRUE)
                    printf("Character %c was popped from the stack.\n", top(&ST));
                pop(&ST);
            } else {
                break;
            }
        } else if(L == 'n') {
            if (T == 'b') {
                A[C] = T;
                C++;
                if(debugMode == TRUE)
                    printf("Character %c was popped from the stack.\n", top(&ST));
                pop(&ST);
            } else {
                break;
            }
        } else if(L == 'o') {
            if (T == 'c') {
                A[C] = T;
                C++;
                if(debugMode == TRUE)
                    printf("Character %c was popped from the stack.\n", top(&ST));
                pop(&ST);
            } else {
                break;
            }
        } else if(L == 'p') {
            if (T == 'd') {
                A[C] = T;
                C++;
                if(debugMode == TRUE)
                    printf("Character %c was popped from the stack.\n", top(&ST));
                pop(&ST);
            } else {
                break;
            }
        }
    }
    if (V == 'Y' && isEmpty(&ST)) {
        for (int i = C - 1; i >= 0; i--)
            printf("%c", A[i]);
        printf(" ");
    }
    else {
        *G = *G + 1;
    }
    reset(&ST);
    memset(A, 0, sizeof(A));
}

int main(int argc, char *argv[]) {
    int option;
    int debugMode = FALSE;
    option = getopt(argc, argv, ":d");
    if(option == 'd'){
        debugMode = TRUE;
    }
    char input[300];
    while (1) {
        printf ("\nEnter input to check or q to quit\n");
        fgets(input, 300, stdin);

        int i = 0;
        while (input[i] != '\n' && input[i] != '\0') {
            i++;
        }
        input[i] = '\0';

        if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) )
            break;
        printf ("%s\n", input);

        char delim[] = " ";
        char *ptr = strtok(input, delim);
        int j = 0 ;

        char *wordList[15];

        while (ptr != NULL) {
            wordList[j] = (char*) malloc(sizeof(char) * strlen(ptr));
            strcpy(wordList[j], ptr);
            ptr = strtok(NULL, delim);
            j++;
        }
        int V = 0, m;
        for(m = 0; m < j; m++) {
            ValidCheck(wordList[m], &V, debugMode);
        }
        printf("\n");
        if(V == m) {
            printf("No valid word decoded.\n");
        }
    }
    printf ("\nGoodbye\n");
    return 0;
}