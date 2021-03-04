#include<fstream.h>
#include<conio.h>
#include<graphics.h>

void main()
 {
 //int gd=DETECT,gm;
 //initgraph(&gd,&gm,"c:/turboc3/bgi");
 clrscr();
 fstream f("jaguar.txt",ios::app|ios::in|ios::out);
 char c[200];
 while(f.getline(c,200))
  {
  if(f.eof())
   break;
  cout<<c<<endl
  ;
  }
 //cout<<"sdrftgyuiopiuygtfdghjkiljuhgfdsfghjuki\nredxfcgvhsafojusdfoajuoiahydsgcvifaudgfvciuagdvoaufc\nalkisdhfgaoiydhgoaisydhgcvoafsicgvoaisvcgaoidysvgoaidyfh\nalidshgcfvolaIdCVGBOAIvBPOIAcgvuoaiddvoaiydvoaucvoAIYVA\NAKUDJSHFVCAIUYDSFGVOAUIYEDGFRAOIUWEYFCDVGAOUSCVAOUYFGVAOIFYGC\n";
 f.close();
 getch();
 //closegraph();
 //restorecrtmode();
 }