// MSVC_ConsoleApplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <array>
#include <chrono>
#include <mutex>
#include <assert.h>

using namespace std;

// Component 
class Unit
{
public:
	virtual int getStrength() = 0;
	virtual void addUnit(Unit* p) {
		assert(false);
	}
	virtual ~Unit() {}
};

// Primitives
class Archer : public Unit
{
public:
	virtual int getStrength() {
		return 1;
	}
};

class Infantryman : public Unit
{
public:
	virtual int getStrength() {
		return 2;
	}
};

class Horseman : public Unit
{
public:
	virtual int getStrength() {
		return 3;
	}
};


// Composite
class CompositeUnit : public Unit
{
public:
	int getStrength() {
		int total = 0;
		for (int i = 0; i < c.size(); ++i)
			total += c[i]->getStrength();
		return total;
	}
	void addUnit(Unit* p) {
		c.push_back(p);
	}
	~CompositeUnit() {
		for (int i = 0; i < c.size(); ++i)
			delete c[i];
	}
private:
	std::vector<Unit*> c;
};


// Вспомогательная функция для создания легиона
CompositeUnit* createLegion()
{
	// Римский легион содержит:
	CompositeUnit* legion = new CompositeUnit;
	// 3000 тяжелых пехотинцев
	for (int i = 0; i < 3000; ++i)
		legion->addUnit(new Infantryman);
	// 1200 легких пехотинцев
	for (int i = 0; i < 1200; ++i)
		legion->addUnit(new Archer);
	// 300 всадников
	for (int i = 0; i < 300; ++i)
		legion->addUnit(new Horseman);

	return legion;
}

int main()
{
	// Римская армия состоит из 4-х легионов
	CompositeUnit* army = new CompositeUnit;
	for (int i = 0; i < 4; ++i)
		army->addUnit(createLegion());

	cout << "Roman army damaging strength is "
		<< army->getStrength() << endl;
	// …
	delete army;
	return 0;
}

/*
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	struct stat fi;
	stat("trains.txt", &fi);
	printf("file size: %d", fi.st_size);

	void *buffer = malloc(fi.st_size);// буфер промежуточного хранения считываемого из файла текста

	ifstream fin("trains.txt"); // открыли файл для чтения
	fin.read((char *)buffer, fi.st_size);
	cout << *(char *)buffer;
	
	fin.close(); // закрываем файл
	delete buffer;

	return 0;
}

*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
