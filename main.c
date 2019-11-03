/*****************************************************************************
**                                                                          **
**                                PHONEBOOK                                 **
**                                                                          **
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// MACROs
#define STRING_DIM 30       //dimension for nouns and emails
#define NUM_DIM 15          //dimension for telephone number

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
void addContact(Contact *);
void addName(Contact *);
void addSurname(Contact *);
void addTelephoneNum(Contact *);
void addEmail(Contact *);
void addType(Contact *);
//void removeContact(Contact *);
//void searchContact(Contact *);
Contact * initializeDynamicVector(int);
Contact * increaseContactVector(Contact *, int);
void printContact(Contact *);
void editContact(Contact *);

int main() {

    static int currentAlloc = 0;               //Num of record currently allocated
    int choice;

    // Inizializza l'array dinamico allocando lo spazio per un contatto.
    Contact * contactVector = initializeDynamicVector(currentAlloc);

    printf("\nHello! Welcome to your Phone Book!");

    int option = 0, i;

    printf("What do you want to do?\nPlease select an option from the menu: ");

    for(; ;)
    {

        printf("\n1 - Add contact"
               "\n2 - Edit contact"
               "\n3 - Remove contact"
               "\n4 - Search contact"
               "\n0 - Exit\n\n"
               "Select an option: ");
        scanf("%d", &option);
        getchar();

        switch(option)
        {
            case 1:
                addContact(&contactVector[i]);
                break;
            case 2:
                editContact(&contactVector[i]);
            case 3:
                //removeContact(&contact);
                break;
            case 4:
                //searchContact(&contact);
                break;
            case 0:
                printf("\nThanks for using this phonebook! Bye!");
                return 0;
            default:
                printf("\nInvalid option selected...");
                break;
        }
        printf("\n");
    }
}

/** ADD NEW CONTACT
 * This procedure stores in a structure all the acquisitions of the fields of a contact (using individual
 * and dedicated procedures) and returns the contact by printing it.
 * @param contact is a pointer to a structure
 */
