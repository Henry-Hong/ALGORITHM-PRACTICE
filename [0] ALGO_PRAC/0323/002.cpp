#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt=0;
int threshold;

typedef vector<int> LargeInteger;

int ctoi(char ch){
    return ch - '0';
}

void roundup_carry(LargeInteger &v)
{

    int carry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] = v[i] % 10;
    }
    if (carry != 0)
        v.push_back(carry);
}

void ladd(LargeInteger &a, LargeInteger &b, LargeInteger &c)
{
    int len = a.size() > b.size() ? a.size() : b.size();
    c.resize(len);
    for (int i = 0; i < len; i++)
    {
        if (i < a.size())
            c[i] += a[i];
        if (i < b.size())
            c[i] += b[i];
    }
    roundup_carry(c);
}

void remove_leading_zero(LargeInteger &v)
{
    while (true)
    {
        if (v.size() != 0 && v.back() == 0)
            v.pop_back();
        else
            return;
    }
}

void roundup_borrow(LargeInteger &v)
{

    int borrow = 0;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] -= borrow;
        borrow = 0;
        if (v[i] < 0)
        {
            v[i] += 10;
            borrow = 1;
        }
    }

    remove_leading_zero(v);
}

void lsub(LargeInteger &a, LargeInteger &b, LargeInteger &c)
{

    int len = a.size() > b.size() ? a.size() : b.size();
    c.resize(len);
    for (int i = 0; i < len; i++)
    {
        if (i < a.size())
            c[i] += a[i];
        if (i < b.size())
            c[i] -= b[i];
    }
    roundup_borrow(c);
}

void lmult(LargeInteger &a, LargeInteger &b, LargeInteger &c)
{   
    c.resize(a.size() + b.size() - 1); // roundup_carry에서 넘치는 digit에 대해 +1 append 해줌.
    for(int i=0; i<c.size(); i++) c[i] = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    roundup_carry(c);
}

void print(LargeInteger &v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
        // if(i % 3 == 0 && i != 0)  cout << ",";
    }
    // cout << "\n";
}

void div_by_exp(LargeInteger& a, int exp, LargeInteger& c){
    for(int i=exp; i<a.size(); i++)
        c.push_back(a[i]);
}

void rem_by_exp(LargeInteger& a, int exp, LargeInteger& c){
    //what if 0123, exp = 5
    if(a.size() == 0){
        c.resize(0);
    }
    else {
        for(int i=0; i < exp && i < a.size(); i++)
            c.push_back(a[i]);
        remove_leading_zero(c);
    }
}

void mul_by_exp(LargeInteger& a, int exp, LargeInteger& c){
    // 012, 3 -> 000012
    if(a.size() == 0){
        c.resize(0);
    } else {
        c.resize(a.size() + exp);
        fill(c.begin(), c.end(), 0);
        copy(a.begin(), a.end(), c.begin() + exp);
    }
}

LargeInteger prod(LargeInteger& a, LargeInteger& b){

    cnt++;
    int m = a.size() > b.size() ? a.size() : b.size();
    int n = m / 2; // 3 -> 1
    // int flag = m % 2;

    LargeInteger x1, x2, y1, y2;
    LargeInteger t1, t2, t3, t4, t5, t6, t7, t8, r;

    if(a.size() == 0 || b.size() == 0){
        r.resize(0);
    }
    else if(m <= threshold){
        lmult(a, b, r);
    }
    else {
        // Let's calc x1 x2, y1, y2
        div_by_exp(a, n, x1);
        rem_by_exp(a, n, x2);
        div_by_exp(b, n, y1);
        rem_by_exp(b, n, y2);

        // (x1 * y1) * 10^2m + ((x1 * y2) + (x2 * y1)) * 10^m + (x2 + y2)
        t1 = prod(x1, y1); mul_by_exp(t1, n * 2, t2);   //t2
        t3 = prod(x1, y2); t4 = prod(x2, y1); ladd(t3, t4, t5); mul_by_exp(t5, n, t6);  //t6
        t7 = prod(x2, y2);  //t7
        ladd(t2, t6, t8);
        ladd(t8, t7, r);
    }
    return r;
}


int main()
{
    LargeInteger A;
    LargeInteger B;
    LargeInteger C;
    string str1, str2;

    cin >> threshold;
    cin >> str1;
    cin >> str2;
    int compZeros = str1.length() - str2.length() > 0 ? str1.length() - str2.length() : str2.length() - str1.length();
    // for(int i=0; i<compZeros && str1.length() < str2.length(); i++) A.push_back(0);
    // for(int i=0; i<compZeros && str2.length() < str1.length(); i++) B.push_back(0);
    for (int i = str1.length() - 1; i >= 0; i--) A.push_back(ctoi(str1[i]));
    for (int i = str2.length() - 1; i >= 0; i--) B.push_back(ctoi(str2[i]));

    C = prod(A, B);
    cout << cnt << "\n";
    print(C);
    return 0;
}