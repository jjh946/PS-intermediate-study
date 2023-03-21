#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, int> name; // 이름으로 검색하는 용도의 map
vector<string> number; // 번호로 검색하는 용도의 vector

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	// Index 0은 쓰지 않음
	name.insert(make_pair("None", 0));
	number.push_back("None");

	// 포켓몬을 도감에 저장
	for (int i = 1; i <= n; i++)
	{
		string pokemon; cin >> pokemon;
		name.insert(make_pair(pokemon, i));
		number.push_back(pokemon);
	}
	// 문제 풀이
	for (int i = 0; i < m; i++)
	{
		string q; cin >> q;

		// 포켓몬 번호가 문제로 주어진 경우
		if (q[0] >= '0' && q[0] <= '9')
		{
			int num = stoi(q);
			cout << number[num] << '\n';
		}
		// 포켓몬 이름이 문제로 주어진 경우
		else
		{
			cout << name[q] << '\n';
		}
	}

	return 0;
}