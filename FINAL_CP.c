#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#if defined(_WIN32) || defined(_WIN64)     //Definitions to ensure portability of Application across multiple OS
const char* os = "win";
#else
#ifdef __linux
const char* os = "linux";
#else
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
const char* os = "linux";
#else
const char* os = "unknown";
#endif
#endif
#endif

//FUNCTION DECLARATIONS:

void clear_screen();
void welcomeScreen();

void green();
void cyan();
void resetColor();

void mainMenu();
    void viewAllTrains();
    void loadEnquiryMenu();
    void loadBookingMenu();
    void loadCancellationMenu();
    void viewMyBookings();

int getPnr();
void stationCodeDisplay();
void addTrains();


typedef struct     //Structure to handle data related to Trains
{
    char trainName[30];
    char trainNum[8];
    char trainSource[6];
    char trainDest[6];
    int numSeats;
    float ticketPrice;

}Train;     //Typedef to Train

typedef struct     //Structure to handle data related to Tickets
{
    char passengerName[30];
    int pnr;
    char trainNum[8];
    char trainSource[6];
    char trainDest[6];
    float ticketPrice;
    char trainName[30];

}Ticket;     //Typedef to Ticket

void clear_screen()     //Function to clear the terminal irrespective of the OS it is used in
{
    if(os=="win")
    {
        system("cls");
    }
    else if(os=="linux")
    {
        system("clear");
    }
    else
    {
        printf("\n___________________________________________________________________________________________________\n");
    }
}


void green()     //Changes color to green
{
	printf("\033[1;32m");
}
void cyan()     //Changes color to cyan
{
	printf("\033[1;36m");
}
void resetColor()     //Changes color to white
{
	printf("\033[0m");
}

void addTrains()     //Function to add trains in a file as soon as Application is launched
{
    FILE *fp;
    fp = fopen("trainDatabaseFinal.dat","rb");     //A database file for trains is opened in read-binary mode
    if(fp == NULL)
    {
        Train trainArray[8]=     //8 Trains are added to an Array of struct (Train) if fp is NULL
        {
            {"DLI Shatabdi","12001","DLI","HBJ",250,1400.0},
            {"Shane Punjab","12498","DLI","ASR",200,1700.0},
            {"Mumbai Rajdhani","22951","DLI","MMCT",350,2500.0},
            {"LKO Humsafar","04941","DLI","LKO",300,1500.0},
            {"RNC Raj Express","20839","DLI","RNC",200,1200.0},
            {"Karnataka Exp","12628","DLI","SBC",250,2400.0},
            {"Darshan Express","22494","DLI","PUNE",250,2000.0},
            {"Garib Rath","12612","DLI","NGP",350,2500.0}
        };

        fp = fopen("trainDatabaseFinal.dat","wb+");
        fwrite(trainArray,8*sizeof(Train),1,fp);     //Data is written into file
        fclose(fp);
    }

    else
    {
        printf("Success");
        fclose(fp);
    }
}

void welcomeScreen()     //Function to display Welcome message on screen
{
    clear_screen();
    printf("\n\n\n\n");
    green();     //Text color changes to green
    printf("\t\t\t\t\t#**~~~~~~~~~~~~~~~~~ WELCOME~~~~~~~~~~~~~~~~~~**#\n");
    printf("\t\t\t\t\t**                                             **\n");
    printf("\t\t\t\t\t*                     TRAIN                     *\n");
    printf("\t\t\t\t\t|                   MANAGEMENT                  |\n");
    printf("\t\t\t\t\t|                     SYSTEM                    |\n");
    printf("\t\t\t\t\t|                                               |\n");
    printf("\t\t\t\t\t|                  TICKET BOOKING               |\n");
    printf("\t\t\t\t\t|                   PLATFORM FOR                |\n");
    printf("\t\t\t\t\t*                 MIGRANT LABOURERS             *\n");
    printf("\t\t\t\t\t**                                             **\n");
    printf("\t\t\t\t\t#**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**#\n");
    resetColor();     //color changes back to white
    printf("\n\n\n\t\t\t Please press ENTER key to continue.....");
    getchar();     // Waits for User to press ENTER key
}

