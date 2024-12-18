#include<iostream>
#include"Time.hpp"
#include<exception>

int main() {
	setlocale(LC_ALL, "RU");
	try {
		std::cout << "Создадим объект t1 класса Time по умолчанию:\n";
		Time t1;
		std::cout << "t1 - " << t1;
		std::cout << "Используем функцию t1.calculateTime(10, 130, 100):\n";
		t1.calculateTime(10, 130, 100);
		std::cout << "t1 - " << t1;

		std::cout << "\nСоздадим объект t2(1060) c заданным значением секунд:\n";
		Time t2(1060);
		std::cout << "t2 - " << t2;
		std::cout << "\nСоздадим объект t3(1, 10, 15) c заданными значениями (ЧЧ:ММ:СС):\n";
		Time t3(1,10,15);
		std::cout << "t3 - " << t3;
		std::cout << "\nСоздадим объект t4(30, 10, 15) c заданными значениями и поймаем исключение:\n";
		Time t4(30, 10, 15);
		std::cout << t4;
	}
	catch (std::invalid_argument& log) {
		std::cerr << "Error: " << log.what() << std::endl;
	}

	return 0;
}