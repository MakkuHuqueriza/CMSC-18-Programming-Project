#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//test
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


void display();
int choiceforUser();
void adminPanel();
int authenticateAdmin();
void initiateNewElection();
void saveElectionInfoInFile();
void createCandidateFiles();

int main(){

    char choice;
    display();
    while(1){
        choice = choiceforUser();

        switch(choice){
            case '1':
                // studentPanel();
                break;
            case '2':
                adminPanel();
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

void adminPanel(){
    while(1){
        
        if(authenticateAdmin()!=1){
            printf("\nWrong Username or Password (Press Enter)");
            getch();
            system("cls");
            display();            
            break;
        }

        printf("\n\nLOGGED IN SUCCESSFULLY (Press Enter)");
		getch();
        system("cls");

        while(1)
        {
            char inputID[15];
            char input; char banInp;
            int WinnerCid, totalVotedNow=0;
            printf("\n\tUSER CHOICES (Select among the options available)");
            printf("\n\t\t[1] New Election\n\t\t[2] Continue Previous Election\n\t\t[3] Delete Illegal Vote\n\t\t[4] Ban User IDs\n\t\t[5] Result\n\t\t[6] Logout\n\tChoice: ");
			scanf(" %c",&input);

            switch(input)
            {
                case '1':
                    initiateNewElection();
                    saveElectionInfoInFile();
                    createCandidateFiles();
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
        for(i=0;i<9;i++)
        {
            password[i]=getch();    
            printf("%c",'*');
        }
        password[i]='\0';
        if((strcmp(password,"pasadopls"))!=0){
            printf("\n");
            return 0;
        }
    }
    return 1;
}

void initiateNewElection(){
	int i;
    printf("\nNew Election Initiation:\n");
    
    printf("\nElections for which Year: ");
    scanf("%d",&currentValidID.year);
    printf("Enter branch code:");
    scanf("%s",currentValidID.branch);
    printf("Enter maximum number of voters:");
    scanf("%d",&currentValidID.totalVoters);
    printf("Enter the no. of candidates:");
    scanf("%d",&numberOfCandidates);

   for (i = 0; i < currentValidID.totalVoters; i++)
    {
        studentVotes[i] = '0';
    }

    for (i = 0;i < numberOfCandidates; i++) // Number of candidates is already pre-determined with maximum of 20 candidates
    {
        candidateArray[i].cid=i+1;
        printf("Enter name of candidate %d: ",i+1);
        scanf(" %s",candidateArray[i].cname);
        candidateArray[i].votes=0;
    }
    return;
}

void saveElectionInfoInFile(){
    printf("Saving Election Info in File...\n");
    FILE *fpointer = fopen("ElectionInfo.txt", "w");
    if(fpointer==NULL)
    {
        printf("\nError in file creation\n");
        fclose(fpointer);
        return;
    }
    fprintf(
        fpointer,"%d\n%s\n%d\n%d",
        currentValidID.year,
        currentValidID.branch,
        currentValidID.totalVoters,
        numberOfCandidates
    );
    fclose(fpointer);
    printf("Saved Successfully :>");
}

void createCandidateFiles(){
	int i;
    printf("\nCreating candidate files...\n");
    FILE *fp;
	char filename[20];
    for(i = 1;i <= numberOfCandidates; i++){
        sprintf(filename,"candidate%d.txt",i);
		fp=fopen(filename,"w");
        fprintf(
            fp,"0\n%s",
            candidateArray[i-1].cname
        );
		fclose(fp);
    }
    printf("Created Files successfully\n");
}


