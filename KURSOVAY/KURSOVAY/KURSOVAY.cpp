#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;


bool TryParse(const string& symbol);
int Priority(const string& c);
bool isOperator(const string& c);
vector<string> StringToRPN(string infix);

int check_bkl(string infix) {
    int status = 0;
    int left = 0;
    for (int i = 0; i < infix.size(); i++)
        if (infix[i] == '(') left++;

    int right = 0;
    for (int i = 0; i < infix.size(); i++)
        if (infix[i] == ')') right++;

    if (left == right)
    {
        status = 1;
    }
    else
    {
        cout << "Incorect enter, Reenter expresion:" << endl;
        if (left > right) {
            cout << "the number of brackets on the left is greater than on the right" << endl;
        }
        else
            cout << "the number of brackets on the right is greater than on the left" << endl;
        system("pause");
    }

    return status;
}

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

vector<string> StrToVector(string input) {
    std::stringstream ss(input);
    
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    system("cls");
    return vstrings;
}

string deleteSymbolFromString(string input,char symbol) {
    input.erase(std::remove(input.begin(), input.end(), symbol), input.end());
    return input;
}

string inputString() {
    string temp;
    string fullString;
    std::string equal = "=";
    for (int out = 0; out != 1;)
    {
        getline(cin, temp);
        fullString = fullString + ' ' + temp;
        if (temp.find(equal) != string::npos) {
            out++;
        }   
    }
    return fullString;
}

bool checkDoubleDot(string input) {
    int size = input.size();
    short dot = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '.') {
            dot++;
        }
    }
    if (dot > 1) {
        cout << input << " have two or more dots"<<endl;
        return false;
    }
    return true;
}

bool checkSign(string input) {
    if (input[0] == '+') {
        return true;
    }
    else if (input[0] == '-') {
        return true;
    }
    else if (input[0] == '*') {
        return true;
    }
    else if (input[0] == '/') {
        return true;
    } 
    
    else
        
        return false;
}



bool checkLetters(string input) {
    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        if ((!isdigit(input[i]) && input[i]!='.' && input[0] != '(' && input[0] != ')') && !checkSign(input)) {

            cout << input << " have extra letter" << endl;
            return false;
        }
    }
   
    return true;
}

bool checkExtraSignAndDigit(vector<string> inputVector){

    inputVector.erase(std::remove(inputVector.begin(), inputVector.end(), ")"), inputVector.end());
    inputVector.erase(std::remove(inputVector.begin(), inputVector.end(), "("), inputVector.end());

    for (int i = 0; i < inputVector.size() - 1; ++i) {
        string temp = inputVector[i];
        string temp2 = inputVector[i+1];
        if (checkSign(temp) == checkSign(temp2)) {
            cout << temp << " " << temp2 << " is not corect input, you miss sign or number" << endl;
            return false;
        }
    }
    return true;
}

bool checkExtraChar(vector<string> inputVector) {

    for (int i = 0; i < inputVector.size(); ++i) {
        string temp = inputVector[i];
        for (int step = 0; step < temp.size(); step++)
        {
            if (!checkDoubleDot(temp)) {
                return false;
            }
            if (!checkLetters(temp)) {
                return false;
            }
            if (!checkExtraSignAndDigit(inputVector)) {
                return false;
            }
        }
    }
    return true;
}




int main()
{
    string infix;// = "12.3 * 3 + 1 * 0 + 2 / 0 + ( ( 5 * 1 ) + 1 ) / 0 + 1=";//our infix expression

    for (int status = 0; status != 2 ; )
    {
        cout << "Enter expresion, after every symbol put space \"( ( a + b ) * c )\":" << endl;
        infix = deleteSymbolFromString(inputString(),'=');
        status=check_bkl(infix);
        if (status == 1) {
            vector<string> temp = StrToVector(infix);
            if (checkExtraChar(temp)) {
                status++;
            }
        }
        system("cls");
    }
    
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