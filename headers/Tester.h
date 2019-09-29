#pragma once
#include <string>
#include <chrono>
#include <string>
#include <typeinfo>
#include "HtmlTable.h"

using namespace std;

class Tester {
public:
    Tester(string outputFile);
    template <typename T> void testTypeOper(char oper);
    void save();

private:
    HtmlTable* table;
    const int ITERS = 10000000;
    std::chrono::time_point<std::chrono::system_clock> timerStart = chrono::system_clock::now(), timerEnd = chrono::system_clock::now();
    chrono::duration<double> elapsed;
    int testsCount = 0;
    double rate = 1;

    double emptyIntLoopTime = 0;
    double emptyLongLoopTime = 0;
    double emptyFloatLoopTime = 0;
    double emptyDoubleLoopTime = 0;
    double emptyCharLoopTime = 0;

    double results[100];
    char opers[100];
    string varTypes[100];

    template <typename T> double calculateEmptyLoopTime();
    template <typename T> void saveRes(double time, char oper);

    double getEmptyLoopTime(char var);
    double getEmptyLoopTime(int var);
    double getEmptyLoopTime(long long var);
    double getEmptyLoopTime(float var);
    double getEmptyLoopTime(double var);
};

template <class T>
void Tester::testTypeOper(char oper){
    switch(oper){
        case '+':{
            int i;
            T a = 0, b, c, d = 1;
            timerStart = chrono::system_clock::now();
            for (i = 0; i < ITERS; i++){
                a = b + d;
                b = c + d;
                c = a + d;
            }
            timerEnd = chrono::system_clock::now();
            elapsed = timerEnd - timerStart;
            saveRes<T>(elapsed.count(), oper);
            break;
        }
        case '-':{
            int i;
            T a = 0, b, c, d = 1;
            timerStart = chrono::system_clock::now();
            for (i = 0; i < ITERS; i++){
                a = b - d;
                b = c - d;
                c = a - d;
            }
            timerEnd = chrono::system_clock::now();
            elapsed = timerEnd - timerStart;
            saveRes<T>(elapsed.count(), oper);
            break;
        }
        case '*':{
            int i;
            T a = 0, b, c, d = 1;
            timerStart = chrono::system_clock::now();
            for (i = 0; i < ITERS; i++){
                a = b * d;
                b = c * d;
                c = a * d;
            }
            timerEnd = chrono::system_clock::now();
            elapsed = timerEnd - timerStart;
            saveRes<T>(elapsed.count(), oper);
            break;
        }
        case '/':{
            int i;
            T a = 0, b, c, d = 1;
            timerStart = chrono::system_clock::now();
            for (i = 0; i < ITERS; i++){
                a = b / d;
                b = c / d;
                c = a / d;
            }
            timerEnd = chrono::system_clock::now();
            elapsed = timerEnd - timerStart;
            saveRes<T>(elapsed.count(), oper);
            break;
        }
    }
}

template <class T>
double Tester::calculateEmptyLoopTime(){
    int i;
    T a = 0, b = 2, c = 5, d = 1;
    timerStart = chrono::system_clock::now();
    for (i = 0; i < ITERS; i++){
        a = b;
        d = c;
        c = a;
    }
    timerEnd = chrono::system_clock::now();
    elapsed = timerEnd - timerStart;
    return elapsed.count();
}

template <class T>
void Tester::saveRes(double time, char oper){
    T a;
    results[testsCount] = 1 / (time - getEmptyLoopTime(a)) * 3 * ITERS;
    opers[testsCount] = oper;
    varTypes[testsCount] = typeid(T).name();
    testsCount++;
}