#pragma once
#include "Personaje.h"

class Lider:public Personaje
{
protected:
	int Puntaje;
	bool Tener_cosas;
public:
	Lider ();
	~Lider ();
	void mover(Graphics^ canvas, Direccion Teclapulsada, int DW, int DH);
	void cambiar_dx_dy(Direccion Teclapulsada);
	void Set_Puntaje(int PPun);
	int Get_Puntaje();
	void cambiar_ten_cosas(bool dato);
	bool retornar_ten_cosas();
};

Lider ::Lider ():Personaje()
{
	Puntaje = 0;
	bool Tener_cosas = false;
	CambiarImagen("Imagenes/Lider2.png", 3, 4);
}

Lider ::~Lider ()
{
}

//void Lider::mover(Graphics^ canvas, Direccion Teclapulsada)
void Lider::mover(Graphics^ canvas, Direccion Teclapulsada, int DW, int DH)
{

		if (Teclapulsada == Direccion::Arriba)		indiceH = 3;
		if (Teclapulsada == Direccion::Izquierda)	indiceH = 1;
		if (Teclapulsada == Direccion::Abajo)		indiceH = 0;
		if (Teclapulsada == Direccion::Derecha)		indiceH = 2;

		indiceW++;
		if (indiceW >= 2) indiceW = 0;
		X += dx;
		//if (X < -18 || X>636) X -= dx;
		if (X < 0 || X>DW - 40) X -= dx;
		//if (Y<-15 || Y>434) Y -= dy;
		Y += dy;
		if (Y<0 || Y>DH - 70) Y -= dy;
	
	mostrar(canvas);
}

void Lider::cambiar_dx_dy(Direccion Teclapulsada)
{
	switch (Teclapulsada)
	{
	case Arriba: dx = 0; dy = -4;
		break;
	case Abajo: dx = 0; dy = 4;
		break;
	case Derecha: dx = 4; dy = 0;
		break;
	case Izquierda: dx = -4; dy = 0;
		break;
	case Ninguno: dx = 0; dy = 0;
		break;
	}
}

void Lider::Set_Puntaje(int PPun)
{
	Puntaje = Puntaje + PPun;
	if (Puntaje < 0) Puntaje = 0;
}
int Lider::Get_Puntaje()
{
	return Puntaje;
}

void Lider::cambiar_ten_cosas(bool dato)
{
	Tener_cosas = dato;
}
bool Lider::retornar_ten_cosas()
{
	return Tener_cosas;
}