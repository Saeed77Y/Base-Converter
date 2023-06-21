# Converting numbers from base to base (2-10)
In this mini-project, I have made an simple application based on C language and with windows.h library that takes a number and two bases: the base of input number (first base) and the base that we want to convert to (second base); then when we click the CONVERT button, we can get the wanted number at the bottom of the window.
### Here is some explanation about functions in BaseCon.h:
* WrongNum: This function checks if input number can be in the base or not; for example 1102 cannot be in binary base.
* CharToNum: This function converts numbers from string form to integer form for doing mathematical calculations.
* MaxPower: This function findes the maximum power of a base that is smaller than input; for example MaxPower(91,3) equals to 4 because 3^4 = 81 < 91 (I wrote this because I needed this function to use in TenToNum function).
* TenToNum: This function is written for convert number from decimal base to another base (2-9).
* NumToTen: This function is written for convert number from any base to decimal base.
