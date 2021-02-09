#include <bits/stdc++.h>
int Num=3;	
//static int sum;//总分（全员总分）

class Score {
public:
	int english;
	int maths;
	int computer; 
	void setscore(int e, int m, int c) {
		this->english = e;
		this->maths = m;
		this->computer = c;
	}
	int GetScore() {
		return english + maths + computer;
	}
	
};

class Student
{
	
public:
	void setname() {
		this->name = "xioaming";
	}
	friend Score;
	//构造函数
	Student() {}
	Student(std::string a, std::string b, int e, int m, int c);
	//析构函数
	~Student();
	//拷贝构造函数
	 Student(const Student& p) {
		this->id = p.id;
		this->name = p.name;
		this->score.computer = p.score.computer;
		this->score.english = p.score.english;
		this->score.maths = p.score.maths;
		num++;
	}

	//以下为应用函数
	void AddItem();
	void ViewData(Student stu);
	void UpdateData(Student *stu);
	int  AvgScoreSubject(Student stu[]);
	Student input();

	//静态方法访问静态成员 求全员平均成绩（静态成员函数） 
	
	float AvgScoreAll(Student* stu);

	std::string id;
	std::string name;
	Score score;
	Score* pscore;

	static int num;//人数(已创建学生人数）
	static void shownum() {
		std::cout << num << std::endl;
	}
};

int Student::num = 0;//静态数据成员定义和初始化，使用类名限定

Student::~Student() {
	num--;
}
//0.基本信息赋值
Student::Student(std::string a, std::string b, int e, int m, int c) {
	this->id = a;
	this->name = b;
	score.setscore(e, m, c);
	num++;
}
// 1.显示某学生资料
void Student::ViewData(Student stu) {
	
	std::cout << "\n姓名:" << name << "\nid:" << id<<"\nenglish:"<<stu.score.english <<"\nmaths:"<<stu.score.maths<<"\ncomputer:"<<stu.score.computer<<std:: endl;
	
}

//2.修改某学生资料
void Student::UpdateData(Student *stu) {
	int i;
	pscore = &stu->score;
	std::cout << "请输入要修改的项目 1.id，2.name，3.english,4.maths,5.computer" << std::endl;
	std::cin >> i;
	switch (i) {
	case 1:std::cin >> stu->id; break;
	case 2:std::cin >> stu->name; break;
	case 3:std::cin >> stu->pscore->english; break;
	case 4:std::cin >> stu->pscore->maths; break;
	case 5:std::cin >> stu->pscore->computer; break;
	}
}

// 3.计算全员平均分 统计每个学生的平均成绩，总分除以人数
float Student::AvgScoreAll(Student stu[]) {
	int sum = 0;
	stu->pscore = &stu->score;
	for (int i = 1; i <= num; i++) {
		sum += stu[i].score.computer + stu[i].score.english + stu[i].score.maths;
	}
	int avgscore = sum / num;//由于成绩一般取整，这里直接整除不保留小数-p;p
	return avgscore;
}

//4.计算单科目平均分 统计多个学生的某一课程平均成绩 ,每个学生的某科成绩总和除以学生数num;
int  Student:: AvgScoreSubject(Student stu[]) {
	int sum=0,j;
	std::cout << "请输入要计算的单科成绩，1数学，2英语，3计算机" << std::endl;
	std::cin >> j;
		switch (j) {
		case 1:for (int i = 1; i <= num; i++) {
			sum +=  stu[i].score.maths;
		}
			break;
		case 2:
			for (int i = 1; i <= num; i++) {
				sum += stu[i].score.english;
			}
			break;
		case 3:
			for (int i = 1; i <= num; i++) {
				sum += stu[i].score.computer;
			}
			break;
		}
		return sum / num;

}
//6.添加学生信息
Student Student::input()     //输入学生信息函数
{
	Student stu;
	std::cout << "\t\t学号：";
	std::cin >> stu.id;
	std::cout << "\t\t姓名：";
	std::cin >> stu.name;
	std::cout << "\t\tcomputer：";
	std::cin >> stu.score.computer;
	std::cout << "\t\tenglish：";
	std::cin >> stu.score.english;
	std::cout << "\t\tmath：";
	std::cin >> stu.score.maths;
	return stu;
}

//视图层
void viewmenu() {
	std::cout << "*************************************************" << std::endl;
	std::cout << "     1.显示某学生资料        2.修改某学生资料" << std::endl;
	std::cout << "     3.计算全员平均分        4.计算单科目平均分 " << std::endl;
	std::cout << "     5.显示学生人数      6.添加学生信息" << std::endl;
	std::cout << "**************************************************" << std::endl;
}
int main() {
	int i, a;   Student stu,st[100];
	//Student st[100]{ Student("201230102", "xiaowang", 70, 80, 50) };
	
	Student e1("201230102", "xiaowang", 70, 80, 50), e2("201230103", "xiaoli", 70, 99, 50);
	st[1] = e1, st[2] = e2;
	std::cout << "我们已经预设了两个学生（编号为1和2），调用了有参构造函数," << std::endl;
	
	viewmenu();//主界面
	while (std::cin >> i)
	{
		switch (i)
		{
		case 1:
			std::cout << "请输入要查询的学生的序号" << std::endl; 
			std:: cin >> a;
			st[a].ViewData(st[a]);
			break;
		case 2:
			std::cout << "请输入要修改的学生的序号" << std::endl; 
			std::cin >> a;
			st[a].UpdateData(&st[a]);
			break;
		case 3:
			std::cout << stu.AvgScoreAll(st) << std::endl;
			break;
		case 4:
			std::cout << stu.AvgScoreSubject(st) << std::endl;
			break;
		case 5:Student:: shownum();//静态方法访问静态成员
			break;
		case 6:st[Num] = stu.input(); Num++;//这里调用了拷贝构造函数
			break;

		}
	}
	return 0;
}