void mainMenu()     //Function which calls multiple functions depending on the user Input
{
int userChoice = 0;     //Integer input from user as their choice

    do     //Do While loop to ensure valid options are chosen, error message to be printed when character input is undefined
    {
    clear_screen();
    green() ;
    printf("\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t\t       MAIN MENU         ");
    printf("\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~");
    resetColor();
    printf("\n\n\t\t\tPLEASE SELECT A NUMBER TO ACCESS IT!");

    cyan();
    printf("\n\n\t\t\t%c1%c  View all trains\n",'<','>');
    printf("\n\t\t\t%c2%c  Make an enquiry\n",'<','>');
    printf("\n\t\t\t%c3%c  Book a ticket\n",'<','>');
    printf("\n\t\t\t%c4%c  Cancel ticket \n",'<','>');
    printf("\n\t\t\t%c5%c  View my Bookings \n",'<','>');
    printf("\n\t\t\t%c0%c  EXIT \n",'<','>');
    resetColor();
    printf("\n\n\t\t\t=============================================");


    printf("\n\n\t\t\tPLEASE SELECT AN OPTION AND PRESS ENTER : ");
    scanf("%d", &userChoice);     //Takes integer input from user

    switch(userChoice)
        {
        case 1:
            viewAllTrains();
            break;
        case 2:
            loadEnquiryMenu();
            break;
        case 3:
            loadBookingMenu();
            break;
        case 4:
            loadCancellationMenu();
            break;
        case 5:
            viewMyBookings();
            break;
        case 0:
            printf("\n\n\n\t\t\tThank you, Please visit us again!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\t\t\tPlease enter a valid option number!");
        }

    }while (userChoice != 0);     // Do while loop ends here
}     //Main menu function ends here

void viewAllTrains()     //Function which displays all Trains in a Table
{
    clear_screen();
    green();
    printf("\n\n\t\t\t\t\t  =======================================================");
    printf("\n\n\t\t\t\t\t\t                   TRAIN DETAILS                       ");
    printf("\n\n\t\t\t\t\t  =======================================================");
    resetColor();

    Train tr;     //tr is declared of type Train (struct)
    FILE *fp;     //File pointer to access files

    fp=fopen("trainDatabaseFinal.dat","rb");     //Train Database is opened

    if(fp==NULL)
        {
            printf("\n\t Sorry! !\n");
            exit(1);
        }
    cyan();
    printf("\n\n\t\t\tTRAIN NO\tTRAIN NAME\t\t\tTO\t\tFROM\t\tFARE\t\tSEATS LEFT\n\n"); //Train data is printed in a tabular form
    resetColor();

    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\t\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t%.2f\t\t%d\n",tr.trainNum,tr.trainName,tr.trainDest,tr.trainSource,tr.ticketPrice,tr.numSeats);
    }     //Train Data is read from file and printed

    stationCodeDisplay(); //Function to display railway station codes
    fclose(fp);

    printf("\n\n\t\t\tPress ENTER to go to main menu.....");
    getchar();
    getchar();
}

