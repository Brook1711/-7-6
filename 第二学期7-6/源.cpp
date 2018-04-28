#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int sumvector(vector<int> & rsorted_v, vector<int> & position_v)
{
	int sum(0);
	for (int i = 0; i < 4; i++)
	{
		sum += rsorted_v[i] * position_v[i];
	}
	return sum;
}

void FindSolution(vector<int> & sorted_v , vector<int> & position_v, int set_position, bool & Ti)
{
	int sum = 0;
	if (set_position == -1)
		return;
	while (sum < 24)
	{
		FindSolution(sorted_v, position_v, set_position - 1, Ti);
		position_v[set_position]++;
		sum = sumvector(sorted_v, position_v);
	}
	if (sum == 24)
	{
		Ti = true;
	}
	position_v[set_position] = 0;


}

int main()
{
	bool Ti = false;
	string str[4];
	vector<int> v,sv;
	cin >> str[0] >> str[1] >> str[2] >> str[3];
	

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		if (str[i].size() == 1)
		{
			if (str[i][0] == 65)
			{
				v.push_back(1);
			}
			else if (str[i][0] >= 48 && str[i][0] <= 57)
			{
				temp = int(str[i][0]) - 48;
				v.push_back(temp);
			}
			else if (str[i][0] == 74)
			{
				v.push_back(11);
			}
			else if (str[i][0] == 81)
			{
				v.push_back(12);
			}
			else if (str[i][0] == 75)
			{
				v.push_back(13);
			}
		}
		else
		{
			v.push_back(10);
		}
	}
	for (int i = 0; i < 4; i++)
		sv.push_back(0);
	sort(v.begin(), v.end());
	
	
	FindSolution(v, sv, 3, Ti);
	if (Ti)
		cout << "Y";
	else
		cout << "N";
	system("pause");
	return 0;
}