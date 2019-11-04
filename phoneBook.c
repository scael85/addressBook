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
                printContact(&contactVector[currentSize-1]);            //procedure to print the new contact
                break;
            case 2:
                printf("\nWhich contact do you want to modify?");       //ask to the user which contact modify
                scanf("%d", &contactID);
                contactID = contactID -1;                               //generate the contactID to identify the contact
                editContact(&contactVector[contactID]);                 //procedure to edit a contact
                printContact(&contactVector[contactID]);                //print of the modified contact
                break;
            case 3:
                deleteContact(contactVector);                           //procedure to delete contacts
                break;
            case 4:
                searchContact(contactVector);                           //procedure to search contacts
                break;
            case 0:
                printf("\nThanks for using this phonebook! Bye!");
                if(contactVector != NULL)
                    free(contactVector);                                //free the allocated memory
                return 0;                                               //end of the program
            default:
                printf("\nInvalid option selected...");
                break;
        }
        printf("\n");
    }
}

/** DINAMIC  VECTOR
 * This function allocates in memory a number of bytes equal to a defined size and returns a pointer
 * of the type declared (in this case struct type) that points to a generic memory address.
 * It checks if the memory is well allocated and prints the memory address, otherwise it gives
 * an error message and the function is terminated.
 * @return a pointer with the generated memory address
 */
