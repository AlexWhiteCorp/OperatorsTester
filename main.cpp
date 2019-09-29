#include <iostream>
#include "headers/Tester.h"

int main(){
    Tester tester("table.html");
    
    tester.testTypeOper<char>('+');
    tester.testTypeOper<char>('-');
    tester.testTypeOper<char>('*');
    tester.testTypeOper<char>('/');

    tester.testTypeOper<int>('+');
    tester.testTypeOper<int>('-');
    tester.testTypeOper<int>('*');
    tester.testTypeOper<int>('/');
    
    tester.testTypeOper<long long>('+');
    tester.testTypeOper<long long>('-');
    tester.testTypeOper<long long>('*');
    tester.testTypeOper<long long>('/');

    tester.testTypeOper<float>('+');
    tester.testTypeOper<float>('-');
    tester.testTypeOper<float>('*');
    tester.testTypeOper<float>('/');

    tester.testTypeOper<double>('+');
    tester.testTypeOper<double>('-');
    tester.testTypeOper<double>('*');
    tester.testTypeOper<double>('/');
    
    tester.save();
    return 0;
}