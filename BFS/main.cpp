#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;
ifstream fin("bfs.in");
ofstream fout("bfs.out");

int N, M;
int const NLIM = 100005;
int Distanta[NLIM];
vector <int> Muchii[NLIM];
queue <int> Coada;

void BFS()
{
	int Nod, Vecin;
	while (!Coada.empty())
	{
		Nod = Coada.front();
		Coada.pop();
		for (unsigned int i = 0; i < Muchii[Nod].size(); i++)
		{
			Vecin = Muchii[Nod][i];
			if (Distanta[Vecin] == -1)
			{
				Coada.push(Vecin);
				Distanta[Vecin] = Distanta[Nod] + 1;
			}
		}
	}
}
void Citire()
{
	int nodStart;
	fin >> N >> M >> nodStart;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		fin >> x >> y;
		Muchii[x].push_back(y);
	}
	for (int i = 1; i <= N; i++)
		Distanta[i] = -1;
	Distanta[nodStart] = 0;

	Coada.push(nodStart);
	BFS();
	for (int i = 1; i <= N; i++)
	{
		fout << Distanta[i] << " ";
	}

}


int main()
{
	Citire();

	return 0;
}