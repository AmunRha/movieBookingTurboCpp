#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<ctype.h>
#include<time.h>

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

void stage_1_login();

void exit_mod(char s='z')
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
   if(s=='s')
      outtextxy(170,249,"Signing out in ");
   else
      outtextxy(218,249,"Exiting in");
   for(int i=5;i>=0;i--)
   {
      gotoxy(42,17);
      cout<<i<<"\b";
      delay(1000);
   }
   if(s=='s')
      stage_1_login();
   else
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
 return -1;
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
	    char star[7],temp;
	    star[0]='~';star[1]='!';star[2]='#';star[3]='$';star[4]='&';star[5]='*';star[6]='@';
	    randomize();
	    for(int i=0;;)
	    {
	       temp=getch();
	       if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||(temp>='0'&&temp<='9'))
	       {
		  pass[i++]=temp;
		  int j=random(7);
		  cout<<star[j];
	       }
	       if(temp==13||temp==10)
	       {
		  pass[i]='\0';
		  break;
	       }
	    }
	    //char star;
	    /*for(int i=0;;)
	    {
	       star=getch();
	       if((star>='a'&&star<='z')||(star>='A'&&star<='Z')||(star>='0'&&star<='9'))
	       {
		  pass[i++]=star;
		  cout<<'*';
	       }
	       if(star==13||star==10)
	       {
		  pass[i]='\0';
		  break;
	       }

	    }*/
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
		settextstyle(3,0,0);
		outtextxy(225,280,l1.ret_username());
		settextstyle(0,0,0);
		outtextxy(150,340,"Redirecting you to Home page in ");
		   for(int i=5;i>=0;i--)
		   {
		      gotoxy(52,22);
		      cout<<i<<"\b";
		      delay(1000);
		   }
		break;
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
		    setcolor(LIGHTRED);
		    outtextxy(130,250,"Unable to Login(no. of attempts exceeded)");
		    outtextxy(130,270,"Press any key to exit");
		    getch();
		    exit_mod();
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
	 setcolor(LIGHTRED);
	 outtextxy(130,250,"Unable to Login(no. of attempts exceeded)");
	 outtextxy(130,270,"Press any key to exit");
	 getch();
	 exit_mod();
	}
       getch();
       setviewport(117,170,462,252,0);
       clearviewport();
       setviewport(0,0,getmaxx(),getmaxy(),1);
       goto login_back;
    }
 fu.close();
 }

 //All functions of Movie detail showing starts from here

struct movie_details
{
   char name[50];
   char code[10];
   char release_date[10];
   char runtime[20];
   char cast[100];
   char synopsis[200];
   char rating[10];
   char language[15];
}m;

void print_rectangle()
{
   outtextxy(0,10,"1.All Movies");
   outtextxy(220,10,"2.Tamil");
   outtextxy(380,10,"3.Hindi");
   outtextxy(560,10,"4.English");
   setcolor(RED);
   rectangle(10,110,328,294);
   rectangle(15,115,323,289);
   setcolor(BLUE);
   rectangle(332,110,628,294);
   rectangle(337,115,623,289);
   setcolor(GREEN);
   rectangle(10,298,328,476);
   rectangle(15,303,323,471);
   setcolor(YELLOW);
   rectangle(332,298,628,476);
   rectangle(337,303,623,471);
   setcolor(13);
   rectangle(10,30,628,106);
   rectangle(15,35,623,101);
}

void print_movie_details(int i)
{
    int x,y;
    setcolor(11);
    if(i==1)
    {
       x=20;y=122;
    }
    else if(i==2)
    {
       x=342;y=122;
    }
    else if(i==3)
    {
       x=20;y=309;
    }
    else
    {
       x=342;y=309;

    }
    outtextxy(x,y,m.name);
    outtextxy(x,y+20,m.code);
    outtextxy(x,y+40,m.runtime);
    outtextxy(x,y+60,m.rating);
    outtextxy(x,y+80,m.language);

}

void print_poster(movie_details m)
{
 setcolor(LIGHTBLUE);
 fstream p;
 int i=50,j=60;
 if(strcmpi(m.code,"005")==0)
 {
    p.open("Starwar.txt",ios::in|ios::out);
    i=30;
    j=0;
 }
 else if(strcmpi(m.code,"002")==0)
 {
    i=150;
    j=10;
    p.open("24.txt",ios::in|ios::out);
 }
 else if(strcmpi(m.code,"003")==0)
 {
    p.open("2_0.txt",ios::in|ios::out);
    i=230;
    j=0;
 }
 else if(strcmpi(m.code,"004")==0)
 {
    p.open("Kabir.txt",ios::in|ios::out);
    i=30;
    j=0;
 }
 else if(strcmpi(m.code,"001")==0)
 {
   p.open("XMEN_logo_1.txt",ios::in|ios::out);
   i=230;
   j=5;
 }
 else if(strcmpi(m.code,"006")==0)
 {
    p.open("simba.txt",ios::in|ios::out);
    i=200;
    j=0;
 }
 else if(strcmpi(m.code,"007")==0)
 {
    p.open("96.txt",ios::in|ios::out);
    i=180;
    j=40;
 }
 else if(strcmpi(m.code,"008")==0)
 {
    p.open("raees.txt",ios::in|ios::out);
    i=200;
    j=5;
 }
 else if(strcmpi(m.code,"009")==0)
 {
    p.open("wonder.txt",ios::in|ios::out);
    i=150;
    j=5;
 }
 char c[200];
 while(p.getline(c,200))
  {
  if(p.eof())
   break;
  i=i+10;
  setviewport(15,15,625,465,1);
  outtextxy(j,i,c);
  }
 setviewport(0,0,getmaxx(),getmaxy(),1);
 p.close();
}

