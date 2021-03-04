#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<ctype.h>

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
		settextstyle(0,0,0);
		outtextxy(130,340,"Redirecting you to Home page in ");
		   for(int i=5;i>=0;i--)
		   {
		      gotoxy(51,22);
		      cout<<i<<"\b";
		      delay(1000);
		   }
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
 if(strcmpi(m.code,"001")==0)
 {
    p.open("Batman_logo_2.txt",ios::in|ios::out);
    i=150;
 }
 else if(strcmpi(m.code,"002")==0)
 {
    i=5;        //test purpose only
    j=10;	//test purpose......remove it later
    p.open("SpiderMan_logo_1.txt",ios::in|ios::out);
 }
 else if(strcmpi(m.code,"003")==0)
 {
    p.open("CaptainAmerica_logo_1.txt",ios::in|ios::out);
    i=160;
 }
 else if(strcmpi(m.code,"004")==0)
 {
    p.open("Superman_logo_2.txt",ios::in|ios::out);
    i=170;
    j=20;
 }
 else if(strcmpi(m.code,"005")==0)
 {
   p.open("XMEN_logo_1.txt",ios::in|ios::out);
   i=170;
   j=5;
 }
 else;
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
}

//seat selection functions starts from here

fstream fs;
int scr_no;
char scr_tm[10];

