#include<iostream>
#include<cstring>
using namespace std;

class Package {
	string sender;
	string receiver;
	string address;
	double weight;
public:
	Package(double weight,string sender,string receiver,string address) {
		this->sender = sender;
		this->receiver = receiver;
		this->address = address;
		this->weight = weight;
	}
	~Package() {};
	virtual double calculatecost() = 0;
	string getsender(string sender) {
		return sender;
	}
	string getreceiver(string receiver) {
		return receiver;
	}
	string getaddress(string address) {
		return address;
	}
	double getweight() {
		return weight;
	}
	 static void fun() {
		 num++;
	}
	 static int num ;
};
int Package::num = 0;
static int num = 0;
class normal :Package {
public:
	double firstcost;
	double overcost;
	double firstweight;
	double getfirstcost() {
		return firstcost;
	}
	double getovercost() {
		return overcost;
	}
	normal(string sender, string receiver, string address, double weight) :Package(weight, sender, receiver, address){
		cout << "请输入快递的重量：" << weight << endl;
		cout << "请输入快递的发件人：" << sender << endl;
		cout << "请输入快递的收件人：" << receiver << endl;
		cout << "请输入快递将要邮寄到的地址：" << address << endl;
		firstcost = 20;
		overcost = 5;
		firstweight = 10;
	}
	double calculatecost() {
		if (getfirstcost() > firstcost) {
			return ((getweight() - firstweight) * 5 + 20);
		}
		else
			return firstcost;
	}
	void print() {
		cout << "该邮件的费用为" << calculatecost() << endl;
	}
};
class hurry :Package {
public:
	double firstprice;
	double distance;
	hurry(double weight, string sender, string receiver, string address,double distance) :Package(weight,sender,receiver,address){
		cout << "请输入快递的重量：" << weight << endl;
		cout << "请输入快递的发件人：" << sender << endl;
		cout << "请输入快递的收件人：" << receiver << endl;
		cout << "请输入快递将要邮寄到的地址：" << address << endl;
		firstprice = 50;
		this->distance = distance;
	}
	double calculatecost() {
		return (firstprice + getweight() * 10 + distance * 0.02);
	}
	void print() {
		cout << "该邮件的费用为：" << calculatecost() << endl;
		cout << '\n';
	}
};
int main() {
	normal package1("ykl", "jr", "sy", 20);
	hurry package2(20, "ykl", "jr", "sy", 50);
	package1.print();
	package2.print();
}