void proceed_Mov_Det(movie_details m)
{
   cleardevice();
   print_poster(m);
   setcolor(LIGHTRED);
   rectangle(10,10,630,470);
   rectangle(15,15,625,465);
   outtextxy(20,20,"Name: ");
   outtextxy(130,20,m.name);
   outtextxy(20,40,"Code: ");
   outtextxy(130,40,m.code);
   outtextxy(20,60,"Language: ");
   outtextxy(130,60,m.language);
   outtextxy(20,80,"Rating: ");
   outtextxy(130,80,m.rating);
   outtextxy(20,100,"Runtine: ");
   outtextxy(130,100,m.runtime);
   outtextxy(20,120,"Release Date: ");
   outtextxy(130,120,m.release_date);
   outtextxy(20,140,"Cast: ");
   outtextxy(130,140,m.cast);
   outtextxy(20,160,"Synopsis: ");
   outtextxy(130,160,m.synopsis);
   outtextxy(130,180,"[Read more..]");
}

//seat selection functions starts from here

class seat
{
   char cord[2];
   int status;
   public:
   char* ret_cord()
   {
      return cord;
   }
   void assign_cord(char inp_cord[2],int n)
   {
      if(n==1)
	 strcpy(cord,inp_cord);
      else if(n==2)
	 strcat(cord,inp_cord);
   }
   int seatshow()
      {return status;}
   void seatocc()               //fills seat
      {status=1;}
   void seatrem()               //empties it
      {status=0;}
   void seatsel()               //temporary selection
      {status=2;}
}s[10][15];

fstream f,fb;
int n,k=0;
char scr_no[1];
int useless;
char useles;
char scr_tm[10];
int no_of_tick,c,row_no;

void decide_st(int opt=0)
   {
   if(strcmpi(m.code,"001")==0)
      {
	 f.open("seats1.txt",ios::in|ios::out|ios::ate);
	 fb.open("seats1_B.txt",ios::in|ios::out|ios::ate);
	 strcpy(scr_tm,"Mor");
	 strcpy(scr_no,"A");
      }
   else if(strcmpi(m.code,"002")==0)
   {
      f.open("seats2.txt",ios::in|ios::out|ios::ate);
      fb.open("seats2_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Mat");
      strcpy(scr_no,"A");
   }
   else if(strcmpi(m.code,"003")==0)
   {
      f.open("seats3.txt",ios::in|ios::out|ios::ate);
      fb.open("seats3_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Nit");
      strcpy(scr_no,"A");
   }
   else if(strcmpi(m.code,"004")==0)
   {
      f.open("seats4.txt",ios::in|ios::out|ios::ate);
      fb.open("seats4_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Mor");
      strcpy(scr_no,"B");
   }
   else if(strcmpi(m.code,"005")==0)
   {
      f.open("seats5.txt",ios::in|ios::out|ios::ate);
      fb.open("seats5_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Mat");
      strcpy(scr_no,"B");
   }
   else if(strcmpi(m.code,"006")==0)
   {
      f.open("seats6.txt",ios::in|ios::out|ios::ate);
      fb.open("seats6_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Nit");
      strcpy(scr_no,"B");
   }
   else if(strcmpi(m.code,"007")==0)
   {
      f.open("seats7.txt",ios::in|ios::out|ios::ate);
      fb.open("seats7_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Mor");
      strcpy(scr_no,"C");
   }
   else if(strcmpi(m.code,"008")==0)
   {
      f.open("seats8.txt",ios::in|ios::out|ios::ate);
      fb.open("seats8_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Mat");
      strcpy(scr_no,"C");
   }
   else if(strcmpi(m.code,"009")==0)
   {
      f.open("seats9.txt",ios::in|ios::out|ios::ate);
      fb.open("seats9_B.txt",ios::in|ios::out|ios::ate);
      strcpy(scr_tm,"Nit");
      strcpy(scr_no,"C");
   }
   if(opt==1)
      fb.close();
   else if(opt==2)
      f.close();
   }

void getlay(int a=1)
{
   for(int i=12;i>0;i--)
   {
       clrscr();
       gotoxy(26,10);
       if(a==1)
   cprintf("Getting the seat layout\n");
       else if(a==2)
   cprintf("Printing Bill, Please wait\n");
       gotoxy(26,13);
       int x=i%4;
       textcolor(BLUE);
       switch(x)
   {
      case 0:cprintf("-|-------     -------|-");break;
      case 1:cprintf("---|-----     -----|---");break;
      case 2:cprintf("-----|---     ---|-----");break;
      case 3:cprintf("-------|-     -|-------");break;
   }
       delay(250);
       textcolor(WHITE);
   }
   clrscr();
}

