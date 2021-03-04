#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
fstream f("seats.dat",ios::binary|ios::in|ios::out);
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
   cprintf("                      SCREEN ");
   cout<<n<<endl;
   textcolor(WHITE);
   int i,j;
   for(i=2;i<12;i++)
   for(j=2;j<17;j++)
   s[i][j].a='O';
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
   f.seekg(k*sizeof(t),ios::beg);
   f.read((char*)&t,sizeof(t));
   if(t.seatshow()==1)
   return 1;
   else
   return 0;
   }
void main()
   {
   clrscr();
   int n;
   textcolor(WHITE);
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
	 {
	 s[i][j].seatocc();
	 int t=(12*i)+j;
	 f.seekg(t*sizeof(s),ios::beg);
	 f.write((char*)&s[i][j],sizeof(s));
	 }
      seatlayout();
      cout<<endl;
      getch();
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
	 f.seekg(t*sizeof(s),ios::beg);
	 f.write((char*)&s[i][j],sizeof(s));
	 }
      seatlayout();
      getch();
      break;
      }
   getch();
   }