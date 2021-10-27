#pragma once
#include "String.h"
using namespace System;
using namespace System::Drawing;

class camion
{
private:
	int poX;
	int poY;
	int w;
	int h;
	char* imagen;
	bool Alte;
public:
	camion();
	~camion();
	void CambiarImagen(char* nombre_imagen);
	void mostrar(Graphics^ canvas);
	void cam_Alt(bool dt);

	int retornarX();
	int retornarY();
	int retornarw();
	int retornarh();
	bool retornarAlt();

};

camion::camion()
{
	Alte = false;
	poX = 570;
	poY = 470;
	imagen = new char[30];
	CambiarImagen("Imagenes/camion.png");
}

camion::~camion()
{
}

void camion::CambiarImagen(char* nombre_imagen)
{
	strcpy(imagen, nombre_imagen); //strcpy funcion para pasar datos de un string a otro

	   //cargar imagen(El sprite)
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	w = bitmap->Width;
	h = bitmap->Height;
	delete bitmap;

}
void camion::mostrar(Graphics^ canvas)
{
	//cargar imagen(El sprite)
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	//Se obtiene el frame o la porcion 
	Rectangle frame = Rectangle(0 * w, 0 * h, w, h);
	//X			, Y		, ancho, alto

//Para hacer un zoom a la imagen
	Rectangle zoom = Rectangle(poX, poY, w * 1, h * 1);

	//dibuja el frame en el canvas
	canvas->DrawImage(bitmap, zoom, frame, GraphicsUnit::Pixel);
}

int camion::retornarX()
{
	return poX;
}
int camion::retornarY()
{
	return poY;
}

int camion::retornarw()
{
	return w;
}
int camion::retornarh()
{
	return h;
}

bool camion::retornarAlt()
{
	return Alte;
}

void camion::cam_Alt(bool dt)
{
	Alte = dt;
}