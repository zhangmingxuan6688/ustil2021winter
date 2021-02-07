#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
void beautify() {
	system("titile 学生成绩管理系统");
	system("color c1");
}

void gotoxy(int x, int y) //定位到第y行的第x列
{
	int xx = 0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}

double sum_eng = 0, sum_math = 0, sum_com = 0, sum_all = 0;



class Score {
public:
	Score() {};

	double english;

	double math;

	double computer;

	void avg_eng(), avg_math(), avg_com(), avg_all();

	Score(const Score& score) {  //拷贝构造函数
	}
	~Score() {};//析构函数

	Score(double a, double b, double c) {//各科的总得分以及全部科目的总得分
		english = a;
		math = b;
		computer = c;
		sum_eng += a;
		sum_math += b;
		sum_com += c;
		sum_all = a + b + c + sum_all;
	}
	
	static void fun() {
		num++;
	}
	static int num;
};

int Score::num = 0;   //注意写变量类型

class Student {
public:
	string ID;

	string name;

	Student() {};

	Student(string ID, string name, double english, double math, double computer) :ID(ID), name(name), score(english, math, computer) {
	}   //初始化参数列表

	~Student() {};//析构函数

	Student(const Student& student) {//拷贝构造函数
		ID = student.ID;
		name = student.name;
	}

	Score score;
};

Student* student[100];

void Add() {
	string ID, name;
	double a, b, c;
	static int q = 0;
	cout << "添加学生学号：" << endl;
	cin >> ID;
	cout << "添加学生姓名：" << endl;
	cin >> name;
	cout << "请输入学生的英语成绩：" << endl;
	cin >> a;
	cout << "请输入学生的数学成绩：" << endl;
	cin >> b;
	cout << "请输入学生的计算机成绩：" << endl;
	cin >> c;
	student[q] = new Student(ID, name, a, b, c);
	Score::fun();
	q++;
}

void Search(string name) {
	int i = 0;
	for (i; i < Score::num; i++)
	{
		if (student[i]->name == name)
		{

			cout << "姓名:" << student[i]->name << endl;
			cout << "学号:" << student[i]->ID << endl;
			cout << "英语成绩:" << student[i]->score.english << endl;
			cout << "数学成绩:" << student[i]->score.math << endl;
			cout << "计算机成绩:" << student[i]->score.computer << endl;
			system("pause");
			return;
		}
	}
	cout << "查无此人!" << endl;
	system("pause");
}

void change(string name) {
	int q = 0;
	for (q; q < Score::num; q++) {
		if (student[q]->name == name) {
			cout << "请输入更改后的英语成绩：" << endl;
			cin >> student[q]->score.english;
			cout << "请输入更改后的数学成绩：" << endl;
			cin >> student[q]->score.math;
			cout << "请输入更改后的计算机成绩：" << endl;
			cin >> student[q]->score.computer;
			system("pause");
			return;
		}
	}
	cout << "查无此人!" << endl;
	system("pause");
}

void avg_eng() {
	double q;
	q = sum_eng / Score::num;
	cout << "英语的平均成绩为："<<q << endl;
	system("pause");
}

void avg_math() {
	double q;
	q = sum_math / Score::num;
	cout <<"数学的平均成绩为" <<q << endl;
	system("pause");
}


void avg_com() {
	double q;
	q = sum_com / Score::num;
	cout <<"计算机的平均成绩为："<< q << endl;
	system("pause");
}


void avg_all() {
	double q;
	q = sum_all / Score::num;
	cout <<"总成绩的平均成绩为："<< q << endl;
	system("pause");
}

void Menu() {
	cout << "*****************学生信息统计*****************" << endl;
	cout << "**1.增加学生信息" << endl;
	cout << "**2.查找学生信息" << endl;
	cout << "**3.修改学生信息" << endl;
	cout << "**4.统计学生英语成绩平均值" << endl;
	cout << "**5.统计学生数学成绩平均值" << endl;
	cout << "**6.统计学生计算机成绩平均值" << endl;
	cout << "**7.统计学生总成绩平均值" << endl;
	cout << "**8.退出系统" << endl;
	cout << "→→→→→→请选择您要进行的操作：←←←←←←" << endl;
}

int main() {
	string name;
	int p;
	beautify();
	while (1) {
		system("cls");
		Menu();
		cin >> p;
		switch (p) {
		case 1:
			Add();
			break;
		case 2:
			cout << "请输入要查询人的名字：" << endl;
			cin >> name;
			Search(name);
			break;
		case 3:
			cout << "请输入要更改人信息的名字：" << endl;
			cin >> name;
			change(name);
			break;
		case 4:
			avg_eng();
			break;
		case 5:
			avg_math();
			break;
		case 6:
			avg_com();
			break;
		case 7:
			avg_all();
			break;
		case 8:
			exit(0);
			break;
		default:
			cout << "请输入正确的选项！" << endl;
			break;
		}

	}return 0;
}
