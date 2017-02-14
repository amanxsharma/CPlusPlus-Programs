//Stack Program
//Input is a string, in the form "5 + 10 POP 5 DUP"
//If a digit comes, push it over stack
//If a + or - comes, POP two digits from stack, calculate and push //the result over stack
//DUP - duplicate the top of the stack

#include <sstream>
#include <locale>
using namespace std;

int solution(string &S) {
    std::locale loc;
   int i = 0,len,counter=0;;
   unsigned int stack[500];
   string arr[500];
    stringstream ssin(S);
    while (ssin.good()){
        ssin >> arr[i];
        ++i;
    }
    len= i;
    for(i=0; i<=len; i++){
       // cout << arr[i] << endl;
        if(isdigit(arr[i],loc)){
        counter++;
        stack[counter] = stoi(arr[i]); //increment counter and Push on the stack 
        
        }
        if(arr[i] == "DUP"){
            unsigned int temp = stack[counter]; //POP top value;
            counter++;
            stack[counter] = temp; //PUSH duplicate value
        }
        if(arr[i] == "POP")
        {
            counter--; //Remove top most element
        }
        if(arr[i]=="+")
        {
            unsigned int sum, first_val, second_val;
            first_val = stack[counter]; //POP first value
            counter--;
            second_val = stack[counter]; //POP second value
            counter --;
            sum = first_val + second_val;
            
            counter++;
            stack[counter] = sum;
            }
        if(arr[i]=="-")
        {
            unsigned int sub, first_val, second_val;
            first_val = stack[counter]; //POP first value
            counter--;
            second_val = stack[counter]; //POP second value
            counter --;
            sub = first_val - second_val;
            
            counter++;
            stack[counter] = sub;
            }
    }
return stack[counter];
    
}