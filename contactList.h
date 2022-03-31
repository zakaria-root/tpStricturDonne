#ifndef __CONTACTLIST
#define  __CONTACTLIST
#include "contact.h"
typedef struct contactList
{
    contact_t contact;
    struct contactList *suive;
    struct contactList *pred;
    int nbrContact;
}contactList_t;


#endif 
