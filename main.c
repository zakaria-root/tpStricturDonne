#include<stdio.h>
#include<stdlib.h>
#include "contactTableImplementation.h"



int main(int argc, char const *argv[])
{
    contact_t c1;
    contactTable_t *table;
    printf("entre le nom d'un contact : ");
    scanf("%s",c1.nom);
    printf("entre le tel d'un contact : ");
    scanf("%s",c1.tel);
    printf("entre le email d'un contact : ");
    scanf("%s",c1.email);

    table = ajouterConatact(table, c1);
    afficherContact(table);




    return 0;
}
