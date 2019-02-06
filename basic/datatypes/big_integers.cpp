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
 * @brief Class BigInteger Class to manage big 
 * 
 * @todo 
 *  <lu>
 *      <li>Implement iterator with bigintegers</li>
 *      <li></li>
 *  </lu>
 */
class BigInteger{
private:
    string number_;
    bool sign_;
public:
    BigInteger();                                 //!< Empty constructor initializes zero
    BigInteger(int n);                            //!< "int" constructor
    BigInteger(string s);                         //!< "string" constructor
    BigInteger(string s, bool sign);              //!< "string" constructor with parameter sign
    ~BigInteger();                                //!< Empty destructor
    void setNumber(string s);                     //!< Assign value to number
    const string& getNumber();                    //!< Retrieves the number
    void setSign(bool s);                         //!< Assign value to sign
    const bool& getSign();                        //!< Retrieves the sign
    BigInteger abs();                             //!< Returns the absolute value
    int digits();                                 //!< Return the number of digits
    bool isNegative();                            //!< Determine wheter a BigIntegers is negative
    bool isPositive();                            //!< Determine wheter a BigIntegers is positive
    bool isEven();                                //!< Determines whereted a BigInteger is even
    bool isOdd();                                 //!< Determines whereted a BigInteger is odd
    static BigInteger combinations(int n, int k); //!< Returns nCk
    static BigInteger ordenations(int n, int k);  //!< Returns nOk
    static BigInteger factorial(int n);           //!< Returns the factorial value
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &num);//!< Output stream operator
    void operator = (BigInteger b);               //!< Operator =
    bool operator < (BigInteger b);               //!< Operator <
    bool operator > (BigInteger b);               //!< Operator >
    bool operator == (BigInteger b);              //!< Operator ==
    bool operator != (BigInteger b);              //!< Operator !=
    bool operator <= (BigInteger b);              //!< Operator <=
    bool operator >= (BigInteger b);              //!< Operator >=
    BigInteger& operator ++();                    //!< Prefix increment
    BigInteger operator ++(int);                  //!< Postfix increment
    BigInteger& operator --();                    //!< Prefix decrement
    BigInteger operator --(int);                  //!< Postfix decrement
    BigInteger operator + (BigInteger b);         //!< Operator +
    BigInteger operator - (BigInteger b);         //!< Operator -
    BigInteger operator * (BigInteger b);         //!< Operator *
    BigInteger operator / (BigInteger b);         //!< Operator /
    BigInteger operator % (BigInteger b);         //!< Operator %
    BigInteger& operator += (BigInteger b);       //!< Operator +=
    BigInteger& operator -= (BigInteger b);       //!< Operator -=
    BigInteger& operator *= (BigInteger b);       //!< Operator *=
    BigInteger& operator /= (BigInteger b);       //!< Operator /=
    BigInteger& operator %= (BigInteger b);       //!< Operator %=
    BigInteger& operator [] (int n);              //!< Operator []
    BigInteger operator -();                      //!< Unary minus sign
    operator string();                            //!< Conversion from BigInteger to string
private:
    long long int toInt(string s);                                      //!< Convert to long long int
    string toString(long long n);                                       //!< Convert to string
    string add(string s1, string s2);                                   //!< Method add
    string subtract(string s1, string s2);                              //!< Method subtract
    string multiply(string s1, string s2);                              //!< Method Multiply
    string pow(int exponent);                                           //!< Raises to the power of the exponent
    string divide(string s1);                                           //!< Method divide by another BigInteger
    std::pair<string, long long int> divide(string s, long long int d); //!< Method divide by long long int
    bool equals(BigInteger b1, BigInteger b2);                          //!< Method to compare two big integers
    bool less(BigInteger b1, BigInteger b2);                            //!< Method to compare with a less than
    bool greater(BigInteger b1, BigInteger b2);                         //!< Method to compare with a greater than
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
 * @brief Destroy the Big Integer:: Big Integer object
 * 
 */
BigInteger::~BigInteger(){
    this->number_ = "0";
    this->sign_ = false;
}
/**
 * @brief Construct a new Big Integer:: Big Integer object from parameter int
 * 
 * @param n 
 */
BigInteger::BigInteger(int n){
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    if(isdigit(s[0])){
        this->setNumber(s);
        this->setSign(false);
    }else{
        this->setNumber(s.substr(1));
        this->setSign(s[0] == '-');
    }
}
/**
 * @brief Construct a new Big Integer:: Big Integer object
 * "string" constructor, if sign is "-"" then turn true the flag this->sign_
 * otherwise turn false this flag.
 * @param s 
 */
