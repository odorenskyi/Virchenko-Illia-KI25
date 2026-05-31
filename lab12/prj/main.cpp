#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <filesystem>
#include <windows.h>
#include "s_calculation.h"

namespace fs = std::filesystem;

bool checkCurrentDirectory() {
    std::string current_path = fs::current_path().string();
    if (current_path.find("Lab12\\prj") == std::string::npos &&
        current_path.find("Lab12/prj") == std::string::npos) {
        return false;
    }
    return true;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    if (!checkCurrentDirectory()) {
        for (int i = 0; i < 100; ++i) {
            std::cout << "\a";
        }

        std::ofstream errorFile("TestResults.txt");
        if (errorFile.is_open()) {
            errorFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            errorFile.close();
        }
        std::cerr << "Помилка: Неправильна директорія проєкту!" << std::endl;
        return 1;
    }

    std::ifstream inputFile("Tests.txt");
    std::ofstream reportFile("TestResults.txt");

    if (!inputFile.is_open() || !reportFile.is_open()) {
        std::cerr << "Помилка відкриття файлів тестів або звітів!" << std::endl;
        return 1;
    }

    reportFile << "=== ПРОТОКОЛ МОДУЛЬНОГО ТЕСТУВАННЯ ===" << std::endl;
    reportFile << "Класу: ClassLab12_Virchenko\n" << std::endl;

    int testCaseID;
    double w, h, expectedArea;
    std::string mat;

    while (inputFile >> testCaseID >> w >> h >> mat >> expectedArea) {
        ClassLab12_Virchenko testObj(w, h, mat);

        double actualArea = testObj.calculateArea();

        bool isSuccess = std::abs(actualArea - expectedArea) < 0.001;

        reportFile << "Test Case ID -> " << testCaseID << " | "
                   << "Action: w=" << w << ", h=" << h << ", mat=" << mat << " | "
                   << "Expected: " << expectedArea << " | "
                   << "Result: " << (isSuccess ? "PASSED" : "FAILED")
                   << " (Actual: " << actualArea << ")" << std::endl;
    }

    std::cout << "Тестування успішно завершено. Результати збережено в TestSuite/TestResults.txt" << std::endl;

    inputFile.close();
    reportFile.close();
    return 0;
}
