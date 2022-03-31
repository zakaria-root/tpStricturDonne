#ifndef __CONTACTTABLE
#define  __CONTACTTABLE
#include "contactList.h"
typedef struct contactTable
{
    contactList_t *table[20];
    int nbGrpContact;
}contactTable_t;

contactTable_t* ajouterConatact(contactTable_t *, contact_t );
contactList_t *creeContact(contact_t);
void afficherContact(contactTable_t* );
#endif 