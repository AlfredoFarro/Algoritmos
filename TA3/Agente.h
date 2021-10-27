#pragma once
#include "Personaje.h"

class Agente:public Personaje
{
protected:
	bool E_Cerca;
	bool Ocupado;
	int indice_aliado;
	int canAl;
public:
	Agente();
	~Agente();
	void mover(Graphics^ canvas, int DW, int DH);
	void Det_Cer(bool dt);
	void cam_Ocupado(bool _dt);
	void Pared();
	void cam_in_al(int indice, int can_al);
	bool Get_Ocu();
	int get_in_al();
	int get_canAl();

};

Agente::Agente()
{
	Random^ r = gcnew Random();
	E_Cerca = false;
	Ocupado = false;
	if (r->Next(1, 50) < 24)
	{
		dx = 1;
	}
	else
	{
		dy = 1;
	}
	CambiarImagen("Imagenes/Agente2.png", 3, 4);
}

Agente::~Agente()
{
}

void Agente::mover(Graphics^ canvas, int DW, int DH)
{
	if (E_Cerca == false)
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
		if (X < 0 || X>DW - 40) dx = dx * -1;
		Y += dy;
		if (Y < 0 || Y>DH - 70) dy = dy * -1;

	}
	mostrar(canvas);
}

void Agente::Det_Cer(bool dt)
{
	E_Cerca = dt;
}

void Agente::Pared()
{
	dx = dx * -1;
	dy = dy * -1;
}

void Agente::cam_Ocupado(bool _dt)
{
	Ocupado = _dt;
}

bool Agente::Get_Ocu()
{
	return Ocupado;
}

void Agente::cam_in_al(int indice, int can_al)
{
	indice_aliado = indice;
	canAl = can_al;
}

int Agente::get_in_al()
{
	return indice_aliado;
}

int Agente::get_canAl()
{
	return canAl;
}