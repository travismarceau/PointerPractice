#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dog_years(int);
void human_years(int);

typedef struct
{
    int age;
    char *type;
    char *name;
    void (*years_func)(void *, void *, int);
} animal;

void years(void *ani, void *nam, int num)
{
    if (strcmp(ani, "human") == 0)
    {
        printf("\n%s is %d in dog years.\n", nam, num * 7);
    }
    else
    {
        printf("\n%s is not human.\n", nam);
    }
}

int main(void)
{
    printf("\nHello world\n\n");
    animal **trav;
    animal ***john;

    //-----------------------------------
    trav = malloc(sizeof(animal *));
    *trav = malloc(sizeof(animal));
    (*trav)->type = malloc(sizeof(char));
    (*trav)->name = malloc(sizeof(char));

    strcpy((*trav)->type, "human");
    strcpy((*trav)->name, "travis");
    (*trav)->age = 31;
    (*trav)->years_func = &years;
    //-----------------------------------

    //-----------------------------------
    john = malloc(sizeof(animal *));
    *john = malloc(sizeof(animal *));
    **john = malloc(sizeof(animal));
    (**john)->type = malloc(sizeof(char));
    (**john)->name = malloc(sizeof(char));

    strcpy((**john)->type, "person");
    strcpy((**john)->name, "john");
    (**john)->age = 32;
    (**john)->years_func = &years;
    //-----------------------------------

    int a = 0;
    a++;

    printf("a: %d\n", a);
    printf("\n%s is a %d year old %s\n", (*trav)->name, (*trav)->age, (*trav)->type);
    printf("\n%c is a %d year old %c\n", *(*trav)->name, (*trav)->age, *(*trav)->type);
    printf("\n%p is a %d year old %p\n", &(*trav)->name, (*trav)->age, &(*trav)->type);

    printf("\n%s is a %d year old %s\n", (**john)->name, (**john)->age, (**john)->type);
    printf("\n%c is a %d year old %c\n", *(**john)->name, (**john)->age, *(**john)->type);
    printf("\n%p is a %p year old %p\n", &(*john), &(**john)->age, &(*john));
    printf("\n%p is a %d year old %p\n", &(**john)->name, (**john)->age, &(**john)->type);

    (*trav)->years_func((*trav)->type, (*trav)->name, (*trav)->age);
    (**john)->years_func((**john)->type, (**john)->name, (**john)->age);
}