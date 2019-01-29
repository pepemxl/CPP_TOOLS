/**
 * @file bigintegers.cpp
 * @author José Luis Alonzo Velázquez (pepemxl@gmail.com)
 * @brief Class Big Integer to use huge numbers.
 * @version 0.1
 * @date 2019-01-29
 * 
 * @copyright Copyright (c) 2019
 * 
 * MACRO MAX save the larger number of characters that can be used for one number.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 10000

using namespace std;
/**
 * @brief Class BigInteger
 * 
 */
class BigInteger{
private:
    string number_;
    bool sign_;
public:
    BigInteger();                       //!< Empty constructor initializes zero
    BigInteger(int n);                  //!< "int" constructor
    BigInteger(string s);               //!< "string" constructor
    BigInteger(string s, bool sin);     //!< "string" constructor
    ~BigInteger();                      //!< Empty destructor
    void setNumber(string s);           //!< Assign value to number
    const string& getNumber();          //!< Retrieves the number
    void setSign(bool s);               //!< Assign value to sign
    const bool& getSign();              //!< Retrieves the sign
private:
    string add(string number1, string number2);              //!< Method add
};

/**
 * @brief Construct a new Big Integer:: Big Integer object
 * Empty constructor initializes zero
 */
BigInteger::BigInteger(){
    this->number_ = "0";
    this->sign_ = false;
}
/**
 * @brief Construct a new Big Integer:: Big Integer object
 * 
 * @param n 
 */
BigInteger::BigInteger(int n) { // "int" constructor
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    if( isdigit(s[0]) ) {
        setNumber( s );
        setSign( false );
    } else {
        setNumber( s.substr(1) );
        setSign( s[0] == '-' );
    }
}
/**
 * @brief Construct a new Big Integer:: Big Integer object
 * "string" constructor
 * @param s 
 */
BigInteger::BigInteger(string s){ 
    if( isdigit(s[0]) ){
        this->setNumber(s);
        this->sign_ = false;
    }else{
        this->setNumber( s.substr(1) );
        this->sign_ = (s[0] == '-');
    }
}
/**
 * @brief Construct a new Big Integer:: Big Integer object
 * "string" constructor
 * @param s 
 * @param sin 
 */
BigInteger::BigInteger(string s, bool sin){
    setNumber( s );
    setSign( sin );
}
/**
 * @brief 
 * 
 * @param s 
 */
void BigInteger::setNumber(string s) {
    this->number_ = s;
}
/**
 * @brief 
 * 
 * @return const string& 
 */
const string& BigInteger::getNumber() { 
    return this->number_;
}
/**
 * @brief 
 * 
 * @param s 
 */
void BigInteger::setSign(bool s) {
    this->sign_ = s;
}
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
const bool& BigInteger::getSign() {
    return this->sign_;
}
/**
 * @brief Method add
 * 
 * @param number1 
 * @param number2 
 * @return string 
 */
string BigInteger::add(string number1, string number2) {
    string add = (number1.length() > number2.length()) ?  number1 : number2;
    char carry = '0';
    int differenceInLength = abs( (int) (number1.size() - number2.size()) );

    if(number1.size() > number2.size()){
        number2.insert(0, differenceInLength, '0'); 
    }else{
        number1.insert(0, differenceInLength, '0');
    }

    for(int i=number1.size()-1; i>=0; --i){
        add[i] = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';
        if(i != 0) {
            if(add[i] > '9') {
                add[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if(add[0] > '9') {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}

int main(int argc, char *argv[]){
    BigInteger test1();
    return 0;
}