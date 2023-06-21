#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

int WrongNum(int Input, int Base) //checks if input number can be in the base or not
{
    if (Input<10)
    {
        if (Input>=Base)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        while(Input!=0)
        {
            int remainder = Input%10;
            if(remainder>=Base)
            {
                return true;
                break;
            }
            Input /=10;
        }
        return false;
    }
}

long int CharToNum(char x[]) //converts a number from string form to integer form
{
    int len = strlen(x);
    long int y = 0;
    for (int i=0;i<strlen(x);i++)
    {
        switch(x[i])
        {
            case '1':
                y += pow(10,len);
                break;
            case '2':
                y += 2*pow(10,len);
                break;
            case '3':
                y += 3*pow(10,len);
                break;
            case '4':
                y += 4*pow(10,len);
                break;
            case '5':
                y += 5*pow(10,len);
                break;
            case '6':
                y += 6*pow(10,len);
                break;
            case '7':
                y += 7*pow(10,len);
                break;
            case '8':
                y += 8*pow(10,len);
                break;
            case '9':
                y += 9*pow(10,len);
                break;
            case '0':
                y += 0;
                break;    
        }
        --len;
    }
    return y/10;
}

int MaxPower(int Input,int Base) //finds maximum power of base before input (needed for TenToNum function)
{
    int Power = 0;
    while (Input>=pow(Base,Power))
    {
        Power++;
    }
    return Power-1;
}

int TenToNum(int Input, int TBase) //converts number from 10(base) to another base
{
    int Converted = 0;
    while (Input!=0)
    {
        int x = MaxPower(Input,TBase);
        int Quotient = Input/pow(TBase,x);
        Converted += Quotient*pow(10,x);
        Input -= Quotient*pow(TBase,x);
    }
    return Converted;
}

int NumToTen(long int Input, int FBase) //converts number from any base to 10(base)
{
    int Converted = 0;
    int Digit = 0;
    while(Input!=0)
    {
        int Remainder = Input%10;
        Converted += Remainder*pow(FBase,Digit);
        Digit++;
        Input/=10;
    }
    return Converted;
}