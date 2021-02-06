#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
void meihua() {
	system("titile  无敌大王的快递店");
	system("color e0");
	system("mode con cols=80  lines=30");
}
class   Package {
public:
	virtual double calculateCost() = 0;
	string sent_iteam;
	string get_iteam;
	string address1;
	string address2;
	int weight;
	int kilometre;
};
class  pu_Package :public Package {//四公斤以内八元 超出四公斤部分按每公斤两元计费			
public:
	virtual double calculateCost()
	{
		if (weight <= 4) {

			return 8;
		}
		else
		{
			price = (8 + (weight - 4) * 2);
			return price;
		}
	}
	double price;
};

class  ji_Package :public Package {//起步价12 +重量*10+公里数*0.02
public:
	virtual double calculateCost()
	{
		price = 12 + (weight * 10) + kilometre * 0.02;

		return price;
	}

	double price;
};
void  test01()
{
	Package* p1 = new pu_Package;
	cout << "***************您选择的是普通包裹,下面请根据提示输入您的信息*******************" << endl;
	cout << "请输入寄件人姓名" ;
	cin >> p1->sent_iteam;
	cout << "请输入收件人姓名";
	cin >> p1->sent_iteam;
	cout << "请输入寄件人地址" ;
	cin >> p1->address1;
	cout << "请输入收件人地址" ;
	cin >> p1->address2;
	cout << "请输入货物重量" ;
	cin >> p1->weight;
	cout << "                   皮鲁鲁机器人正在为您飞速计算价格....." << endl<<endl<<endl ;
	Sleep(1000);
	cout << "               您所需要支付金额为（" << p1->calculateCost() << "）元," <<"请您到前台进行支付."<<endl<<endl<<endl
		<<endl<<"******************很高兴为您服务，期待下一次与您相见!**************************" << endl;
	system("pause");
	delete p1;
}
void test02()
{
	Package* p2 = new ji_Package;
	cout << "***************您选择的是加急包裹,下面请根据提示输入您的信息*******************" << endl;
	cout << "请输入寄件人姓名";
	cin >> p2->sent_iteam;
	cout << "请输入收件人姓名" ;
	cin >> p2->sent_iteam;
	cout << "请输入寄件人地址" ;
	cin >> p2->address1;
	cout << "请输入收件人地址" ;
	cin >> p2->address2;
	cout << "请输入货物重量" ;
	cin >> p2->weight;
	cout << "请输入加急公里数" ;
	cin >> p2->kilometre;
	cout << "                   皮鲁鲁机器人正在为您飞速计算价格....." << endl << endl << endl;
	Sleep(1000);
	cout << "               您所需要支付金额为（" << p2->calculateCost() << "）元," << "请您到前台进行支付." << endl << endl << endl
		<< endl << "******************很高兴为您服务，期待下一次与您相见!**************************" << endl;
	system("pause");
	delete p2;
}
int main() {
	meihua();
	int p;
	while (1) {
		system("cls");
		cout << "************************客户您好我是本店智能机器人******************************" << endl;
		cout << "            本店快递包裹共有两种类型,分别为普通包裹与极速包裹.         " << endl;
		//cout << "普通包裹计费方式为：四公斤以内八元，超出四公斤部分按每公斤两元计费"<<endl;
		//cout << "极速包裹计费方式为：起步价12 +重量*10+公里数*0.02"<<endl;
		cout << "                    请输入数字代表您所需要的包裹类型：" << endl << "                       1普通包裹 " << "2加急包裹" << endl;
		cin >> p;
		switch (p)
		{
		case 1:test01(); break;
		case 2:test02(); break;
		default:cout << "输入错误！"; break;
		}

	}
	return 0;
}

