#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


struct Music{
	string name;
	string style;
	int freq = 0;
	Music(string _name, string _style): name(_name), style(_style) {};
};

int main()
{
	string str;
	unordered_map<string, std::vector<Music> type_arr;
	unordered_map<string, string> check;
	while (getline(cin, str))
	{
		stringstream sin(str);
		if (str == '\n') break;
		string s;
		vector<string> info;
		while (sin >> s)
		{
			info.push_back(s);
		}

		if (info[0] == 'I')
		{
			check[info[1]] = info[2];
			if (type_arr.count(info[2]) == 0)
			{
				vector<Music> music;
				Music mus(info[1], info[2]);
				music.push_back(mus);
				type_arr.push_back(mus);
			}
			else
			{
				Music mus(info[1], info[2]);
				type_arr[info[2]].push_back(mus);
			}
		}
		else if (info[0] == "P") {
			string style = check[info[1]];
			if (style  == "UnKnownStyle") 
			{
				for (auto &it : type_arr[style])
				{
					if (it.name == info[])
				}
			}
		}

	}
}
