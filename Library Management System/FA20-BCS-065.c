/*1.    TASK DESCRIPTION
Program for managing library through computerized system.*/

/*2.    AUTHOR DETAILS
    Author Name:        Muhammad Junaid Nadeem
    Program Name:       main.c
    Program Version:    1.0
    License:            Public Domain*/

/*3.    System Information
    Operating System:   Windows 10 Pro
    Compiler:           CodeBlocks
    Start Date:         9-6-2021
    End Date:           12-6-2021*/

/*4.    Purpose Of Program
 The main purpose of this program is to add, remove, display and issue books through computerized sytem.*/



//INCLUSION OF LIBRARIES.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define _WIN32_WINNT 0x05232
//DECLARING STRCUTURE.
    struct book
    {
        //STRUCTURE VARIABLES:
        int book_serial;
        int isbn;
        char book_name[25];
        int edition;
        char author[25];
        char Is_reserved[4];
    };

//PROTOTYPES OF FUNCTIONS USED.
void welcome();
void gotoxy(int x, int y);
void menu();
void add_book(struct book b, FILE *);
void display_books(struct book b, FILE *);
void modify_record(struct book b,FILE *);
void remove_book(struct book b, FILE *);
void issue_book(struct book b, FILE *);
void search_book(struct book b, FILE *);
void Exit();
void MaximizeOutputWindow();
char choice;




