#pragma once
#include <string>
#include <fstream>

using namespace std;

class HtmlTable{
public:
    HtmlTable(string outputFileName, string fields[]);
    void addNewRow(char operType, string varType, double time, double percent);
    ~HtmlTable();

private:
    ofstream file;
    bool isOpen = false;

    void addNewCell(string value);
    void addNewCell(char value);
    void addNewCell(double value);
    void addNewCell(double dv, string sv);
    string percentToDiagram(double percent);
};
