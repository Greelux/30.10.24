#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");

    ofstream OpenFile("classwork.txt");
    if (!OpenFile) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 200; ++i) {
        int randomNum = rand() % 1000 + 1;
        OpenFile << randomNum << endl; 
    }

    OpenFile.close();
    cout << "Файл \"classwork.txt\" створений та заповнений випадковими числами." << endl;

    int userNumber;
    cout << "Введіть число для пошуку: ";
    cin >> userNumber;

    ifstream inFile("classwork.txt");
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return 1;
    }

    int currentNumber;
    int count = 0;

    while (inFile >> currentNumber) {
        if (currentNumber == userNumber) {
            ++count;
        }
    }

    inFile.close();

    if (count > 0) {
        cout << "Число знайдено " << count << " разів." << endl;
    }
    else {
        cout << "Число не знайдено." << endl;
    }

    return 0;
}
