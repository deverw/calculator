// Context-free grammar with the following production rules:
// <Expression> = <Term> | <Term> + <Expression> |  <Term> - <Expression>
// <Term> = <Factor> | <Factor> * <Term> | <Factor> / <Term>
// <Factor> = <Float> | (<Expression>)
// <Float> handled by stof

#include <iostream>
#include <string>

using namespace std;

string error_msg="";

size_t FindOp(string exp, char op1, char op2)
// look for first operator (op1 or op2) outside brackets, from left to right
// return 0 if nothing found
{
    size_t pos=0;
    uint brackets=0;
    char check_char;

    while (pos<exp.length())
    {
        check_char=exp.at(pos);
        if (check_char=='(')
            brackets++;
        if (check_char==')')
            if (brackets<1)
            {
                // more closed brackets than opened
                error_msg="Open bracket missing.";
                pos=0;
                break;
            }
            else
                brackets--;
        if (brackets)
            pos++;      // don't look inside brackets
        else
            if (pos && (check_char==op1 || check_char==op2))    // ignore operator at pos=0
                break;      // operator found
            else
                pos++;
    }
    if (brackets)
    {
         // entire expression evaluated and not all brackets closed
        error_msg="Close bracket missing.";
        pos=0;
    }
    return pos;
}

float ReadExpression(string exp);

float ReadFactor(string_exp)
{
    float val;
    if (exp.at(0)=='(')
        if (exp.at(exp.length()-1)==')')
            val=ReadExpression(exp.substr(1,exp.length()-2));
        else
            error_msg="Close bracket missing.";
    else
        try
            val=stof(exp);
        catch (exception &ex)
            error_msg=ex.what();
    return val;
}

float ReadTerm(string exp)
{
    float val;
    size_t pos;
    char op;
    
    pos=FindOp(exp,'*','/');
    if (pos)
    {
        op=exp.at(pos);
        val=ReadFactor(exp.substr(0,pos));
        switch (op)
        {
            case '*':
                val*=ReadTerm(exp.substr(pos+1));
                break;
            case '/':
                val/=ReadTerm(exp.substr(pos+1));
                break;
        }
    }
    else
        val=ReadFactor(exp);
    return val;
}

float ReadExpression(string exp)
{
    float val;
    size_t pos;
    char op;
    
    pos=FindOp(exp,'+','-');
    if (pos)
    {
        op=exp.at(pos);
        val=ReadTerm(exp.substr(0,pos));
        switch (op)
        {
            case '+':
                val+=ReadExpression(exp.substr(pos+1));
                break;
            case '-':
                val-=ReadExpression(exp.substr(pos+1));
                break;
        }
    }
    else
        val=ReadTerm(exp);
    return val;
}

int main()
{
    string exp;
    float result=0;

    cout << "Enter expression: ";
    cin >> exp;
    result=ReadExpression(exp);
    if (error_msg.length())
        cout << "Error: " << error_msg << endl;
    else
        cout << "Result: " << to_string(ReadExpression(exp)) << endl;
}