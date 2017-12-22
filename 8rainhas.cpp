#include <iostream>
#include <vector>

using namespace std;

// conta a quantidade de solu��es
int sol = 0;

// fun��o para mostrar o tabuleiro
void mostrarTabuleiro(vector<vector<int> > & tab, int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(tab[i][j] == 1)
				cout << "R\t";
			else
				cout << "*\t";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

// verifica se � seguro colocar a rainha numa determinada coluna
// isso poderia ser feito com menos c�digo, mas assim ficou mais did�tico
bool seguro(vector<vector<int> > & tab, int N, int lin, int col)
{
	int i, j;

	// verifica se ocorre ataque na linha
	for(i = 0; i < N; i++)
	{
		if(tab[lin][i] == 1)
			return false;
	}

	//verifica se ocorre ataque na coluna
	for(i = 0; i < N; i++)
	{
		if(tab[i][col] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal principal
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if(tab[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i < N && j < N; i++, j++)
	{
		if(tab[i][j] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal secund�ria
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j < N; i--, j++)
	{
		if(tab[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i < N && j >= 0; i++, j--)
	{
		if(tab[i][j] == 1)
			return false;
	}

	// se chegou aqui, ent�o est� seguro (retorna true)
	return true;
}

/*
	fun��o que resolve o problema
	retorna true se conseguiu resolver e false caso contr�rio
*/
void executar(vector<vector<int> > & tab, int N, int col)
{
	if(col == N)
	{
		cout << "Solucao " << sol + 1 << ":\n\n";
		mostrarTabuleiro(tab, N);
		sol++;
		return;
	}

	for(int i = 0; i < N; i++)
	{
		// verifica se � seguro colocar a rainha naquela coluna
		if(seguro(tab, N, i, col))
		{
			// insere a rainha (marca com 1)
			tab[i][col] = 1;

			// chamada recursiva
			executar(tab, N, col + 1);

			// remove a rainha (backtracking)
			tab[i][col] = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	// n�mero de rainhas
	int N = 8;

	// tabuleiro (matriz)
	vector<vector<int> > tab;

	// inserindo todas as linhas
	for(int i = 0; i < N; i++)
	{
		vector<int> linha(N);
		tab.push_back(linha);
	}

	// imprime todas as solu��es
	executar(tab, N, 0);

	// imprime a quantidade de solu��es
	cout << "\nEncontradas " << sol << " solucoes!\n";

	return 0;
}
