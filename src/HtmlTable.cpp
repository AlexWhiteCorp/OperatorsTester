#include <iostream>
#include "../headers/HtmlTable.h"


HtmlTable::HtmlTable(string outputFileName, string fields[]){
    file.open(outputFileName);
    if (file.is_open()){
        isOpen = true;
        file << "<!doctype html>\n";
        file << "<html>\n";
        file << "<head>\n";
        file << "    <meta charset=\"UTF-8\">";
        file << "    <title>Operators Testing || Lab 1</title>\n";
        file << "    <link rel=\"stylesheet\" type=\"text/css\" href=\"resources/table.css\">\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "    <table>\n";
        file << "        <tr>\n" << "            ";
        for(int i = 0; i <= fields->length(); i++){
            addNewCell(fields[i]);
        }
        file << "\n        </tr>\n";
    }
    else {
        cout << "File Error!";
    }
}

string HtmlTable::percentToDiagram(double percent){
    string diagram = "";
    for(int i = 0; i < percent; i = i + 2){
        diagram += "X";
    }
    return diagram;
}

void HtmlTable::addNewRow(char operType, string varType, double time, double percent){
    percent = int(percent * 100 + 0.5) / 100.0;
    file << "        <tr>\n" << "            ";
    addNewCell(operType);
    addNewCell(varType);
    addNewCell(time);
    addNewCell(percentToDiagram(percent));
    addNewCell(percent, "%");
    file << "\n        </tr>\n";

    cout.width(5); cout << left << operType;
    cout.width(10); cout << left << varType;
    cout.width(15); cout << left << time;
    cout.width(53); cout << left << percentToDiagram(percent);
    cout.width(5); cout << right << percent << endl;
}

void HtmlTable::addNewCell(string value){
    file << "<td>" << value << "</td>";
}

void HtmlTable::addNewCell(char value){
    file << "<td>" << value << "</td>";
}

void HtmlTable::addNewCell(double value){
    file << "<td>" << value << "</td>";
}

void HtmlTable::addNewCell(double dv, string sv){
    file << "<td>" << dv << sv << "</td>";
}

HtmlTable::~HtmlTable(){
    if(isOpen){
        file << "    </table>\n";
        file << "</body>\n";
        file << "</html>\n";
    }
}