void loadEnquiryMenu()     //Function to display available trains according to the user's requirements
{
    clear_screen();
    green();
    printf("\n\n\t\t\t\t\t\t ================================================");
    printf("\n\n\t\t\t\t\t\t                    ENQUIRY MENU                 ");
    printf("\n\n\t\t\t\t\t\t ================================================");
    resetColor();
    stationCodeDisplay();

    char trSource[6];     //variable that handles user source input
    char trDest[6];     //variable that handles user destination input
    int sourceValid;     //variable used for do while loop
    int destValid;     //variable used for do while loop
    Train trainArray[8];
    int trainIndex;
    FILE *fp;

    do      //Do While loop to ensure valid Source Destination is entered, error message to be printed when character input is undefined
    {
    printf("\n\tPlease enter Source Station: ");
    scanf("%s",trSource);
    sourceValid=strcmp(trSource,"DLI");
        if(sourceValid!=0)
        {
            printf("\n\tNo trains available! Please choose a different Source Station!\n");

        }
    }while(sourceValid!=0);     //do while ends

    do      //Do While loop to ensure valid Final Destination is entered, error message to be printed when character input is undefined
    {
    printf("\n\tPlease enter Final Destination : ");
    scanf("%s",trDest);
        if(strcmp(trDest,"HBJ")==0 || strcmp(trDest,"ASR")==0 || strcmp(trDest,"MMCT")==0 || strcmp(trDest,"LKO")==0 || strcmp(trDest,"RNC")==0 || strcmp(trDest,"SBC")==0 || strcmp(trDest,"PUNE")==0 || strcmp(trDest,"NGP")==0)
        {
            destValid=0;
        }
        else
        {
            printf("\n\tNo trains available for your requirement,Please enter a valid Final Destination!\n");
            destValid=1;
        }
    }while(destValid!=0);     //do while ends

    fp=fopen("trainDatabaseFinal.dat","rb");     //Train database file is opened

    if(fp==NULL)
    {
        printf("\n\tSorry! Train database could not be opened!");
        exit(1);
    }

    fread(trainArray,sizeof(Train),8,fp);     //if fp is not null,file is read

    for(int i=0;i<8;i++)
    {
        if(strcmp(trDest,trainArray[i].trainDest)==0)     // User input destination is compared with the destination field of each element of
        {                                                 // train array using a for loop
            trainIndex=i;     //The index of the array element is stored in a variable to be used later
        }
    }

    printf("\n\tShowing trains matching your requirements:\n");
    cyan();
    printf("\n\t\tTRAIN NO\tTRAIN NAME\t\t\tTO\t\tFROM\t\tFARE\t\tSEATS LEFT\n\n");
    resetColor();

    printf("\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t%.2f\t\t%d\n",trainArray[trainIndex].trainNum,trainArray[trainIndex].trainName,trainArray[trainIndex].trainDest,trainArray[trainIndex].trainSource,trainArray[trainIndex].ticketPrice,trainArray[trainIndex].numSeats);
    fclose(fp);                                               //Matching trains are presented in a tabular form

    printf("\n\n\t\t\tPress ENTER to go to main menu.....");
    getchar();
    getchar();
}

