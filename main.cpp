// =================================================================
//
// File: main.cpp
// Author: Sven Chavez Garcia 
// Date: 2 de septiembre del 2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "fstream"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream entrada_txt;
	ofstream salida_txt;

	entrada_txt.open(argv[1], ios::in);
	salida_txt.open(argv[2], ios::out);

	if (argc != 3){
		return -1;
	}

	else if (entrada_txt.fail() || salida_txt.fail()){
		std::cout << "no se pudo abrir alguno de los textos...";
		return -1;
	}

	int n, num, q;
	entrada_txt >> n;

	vector <int> arreglo(n);

	for(int i = 0; i < n; i++){
		entrada_txt >> num;
		arreglo[i] = num;
	}

	vector <int> auxiliar = arreglo;
	vector <int> auxiliar2 = arreglo;

	salida_txt << bubbleSort(arreglo) << ' ' << selectionSort(auxiliar) << ' ' << insertionSort(auxiliar2) << ' '<<endl<<endl;

	entrada_txt >> q;
	pair <int, int> respuestas;

	for (int i = 0; i < q; i++){
		entrada_txt >> num;
		respuestas = sequentialSearch(arreglo, num);
		salida_txt << respuestas.first << ' ' << respuestas.second << ' ';
		respuestas = binarySearch(arreglo, num);
		salida_txt << respuestas.second<<endl;
	}

	entrada_txt.close();
	salida_txt.close();

	return 0;
}