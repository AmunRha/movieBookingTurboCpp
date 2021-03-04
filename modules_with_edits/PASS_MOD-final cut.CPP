#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>

class login_data
 {
	char username[11];
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

void print_front_layout()
{
	settextstyle(10,0,5);
	setcolor(10);
	outtextxy(120,20,"LOGIN PAGE");
	setcolor(BLUE);
	rectangle(120,200,500,300);
	rectangle(125,205,495,295);
	settextstyle(0,0,4);
	setcolor(BROWN);
	outtextxy(180,240,"1.LOGIN");
	setcolor(BLUE);
	rectangle(120,310,500,410);
	rectangle(125,315,495,405);
	setcolor(BROWN);
	outtextxy(180,350,"2.CREATE");
	setcolor(BLUE);
	rectangle(120,120,500,190);
	rectangle(125,125,495,185);
	setcolor(MAGENTA);
	settextstyle(0,0,0);
	outtextxy(130,130,"Enter your choice");
	outtextxy(130,150,"Press '1' to LOGIN");
	outtextxy(130,160,"Press '2' to CREATE");
	outtextxy(130,170,"Press '3' to EXIT");
}

void exit_mod()
{
   setcolor(RED);
   settextstyle(1,0,2);
   setviewport(109,156,472,382,1);
   clearviewport();
   setviewport(0,0,getmaxx(),getmaxy(),1);
   setcolor(BLUE);
   rectangle(110,160,470,380);
   rectangle(115,165,465,375);
   setcolor(RED);
    /*setviewport(117,170,462,252,0);
    clearviewport();
    setviewport(0,0,getmaxx(),getmaxy(),1);*/
   outtextxy(218,249,"Exiting in ");
   for(int i=5;i>=0;i--)
   {
      gotoxy(42,17);
      cout<<i<<"\b";
      delay(1000);
   }
   exit(0);
   /*setviewport(122,122,498,188,1);
   clearviewport();
   setviewport(0,0,getmaxx(),getmaxy(),1);
   setcolor(RED);
   settextstyle(1,0,3);
   outtextxy(220,134,"Exiting in ");
   for(int i=5;i>=0;i--)
   {
      gotoxy(46,10);
      cout<<i<<"\b";
      delay(1000);
   }
   exit(0); */
}

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
 cleardevice();
 settextstyle(2,0,8);
 setcolor(GREEN);
 outtextxy(105,120,"Welcome to the CREATE Page");
 setcolor(BLUE);
 rectangle(5,155,245,215);
 rectangle(10,160,240,210);
 setcolor(LIGHTBLUE);
 setviewport(38,147,88,165,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),1);
 settextstyle(2,0,7);
 outtextxy(41,145,"Name");
 settextstyle(0,0,0);
 outtextxy(20,167,"Max 10. char");
 char name[50];
 gotoxy(4,12);
 gets(name);
 if(strcmpi(name,"e")==0)   //test purpose only
    exit(0);
 enter_id:
 setcolor(BLUE);
 rectangle(5,225,245,285);
 rectangle(10,230,240,280);
 setcolor(LIGHTBLUE);
 setviewport(38,220,122,250,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),1);
 settextstyle(2,0,7);
 outtextxy(41,215,"User ID");
 settextstyle(0,0,0);
 outtextxy(20,237,"Max. 15 char");
 char id[20];
 gotoxy(4,17);
 cin>>id;
 if(strcmpi(id,"e")==0)  //test purpose only
    exit(0);
 if(check_userID(id)==1)
    {
       setviewport(11,235,239,279,1);
       clearviewport();
       setviewport(0,0,getmaxx(),getmaxy(),1);
       settextstyle(0,0,0);
       setcolor(LIGHTRED);
       outtextxy(25,245,"User name already exists");
       getch();
       setviewport(11,235,239,279,1);
       clearviewport();
       setviewport(0,0,getmaxx(),getmaxy(),1);
       goto enter_id;
    }
 setcolor(BLUE);
 rectangle(5,295,245,355);
 rectangle(10,300,240,350);
 setcolor(LIGHTBLUE);
 setviewport(38,290,136,320,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),1);
 settextstyle(2,0,7);
 outtextxy(41,285,"Password");
 char pass[15];
 gotoxy(4,21);
 cin>>pass;
 if(strcmpi(pass,"e")==0) 	//test purpose only
    exit(0);
 l1.save_credentials(name,id,pass);
 setviewport(0,151,246,356,1);
 clearviewport();
 setviewport(0,0,getmaxx(),getmaxy(),1);
 setcolor(BLUE);
 rectangle(110,160,470,380);
 rectangle(115,165,465,375);
 setcolor(LIGHTGREEN);
 settextstyle(0,0,0);
 outtextxy(215,180,"Creation Succesful");
 outtextxy(130,260,"Redirecting you to login page in ");
 for(int i=5;i>=0;i--)
  {
     gotoxy(51,17);
     cout<<i<<"\b";
     delay(1000);
  }
 }

