#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a, b;
	int sum = 0;
	while (cin >> a >> b)
	{
		sum = a + b;
		string s = to_string(sum);
		int len = s.size();
		
		if (sum < 0)
		{
			for (int i = 1; i < len - 1; i++)
			{
				if (i % 3 == 0)//every three numbers insert a ,
				{
					s.insert(len - i, ",");
				}
			}
		}
		else
		{
			for (int i = 1; i < len; i++)
			{
				if (i % 3 == 0)
				{
					s.insert(len - i, ",");
				}
			}
		}
		cout << s;
	}
	return 0;
}