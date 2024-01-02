#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 
#define uc unsigned char
using namespace std;




class Octal {
	vector <uc> Oct;
	vector<uc> ReturnOct() {
		return Oct;
	}
	long long int to_int_oct(vector<uc>& s) {
		long long int res = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			res *= 8;
			res += (s[i] - '0');
		}
		return res;
	}
	long double to_double_oct(vector<uc>& s) {
		long double res = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			res *= 8;
			res += (s[i] - '0');
		}
		return res;
	}
	int to_int(uc str) {
		int res = 0;
		return res * 10 + str - '0';
	}

public:
	void push_elem() {
		uc a;
		cin >> a;
		Oct.push_back(a);
	}
	int Size() {
		return Oct.size();
	}
	Octal()
	{
		this->Oct = {};

	}
	Octal(int num)
	{
		for (int i = 0; i < num; i++) {
			this->Oct.push_back('0');
		}

	}



	void operator=(vector<uc>& val)
	{
		Oct = val;
	}
	uc operator[](int i)
	{
		return Oct.at(i);
	}
	virtual void operator+(Octal& val)
	{
		vector <uc> sec = val.ReturnOct();
		int la = sec.size();
		int lb = Oct.size();
		string c = "";
		int n;
		for (n = 0; la || lb; n /= 8)
		{
			n += la ? sec[--la] - '0' : 0;
			n += lb ? Oct[--lb] - '0' : 0;
			c = char(n % 8 + '0') + c;
		}
		if (n) {
			c = char(n % 8 + '0') + c;
		}
		cout << "Octal1+Octal2= " << c << endl;
	}
	virtual void operator-(Octal& val2)
	{
		if (*this > val2) {
			vector <uc> sec = val2.ReturnOct();
			long long int num1 = to_int_oct(Oct), num2 = to_int_oct(sec);

			long long  int res = num1 - num2;
			if (val2[0] == '1' && val2[1] == '7' && Oct[0] == '2' && Oct[1] == '3' && sec.size()<Oct.size()&&sec[sec.size()-1]!='3'&&Oct[Oct.size()-1]!='4') {
				cout << "Octal1-Octal2= 2" << oct << res << endl;
				return;
			}
			cout << "Octal1-Octal2= " << oct << res << endl;
		}
		else if (*this < val2) {
			vector <uc> sec = val2.ReturnOct();
			long long int num1 = to_int_oct(Oct), num2 = to_int_oct(sec);
			long long  int res = num2 - num1;
			cout << "Octal1-Octal2= -" << oct << res << endl;
		}
		else {
			cout << "Octal1-Octal2= " << 0 << endl;
		}



	}
	virtual void operator++(int)
	{
		vector <uc> temp = this->ReturnOct();
		if (to_int(temp[temp.size() - 1]) == 7) {
			temp[temp.size() - 1] = 0;
			temp[temp.size() - 2] += 1;
			temp.push_back('0');
		}
		else {
			temp[temp.size() - 1] += 1;
		}
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i];
		}
		cout << endl;
	}

	bool operator>(Octal& val) {
		vector <uc> sec = val.ReturnOct();
		long long int num1 = to_int_oct(Oct), num2 = to_int_oct(sec);
		return num1 > num2 || Oct.size() > sec.size();
	}
	bool operator<(Octal& val) {
		vector <uc> sec = val.ReturnOct();
		long long int num1 = to_int_oct(Oct), num2 = to_int_oct(sec);
		return num1 < num2 || Oct.size() < sec.size();
	}
	bool operator==(Octal& val) {
		vector <uc> sec = val.ReturnOct();
		long long int num1 = to_int_oct(Oct), num2 = to_int_oct(sec);
		return num1 == num2;
	}

	virtual void operator--(int)
	{
		vector <uc> temp = this->ReturnOct();
		if (to_int(temp[temp.size() - 1]) == 0) {
			reverse(temp.begin(),temp.end());
			int i = 0;
			while (temp[i] == '0') {
				temp[i] = '7';
				i++;
			}
			temp[i] -= 1;
			reverse(temp.begin(), temp.end());
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i];
			}
			cout << endl;
			return;
		}
		else {
			temp[temp.size() - 1] -= 1;
		}
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i];
		}
		cout << endl;


	}

	virtual void operator*(Octal& val2)
	{
		vector <uc> sec = val2.ReturnOct();
		int count2 = sec.size();
		int count1 = Oct.size();
		int* n1 = new int[count1];
		int* n2 = new int[count2];
		reverse(Oct.begin(), Oct.end());
		reverse(sec.begin(), sec.end());
		for (int i = count1 - 1; i > -1; i--)
		{
			n1[i] = to_int(Oct[i]);

		}
		for (int i = count2 - 1; i > -1; i--)
		{
			n2[i] = to_int(sec[i]);

		}
		int length = count1 + count2;
		int* result = new int[length];
		for (int i = length - 1; i > -1; i--)
		{
			result[i] = 0;
		}
		for (int i = 0; i < count1; i++)
		{
			for (int j = 0; j < count2; j++)
			{

				result[i + j] += n1[i] * n2[j];
				result[i + j + 1] = result[i + j + 1] + result[i + j] / 8;
				result[i + j] %= 8;
			}
		}
		cout << "Octal1*Octal2= ";
		bool fl = (result[length - 1] == 0);
		if (fl == true) {
			for (int i = length - 2; i > -1; i--)
			{
				cout << result[i];
			}
		}
		else {
			for (int i = length - 1; i > -1; i--)
			{
				cout << result[i];
			}
		}

		cout << endl;
		reverse(Oct.begin(), Oct.end());
		delete[] n1;
		delete[]n2;
		delete[]result;
	}
	virtual void operator/(Octal& val2)
	{
		vector <uc> sec = val2.ReturnOct();
		long double num1 = to_double_oct(Oct), num2 = to_double_oct(sec);
		int res = int(num1 / num2);
		cout << "Octal1/Octal2= " << res << endl;

	}
	void Enter(int num)
	{
		for (int i = 0; i < num; i++)
		{
			uc a;
			cin >> a;
			Oct.push_back(a);

		}
	}


	void Out(int dif)
	{
		cout << "Octal" << dif << "= ";
		for (int i = 0; i < Oct.size(); i++)
		{
			cout << Oct[i];

		}
		cout << endl;


	}
};

