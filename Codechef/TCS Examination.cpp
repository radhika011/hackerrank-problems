
/*
Two friends, Dragon and Sloth, are writing a computer science examination series. There are three subjects in this series: DSA, TOC, and DM. Each subject carries 100 marks.

You know the individual scores of both Dragon and Sloth in all 3 subjects. You have to determine who got a better rank.

The rank is decided as follows:

The person with a bigger total score gets a better rank
If the total scores are tied, the person who scored higher in DSA gets a better rank
If the total score and the DSA score are tied, the person who scored higher in TOC gets a better rank
If everything is tied, they get the same rank.



*/


#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int d1,d2,d3;
        int s1,s2,s3;
        cin>>d1>>d2>>d3;
        cin>>s1>>s2>>s3;
        int d = d1+d2+d3;
        int s = s1+s2+s3;
        if(d>s){
            cout<<"Dragon"<<endl;
            continue;
        }
        else if(s>d){
            cout<<"Sloth"<<endl;
            continue;
        }
        else{
            if(d1>s1){
                cout<<"Dragon"<<endl;
                continue;
            }
            else if(d1<s1){
                cout<<"Sloth"<<endl;
                continue;
            }
            else{
                 if(d2>s2){
                cout<<"Dragon"<<endl;
                continue;
            }
            else if(d2<s2){
                cout<<"Sloth"<<endl;
                continue;
            }
            else{
               if(d3>s3){
                cout<<"Dragon"<<endl;
                continue;
            }
            else if(d3<s3){
                cout<<"Sloth"<<endl;
                continue;
            }
            else{
                cout<<"Tie"<<endl;
                continue;

            }
            }



            }

        }

    }
    return 0;
}