Contact * initializeDynamicVector(){

    // Initialization of the dynamic vector
    Contact *contactVector = NULL;

    // malloc function: the memory is created but not initialized
    contactVector = (Contact *) malloc(currentSize* sizeof(Contact));
    if (contactVector == NULL) {                                                 //check that memory is well allocated
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

/** ADD NEW CONTACT
 * This procedure stores in a structure all the acquisitions of the fields of a contact (using individual
 * and dedicated procedures).
 * @param contact is a pointer to a structure
 *
 * PROBLEM: all new contacts are stored at the end of the dynamic vector and not in alphabetic order
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

    int i, flagCorrectName = 0;

    do{
        // first ask to the user the name
        printf("\nInsert the name (no numbers allow):");
        scanf("%[^\n]s", contact->name);
        getchar();

        // then check if it respect the condition to not be empty and to not have numbers
        for(i = 0 ; i <= strlen(contact->name), contact->name[i] != '\0'; ++i){
            if(!(isdigit(contact->name[i])) && (contact->name[0] != ' ')){
                flagCorrectName = 1;}
            else{
                flagCorrectName = 0;
                printf("\nWarning...");
                printf("\nthe name has number or it's empty. Please insert again.\n");
                break;}
        }

    }while(flagCorrectName == 0);

}

/** ADD A SURNAME
 * This procedure allows to add a non empty surname. It checks there are no numbers in it.
 * @param contact is a pointer to a field of the structure where the string for the surname is contained
 */
void addSurname(Contact *contact){

    int i, flagCorrectSurname = 0;

    do{
        // first ask to the user the surname
        printf("\nInsert the surname (no numbers allow):");
        scanf("%[^\n]s", contact->surname);
        getchar();

        // then check if it respect the condition to not be empty and to not have numbers
        for(i = 0 ; i <= strlen(contact->surname), contact->surname[i] != '\0'; ++i){
            if(!(isdigit(contact->surname[i])) && (contact->surname[0] != ' ')){
                flagCorrectSurname = 1;}
            else{
                flagCorrectSurname = 0;
                printf("\nWarning...");
                printf("\nthe surname has number or it's empty. Please insert again.\n");
                break;}
        }

    }while(flagCorrectSurname == 0);

}

/** ADD MOBILE
 *  This procedure allows to add a non empty phone num. It checks there are no letters and symbols.
 * @param contact is a pointer to a field of the structure where the string for the phone num is contained
 */
void addTelephoneNum(Contact *contact){

    int i, flagCorrectNum = 0;

    do{
        // first ask to the user the mobile
        printf("\nInsert telephone number (no symbols or letters allow):");
        scanf("%[^\n]s", contact->telephoneNumber);
        getchar();

        // then check if it respect the condition to not be empty and to not have letters or symbols
        for(i = 0 ; i <= strlen(contact->telephoneNumber), contact->telephoneNumber[i] != '\0'; ++i){
            if (contact->telephoneNumber[i] < '0' || contact->telephoneNumber[i] > '9' ||
                (contact->telephoneNumber[0] == ' ')){
                printf("\nWarning...");
                printf("\nthe number has a char or it's empty. Please insert again.\n");
                flagCorrectNum = 1;
                break;}
            else
                flagCorrectNum = 0;
        }

    }while(flagCorrectNum == 1);

}

/** ADD EMAIL ADDRESS
 *  This procedure allows to add a non empty email and checks if there is at least one char before the @,
 *  at least one char after the @ and that the domain ended with .com or .it.
 * @param contact is a pointer to a field of the structure where the string for the email is contained
 *
 * I don't know why the procedure doesn't return an error if there is no @. In my mind I'm controlling it, but
 * at the end it doesn't work.
 */
void addEmail(Contact *contact){

    char *last3 = NULL, *last4 = NULL, *afterAt = NULL;
    int sizeEmail = 0, atPos = 0, flagCorrectEmail = 0;

    do {
        // first ask to the user the email
        printf("\nInsert the email in the format example@example.com or .it:");
        scanf("%[^\n]s", contact->emailAddress);
        getchar();

        afterAt = strstr(contact->emailAddress, "@");      //extract the part of the email from @ on (es @gmail.com)
        sizeEmail = strlen(contact->emailAddress);         //gives the length of the email
        atPos = afterAt - contact->emailAddress + 1;       //gives the position of the index associated to the @
        last3 = &contact->emailAddress[sizeEmail - 3];     //store the last 3 char (es .it)
        last4 = &contact->emailAddress[sizeEmail - 4];     //store the last 4 char (es .com)

        /* then controls: 1) email can't start with @ or a space; 2) after the @ there will be a alphanumeric char;
         * 3) email must end with .it or .com
         * If controls are passed the variable flagCorrectEmail becomes 1 and che cycle ends. Otherwise we have a
         * warning message and the user has to reinsert the email. */
        if(contact->emailAddress[0] != '@' && contact->emailAddress[0] != ' ' && isalnum(contact->emailAddress[atPos + 1])
           && ((strcmp(last3, ".it") == 0) || (strcmp(last4, ".com")== 0))){
            flagCorrectEmail = 1;}
        else{
            printf("\nWarning...");
            printf("\nemail is not valid. Please insert again.\n");
            flagCorrectEmail = 0;
        }

    }while(flagCorrectEmail == 0);

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
    printf("\nWhich field do you want edit? (press 0 to go back)"
           "\n1) name"
           "\n2) surname"
           "\n3) telephone number"
           "\n4) email"
           "\n5) type of the contact\n"
           "\nSelect an option: ");
    scanf("%d", &choice);
    getchar();

    switch(choice){
        case 1:
            printf("\nEnter the new name of the contact:");
            addName(contact);                                           //procedure to enter a new name
            break;
        case 2:
            printf("\nEnter the new surname of the contact:");
            addSurname(contact);                                        //procedure to enter a new surname
            break;
        case 3:
            printf("\nEnter the new mobile number of the contact:");
            addTelephoneNum(contact);                                   //procedure to enter a new mobile
            break;
        case 4:
            printf("\nEnter the new email");
            addEmail(contact);                                          //procedure to enter a new email
            break;
        case 5:
            printf("\nEnter the new type of the contact");
            addType(contact);                                           //procedure to assign a new type
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

    printf("\nWhat do you want to delete? (press 0 to exit)"
           "\n1) all the phonebook"
           "\n2) a contact with a certain id"
           "\n3) all contacts with a certain name or surname "
           "\n4) a type of contacts\n"
           "\nSelect an option: ");
            scanf("%d", &option);

    switch(option){
        case 1:
            if(contact != NULL)
                free(contact);
            printf("All phonebook has been deleted.");
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

            //printf("All contacts named %s have been delated.", .....);
            break;
        case 4:

            //printf("All contacts of type %d have been delated.", ....);
            break;
        case 0:
            printf("\nBack to the menu");
            return;
        default:
            printf("\nInvalid option selected...");
            break;
    }

}

/** The goal of this procedure is to search for contacts by letting the user decide how to do it.
 * Searching options are implemented through a switch case and they are: by name; by surname; by mobile num;
 * by email and by type.
 * @param contact is a pointer to the dynamic vector where the contacts are stored.
 *
 * I'm aware there are problems and more situations are not taken into account by this procedure (e.g. checks are
 * done only for the entire string and not also for a portion of it).
 */
void searchContact(Contact *contact){

    int option, i;
    TypeOfContact type;
    char name[STRING_DIM + 1], surname[STRING_DIM + 1], mobile[NUM_DIM + 1], email[STRING_DIM + 1];

    printf("\nSearch contact..."
           "\n1) by name"
           "\n2) by surname"
           "\n3) by mobile number"
           "\n4) by email"
           "\n5) by type of contacts\n"
           "\nSelect an option: ");
    scanf("%d", &option);
    getchar();

    switch(option){

        // search by name
        case 1:

            printf("\nEnter the name you are looking for : ");
            scanf("%[^\n]s", &name);

            for(i = 0 ; i < currentSize ; ++i){

                if(strcmp(contact[i].name, name) == 0){
                    printContact(&contact[i]);
                    }
                else{
                    printf("\nNo match found...");}
            }
            break;

        // search by surname
        case 2:

            printf("\nEnter the surname you are looking for : ");
            scanf("%[^\n]s", &surname);

            for(i = 0 ; i < currentSize ; ++i){

                if(strcmp(contact[i].surname, surname) == 0){
                    printContact(&contact[i]);
                    break;}
                else{
                    printf("\nNo match found...");}
            }
            break;

        // search by mobile
        case 3:

            printf("\nEnter the mobile number you are looking for : ");
            scanf("%[^\n]s", &mobile);

            for(i = 0 ; i < currentSize ; ++i){

                if(strcmp(contact[i].telephoneNumber, mobile) == 0){
                    printContact(&contact[i]);
                    break;}
                else{
                    printf("\nNo match found...");}
            }
            break;

        // search by email
        case 4:

            printf("\nEnter the email you are looking for : ");
            scanf("%[^\n]s", &email);

            for(i = 0 ; i <= currentSize ; ++i){

                if(strcmp(contact[i].emailAddress, email) == 0){
                    printContact(&contact[i]);
                   }
                else{
                    printf("\nNo match found...");}
            }
            break;

        // search by type
        case 5:

            printf("\nEnter the type of contact you are looking for : ");
            scanf("%d", &type);

            for(i = 0; i <= currentSize; ++i){
                if(type == contact[i].typeOfContact){
                    printContact(&contact[i]);
                }
                else{
                    printf("\nNo match found...");}
                }
            break;

        default:
            printf("\nInvalid option selected...");
            break;
    }
}

