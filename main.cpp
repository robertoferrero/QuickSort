#include <iostream>
#include <cstdlib>
#include <vector>


template<typename T>
void swap(std::vector<T>& v,int p1, int p2) {
	T aux = v[p1];
	v[p1] = v[p2];
	v[p2] = aux;
}

template<typename T>
int posicioPivot(std::vector<T>& v, int primer, int ultim) {
	srand((unsigned int)time(0));
	int pos1 = rand() % (ultim - primer + 1) + primer;
	int pos2 = rand() % (ultim - primer + 1) + primer;
	int pos3 = rand() % (ultim - primer + 1) + primer;

	if (v[pos1] >= v[pos2] && v[pos2] >= v[pos3])
		return pos2;
	else if (v[pos2] >= v[pos1] && v[pos1] >= v[pos3])
		return pos1;
	else
		return pos3;
	
}

template<typename T>
int dividirVector(std::vector<T>& v, int primer, int ultim, int posPivot) {
	
	swap(v,primer,posPivot); // Pivot a la 1a posició

	int indexEsquerra = primer + 1;
	int indexDreta    = ultim;

	while (indexEsquerra < indexDreta) {
		while (indexDreta > indexEsquerra && v[indexDreta] >= v[primer])
			indexDreta--;
		while (indexEsquerra < indexDreta && v[indexEsquerra] <= v[primer])
			indexEsquerra++;
		swap(v, indexEsquerra, indexDreta);
	}

	if (v[indexDreta] < v[primer])
		swap(v, indexDreta, primer);
	
	return indexDreta;
}


template<typename T>
void quicksort(std::vector<T>& v, int primer, int ultim) {

	
	if (ultim > primer) {
		// Seleccionem pivot
		int posPivot = posicioPivot(v, primer, ultim);

		// Dividim vector
		int index = dividirVector(v,primer,ultim,posPivot);

		// Crides recursives
		quicksort(v, primer, index-1);
		quicksort(v, index+1, ultim);
	}
}

template<typename T>
void quicksort(std::vector<T>& v) {
	quicksort(v, 0, v.size() - 1);
}

template<typename T>
void mostraVector(std::vector<T>& v) {

	for (T valor : v)
		std::cout << valor << " ";
	
	std::cout << std::endl;
}


int main() {
	std::vector<int> v = {23,16,38,95,99,4,61,2,46,12,35};

	//std::vector<std::string> v = { "hola","adeu","miau","salut","guau" };
	std::cout << "Vector abans d'ordenar" << std::endl;
	mostraVector(v);
	
	quicksort(v);

	std::cout << "Vector després d'ordenar" << std::endl;
	mostraVector(v);

	int a = 5;
}