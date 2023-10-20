#include <bits/stdc++.h>
using namespace std;

class Calculator
{
private:
    double a;
    double b;

public:
    Calculator(double a, double b) {}
    Calculator(){}
    double add(double a, double b) { return a + b; }
    double div(double a, double b) { return (b != 0) ? a / b : 0; }
    double mul(double a, double b) { return a * b; }
    double sub(double a, double b) { return a - b; }

    void exp(string result){
        char arr[]={'+','*','/','-'};
        for(int i:arr){
            if(result.find(i)){
                switch(i){
                case '+': add(a,b);
                            break;
                case '-': sub(a,b);
                            break;
                case '*': mul(a,b);
                            break;
                case '/': div(a,b);
                default: cout<<"Invalid Input";
                };
            }
    }
};


int main(int argc, char* argv[])
{
    Calculator calc;
    string result;
    
    if(argc>1){
        result=argv[1];
        cout<<calc.exp(result)<<endl;
    }
    else{
        while(true){
            cout<<"Enter expression or 'q' to quit -> ";
            getline(cin,result);
            if(result=='q'||result=='Q')
                break;
            
        }
    }
    return 0;
}