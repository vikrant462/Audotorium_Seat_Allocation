#include<stdio.h>
#include<conio.h>
#include<process.h>    //exit
#include<unistd.h>     //sleep
#include<string.h>
layout()
{
	system("color 04");
	int i;
	printf("\n\n\n");
	printf("    ___________________________________________________________________\n");
	for(i=0;i<3;i++)
	printf("   |                                                                   |\n");
	printf("   |            ~~~~~WELCOME TO VIKRANT AUDOTORIUM~~~~~                |\n");
	for(i=0;i<3;i++)
	printf("   |                                                                   |\n");
	printf("   |___________________________________________________________________|\n");
	printf("\n");

	for(i=1;i<=100;i++)
	{
		if((i-1)%10==0)
		printf("    )(         ");
		printf("%3d ",i);
		if(i%5==0&&i%10!=0)
		printf("|    |");
		if(i%10==0)
		printf("        )(\n");
	}
	printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
	sleep(1);
}
	//////////////////////////////////////////////
	welcome_page()
	{
	    int n;
		printf("            ~~~~~~~~~~~~~~~~~Enter Your Choice~~~~~~~~~~~~~~~~~~\n\n");
		printf("                          ----------------------- \n");
		printf("                         |   1.Manager Acess     |\n");
		printf("                         |   2.Booking Ticket    |\n");
		printf("                         |   3.Cancel Ticket     |\n");
		printf("                         |   4.Show Booked Seat  |\n");
		printf("                         |   5.Save & Exit       |\n");
	    printf("                          ----------------------- \n\t\t");
		scanf("%d",&n);
		return (n);
	}
	/////////
	copy()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;
    fptr1 = fopen("new1.txt","r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n","new1.txt");
        exit(0);
    }
 
    fptr2 = fopen("new.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n","new.txt");
        exit(0);
    }
    c = fgetc(fptr1);
    while (c!=EOF)
    {
        fputc(c,fptr2);
        c = fgetc(fptr1);
    }
    //printf("\nContents copied to %s", filename);
    fclose(fptr1);
    fclose(fptr2);
}
	/////////
		cancel_ticket()
      {       
        system("cls");
        show_booked_seat();
		int delete_line,t=0;
		char s[15],c=' ';
		FILE *fptr1,*fptr2;
		fptr1=fopen("new.txt","r");
		fptr2=fopen("new1.txt","w");
		if(fptr1==NULL||fptr2==NULL)
		{
	    printf("                     File Not found\n");
        }
    	printf("\n\t\t\tEnter Seat Number to be Canceled\n\t\t\t");
        scanf("%d", &delete_line);
       //scanf("%s",&c);
       fflush(stdin);
       fgets(s,15,fptr1);
      while(!feof(fptr1))
      {
	 t++;
	 if(t!=delete_line)
	 	fprintf(fptr2,"%s",s);
     else
     {
     fprintf(fptr2,"XXXXXX\n");
     }
     fgets(s,15,fptr1);
     }
     fclose(fptr1);
     fclose(fptr2);
     remove("new.txt");
     copy();
     printf("\tPress 'Y' for more Cancelling\n\t\t");	
     scanf("%c",&c);
     if(c=='y'||c=='Y')
     cancel_ticket();
     //fclose(fptr1);
     //fclose(fptr2);
   }
	/////////
	display_name()
	{
		system("cls");
		int i;
		printf("\t\t\t\t\t\t\t\t\t\t\t    ~~~~~~!Persons Name!~~~~~~\n\n");
		FILE *fptr;
		fptr=fopen("new.txt","r");
		if(fptr==NULL)
		{
	    printf("                        File Not Found\n");
        }
        for(i=1;i<=100;i++)
	{
		char s[15]="              ";
		char c[]=" ";
		fgets(c,15,fptr);
		int l=strlen(c);
		strncpy(s,c,l-1);
		if((i-1)%10==0)                        //for decorative purpose
		printf("                 ");
		if(s[0]=='-')
		{
		printf("%3d%s",i,s);
	    }
		else
        printf("%3d-______       ",i);
		if(i%5==0&&i%10!=0)
		printf("|    |");
		if(i%10==0)
		printf("\n");
	}
        printf("\n\n");
	}
	///////////////////////////////////////////////
    int	total_res_seat()
	{
		system("cls");
		int n=0,i;
		FILE *fptr;
	    fptr=fopen("new.txt","r");
		if(fptr==NULL)
		{
	    printf("                        File Not Found\n");
        }
        for(i=1;i<=100;i++)
        {
        char s[3]=" ";
		fgets(s,10,fptr);
		if(s[0]=='-')
		n++;
	    }
		printf("                      Total Reserved Seats Are:- %d\n",n);
		printf("                      Total Vacant Seats Are:- %d\n\n\n",100-n);
		return n;
	}
	/////////
	int total_collection()
	{
		int n=total_res_seat();
		system("cls");
		printf("\t\t\tFee Charge Per Head is 200\n");
		printf("                        Total Collection:-%d\n\n",n*200);
	}
	//////////////////////
    int	booking_ticket()
	{   
	    show_booked_seat();
		int delete_line,t=0;
		char s[15],c=' ';
		FILE *fptr1,*fptr2;
		fptr1=fopen("new.txt","r");
		fptr2=fopen("new1.txt","w");
		if(fptr1==NULL||fptr2==NULL)
		{
	    printf("                     File Not found\n");
        }
    	printf("\n\t\t\tEnter Seat Number to be Booked\n\t\t\t");
        scanf("%d", &delete_line);
    //scanf("%s",&c);
    fflush(stdin);
    fgets(s,15,fptr1);
    while(!feof(fptr1))
    {
	 t++;
	 if(t!=delete_line)
	 	fprintf(fptr2,"%s",s);
     else
     {
     printf("              ......Enter The Name.....\n\t\t\t\t\t\t");
     fflush(stdin);
     gets(s);
     fprintf(fptr2,"-%s\n",s);
     }
     fgets(s,15,fptr1);
     }
     fclose(fptr1);
     fclose(fptr2);
     remove("new.txt");
    copy();
     printf("\t\t Press 'Y' for more Booking\n\t\t");	
     scanf("%c",&c);
     if(c=='y'||c=='Y')
     booking_ticket();
     //fclose(fptr1);
     //fclose(fptr2);
}
	///////////////////
