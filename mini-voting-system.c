#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void display();
int choiceforUser();

int main(){

    char choice;
    display();
    while(1){
        choice = choiceforUser();

        switch(choice){
            case '1':
                studentPanel();
                break;
            case '2':
                adminPanel();
                break;
            case '0':
                return 0;
            default:
                printf("\nInvalid option");
                getch();
        }
    }
    return 0;
}

void display(){
	printf("\n=================================================================================================================\n");
	printf("THIS PROGRAM IS A MINI-VOTING SYSTEM\n");
    printf("UNANTICIPATED USER ACTIONS OR INPUTS MAY LEAD TO BUGS OR THE TERMINATION OF THE PROGRAM.\n");
	printf("=================================================================================================================\n");
}

int choiceforUser(){
    int choice;
    
    printf("\n\tUSER CHOICES (Select among the options available)\n");
    printf("\t\t[1] Add Record\n");
    printf("\t\t[2] Display All Records\n");
    printf("\t\t[0] Exit\n");
    printf("\tChoice: ");
    scanf("%d", &choice);

    return choice;
}