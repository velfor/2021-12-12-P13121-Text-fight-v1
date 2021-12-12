#include <iostream>
#include <windows.h>
using namespace std;
class Knight {
	//������ �������
private:
	double m_hp;
	double m_damage;
	string m_name;
public:
	//setter, ������� - ������� (�������� ������������)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	// ������ ���� �������� ����� �������� ���� �����������
	Knight(string name, double hp, double damage) {
		m_hp = hp;
		m_damage = damage;
		m_name = name;
	}

	//������
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string getName() { return m_name; }

	//���������� ������
	void increaseDamage() {
		m_damage *= 1.1;
	}
	//������
	void print() {
		cout << "Knight name " << m_name << endl;
		cout << "Knight hp " << m_hp << endl;
		cout << "Knight damage " << m_damage << endl;
	}

};
class Mage {
	//������ �������
private:
	double m_hp;
	double m_damage;
	string m_name;
	//������ ������ (�������, ������������ ��������� �������)
public:
	//setter, ������� - ������� (�������� ������������)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }

	//������
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string getName() { return m_name; }

	//�������
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
	//������� ������
	Knight k1("Valera", 100, 20);
	//�������� � ������ ������
	//k1.setName("Valera");
	//k1.setHp(100);
	//k1.setDamage(20);
	k1.print();

	Mage m1;
	m1.setName("Travis");
	m1.setHp(50);
	m1.setDamage(20);
	m1.print();

	//�������� ������� ����
	while (true) {
		// ��� ������, ������ ���� ����
		cout << "Knight hit mage" << endl;
		m1.setHp(m1.getHp() - k1.getDamage());
		
		//������������� ����
		m1.print();
		//��������� �� ������
		if (m1.getHp() <= 0) {
			cout << "Knight win!" << endl;
			break;
		}
		//������ �������� �����
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
		
		//�������� �� 3000 �� = 3�
		Sleep(3000);

		// ��� ����
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