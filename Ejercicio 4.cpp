#include <iostream>
using namespace std;

void ordenarInsercion(int v[], int a, int b) {
	for (int i = a + 1; i <= b; i++) {
		int key = v[i];
		int j = i - 1;
		while (j >= a && v[j] > key) {
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = key;
	}
}

void particion2(int v[],int a, int b, int pivot, int&p, int&q) {
	int k{ 0 };
		int aux;

		while (k <= q)
		{
			if (v[k] == pivot) { k = k + 1; }
			else if (v[k] < pivot)
			{
				aux = v[p]; v[p] = v[k]; v[k] = aux;
				p = p + 1; k = k + 1;
			}
			else {
				aux = v[q]; v[q] = v[k]; v[k] = aux;
				q = q - 1;
			}
		}
}



int seleccion3(int v[], int a, int b, int k) {
	int l, p, q, s, pm, t;
	int aux, mm;
	t = b - a + 1;
	if (t <= 12)
	{
		ordenarInsercion(v, a, b); return v[k];
	}
	else
	{
		s = t / 5;
		for (l = 1; l <= s; l++)
		{
			ordenarInsercion(v, a + 5 * (l - 1), a + 5 * l - 1);
			pm = a + 5 * (l - 1) + (5 / 2);
			aux = v[a + l - 1];
			v[a + l - 1] = v[pm];
			v[pm] = aux;
		};
		mm = seleccion3(v, a, a + s - 1, a + (s - 1) / 2);
		particion2(v, a, b, mm, p, q);
		if ((k >= p) && (k <= q)) { return mm; }
		else if (k < p) { return seleccion3(v, a, p - 1, k); }
		else { return seleccion3(v, q + 1, b, k); }
	}
}

int main() {

	int v[20] = { 1,3,2,4,5,6,7,8,3,4,5,7,2,3,78,23,34,52,12,11 };
	int k = 1;


	int r = 0;
	r = seleccion3(v, 0, 20 - 1, k);
	cout << r << "\n";
}