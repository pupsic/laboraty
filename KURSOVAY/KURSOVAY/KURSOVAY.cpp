#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

bool TryParse(const string& symbol);
int Priority(const string& c);
bool isOperator(const string& c);
vector<string> StringToRPN(string infix);


bool is_sign(string str) {
    std::string plus = "+";
    std::string minus = "-";
    std::string mult = "*";
    std::string div = "/";
    if (str.find(plus) != string::npos) {
        return true;
    }
    else if (str.find(minus) != string::npos) {
        return true;
    }
    else if (str.find(mult) != string::npos) {
        return true;
    }
    else if (str.find(div) != string::npos) {
        return true;
    }
    else
        return false;
}



float Opertion(string str,float a, float b) {
    std::string plus="+";
    std::string minus="-";
    std::string mult="*";
    std::string div="/";
    if (str.find(plus) != string::npos) {
        return a + b;
    }
    else if (str.find(minus) != string::npos) {
        return a - b;
    }
    else if (str.find(mult) != string::npos) {
        return a * b;
    }
    else if (str.find(div) != string::npos) {
        if (b == 0) {
            cout << "error: cannot be divided by zero"<<endl;
        }
        return a / b;
    }
    else
        return 0;
}

string delete_paren(string str) {
    if (str.front() == '(') {
        str.erase(0, 1);
        if (str.back() == ')') {
            str.erase(str.size() - 1);
        }
    }
    return str;
}

void print_vetor(vector<string> outputList) {
    cout << "vector: ";
    for (int out = 0; outputList.size() > out; out++) {
        cout << " " << outputList[out] << " ";
    }
    cout << endl;
}

vector<string> count_RPN(vector<string> outputList){
    string operation;

    float a;
    float b;
    int current_step;

    for (int step = 0; outputList.size() != 1; step++)
    {

        operation = outputList[step];
        //print_vetor(outputList);
        if (is_sign(operation)) {
            current_step = step;

            step--;
            b = stof(outputList[step]);
            outputList.erase(outputList.begin() + current_step);

            step--;
            a = stof(outputList[step]);
            outputList.erase(outputList.begin() + --current_step);
            /*cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout <<"result: "<< Opertion(operation, a, b)<<endl;*/
            outputList[--current_step] = to_string(Opertion(operation, a, b));

        }
    }
    return outputList;
}



int main()
{
    string infix;// = "12.3 * 3 + 1 * 0 + 2 / 0 + ( 5 * 1 ) / 0 + 1";//our infix expression
    cout << "Enter expresion, after every symbol put space \"( ( a + b ) * c )\":"<<endl;
    getline(cin, infix);
    vector<string> outputList = StringToRPN(infix);
    outputList = count_RPN(outputList);
    cout <<infix <<" = " <<outputList[0];
    return 0;
}

vector<string> StringToRPN(string infix) {
    istringstream iss(infix);
    vector<string> tokens;//store the tokens here
    while (iss)
    {
        string temp;
        iss >> temp;
        tokens.push_back(temp);
    }
    vector<string> outputList;//output vector
    stack<string> s;//main stack

    //operator: +, -, *, /, ^, ()
    //operands: 1234567890
    for (unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        if (TryParse(tokens[i]))
        {
            outputList.push_back(tokens[i]);
        }
        if (tokens[i] == "(")
        {
            s.push(tokens[i]);
        }
        if (tokens[i] == ")")
        {
            while (!s.empty() && s.top() != "(")
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        if (isOperator(tokens[i]) == true)
        {
            while (!s.empty() && Priority(s.top()) >= Priority(tokens[i]))
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.push(tokens[i]);
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while (!s.empty())
    {
        outputList.push_back(s.top());
        s.pop();
    }
    return outputList;
}


bool TryParse(const string& symbol)
{
    bool isNumber = false;
    for (unsigned int i = 0; i < symbol.size(); i++)
    {
        if (!isdigit(symbol[i]))
        {
            isNumber = false;
        }
        else
        {
            isNumber = true;
        }
    }
    return isNumber;
}
int Priority(const string& c)
{
    if (c == "^")
    {
        return 3;
    }
    if (c == "*" || c == "/")
    {
        return 2;
    }
    if (c == "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool isOperator(const string& c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}