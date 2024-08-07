#include <iostream>
#include <map>
#include <list>
#include <string>
#include <vector>
#include <algorithm> // для std::max_element

// Класс для управления списком сотрудников
class EmployeeList {
public:
    // Конструктор добавления компании в список
    void addCompany(const std::string& companyName, const std::map<std::string, double>& employees) {
        companies.emplace_back(companyName, employees); // добавляет новую компанию и её сотрудников в список.
    }

    // Метод вывода всех сотрудников всех компаний
    void printAllEmployees() const {
        for (const auto& company : companies) {
            const auto& companyName = company.first;
            const auto& employees = company.second;

            std::cout << "Компания: " << companyName << std::endl;
            for (const auto& employee : employees) {
                std::cout << "  Фамилия: " << employee.first << ", Зарплата: " << employee.second << std::endl;
            }
        }
    }

    // Метод получения вектора самых высокооплачиваемых сотрудников
    std::vector<std::pair<std::string, double>> getTopPaidEmployees() const { // находит и возвращает список самых высокооплачиваемых сотрудников из каждой компании.
        std::vector<std::pair<std::string, double>> topPaidEmployees;

        for (const auto& company : companies) {
            const auto& employees = company.second;

            // Находим сотрудника с самой высокой зарплатой
            auto maxEmployee = std::max_element(employees.begin(), employees.end(),
                [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
                    return a.second < b.second;
                });

            if (maxEmployee != employees.end()) {
                topPaidEmployees.emplace_back(maxEmployee->first, maxEmployee->second);
            }
        }

        return topPaidEmployees;
    }

private:
    // Список компаний, где каждая компания представлена парой (название компании, карта сотрудников)
    std::list<std::pair<std::string, std::map<std::string, double>>> companies;
};

int main() {
    setlocale(LC_ALL, "ru");
    // Создаем список сотрудников
    EmployeeList employeeList;

    // Добавляем компании с сотрудниками и их зарплатами
    employeeList.addCompany("Компания А", { {"Иванов", 50000}, {"Петров", 60000}, {"Сидоров", 55000} });
    employeeList.addCompany("Компания Б", { {"Кузнецов", 70000}, {"Смирнов", 65000}, {"Попов", 72000} });
    employeeList.addCompany("Компания В", { {"Соколов", 80000}, {"Михайлов", 75000}, {"Васильев", 78000} });

    // Вывод всех сотрудников
    std::cout << "Список всех сотрудников:" << std::endl;
    employeeList.printAllEmployees();

    // Получение самых высокооплачиваемых сотрудников из каждой компании
    auto topPaidEmployees = employeeList.getTopPaidEmployees();

    // Вывод самых высокооплачиваемых сотрудников
    std::cout << "\nСамые высокооплачиваемые сотрудники:" << std::endl;
    for (const auto& employee : topPaidEmployees) {
        std::cout << "Фамилия: " << employee.first << ", Зарплата: " << employee.second << std::endl;
    }

    return 0;
}
// Задание
// Создайте объект класса list, полями которого являются
// объекты класса map.Каждый объект – это описание
// сотрудников компании.Ключи – фамилии сотрудников, а
// значения – из зарплаты.
// Создайте следующие функции для работы со списком :
// ● функция вывода всех сотрудников всех компаний;
// ● функция, возвращающая вектор самых
// высокооплачиваемых сотрудников из всех компаний(по
// одному сотруднику на компанию).