void login()
 {
 ifstream fu;
 int p=0;
 login_back:
 cleardevice();
 settextstyle(2,0,8);
 setcolor(GREEN);
 outtextxy(110,120,"Welcome to the LOGIN Page");
 setcolor(BLUE);
 rectangle(110,160,470,260);
 rectangle(115,165,465,255);
 rectangle(110,280,470,380);
 rectangle(115,285,465,375);
 setcolor(LIGHTBLUE);
 settextstyle(2,0,6);
 setviewport(153,272,235,290,1);
 clearviewport();
 outtextxy(3,0,"Password");
 setviewport(153,152,223,170,1);
 clearviewport();
 outtextxy(3,0,"User ID");
 setviewport(0,0,getmaxx(),getmaxy(),1);
 settextstyle(0,0,0);
 outtextxy(130,180,"Enter your UserID");
 outtextxy(325,245,"Press 'e' to exit");
 char id[20], pass[15];
 int f=1;
 gotoxy(29,14);
 cin>>id;
 if(strcmpi(id,"e")==0)
 {
    exit_mod();
    //exit_at_userid:

  }
 fu.open("User_Login_Data.bat",ios::binary);
 while(fu.read((char*)&l1,sizeof(l1)))
	{
	if(strcmpi(id,l1.ret_userID())==0)
	 {  int count_lg=0;f=0;
	    login_pass:
	    setcolor(LIGHTBLUE);
	    outtextxy(130,300,"Enter your Password");
	    gotoxy(29,21);
	    cin>>pass;   // presntation edit 1
	    if(strcmp(pass,l1.ret_userpass())==0)
	     {
		setviewport(109,156,472,382,1);
		clearviewport();
		setviewport(0,0,getmaxx(),getmaxy(),1);
		setcolor(BLUE);
		rectangle(110,160,470,380);
		rectangle(115,165,465,375);
		setcolor(LIGHTGREEN);
		outtextxy(225,180,"Login Succesful");
		settextstyle(0,0,2);
		outtextxy(195,240,"Welcome Back, ");
		//setviewport(300,0,640,480,1);
		//settextjustify(CENTER_TEXT,TOP_TEXT);
		settextstyle(3,0,0);
		//outtextxy(0,0,l1.ret_username());
		outtextxy(225,280,l1.ret_username());
		delay(5000);
		exit(0);
	     }
	    else
	     {
		setviewport(117,292,463,373,1);
		clearviewport();
		setviewport(0,0,getmaxx(),getmaxy(),1);
		setcolor(LIGHTRED);
		outtextxy(170,320,"Wrong password, try again");
		getch();
		count_lg++;
		if(count_lg==5)
		 {
		    setviewport(109,156,472,382,1);
		    clearviewport();
		    setviewport(0,0,getmaxx(),getmaxy(),1);
		    setcolor(BLUE);
		    rectangle(110,160,470,380);
		    rectangle(115,165,465,375);
		    setcolor(RED);
		    outtextxy(227,180,"Login Failed");
		    /*setviewport(117,170,462,252,0);
		    clearviewport();
		    setviewport(0,0,getmaxx(),getmaxy(),1);*/
		    setcolor(LIGHTRED);
		    outtextxy(130,250,"Unable to Login(no. of attempts exceeded)");
		    outtextxy(130,270,"Press any key to exit");
		    getch();
		    exit_mod();
		    //goto exit_at_userid;
		    /*setviewport(117,292,463,373,1);
		    clearviewport();
		    setviewport(0,0,getmaxx(),getmaxy(),1);
		    setcolor(LIGHTRED);
		    outtextxy(130,300,"Unable to Login(no. of attempts exceeded)");
		    outtextxy(130,320,"Press any key to exit");
		    getch();
		    exit(0);*/
		 }
		setviewport(117,292,463,373,1);
		clearviewport();
		setviewport(0,0,getmaxx(),getmaxy(),1);
		goto login_pass;
	      }
	 }
	 else
	  f=1;
	}
 fu.close();
 if(f!=0)
  {
      setviewport(109,156,472,382,1);
      clearviewport();
      setviewport(0,0,getmaxx(),getmaxy(),1);
      setcolor(BLUE);
      rectangle(110,160,470,380);
      rectangle(115,165,465,375);
      setcolor(RED);
      outtextxy(229,180,"Login Failed");
      /*setviewport(117,170,462,252,0);
      clearviewport();
      setviewport(0,0,getmaxx(),getmaxy(),1);
      settextstyle(0,0,0);*/
      setcolor(LIGHTRED);
      outtextxy(121,250,"UserID you entered doesnt exist. Try again");
      p++;
      if(p==5)
       {
	 setviewport(109,156,472,382,1);
	 clearviewport();
	 setviewport(0,0,getmaxx(),getmaxy(),1);
	 setcolor(BLUE);
	 rectangle(110,160,470,380);
	 rectangle(115,165,465,375);
	 setcolor(RED);
	 outtextxy(227,180,"Login Failed");
	 /*setviewport(117,170,462,252,0);
	 clearviewport();
	 setviewport(0,0,getmaxx(),getmaxy(),1);*/
	 setcolor(LIGHTRED);
	 outtextxy(130,250,"Unable to Login(no. of attempts exceeded)");
	 outtextxy(130,270,"Press any key to exit");
	 getch();
	 exit_mod();
	 //goto exit_at_userid;
	}
       getch();
       setviewport(117,170,462,252,0);
       clearviewport();
       setviewport(0,0,getmaxx(),getmaxy(),1);
       goto login_back;
    }
 fu.close();
 }

void main()
 {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	ofstream fu("User_Login_Data.bat",ios::ate|ios::binary);
	cleardevice();
	print_front_layout();
	gotoxy(37,9);
	int choice_lc;
	cin>>choice_lc;
	if(choice_lc==3)
	     exit_mod();
	cleardevice();
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
