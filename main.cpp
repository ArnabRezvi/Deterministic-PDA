#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    stack <char> st;
    string a;
    int state = 0;    //0 means push state
    cout<<"\nEnter String:";
    cin>>a;

    for(unsigned i=0; i<a.size(); i++){

        if( (state == 0 ) && (a[i]== '0') ){

            st.push('x');
            state = 0;
            cout<<"pushed\n";

        }
        else if( (state == 0) && (a[i]=='1') ){

            if(st.empty()==true){

                cout<<"REJECTED";
                break;
            }
            else{

                st.pop();
                state = 1;      //1 means pop state
                cout<<"popped\n";
            }
        }

        else if( (state == 1) && (a[i]=='0') ){

            cout<<"REJECTED";
            break;
        }

        else if( (state == 1) && (a[i]=='1') ){

            if(st.empty() == true) {

                cout<<"REJECTED";
                break;

            }
            else if((st.size() == 1) && (a[i+1] == '\0')){

                st.pop();
                cout<<"popped\n";
                cout<<"ACCEPTED";
                break;

            }
            else if((st.empty()== false) && (a[i+1] == '\0')){

                cout<<"REJECTED";
                break;

            }
            else{

                st.pop();
                cout<<"popped\n";
                state=1;

            }

        }
        else{
            cout<<"REJECTED";
        }


    }

    return 0;
}
