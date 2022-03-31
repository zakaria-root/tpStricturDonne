#include <stdio.h>
#include <string.h>
#include "contactTable.h"
#include <stdlib.h>

contactTable_t *ajouterContact(contactTable_t *table, contact_t contact1)
{
    char c = contact1.nom[0];
    int index = c - 65;

    contactList_t *ct = creeContact(contact1);
    if (table->table[index]->nbrContact == 0)
    {
        table->table[index] = ct;
        table->table[index]->nbrContact = table->table[index]->nbrContact + 1;
    }
    else
    {
        contactList_t *temp = table->table[index];
        if ((strcmp(temp->contact.nom, contact1.nom) != -1))
        {
            ct->suive = temp;
            temp->pred = ct;
            temp = ct;
            table->table[index]->nbrContact = table->table[index]->nbrContact + 1;
            return table;
        }

        while (temp != NULL && (strcmp(temp->contact.nom, contact1.nom) == -1))
            temp = temp->suive;
        if (temp != NULL)
        {
            ct->suive = temp->suive;
            if (temp->suive != NULL)
                temp->suive = temp->suive->pred = ct;
            ct->pred = temp;
            temp->suive = ct;
        }
        table->table[index]->nbrContact = table->table[index]->nbrContact + 1;
    }
    return table;
}

contactList_t *supprimerContact(contactTable_t *table, contact_t c1)
{
    char c = c1.nom[0];
    int index = c - 65;

    if (table->table[index]->nbrContact == 0)
    {
        printf("le tableau est vide \n");
    }
    else
    {
        contactList_t *temp = table->table[index];
        if ((strcmp(temp->contact.nom, c1.nom) == 0))
        {
            contactList_t *temp1 = temp;
            temp = temp->suive;
            temp->pred = NULL;
            free(temp1);
            table->table[index]->nbrContact = table->table[index]->nbrContact - 1;
            return table;
        }

        while (temp->suive != NULL && (strcmp(temp->contact.nom, c1.nom) != 0))
        {
            temp = temp->suive;
        }
        if (temp->suive != NULL)
        {
            contactList_t *temp1 = temp;
            temp->pred->suive = temp->suive;
            if (temp->suive != NULL)
                temp->suive->pred = temp->pred;

            free(temp1);
            table->table[index]->nbrContact = table->table[index]->nbrContact - 1;
        }
    }
    return table;
}

contactList_t *creeContact(contact_t contact)
{
    contactList_t *c;
    c = (contactList_t *)malloc(sizeof(contactList_t));
    strcpy(c->contact.nom, contact.nom);
    strcpy(c->contact.tel, contact.tel);
    strcpy(c->contact.email, contact.email);
    c->suive = NULL;
    c->pred = NULL;
    return c;
}

void afficherContact(contactTable_t *table)
{
    for (int index = 0; index < table->nbGrpContact; index++)
    {
        printf("table[%d] : \n", index);
        contactList_t *temp = table->table[index];
        while (temp != NULL)
        {
            printf("nom :%s - tel:%s - email:%s --> ", temp->contact.nom, temp->contact.tel, temp->contact.email);
        }
    }
}

contactList_t *chercherContact(contactTable_t *table, contact_t contact1)
{
    contactList_t *contact = NULL;
    for (int index = 0; index < table->nbGrpContact; index++)
    {
        contactList_t *temp = table->table[index];
        while (temp != NULL && (strcmp(temp->contact.nom, contact1.nom) != 0))
            temp = temp->suive;
        if (temp != NULL)
            contact = creeContact(temp->contact);
        return contact;
    }
}

contactTable_t *modifierContact(contactTable_t *table, contact_t c1, contact_t c2)
{
    char c = c1.nom[0];
    int index = c - 65;

    if (table->table[index]->nbrContact == 0)
    {
        printf("le tableau est vide \n");
    }
    else
    {
        contactList_t *temp = table->table[index];
        
        while (temp != NULL && (strcmp(temp->contact.nom, c1.nom) != 0))
        {
            temp = temp->suive;
        }
        if (temp != NULL)
        temp->contact = c2;
    }
    return table;
}