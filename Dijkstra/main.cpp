#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;


//ifstream fin("dijkstra.in");
//ifstream fout("dijkstra.out");
const int NMAX = 50000;
const int oo = (1 << 30);
int N, M;
int D[NMAX];			//vectorul de distante
bool InCoada[NMAX];		//stocheaza cand un nod intra in coada

vector <pair <int, int > > G[NMAX];
struct ComparaDistante
{
	bool operator()(int x, int y)
	{
		return D[x] > D[y];
	}
};

priority_queue < int, vector <int >, ComparaDistante > Coada;

void Citire()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		G[x].push_back(make_pair(y, c));// Punem in G[x] toti vecinii care au costul c
	}
}
void Dijkstra(int nodStart)
{
	for (int i = 1; i <= N; i++)
	{
		D[i] = oo;
	}
	D[nodStart] = 0;			
	Coada.push(nodStart);		//Punem nodul de start in coada
	InCoada[nodStart] = true;	// Validam ca nodul este in coada
	while (!Coada.empty())
	{
		int nodCurent = Coada.top();// extragem codul curent 
		Coada.pop();
		InCoada[nodCurent] = false;

		for (size_t i = 0; i < G[nodCurent].size(); i++)
		{
			int Vecin = G[nodCurent][i].first;
			int Cost = G[nodCurent][i].second;
			if (D[nodCurent] + Cost < D[Vecin])
			{
				D[Vecin] = D[nodCurent] + Cost;
				if (InCoada[Vecin] == false)
				{
					Coada.push(Vecin);
					InCoada[Vecin] = true;
				}
			}
		}
	}
}
void Afisare()
{
	for (int i = 2; i <= N; i++)
	{
		if (D[i] != oo)
		{
			cout << D[i] << " ";
		}
		else
			cout << " 0 ";
	}
}
int main()
{

	Citire();
	Dijkstra(1);
	Afisare();

	return 0;
}