int main()
{
    MaximizeOutputWindow();
    welcome(); //FUNCTION CALL.
    FILE *ptr;// DECLARATION OF FILE.
    ptr= fopen("records_file.exe","rb+");// OPENING DECLARED FILE.
    if (ptr == NULL) // VERIFYING OPENING OF FILE.
    {
        ptr = fopen("records_file.exe", "wb+");//OPENING FILE IN READ AND WRITE BINARY FORMAT.
        if (ptr == NULL)
        {
            puts("Cannot open file");
            exit(1);
        }
    }

    struct book b; //DECLARING A STRUCTURE VARIABLE.
    int choice;    //DECLARING AN INT VARIABLE.
    while (1)      // LOOP FOR CONTINUOUS MENU DISPLAY.
    {
        menu();    //FUNCTION CALL.
        printf("Choose any option and enter an integer number from above:");
        scanf("%d",&choice);
        system("CLS");
        if (choice == 1)    //CONDITIONS FOR CHECKING INPUT OF USER.
            add_book(b,ptr);//FUNCTION CALL
        else if (choice==2)
            remove_book(b,ptr); //FUNCTION CALL
        else if (choice==3)
            search_book(b,ptr); //FUNCTION CALL
        else if (choice==4)
            modify_record(b,ptr); //FUNCTION CALL
        else if (choice==5)
            display_books(b,ptr); //FUNCTION CALL
        else if (choice==6)
            issue_book(b,ptr); //FUNCTION CALL
        else if (choice==7)
            Exit(); //FUNCTION CALL
        printf("Press any key to go to Menu.");
        char choose;
        fflush(stdin);
        scanf("%c",&choose);
    }
    fclose(ptr); //CLOSING FILE.
    return 0;
}
void menu() //FUNCTION BODY
{
    system("color 0F");
    system("CLS");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("MAIN MENU \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n \n");
    //MENU DISPLAYED IN PROGRAM.
    gotoxy(69,16);
    printf("Press 1 to ADD BOOK\n");
    gotoxy(69,18);
    printf("Press 2 to REMOVE BOOK\n");
    gotoxy(69,20);
    printf("Press 3 to SEARCH BOOK\n");
    gotoxy(69,22);
    printf("Press 4 to MODIFY RECORD\n");
    gotoxy(69,24);
    printf("Press 5 to DISPLAY ALL BOOKS\n");
    gotoxy(69,26);
    printf("Press 6 to ISSUE BOOK\n");
    gotoxy(69,28);
    printf("Press 7 to EXIT\n");
    gotoxy(55,32);
}
void add_book(struct book x, FILE *addptr)//FUNCTION BODY.
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("ADD BOOK \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n \n");
    while (1)// LOOP FOR ADDING BOOK IN FILE.
        {
            fseek(addptr,0,SEEK_END);// MOVING POINTER TO REQUIRED LOCATION.
            //GETTING INPUTS.
            gotoxy(69,16);
            printf("Enter Book Serial:");
            fflush(stdin);
            scanf(x.book_serial);
            gotoxy(69,18);
            printf("Enter ISBN number:");
            fflush(stdin);// CLEARING BUFFERS.
            scanf("%d",&x.isbn);
            gotoxy(69,20);
            printf("Enter Book Name:");
            fflush(stdin);
            gets(x.book_name);
            gotoxy(69,22);
            printf("Enter Edition:");
            scanf("%d",&x.edition);
            gotoxy(69,24);
            printf("Enter Author:");
            fflush(stdin);
            gets(x.author);
            gotoxy(69,26);
            printf("Enter Reserved or Not(yes/no):");
            gets(x.Is_reserved);
            system("CLS");
            fwrite(&x,sizeof(x),1,addptr);
            gotoxy(69,4);
            printf("Do you want to add another book?(y/n)");
            fflush(stdin);//CLEARING BUFFER.
            scanf("%c",&choice);//CHOICE VARIBALE.
            if (choice=='y')
                continue;
            else
                break;
        }

}
void remove_book(struct book x, FILE *remove_ptr)//FUNCTION BODY
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("REMOVE BOOK \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n \n");
    char name[25];//VARIABLE FOR GETTING NAME OF BOOK TO DELETE.
    int verify=0; //VARIABLE FOR VERIFYING DELETION.
    while (1)
    {
        gotoxy(60,16);
        printf("Enter the Name of Book you want to Remove:");
        fflush(stdin);
        gets(name);//GETTING BOOK NAME.
        FILE *ptx;  //CREATING NEW FILE.
        ptx = fopen("remove_file.exe","wb"); //OPENING NEW FILE.
        rewind(remove_ptr); //REWINDING POINTER.
        while (fread(&x, sizeof(x),1, remove_ptr)== 1)//CONDITION FOR SEARCHING THE REQUIRED BOOK.
            {
                if (strcmp(name,x.book_name) == 0 )//CONDITION FOR CHECKING BOOK IN DATABASE.
                    {
                        gotoxy(69,18);
                        printf("Book is successfully removed!\n");
                        verify=1;
                        break;
                    }

            }
        if (verify == 0)
            {
                gotoxy(60,18);
                printf("Please Enter valid Book Name....\n");
            }
        rewind(remove_ptr);
        while (fread(&x, sizeof(x),1, remove_ptr)== 1)
            {
                if (strcmp(name,x.book_name) != 0 )//REMOVING BOOK FROM DATABASE.
                {
                    fwrite(&x, sizeof(x),1,ptx);
                }
            }
        fclose(remove_ptr);//CLOSING FILES
        fclose(ptx);
        fflush(stdin);
        remove("records_file.exe");//REMOVING OLD FILE.
        fflush(stdin);
        rename("remove_file.exe","records_file.exe");//RENAMING NEW FILE AS OLD FILE.
        remove_ptr= fopen("records_file.exe","rb+");//OPENING NEW FILE DATABASE.
        printf("\n \nDo you want to Remove another Book?(y/n)");
        scanf("%c",&choice);//CHOICE VARIBALE.
            if (choice=='y')
                {
                    system("CLS");
                    continue;
                }
            else
                break;
    }

}
void search_book(struct book x, FILE *search_ptr)//FUNCTION BODY.
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("SEARCH BOOK \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    int choose,isbn,found;//DECLARING AND INITIALIZING VARIABLES.
    char book_name[25], author_name[25];
    while (1)
    {
        found =0;
        gotoxy(57,16);
        printf("Enter the Integer from following to Search Book:");
        gotoxy(57,18);
        printf("1 By ISBN.");
        gotoxy(57,20);
        printf("2 By Book Name.");
        gotoxy(57,22);
        printf("3 By Author Name.\n");
        scanf("%d", &choose);//GETTING INPUT FROM USER WITH WHAT RESPECT HE WANTS TO SEARCH BOOK.
        rewind(search_ptr);
        if (choose == 1)
        {
            gotoxy(57,26);
            printf("Enter the ISBN number of Book you want to search:");
            scanf("%d", &isbn);
            while (fread(&x,sizeof(x),1,search_ptr)==1)//MATCHING ISBN NUMBER.
            {
                if (x.isbn== isbn)
                {
                    found=1;
                    gotoxy(57,28);
                    printf("Record of Book with ISBN %d is as Follows:\n",isbn);
                    gotoxy(0,32);
                    printf("Book Serial %d.\nBook Name %s.\nBook Edition %d.\nBook Author %s.\nIs Book Reserved? %s.\n \n",x.book_serial,x.book_name,x.edition,x.author,x.Is_reserved);
                    break;
                }
            }
            if (found==0)
                {
                    gotoxy(57,28);
                    printf("No Record Found!\n");
                }
        }
        else if (choose ==2)
        {
            gotoxy(57,26);
            printf("Enter the Name of Book you want to search:");
            fflush(stdin);
            gets(book_name);
            while (fread(&x,sizeof(x),1,search_ptr)==1)//MATCHING BOOK NAME.
            {
                if(strcmp(book_name,x.book_name)==0)
                {
                    found=1;
                    gotoxy(57,28);
                    printf("Record of Book Name %s is as Follows:\n",book_name);
                    gotoxy(0,32);
                    printf("Book Serial %d.\nBook ISBN %d.\nBook Edition %d.\nBook Author %s.\nIs Book Reserved? %s.\n",x.book_serial,x.isbn,x.edition,x.author,x.Is_reserved);
                    break;
                }
            }
            if (found==0)
            {
                gotoxy(57,28);
                printf("No Record Found!\n");
            }
        }
        else if (choose ==3)
        {
            gotoxy(57,26);
            printf("Enter the Name of Author of Book you want to search:");
            fflush(stdin);
            gets(author_name);
            while (fread(&x,sizeof(x),1,search_ptr)==1)//MATCHING AUTHOR OF BOOK.
            {
                if(strcmp(author_name,x.author)==0)
                {
                    found=1;
                    gotoxy(57,28);
                    printf("Record of Book with Author %s is as Follows:\n",author_name);
                    gotoxy(0,32);
                    printf("Book Serial %d.\nBook ISBN %d.\nBook Edition %d.\nBook Name %s.\nIs Book Reserved? %s.\n",x.book_serial,x.isbn,x.edition,x.book_name,x.Is_reserved);
                    break;
                }
            }
            if (found==0)
            {
                gotoxy(57,28);
                printf("No Record Found!\n");
            }
        }
        gotoxy(57,36);
        printf("Do You want to Search another Book(y/n)?");
        fflush(stdin);
        scanf("%c",&choice);//CHOICE VARIBALE.
        system("CLS");
        if (choice=='y')
        {
            continue;
        }
        else
            break;
    }
}
void modify_record(struct book x,FILE* modify_ptr)//BODY OF FUNCTION.
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("MODIFY BOOK \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    int choose,temp; //VARIABLE DECLARATION.
    char modify[25];// STRING DECLARATION.
    while (1)
    {
        gotoxy(57,16);
        printf("Enter the Name of the Book to Modify:");
        fflush(stdin);
        gets(modify);
        rewind(modify_ptr);//REWINDING POINTER.
        while (fread(&x, sizeof(x), 1, modify_ptr) == 1)//COMPARING THE POINTER.
        {
            temp=0;
            if (strcmp(modify,x.book_name)== 0)
            {
                printf("What do you want to Modify?\n \n1 for Serial.\n \n2 for ISBN.\n \n3 for Name.\n \n4 for Edition.\n \n5 for Author.\n \n6 for Reservations.\t");
                scanf("%d", &choose);//GETTING INPUT WHAT USER WANTS TO MODIFY.
                switch(choose)//SWITCH STATEMENT ACCORDING TO USER CHOICE.
                {
                case 1:
                    gotoxy(57,32);
                    printf("Enter New Serial:");
                    scanf("%d", &x.book_serial);
                    break;
                case 2:
                    gotoxy(57,32);
                    printf("Enter New ISBN:");
                    scanf("%d", &x.isbn);
                    break;
                case 3:
                    gotoxy(57,32);
                    printf("Enter New Name Of Book:");
                    fflush(stdin);
                    gets(x.book_name);
                    break;
                case 4:
                    gotoxy(57,32);
                    printf("Enter New Edition:");
                    scanf("%d", &x.edition);
                    break;
                case 5:
                    gotoxy(57,32);
                    printf("Enter Modified Author Name:");
                    fflush(stdin);
                    gets(x.author);
                    break;
                case 6:
                    gotoxy(57,32);
                    printf("Enter Reserved (Yes/No):");
                    scanf("%s", x.Is_reserved);
                    break;
                default:
                    printf("Please Enter Valid Integer Number.");
                    break;
                }
            fseek(modify_ptr,-sizeof(x),SEEK_CUR);//SEEKING THE LOCATION TO MODIFY DATA.
            fwrite(&x,sizeof(x),1, modify_ptr);//MODIFYING DATA.
            gotoxy(57,34);
            printf("Modification Applied Successfully!\n");
            temp=1;
            break;
            }
        }
        if (temp==0)
        {
            printf("Book not available!\n");
        }
        printf("Do you want to Make another Modification(y/n)?");
        fflush(stdin);
        scanf("%c",&choice);//CHOICE VARIBALE.
        system("CLS");
            if (choice=='y')
                continue;
            else
                break;
    }

}
void display_books(struct book x, FILE*show_ptr)//BODY OF FUNCTION.
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("ALL BOOKS AVAILABLE \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n \n \n");
    printf("%-30s %-30s %-30s  %-30s %-30s %-30s", "|Serial Number|", "|ISBN Number|", "|Book Name|", "|Edition|", "|Author|", "|Reserve|");
    gotoxy(0,18);
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    rewind(show_ptr);
    while (fread(&x, sizeof(x), 1, show_ptr) == 1)//CONDITION FOR READING ALL THE DATA IN FILE.
    {
        if (x.book_serial != 0 && x.isbn != 0)
        {//PRINTING THE REQUIRED DATA.

            printf("%-30d %-30d %-30s %-30d %-30s %-30s\n \n", x.book_serial, x.isbn, x.book_name, x.edition, x.author, x.Is_reserved);
        }
    }
}
void issue_book(struct book x, FILE *issue_ptr)//BODY OF FUNCTION.
{
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("ISSUE BOOK \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    char name[25];//INITIALIZING REQUIRED VARIABLES.
    int verify;
    while(1)
    {
        verify=0;
        gotoxy(62,16);
        printf("Enter the Name of the Book to be Issued:");
        fflush(stdin);
        gets(name);//GETTING INPUT OF THE BOOK TO BE ISSUED.
        rewind(issue_ptr);
        while (fread(&x,sizeof(x),1,issue_ptr)==1)//SEARCHING BOOK IN DATABASE.
        {
            if(strcmp(name, x.book_name) == 0 && strcmp(x.Is_reserved,"no")==0)
            {
                gotoxy(65,18);
                printf("Book is issued Successfully!\n");
                strcpy(x.Is_reserved,"yes");
                fseek(issue_ptr,-sizeof(x),SEEK_CUR);
                fwrite(&x, sizeof(x),1,issue_ptr);
                verify=1;
                break;
            }
            if (verify == 0)
            {
                gotoxy(65,18);
                printf("BOOK not Found or ISSUED!\n");
            }
        }
        printf("Do you want to Issue another Book(y/n)?");
        fflush(stdin);
        scanf("%c",&choice);//CHOICE VARIBALE.
        system("CLS");
        if (choice=='y')
            continue;
        else
            break;
    }

}
void Exit()//EXIT FUNCTION.
{//BODY.
    system("color 70");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    for(mod=0;mod<=73;mod++)
        printf(" ");
    printf("Exit \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    gotoxy(72,16);
    printf("BYE BYE!");
    exit(0);
}
void welcome()
{
    system("color F0");
    int mod;
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("_-");
    printf("\n \n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n \n");
    Sleep(1000);
    for(mod=0;mod<=60;mod++)
        printf(" ");
    printf("LIBRARY MANAGEMENT SYSTEM \n\n");
    for(mod=0;mod<=160;mod++)
        printf(".");
    printf("\n");
    for(mod=0;mod<=160;mod++)
        printf("=");
    printf("\n \n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n \n");
    Sleep(1000);
    for(mod=0;mod<=65;mod++)
        printf(" ");
    printf("SEMESTER PROJECT\n \n");
    Sleep(1000);
    for(mod=0;mod<=67;mod++)
        printf(" ");
    printf("FA20-BCS-065\n \n");
    Sleep(1000);
    for(mod=0;mod<=63;mod++)
        printf(" ");
    printf("MUHAMMAD JUNAID NADEEM\n");
    printf("\n \n");
    Sleep(1000);
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n");
    for(mod=0;mod<=80;mod++)
        printf("-_");
    printf("\n \n");
    Sleep(1000);
    for(mod=0;mod<=71;mod++)
        printf(" ");
    printf("Welcome\n \n \n \n");
    system("pause");
    system("CLS");
}
gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void MaximizeOutputWindow()
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