void addContact(Contact *contactVector){

    int update;
    printf("\nHow many contacts do you want to create?");
    scanf("%d", &update);

    contactVector = increaseContactVector(contactVector, update);

     int i, flagCorrectName = 0, flagCorrectSurname = 0, flagCorrectNum = 0;

    //routine do get and check the name
    addName(&contact[i]);
    /*
    do{
        printf("\nInsert your name (no numbers allow):");
        scanf("%[^\n]s", contact->name);
        getchar();

        for(i = 0 ; i <= strlen(contact->name), contact->name[i] != '\0'; ++i){
            if(!(isdigit(contact->name[i])) && (contact->name[0] != ' ')){
                flagCorrectName = 1;}
            else{
                flagCorrectName = 0;
                printf("\nThe name has a number in it or it's empty. FIX IT.");
                break;}
        }
    }while(flagCorrectName == 0);*/

    //routine do get and check the surname
    addSurname(&contact[i]);

    /*do{
        printf("\nInsert your surname (no numbers allow):");
        scanf("%[^\n]s", contact->surname);
        getchar();

        for(i = 0 ; i <= strlen(contact->surname),contact->surname[i] != '\0'; ++i){
            if(!(isdigit(contact->surname[i])) && (contact->name[0] != ' ')){
                flagCorrectSurname = 1;}
            else{
                flagCorrectSurname = 0;
                printf("\nThe surname has a number in it or it's empty. FIX IT.");
                break;}
        }
    }while(flagCorrectSurname == 0);*/

    //routine do get and check the telephone number
    addTelephoneNum(&contact[i]);

    /*do{
        printf("\nInsert your telephone number (no symbols or letters allow):");
        scanf("%[^\n]s", contact->telephoneNumber);
        getchar();

        for(i = 0 ; i <= strlen(contact->telephoneNumber), contact->telephoneNumber[i] != '\0'; ++i){
            if (contact->telephoneNumber[i] < '0' || contact->telephoneNumber[i] > '9' || (contact->telephoneNumber[0] == ' ')){
                printf("\nThe number has a char in it or it's empty. FIX IT.");
                flagCorrectNum = 1;
                break;}
            else
                flagCorrectNum = 0;
        }
    }while(flagCorrectNum == 1);*/

    //routine to add email address
    addEmail(&contact[i]);

    /*char *last3 = NULL, *last4 = NULL, *afterAt = NULL;
    int sizeEmail = 0, atPos = 0, flagCorrectEmail = 0;

    do {
        printf("\nAdd email in the format example@example.com or .it:");
        scanf("%[^\n]s", contact->emailAddress);
        getchar();

        afterAt = strstr(contact->emailAddress, "@");      //extract the part of the email from @ on (es @gmail.com)
        sizeEmail = strlen(contact->emailAddress);         //gives the length of the email
        atPos = afterAt - contact->emailAddress + 1;       //gives the position of the index associated to the @
        last3 = &contact->emailAddress[sizeEmail - 3];     //store the last 3 char (es .it)
        last4 = &contact->emailAddress[sizeEmail - 4];     //store the last 4 char (es .com)

         Controls: 1) email can't start with @ or a space; 2) after the @ there will be a alphanumeric char;
         * 3) email must end with .it or .com
         * If controls are passed the variable flagCorrectEmail becomes 1 and che cycle ends. Otherwise we have a
         * warning message and the user has to reinsert the email.
        if(contact->emailAddress[0] != '@' && contact->emailAddress[0] != ' ' && isalnum(contact->emailAddress[atPos + 1])
           && ((strcmp(last3, ".it") == 0) || (strcmp(last4, ".com")== 0))){
            flagCorrectEmail=1;}
        else{
            printf("\nWarning! The email is not valid. Please, insert again.");
            flagCorrectEmail = 0;
        }

    }while(flagCorrectEmail == 0);*/

    //routine to add the type of contact
    addType(&contact[i]);

    /*do{
        printf("\nInsert what type of contacts is:\ntype 0 for WORK,\ntype 1 for FAMILY,\ntype 2 for FRIENDS,"
               "\ntype 3 for OTHERS");
        printf("\nSelect an option: ");
        scanf("%d", contact->typeOfContact);

        if(contact->typeOfContact >= 4){
            printf("\nInvalid choice. Please insert again.");
        }

    }while(contact->typeOfContact >= 4);*/

    printContact(&contact[i]);

 }

 /** ADD A NAME
  * This procedure allows to add a non empty name. It checks there are no numbers in it.
  * @param contact is a pointer to a field of the structure where the string for the name is contained
  */
void addName(Contact *contact){

    int i, correctName = 0;

    do{
        printf("\nInsert the name (no numbers allow):");
        scanf("%[^\n]s", contact[i].name);
        getchar();

        for(i = 0 ; i <= strlen(contact[i].name), contact[i].name[i] != '\0'; ++i){
            if(!(isdigit(contact[i].name[i])) && (contact[i].name[0] != ' ')){
                correctName = 1;}
            else{
                correctName = 0;
                printf("\nWarning...");
                printf("\nthe name has number or it's empty. Please insert again.\n");
                break;}
        }

    }while(correctName == 0);

}

 /** ADD A SURNAME
  * This procedure allows to add a non empty surname. It checks there are no numbers in it.
  * @param contact is a pointer to a field of the structure where the string for the surname is contained
  */
void addSurname(Contact *contact){

    int i, correctSurname = 0;

    do{
        printf("\nInsert the surname (no numbers allow):");
        scanf("%[^\n]s", contact[i].surname);
        getchar();

        for(i = 0 ; i <= strlen(contact[i].surname), contact[i].surname[i] != '\0'; ++i){
            if(!(isdigit(contact[i].surname[i])) && (contact[i].surname[0] != ' ')){
                correctSurname = 1;}
            else{
                correctSurname = 0;
                printf("\nWarning...");
                printf("\nthe surname has number or it's empty. Please insert again.\n");
                break;}
        }

    }while(correctSurname == 0);

}

/** ADD MOBILE
 *  This procedure allows to add a non empty phone num. It checks there are no letters and symbols.
 * @param contact is a pointer to a field of the structure where the string for the phone num is contained
 */
