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
	system("title 学生成绩管理系统");
	system("color 71");
	system("mode con cols=60 lines=40");
}

double sume = 0, summ = 0, sumo = 0, sum = 0;

class score {
public:
	double e;
	double m;
	double o;
	score(double a, double b, double c) {
		e = a;
		m = b;
		o = c;
		sume = sume + a;
		summ = summ + b;
		sumo = sumo + c;
		sum = sum + a + b + c;

	}
	score() {};
	~score() {};
	score(const score& s){}
	static int num;
	static void fun() {
		num++;
	}
};

int score::num = 0;

class student {
public:
	string xuehao,name;
	student(string xuehao,string name,double e,double m,double o): xuehao(xuehao), name(name), s(e,m,o){}
	student() {};
	~student() {};
	student(const student& stu) {
		xuehao = stu.xuehao;
		name = stu.name;

	}
	score s;

};

student* stu[500];

void add() {
	string xuehao, name;
	double a, b, c;
	static int d = 0;
	cout << "请输入学生学号：" << endl;
	cin >> xuehao;
	cout << "请输入学生姓名：" << endl;
	cin >> name;
	cout << "请输入学生的英语成绩" << endl;
	cin >> a;
	cout << "请输入学生的数学成绩" << endl;
	cin >> b;
	cout << "请输入学生的计算机成绩" << endl;
	cin >> c;
	stu[d] = new student(xuehao, name, a, b, c);
	score::fun();
	d++;
	cout << endl;
	cout << "已成功添加！";
	cout << endl;
	system("pause");
	system("cls");
}

void change(string name) {
	int a = 0;
	for (a; a < score::num; a++) {
		if (stu[a]->name == name) {
			cout << "请输入修改后的英语成绩："<<endl;
			cin >> stu[a]->s.e;
			cout << "请输入修改后的数学成绩：" << endl;
			cin >> stu[a]->s.m;
			cout << "请输入修改后的计算机成绩：" << endl;
			cin >> stu[a]->s.o;
			cout << endl;
			cout << "已成功修改！";
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "查无此人" << endl;
			system("pause");
			system("cls");
		}
	}
}

void search(string name) {
	int a = 0;
	for (a; a <score::num; a++) {
		if (stu[a]->name == name) {
			cout << "学生姓名：" << endl << stu[a]->name << endl;
			cout << "学号：" << endl << stu[a]->xuehao << endl;
			cout << "英语成绩：" << endl << stu[a]->s.e << endl;
			cout << "数学成绩：" << endl << stu[a]->s.m << endl;
			cout << "计算机成绩：" << endl << stu[a]->s.o << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout<< "查无此人" << endl;
			system("pause");
			system("cls");
		}
	}
}

void avge() {
	double a;
	a = sume / score::num;
	cout << "英语的平均成绩为：" << a << endl;
	system("pause");
	system("cls");
}

void avgm() {
	double a;
	a = summ / score::num;
	cout << "数学的平均成绩为:" << a << endl;
	system("pause");
	system("cls");
}

void avgo() {
	double a;
	a = sumo/score::num;
	cout << "计算机的平均成绩为：" << a<< endl;
	system("pause");
	system("cls");
}

void avg() {
	double a;
	a = sum/ score::num;
	cout << "总成绩的平均成绩为：" << a << endl;
	system("pause");
	system("cls");
}

void menu() { 
	cout <<" ————学生成绩管理系统———— " <<endl;
	cout << " 1.添加学生信息" << endl;
	cout << " 2.修改学生信息（按姓名修改）" << endl;
	cout << " 3.查找学生信息" << endl;
	cout << " 4.统计学生英语成绩平均值" << endl;
	cout << " 5.统计学生数学成绩平均值" << endl;
	cout << " 6.统计学生计算机成绩平均值" << endl;
	cout << " 7.统计学生总成绩平均值" << endl;
	cout << " ————请选择您要进行的操作：" << endl;



}

int main() {
	gotoxy(1, 5);
	meihua();
	string name;
	int b;
	menu();
	while (~scanf("%d", &b)) {
		cout << endl;
		cout << endl;
		
		switch (b) {
		case 1:
			
			add();
			menu();
			break;
		case 2:
			
			cout << "请输入要更改的学生姓名：" << endl;
			cin >> name;
			change(name);
			menu();
			break;
		case 3:
			cout << "请输入要查询的学生姓名："<< endl;
			cin >> name;
			search(name);
			menu();
			break;
		case 4:
			avge();
			menu();
			break;
		case 5:
			avgm();
			menu();
			break;
		case 6:
			avgo();
			menu();
			break;
		case 7:
			avg();
			menu();
			break;
		default:
			cout << "请您输入正确的序号："<<endl;
			menu();
			break;
		}
		
	}
	return 0;

}


