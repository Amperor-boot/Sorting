#include "Header.h"

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RU");
	SetConsoleCP(1251);		//устанавливаем кодовую страницу в поток ввода
	SetConsoleOutputCP(1251);	//устанавливаем кодовую страницу в поток вывода

	if (!task_1())
		cout << "Задание №1 выполнено успешно" << endl;
	if (!task_2())
		cout << "Задание №2 выполнено успешно" << endl;
	if (!task_3())
		cout << "Задание №3 выполнено успешно" << endl;
	return 0;
}