// Context-free grammar with the following production rules:
// <Expression> = <Product> | <Product> + <Expression> |  <Product> - <Expression>
// <Product> = <Value> | <Value> * <Product> | <Value> / <Product>
// <Value> = float | (<Expression>)

#include "calculator.hpp"

string error_msg = "";

size_t FindOp(string exp, char op1, char op2)
// look for first operator in string 'exp' (character defined by 'op1' and 'op2') outside brackets, from left to right
// return 0 if nothing found
{
    size_t pos = 0;
    int brackets = 0;
    char check_char;
    bool op_found = false;

    while (pos < exp.length())
    {
        check_char = exp.at(pos);
        if (check_char == '(')
            brackets++;
        if (check_char == ')')
            if (brackets < 1)
            {
                // more closed brackets than opened
                error_msg = "Open bracket missing.";
                pos = 0;
                break;
            }
            else
                brackets--;
        if (brackets)
            pos++;      // don't look inside brackets
        else
            if (pos && (check_char == op1 || check_char == op2))    // ignore operator at pos=0
            {
                op_found = true;        // operator found
                break;
            }
            else
                pos++;
    }
    if (!op_found)
        pos = 0;
    if (brackets)
    {
        // entire expression evaluated and not all brackets closed
        error_msg = "Close bracket missing.";
        pos = 0;
    }

    return pos;
}

float ReadValue(string exp)
{
    float val;
    if (exp.at(0) == '(')
        if (exp.at(exp.length() - 1) == ')')
            val = ReadExpression(exp.substr(1, exp.length() - 2));
        else
            error_msg = "Close bracket missing.";
    else
    {
        try
        {
            val = stof(exp);
        }
        catch (exception& ex)
        {
            error_msg = ex.what();
        }
    }
    return val;
}

float ReadProduct(string exp)
{
    float val;
    size_t pos;
    char op;

    pos = FindOp(exp, '*', '/');
    if (pos)
    {
        op = exp.at(pos);
        val = ReadValue(exp.substr(0, pos));
        switch (op)
        {
        case '*':
            val *= ReadProduct(exp.substr(pos + 1));
            break;
        case '/':
            val /= ReadProduct(exp.substr(pos + 1));
            break;
        }
    }
    else
        val = ReadValue(exp);
    return val;
}

float ReadExpression(string exp)
{
    float val;
    size_t pos;
    char op;

    pos = FindOp(exp, '+', '-');
    if (pos)
    {
        op = exp.at(pos);
        val = ReadProduct(exp.substr(0, pos));
        switch (op)
        {
        case '+':
            val += ReadExpression(exp.substr(pos + 1));
            break;
        case '-':
            val -= ReadExpression(exp.substr(pos + 1));
            break;
        }
    }
    else
        val = ReadProduct(exp);
    return val;
}

int main()
{
    string exp;
    float result = 0;

    cout << "Enter expression: ";
    cin >> exp;
    result = ReadExpression(exp);
    if (error_msg.length())
        cout << "Error: " << error_msg << endl;
    else
        cout << "Result: " << to_string(result) << endl;
    cout << "(Press 'Enter' to exit)";
    cin.clear();
    cin.ignore(2);
    return(0);
}