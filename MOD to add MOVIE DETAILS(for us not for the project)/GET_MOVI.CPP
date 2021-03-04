#include<fstream.h>
#include<conio.h>
#include<stdio.h>

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
};

void main()
{
   clrscr();
   fstream f("Movie_Details.bat",ios::binary|ios::ate|ios::in|ios::out);
   //fstream ft("MD.txt",ios::in|ios::out);
   char ch;
   movie_details m;
   do
   {
      f.seekp(0,ios::end);
      cout<<"\nEnter the movie name: ";
      gets(m.name);
      cout<<"Enter movie code: ";
      cin>>m.code;
      cout<<"Enter the language of the movie: ";
      gets(m.language);
      cout<<"Enter the synopsis of the movie: ";
      gets(m.synopsis);
      cout<<"Enter the release date of the movie: ";
      gets(m.release_date);
      cout<<"Enter the rating of the movie<'x'%>: ";
      gets(m.rating);
      cout<<"Enter the runtime of the movie<'x' h 'y' min>: ";
      gets(m.runtime);
      cout<<"Enter the cast of the movie: ";
      gets(m.cast);
      f.write((char*)&m,sizeof(m));
      cout<<"Do you wan to continue?\n";
      cin>>ch;
      }while(ch=='y');
/*f.seekp(0,ios::beg);
cout<<sizeof(m);
while(f.read((char*)&m,sizeof(m)))
{
   cout<<m.name;
   cout<<m.code;
   cout<<m.release_date;
   cout<<m.runtime;
   cout<<m.cast;
   cout<<m.synopsis;
   cout<<m.rating;
   cout<<m.language<<endl;
} */
      /*ft.getline(m.name,50,'#');
      cout<<m.name;
      ft>>m.code;
      cout<<m.code;
      ft.getline(m.release_date,10,'#');
      cout<<m.release_date;
      ft.getline(m.runtime,10,'#');
      cout<<m.runtime;
      ft.getline(m.cast,100,'#');
      cout<<m.cast;
      ft.getline(m.synopsis,200,'#');
      cout<<m.synopsis;
      ft.getline(m.rating,4,'#');
      cout<<m.rating;
      ft.getline(m.language,10,'#');
      cout<<m.language<<endl;*/
   getch();
}