void loadBookingMenu()     //Function to book tickets
{
    clear_screen();
    green();
    printf("\n\n\t\t\t\t\t\t\t================================================");
    printf("\n\n\t\t\t\t\t\t\t             TRAIN BOOKING CENTER"              );
    printf("\n\n\t\t\t\t\t\t\t================================================");
    resetColor();
    stationCodeDisplay();

    FILE *fp1,*fp2,*temp;

    char name[12];
    char surname[12];
    char trSource[6];     //variable that handles user source input
    char trDest[6];     //variable that handles user destination input
    int sourceValid;
    int destValid;
    Ticket passengerTicket;
    int pnr;

    Train trainArray[8];
    int trainIndex;

    printf("\n\tPlease enter Passenger  Name([Name] [Surname]): ");     //FULL NAME SHOULD BE ENTERED IN THIS FORMAT
    scanf("%s%s",name,surname);                                         // PLEASE DO NOT MAKE USE OF '[]' TO ENCLOSE NAME

    do     //do while loop ensures valid source destination is entered
    {
    printf("\n\tPlease enter Source Station : ");
    scanf("%s",trSource);
    sourceValid=strcmp(trSource,"DLI");     //user input source destination is compared with "DLI", strcmp returns an integer
        if(sourceValid!=0)
        {
            printf("\n\tPlease enter a valid Source Station!\n");

        }
    }while(sourceValid!=0);     //do while ends

    do     //do while loop ensures valid final destination is entered
    {
    printf("\n\tPlease enter Final Destination : ");
    scanf("%s",trDest);
        if(strcmp(trDest,"HBJ")==0 || strcmp(trDest,"ASR")==0 || strcmp(trDest,"MMCT")==0 || strcmp(trDest,"LKO")==0 || strcmp(trDest,"RNC")==0 || strcmp(trDest,"SBC")==0 || strcmp(trDest,"PUNE")==0 || strcmp(trDest,"NGP")==0)
        {                        //if condition ensures that user input final destination matches with one of the acceptable final destinations
            destValid=0;
        }
        else
        {
            printf("\n\tNo trains available for your requirement,Please enter a valid Final Destination!\n");
            destValid=1;
        }
    }while(destValid!=0);     //do while ends

    fp1=fopen("trainDatabaseFinal.dat","rb");     //Train database file is opened

    if(fp1==NULL)
    {
        printf("\n\tSorry! Train database could not be opened!");
        exit(1);
    }

    fread(trainArray,sizeof(Train),8,fp1);     // Train data is read from the file

    for(int i=0;i<8;i++)
    {
        if(strcmp(trDest,trainArray[i].trainDest)==0)     // User input destination is compared with the destination field of each element of
        {                                                 // train array using a for loop
            trainIndex=i;     //The index of matching array element is stored in a variable to be used later
        }
    }

    if(trainArray[trainIndex].numSeats>0)     //If condition checks if seats are available
    {
        printf("\n\t%d Seats are available in Train %s ,#%s from %s to %s\n",trainArray[trainIndex].numSeats,trainArray[trainIndex].trainName,trainArray[trainIndex].trainNum,trainArray[trainIndex].trainSource,trainArray[trainIndex].trainDest);

        char confirm;    //CONFIRMATION PROMPT FOR BOOKING
        getchar();

        printf("\n\tDo you want to confirm your booking? (Y/N) : ");
        scanf(" %c",&confirm);

        while(confirm != 'Y' && confirm != 'N')
        {
            printf("\n\tInvalid input! Please confirm with Y for yes and N for no.");     //Ensures valid input by user
            printf("\n\tDo you want to confirm your booking?(Y/N) : ");
            scanf(" %c",&confirm);
        }

        if(confirm=='Y')
        {
        fp2=fopen("ticketDatabase.dat","ab+");     //Ticket database file is opened in append-binary mode

            if(fp2==NULL)
            {
                printf("\t\nSorry!Ticket Database could not be loaded");
            }

            strcpy(passengerTicket.passengerName,name);     //User name,train source,train destination,train number,train name and fare
            strcpy(passengerTicket.trainSource,trainArray[trainIndex].trainSource);     //are copied and stored in passenger ticket struct
            strcpy(passengerTicket.trainDest,trainArray[trainIndex].trainDest);
            strcpy(passengerTicket.trainNum,trainArray[trainIndex].trainNum);
            strcpy(passengerTicket.trainName,trainArray[trainIndex].trainName);
            pnr=getPnr();     //PNR is fetched from the function getPnr()
            passengerTicket.pnr=pnr;
            passengerTicket.ticketPrice=trainArray[trainIndex].ticketPrice;

            fwrite(&passengerTicket,sizeof(passengerTicket),1,fp2);     //Ticket details are written into Ticket database file

            printf("\n\tTicket booked Successfully!...");
            printf("\n\tYour PNR Number is : %d" ,pnr);

            printf("\n\n\tYou can view your booking in MAIN MENU --%c %c5%c View my Bookings \n",'>','<','>');
            fclose(fp2);     //Ticket database file is closed
            fclose(fp1);      //Train database file is closed

            trainArray[trainIndex].numSeats-=1;     //SEAT UPDATION WHEN USER BOOKS TICKET

            //replacing train with occupied seats info with TEMPORARY file
            temp=fopen("temp1.dat","wb");

            if(temp==NULL)
            {
                fclose(temp);
                printf("\n\t File could not be opened\n");
                exit(1);
            }

            fwrite(trainArray,8*sizeof(Train),1,temp);     //Details added to temporary file
            fclose(temp);     //Temporary file is closed

            remove("trainDatabaseFinal.dat");     //contents of Original train database are removed
            rename("temp1.dat","trainDatabaseFinal.dat");     //temporary file is renamed as Train Database
            remove("temp1.dat");     //Temporary file is removed
        }

        else
        {
            printf("\n\t Ticket booking was canceled!");
        }

    }
    else
    {
        printf("\n\tSorry!, no seats are available right now. Please check again later!");
    }

    printf("\n\n\t\t\tPress ENTER to go to main menu.....");

    getchar();
    getchar();
}

