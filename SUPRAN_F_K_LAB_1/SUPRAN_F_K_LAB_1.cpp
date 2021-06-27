#include <iostream>
#include <string>
#include <vector>
#include <functional>
/*
* Первая лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Написать программу, которая заменяет все четные числа 
* в целочисленном статическом массиве на 0. (массив из 10 элементов)
*/
void func1()
{
	system("cls");
	const int SIZE = 10;
	int arr[SIZE];
	std::cout << "Введите 10 элементов массива: ";
	for (size_t i = 0; i < SIZE; i++) // Заполнение массива
		std::cin >> arr[i];
	std::cout << "Замена всех четных чисел на 0:\n";
	for (size_t i = 0; i < SIZE; i++) // Замена всех четных чисел на 0 и вывод массива
	{
		if (!(arr[i] % 2)) 
			arr[i] = 0;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Ввод символа с клавиатуры (с проверкой что это именно символ), 
* ввод строки с клавиатуры (с проверкой что это именно строка).
* Вывод в консоль номера, который символ занимает в строке, если он там есть.
* Если нет — вывод сообщения об отсутствии символа.
* 
* Примечание:
* 1) В проверке символа проверялось является ли введенный символ латинской буквой;
* 2) В проверке строки проверялась длина введенных данных.
*/
void func2()
{
	system("cls");
	char symbol;
	std::string str;
	std::cout << "Введите символ: ";
	std::cin >> symbol;
	std::cin.ignore();
	if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z') // Проверка символа
		std::cout << "Введенный символ является символом.\n";
	else
		std::cout << "Введенный символ не является символом.\n";

	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	if (str.length() > 1) // Проверка строки
		std::cout << "Введенная строка является строкой.\n";
	else
		std::cout << "Введенная строка не является строкой.\n";

	std::cout << "Введите искомый символ: ";
	std::cin >> symbol;
	size_t pos = str.find(symbol); // Поиск символа
	if (pos != std::string::npos)
		std::cout << "Введенный символ находится по номером " << pos + 1 << ".\n";
	else
		std::cout << "Введенный символ не найден.\n";

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Расчет определителя матрицы, матрица размером 3 на 3. 
* Ввод чисел построчно. Числа только целые.
*/
void func3()
{
	system("cls");
	const int SIZE = 3;
	int matrix[SIZE][SIZE];
	std::cout << "Введите элементы матрицы 3x3:\n";
	for (size_t i = 0; i < SIZE; i++) // Ввод матрицы
		for (size_t j = 0; j < SIZE; j++)
			std::cin >> matrix[i][j];
	// Вычисление определителя
	int det = matrix[0][0] * matrix[1][1] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1] 
		- matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0]
		+ matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0];
	std::cout << "Определитель матрицы: " << det << ".\n";

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Замена всех четных чисел в целочисленном статическом массиве на 0.",
		"Проверка символа, строки и поиск по строке.",
		"Расчет определителя матрицы 3x3."
	};
	std::vector<std::function<void()>> fVector = { func1, func2, func3 };
	showMenu(titleVector, fVector);
	return 0;
}