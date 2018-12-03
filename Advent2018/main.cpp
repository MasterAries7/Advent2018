#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

bool check2(string x);
bool check3(string x);
string findCommon(string x, string y);

void day1pt2() {
	ifstream input;
	input.open("input1.txt");
	set<int> freq;
	int inputchange;
	int current = 0;
	while (true) {
		if (freq.count(current))
			break;
		else {
			freq.insert(current);
			input >> inputchange;
			current += inputchange;
		}
		if (input.eof()) {
			input.close();
			input.open("input1.txt");
		}
	}
	cout << "Duplicate data is " << current;
}

void day2pt1() {
	ifstream input;
	input.open("input2-1.txt");
	int check3s = 0;
	int check2s = 0;
	string in;
	while (true) {
		if (input.eof()) {
			break;
		}
		getline(input, in);
		if (check3(in)) {
			check3s++;
		}
		if (check2(in)) {
			check2s++;
		}
	}
	cout << "Checksum is " << check3s*check2s << endl;
}

string day2pt2() {
	ifstream input;
	input.open("input2-1.txt");
	ifstream input2;
	string in, in2;
	while (true) {
		if (input.eof()) {
			break;
		}
		getline(input, in);
		input2.open("input2-1.txt");
		while (true) {
			if (input2.eof()) {
				break;
			}
			getline(input2, in2);
			if (in == in2) {
				getline(input2, in2);
			}
			string str = findCommon(in, in2);
			if (str != "0") {
				return str;
			}
		}
		input2.close();
	}
	return "0";
}

bool check3(string x) {
	int count;
	char ch;
	for (int j = 0; j < x.length(); j++) {
		count = 0;
		ch = x.at(j);
		for (int i = 0; i < x.length(); i++) {
			if (ch == x.at(i)) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}

bool check2(string x) {
	int count;
	char ch;
	for (int j = 0; j < x.length(); j++) {
		count = 0;
		ch = x.at(j);
		for (int i = 0; i < x.length(); i++) {
			if (ch == x.at(i)) {
				count++;
			}
		}
		if (count == 2) {
			return true;
		}
	}
	return false;
}

string findCommon(string x, string y) {
	int uncommon=0;
	int loc;
	for (int i = 0; i < x.length(); i++) {
		if(x.at(i) != y.at(i)) {
			uncommon++;
			loc = i;
		}
	}
	if (uncommon == 1) {
		x.erase(loc, 1);
		return x;
	}
	else {
		return "0";
	}
}

void main() {
	int x;
	cout << day2pt2();
	cin >> x;
}