#pragma once
#include "String.h"
using namespace System;
using namespace System::Drawing;

class Casa
{
private:
	int poX;
	int poY;
	int w;
	int h;
	char* imagen;
	bool Alterado;
public:
	Casa();
	~Casa();
	void CambiarImagen(char* nombre_imagen);
	void mostrar(Graphics^ canvas);
	void cam_alt(bool _dt);

	int retornarX();
	int retornarY();
	int retornarw();
	int retornarh();

	bool retornar_Alterado();

};

Casa::Casa()
{
	Alterado = false;
	poX = 0;
	poY = 0;
	imagen = new char[30];
	CambiarImagen("Imagenes/casa.png");
}

Casa::~Casa()
{
}

void Casa::CambiarImagen(char* nombre_imagen)
{
	strcpy(imagen, nombre_imagen); //strcpy funcion para pasar datos de un string a otro

	   //cargar imagen(El sprite)
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	w = bitmap->Width;
	h = bitmap->Height;
	delete bitmap;

}
void Casa::mostrar(Graphics^ canvas)
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

int Casa::retornarX()
{
	return poX;
}
int Casa::retornarY()
{
	return poY;
}

int Casa::retornarw()
{
	return w;
}
int Casa::retornarh()
{
	return h;
}

bool Casa::retornar_Alterado()
{
	return Alterado;
}

void Casa::cam_alt(bool _dt)
{
	Alterado = _dt;
}