int show_booked_seat()
	{
		system("cls");
		int i;
		printf("                \t\t\t\t!Reserved Seats!\n\n");
		FILE *fptr;
		fptr=fopen("new.txt","r");
		if(fptr==NULL)
		{
	    printf("                        File Not Found\n");
	    //exit(0);
        }
        for(i=1;i<=100;i++)
	{
		char s[15]="         ";
		char c[]=" ";
		fgets(c,15,fptr);
		int l=strlen(c);
		strncpy(s,c,l-1);
		if((i-1)%10==0)                        //for decorative purpose
		printf("                 ");
		if(s[0]=='-')
		printf("%3d**  ",i);
		else
        printf("%3d___ ",i);
		if(i%5==0&&i%10!=0)
		printf("|    |");
		if(i%10==0)
		printf("\n");
	}
        printf("\n\n");
	}
	////////////
	int manager_acess()
	{
		int n;
		printf("               _______Manager Section______\n");
		char key[10]="123",pass[10];
		ty:
		printf("              ......Enter The Password.....\n\t\t\t\t\t\t");
		scanf("%s",pass);
		if(strcmp(pass,key)==0)
		{
		printf("                               !Login Successful!   \n");
		tx:
		printf("              ~~~~~~~~~~~~~~~~~~Enter Your Choice~~~~~~~~~~~~~~~~~~\n\n");
		printf("                          ----------------------------- \n");
		printf("                         |   1.Display The Name Of     |\n");
		printf("                         |        Each Person          |\n");
		printf("                         |   2.Total Reserved Seats    |\n");
		printf("                         |   3.Total Collection        |\n");
		printf("                         |   4.Exit & Save             |\n");
	    printf("                          ----------------------------- \n\t\t");
		scanf("%d",&n);
		}
		else
		{
			printf("\t\t\tWrong Password\n");
		goto ty;
	    }
		switch(n)
		{
			case 1:
				display_name();
				goto tx;
			case 2:
			     total_res_seat();
				 goto tx;
			case 3:
			      total_collection();
				 goto tx;
		    case 4:
			      exit (0);	   
			default:
			       printf("                               Enter Valid Option\n");
			     goto tx;	     	
		}
	}
	////////////////////
int main()
{
	int n;
	layout();
	tx:
	n=welcome_page();
	switch(n)
	{
		case 1:
			manager_acess();
		    goto tx;
		case 2:
			system("cls");
			booking_ticket();
		    goto tx;
		case 3:
			cancel_ticket();
			goto tx;
		case 4:
		    show_booked_seat();
		    goto tx;
		case 5:
		    exit (0);	
		default:
			printf("                               Enter Valid Option\n");
		    goto tx;	     	
	}
	return 0;
}
