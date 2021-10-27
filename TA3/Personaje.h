#pragma once
#include "String.h"
using namespace System;
using namespace System::Drawing;
enum Direccion { Arriba, Abajo, Derecha, Izquierda, Ninguno};

class Personaje
{
protected:
	int X;
	int Y;
	int dx;
	int dy;
	int H;
	int W;
	int indiceH, indiceW;
	char* imagen;

public:
	Personaje();
	~Personaje();
	//metodos
	void CambiarImagen(char* nombre_imagen, int ncol, int nfil);
	void mostrar(Graphics^ canvas);

	//Metodos Get y Set
	void CambiarY(int valor);
	void CambiarX(int valor);
	void CambiarH(int valor);
	void CambiarW(int valor);
	void CambiarIndiceH(int valor);
	void CambiarIndiceW(int valor);
	void Cambiardx(int dato);
	void Cambiardy(int dato);

	int retornarX();
	int retornarY();
	int retornardx();
	int retornardy();
	int retornarW();
	int retornarH();
	int retornarIndiceW();
	int retornarIndiceH();
};

Personaje::Personaje()
{
	X = 0;
	Y = 0;
	dx = 0;
	dy = 0;
	H = 0;
	W = 0;
	indiceH = indiceW = 0;
	imagen = new char[30];//para el nombre del sprite
}

Personaje::~Personaje()
{
}

void Personaje::CambiarImagen(char* nombre_imagen, int ncol, int nfil) //solo se copia la ruta donde se encuentra la imagen
{
	strcpy(imagen, nombre_imagen); //strcpy funcion para pasar datos de un string a otro

	//cargar imagen(El sprite)
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	//se obtiene las dimensiones de la imagen(sprite)
	W = bitmap->Width / ncol;
	H = bitmap->Height / nfil;
	// W y H tienen la dimension de cada frame 

	delete bitmap;
}

void Personaje::mostrar(Graphics^ canvas)
{
	//cargar imagen(El sprite)
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	//Se obtiene el frame o la porcion 
	Rectangle frame = Rectangle(indiceW * W, indiceH * H, W, H);
	//X			, Y		, ancho, alto

//Para hacer un zoom a la imagen
	Rectangle zoom = Rectangle(X, Y, W * 1, H * 1);

	//dibuja el frame en el canvas
	canvas->DrawImage(bitmap, zoom, frame, GraphicsUnit::Pixel);

}

void Personaje::CambiarY(int valor) { Y = valor; }
void Personaje::CambiarX(int valor) { X = valor; }
void Personaje::CambiarH(int valor) { H = valor; }
void Personaje::CambiarW(int valor) { W = valor; }
void Personaje::CambiarIndiceH(int valor) { indiceH = valor; }
void Personaje::CambiarIndiceW(int valor) { indiceW = valor; }
void Personaje::Cambiardx(int dato) { dx = dato; }
void Personaje::Cambiardy(int dato) { dy = dato; }

int Personaje::retornarX() { return X; }
int Personaje::retornarY() { return Y; }
int Personaje::retornardx() { return dx; }
int Personaje::retornardy() { return dy; }
int Personaje::retornarW() { return W; }
int Personaje::retornarH() { return H; }
int Personaje::retornarIndiceW() { return indiceW; }
int Personaje::retornarIndiceH() { return indiceH; }
