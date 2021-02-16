#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void meihua() {
	system("title 智能快递系统");
	system("color 71");
	system("mode con cols=100 lines=40");
}

class package {
public:
	virtual double calculateCost() = 0;
	string sent, get, a1, a2;
	double weight, kilometre;
};

class pup :
	public package {
public:
	double p;
	virtual double calculateCost() {
		if (weight <= 1) {
			return 8;
		}
		else {
			p = 8 + (weight - 1) * 2;
			return p;

		}
	}

};

class jip :
	public package {
public:
	double p;
	virtual double calculateCost() {
		p = 10 + weight * 10 + kilometre * 0.02;
		return p;
	}
};

void pu() {
	package* a = new pup;
	cout << "————您选择的是普通快递，请根据以下提示输入您的个人信息————"<<endl;
	cout << "请输入寄件人姓名：" << endl;
	cin >> a->sent;
	cout << "请输入收件人姓名：" << endl;
	cin >> a->get;
	cout << "请输入寄件人地址：" << endl;
	cin >> a->a1;
	cout << "请输入收件人地址：" << endl;
	cin >> a->a2;
	cout << "请输入快递重量（单位：千克）：" << endl;
	cin >> a->weight;
	cout << "————————————————————--——" << endl;
	cout << "————————————————————--——" << endl;
	cout << "您所需要支付的金额为： "<<a->calculateCost()  <<"元" << endl;
	system("pause");
	system("cls");
}

void ji() {
	package* b = new jip;
	cout << "————您选择的是加急快递，请根据以下提示输入您的个人信息————" << endl;
	cout << "请输入寄件人姓名：" << endl;
	cin >> b->sent;
	cout << "请输入收件人姓名：" << endl;
	cin >> b->get;
	cout << "请输入寄件人地址：" << endl;
	cin >> b->a1;
	cout << "请输入收件人地址：" << endl;
	cin >> b->a2;
	cout << "请输入快递重量（单位：千克）：" << endl;
	cin >> b->weight;
	cout << "请输入加急公里数（单位：公里）：" << endl;
	cin >> b->kilometre;
	cout << "————————————————————--——" << endl;
	cout << "————————————————————--——" << endl;
	cout << "您所需要支付的金额为： " << b->calculateCost() << "元" << endl;
	system("pause");
	system("cls");
}



void menu() {
	cout << "————智能快递系统————" << endl;
	cout << "尊敬的客人：您好！" << endl;
	cout << "  本店快递有两种类型： 1.普通快递   2.加急快递" << endl;
	cout << "——请输入 数字 选择您需要邮寄的的方式：" << endl << endl;

}

void main() {
	meihua();
	int a;
	menu();
	while (~scanf("%d", &a)) {
		switch (a) {
		case 1:
			pu();
			menu();
			break;
		case 2:
			ji();
			menu();
			break;
		default:
			cout << endl;
			cout << "请您输入正确的数字(  1  或   2  ):" << endl<<endl;
			

	}
	}
	

}