void decide_st()
   {
   if(strcmpi(m.code,"001")==0)
      {
	 fs.open("seats1.dat",ios::binary|ios::in|ios::out|ios::ate);
	 scr_no=1;
	 strcpy(scr_tm,"Morning");
      }
   else if(strcmpi(m.code,"002")==0)
   {
      fs.open("seats2.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=1;
      strcpy(scr_tm,"Matinee");
   }
   else if(strcmpi(m.code,"003")==0)
   {
      fs.open("seats3.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=1;
      strcpy(scr_tm,"Night");
   }
   else if(strcmpi(m.code,"004")==0)
   {
      fs.open("seats4.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=2;
      strcpy(scr_tm,"Morning");
   }
   else if(strcmpi(m.code,"005")==0)
   {
      fs.open("seats5.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=2;
      strcpy(scr_tm,"Matinee");
   }
   else if(strcmpi(m.code,"006")==0)
   {
      fs.open("seats6.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=2;
      strcpy(scr_tm,"Night");
   }
   else if(strcmpi(m.code,"007")==0)
   {
      fs.open("seats7.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=3;
      strcpy(scr_tm,"Morning");
   }
   else if(strcmpi(m.code,"008")==0)
   {
      fs.open("seats8.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=3;
      strcpy(scr_tm,"Matinee");
   }
   else if(strcmpi(m.code,"009")==0)
   {
      fs.open("seats9.dat",ios::binary|ios::in|ios::out|ios::ate);
      scr_no=3;
      strcpy(scr_tm,"Night");
   }
   }
class seat                            //class that contains data of seat
   {
   int status;
   public:
   char a;
   seat()
      {
      status=0;
      a=' ';
      }
   int seatshow()
      {return status;}
   void seatocc()               //fills seat
      {status=1;}
   void seatrem()               //empties it
      {status=0;}
   void seatsel()               //temporary selection
      {status=2;}
   void seatelse()              //for identifying row, column co-ordinates
      {status=3;}
   }s[12][17];
void initdata()                 //initially puts data into the file
   {
   int i,j;
   for(i=0;i<12;i++)
   for(j=0;j<17;j++)
      {
      if(i!=1||i!=2||j!=1||j!=2||j!=10)
	 {
	 s[i][j].seatrem();
	 }
      else
	 s[i][j].seatelse();
      }
   for(i=2;i<12;i++)
   for(j=2;j<17;j++)
   fs.write((char*)&s[i][j],sizeof(s));
   fs.close();
   }
void seatconv(char a[])  //converting given seat id to valid coordinates and selecting or confirming them
   {
   int m,n;
   m=a[0]-46;
   n=a[1]-63;
   if(n>=9)
   n++;
   s[m][n].seatsel();
   }
void getlay()
   {
   for(int i=12;i>0;i--)
      {
      clrscr();
      gotoxy(26,10);
      cprintf("Getting the seat layout\n");
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
   }
void seatlayout(char n='0')             //Function to display seat layout
   {
   clrscr();
   textcolor(MAGENTA);
   cprintf("              SCREEN ");
   cout<<scr_no<<'\t';
   textcolor(LIGHTMAGENTA);
   cprintf("SHOWTIME ");
   cout<<scr_tm<<endl;
   textcolor(WHITE);
   int i,j;
   for(i=2;i<17;i++)            //for assigning column identity,i.e. A,B,C
      {
      int r;
      if(i<=9)
      r=i;
      else
      r=i-1;
      if(i==9)                  //for getting alleyway
      i++;
      s[0][i].a=65+r-2;
      s[0][i].seatelse();
      }
   for(i=2;i<12;i++)            //for assigning row identity,i.e. 1,2,3
      {
      s[i][0].a=48+i-2;
      s[i][0].seatelse();
      }
   for(i=0;i<12;i++)
      {
      cout<<endl;
      for(j=0;j<17;j++)
	 {
	 if(i==0&&j==0)
	 cout<<"    ";
	 else if(i==1||j==1)
	 cout<<"    ";
	 else if(j==9)
	 cout<<"    ";
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
	    textcolor(CYAN + BLINK);
	    cprintf("O");
	    cout<<"   ";
	    }
	 else
	    {
	    textcolor(WHITE);
	    cout<<s[i][j].a<<"   ";
	    }
	 }
      }
   cout<<endl<<endl;
   textcolor(YELLOW);
   cprintf("           --------------------------------------------------");
   cout<<endl;
   cprintf("         /                 SCREEN THIS WAY                    \\");
   gotoxy(67,13);                    //Legend description
   textcolor(WHITE);                //"      "
   cprintf("| Legend:");            //"      "
   cout<<endl;                      //"      "
   gotoxy(68,14);                   //"      "
   textcolor(GREEN);                //"      "
   cprintf("O: Unoccupied");        //"      "
   cout<<endl;                      //"      "
   gotoxy(68,15);                   //"      "
   textcolor(RED);                  //"      "
   cprintf("O: Occupied");          //"      "
   textcolor(CYAN);                 //"      "
   gotoxy(68,16);                   //"      "
   cprintf("O: Selected");          //"      "
   textcolor(WHITE);
   cout<<endl<<endl<<endl;
   }
int fillcheck(char a[])
   {
   int m,n;
   seat t;
   m=a[0]-46;
   n=a[1]-63;
   if(n>=9)
   n++;
   int k=(15*m)+n;
   fs.seekg(k*sizeof(t),ios::beg);
   fs.read((char*)&t,sizeof(t));
   if(t.seatshow()==1)
   return 1;
   else
   return 0;
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

int stage_2_movie()      //function to start the movie detail display
{
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
   outtextxy(20,50,"Type the Movie Code to proceed further: ");
   outtextxy(20,65,"Press 'n' to go to the next page");
   outtextxy(20,80,"Press 'e' to exit");
   //outtextxy(20,60,"Press 'b' to go to the previous page");
   char in[10];
   gotoxy(44,4);
   cin>>in;
   if(strcmpi(in,"e")==0)      // test purpose only
      exit_mod();
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
	    return 0;
	 }
	 else if(c=='m')
	 {
	   f.close();
	   f.open("Movie_Details.bat",ios::binary|ios::in);
	   goto begin_again;
	 }
	 else
	    goto wrong_sel;
      }
   }
   return 0;
}

void stage_3_seat()        //function to start with seat selection process
{
   clrscr();
   int n;
   decide_st();
   fs.seekp(0,ios::beg);
   fs.read((char*)&s,sizeof(s));
   //initdata();
   textcolor(WHITE);
   char choice;
   do
   {
   cprintf("1.Normal Booking (For less than 15 seats)");
   cout<<endl;
   cprintf("2.Bulk Booking (For entire rows)");
   cout<<endl;
   cprintf("\nEnter your choice: ");
   int c;
   cin>>c;
   switch(c)
      {
      case 1:
      textcolor(WHITE);
      cprintf("No. of tickets?: ");
      cin>>n;
      getlay();
      cprintf("Current status:");
      cout<<endl;
      seatlayout();
      textcolor(WHITE);
      cout<<endl<<endl;
      cprintf("Proceed to selection?");
      cout<<endl;
      cprintf("(Press Enter to continue)");
      cout<<endl;
      getch();
      clrscr();
      char h[2];
      seatlayout();
      for(int i=0;i<n;i++)
	 {
	 cout<<endl<<endl;
	 cprintf("Select seats (e.g. 3D,5G)");
	 cout<<endl;
	 int f=0;
	 do
	    {
	    f=0;
	    cprintf("Seat ");
	    cout<<i+1;
	    cprintf(": ");
	    gets(h);
	    if(strlen(h)!=2)
	    f=1;
	    if(h[1]>=97&&h[1]<=122)                          //converting lowercase to uppercase
	    h[1]-=32;
	    if(h[1]<65||h[1]>79)                             //checking valid seat id
	    f=1;                                             //"        "     "    "
	    if(h[0]<48||h[0]>57)                             //"        "     "    "
	    f=1;                                             //"        "     "    "
	    if(f)                                            //"        "     "    "
	    cprintf("Please enter a valid seat ID\n");       //"        "     "    "
	    if(fillcheck(h))
	       {
	       f=1;
	       cprintf("Seat has already been booked\n");
	       }
	    cout<<endl;
	    }
	 while(f);
	 seatconv(h);
	 clrscr();
	 seatlayout();
	 }
      cout<<endl;
      cprintf("Confirm seats?");
      cout<<'\n';
      cprintf("(Press enter to confirm)");
      getch();
      getlay();
      seatlayout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Confirm booking?");
      cout<<endl;
      cprintf("(Press enter to continue)");
      getch();
      for(i=0;i<12;i++)
      for(int j=0;j<17;j++)
      if(s[i][j].seatshow()==2)
	 s[i][j].seatocc();
      fs.write((char*)&s,sizeof(s));
      seatlayout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Thank you for choosing us!");
      cout<<endl;
      cprintf("Have a nice movie time!");
      break;
      case 2:                                         //For bulk booking
      textcolor(WHITE);
      cprintf("How many rows would you like to book?: ");
      int b;
      cin>>b;
      cout<<endl;
      for(i=0;i<b;i++)
	 {
	 clrscr();
	 seatlayout();
	 cout<<endl;
	 textcolor(WHITE);
	 cprintf("Enter the row number(s):");
	 cout<<endl;
	 int r;
	 cin>>r;
	 for(int j=0;j<17;j++)
	    s[r+2][j].seatsel();
	 }
      seatlayout();
      cprintf("Confirm seats?");
      cout<<endl;
      cprintf("(Press Enter to continue)");
      getch();
      getlay();
      seatlayout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Confirm booking?");
      cout<<endl;
      cprintf("(Press enter to continue)");
      for(i=0;i<12;i++)
      for(j=0;j<17;j++)
      if(s[i][j].seatshow()==2)
	 {
	 s[i][j].seatocc();
	 int t=(12*i)+j;
	 fs.seekg(t*sizeof(s),ios::beg);
	 fs.write((char*)&s[i][j],sizeof(s));
	 }
      seatlayout();
      cout<<endl;
      textcolor(WHITE);
      cprintf("Thank you for choosing us!");
      cout<<endl;
      cprintf("Have a nice movie time!");
      break;
      }
   cout<<"Do you want to book further? <Y/N>\n";
   cin>>choice;
   }
   while(choice=='Y'||choice=='y');
   getch();
}


void main()
 {
   stage_1_login();
   stage_2_movie();
   stage_3_seat();
 }
