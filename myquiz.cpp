#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;

class quiz
{
private:

    int right,wrong, score;
    string name;
    vector<string> user_name;//user name
    char ans;
    string s;

public:
    quiz()
    { score=0,right=0 ,wrong=0; }
    void init();
    void define();
    void display();
};
void  quiz :: define()
{
   ifstream inf,answ;
   char ch;
      int i=0;
   inf.open("quiz.txt",ios::in);
   answ.open("answer.txt",ios::in);
    while(getline(inf,s))
    {
answ >> noskipws >> ch;
    cout<<endl<<s<<endl;
  cout<<"Type your option"<<endl;
    cin>>ans;

    if(ch==ans)
       {
       score=score+2;
        right++;
        }
    else
       {
       wrong++;
       
       }
    }
   inf.close();
   answ.close();
}
void quiz :: init()
 {
     cout<<"\n\n\t\t\t\t\t  enter your Name:"<<endl;
      cin>>name;
      user_name.push_back(name);
     
  }
     
     
void quiz :: display()
{
    cout << " \n\n\t\t\t\t\t   ** SCORE BOARD **\n\n\n";
    cout << "\t\t\t\t\t............................\n\n";
    cout << "\t\t\t\t\t:       USER  NAME         : ";
    for(int i=0;i<5;i++)
    cout<<user_name[i] ;
	cout<< "\n\n";
    cout << "\t\t\t\t\t...........................:\n\n";
    cout << "\t\t\t\t\t:      TOTAL SCORE         : " <<score<< "\n\n";
    cout << "\t\t\t\t\t...........................:\n\n";
    cout << "\t\t\t\t\t:TOTAL ATTEMPT QUESTION    : " << right + wrong << "\n\n";
    cout << "\t\t\t\t\t...........................:\n\n";
    cout << "\t\t\t\t\t:      WRONG QUESTION      : " << wrong << "\n\n";
    cout << "\t\t\t\t\t...........................: \n\n";
    cout << "\t\t\t\t\t:      RIGHT QUESTION      : " << right << "\n\n";
    cout << "\t\t\t\t\t:..........................:\n\n";
    
    right=0,wrong=0,score=0;
 }


int main()
{
    quiz r;
    cout<<"\n\n\t\t\t\t\t             ** WEL-COME**";
	cout<<"\n\n\t\t\t\t\t            ** Quiz Game **";
	cout<<"\n\n\t\t\t\t\t========================================";
	cout<<"\n\n\t\t\t\t\t||  Developed By : deeksha and muskan || ";
	cout<<"\n\n\t\t\t\t\t========================================";
	cout<<"\n\n";
   
   // cout<<"\t*2 marks per quiz";
       L:
   
       int c;
       fflush(stdin);
       while(1)
       {
       	 cout<<"\n\n\t\t\t\t\t\tselect your choice:\n"
        <<"\n\t\t\t\t\t1 for start quiz"<<"\n\t\t\t\t\t2 for display quiz score"
        <<"\n\t\t\t\t\t3 for exit the quiz :";
       cin>>c;
       	
       switch(c)
       {
       case 1:
        r.init();
          r.define();
          break;
        case 2:
          r.display();
          break;
       case 3:
           exit(1);
       default:
         cout<<"invalid choice!";
        goto L;
       }
    }
      // system("pause");

}