void seatconv(char a[2],int choi)
{
   decide_st(1);
   f.seekp(0,ios::beg);
   while(f.getline(a,3,'\n'))
   {
      for(int i=0;i<10;i++)
	 for(int j=0;j<15;j++)
	 {
	    if(strcmpi(a,s[i][j].ret_cord())==0)
	    {
		switch(choi)
		{
		   case 1:s[i][j].seatrem();break;
		   case 0:s[i][j].seatocc();break;
		   case 3:s[i][j].seatsel();break;
		}
	    }
	 }
   }
   f.close();
}

int fillcheck(char chk_cord[2])
{
   decide_st(1);
   f.seekp(0,ios::beg);
   char a[2];
   while(f.getline(a,3,'\n'))
   {
	    if(strcmpi(a,chk_cord)==0)
	    {
	       f.close();
	       return 1;
	    }

   }
   f.close();
   return 0;
}

int fillcheck(int chk_row,int opt=1)
{
   switch(opt)
   {
   case 1:
   decide_st(2);
   fb.seekp(0,ios::beg);
   int a;
   while(fb>>a)
   {
      if(a==chk_row)
      {
	 fb.close();
	 return 1;
      }
   }
   fb.close();
   return 0;
   case 2:

	    for(int i=0;i<15;i++)
	    if(s[chk_row][i].seatshow()==1)
	       return 1;
   return 0;
   }
   return -1;
}
				       //prints the rough layout
void print_layout()
{

   cout<<"\n";
   textcolor(MAGENTA);
   cprintf("              SCREEN ");
   cout<<scr_no<<"\t\t     ";
   textcolor(LIGHTMAGENTA);
   cprintf("SHOWTIME ");
   cout<<scr_tm<<"\n\n\t ";
   char a='A';
   for(int i=0;i<15;i++)
   {
      textcolor(WHITE);
      if(a=='H')
	 a++;
      if(i==7)
	 cout<<"   ";
      else
      {
	 cout<<a++<<"   ";
      }
   }
   cout<<endl;
   int n=0;
   for(i=0;i<10;i++)
   {
      cout<<endl<<n++<<"\t ";
      for(int j=0;j<15;j++)
      {
	 if(j==7)
	    cout<<"   ";
	 else if(s[i][j].seatshow()==0)
	 {
	    textcolor(GREEN);
	    cprintf("O");
	    cout<<"   ";
	 }
	 else if(s[i][j].seatshow()==1)
	 {
	    textcolor(RED);
	    cprintf("O");
	    cout<<"   ";
	 }
	 else if(s[i][j].seatshow()==2)
	 {
	    textcolor(CYAN+BLINK);
	    cprintf("O");
	    cout<<"   ";
	 }
      }
   }
   cout<<endl<<endl;
   textcolor(YELLOW);
   cprintf("            --------------------------------------------------");
   cout<<endl;
   cprintf("          /                   SCREEN THIS WAY                  \\");
   gotoxy(67,12);                    //Legend description
   textcolor(WHITE);                //"      "
   cprintf("| Legend:");            //"      "
   cout<<endl;                      //"      "
   gotoxy(67,14);                   //"      "
   textcolor(GREEN);                //"      "
   cprintf("|O: Unoccupied");        //"      "
   cout<<endl;                      //"      "
   gotoxy(67,15);                   //"      "
   textcolor(RED);                  //"      "
   cprintf("|O: Occupied");          //"      "
   textcolor(CYAN);                 //"      "
   gotoxy(67,16);                   //"      "
   cprintf("|O: Selected");          //"      "
   textcolor(WHITE);
   cout<<endl<<endl<<endl;

}

void initdata()                 //assigns the row and column for the struct s
{
   char a[1];
   textcolor(WHITE);
   strcpy(a,"0");
   for(int i=0;i<10;i++)
   {
      for(int j=0;j<15;j++)
      {
	     s[i][j].assign_cord(a,1);
	     s[i][j].seatrem();
      }
      a[0]++;
   }
   for(i=0;i<10;i++)
   {
      strcpy(a,"a");
      for(int j=0;j<15;j++)
      {
	     s[i][j].assign_cord(a,2);
	     a[0]++;
      }
   }
}

void get_inp_rowFL()
{
   int r_inp;
   decide_st(2);
   fb.seekp(0,ios::beg);
   while(fb>>r_inp)
   {
      for(int j=0;j<15;j++)
	 s[r_inp][j].seatocc();
   }
   fb.close();
}

int check_housefull()
{
   for(int i=0;i<10;i++)
      for(int j=0;j<15;j++)
      {
	 if(i==6&&j==7)
	    continue;
	 if(s[i][j].seatshow()==0)
	    return 0;
      }
   return 1;
}

//payment functions starts from here

