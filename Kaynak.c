#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int stackboyutchar = 10;
int stackboyutint = 10;
char* charstack;
int* intstack;
int topchar = -1;
int topint = -1;


int ischarFull() {
    if (topchar >= (stackboyutchar - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int isintFull() {
    if (topint >= (stackboyutint - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

void pushchar(int item) {
    if (ischarFull()) {
        char* charstack2;
        stackboyutchar = stackboyutchar * 2;
        charstack2 = (char*)malloc(sizeof(char) * stackboyutchar);

        for (int i = 0; i <= topchar; i++) {
            charstack2[i] = charstack[i];
        }
        free(charstack);
        charstack = charstack2;
    }
    topchar++;
    charstack[topchar] = (char)item;
}

void pushint(int item) {
    if (isintFull()) {
        int* intstack2;
        stackboyutint = stackboyutint * 2;
        intstack2 = (int*)malloc(sizeof(int) * stackboyutint);

        for (int i = 0; i <= topint; i++) {
            intstack2[i] = intstack[i];
        }
        free(intstack);
        intstack = intstack2;
    }
    topint++;
    intstack[topint] = (int)item;
}

void printcharstack() {
    printf("\nCharStack:");
    for (int i = 0; i <= topchar; i++) {
        printf("\n %c", charstack[i]);
    }
    printf("\n");
}

void printintStack() {
    printf("\nIntStack:");
    for (int i = 0; i <= topint; i++) {
        printf("\n %c", intstack[i]);
    }
    printf("\n");
}

int main() {

    charstack = (char*)malloc(sizeof(char) * stackboyutchar);
    intstack = (int*)malloc(sizeof(int) * stackboyutint);


    int dizi[100];

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        dizi[i] = rand() % 208 + 48;
        printf("sayi karsiligi: %d ve ascii karsiligi: %c\n", dizi[i], dizi[i]);
    }

    for (int i = 0; i < 100; i++)
    {
        if (dizi[i] >= 97 && dizi[i] <= 122)
        {
            pushchar(dizi[i]);
        }
        else
        {
            pushint(dizi[i]);
        }
    }

    printcharstack();
    printintStack();

    int degisken[100];
    for (int i = 0; i < 100; i++) {
        pushchar(degisken[i]);
        degisken[i] = intstack[i];
        intstack[i] = charstack[i];
        charstack[i] = degisken[i];
    }

    printf("\n ***************** yer degistirme *****************\n");

    printcharstack();
    printintStack();

    return 0;

}