BigInteger::BigInteger(string s){ 
    if(isdigit(s[0])){
        this->setNumber(s);
        this->sign_ = false;
    }else{
        this->setNumber(s.substr(1));
        this->sign_ = (s[0] == '-');
    }
}
/**
 * @brief Construct a new Big Integer:: Big Integer object
 * "string" constructor with parameter sign
 * @param s 
 * @param sin 
 */
BigInteger::BigInteger(string s, bool sign){
    this->setNumber(s);
    this->setSign(sign);
}
/**
 * @brief Method set for variable number_
 * 
 * @param s 
 */
void BigInteger::setNumber(string s){
    this->number_ = s;
}
/**
 * @brief Method get for number_
 * 
 * @return const string& 
 */
const string& BigInteger::getNumber(){ 
    return this->number_;
}
/**
 * @brief Method set for sign_
 * 
 * @param s 
 */
void BigInteger::setSign(bool s){
    this->sign_ = s;
}
/**
 * @brief Method get for sign_
 * 
 * @return true 
 * @return false 
 */
const bool& BigInteger::getSign(){
    return this->sign_;
}
/**
 * @brief Method that return absolute value
 * 
 * @return BigInteger 
 */
BigInteger BigInteger::abs(){
    return BigInteger(this->getNumber());
}
/**
 * @brief Return the number of digist of BigInteger
 * 
 * @return int 
 */
int BigInteger::digits(){
    int total = this->number_.length();
    return total;
}
/**
 * @brief Determine wheter a BigIntegers is negative
 * 
 * @return true 
 * @return false 
 */
bool BigInteger::isNegative(){
    bool flag = false;
    if(this->getSign()){
        flag = true;
    }
    return flag;
}
/**
 * @brief Determine wheter a BigIntegers is positive
 * 
 * @return true 
 * @return false 
 */
bool BigInteger::isPositive(){
    bool flag = false;
    if(!this->getSign()){
        flag = true;
    }
    return flag;
}
/**
 * @brief Determines whereted a BigInteger is even
 * 
 * @return true 
 * @return false 
 */
bool BigInteger::isEven(){
    bool flag = false;
    int n = this->number_.length()-1;
    if(int(this->number_[n]-'0')%2 == 0){
        flag = true;
    }
    return flag;
}
/**
 * @brief Determines whereted a BigInteger is odd
 * 
 * @return true 
 * @return false 
 */
bool BigInteger::isOdd(){
    bool flag = false;
    int n = this->number_.length()-1;
    if(int(this->number_[n]-'0')%2 == 1){
        flag = true;
    }
    return flag;
}
/**
 * @brief Returns nCk
 * 
 * @param n 
 * @param k 
 * @return BigInteger 
 */
BigInteger BigInteger::combinations(int n, int k){
    BigInteger aux(0);    
    return aux;
}
/**
 * @brief Returns nOk
 * 
 * @param n 
 * @param k 
 * @return BigInteger 
 */
BigInteger BigInteger::ordenations(int n, int k){
    BigInteger aux(0);    
    return aux;
}
/**
 * @brief Returns factorial of n
 * 
 * @param n 
 * @return BigInteger 
 */
BigInteger BigInteger::factorial(int n){
    BigInteger aux(1);
    for(int i = 1; i <= n;++i){
        aux *= i;
    }
    return aux;
}
/**
 * @brief Overload of operator << as friend function
 * 
 * @param os 
 * @param num 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const BigInteger &b){
    os << b.number_;
    return os;
}
/**
 * @brief Operator =
 * 
 * @param b 
 */
void BigInteger::operator = (BigInteger b){
    this->setNumber(b.getNumber());
    this->setSign(b.getSign());
}
/**
 * @brief Operator ==
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator == (BigInteger b) {
    return this->equals((*this) , b);
}
/**
 * @brief Operator !=
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator != (BigInteger b) {
    return !this->equals((*this) , b);
}
/**
 * @brief Opertaor >
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator > (BigInteger b) {
    return this->greater((*this) , b);
}
/**
 * @brief Operator <
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator < (BigInteger b){
    return this->less((*this),b);
}
/**
 * @brief Operator >=
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator >= (BigInteger b){
    return this->equals((*this),b) || this->greater((*this),b);
}
/**
 * @brief Operator <=
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator <= (BigInteger b){
    return this->equals((*this) , b) || this->less((*this) , b);
}
/**
 * @brief Prefix increment
 * 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator ++(){
    (*this) = (*this) + 1;
    return (*this);
}
/**
 * @brief Postfix increment
 * 
 * @return BigInteger 
 */
BigInteger BigInteger::operator ++(int){
    BigInteger before = (*this);
    (*this) = (*this) + 1;
    return before;
}
/**
 * @brief Prefix decrement
 * 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator --(){
    (*this) = (*this) - 1;
    return (*this);

}
/**
 * @brief Postfix decrement
 * 
 * @return BigInteger 
 */
