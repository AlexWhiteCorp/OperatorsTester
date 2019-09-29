#include <iostream>
#include <string>
#include "../headers/Tester.h"
#include "../headers/HtmlTable.h"

using namespace std;

Tester::Tester(string outputFile){
    string fields[]{"oper", "type", "time", "diagram", "percent", "mln/sec"};
    table = new HtmlTable(outputFile, fields);

    emptyCharLoopTime = calculateEmptyLoopTime<char>();
    emptyIntLoopTime = calculateEmptyLoopTime<int>();
    emptyLongLoopTime = calculateEmptyLoopTime<long>();
    emptyFloatLoopTime = calculateEmptyLoopTime<float>();
    emptyDoubleLoopTime = calculateEmptyLoopTime<double>();
}

string getTypeNameByID(string id){
    switch(id[0]){
        case 'i':
            return "int";
        case 'x':
            return "long";
        case 'f':
            return "float";
        case 'd':
            return "double";
        case 'c':
            return "char";
    }
}

void Tester::save() {
    if(testsCount != 0){
        rate = results[0];
        for(int i = 1; i < testsCount; i++){
            if(results[i] > rate)rate = results[i];
        }

        for(int i = 0; i < testsCount; i++){
            table -> addNewRow(opers[i], getTypeNameByID(varTypes[i]), results[i], results[i] / rate * 100);
        }

        delete table;
    }
}

double Tester::getEmptyLoopTime(char var){
    return emptyCharLoopTime;
}

double Tester::getEmptyLoopTime(int var){
    return emptyIntLoopTime;
}

double Tester::getEmptyLoopTime(long long var){
    return emptyLongLoopTime;
}

double Tester::getEmptyLoopTime(float var){
    return emptyFloatLoopTime;
}

double Tester::getEmptyLoopTime(double var){
    return emptyDoubleLoopTime;
}
