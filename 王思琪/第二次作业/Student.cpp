#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Score {
public:
	int chinese;
	int maths;
	int english;
	void inputscore(int e, int m, int c) {
		this->chinese = e;
		this->maths = m;
		this->english = c;
	}
};
class Student
{
public:
	void inputname() {
		this->name = "xioaming";
	}
	friend Score;
	Student() {}
	
	Student(string a, string b, int e, int m, int c);
	
	~Student();

	Student(const Student& temp) {
		this->id = temp.id;
		this->name = temp.name;
		this->score.chinese = temp.score.chinese;
		this->score.maths = temp.score.maths;
		this->score.english = temp.score.english;
		num++;
	}

	void Print(Student stu[]);
	void Update(Student* stu);
	void  AverageScore(Student stu[]);
	Student input();

	string id;
	string name;
	Score score;
	Score* pscore;
	
	static int num;//人数
	static void shownum() {
		cout << num/3 << endl;
	}
};
int Student::num = 0;
Student::~Student() {
	num++;
}
// 显示学生资料
void Student::Print	(Student stu[]) {
	cout << "姓名   学号   语文   数学  英语   平均成绩" << endl;
	for (int i = 1; i <= num/3; i++) {
		cout << stu[i].name << "   " << stu[i].id << "   " << stu[i].score.chinese << "   " << stu[i].score.maths;
		cout << "   " << stu[i].score.english << "   " << (stu[i].score.chinese + stu[i].score.maths + stu[i].score.english) / 3 << endl;
	}
}
//修改某学生资料
void Student::Update(Student* stu) {
	int i;
	pscore = &stu->score;
	cout << "请按顺序输入数据，每输入完成请按回车" << endl;
	cout << "学号  姓名  语文成绩  数学成绩  英语成绩" << endl;
	cin >> stu->id;
	cin >> stu->name; 
	cin >> stu->pscore->chinese;
	cin >> stu->pscore->maths; 
	cin >> stu->pscore->english; 
}
//计算科目平均分
void  Student::AverageScore(Student stu[]) {
	int sum = 0;
	cout << "语文\t数学\t英语" << endl;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.chinese;
	}
	cout << sum / (num / 3) << "	";
	sum = 0;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.maths;
	}
	cout << sum /( num / 3 )<< "	";
	sum = 0;
	for (int i = 1; i <= num / 3; i++) {
		sum += stu[i].score.english;
	}
	cout << sum /( num / 3 )<< "	" << endl;
}
//添加学生信息
Student Student::input()     //输入学生信息函数
{
	Student stu;
	cout << "学号：";
	cin >> stu.id;
	cout << "姓名：";
	cin >> stu.name;
	cout << "语文：";
	cin >> stu.score.chinese;
	cout << "数学：";
	cin >> stu.score.maths;
	cout << "英语：";
	cin >> stu.score.english;
	return stu;
}
//主界面
void welcomemenu() {
	cout << "2.添加学生信息"  << endl;
	cout << "1.显示学生资料"<< endl;
	cout << "3.计算科目平均分" << endl;
	cout << "4.查看学生人数" << endl;
	cout << "5.修改某学生资料" << endl;
}
int main() {
	int i, a;
	Student stu, st[100];
	int Num = 1;
	welcomemenu();
	while (cin >> i){
		switch (i){
		case 1:
			st[Num] = stu.input();
			Num++;//这里调用了拷贝构造函数
			break;
		case 2:
			stu.Print(st);
			break;
		case 3:
			stu.AverageScore(st);
			break;
		case 4:stu.shownum();//静态方法访问静态成员
			break;
		case 5:
			cout << "请输入要修改的学生的序号" << endl;
			cin >> a;
			st[a].Update(&st[a]);
			break;
		}
		system("pause");
		system("cls");
		welcomemenu();//主界面
	}
	return 0;
}
