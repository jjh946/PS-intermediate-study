#include <iostream>
using namespace std;

int m, n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int arr[50][50] = { 0, };
int visited[50][50] = { 0, };

void Reset()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			arr[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void DFS(int x, int y)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 경계 검사
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		// 배추가 존재하고, 방문되지 않은 상태라면
		if (arr[ny][nx] == 1 && visited[ny][nx] == 0)
		{
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	int t; cin >> t;
	while (t--)
	{
		Reset();
		int k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y; cin >> x >> y;
			arr[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visited[i][j] == 0)
				{
					cnt++;
					DFS(j, i);
				}
			}
		}

		cout << cnt << endl;

	}

	return 0;
}