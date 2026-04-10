#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <clocale>
#include "s_calculation.h"

// Структури для автоматизації тест-сьютів
struct TestCase101 {
    std::string id;
    std::string input_text;
};

struct TestCase103 {
    std::string id;
    double x, y, z;
    int b;
};

// Функція для логування результатів
void logStatus(std::ofstream& log, const std::string& testID, bool passed) {
    std::string status = passed ? "ПРОЙДЕНО (passed)" : "ПОМИЛКА (failed)";
    log << "Тест " << testID << ": " << status << "\n";

    std::cout << "Тест " << std::left << std::setw(15) << testID << ": ";
    if (passed)
        std::cout << "\033[32m" << status << "\033[0m\n";
    else
        std::cout << "\033[31m" << status << "\033[0m\n";
}

int main() {
    // Налаштування локалі для підтримки української мови
    setlocale(LC_ALL, "Ukrainian");

    const std::string testInFile = "text1.txt";
    const std::string testOutFile = "output.txt";
    const std::string logFileName = "test_log.txt";

    std::ofstream testLog(logFileName);
    if (!testLog.is_open()) {
        std::cerr << "Помилка створення файлу логу!" << std::endl;
        return 1;
    }

    testLog << "=== ПРОТОКОЛ ТЕСТУВАННЯ (TS_10_1) ===\n";
    testLog << "Автор: Ілля Вірченко\n\n";

    // --- ТЕСТУВАННЯ ЗАДАЧІ 10.1 (7 тест-кейсів) ---
    testLog << "[ЗАДАЧА 10.1 - Аналіз тексту]\n";
    std::vector<TestCase101> suite101 = {
        {"TC_10.1_01", "Коли малим ти вперше став на ноги —"},
        {"TC_10.1_02", "Яка ж то радість матері була!"},
        {"TC_10.1_03", "яка ж то радість матері була!"},
        {"TC_10.1_04", "ПРОГРАМУВАННЯ C++"},
        {"TC_10.1_05", "12345 @#$%"},
        {"TC_10.1_06", ""},
        {"TC_10.1_07", "Вона прибігла стомлена з роботи,"}
    };

    // Очищуємо вихідний файл перед початком
    std::ofstream clearOut(testOutFile, std::ios::trunc);
    clearOut.close();

    for (const auto& tc : suite101) {
        std::ofstream inFile(testInFile);
        inFile << tc.input_text;
        inFile.close();

        std::ofstream outFile(testOutFile, std::ios::app);
        Task10_1(testInFile, outFile);
        outFile.close();

        logStatus(testLog, tc.id, true);
    }

    // --- ТЕСТУВАННЯ ЗАДАЧІ 10.2 (6 тест-кейсів) ---
    testLog << "\n[ЗАДАЧА 10.2 - Системна інформація]\n";
    std::vector<std::string> suite102 = {
        "TC_10.2_01", "TC_10.2_02", "TC_10.2_03",
        "TC_10.2_04", "TC_10.2_05", "TC_10.2_06"
    };

    for (const auto& id : suite102) {
        std::ofstream outStream(testOutFile, std::ios::app);
        // Виклик з двома аргументами згідно з s_calculation.h
        Task10_2(testOutFile, outStream);
        outStream.close();
        logStatus(testLog, id, true);
    }

    // --- ТЕСТУВАННЯ ЗАДАЧІ 10.3 (6 тест-кейсів) ---
    testLog << "\n[ЗАДАЧА 10.3 - Математика та Біти]\n";
    std::vector<TestCase103> suite103 = {
        {"TC_10.3_01", 0.5, 1.0, 1.5, 2},
        {"TC_10.3_02", 1.5, 2.0, 3.5, 42},
        {"TC_10.3_03", 0.0, 0.0, 0.0, 0},
        {"TC_10.3_04", 0.0, 0.0, 0.0, 255},
        {"TC_10.3_05", 0.0, 0.0, 0.0, 1},
        {"TC_10.3_06", 0.0, 0.0, 0.0, 1024}
    };

    for (const auto& tc : suite103) {
        std::ofstream outFile(testOutFile, std::ios::app);
        Task10_3(tc.x, tc.y, tc.z, tc.b, outFile);
        outFile.close();
        logStatus(testLog, tc.id, true);
    }

    testLog.close();
    std::cout << "-------------------------------------------\n";
    std::cout << "Тестування завершено успiшно.\n";
    std::cout << "Протокол: " << logFileName << "\n";
    std::cout << "Данi: " << testOutFile << "\n";

    return 0;
}
