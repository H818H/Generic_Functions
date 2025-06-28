#include"gENFUNCTIONS.h"
#include<stdio.h>

int main()
{
     // First input: a string (also works for a single char)
    char name[STRING_SIZE];
    _inputFunction("Input NAME: ",  // 1st param: prompt message
        name,                       // 2nd param: variable that will receive input
        T_STR);                     // 3rd param: expected type

    int age;
    _inputFunction("Input AGE: ", &age, T_INT);

    float pi;
    _inputFunction("Input PI: ", &pi, T_FLOAT);

    double payment;
    _inputFunction("Input PAYMENT: ", &payment, T_DOUBLE);

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%0.2f\n", pi);
    printf("%0.5lf\n", payment);

    return 0;
}