void print_bill()
{
   rectangle(100,20,530,360);
   setlinestyle(CENTER_LINE,1,1);
   line(110,80,520,80);
   settextstyle(3,0,4);
   setcolor(3);
   outtextxy(175,30,"The World Cinemas");
   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(120,100,m.name);
   outtextxy(120,120,"Screen - ");
   outtextxy(215,120,scr_no);
   outtextxy(400,105,"Seats - ");                   //input to be added
   gotoxy(62,8);
   cout<<no_of_tick;
   outtextxy(400,125,"Time - ");
   outtextxy(480,125,scr_tm);
   settextstyle(2,0,6);
   setcolor(7);
   outtextxy(120,170,"Sub-Total");
   outtextxy(120,190,"Internet Handling Fees");
   outtextxy(120,220,"Additional Charges");
   outtextxy(120,250,"CGST(9%)");
   outtextxy(120,270,"SGST(9%)");
   outtextxy(120,300,"Total Payable Amount");
   settextstyle(6,0,2);
   int j=165;
   for(int i=1;i<=2;i++,j+=20)
      outtextxy(420,j,"Rs.");
   j+=10;
   outtextxy(420,j,"Rs.");
   j+=30;
   for(i=1;i<=2;i++,j+=20)
      outtextxy(420,j,"Rs.");
   outtextxy(420,j+10,"Rs.");
   int sub_tot,hand_fee,add_fee;                //input to be added
   sub_tot=no_of_tick*120;
   hand_fee=14;
   add_fee=21;
   int sgst,cgst,tot;
   sgst=cgst=0.09*sub_tot;
   tot=sub_tot+hand_fee+add_fee+sgst+cgst;
   gotoxy(57,12);
   cout<<sub_tot;
   gotoxy(57,13);
   cout<<hand_fee;
   gotoxy(57,15);
   cout<<add_fee;
   gotoxy(57,17);
   cout<<cgst;
   gotoxy(57,18);
   cout<<sgst;
   gotoxy(57,20);
   cout<<tot;
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(100,370,"Press enter to pay and proceed to show your ticket...");
   settextstyle(5,0,3);
   setcolor(12);
   outtextxy(260,380,"Thank you");
   outtextxy(300,400,"and");
   outtextxy(200,420,"Have a nice movie time !!!");
   getch();
   setcolor(15);
}

void about_us()
{
   int t=0;
   start_of_about:
   settextstyle(7,0,4);
   setcolor(11);
   outtextxy(70,150,"PROGRAM");
   outtextxy(90,190,"FORGED");
   outtextxy(125,230,"WITH");
   outtextxy(410,340,"ADHITHYA");
   outtextxy(469,370,"AKASH");
   outtextxy(442,400,"HARISH");
   settextstyle(4,0,4);
   outtextxy(245,40,"About US");
   setcolor(RED);
   settextstyle(7,0,4);
   outtextxy(59,270,"PASSION");
   outtextxy(416,430,"CLASS 12");
   settextstyle(7,0,1);
   outtextxy(50,90,"Howdy and Welcome.");
   settextstyle(5,0,5);
   setcolor(LIGHTBLUE);
   line(50,60,70,60);
   line(115,60,230,60);
   line(400,60,580,60);
   setcolor(GREEN);
   setfillstyle(1,LIGHTGREEN);
   int bk[]={70,0,70,80,92,90,115,80,115,0,70,0};
   fillpoly(6,bk);
   setcolor(WHITE);
   settextstyle(8,0,1);
   outtextxy(305,86,"THE CREATORS");
   settextstyle(2,0,5);
   outtextxy(255,96,"We are ");
   outtextxy(460,96,"of this Program.");
   outtextxy(52,108,"We are dedicated to professional service,quality design, and trustworthy");
   outtextxy(52,120,"results. We create highly functional user interfaces with the perfect ");
   outtextxy(52,132,"mixture of simplicity,elegance and innovation for each of our clients.");
   outtextxy(52,344,"Our passion translates into a positive working");
   outtextxy(52,356,"relationship that reflects the true secret to");
   outtextxy(52,368,"our success.A unique high-quality software");
   outtextxy(52,380,"helps you choose and make your call to action");
   outtextxy(52,392,"tantalizing and easy to locate.");
   outtextxy(52,420,"We know how important comfortable and user");
   outtextxy(52,432,"friendly software is to you,thus,strive to");
   outtextxy(52,444,"deliver creative ideas and the most relevant");
   outtextxy(52,456,"results.");
   settextstyle(1,0,3);
   setcolor(RED);
   outtextxy(240,152,"Who We Are");
   settextstyle(8,0,1);
   setcolor(LIGHTGREEN);
   outtextxy(243,176,"THE WORLD");
   settextstyle(2,0,5);
   outtextxy(365,184,"cinemas is a Theatre based in");
   outtextxy(246,198,"INDIA. We are a small but super-creative team");
   outtextxy(246,210,"of 3 members. We strive to bring you effective");
   outtextxy(246,222,"and high-quality professional service.");
   outtextxy(246,250,"Our goal is simple - to ensure beatiful,usable");
   outtextxy(246,262,"interfaces through handcrafted semantic code");
   outtextxy(246,274,"that produces a satisfying experince for every");
   outtextxy(246,286,"visitor to book tickets hassle-free.While our");
   outtextxy(246,298,"vison is noble,we back up that vision with");
   outtextxy(246,310,"unparalleled creativitty and passion that make");
   outtextxy(246,322,"a distinct difference in the designs we create.");
   setcolor(13);
   if(t==0)
   {
      outtextxy(52,466,"Please wait until your Ticket is processed.");
      delay(5000);
      t++;
      cleardevice();
      goto start_of_about;
   }
   else
   {
      outtextxy(52,466,"Your Ticket is processed.Press any key.");
   }
   setcolor(WHITE);
   getch();
}

