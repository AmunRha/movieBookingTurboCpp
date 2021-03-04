#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>

class login_data
 {
	char username[50];
	char userID[20];
	char userpass[15];

	public:

	char* ret_username()
	 {
	 return username;
	 }

	char* ret_userID()
	 {
	 return userID;
	 }

	char* ret_userpass()
	{
	return userpass;
	}

	void save_credentials(char name[],char ID[],char pass[])
	 {
	 strcpy(username,name);
	 strcpy(userID,ID);
	 strcpy(userpass,pass);
	 }
 }l1;

int check_userID(char id[])
 {
 ifstream fu("User_Login_Data.bat",ios::binary);;
 int f=0;
 while(fu.read((char*)&l1,sizeof(l1)))
  {
     if(strcmpi(id,l1.ret_userID())==0)
      {
	 f=1;
	 return f;
      }
  }
 if(f!=1)
      return 0;

 }


void create()
 {
 cout<<"\nEnter your Name [max 50]\n";
 char name[50];
 gets(name);
 enter_id:
 cout<<"\nEnter your UserID [max 20]\n";
 char id[20];
 cin>>id;
 if(check_userID(id)==1)
    {
       cout<<"\nUser name already exists\n";
       goto enter_id;
    }
 cout<<"\nEnter your Password [max 15]\n";
 char pass[15];
 cin>>pass;
 l1.save_credentials(name,id,pass);
 cout<<"\nYou have succesfully created a new account!\n";
 delay(800);
 cout<<"\nRedirecting you to login page in ";
 for(int i=5;i>=0;i--)
  {
     cout<<i<<"\b";
     delay(1000);
  }
 }

void login()
 {
 ifstream fu;
 clrscr();
 int p=0;
 cout<<"\nWelcome to the Login Page\n";
 login_back:
 cout<<"\nEnter your UserID\n";
 char id[20], pass[15];
 int f=1;
 cin>>id;
 fu.open("User_Login_Data.bat",ios::binary);
 while(fu.read((char*)&l1,sizeof(l1)))
	{
	if(strcmpi(id,l1.ret_userID())==0)
	 {  int count_lg=0;f=0;
	    login_pass:
	    cout<<"\nEnter your Password\n";
	    cin>>pass;   // presntation edit 1
	    if(strcmp(pass,l1.ret_userpass())==0)
	     {
		cout<<"\nYou have succesfully Logged in\nWelcome Back, "<<l1.ret_username()<<endl;
		delay(5000);
		exit(0);
	     }
	    else
	     {
		cout<<"\nWrong password";
		count_lg++;
		if(count_lg==5)
		 {
		    cout<<"\nToo many attempts of login\n";
		    cout<<"Exiting in ";
		    for(int i=5;i>=0;i--)
		     {
			cout<<i<<"\b";
			delay(1000);
		     }
		 }
		goto login_pass;
	      }
	 }
	 else
	  f=1;
	}
 fu.close();
 if(f!=0)
  {
      cout<<"\nUserID you entered doesnt exist. Try again\n";
      p++;
      if(p==5)
       {
	 cout<<"\nToo many attempts of login\n";
	 cout<<"Exiting in ";
	 for(int i=5;i>=0;i--)
	  {
	     cout<<i<<"\b";
	     delay(1000);
	  }
	 exit(0);
	}
       goto login_back;
    }
 fu.close();
 }

void main()
 {      ofstream fu("User_Login_Data.bat",ios::ate|ios::binary);
	clrscr();
	cout<<"\t\t\tLOGIN PAGE\n";
	cout<<"1.Login\n2.Create\n3.Exit\n";
	int choice_lc;
	cin>>choice_lc;
	if(choice_lc==3)
	 {
	    cout<<"\nExiting in ";
	    for(int i=5;i>=0;i--)
	     {
		cout<<i<<"\b";
		delay(1000);
	     }
	    exit(0);
	 }
	clrscr();
	switch(choice_lc)
	 {
		case 1:	login();
			break;


		case 2: create();
			fu.write((char*)&l1,sizeof(l1));
			fu.close();
			login();
			break;

	 }

 getch();
 }
