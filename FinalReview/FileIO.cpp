#include <iostream>
#include <string>
#include<fstream>
using namespace std;

int main() {
	int i;
	string id, name;
	/*
	ofstream myout;
	myout.open("student.txt", ios::out);//相对路径
	if (!myout) {
		cout << "open Failed" << endl;
		return 0;
	}
	cout << "input num;";
	int num;
	cin >> num;
	for (i = 0; i < num; i++) {
		cout << "input " << i << " number:";
		cin >> id;
		cout << "input " << i << " name:";
		cin >> name;
		myout << i << " " << id << " " << name << endl;
		
	}
	myout.close();
*/
	ifstream myin;
	myin.open("student.txt", ios::in);//相对路径
	if (!myin) {
		cout << "open Failed" << endl;
		return 0;
	}
	char input[30];
	while (!myin.eof()) {
		myin.getline(input, sizeof(input));
		cout << input << endl;
	}

	myin.close();
	return 0;

}