void barcode()
{
   int j=140;
   setlinestyle(SOLID_LINE,1,1);
   for(int i=1;i<=6;i++,j+=2)
   line(570,j,610,j);
   j+=5;
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=2;i++,j+=4)
   line(570,j,610,j);
   j+=3;
   for(i=1;i<=2;i++,j+=4)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   for(i=1;i<=3;i++,j+=3)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=4;i++,j+=5)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=2;i++,j+=1)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=4)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=3;i++,j+=6)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=4)
   line(570,j,610,j);
   j+=3;
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=2;i++,j+=4)
   line(570,j,610,j);
   j+=3;
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=4;i++,j+=2)
   line(570,j,610,j);
   setlinestyle(SOLID_LINE,1,1);
   for(i=1;i<=2;i++,j+=3)
   line(570,j,610,j);
   j+=2;
   setlinestyle(SOLID_LINE,1,3);
   for(i=1;i<=3;i++,j+=2)
   line(570,j,610,j);


}

int stage_2_movie();
int var_start_stg_2=0;

void print_ticket()
{
   rectangle(20,100,620,380);                          //outline of the ticket and inner designs starts here
   int arr1[]={20,330,80,230,160,380,20,380,20,330};
   int arr2[]={25,100,105,250,185,100,25,100};
   int arr3[]={108,255,175,380,240,255,108,255};
   setfillstyle(CLOSE_DOT_FILL,LIGHTGREEN);
   drawpoly(6,arr1);
   floodfill(25,335,15);                		//dont use fillpoly. causing some unexpected output.
   setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
   fillpoly(4,arr2);
   setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
   fillpoly(4,arr3);
   setlinestyle(CENTER_LINE,1,1);
   line(513,120,513,360);
   settextstyle(1,0,1);                                  //texts inside starts here
   outtextxy(175,130,"The");
   outtextxy(175,150,"World");
   outtextxy(175,170,"Cinemas");
   settextstyle(8,0,2);
   outtextxy(270,130,"Movie Ticket");
   settextstyle(4,0,5);
   setcolor(12);
   outtextxy(175,190,m.name);
   settextstyle(2,0,6);
   setcolor(11);
   outtextxy(250,270,"Seat");
   outtextxy(330,270,"Time");
   outtextxy(410,270,"Screen");
   settextstyle(0,0,1);
   setcolor(5);
   switch(c)
   {
   case 1:   decide_st(1);
	     f.seekp(0,ios::end);
	     f.seekp(f.tellp()-(4*no_of_tick));
	     break;
   case 2:   decide_st(2);
	     fb.seekp(0,ios::end);
	     fb.seekp(fb.tellp()-(3*row_no));
   }
   char temp_cord[2];
   int cor=300,k=245;
   if(c==2)
   {
      outtextxy(220,300,"Row");
      no_of_tick=row_no;
   }
   for(int i=0;i<no_of_tick;i++)
   {
      if(c==1)
      {	 while(f>>temp_cord)
	    break;
	 outtextxy(k,cor,temp_cord);
	 k=k+16;
      }
      else if(c==2)
      {	 while(fb>>temp_cord)
	     break;
	 outtextxy(k,cor,temp_cord);
	 outtextxy(k+5,cor,",");
	 k=k+10;
      }
      if((i+1)%4==0&&i!=0)
      {
	 cor=cor+10;
	 k=245;
      }
   }
   f.close();
   fb.close();
   settextstyle(0,0,2);
   outtextxy(330,300,scr_tm);
   outtextxy(410,300,scr_no);
   setcolor(15);
   setlinestyle(CENTER_LINE,1,1);
   line(310,270,310,330);
   line(390,270,390,330);
   settextstyle(3,0,2);
   outtextxy(250,343,"ADMIT ONE");
   settextstyle(7,1,1);
   outtextxy(485,185,"Tear Here");
   settextstyle(0,0,0);
   setcolor(10);
   outtextxy(518,150,"Scrn");
   outtextxy(518,200,"Time");
   outtextxy(518,250,"Code");
   outtextxy(518,300,"Seat");
   setcolor(14);
   outtextxy(518,170,scr_no);              //input further to be given
   outtextxy(518,220,scr_tm);
   outtextxy(518,270,m.code);
   switch(c)
   {
   case 1:    decide_st(1);
	      f.seekp(0,ios::end);
	      f.seekp(f.tellp()-(4*no_of_tick));
	      break;
   case 2:    decide_st(2);
	      fb.seekp(0,ios::end);
	      fb.seekp(fb.tellp()-(3*row_no));
	      break;
   }
   cor=320;k=518;
   if(c==2)
   {
      outtextxy(518,310,"Row:-");
      no_of_tick=row_no;
   }
   for(i=0;i<no_of_tick;i++)
   {
      if(c==1)
      {	 while(f>>temp_cord)
	    break;
	 outtextxy(k,cor,temp_cord);
	 k=k+16;
      }
      else if(c==2)
      {	 while(fb>>temp_cord)
	     break;
	 outtextxy(k,cor,temp_cord);
	 outtextxy(k+5,cor,",");
	 k=k+10;
      }
      if((i+1)%4==0&&i!=0)
      {
	 cor=cor+10;
	    k=518;
      }
   }
   f.close();
   fb.close();
   settextstyle(0,0,0);
   setcolor(15);
   outtextxy(20,400,"BE SMART, SAY NO TO QUEUES AND PRINTOUTS.");
   outtextxy(20,420,"BOOK TICKETS ONLINE");
   outtextxy(20,440,"SHOW BARCODE AT THE WORLD CINEMAS");
   outtextxy(20,460,"PRESS ANY KEY TO GO BACK TO THE MAIN MENU");
   getch();
   stage_2_movie();
}

