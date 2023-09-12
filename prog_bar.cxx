#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

void prog_bar(int prog) {
    std::cout << "[" << std::string(prog, '*') 
              << std::string((20 - prog), ' ')
              << "]" << std::flush << "\r";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

int main() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    for (int i=1; i<=20; i++) { 
        SetConsoleTextAttribute(hConsole, i);
        prog_bar(i);
    }
    SetConsoleTextAttribute(hConsole, csbi.wAttributes);
    std::cout << std::endl;
}
