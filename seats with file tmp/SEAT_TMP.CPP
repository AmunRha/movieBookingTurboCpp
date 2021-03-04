#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>

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

fstream f;
				       //prints the rough layout
void print_layout()
{
   cout<<"\n\n\t   ";
   char a='A';
   for(int i=0;i<15;i++)
   {
      textcolor(WHITE);
      if(i==7)
	 cout<<"    ";
      else
      {
	 cout<<a++<<"   ";
      }
   }
   cout<<endl;
   int n=0;
   for(i=0;i<10;i++)
   {
      cout<<endl<<n++<<"\t   ";
      for(int j=0;j<15;j++)
      {
	 if(j==7)
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
	    textcolor(CYAN+BLINK);
	    cprintf("O");
	    cout<<"   ";
	 }
      }
   }
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

void main()
{
   clrscr();
   char choice,cord[2];
   initdata();
   cout<<"Current layout: \n";
   //print_layout();
      f.open("xemp.txt",ios::in);
   while(f.getline(cord,3,'\n'))
   {
      for(int i=0;i<10;i++)
	 for(int j=0;j<15;j++)
	    if(strcmpi(cord,s[i][j].ret_cord())==0)
		s[i][j].seatocc();
   }
   print_layout();
   getch();
   f.close();
   f.open("xemp.txt",ios::out|ios::ate);
   do
   {
      cout<<"\n\nEnter a seat to continue[0a,1b,2c,etc]\n";
      cin>>cord;
      f.write(cord,strlen(cord)).put('\n');
      cout<<"\nDo you want to continue?";
      cin>>choice;
   }
   while(choice=='y'||choice=='Y');
   getch();
   f.close();
   clrscr();
   clrscr();
   cout<<"Layout after reading the file: \n";
   f.open("xemp.txt",ios::in);
   while(f.getline(cord,3,'\n'))
   {
      for(int i=0;i<10;i++)
	 for(int j=0;j<15;j++)
	    if(strcmpi(cord,s[i][j].ret_cord())==0)
		s[i][j].seatocc();
   }
   print_layout();
   getch();
}