void stage_0_logo()
{
    clrscr();
    for(int i=1;i<=4;i++)
    {
	fstream f;
	char c[200];
	switch(i)
	{
	case 1:    f.open("WELCOME.txt",ios::in|ios::out);
		   textcolor(LIGHTMAGENTA);
		   while(f.getline(c,200))
		   {
		       if(f.eof())
			   break;
		       cprintf(c);
		       cout<<endl;
		   }
		   f.close();
		   delay(2000);
		   break;

	case 2:    f.open("TOTHENXT.txt",ios::app|ios::in|ios::out);
		   textcolor(LIGHTRED);
		   while(f.getline(c,200))
		   {
		       if(f.eof())
			  break;
		       if(strcmpi(c,"&")==0)
		       {
			  delay(50);
			  clrscr();
			  continue;
		       }
		       cprintf(c);
		       cout<<endl;
		   }
		   f.close();
		   cout<<"\n\n\t";
		   textcolor(BLUE+BLINK);
		   textbackground(CYAN);
		   cprintf("MADE WITH C++!!!");
		   delay(2000);
		   textbackground(BLACK);
		   break;

	case 3:	   for(int j=1;j<=2;j++)
		   {
		      f.open("GLOBE.txt",ios::app|ios::in|ios::out);
		      textcolor(LIGHTGREEN);
		      while(f.getline(c,200))
		      {
			  if(f.eof())
			      break;
			  if(strcmpi(c,"&")==0)
			  {
			      delay(150);
			      clrscr();
			      continue;
			  }
			  cprintf(c);
			  cout<<endl;
		      }
		      f.close();
		   }
		   break;

	case 4:    f.open("THEWRLD.txt",ios::app|ios::in|ios::out);
		   textcolor(LIGHTCYAN);
		   while(f.getline(c,200))
		   {
		       if(f.eof())
			  break;
		       if(strcmpi(c,"&")==0)
		       {
			  delay(150);
			  clrscr();
			  continue;
		       }
		       cprintf(c);
		       cout<<endl;
		   }
		   f.close();
		   delay(1000);
		   break;

	}
    }
}

void stage_1_login()         //function to start the program with login page
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
    fu.close();
}

void intermediate_tc();