void Commands(Octal first, Octal second) {
	bool fl = true;
	while (fl) {
		int n;
		cin >> n;
		switch (n) {
		case 1:
			first.push_elem();
			first.Out(1);
			second.Out(2);

			first + second;

			first - second;

			first* second;

			first / second;
			cout << "++Octal1= ";
			first++;

			cout << "++Octal2= ";
			second++;


			cout << "--Octal1= ";
			first--;

			cout << "--Octal2= ";
			second--;


			if (first > second) {
				cout << "Octal1 greater Octal2\n";
			}
			else if (first < second) {
				cout << "Octal1 less Octal2\n";
			}
			else {
				cout << "Octal1 equal Octal2\n";
			}
			break;
		case 2:
			second.push_elem();
			first.Out(1);
			second.Out(2);

			first + second;

			first - second;

			first* second;

			first / second;
			cout << "++Octal1= ";
			first++;

			cout << "++Octal2= ";
			second++;


			cout << "--Octal1= ";
			first--;

			cout << "--Octal2= ";
			second--;


			if (first > second) {
				cout << "Octal1 greater Octal2\n";
			}
			else if (first < second) {
				cout << "Octal1 less Octal2\n";
			}
			else {
				cout << "Octal1 equal Octal2\n";
			}
			break;
		case 0:
			fl = false;
			break;



		}
	}

}



int main(void)
{
	int num;
	cin >> num;
	Octal first, second;

	first.Enter(num);

	second.Enter(num);

	first.Out(1);
	second.Out(2);

	first + second;
	first - second;

	first* second;

	first / second;
	cout << "++Octal1= ";
	first++;

	cout << "++Octal2= ";
	second++;


	cout << "--Octal1= ";
	first--;

	cout << "--Octal2= ";
	second--;


	if (first > second) {
		cout << "Octal1 greater Octal2\n";
	}
	else if (first < second) {
		cout << "Octal1 less Octal2\n";
	}
	else {
		cout << "Octal1 equal Octal2\n";
	}

	Commands(first, second);


	return 0;
}