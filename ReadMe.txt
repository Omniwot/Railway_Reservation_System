#############################################################
ReadMe for assignment submitted by 2019B1PS0969P
Practical section number: P10
Assignment question attempted: 6 (Railway Reservation System for Migrant labourers)
#############################################################
Team:
1. 2019B1PS0969P Chirag Matai
2. 2019A2PS0626P Om Srivastava
3. 2019A3PS0282P Harshal Abhyankar
#############################################################
Description of how to run the code and observe the output:

We have developed a console based application to facilitate railway booking for migrant labourers.

1. A file with extension .c namely FINAL_CP.c is submitted for this purpose
2. This file needs to be compiled on the default gcc compiler by executing the command "gcc FINAL_CP.c"
3. On succesfully compiling the application, the following a.out file will be generated.

4. On opening the generated executable 'a.out' , you will be greeted with a Welcome Screen.
5. On pressing ENTER you will be directed to the 'Main Menu' where you will be presented with 6 options.
6. You will be prompted to enter an integer (0-5) to access the following sub menus:

   <1> View all trains	
   <2> Make an enquiry
   <3> Book a ticket 
   <4> Cancel ticket
   <5> View my Bookings

   <0> EXIT

7. Throughout the program, certain conditions and safety checks are added to ensure you cannot proceed further by entering an invalid character. 

8. Train details are fetched on the basis of user input of station codes. The details of which , are presented in a seperate section in each sub menu.

8. To view all trains, you can press 1 on the main menu. On entering 1 you are directed to the --insert heading-- section , where you can view all the running trains.Here you can view the
   Train No, Train Name,the source and final destinations ,fare and Seats available which are updated realtime on the basis of bookings and cancellations. Once you are finished viewing the     trains, you can press ENTER to go back to the main menu.

9. To make an enquiry, you can press 2 on the main menu.On entering 2 you are directed to the --insert heading-- section , where you're prompted to enter your source and final destination.     On pressing enter, a table containing all the details of the running trains is presented to you. To go back to the main menu you can press the ENTER key.

10. To book a ticket, you can press 3 on the main menu.On entering 3 you are directed to the --insert heading-- section , where you're prompted to enter your FULL NAME , source ,and final
    destination. The only acceptable source destination is DLI (representing Delhi junction) . If you enter an invalid source or final destination , an error message is printed. Once your
    final destination is validated , the number of seats available in the train are checked.If seats are available, a BOOKING CONFIRMATION prompt is presented to you. If you enter Y (for
    Yes) , your ticket is booked and PNR is generated ,starting from 1. If you enter N (for No) , ticket booking process is cancelled . Please note you CANNOT go back to the main menu           unless you enter your FULL NAME, source and final destination and the Y or N  for booking confirmation prompt. After entering Y/N  you can press the ENTER key to go back to the main         menu.

11. To cancel a ticket, you can press 4 on the main menu.On entering 4 you are directed to the --insert heading-- section. Here, you're prompted to enter the PNR number corresponding to the
    ticket you wish to cancel. If your PNR is invalid ,an error message is printed and you can press ENTER to go to the main menu. If your PNR is valid a CANCELLATION CONFIRMATION prompt is     presented to you. If you enter Y (for Yes) , your ticket is cancelled , and your refund amount is displayed on the screen. If you enter N (for No) , the ticket cancellation process is       terminated and you can press ENTER to go back to the main menu.

12. To view your booked tickets, you can press 5 on the main menu.On entering 5 you are directed to the --insert heading-- section. Here, all your booked tickets are presented in a tabular      form . If a you book or cancel a ticket, the changes are reflected in this section.Once you are finished viewing your booked tickets, you can press ENTER to go back to the main menu.

13. To EXIT from the application, you can press 0 from the main menu.

14. In this application we have also ensured its portability across different operating systems by using appropriate functions.
   	
############################################################
Known limitations of the code :

There are no known limitations of code as such. But the following points must be kept in mind :

1. Please run our application in Full screen mode to ensure proper orientation of the tables used.
2. Please access the 'View my Bookings' section only after booking your first ticket otherwise you will have to relaunch the application. This is to ensure the requisite files are generated properly ,prior to you viewing them.
3. Please ensure you enter valid case for the input wherever prompted. For eg. the station code DLI is valid and dli is invalid.

#############################################################
Contributions of the team members:

We have worked collectively to make this application,however the individual contributions are as follows:

1. Chirag Matai  : .c file compilation , ticket BOOKING function, main menu function, pnr updation ,ReadMe.txt,Code comments
2. Om Srivastava : struct implementation,ENQUIRY,view all trains,add trains,clear screen function,color change,seat updation 
3. Harshal Abhyankar :  welcome screen , CANCELLATION , view my bookings , confirmation prompts , seat updations
#################################################################################### THANK YOU !!############################################################################################