int stage_2_movie()      //function to start the movie detail display
{
   not_allowed:
   fstream f("Movie_Details.bat",ios::binary|ios::ate|ios::in|ios::out);
   f.seekg(0,ios::beg);
   int i=0,find=0;
   begin_again:
   int j=0;
   int gd2=DETECT,gm2;
   initgraph(&gd2,&gm2,"C:\\TURBOC3\\BGI");
   cleardevice();
   print_rectangle();
   while(f.read((char*)&m,sizeof(m)))
   {
      i++; j++;
      if(j==5)
      {
	 j=0;
	 break;
      }
      print_movie_details(j);

   }
   --i;
   setcolor(WHITE);
   if(var_start_stg_2==1)
   {
      outtextxy(20,65,"blocked until the chosen movie is displayed.");
      outtextxy(20,50,"Due to our company policy, booking is ");
   }
   else
   {
      outtextxy(20,50,"Type the Movie Code to proceed further: ");
      outtextxy(20,65,"Press 'n' to go to the next page");
   }
   outtextxy(20,80,"Press 'b' to sign out");
   //outtextxy(20,60,"Press 'b' to go to the previous page");
   char in[10];
   gotoxy(44,4);
   cin>>in;
   if(var_start_stg_2==1)
      if(strcmpi(in,"b")!=0)
	 goto not_allowed;
   if(strcmpi(in,"b")==0)
      exit_mod('s');
   if(strcmpi(in,"n")==0)
   {
      f.seekg(f.tellp()-1*sizeof(m));
      goto begin_again;
   }
   /*else if(strcmpi(in,"b")==0)
   {
      cout<<"First pos "<<f.tellp()/sizeof(m);
      delay(1000);
      f.seekg((i-8)*sizeof(m),ios::beg);
      cout<<"\nSecond pos"<<f.tellp()/sizeof(m);
      delay(1000);
      f.clear();
      i=i-5;
      goto begin_again;
   }*/
   else
   {
      f.close();
      f.open("Movie_Details.bat",ios::binary|ios::in);
      while(f.read((char*)&m,sizeof(m)))
      {
	 if(strcmpi(in,m.code)==0)
	 {
	    find=1;
	    break;
	 }
      }
      if(find!=1)
      {
	 cleardevice();
	 setcolor(LIGHTRED);
	 rectangle(10,10,630,470);
	 rectangle(15,15,625,465);
	 setcolor(RED);
	 outtextxy(25,25,"Unable to find the movie");
	 outtextxy(25,45,"Please press 'm' to check again!");
	 outtextxy(25,65,"or Press 'e' to exit");
	 char c;
	 gotoxy(4,6);
	 cin>>c;
	 if(c=='e')
	    exit_mod();
	 else if(c=='m')
	 {
	    f.close();
	    f.open("Movie_Details.bat",ios::binary|ios::in);
	    goto begin_again;
	 }
      }
      else
      {
	 proceed_Mov_Det(m);
	 wrong_sel:
	 setcolor(LIGHTGREEN);
	 outtextxy(317,30,"Press 'y' to procced to seat selection");
	 outtextxy(317,50,"Press 'm' to go back to main menu");
	 char c;
	 gotoxy(76,4);
	 cin>>c;
	 if(c=='y')
	 {
	    outtextxy(300,85,"Redirecting you to Seat Selection in ");
	    for(int i=5;i>=0;i--)
	    {
	       gotoxy(76,6);
	       cout<<i<<"\b";
	       delay(1000);
	    }
	    closegraph();
	    var_start_stg_2=1;
	    return 0;
	 }
	 else if(c=='m')
	 {
	   f.close();
	   f.open("Movie_Details.bat",ios::binary|ios::in);
	   find=0;
	   goto begin_again;
	 }
	 else
	    goto wrong_sel;
      }
   }
   f.close();
   return 0;
}

void stage_4_payment();

