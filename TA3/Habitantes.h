#pragma once
#include "Personaje.h"

class Habitante :public Personaje
{
protected:
	bool N_ayuda;
	int N_mov;
public:
	Habitante();
	~Habitante();
	void Pedir_Ayuda();
	void mover(Graphics^ canvas, int DW, int DH);
	void Pared();

	void T_caminar();
	void Cam_Estado_ayuda();
	bool get_N_ayuda();
};

Habitante::Habitante()
{
	Random^ r = gcnew Random();
	N_ayuda = false;
	N_mov = 0;
	if (r->Next(1, 50) < 24)
	{
		dx = 1;
	}
	else
	{
		dy = 1;
	}
	CambiarImagen("Imagenes/Habitante2.png", 3, 4);
}

Habitante::~Habitante()
{
}

void Habitante::mover(Graphics^ canvas, int DW, int DH)
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
	N_mov++;
	if (N_mov > 100)
	{
		T_caminar();
		N_mov = 0;
	}
	mostrar(canvas);
}

void Habitante::T_caminar()
{
	dx = dx * -1;
	dy = dy * -1;
}

void Habitante::Pedir_Ayuda()
{
	N_ayuda = true;
	CambiarImagen("Imagenes/Habitante2A.png", 3, 4);
}

bool Habitante::get_N_ayuda()
{
	return N_ayuda;
}

void Habitante::Cam_Estado_ayuda()
{
	N_ayuda = false;
	CambiarImagen("Imagenes/Habitante2.png", 3, 4);
}

void Habitante::Pared()
{
	dx = dx * -1;
	dy = dy * -1;
}