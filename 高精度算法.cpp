#include<iostream>
#include<string>
using namespace std;

void sub(int x[], int y[])
{
	int assist = 0;
	for (int i = y[0]; i >= 1; i--)
	{
		if (x[i] - y[i] - assist >= 0)
		{
			x[i] = x[i] - y[i] - assist;
			assist = 0;
		}
		else if (x[i] - y[i] - assist < 0)
		{
			x[i] = x[i] + 10 - y[i] - assist;
			assist = 1;
		}
	}
}

bool compare(int x[], int y[])
{
	for (int i = 1; i <= x[0]; i++)
	{
		if (x[i] > y[i])
		{
			return true;
		}
		else if (x[i] < y[i])
		{
			return false;
		}
	}
	return true;
}

void copy(int x[], int y[], int assist)
{
	for (int i = 1; i <= x[0]; i++)
	{
		y[i + assist] = x[i];
	}
	y[0] = x[0] + assist;
}

int main()
{
	string s1 = " ";
	string s2 = " ";
	cin >> s1 >> s2;
	int num1[310] = { 0 };
	int num2[310] = { 0 };
	int result[310] = { 0 };

	if (s1 == "0")
	{
		cout << 0 << endl << 0;
		return 0;
	}

	num1[0] = s1.size();
	num2[0] = s2.size();
	result[0] = num1[0] - num2[0] + 1;

	if (num1[0] < num2[0])
	{
		cout << 0 << endl << s1;
		return 0;
	}

	for (int i = 1; i <= num1[0]; i++)
	{
		num1[i] = s1[i - 1] - '0';
	}
	for (int i = 1; i <= num2[0]; i++)
	{
		num2[i] = s2[i - 1] - '0';
	}

	int temp[620] = { 0 };
	for (int i = 1; i <= result[0]; i++)
	{
		memset(temp, 0, sizeof(temp));
		copy(num2, temp, i - 1);
		num1[0] = temp[0];
		while (compare(num1, temp) == true)
		{
			sub(num1, temp);
			result[i]++;
		}
	}

	int head = 1;
	for (int i = 1; i <= result[0]; i++)
	{
		if (result[i] == 0 && i == head)
		{
			head++;
			continue;
		}
		cout << result[i];
	}
	cout << endl;
	head = 1;
	for (int i = 1; i <= num1[0]; i++)
	{
		if (num1[i] == 0 && i == head)
		{
			head++;
			continue;
		}
		cout << num1[i];
	}
	if (head == num1[0] + 1)
	{
		cout << 0;
	}
	return 0;
}

































//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string c;
//	cin >> c;
//	int num[35] = { 0 };
//	int len = c.size();
//
//	for (int i = 0; i < len; i++)
//	{
//		num[i] = c[i] - '0';
//	}
//
//	int count = 0;
//	for (int i = 2; i <= 9; i++)
//	{
//		int ass = 0;
//		for (int j = 0; j < len; j++)
//		{
//			num[j] = num[j] + ass * 10;
//			ass = num[j] % i;
//			num[j] = num[j] / i;
//		}
//		if (ass == 0)
//		{
//			cout << i << " ";
//			count++;
//		}
//		if (count == 0)
//		{
//			cout << "none";
//		}
//	}
//	return 0;
//}

//int main()
//{
//	string n;
//	cin >> n;
//	int num[110] = { 0 };
//	int len = n.size();
//
//	for (int i = 0; i < len; i++)
//	{
//		num[i] = n[i] - '0';
//	}
//
//	int ass = 0;
//	for (int i = 0; i < len; i++)
//	{
//		num[i] = num[i] + ass * 10;
//		ass = num[i] % 13;
//		num[i] = num[i] / 13;
//	}
//	int rest = ass;
//
//	ass = 0;
//	for (int i = len - 1; i >= 0; i--)
//	{
//		num[i] = num[i] + ass;
//		ass = num[i] / 10;
//		num[i] = num[i] % 10;
//	}
//
//	int start = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (num[i] == 0 && i == start)
//		{
//			start++;
//			continue;
//		}
//		cout << num[i];
//	}
//	cout << endl << rest;
//	return 0;
//}





























//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	int num1[110] = { 0 }, num2[110] = { 0 }, mul[220] = { 0 };
//	int i = 0, j = 0;
//
//	getline(cin, s1);
//	getline(cin, s2);
//	int len1 = s1.size();
//	int len2 = s2.size();
//
//	for (i = 0; i < len1; i++)
//	{
//		num1[i] = s1[len1 - 1 - i] - '0';
//	}
//
//	for (i = 0; i < len2; i++)
//	{
//		num2[i] = s2[len2 - 1 - i] - '0';
//	}
//
//	for (i = 0; i < len2; i++)
//	{
//		for (j = 0; j < len1; j++)
//		{
//			mul[j + i] += num1[j] * num2[i];
//			if (mul[j + i] >= 10)
//			{
//				mul[j + i + 1] += mul[j + i] / 10;
//				mul[j + i] = mul[j + i] % 10;
//			}
//		}
//	}
//
//	int len = len1 + len2 - 1;
//	for (i = len; i >= 0; i--)
//	{
//		if (mul[len] == 0)
//		{
//			if (len == 0)
//			{
//				cout << 0;
//				break;
//			}
//			len--;
//			continue;
//		}
//		cout << mul[i];
//	}
//
//	return 0;
//}


































//1168--大整数加法
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int i;
//	string s1, s2;
//	int num1[210], num2[210], add[210] = { 0 };
//	getline(cin, s1);
//	getline(cin, s2);
//	int len1 = s1.size();
//	int len2 = s2.size();
//
//	for (i = 0; i < len1; i++)
//	{
//		num1[i] = s1[len1 - 1 - i] - '0';
//		num2[i] = s2[len2 - 1 - i] - '0';
//	}
//
//	reverse(num1, num1 + len1);
//	reverse(num2, num2 + len2);
//
//	for (i = 0; i < max(len1, len2); i++)
//	{
//		if (i == 0)
//		{
//			add[i] = (num1[i] + num2[i]) % 10;
//		}
//		else if (i > 0)
//		{
//			add[i] = (num1[i] + num2[i] + (num1[i - 1] + num2[i - 1]) / 10) % 10;
//		}
//	}
//
//	if (num1[max(len1, len2) - 1] + num2[max(len1, len2) - 1] + (num1[max(len1, len2) - 2] + num2[max(len1, len2) - 2]) / 10 >= 10)
//	{
//		add[max(len1, len2)] = 1;
//	}
//
//	for (i = max(len1, len2); i >= 0; i--)
//	{
//		if (add[i] == 0 && i == max(len1, len2))
//		{
//			continue;
//		}
//		cout << add[i];
//	}
//
//	return 0;
//}