int stage_3_seat()        //function to start with seat selection process
{
   start_frm_top:
   clrscr();
   char choice;
   int t=0;
   char *cord=new char[2];
   initdata();
   textcolor(WHITE);
   seatconv(cord,0);
   get_inp_rowFL();
   int hf=check_housefull();
   if(hf==1)
   {
      cout<<"Looks like all seats are filled! Housefull!";
      cout<<endl;
      cout<<"Press any key to return to main menu";
      var_start_stg_2=0;
      getch();
      return 0;
   }
   cout<<"\n\nChoose\n1.Normal Booking\n2.Bulk Booking\n";
   cin>>c;
   switch(c)
   {
      case 1:
	 textcolor(WHITE);
	 cprintf("No. of tickets?: ");
	 cin>>n;
	 no_of_tick=n;
	 seatconv(cord,0);
	 getlay();
	 get_inp_rowFL();
	 print_layout();
	 textcolor(WHITE);
      cout<<endl;
      cprintf("Proceed to selection?");
      cout<<endl;
      cprintf("(Press Enter to continue)");
      cout<<endl;
      cprintf("(Press 'e' to cancel and go back to the main menu)");
      char chk_proceed=getch();
      if(chk_proceed=='e')
      {
	 return 0;
      }
      clrscr();
      print_layout();
       for(k=0;k<n;k++)
       {
	   cout<<endl;
	   cprintf("Select seats (e.g. 3D,5G)");
	   cout<<endl;
	 do
	    {
	    t=0;
	    cout<<endl;
	    cprintf("Seat ");
	    cout<<k+1;
	    cprintf(": ");
	    cin>>cord;
	    if(strlen(cord)!=2)
	    t=1;
	    if(cord[1]>=97&&cord[1]<=122)                          //converting lowercase to uppercase
	    cord[1]-=32;
	    if(cord[1]<65||cord[1]>79)                             //checking valid seat id
	    t=1;                                             //"        "     "    "
	    if(cord[0]<48||cord[0]>57)                             //"        "     "    "
	    t=1;					     //"        "     "    "
	    if(t)                                            //"        "     "    "
	    {
	       cprintf("Please enter a valid seat ID");
	       cout<<endl;
	       continue;
	    }
	    t=0;
	    if(fillcheck(cord))
	       t=1;
	    if(t==1)
	    {
	       textcolor(RED);
	       cprintf("Seat has already been booked");
	       cout<<endl;
	       textcolor(WHITE);
	    }
	    //cout<<"\n";
	    }
	    while(t);
	   decide_st(1);
	   f.write(cord,strlen(cord)).put('\n');
	   f.close();
	 seatconv(cord,3);
	 clrscr();
	 print_layout();
	 }
	 cout<<endl;
      cprintf("Confirm seats?");
      cout<<'\n';
      cprintf("(Press enter to confirm)");
      getch();
      getlay();
      clrscr();
      print_layout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Confirm booking?");
      cout<<endl;
      cprintf("(Press enter to continue)");
      getch();
      for(int i=0;i<10;i++)
	 for(int j=0;j<15;j++)
	 {
	    if(s[i][j].seatshow()==2)
	       s[i][j].seatocc();
	 }
      clrscr();
      print_layout();
   cout<<endl;
   break;
   case 2:textcolor(WHITE);
	  cprintf("How many rows would you like to book?: ");
	  cin>>n;
	  row_no=n;
	  no_of_tick=10*n;
	  seatconv(cord,0);
	  getlay();
	  get_inp_rowFL();
	  print_layout();
	 textcolor(WHITE);
      cout<<endl;
      cprintf("Proceed to selection?");
      cout<<endl;
      cprintf("(Press Enter to continue)");
      cout<<endl;
      cprintf("(Press 'e' to cancel and go back to the main menu)");
      chk_proceed=getch();
      if(chk_proceed=='e')
	 stage_2_movie();
      clrscr();
      print_layout();
	  int r;
	  for(i=0;i<n;i++)
	 {
	 cout<<endl;
	 textcolor(WHITE);
	 cprintf("Select Rows(0-9)");
	 cout<<endl;
	 int t=0;
	 do
	 {
	 t=0;
	 cprintf("Row ");
	 cout<<i+1;
	 cprintf(": ");
	 cin>>r;
	 if(r<=0&&r>=9)
	 t=1;
	 if(t)                                            //"        "     "    "
	 {
	    cprintf("Please enter a valid Row");
	    cout<<endl;
	    continue;
	 }
	 t=0;
	 if(fillcheck(r))
	    t=1;
	 if(t==1)
	 {
	    textcolor(RED);
	    cprintf("Row is already booked");
	    cout<<endl;
	    textcolor(WHITE);
	    continue;
	 }
	 t=0;
	 if(fillcheck(r,2))
	   t=1;
	 if(t==1)
	 {
	    textcolor(RED);
	    cprintf("One or many seats in this row have already been booked!");
	    cout<<endl;
	    cprintf("Please choose a different row");
	    textcolor(WHITE);
	    cout<<endl<<endl;
	 }
	 cout<<endl;
	 }while(t);
	 decide_st(2);
	 fb<<r;
	 fb.put('\n');
	 fb.close();
	 decide_st(1);
	 for(j=0;j<15;j++)
	    f.write(s[r][j].ret_cord(),2).put('\n');
	 f.close();
	 for(j=0;j<15;j++)
	    s[r][j].seatsel();
	 seatconv(cord,3);
	 clrscr();
	 print_layout();
	 }
      cout<<endl;
      cprintf("Confirm seats?");
      cout<<endl;
      cprintf("(Press Enter to continue)");
      getch();
      getlay();
      clrscr();
      print_layout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Confirm booking?");
      cout<<endl;
      cprintf("(Press enter to continue)");
      getch();
      for(i=0;i<10;i++)
      for(j=0;j<15;j++)
      if(s[i][j].seatshow()==2)
	 s[i][j].seatocc();
      clrscr();
      print_layout();
      cout<<endl;
	  break;
      default: cout<<"Wrong choice.Press any key to continue";
	       getch();
	       goto start_frm_top;
   }
   delete cord;
   delay(2000);
   stage_4_payment();
   return 1;
}

void stage_4_payment()               //payment module
{
   int gd = DETECT , gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   cleardevice();
   print_bill();
   cleardevice();
   about_us();
   cleardevice();
   barcode();
   print_ticket();
}
void intermediate_tc()
   {
   clrscr();
   textcolor(LIGHTBLUE);
   cout<<"\t\t\t    ";
   gotoxy(35,0);
   cprintf("TERMS AND CONDITIONS");
   cout<<endl<<endl<<endl<<endl;
   textcolor(LIGHTGRAY);
   cprintf("1. Entry is allowed only for valid ticket holders.");
   cout<<'\n';
   cprintf("2. Guests aged under 18 will not be allowed in `A` rated movies");
   cout<<'\n';
   cprintf("3. Children above the age of 3 years require tickets for `U` or `U/A` rated movies.");
   cout<<'\n';
   cprintf("4. In case a ticket is lost or misplaced, a duplicate ticket cannot be issued.");
   cout<<'\n';
   cprintf("5. Tickets once purchased cannot be cancelled, exchanged or refunded.");
   cout<<'\n';
   cprintf("6. Guest Agrees to be contacted by THE WORLD Management for the purpose of seeking feedback for service improvement.");
   cout<<'\n';
   cprintf("7. Decision(s) taken by THE WORLD shall be final and binding, Rights of admission reserved.");
   cout<<'\n';
   cprintf("8. Outside food and beverages are not allowed inside the cinema premises");
   cout<<"\n\n\n";
   cout<<endl;
   textcolor(RED);
   cprintf("Even though u won't read this, Please press any key to proceed further,");
   cout<<endl;
   getch();
   }

void main()
 {
   clrscr();
   stage_0_logo();
   stage_1_login();
   start_frm_movie:
   stage_2_movie();
   intermediate_tc();
   int chk=stage_3_seat();
   if(chk==0)
      goto start_frm_movie;
   getch();
 }
