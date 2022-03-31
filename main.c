#include <stdio.h>
#include <stdlib.h>
#include "contactTableImplementation.h"

int main(int argc, char const *argv[])
{
    contact_t c1;
    contactTable_t *table;
    table->nbGrpContact = 26;
    char c;
    do{
    printf("1) ajouter un contact\n");
    printf("2) supprimer un contact\n");
    printf("3) modifier un contact\n");
    printf("4) rechercher un contact\n");
    printf("5) sortie de programme\n");
    printf("enter un nimero :");
    scanf("%c", &c1);
    switch (c)
    {
    case 1:
        system("clear");
        printf("entre le nom d'un contact : ");
        scanf("%s", c1.nom);
        printf("entre le tel d'un contact : ");
        scanf("%s", c1.tel);
        printf("entre le email d'un contact : ");
        scanf("%s", c1.email);
        table = ajouterContact(table, c1);
        afficherContact(table);
        getchar();
        break;

    case 2:
        system("clear");
        printf("entre le nom d'un contact : ");
        scanf("%s", c1.nom);
        printf("entre le tel d'un contact : ");
        scanf("%s", c1.tel);
        printf("entre le email d'un contact : ");
        scanf("%s", c1.email);
        table = supprimerContact(table, c1);
        afficherContact(table);
        getchar();
        break;

    case 3:
        system("clear");
        printf("entre le nom d'un contact : ");
        scanf("%s", c1.nom);
        printf("entre le tel d'un contact : ");
        scanf("%s", c1.tel);
        printf("entre le email d'un contact : ");
        scanf("%s", c1.email);
        table = modifierContact(table, c1);
        afficherContact(table);
        getchar();
        break;

    case 4:
        system("clear");
        contactList_t *contact = NULL;
        printf("entre le nom d'un contact : ");
        scanf("%s", c1.nom);
        printf("entre le tel d'un contact : ");
        scanf("%s", c1.tel);
        printf("entre le email d'un contact : ");
        scanf("%s", c1.email);
        contact = chercherContact(table, c1);
        printf("nom :%s - tel:%s - email:%s --> ", contact->contact.nom, contact->contact.tel, contact->contact.email);
        getchar();
        break;
 case 5:
 printf("merci >>>>");
return 0;
 break;
    default:
        break;
    }
    }while (1);



    return 0;
}
