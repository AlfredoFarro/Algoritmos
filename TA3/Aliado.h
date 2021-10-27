#pragma once
#include "Personaje.h"

class Aliado:public Personaje
{
protected:
	bool Ocupado;
	int indice_Habitante, CANT;
public:
	Aliado();
	~Aliado();
	void mover(Graphics^ canvas, int DW, int DH);

	void Pared();
	void cam_Ocupado(bool _dt);
	void cam_in_Ha(int indice, int can);
	bool Get_Ocu();
	int get_in_al();
	int get_N_ha();
};

Aliado::Aliado()
{
	Random^ r = gcnew Random();
	Ocupado = false;
	if (r->Next(1, 50) < 24)
	{
		dx = 1;
	}
	else
	{
		dy = 1;
	}
	CambiarImagen("Imagenes/Aliado2.png", 3, 4);
}

Aliado::~Aliado()
{
}

void Aliado::mover(Graphics^ canvas, int DW, int DH)
{
	if (dx == 0 && dy < 0) indiceH = 3; //arriba
	if (dx < 0 && dy == 0) indiceH = 1; //izquierda
	if (dx == 0 && dy > 0) indiceH = 0; //abajo 
	if (dx > 0 && dy == 0) indiceH = 2;  //derecha

	if (dx < 0 && dy < 0) indiceH = 3;
	if (dx > 0 && dy < 0) indiceH = 3;
	if (dx < 0 && dy > 0) indiceH = 0;
	if (dx > 0 && dy > 0) indiceH = 0;

	indiceW++;
	if (indiceW >= 3) indiceW = 0;
	X += dx;
	if (X < 0 || X>DW-40) dx = dx * -1;
	Y += dy;
	if (Y < 0 || Y>DH-70) dy = dy * -1;

	mostrar(canvas);
}

void Aliado::cam_Ocupado(bool _dt)
{
	Ocupado = _dt;
}
void Aliado::cam_in_Ha(int indice, int can)
{
	indice_Habitante = indice;
	CANT = can;
}
bool Aliado::Get_Ocu()
{
	return Ocupado;
}
int Aliado::get_in_al()
{
	return indice_Habitante;
}
int Aliado::get_N_ha()
{
	return CANT;
}
void Aliado::Pared()
{
	dx = dx * -1;
	dy = dy * -1;
}