void addTelephoneNum(Contact *contact){

    int i, correctNum = 0;

    do{
        printf("\nInsert telephone number (no symbols or letters allow):");
        scanf("%[^\n]s", contact[i].telephoneNumber);
        getchar();

        for(i = 0 ; i <= strlen(contact[i].telephoneNumber), contact[i].telephoneNumber[i] != '\0'; ++i){
            if (contact[i].telephoneNumber[i] < '0' || contact[i].telephoneNumber[i] > '9' ||
                (contact[i].telephoneNumber[0] == ' ')){
                printf("\nWarning...");
                printf("\nthe number has a char or it's empty. Please insert again.\n");
                correctNum = 1;
                break;}
            else
                correctNum = 0;
        }

    }while(correctNum == 1);

}

/** ADD EMAIL ADDRESS
 *  This procedure allows to add a non empty email and checks if there is at least one char before the @,
 *  at least one char after the @ and that the domain ended with .com or .it.
 * @param contact is a pointer to a field of the structure where the string for the email is contained
 */
void addEmail(Contact *contact){

    char *last3 = NULL, *last4 = NULL, *result = NULL;
    int sizeEmail = 0, pos = 0, correctEmail = 0, i;

    do {
        printf("\nInsert the email in the format example@example.com or .it:");

        scanf("%[^\n]s", contact[i].emailAddress);
        getchar();
        result = strstr(contact[i].emailAddress, "@");
        sizeEmail = strlen(contact[i].emailAddress);
        pos = result - contact[i].emailAddress + 1;
        last3 = &contact[i].emailAddress[sizeEmail - 3];
        last4 = &contact[i].emailAddress[sizeEmail - 4];

        if(contact[i].emailAddress[0] != '@' && contact[i].emailAddress[0] != ' ' && isalnum(contact[i].emailAddress[pos + 1])
           && ((strcmp(last3, ".it") == 0) || (strcmp(last4, ".com")== 0))){
            correctEmail=1;}
        else{
            printf("\nWarning...");
            printf("\nemail is not valid. Please insert again.\n");
            correctEmail = 0;
        }

    }while(correctEmail == 0);

}

/** ADD TYPE OF CONTACT
 * This procedure allows to add type option for the created contact.
 * Check that the user types an option among those allowed.
 * @param contact is a pointer to a field of the structure where the enum for the type is contained
 */
void addType(Contact *contact){

    int i;

    do{
        printf("\nInsert what type of contact is:\ntype 0 for WORK,\ntype 1 for FAMILY,\ntype 2 for FRIENDS,"
               "\ntype 3 for OTHERS");
        printf("\nSelect an option: ");
        scanf("%d", contact[i].typeOfContact);

        if(contact[i].typeOfContact >= 4){
            printf("\nInvalid choice. Please insert again.");
        }

    }while(contact[i].typeOfContact >= 4);

}

/** VISUALIZED A CONTACT
 *  This procedure allows to print clearly all contact details
 * @param contact passes the structure where the data is stored
 */
void printContact(Contact *contact){

    int i, size;

    for(i = 0 ; i < size ; i++)
    {
        printf("\nID       : %d", i+1);
        printf("\nName     : %s", contact[i].name);
        printf("\nSurname  : %s", contact[i].name);
        printf("\nMobile   : %s", contact[i].telephoneNumber);
        printf("\nEmail    : %s", contact[i].emailAddress);
        printf("\nType     : %d (0=WORK, 1=FAMILY, 2=FRIENDS, 3=OTHERS).", contact[i].typeOfContact);
        printf("\n");
    }
}

/** EDIT CONTACT
 *  This procedure print the information about a contact and ask to the user which field he/she wants to edit
 *  I use a switch case to set the choices the user has. Depending on the user's choice,
 *  a specific subroutine will be started to modify the required field.
 * @param contact passes the structure where the data is saved
 */