int getPnr()     //Function which manages PNR number of booked ticket
{                 // The most recent PNR is stored in a txt file
    FILE *fp;
    int pnrValue=0;
    fp=fopen("pnrTemp.txt","r");


    if(fp==NULL)
    {
    fp=fopen("pnrTemp.txt","w");
    fprintf(fp,"%d",0);
    fclose(fp);
    fp=fopen("pnrTemp.txt","r");
    }

    fscanf(fp ,"%d",&pnrValue);

    fclose(fp);

    fp=fopen("pnrTemp.txt","w");
    fprintf(fp,"%d",pnrValue+1);
    fclose(fp);

    return pnrValue+1;     //PNR is incremented
}



void loadCancellationMenu()     //function to cancel tickets using user input PNR
{
    clear_screen();
    green();
    printf("\n\n\t\t\t\t\t\t\t================================================");
    printf("\n\n\t\t\t\t\t\t\t              CANCEL YOUR TICKETS HERE          ");
    printf("\n\n\t\t\t\t\t\t\t================================================");
    resetColor();
    stationCodeDisplay();

    Train trainArray[8];
    Ticket passengerTicket;

    int trainIndex;
    int passengerPNR;
    int found = 0;
    char a[8];


    FILE *fpTicket, *tempTicket, *fpTrain ,*tempTrain;

    fpTicket=fopen("ticketDatabase.dat","rb");     //Ticket database file is opened

     if(fpTicket==NULL)
    {
        printf("\t\nTickets could not be loaded!");
        exit(1);
    }

    tempTicket=fopen("tempTicket.dat","wb");     //Temporary file is created

    if(tempTicket==NULL)
    {
        fclose(fpTicket);
        printf("\n\t File could not be opened\n");
        exit(1);
    }

    printf("\n\n\t\tPlease enter the PNR number of the ticket you wish to cancel : ");     //User inputs PNR
    scanf("%d",&passengerPNR);

    while (fread(&passengerTicket, sizeof(passengerTicket), 1, fpTicket))      //While loop to compare user input PNR with PNRs in
    {                                                                          //main Ticket database file
        if (passengerTicket.pnr != passengerPNR)
        {
            // If PNR of ticket in "ticketDatabase.dat" does not match the
            // PNR entered then the ticket's info is written into
            // the temporary file and it is skipped if the PNRs match
            fwrite(&passengerTicket, sizeof(passengerTicket), 1, tempTicket);
        }
        else
        {
            for(int i=0;i<8;i++){
                a[i]=passengerTicket.trainNum[i];  //to copy train no of the train whose seats have to be updated
            }
            found = 1;     // User input PNR matches with PNR present in Ticket database
        }
    }     //while loop for PNR comparison ends

    if (found)
    {
        char confirm;    //cancellation prompt
        getchar();

        printf("\n\t\tDo you want to confirm your cancellation? (Y/N) : ");
        scanf(" %c",&confirm);

         while(confirm != 'Y' && confirm != 'N')    //while loop ensures valid character input
        {
            printf("\n\tInvalid input! Please confirm with Y for yes and N for no.");
            printf("\n\tDo you want to confirm your cancellation?(Y/N) : ");
            scanf(" %c",&confirm);
        }

        if(confirm=='Y')
        {
            printf("\n\t\tTicket cancelled successfully.....");
            printf("\n\t\tYou will be refunded 50%% of the ticket price");
            printf("\n\t\tYour refund amount in rupees is: %.2f",((passengerTicket.ticketPrice)/(2.00)));  //Refund amount displayed

            //replacing train with occupied seats info with Temporary file
            fpTrain=fopen("trainDatabaseFinal.dat","rb");

            if(fpTrain==NULL)
            {
                printf("\n\tSorry! Train database could not be opened!");
                exit(1);
            }

            fread(trainArray,sizeof(Train),8,fpTrain);    //Main train database is opened

            for(int i=0;i<8;i++)
            {
                if(strcmp(a,trainArray[i].trainNum)==0)
                {
                    trainIndex=i;     //index of array element is stored in a variable to be used later
                }
            }

            fclose(fpTrain);     //main train database is closed

            trainArray[trainIndex].numSeats+=1;//SEAT INCREMENT ON CANCELLATION

            tempTrain=fopen("trainTemp.dat","wb");    //Temporary train database file is opened
            if(tempTrain==NULL)
            {
                fclose(tempTrain);
                printf("\n\t File could not be opened\n");
                exit(1);
            }

            fwrite(trainArray,8*sizeof(Train),1,tempTrain);    //Data is written into temporary file
            fclose(tempTrain);     //Temporary train database file is closed

            remove("trainDatabaseFinal.dat");     //Contents of main Train database are removed
            rename("trainTemp.dat","trainDatabaseFinal.dat");     //Temporary train database is renamed
            remove("trainTemp.dat");     //temporary train database file is removed

            fclose(fpTicket);     //Main ticket file is closed
            fclose(tempTicket);    //Temporary ticket file is closed

            remove("ticketDatabase.dat");     // Removing the original TICKET DATABASE and renaming the temporary file created with the
            rename("tempTicket.dat","ticketDatabase.dat");    // name of the TICKET DATABASE
        }     //if condition for 'Y' ends

        else     //is user inputs 'N'
        {
            printf("\n\t\t Ticket cancellation process was canceled!");
        }

    } // If condition for PNR found ends

    else     // If user input PNR does not match PNR in ticket Database
    {
        printf("\n\t\t\tTicket not found");

    }

    printf("\n\n\t\t\tPress ENTER to go to main menu.....");//ERROR IN UBUNTU HERE
    getchar();
    getchar();
}
void viewMyBookings()
{

    clear_screen();
    green();
    printf("\n\n\t\t\t\t\t\t\t================================================");
    printf("\n\n\t\t\t\t\t\t\t               MY BOOKED TICKETS                ");
    printf("\n\n\t\t\t\t\t\t\t================================================");
    resetColor();
    stationCodeDisplay();

    FILE *fp;
    Ticket ticket;

    fp=fopen("ticketDatabase.dat","rb");     //Ticket database is opened

    if(fp==NULL)
    {
        printf("\t\nTickets could not be loaded!");
        exit(1);
    }

    cyan();
    printf("\n\t\tTRAIN NO\tTRAIN NAME\t\tTO\t\tFROM\t\tFARE\t\tPNR\tPASSENGER NAME\n\n");
    resetColor();

    while(fread(&ticket,sizeof(ticket),1,fp)==1)
    {
        printf("\t\t%s\t\t%s\t\t%s\t\t%s\t\t%.2f\t\t%d\t%s\n",ticket.trainNum,ticket.trainName,ticket.trainDest,ticket.trainSource,ticket.ticketPrice,ticket.pnr,ticket.passengerName);
    }                                                          //Ticket data is presented in a tabular form
    fclose(fp);     //Ticket database is closed

    printf("\n\n\t\t\tPress ENTER to go to main menu.....");
    getchar();
    getchar();
}

void stationCodeDisplay()    //Prints Station code
{
    cyan();
    printf("\n\n\t\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
    printf("\n\t\t\t\t\t\t\t~~~  DLI: Old Delhi Railway Station  ~~~");
    printf("\n\t~~~  HBJ : Habibganj Railway Station-Bhopal ||| ASR : Amritsar Junction ||| MMCT : Mumbai Central Railway Station ||| LKO : Lucknow Junction  ~~~");
    printf("\n\t\t\t~~~  RNC: Ranchi Railway station ||| SBC: Bangalore city junction ||| PUNE: Pune Junction ||| NGP: Nagpur Junction  ~~~\n\n");
    printf("\t\t~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
}


int main()     //Main function
{
    addTrains();
    clear_screen();
    welcomeScreen();
    mainMenu();
}
