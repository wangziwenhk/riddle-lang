module;
#include <iostream>
#include <termcolor/termcolor.hpp>
export module Support.CommandHelp;
namespace Riddle {
}
export namespace Riddle {
    void printCommandHelp() {
        using namespace std;
        cout << termcolor::white << "OVERVIEW: Riddle compiler" << endl << endl;
        cout<< "USAGE: riddle.exe [options] file..." << endl << endl;
        cout << "OPTIONS:" << endl;
        cout << "\t" << "-o" << "\t" << "output" << endl;
        cout << "\t" << "-output" << "\t" << "output" << endl;
    }
}// namespace Riddle