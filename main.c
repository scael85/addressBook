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

Contact getContact();
void printContact(Contact contact);
void editContact(Contact contact);
Contact initializeDinamicVector();

int main() {

    //Contact contact1;
    Contact pointerAddress;
    //contact1 = getContact();
    //editContact(contact1);
    pointerAddress = initializeDinamicVector();



    return 0;
}

/*2) Implementare una funzione o procedura che acquisisca i campi di un Contatto e restituisca tale contatto.
 * Effettuare i controlli sull'input:
 * - nome (non vuoto, non deve contenere cifre)
 * - cognome (non vuoto, non deve contenere cifre)
 * - numero di telefono (non vuoto, non deve contenere simboli o lettere)
 * - indirizzo email (deve contenere almeno un carattere prima della chiocciola, almeno un carattere chiocciola,
 *  almeno un carattere dopo la chiocchiola, un punto e un dominio come com o it)
 *  - tipologia (deve essere richiesto in modo semplice per l'utente, ad esempio usando un menu)*/
 Contact getContact(){

     Contact contact;
     int i, correctName = 0, correctSurname = 0, correctNum = 0;

    //routine do get and check the name
    do{
        printf("\nInsert your name (no numbers allow):");
        scanf("%[^\n]s", &contact.name);
        getchar();

        for(i = 0 ; i <= *contact.name, contact.name[i] != '\0'; ++i){
            if(!(isdigit(contact.name[i])) && (contact.name[0] != ' ')){
                correctName = 1;}
            else{
                correctName = 0;
                printf("\nThe name has a number in it or it's empty. FIX IT.");
                break;}
        }

    }while(correctName == 0);


    //routine do get and check the surname
    do{
        printf("\nInsert your surname (no numbers allow):");
        scanf("%[^\n]s", &contact.surname);
        getchar();

        for(i = 0 ; i <= *contact.surname, contact.surname[i] != '\0'; ++i){
            if(!(isdigit(contact.surname[i])) && (contact.name[0] != ' ')){
                correctSurname = 1;}
            else{
                correctSurname = 0;
                printf("\nThe surname has a number in it or it's empty. FIX IT.");
                break;}
        }

    }while(correctSurname == 0);

    //routine do get and check the telephone number
    do{
        printf("\nInsert your telephone number (no symbols or letters allow):");
        scanf("%[^\n]s", &contact.telephoneNumber);
        getchar();

        for(i = 0 ; i <= *contact.telephoneNumber, contact.telephoneNumber[i] != '\0'; ++i){
            if (contact.telephoneNumber[i] < '0' || contact.telephoneNumber[i] > '9' || (contact.telephoneNumber[0] == ' ')){
                printf("\nThe number has a char in it or it's empty. FIX IT.");
                correctNum = 1;
                break;}
            else
                correctNum = 0;
        }

    }while(correctNum == 1);


    printf("\nInsert your email address in this similar format 'example@example.com':");
    scanf("%s", &contact.emailAddress);
    printf("\nInsert what type of contacts is:\ntype 0 for WORK,\ntype 1 for FAMILY,\ntype 2 for FRIENDS,"
               "\ntype 3 for OTHERS");
    scanf("%d", &contact.typeOfContact);

     return contact;
 }

// 3) Implementare una procedura che stampi in modo chiaro e ordinato tutti i dati del contatto
void printContact(Contact contact){
    printf("\nThe name of the contact is %s.", contact.name);
    printf("\nThe surname of the contact is %s.", contact.surname);
    printf("\nThe telephone number of the contact is %s.", contact.telephoneNumber);
    printf("\nThe email address of the contact is %s.", contact.emailAddress);
    printf("\nThe type of the contact is %d (0=WORK, 1=FAMILY, 2=FRIENDS, 3=OTHERS).", contact.typeOfContact);
 }

/* 4) Implementare una funzione o procedura che permetta la modifica di un contatto.
*  Riceverà come parametro un contatto, lo stamperà e chiederà quale campo deve essere modificato.
*  Una volta inserito il nuovo valore, a seconda dei casi il contatto dovrà essere restituito al chiamante o meno
*  (dipende se si utilizza una procedura o una funzione). */
void editContact(Contact contact){

    printContact(contact);
    printf("\n");

    int choice;
    printf("\nWhich field of the Phonebook do you want edit? (press 0 to exit)");
    printf("\n1) name");
    printf("\n2) surname");
    printf("\n3) telephone number");
    printf("\n4) email");
    printf("\n5) type of the contact");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nEnter the new name of the contact:");
            scanf("%s", &contact.name);
            break;
        case 2:
            printf("\nEnter the new surname of the contact:");
            scanf("%s", &contact.surname);
            break;
        case 3:
            printf("\nEnter the new telephone number of the contact:");
            scanf("%s", &contact.telephoneNumber);
            break;
        case 4:
            printf("\nEnter the new email of the contact 'example@example.com':");
            scanf("%s", &contact.emailAddress);
            break;
        case 5:
            printf("\nEnter the new type of the contact (0=WORK, 1=FAMILY, 2=FRIENDS, 3=OTHERS):");
            scanf("%d", &contact.typeOfContact);
            break;
        default:
            printf("\nNo modification needed");

    }

    printContact(contact);
  }

/* 5) Implementare una funzione che inizializzi un vettore dinamico. Essa dovrà allocare lo spazio per un contatto
*  e restituire l'indirizzo di memoria relativo se l'allocazione è andata a buon fine.
*  Altrimenti il programma terminerà comunicando all'utente tale malfunzionamento. */
Contact initializeDinamicVector(){

    Contact *pointer = NULL;
    int n;

    printf("\nHow many contacts n do you want?");
    scanf("%d", &n);
    pointer = (Contact *)malloc(n * sizeof(Contact));
    if ( pointer == NULL ){
        printf("\nFailed to allocate memory");
        exit(-1);
    }
    else
        printf("\nThe memory address of a contact id %p", pointer);

    return *pointer;
}

/* 6) Implementare la funzione di inserimento seguendo la logica seguente: passo il contatto,
 *  aumento lo spazio del vettore dinamico per contenere un nuovo elemento e a questo punto inserisco
 *  il nuovo contatto seguendo l'ordine alfabetico. Si possono presentare due casi: inserimento in coda,
 *  inserimento non in coda. Se in coda non dovremo far altro che inserire il contatto nell'ultima (e nuova)
 *  posizione, altrimenti una volta trovato il contatto successivo in ordine alfabetico dovremo far scorrere
 *  tutti i contatti di una posizione e inserire il nuovo contatto nella corretta posizione. Al termine delle
 *  operazioni ricordarsi di tenere traccia dell'eventuale cambio di valore del puntatore al vettore dinamico.*/

/*  7) Implementare la funzione di eliminazione offrendo le seguenti possibilità:
 *  - eliminare tutta la rubrica
 *  - eliminare un contatto con un certo indice
 *  - eliminare tutti i contatti con un certo nome o cognome
 *  - elininare una categoria di contatti
 *  In tutti i casi dovremo sempre stare attenti a modificare lo spazio occupato dal vettore,
 *  se ad esempio abbiamo un vettore di 3 contatti A, B e C e dobbiamo eliminare B sposteremo C in B e
 *  riallocheremo lo spazio eliminando un elemento (l'ultimo).
 *  Ricordarsi sempre di restituire il puntatore al vettore dinamico.*/
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

            break;
        case 3:

            break;
        case 4:

            break;
        default:
            printf("\nBack to the menu");

    }

}