BigInteger BigInteger::operator --(int){
    BigInteger before = (*this);
    (*this) = (*this) - 1;
    return before;
}
/**
 * @brief Operator +
 * 
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator + (BigInteger b){
    BigInteger sum;
    if(this->getSign() == b.getSign()){
        sum.setNumber(this->add(this->getNumber(),b.getNumber()));
        sum.setSign(this->getSign());
    }else{
        if(this->abs() > b.abs()){
            sum.setNumber(this->subtract(this->getNumber(),b.getNumber()));
            sum.setSign(this->getSign());
        } else {
            sum.setNumber(this->subtract(b.getNumber(),this->getNumber()));
            sum.setSign(b.getSign());
        }
    }
    if(sum.getNumber() == "0") // avoid (-0) problem
        sum.setSign(false);
    return sum;
}
/**
 * @brief Operator -
 * 
 * @param b 
 * @return BigInteger 
 * @todo Revisar que al salir de la funcion b no sea modificada
 */
BigInteger BigInteger::operator - (BigInteger b){
    b.setSign(!b.getSign());
    return (*this) + b;
}
/**
 * @brief Operator *
 * 
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator * (BigInteger b){
    BigInteger product;
    product.setNumber(this->multiply(this->getNumber(),b.getNumber()));
    product.setSign(this->getSign() != b.getSign());
    if(product.getNumber() == "0"){
        product.setSign(false);
    }
    return product;
}
/**
 * @brief Operator / for b as long long
 * 
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator / (BigInteger b){
    long long int den = toInt( b.getNumber() );
    BigInteger div;

    div.setNumber( divide(getNumber(), den).first );
    div.setSign( getSign() != b.getSign() );

    if(div.getNumber() == "0") // avoid (-0) problem
        div.setSign(false);

    return div;
}
/**
 * @brief Operator %
 * 
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator % (BigInteger b){
    long long den = toInt(b.getNumber());
    BigInteger rem;
    long long rem_int = this->divide(this->number_, den).second;
    rem.setNumber(toString(rem_int));
    rem.setSign(this->getSign() != b.getSign());

    if(rem.getNumber() == "0") // avoid (-0) problem
        rem.setSign(false);

    return rem;
}
/**
 * @brief Operator +=
 * 
 * @param b 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator += (BigInteger b) {
    (*this) = (*this) + b;
    return (*this);
}
/**
 * @brief Operator -=
 * 
 * @param b 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator -= (BigInteger b) {
    (*this) = (*this) - b;
    return (*this);
}
/**
 * @brief Operator *=
 * 
 * @param b 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator *= (BigInteger b) {
    (*this) = (*this) * b;
    return (*this);
}
/**
 * @brief Operator /=
 * 
 * @param b 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator /= (BigInteger b) {
    (*this) = (*this) / b;
    return (*this);
}
/**
 * @brief Operator %=
 * 
 * @param b 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator %= (BigInteger b) {
    (*this) = (*this) % b;
    return (*this);
}
/**
 * @brief Operator []
 * 
 * @param n 
 * @return BigInteger& 
 */
BigInteger& BigInteger::operator [] (int n){
    return *(this + (n*sizeof(BigInteger)));
}
/**
 * @brief Unary minus sign
 * 
 * @return BigInteger 
 */
BigInteger BigInteger::operator -(){
    return (*this)*-1;
}
/**
 * @brief Operator stringm, converts BigInterger to string
 * 
 * @return string 
 */
BigInteger::operator string(){ 
    string signed_string = (this->getSign()) ? "-" : "";
    signed_string += this->number_;
    return signed_string;
}
/**
 * @brief Method of comparisson equals
 * 
 * @param b1 
 * @param b2 
 * @return true 
 * @return false 
 */
bool BigInteger::equals(BigInteger b1, BigInteger b2) {
    return (b1.getNumber() == b2.getNumber()) && (b1.getSign() == b2.getSign());
}
/**
 * @brief Method of comparisson less
 * 
 * @param b1 
 * @param b2 
 * @return true 
 * @return false 
 */
bool BigInteger::less(BigInteger b1, BigInteger b2) {
    bool sign1 = b1.getSign();
    bool sign2 = b2.getSign();

    if(sign1 && !sign2){
        return true;
    }else if(!sign1 && sign2){
        return false;
    }else if(!sign1){
        if(b1.getNumber().length() < b2.getNumber().length()){
            return true;
        }
        if(b1.getNumber().length() > b2.getNumber().length()){
            return false;
        }
        return b1.getNumber() < b2.getNumber();
    }else{
        if(b1.getNumber().length() > b2.getNumber().length()){
            return true;
        }
        if(b1.getNumber().length() < b2.getNumber().length()){
            return false;
        }
        return b1.getNumber().compare(b2.getNumber()) > 0;
    }
}
/**
 * @brief Method of comparisson greater
 * 
 * @param n1 
 * @param n2 
 * @return true 
 * @return false 
 */
