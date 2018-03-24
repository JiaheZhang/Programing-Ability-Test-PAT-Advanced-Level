#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int k;
	int Nk;
	double ak;
	pair<int, double> p;
	vector<pair<int, double> > v1, v2, result;
	
	scanf("%d",&k); 
	//cin >> k;
	while (k > 0)
	{
		k--;
		scanf("%d",&Nk);
		scanf("%lf",&ak);
		p.first = Nk;
		p.second = ak;
		//cin >> p.first >> p.second;
		v1.push_back(p);
	}

	scanf("%d",&k); 
	while (k > 0)
	{
		k--;
		scanf("%d",&Nk);
		scanf("%lf",&ak);
		p.first = Nk;
		p.second = ak;
		v2.push_back(p);
	}
	int len1 = v1.size();
	int len2 = v2.size();
	int i = 0;
	int j = 0;

	while (i < len1 || j < len2)
	{
		if (i < len1&&j < len2)
		{
			if (v1[i].first == v2[j].first)
			{
				if(v1[i].second + v2[j].second != 0)
				{
					p.first = v1[i].first;
					p.second = v1[i].second + v2[j].second;
					result.push_back(p);
				} 
				
				i++;
				j++;
			}
			else
			if (v1[i].first > v2[j].first)
			{
				result.push_back(v1[i]);
				i++;
			}
			else
			if (v1[i].first < v2[j].first)
			{
				result.push_back(v2[j]);
				j++;
			}
		}
		else
		if (i < len1&&j == len2)
		{
			result.push_back(v1[i]);
			i++;
		}
		else
		if (i == len1&&j < len2)
		{
			result.push_back(v2[j]);
			j++;
		}
	}
	/*
	vector<pair<int, double> >::iterator it = result.begin(); //真几把坑 基础不扎实 
	for ( ; it != result.end(); it++)
	{
		if (it->second == 0)
			result.erase(it);
	}
	*/
	cout << result.size();
	for (int k = 0; k < result.size(); k++)
	{
		printf(" %d %.1f", result[k].first, result[k].second);
	}

	return 0;
}
