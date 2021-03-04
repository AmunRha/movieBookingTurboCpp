#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

void main()
 {
 clrscr();
 fstream f("jaguar.txt",ios::app|ios::in|ios::out);
 char c[200];
 textcolor(GREEN);
 for(int i=1;i<=4;i++)
 {
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
  cout<<c<<endl;
  }
 f.close();
 f.open("jaguar.txt",ios::app|ios::in|ios::out);
 }
 f.close();
 getch();
 }