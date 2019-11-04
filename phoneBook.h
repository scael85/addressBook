#ifndef ADDRESSBOOK_PHONEBOOK_H
#define ADDRESSBOOK_PHONEBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// MACRO
#define STRING_DIM 30           //dimension for nouns and emails
#define NUM_DIM 15              //dimension for telephone number
#define UPDATE 1                //add 1 contact

//static type to take into account the increment of contacts when the function is called
static int currentSize = 0;     //Num of record currently allocated. The phonebook is empty

/* Enumeration to define the type of possible contacts */
typedef enum {WORK, FAMILY, FRIENDS, OTHERS} TypeOfContact;

/* Structure of the contacts */
typedef struct {
    char name[STRING_DIM];                      //name
    char surname[STRING_DIM];                   //surname
    char telephoneNumber[NUM_DIM];              //telephone number
    char emailAddress[STRING_DIM];              //email address
    TypeOfContact typeOfContact;                //type of the contact
} Contact;

/* Functions */
int start();
void addContact(Contact *);
void addName(Contact *);
void addSurname(Contact *);
void addTelephoneNum(Contact *);
void addEmail(Contact *);
void addType(Contact *);
void deleteContact(Contact *);
void searchContact(Contact *);
Contact * initializeDynamicVector();
Contact * increaseContactVector(Contact *);
void printContact(Contact *);
void editContact(Contact *);

#endif //ADDRESSBOOK_PHONEBOOK_H
