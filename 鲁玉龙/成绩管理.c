#include<iostream>
#include<string>
using namespace std;
void meihua() {
	system("titile  无敌大王的学生成绩管理系统");
	system("color b0");
	system("mode con cols=55 lines=30");
}
double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
class Score {
public:
	Score(int a, int b, int c) {
		english = a;
		math = b;
		jisuanji = c;
		sum1 += a;
		sum2 += b;
		sum3 += c;
		sum4 = sum1 + sum2 + sum3 + sum4;
	}
	Score() {
	}
	~Score() {}
	Score(const Score& score)
	{
	}
	static void func1() {
		num++;
	}
public:
	double english;
	double math;
	double  jisuanji;
public:
	static int num;
};
int Score::num = 0;
class Student {
public:
	Student() {
	}
	Student(string a, string b, int c, int d, int e) :xuehao(a), name(b), score(c, d, e) {
	}
	Student(const Student& student)
	{
		xuehao = student.xuehao;
		name = student.name;
	}
	~Student() {}

public:
	string xuehao;
	string  name;
public:Score score;
};

Student* student[100];
void zeng()
{
	string q;
	string w;
	int m, n, z;
	static int a = 0;
	cout << "请输入学生学号:";
	cin >> q;
	cout << "请输入学生姓名";
	cin >> w;
	cout << "请输入学生英语成绩";
	cin >> m;
	cout << "请输入学生数学成绩";
	cin >> n;
	cout << "请输入学生计算机成绩";
	cin >> z;
	student[a] = new Student(q, w, m, n, z);
	Score::func1();
	a++;
}
void chaxun(string x)
{
	for (int i = 0; i < Score::num; i++)
	{
		if (student[i]->name == x)
		{

			cout << "姓名:" << student[i]->name << " 学号:" << student[i]->xuehao << endl << "英语成绩:"
				<< student[i]->score.english << "  数学成绩:" << student[i]->score.math
				<< "  计算机成绩:" << student[i]->score.jisuanji << endl;
			system("pause");
			return;
		}

	}
	cout << "查无此人!" << endl;
	system("pause");
}
void xiugai(string x)
{
	for (int i = 0; i < Score::num; i++)
	{
		if (student[i]->name == x)
		{
			cout << "请输入要修改学生英语成绩;";
			cin >> student[i]->score.english;
			cout << "请输入要修改学生数学成绩";
			cin >> student[i]->score.math;
			cout << "请输入要修改学生计算机成绩";
			cin >> student[i]->score.jisuanji;
			system("pause");
			return;
		}
	}
	cout << "查无此人" << endl;
	system("pause");
}
void avg1()
{
	double m_english;
	m_english = sum1 / Score::num;
	cout << m_english << endl;
	system("pause");
}
void avg2()
{
	double m_math;
	m_math = sum2 / Score::num;
	cout << m_math << endl;
	system("pause");
}
void avg3()
{
	double m_jisuanji;
	m_jisuanji = sum3 / Score::num;
	cout << m_jisuanji << endl;
	system("pause");
}
void avg()
{
	double m_sum;
	m_sum = sum4 / Score::num;
	cout << m_sum << endl;
	system("pause");
}
int main()
{
	meihua();
	int p;
	string x;
	while (1) {
		system("cls");
		cout << "请输入您需要的操作" << endl << "1增加学生" << endl << "2查询学生" << endl << "3通过输入学生姓名修改学生信息" << endl << "4统计学生总成绩平均值" << endl << "5统计学生英语成绩平均值" << endl << "6统计学生数学成绩平均值" << endl << "7统计学生计算机平均值" << endl << "8退出程序" << endl;
		cin >> p;
		switch (p)
		{
		case 1:zeng(); break;
		case 2: cout << "请输入查询学生姓名；"; cin >> x; chaxun(x); break;
		case 3:cout << "请输入要修改学生姓名；"; cin >> x; xiugai(x); break;
		case 4:avg(); break;
		case 5:avg1(); break;
		case 6:avg2(); break;
		case 7:avg3(); break;
		case 8:exit(0); break;
		default:cout << "输入错误"; break;
		}
	}
	return 0;
}