bool BigInteger::greater(BigInteger b1, BigInteger b2){
    return !this->equals(b1, b2) && !this->less(b1, b2);
}
/**
 * @brief Method add of two strings
 * 
 * @param s1 
 * @param s2 
 * @return string 
 */
string BigInteger::add(string s1, string s2) {
    string sum = (s1.length() > s2.length()) ?  s1 : s2;
    char carry = '0';
    int differenceInLength = std::abs((int) (s1.size() - s2.size()));

    if(s1.size() > s2.size()){
        s2.insert(0, differenceInLength, '0');
    }else{
        s1.insert(0, differenceInLength, '0');
    }
    for(int i=s1.size()-1; i>=0; --i) {
        sum[i] = ((carry-'0')+(s1[i]-'0')+(s2[i]-'0')) + '0';

        if(i != 0) {
            if(sum[i] > '9') {
                sum[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if(sum[0] > '9') {
        sum[0]-= 10;
        sum.insert(0,1,'1');
    }
    return sum;
}
/**
 * @brief Substraction method
 * 
 * @param s1 
 * @param s2 
 * @return string 
 */
string BigInteger::subtract(string s1, string s2) {
    string sub = (s1.length()>s2.length())? s1 : s2;
    int differenceInLength = std::abs( (int)(s1.size() - s2.size()) );

    if(s1.size() > s2.size())
        s2.insert(0, differenceInLength, '0');

    else
        s1.insert(0, differenceInLength, '0');

    for(int i=s1.length()-1; i>=0; --i) {
        if(s1[i] < s2[i]) {
            s1[i] += 10;
            s1[i-1]--;
        }
        sub[i] = ((s1[i]-'0')-(s2[i]-'0')) + '0';
    }

    while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
        sub.erase(0,1);

    return sub;
}
/**
 * @brief Product method
 * 
 * @param n1 
 * @param n2 
 * @return string 
 */
string BigInteger::multiply(string s1, string s2) {
    if(s1.length() > s2.length()){
        s1.swap(s2);
    }
    string res = "0";
    for(int i=s1.length()-1; i>=0; --i) {
        string temp = s2;
        int currentDigit = s1[i]-'0';
        int carry = 0;

        for(int j=temp.length()-1; j>=0; --j) {
            temp[j] = ((temp[j]-'0') * currentDigit) + carry;

            if(temp[j] > 9) {
                carry = (temp[j]/10);
                temp[j] -= (carry*10);
            } else
                carry = 0;

            temp[j] += '0'; // back to string mood
        }

        if(carry > 0)
            temp.insert(0, 1, (carry+'0'));

        temp.append((s1.length()-i-1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

        res = add(res, temp); // O(n)
    }

    while(res[0] == '0' && res.length()!=1) // erase leading zeros
        res.erase(0,1);

    return res;
}

pair<string, long long> BigInteger::divide(string n, long long den) {
    long long rem = 0;
    string result;
    result.resize(MAX);

    for(int indx=0, len = n.length(); indx<len; ++indx) {
        rem = (rem * 10) + (n[indx] - '0');
        result[indx] = rem / den + '0';
        rem %= den;
    }
    result.resize( n.length() );

    while( result[0] == '0' && result.length() != 1)
        result.erase(0,1);

    if(result.length() == 0)
        result = "0";

    return make_pair(result, rem);
}

string BigInteger::toString(long long n) {
    stringstream ss;
    string temp;

    ss << n;
    ss >> temp;

    return temp;
}
/**
 * @brief toInt method
 * 
 * @param s 
 * @return long long 
 */
long long int BigInteger::toInt(string s) {
    long long int sum = 0;
    for(int i=0; i<s.length(); i++){
        sum = (sum*10) + (s[i] - '0');
    }
    return sum;
}

int main(int argc, char *argv[]){
    int a1=-5;
    long int a2=-5;
    BigInteger test0(6);
    BigInteger test1(-5);
    BigInteger test2("-5");
    BigInteger test3(a1);
    BigInteger test4(a2);
    std::cout << test0.isEven() << std::endl;
    std::cout << test1.isEven() << std::endl;
    std::cout << test1.factorial(100) << std::endl;
    std::cout << test1.factorial(100) << std::endl;
    // test4.digits();
    // test1.isEven();
    // test4.isEven();
    return 0;
}