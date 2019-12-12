#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string factorize(int num);
void displayFactor(string fctr);

int main()
{
    //cout<<factorize(150)<<endl;
    cout<<factorize(150)<<endl;
    displayFactor(factorize(150));
    
    cout<<factorize(1650)<<endl;
    displayFactor(factorize(1650));
    return 0;
}

string factorize(int num)
{
    string result = "";
    int divisor = 2;
    while(num>1)
    {
        if(num % divisor==0)
        {
            num = num/divisor;
            result = result + to_string(divisor) + " " ;
        }
        else
        {
            divisor++;
        }
    }
    return result;
}
void displayFactor(string fctr)
{
    string result = "";
    stringstream num(fctr);
    vector<int> factors;
    int n;
    int dupes = 1;
    int current = 0;
    
    while(num>>n)
    {
        factors.push_back(n);
    }
    
    for(int i = 0 ; i<factors.size() ; i++)
    {
        current = factors[i];
        if(factors[i] != factors[i+1])
        {
            result += to_string(factors[i]) + "*";
        }
        while(factors[i] == factors[i+1]) 
        {
            dupes++;
            i++;
            if(factors[i] != factors[i+1])
            {
                result += to_string(current) + "^" + to_string(dupes) + "*";
            }
        }
    }
    result[result.length()-1]=' ';
    cout<<result<<endl;
}








