/*
#include<stdio.h>

int main (){
    int a,b;

    printf("enter the first number:");
    scanf("%d",&a);
    printf("enter the second number:");
    scanf("%d",&b);

    printf("before swapping:\n");
    printf("a=%d\n",a);
    printf("b=%d\n",b);

   // a=a+b;
   // b=a-b;
   // a=a-b;

    printf("\nafter swapping :\n");
    printf("a=%d\n",a);
    printf("b= %d",b);


    return 0;


    
    }*/



/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberToGuess;
    int guess;
    int attempts = 0;
    int maxAttempts = 5; // You can adjust this to change the maximum number of attempts

    // Initialize random number generator
    srand(time(NULL));

    // Generate random number between 1 and 100
    numberToGuess = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100. Try to guess it.\n");

    // Game loop
    while (attempts < maxAttempts) {
        printf("\nEnter your guess (between 1 and 100): ");
        scanf("%d", &guess);

        attempts++;

        // Check if the guess is correct
        if (guess == numberToGuess) {
            printf("Congratulations! You guessed the number %d correctly in %d attempts.\n", numberToGuess, attempts);
            break;
        } else if (guess < numberToGuess) {
            printf("Try again! The number I'm thinking of is higher than %d.\n", guess);
        } else {
            printf("Try again! The number I'm thinking of is lower than %d.\n", guess);
        }
    }

    // If all attempts are used and the number is not guessed correctly
    if (attempts == maxAttempts) {
        printf("\nSorry, you've used all %d attempts. The number I was thinking of was %d.\n", maxAttempts, numberToGuess);
    }

    return 0;
}





e343453454657689o795643257689




#include <stdio.h>

