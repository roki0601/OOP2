#include <iostream>

using namespace std;

class Car {
protected:
	int model, count;
public:
	Car()
	{
		cout << "Car()\n";
		model = 1;
		count = 1; 
	}

	Car(int model, int count)
	{
		cout << "Car(int model, int count)\n";
		this->model = model;
		this->count = count;
	}

	Car(const Car& c)
	{
		cout << "Car(const Car& c)\n";
		model = c.model;
		count = c.count;
	}


	void add(int add_count)
	{
		count += add_count;
	}

	void print();

	~Car()
	{
		cout << "Destruction Car\t" << model << "\t" << count << "\n";
	}
};




class UniqueCar: public Car {
protected:
	int wheels;
public:
	UniqueCar() : Car()
	{
		cout << "UniqueCar()\n";
		wheels = 1;
	}

	UniqueCar(int model, int count, int wheels) : Car(model, count)
	{
		cout << "UniqueCar(int model, int count, int wheels)\n";
		this->wheels = wheels;
	}

	UniqueCar(const UniqueCar& uc)
	{
		cout << "UniqueCar(const UniqueCar &uc)\n";
		model = uc.model;
		count = uc.count;
		wheels = uc.wheels;
	}


	void add(int add_count)
	{
		count += add_count;
	}

	void print()
	{
		cout << model << "\t" << count << "\t" << wheels << endl;
	}

	void change_wheels(int c_wheels)
	{
		wheels = c_wheels;
	}

	~UniqueCar()
	{
		cout << "Destruction Unique Car\t" << model << "\t" << count << "\t" << wheels << endl;
	}

};





void Car::print()
{
	cout << model << "\t" << count << endl;
}

class Factory {
protected:
	Car *car1;
	Car *car2;
public:
	Factory()
	{
		cout << "Factory()\n";
		car1 = new Car;
		car2 = new Car;
	}

	Factory(int model1, int count1, int model2, int count2)
	{
		cout << "Factory(int model1, int count1, int model2, int count2)\n";
		car1 = new Car(model1, count1);
		car2 = new Car(model2, count2);
	}

	Factory(const Factory& f)
	{
		cout << "Factory(const Factory& f)\n";
		car1 = new Car(*(f.car1));
		car2 = new Car(*(f.car2));
	}

	~Factory()
	{
		delete car1;
		delete car2;
		cout << "Destruction Factory\n";
	}
};





int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
menu:
	cout << "\n1. Статическое создание\n2. Динамическое создание\n3. Демонстрация методов\n4. Наследование\n5. Композиция \n0.Выход из программы\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			system("cls");
				Car c1;
				Car c2(3, 15);
				Car c3(c2);  //обычное создание (статическое)
				goto menu;
				break;
		}
		case 2:
		{
			system("cls");
			Car *c1 = new Car(); //создание через указатель
			Car *c2= new Car(3, 15); //создается объект класса Car и в переменную заносится ссылка на нее
			Car *c3 = new Car(*c2); 
			
			delete c1;
			delete c2;
			delete c3;
			goto menu;
			break;
		}
		case 3:
		{
			system("cls");
			Car c1(0, 0);
			c1.print();
			c1.add(10); //демонстрация методов
			goto menu;
			break;
		}
		case 4:
		{
			system("cls");
			UniqueCar uc1(1, 1, 4); //демонстрация наследования, вызова конструкторов и деструкторов
			goto menu;
			break;
		}
		case 5:
		{
			system("cls");
			Factory* f1 = new Factory;
			Factory* f2 = new Factory(*f1);
			delete f1;
			delete f2;
			goto menu;
			break;
		}
		case 0:
		{
			break;
		}
	}
}