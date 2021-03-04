#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

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

void print_rectangle()
{
   outtextxy(0,10,"1.Latest release");
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
    p.open("SpiderMan_logo_1.txt",ios::in|ios::out);
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

void seat_sel(movie_details m)
{
   cleardevice();
   setcolor(LIGHTRED);
   rectangle(10,10,630,470);
   rectangle(15,15,625,465);
   setcolor(BLUE);
   settextstyle(10,1,3);
   outtextxy(25,150,"Seat Selection");
   settextstyle(0,0,0);
   outtextxy(25,25,"Press any character to exit");
   getch();
   exit_mod();
}


void main()
{
   fstream f("Movie_Details.bat",ios::binary|ios::ate|ios::in|ios::out);
   f.seekg(0,ios::beg);
   int i=0,find=0;
   begin_again:
   int j=0;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
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
	    seat_sel(m);   	//not yet properly intialised
	 else if(c=='m')
	 {
	   f.close();
	   f.open("Movie_Details.bat",ios::binary|ios::in);
	   goto begin_again;
	 }
	 else
	    goto wrong_sel;
      }
      getch();
   }
}