int main() {
    int n, i;
    unsigned long long firstTerm = 0, secondTerm = 1, nextTerm;

    // Input number of terms from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms:\n", n);

    // Special case for first term (0)
    if (n >= 1) {
        printf("%llu, ", firstTerm);
    }
    
    // Special case for second term (1)
    if (n >= 2) {
        printf("%llu, ", secondTerm);
    }

    // Calculate and print remaining terms
    for (i = 3; i <= n; ++i) {
        nextTerm = firstTerm + secondTerm;
        printf("%llu", nextTerm);
        if (i < n) {
            printf(", ");
        }
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
 
    printf("\n");

    return 0;




#include<stdio.h>

int main()
{
    float income,tax=0.0;

    printf("enter the income amount:");
    scanf("%f",&income);

    if(income > 250000 && income<= 500000){
        tax= (income-250000)*0.05;
    
    } else if(income> 500000 && income<= 1000000){
        tax=12500 +(income - 500000)*0.20;
    }else if(income> 1000000){
        tax = 112500+(income - 1000000)*0.30;
    }

    printf("income tax payable: %2f\n",tax);
   
    return 0;
    }




*/






/*
    Author : Rohit Singh
    Project Name : Phonebook
    Date created : 16/07/2021
    Description : By using this file we can save contacts and do these operations in it.
        1) view all contacts.
        2) add a contact.
        3) remove a contact.
        4) search details of any contact number.
        5) update details of any contact.
        6) delete whole phonebook (delete all contacts present in phonebook).
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
    char country_code[4];
    long int mble_no;
    char sex[8];
    char mail[100];
};

// Defining person data type.
typedef struct person person;

// All function declaration.
void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);


// Program starts here.
int main()
{
    start();
    return 0;
}

// This function will start our program.
void start()
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                list_record();
                getchar();
                getchar();
                break;
            case 2:
                add_person();
                getchar();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                getchar();
                break;
            default :
                system("clear");
                printf("Thanks for using phonebook visit again : )\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}

// This will print main menu.
void print_menu()
{
    system("clear");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome TO My phone book                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) list record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person Details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) exit Phonebook\n\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

// This function will add contact into phonebook.
void add_person()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("clear");
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");

    }
}

// By this we take contact information.
void take_input(person *p)
{
    system("clear");
    // This getchar is for taking \n occured by previous functions.
    // So that scanset in scanf will work properly.
    getchar();
    printf("Enter name : ");
    // Here we are using scanset '^' - >  until get
    scanf("%[^\n]s",p->name);

    printf("Enter country code : ");
    scanf("%s",p->country_code); 
    
    printf("Enter mobile no : ");
    scanf("%ld",&p->mble_no); 

    printf("Enter sex : ");
    scanf("%s",p->sex); 
    
    printf("Enter email : ");
    scanf("%s",p->mail); 
}

// This function will list contact available in phonebook.
void list_record()
{
    system("clear");
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        // fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.country_code);
            int len3 = 15;
            int len4 = 21 - strlen(p.sex);
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",p.country_code);
            for(i=0;i<len2;i++) printf(" ");

            printf("%ld",p.mble_no);
            for(i=0;i<len3;i++) printf(" ");

            printf("%s",p.sex);
            for(i=0;i<len4;i++) printf(" ");

            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
        
    }
}

// This function will search contact in phonebook.
void search_person()
{
    system("clear");
    long int phone;
    printf("Enter Phone number of the person you want to search : ");
    scanf("%ld",&phone);

    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.country_code);
                int len3 = 15;
                int len4 = 21 - strlen(p.sex);
                printf("%s",p.name);
                for(i=0;i<len1;i++) printf(" ");

                printf("%s",p.country_code);
                for(i=0;i<len2;i++) printf(" ");

                printf("%ld",p.mble_no);
                for(i=0;i<len3;i++) printf(" ");

                printf("%s",p.sex);
                for(i=0;i<len4;i++) printf(" ");

                printf("%s",p.mail);
                printf("\n");

                flag = 1;
                break;
            }
            else continue;
            // fflush(stdin);
        }
        if(flag == 0) 
        {
            system("clear");
            printf("Person is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }

}

// This function will remove contact from phonebook.
void remove_person()
{
    system("clear");
    long int phone;
    printf("Enter Phone number of the person you want to remove from phonebook : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                system("clear");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
        
    }

}

// This function will update contact information.
void update_person()
{

    system("clear");
    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone) 
            {   
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("clear");
                printf("Data updated successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}


// This function will clear all the data of phonebook.
void remove_all()
{
    char choice;
    system("clear");
    remove("./phonebook_db");
    printf("All data in the phonebook deleted successfully\n");
    printf("Press any key to continue ... \n");
}
*/

/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int game(char you, char computer)
{
    if(you==computer)

    return -1;

    if (you =='s' && computer =='p')
    return 0;

    else if(you ='p'&& computer =='s') return 1;

    if (you =='s' && computer =='z')
    return 1;

    else if(you =='z' && computer =='s')

    return 0;

    if (you =='p'&& computer =='z')
    return 0;

    else if (you =='z'&& computer =='p')
    return 1;

}


int main()
{
    int n;

    char you, computer , result;

    srand(time(NULL));

    n= rand() %100;

    if(n < 33)

     computer ='s';

     else if(n> 33&&n<<66)

     computer ='p';

     else 
     computer ='z';

     Printf("\n\n\n\n\t\t\t\tenter s for Stone , p for Paper and z for scissor\n\t\t\t\t\t\t");

     scanf("%c", &you);

     result= game(you, computer);

     if(result ==-1){
        printf("\n\n\t\t\t\tgame draw!\n");
     }

     else if (result ==1){
        printf("\n\n\t\t\tWow! you have won the game!\n");
     }

     else{
        printf("\n\n\t\t\t\ton! you lost the game! \n");

     }

     printf("\t\t\t\tYou choose: %c and computer choose : %c\n",you, computer);

     return 0;
}
*/


#include<stdio.h>

int main(){

    int a=11;

    if (a==11)
    printf("i am 11");

    else

    printf("i am nit 11");

    return 0;
}