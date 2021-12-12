#include <iostream>
#include <windows.h>
using namespace std;
class Knight {
	//данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
public:
	//setter, функции - сеттеры (замен€ют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	// вместо всех сеттеров можно написать один конструктор
	Knight(string name, double hp, double damage) {
		m_hp = hp;
		m_damage = damage;
		m_name = name;
	}

	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string getName() { return m_name; }

	//увеличение дамага
	void increaseDamage() {
		m_damage *= 1.1;
	}
	//печать
	void print() {
		cout << "Knight name " << m_name << endl;
		cout << "Knight hp " << m_hp << endl;
		cout << "Knight damage " << m_damage << endl;
	}

};
class Mage {
	//данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
	//методы класса (функции, определ€ющие поведение объекта)
public:
	//setter, функции - сеттеры (замен€ют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }

	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string getName() { return m_name; }

	//лечение
	void increaseHp(double addHp) {
		m_hp += addHp;
	}
	void print() {
		cout << "Mage name " << m_name << endl;
		cout << "Mage hp " << m_hp << endl;
		cout << "Mage damage " << m_damage << endl;
	}
};

int main() {
	//создали рыцар€
	Knight k1("Valera", 100, 20);
	//записали в рыцар€ данные
	//k1.setName("Valera");
	//k1.setHp(100);
	//k1.setDamage(20);
	k1.print();

	Mage m1;
	m1.setName("Travis");
	m1.setHp(50);
	m1.setDamage(20);
	m1.print();

	//основной игровой цикл
	while (true) {
		// ход рыцар€, рыцарь бьет мага
		cout << "Knight hit mage" << endl;
		m1.setHp(m1.getHp() - k1.getDamage());
		
		//распечатываем мага
		m1.print();
		//провер€ем на смерть
		if (m1.getHp() <= 0) {
			cout << "Knight win!" << endl;
			break;
		}
		//рыцарь увеличил дамаг
		cout << "What is ur choice ? Press 1 to increase damage by 10%";
		int choice;
		cin >> choice;
		switch (choice) {
			case 1:
				k1.increaseDamage();
				break;
			//case 2: 
			//case 3:
		}
		
		//задержка на 3000 мс = 3с
		Sleep(3000);

		// ход мага
		cout << "Mage hit knight" << endl;
		k1.setHp(k1.getHp() - m1.getDamage());
		//
		k1.print();
		if (k1.getHp() <= 0) {
			cout << "Mage win!" << endl;
			break;
		}
		m1.increaseHp(50);
		Sleep(3000);
	}
	return 0;
}