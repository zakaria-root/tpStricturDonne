#include <stdio.h>
#include <string.h>
#include "contactTable.h"
#include <stdlib.h>

contactTable_t* ajouterConatact(contactTable_t *table, contact_t contact1)
{
    char c = contact1.nom[0];
    int index  = c - 65;
    
    contactList_t *ct = creeContact(contact1);
    if (table->table[index]->nbrContact)
    {
        table->table[index] = ct;
    }
    else
    {
        contactList_t *temp = table->table[index];
        if ((strcmp(temp->contact.nom, contact1.nom) != -1))
        {
            ct->suive = temp;
            temp->pred = ct;
            temp = ct;
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


void afficherContact(contactTable_t *table){
    for (int index = 0; index < table->nbGrpContact; index++)
    {
        contactList_t * temp = table->table[index];
        while (temp != NULL)
        {
            printf("nom :%s - tel:%s - email:%s --> ",temp->contact.nom,temp->contact.tel,temp->contact.email );
        }
        
    }
    
}

