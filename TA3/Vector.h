#pragma once
#include <vector>

using namespace std;

template <typename Tipo>

class Vector 
{
protected:
	vector<Tipo*>arr;
public:
	Vector() { arr = vector<Tipo*>(); };
	~Vector() {};
	void Agregar(Tipo* dato) { arr.push_back(dato); };
	void Eliminar(int indice) { arr.erase(arr.begin() + indice); };
	Tipo* get(int indice) { return arr.at(indice); };
	int get_N() { return arr.size(); };
};


