#ifndef __CONTACTTABLE
#define  __CONTACTTABLE
#include "contactList.h"

typedef struct contactTable
{
    contactList_t *table[20];
    int nbGrpContact;
}contactTable_t;

contactTable_t* ajouterContact(contactTable_t *, contact_t );
contactList_t *creeContact(contact_t);
contactList_t *chercherContact(contactTable_t *, contact_t);
contactTable_t *supprimerContact(contactTable_t *, contact_t);
contactTable_t *modifierContact(contactTable_t *, contact_t);
void afficherContact(contactTable_t* );
#endif 