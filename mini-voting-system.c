#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct currentValidID{
    int year;
    char branch[6];
    int totalVoters;
};

typedef struct candidate{
    int cid;
    char cname[20];
    int votes;
}CANDIDATE;

struct currentValidID currentValidID; 
CANDIDATE candidateArray[20]; 
int numberOfCandidates; 
char studentVotes[200];
void adminPanel();

void display();
int choiceforUser();
int isValid(char userID[15]);
int authenticateAdmin();

int main(){

    char choice;
    display();
    while(1){
        choice = choiceforUser();

        switch(choice){
            case '1':
                // studentPanel();
                printf("1");
                break;
            case '2':
                adminPanel();
                printf("2");
                break;
            case '0':
                printf("\nExiting program...");
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
    char choice;
    
    printf("\n\tUSER CHOICES (Select among the options available)\n");
    printf("\t\t[1] Student Panel\n");
    printf("\t\t[2] Admin Panel\n");
    printf("\t\t[0] Exit\n");
    printf("\tChoice: ");
    scanf(" %c", &choice);

    return choice;
}

int authenticateAdmin(){
    char username[15], password[10];
    
    printf("\nEnter username(Max of 14 characters): ");
    scanf("%s",username);
    if((strcmp(username,"Admin"))!=0)
        return 0;
    else
    {
        printf("Enter Password(Max of 9 characters): ");
        int i=0;
        for(i=0;i<5;i++)
        {
            password[i]=getch();    
            printf("%c",'*');
        }
        password[i]='\0';
        if((strcmp(password,"pasadopls"))!=0)
            return 0;
    }
    return 1;
}

void adminPanel(){
    while(1){
        
        if(authenticateAdmin()!=1){
            printf("\n Wrong Username or Password \n");            
            break;
        }

        printf("\n\nLOGGED IN SUCCESSFULLY (Press Enter)");
		getch();

        while(1)
        {
            char inputID[15];
            char input;char banInp;
            int WinnerCid, totalVotedNow=0;
            printf("\n1.New Election\n2.Continue Previous Election\n3.Delete Illegal Vote\n4.Ban User IDs\n5.Result\n6.Logout\nOption:");
			scanf(" %c",&input);

            switch(input)
            {
                case '1':
                    // initiateNewElection();
                    // saveElectionInfoInFile();
                    // createCandidateFiles();
                    break;
                case '2':
                    // loadElectionInfoFromFile();
                    break;
                case '3':
                    // printf("\nEnter user ID to delete its vote: ");
                    // scanf("%s",inputID);
                    // deleteIllegalVote(inputID);
                    break;
                case '4':
                    // printf("Do you want to ban particular ID's?\nPress 1 if yes or any other key to continue...");
                    // scanf(" %c",&banInp);
                    // if(banInp=='1'){
                    //     banID();
                    // }
                    break;
                case '5':
                    // WinnerCid = getWinner();
                    // if(WinnerCid != -1){
                    //     printf("\nWinner is %s with %d votes\n",candidateArray[WinnerCid-1].cname,candidateArray[WinnerCid-1].votes);
                    // }
                    // else{
                    //     printf("\nIts A TIE");
                    // }
                    // printf("\nFull Result\n");
                    // for(int i=0;i<numberOfCandidates;i++){
                    //     totalVotedNow+=candidateArray[i].votes;
                    //     printf("%d. %s -> %d votes\n",candidateArray[i].cid,candidateArray[i].cname,candidateArray[i].votes);
                    // }
                    // printf("\nVoting Percentage: %d %%\n\n",(totalVotedNow*100)/currentValidID.totalVoters);
                    break;
                case '6':
                    return;
                default:
                    printf("Invalid Option");
					getch();
            }
			
        }
    }

};


// int isValid(char userID[15]){
//     if(strlen(userID)!=14)
//         return 0;
    
//     int inputedYear=extractYear(userID);
//     int inputedRollNo = extractRollNo(userID);
    
//     if(inputedYear!=currentValidID.year || checkBranchCode(userID)!=1 || inputedRollNo>currentValidID.totalVoters)
//         return 0;

//     return 1;
// }
