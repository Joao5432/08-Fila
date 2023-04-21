#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
void exibirElementos();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Exibir elementos \n";
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4: exibirElementos();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}


void insere()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (inicio == NULL) {
		inicio = novo;
	}

	else {
		fim = novo;
		novo->prox = fim;
		inicio->prox = fim;

	}
}

void remove()
{
	NO* aux = inicio;

	if (inicio == NULL) {
		cout << "A lista esta vazia" << endl;
	}

	else if (inicio->prox == NULL) {
		free(aux);
		inicio = NULL;
	}

	else {
		inicio = inicio->prox;
		free(aux);
	}


}

void exibirElementos()
{
	if (inicio == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = inicio;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}