#ifndef _CALCULATOR_

#define _CALCULATOR_

#include <iostream> // cin, cout
#include <string>   // string, stof
#include <cstddef>  // size_t

using namespace std;

size_t FindOp(string exp, char op1, char op2);
float ReadExpression(string exp);
float ReadValue(string exp);
float ReadProduct(string exp);

#endif