void editContact(Contact *contact){

    printContact(contact);
    printf("\n");

    int choice;
    printf("\nWhich field do you want edit? (press 0 to go back)");
    printf("\n1) name");
    printf("\n2) surname");
    printf("\n3) telephone number");
    printf("\n4) email");
    printf("\n5) type of the contact");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nEnter the new name of the contact:");
            addName(contact);
            break;
        case 2:
            printf("\nEnter the new surname of the contact:");
            addSurname(contact);
            break;
        case 3:
            printf("\nEnter the new mobile number of the contact:");
            addTelephoneNum(contact);
            break;
        case 4:
            printf("\nEnter the new email");
            addEmail(contact);
            break;
        case 5:
            printf("\nEnter the new type of the contact");
            addType(contact);
            break;
        case 0:
            printf("\nBack to the main menu");
            return;
        default:
            printf("\nInvalid selection...");
            break;
    }

    printContact(contact);
  }

/** DINAMIC  VECTOR
 * This function allocates the space for a given type of structure. Ask the user how many contacts
 * wants and generates a dynamic vector. It checks if the memory is well allocated and prints the memory address,
 * otherwise it gives an error message and the function is terminated.
 * @return a pointer with the generated memory address
 */
Contact * initializeDynamicVector(int n){

    Contact *contact = NULL;

    contact = (Contact *)malloc(n * sizeof(Contact));
    if ( contact == NULL ){
        printf("\nFailed to allocate memory");
        exit(-1);
    }
    else
        printf("\nThe memory address of your phonebook is %p", contact);
        printf("\n");

    return contact;
}

Contact * increaseContactVector(Contact* contactVector, update){

    static int currentAlloc = 0;

    currentAlloc =+ update;
    contactVector = (Contact *) realloc (contactVector, currentAlloc* sizeof(Contact));
    if ( contactVector == NULL ){
        printf("\nFailed to allocate memory");
        exit(-1);
    }

    return contactVector;
}

/* 6) Implementare la funzione di inserimento seguendo la logica seguente: passo il contatto,
 *  aumento lo spazio del vettore dinamico per contenere un nuovo elemento e a questo punto inserisco
 *  il nuovo contatto seguendo l'ordine alfabetico. Si possono presentare due casi: inserimento in coda,
 *  inserimento non in coda. Se in coda non dovremo far altro che inserire il contatto nell'ultima (e nuova)
 *  posizione, altrimenti una volta trovato il contatto successivo in ordine alfabetico dovremo far scorrere
 *  tutti i contatti di una posizione e inserire il nuovo contatto nella corretta posizione. Al termine delle
 *  operazioni ricordarsi di tenere traccia dell'eventuale cambio di valore del puntatore al vettore dinamico.*/

/*  7) Implementare la funzione di eliminazione offrendo le seguenti possibilità:
 *  In tutti i casi dovremo sempre stare attenti a modificare lo spazio occupato dal vettore,
 *  se ad esempio abbiamo un vettore di 3 contatti A, B e C e dobbiamo eliminare B sposteremo C in B e
 *  riallocheremo lo spazio eliminando un elemento (l'ultimo).
 *  Ricordarsi sempre di restituire il puntatore al vettore dinamico.*/
/** DELETE FUCTION
 * This function allows to delete several things from the phonebook: all contacts; contact with a certain ID;
 * all contacts with a certain name or surname; all contacts of certain type.
 *
 * @param contact
 */
 /*
void delete(){

    printf("\n");
    int option;
    printf("\nWhat do you want to delete? (press 0 to exit)");
    printf("\n1) all the phonebook");
    printf("\n2) a contact with a certain id");
    printf("\n3) all contacts with a certain name or surname ");
    printf("\n4) a type of contacts");
    scanf("%d", &option);

    switch(option){
        case 1:

            printf("All phonebook has been deleted.");
            break;
        case 2:

            printf("The contact with %dID has been delated.", i+1);
            break;
        case 3:

            printf("All contacts named %s have been delated.", .....);
            break;
        case 4:

            printf("All contacts of type %d have been delated.", ....);
            break;
        case 0:
            printf("\nBack to the menu");
            return;
        default:
            printf("\nInvalid option selected...");
            break;
    }

}*/


