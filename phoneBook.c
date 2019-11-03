#include "phoneBook.h"

//functions & comments

/** START THE PROGRAM **/
int start(){
    int option = 0, contactID;

    // Initialization of the dynamic vector
    Contact* contactVector = initializeDynamicVector();

    printf("\nHello! Welcome to your Phone Book!");
    printf("\nWhat do you want to do?\nPlease select an option from the menu: ");

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
                contactVector = increaseContactVector(contactVector);   //function to add 1 space to the dynamic vector
                addContact(&contactVector[currentSize-1]);              //procedure to add a contact
                printContact(&contactVector[currentSize-1]);            //print of the new contact
                break;
            case 2:
                printf("\nWhich contact do you want to modify?");       //ask to the user which contact modify
                scanf("%d", &contactID);
                contactID = contactID -1;                               //generate the contactID to identify the contact
                editContact(&contactVector[contactID]);                 //procedure to edit a contact
                printContact(&contactVector[contactID]);                //print of the modified contact
                break;
            case 3:
                //deleteContact(&contact);
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

/** DINAMIC  VECTOR
 * This function allocates the space for a given type of structure. Ask the user how many contacts
 * wants and generates a dynamic vector. It checks if the memory is well allocated and prints the memory address,
 * otherwise it gives an error message and the function is terminated.
 * @return a pointer with the generated memory address
 */
Contact * initializeDynamicVector(){

    Contact *contactVector = NULL;

    contactVector = (Contact *) calloc(currentSize, sizeof(Contact));
    if (contactVector == NULL) {
        printf("\nFailed to allocate memory");
        exit(-1);
    } else
        printf("\nThe memory address of your phonebook is %p", contactVector);
    printf("\n");

    return contactVector;
}

/** INCREASE THE SPACE IN THE ARRAY OF CONTACTS
 * Through the realloc, this function allows to increase by one the size of the dynamic vector
 * in order to add a new contact which will be stored in the new position created at the end of the array.
 * @param contactVector is the starting dynamic vector
 * @return the starting dynamic vector increased by one
 */
Contact * increaseContactVector(Contact* contactVector){

    currentSize = currentSize + UPDATE;                 //update the num of available allocations

    contactVector = (Contact *) realloc(contactVector, currentSize* sizeof(Contact));
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
/** ADD NEW CONTACT
 * This procedure stores in a structure all the acquisitions of the fields of a contact (using individual
 * and dedicated procedures) and returns the contact by printing it.
 * @param contact is a pointer to a structure
 */
void addContact(Contact *contact){

    //routine do get and check the name
    addName(contact);

    //routine do get and check the surname
    addSurname(contact);

    //routine do get and check the telephone number
    addTelephoneNum(contact);

    //routine to add email address
    addEmail(contact);

    //routine to add the type of contact
    addType(contact);
}

/** ADD A NAME
 * This procedure allows to add a non empty name. It checks there are no numbers in it.
 * @param contact is a pointer to a field of the structure where the string for the name is contained
 */
void addName(Contact *contact){

    int i, correctName = 0;

    do{
        printf("\nInsert the name (no numbers allow):");
        scanf("%[^\n]s", contact->name);
        getchar();

        for(i = 0 ; i <= strlen(contact->name), contact->name[i] != '\0'; ++i){
            if(!(isdigit(contact->name[i])) && (contact->name[0] != ' ')){
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
        scanf("%[^\n]s", contact->surname);
        getchar();

        for(i = 0 ; i <= strlen(contact->surname), contact->surname[i] != '\0'; ++i){
            if(!(isdigit(contact->surname[i])) && (contact->surname[0] != ' ')){
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
        scanf("%[^\n]s", contact->telephoneNumber);
        getchar();

        for(i = 0 ; i <= strlen(contact->telephoneNumber), contact->telephoneNumber[i] != '\0'; ++i){
            if (contact->telephoneNumber[i] < '0' || contact->telephoneNumber[i] > '9' ||
                (contact->telephoneNumber[0] == ' ')){
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

        scanf("%[^\n]s", contact->emailAddress);
        getchar();
        result = strstr(contact->emailAddress, "@");
        sizeEmail = strlen(contact->emailAddress);
        pos = result - contact->emailAddress + 1;
        last3 = &contact->emailAddress[sizeEmail - 3];
        last4 = &contact->emailAddress[sizeEmail - 4];

        if(contact->emailAddress[0] != '@' && contact->emailAddress[0] != ' ' && isalnum(contact->emailAddress[pos + 1])
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

    printf("\nInsert what type of contact is:\ntype 0 for WORK,\ntype 1 for FAMILY,\ntype 2 for FRIENDS,"
           "\ntype 3 for OTHERS");
    printf("\nSelect an option: ");
    scanf("%d", &contact->typeOfContact);
    getchar();
}

/** VISUALIZED A CONTACT
 *  This procedure allows to print clearly all contact details
 * @param contact passes the structure where the data is stored
 */
void printContact(Contact *contact){

    printf("\nName     : %s", contact->name);
    printf("\nSurname  : %s", contact->surname);
    printf("\nMobile   : %s", contact->telephoneNumber);
    printf("\nEmail    : %s", contact->emailAddress);
    printf("\nType     : %d (0=WORK, 1=FAMILY, 2=FRIENDS, 3=OTHERS).", contact->typeOfContact);
    printf("\n");
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
    getchar();

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
}

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
void deleteContact(Contact * contact){

    int contactID, option, type;

    printf("\n");
    printf("\nWhat do you want to delete? (press 0 to exit)");
    printf("\n1) all the phonebook");
    printf("\n2) a contact with a certain id");
    printf("\n3) all contacts with a certain name or surname ");
    printf("\n4) a type of contacts");
    scanf("%d", &option);

    switch(option){
        case 1:
            if(contact != NULL)
                free(contact);
            printf("All phonebook has been deleted.");
            contact = initializeDynamicVector();
            break;
        case 2:
            printf("\nEnter the ID number of the contact you want to delete: ");
            scanf("%d", &contactID);
            contact[contactID-1] = contact[contactID];
            printf("The contact with ID number %d has been deleted.", contactID);
            contact[contactID-1] = contact[contactID];
            contact = (Contact *) realloc(contact, (currentSize - 1)* sizeof(Contact));
            if ( contact == NULL ){
                printf("\nFailed to allocate memory");
                exit(-1);
            }
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

/*8) Aggiungere alle funzionalità del programma la ricerca dei contatti offrendo le seguenti possibilità:
- ricerca mediante nome (o parte del nome)
- ricerca mediante cognome (o parte del cognome)
- ricerca mediante mail (o parte del mail)
- ricerca mediante numero
- ricerca mediante categoria
void searchContact(Contact*){

}*/
