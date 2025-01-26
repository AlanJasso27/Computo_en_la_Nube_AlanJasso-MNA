// Tarea1_programacion_paralela.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>


#define N 10000
#define chunk 700
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
		{
			a[i] = i * 30;
			b[i] = (i + 3.4) * 5.3;
		}
	int pedazos = chunk;

	// original: N=1000, chunk=100, mostrar=10 y a[i]=i*10 & b[i]=(i + 3) * 3.7

	// segunda prueba se cambió para N=1500, chunk=200, mostrar=5 y a[i]=i*25 & b[i]=(i + 5) * 4

	// tercera prueba se cambió N=4500, chunk=500, mostrar=10 y a[i]=i*19 & b[i]=(i + 4.5) * 8

	// cuarta prueba se cambió N=10000, chunk=700, mostrar=10 y a[i]=i*30 & b[i]=(i + 3.4) * 5.3


	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}

void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
