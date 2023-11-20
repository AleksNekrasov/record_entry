// record_entry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::string path = "statement.txt";
    std::ofstream file;
    file.open(path, std::ofstream::app);

    if (!file.is_open())
    {
        std::cerr  << "error in file path!";
            return 1;
    }
    std::cout << "File is open. \n\n";
    std::string line_for_statement;                                                      // строка для ввода в ведомость
    std::cout << " Enter the person’s details (first name, last name, amount, date): ";
    std::getline(std::cin, line_for_statement);
    std::stringstream examination(line_for_statement);

    std::string first_name;
    std::string last_name;
    double amount;
    std::string date;

    examination >> first_name >> last_name >> amount >> date;
    int number = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    
    if (number > 0 && number < 32 && month > 0 && month < 13)
    {
        file.width(4);
        file << line_for_statement << std::endl;
    }
    else
    {
        std::cerr << "date entered incorrectly!!";
    }
    
    file.close();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
