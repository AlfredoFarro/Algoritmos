#pragma once
#include "Casa.h"
#include "camion.h"
#include "Lider.h"
#include "Agente.h"
#include "Aliado.h"
#include "Habitantes.h"
#include"Vector.h"

bool ColisionDistancia2(int obj1X, int obj1Y, int obj1A, int obj1L, int obj2X, int obj2Y, int obj2A, int obj2L, int dist)
{
	float px = pow((obj1X + obj1A / 2) - (obj2X + obj2A / 2), 2.0);
	float py = pow((obj1Y + obj1L / 2) - (obj2Y + obj2L / 2), 2.0);
	return  sqrt(px + py) < dist;
}

bool ColisionUsando_BoundingBox2(int obj1X, int obj1Y, int obj1A,
	int obj1L, int obj2X, int obj2Y, int obj2A, int obj2L)
{
	return (obj1X + obj1A > obj2X && obj1X < obj2X + obj2A && obj1Y + obj1L > obj2Y
		&& obj1Y < obj2Y + obj2L);
}

class Juego2
{
private:
	int DW;
	int DH;
	int NumA, NumAg, NumHa;
	Casa* objeto_casa;
	camion* objeto_camion;
	Lider* ObjetoLider;
	Agente* ObjetoAgente;
	Aliado* ObjetoAliado;
	Habitante* ObjetoHabitante;
	Vector<Aliado>* objeto_Vec_Aliado;
	Vector<Agente>* objeto_Vec_Agente;
	Vector<Habitante>* objeto_Vec_Habitantes;
public:
	Juego2(int _DW, int _DH, int N_A, int N_Ag, int N_Hab);
	~Juego2();

	void MoverLider(Graphics^ canvas, Direccion Teclapulsada);
	void Cam_Dir_Lider(Direccion Teclapulsada);

	void mostrar_casa(Graphics^ canvas);
	void Cambiar_e_casa(bool dato);
	void mostrar_camion(Graphics^ canvas);
	void cambiar_e_camion(bool dato);
	bool retornar_e_casa();
	bool retornar_e_camion();

	void Ag_NPC();
	void Ag_Aliado();

	void MoverAliado(Graphics^ canvas);
	int Get_Can_Arr_Ali();

	void MoverAgente(Graphics^ canvas);

	void MoverHabitante(Graphics^ canvas);
	void Auxilio();

	int retornar_puntaje();
};


Juego2::Juego2(int _DW, int _DH, int N_A, int N_Ag, int N_Hab)
{
	DW = _DW;
	DH = _DH;
	NumA = N_A;
	NumAg = N_Ag;
	NumHa = N_Hab;
	ObjetoLider = new Lider();
	objeto_casa = new Casa();
	objeto_casa->CambiarImagen("Imagenes/Hospital.png");
	objeto_camion = new camion();

	objeto_Vec_Aliado = new Vector<Aliado>;
	objeto_Vec_Agente = new Vector<Agente>();
	objeto_Vec_Habitantes = new Vector<Habitante>();
}

Juego2::~Juego2()
{
}

void Juego2::MoverLider(Graphics^ canvas, Direccion Teclapulsada)
{
	ObjetoLider->mover(canvas, Teclapulsada, DW, DH);
	if (objeto_casa->retornar_Alterado() == true)
	{
		if (ColisionDistancia2(ObjetoLider->retornarX(), ObjetoLider->retornarY(), ObjetoLider->retornarW(), ObjetoLider->retornarH(), objeto_casa->retornarX(),
			objeto_casa->retornarY(), objeto_casa->retornarw(), objeto_casa->retornarh(), 50))
		{
			if (ObjetoLider->retornar_ten_cosas() == true)
			{
				objeto_casa->CambiarImagen("Imagenes/Hospital.png");
				objeto_casa->cam_alt(false);
				ObjetoLider->cambiar_ten_cosas(false);
			}
		}
	}

	if (objeto_camion->retornarAlt() == true)
	{
		if (ColisionDistancia2(ObjetoLider->retornarX(), ObjetoLider->retornarY(), ObjetoLider->retornarW(), ObjetoLider->retornarH(), objeto_camion->retornarX(),
			objeto_camion->retornarY(), objeto_camion->retornarw(), objeto_camion->retornarh(), 50))
		{
			objeto_camion->CambiarImagen("Imagenes/camion.png");
			objeto_camion->cam_Alt(false);
			ObjetoLider->cambiar_ten_cosas(true);
		}
	}
}

void Juego2::Cam_Dir_Lider(Direccion Teclapulsada)
{
	ObjetoLider->cambiar_dx_dy(Teclapulsada);
}

void Juego2::mostrar_casa(Graphics^ canvas)
{
	objeto_casa->mostrar(canvas);
}
void Juego2::Cambiar_e_casa(bool dato)
{
	objeto_casa->CambiarImagen("Imagenes/HospitalA.png");
	objeto_casa->cam_alt(dato);
}
bool Juego2::retornar_e_casa()
{
	return objeto_casa->retornar_Alterado();
}
void Juego2::mostrar_camion(Graphics^ canvas)
{
	objeto_camion->mostrar(canvas);
}
void Juego2::cambiar_e_camion(bool dato)
{
	objeto_camion->CambiarImagen("Imagenes/camionA.png");
	objeto_camion->cam_Alt(dato);
}
bool Juego2::retornar_e_camion()
{
	return objeto_camion->retornarAlt();
}

void Juego2::Ag_NPC()
{
	Random^ R = gcnew Random();
	ObjetoLider->CambiarX(R->Next(5, DW - 100));
	ObjetoLider->CambiarY(R->Next(5, DH - 100));
	for (int i = 0; i < NumA; i++)
	{
		ObjetoAliado = new Aliado();
		ObjetoAliado->CambiarImagen("Imagenes/Aliado.png", 3, 4);
		ObjetoAliado->CambiarX(R->Next(5, DW - 60));
		ObjetoAliado->CambiarY(R->Next(180, DH - 150));
		objeto_Vec_Aliado->Agregar(ObjetoAliado);
		System::Threading::Thread::Sleep(30);
	}
	for (int i = 0; i < NumAg; i++)
	{
		ObjetoAgente = new Agente();
		ObjetoAgente->CambiarX(R->Next(5, DW - 100));
		ObjetoAgente->CambiarY(R->Next(130, DH - 150));
		objeto_Vec_Agente->Agregar(ObjetoAgente);
		System::Threading::Thread::Sleep(30);
	}
	for (int i = 0; i < NumHa; i++)
	{
		ObjetoHabitante = new Habitante();
		ObjetoHabitante->CambiarX(R->Next(5, DW - 100));
		ObjetoHabitante->CambiarY(R->Next(120, DH - 150));
		objeto_Vec_Habitantes->Agregar(ObjetoHabitante);
		System::Threading::Thread::Sleep(30);
	}
}

void Juego2::Ag_Aliado()
{
	Random^ R = gcnew Random();
	ObjetoAliado = new Aliado();
	ObjetoAliado->CambiarImagen("Imagenes/Aliado.png", 3, 4);
	ObjetoAliado->CambiarX(R->Next(5, DW - 60));
	ObjetoAliado->CambiarY(R->Next(180, DH - 150));
	objeto_Vec_Aliado->Agregar(ObjetoAliado);
	for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
	{
		ObjetoAgente = objeto_Vec_Agente->get(i);
		ObjetoAgente->cam_Ocupado(false);
	}
}

void Juego2::MoverAliado(Graphics^ canvas)
{
	if (objeto_Vec_Aliado->get_N() > 0)
	{
		for (int i = 0; i < objeto_Vec_Aliado->get_N(); i++)
		{
			ObjetoAliado = objeto_Vec_Aliado->get(i);

			for (int j = 0; j < objeto_Vec_Habitantes->get_N(); j++)
			{
				ObjetoHabitante = objeto_Vec_Habitantes->get(j);
				if (ObjetoHabitante->get_N_ayuda() == true)
				{
					if (ObjetoAliado->Get_Ocu() == false)
					{
						if (ColisionDistancia2(ObjetoAliado->retornarX(), ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), ObjetoHabitante->retornarX(),
							ObjetoHabitante->retornarY(), ObjetoHabitante->retornarW(), ObjetoHabitante->retornarH(), 300))
						{
							ObjetoAliado->cam_Ocupado(true);
							ObjetoAliado->cam_in_Ha(j, objeto_Vec_Aliado->get_N());
						}
					}
					else
					{
						ObjetoHabitante = objeto_Vec_Habitantes->get(ObjetoAliado->get_in_al());
						if (ObjetoAliado->get_N_ha() == objeto_Vec_Aliado->get_N())
						{
							if (ColisionDistancia(ObjetoAliado->retornarX(), ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), ObjetoHabitante->retornarX(),
								ObjetoHabitante->retornarY(), ObjetoHabitante->retornarW(), ObjetoHabitante->retornarH(), 300))
							{
								if (ObjetoAliado->retornarX() < ObjetoHabitante->retornarX())
								{
									ObjetoAliado->Cambiardx(1);
								}
								else
								{
									ObjetoAliado->Cambiardx(-1);
								}

								if (ObjetoAliado->retornarY() < ObjetoHabitante->retornarY())
								{
									ObjetoAliado->Cambiardy(1);
								}
								else
								{
									ObjetoAliado->Cambiardy(-1);
								}

								if (ObjetoAliado->retornarX() == ObjetoHabitante->retornarX()) ObjetoAliado->Cambiardx(0);
								if (ObjetoAliado->retornarY() == ObjetoHabitante->retornarY()) ObjetoAliado->Cambiardy(0);

								if (ColisionDistancia(ObjetoAliado->retornarX(), ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), ObjetoHabitante->retornarX(),
									ObjetoHabitante->retornarY(), ObjetoHabitante->retornarW(), ObjetoHabitante->retornarH(), 15))
								{
									ObjetoAliado->cam_Ocupado(false);
									ObjetoAliado->CambiarX(600);
									ObjetoAliado->CambiarY(400);
									ObjetoHabitante->Cam_Estado_ayuda();
									ObjetoLider->Set_Puntaje(10);
									for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
									{
										ObjetoAgente = objeto_Vec_Agente->get(i);
										ObjetoAgente->cam_Ocupado(false);
									}
								}
							}
							else
							{
								for (int i = 0; i < objeto_Vec_Aliado->get_N(); i++)
								{
									ObjetoAliado = objeto_Vec_Aliado->get(i);
									ObjetoAliado->cam_Ocupado(false);
								}
							}
						}
						else
						{
							for (int i = 0; i < objeto_Vec_Aliado->get_N(); i++)
							{
								ObjetoAliado = objeto_Vec_Aliado->get(i);
								ObjetoAliado->cam_Ocupado(false);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < objeto_Vec_Aliado->get_N(); i++)
		{
			ObjetoAliado = objeto_Vec_Aliado->get(i);
			if (ColisionUsando_BoundingBox2(ObjetoAliado->retornarX(), ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), objeto_casa->retornarX(),
				objeto_casa->retornarY(), objeto_casa->retornarw(), objeto_casa->retornarh()) || ColisionUsando_BoundingBox2(ObjetoAliado->retornarX(), ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), objeto_camion->retornarX(),
					objeto_camion->retornarY(), objeto_camion->retornarw(), objeto_camion->retornarh()))
			{
				ObjetoAliado->Pared();
			}
			ObjetoAliado->mover(canvas, DW, DH);
		}
	}
}

void Juego2::MoverAgente(Graphics^ canvas)
{
	if (objeto_Vec_Agente->get_N() > 0)
	{
		if (objeto_Vec_Aliado->get_N() > 0)
		{
			for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
			{
				ObjetoAgente = objeto_Vec_Agente->get(i);
				for (int j = 0; j < objeto_Vec_Aliado->get_N(); j++)
				{
					ObjetoAliado = objeto_Vec_Aliado->get(j);
					if (ObjetoAgente->Get_Ocu() == false)
					{
						if (ColisionDistancia2(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), ObjetoAliado->retornarX(),
							ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), 150))
						{
							ObjetoAgente->cam_Ocupado(true);
							ObjetoAgente->cam_in_al(j, objeto_Vec_Aliado->get_N());
						}
					}
					else
					{
						ObjetoAliado = objeto_Vec_Aliado->get(ObjetoAgente->get_in_al());
						if (ObjetoAgente->get_canAl() == objeto_Vec_Aliado->get_N())
						{
							if (ColisionDistancia2(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), ObjetoAliado->retornarX(),
								ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), 150))
							{
								if (ObjetoAgente->retornarX() < ObjetoAliado->retornarX())
								{
									ObjetoAgente->Cambiardx(1);
								}
								else
								{
									ObjetoAgente->Cambiardx(-1);
								}

								if (ObjetoAgente->retornarY() < ObjetoAliado->retornarY())
								{
									ObjetoAgente->Cambiardy(1);
								}
								else
								{
									ObjetoAgente->Cambiardy(-1);
								}

								if (ObjetoAgente->retornarX() == ObjetoAliado->retornarX())	ObjetoAgente->Cambiardx(0);
								if (ObjetoAgente->retornarY() == ObjetoAliado->retornarY()) ObjetoAgente->Cambiardy(0);

								if (ColisionDistancia(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), ObjetoAliado->retornarX(),
									ObjetoAliado->retornarY(), ObjetoAliado->retornarW(), ObjetoAliado->retornarH(), 15))
								{
									objeto_Vec_Aliado->Eliminar(ObjetoAgente->get_in_al());
									ObjetoLider->Set_Puntaje(-5);
									for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
									{
										ObjetoAgente = objeto_Vec_Agente->get(i);
										ObjetoAgente->cam_Ocupado(false);
									}
								}
							}
							else
							{
								for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
								{
									ObjetoAgente = objeto_Vec_Agente->get(i);
									ObjetoAgente->cam_Ocupado(false);
								}
							}
						}
						else
						{
							for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
							{
								ObjetoAgente = objeto_Vec_Agente->get(i);
								ObjetoAgente->cam_Ocupado(false);
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < objeto_Vec_Agente->get_N(); i++)
		{
			ObjetoAgente = objeto_Vec_Agente->get(i);
			if (ColisionDistancia2(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), ObjetoLider->retornarX(),
				ObjetoLider->retornarY(), ObjetoLider->retornarW(), ObjetoLider->retornarH(), 15))

			{
				ObjetoAgente->Det_Cer(true);
			}
			else
			{
				ObjetoAgente->Det_Cer(false);
			}

			if (ColisionUsando_BoundingBox2(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), objeto_casa->retornarX(),
				objeto_casa->retornarY(), objeto_casa->retornarw(), objeto_casa->retornarh()) || ColisionUsando_BoundingBox2(ObjetoAgente->retornarX(), ObjetoAgente->retornarY(), ObjetoAgente->retornarW(), ObjetoAgente->retornarH(), objeto_camion->retornarX(),
					objeto_camion->retornarX(), objeto_camion->retornarw(), objeto_camion->retornarh()))
			{
				ObjetoAgente->Pared();
			}
			ObjetoAgente->mover(canvas, DW, DH);
		}
	}
}

void Juego2::MoverHabitante(Graphics^ canvas)
{
	if (objeto_Vec_Habitantes->get_N() > 0)
	{
		for (int i = 0; i < objeto_Vec_Habitantes->get_N(); i++)
		{
			ObjetoHabitante = objeto_Vec_Habitantes->get(i);
			if (ColisionUsando_BoundingBox2(ObjetoHabitante->retornarX(), ObjetoHabitante->retornarY(), ObjetoHabitante->retornarW(), ObjetoHabitante->retornarH(), objeto_casa->retornarX(),
				objeto_casa->retornarY(), objeto_casa->retornarw(), objeto_casa->retornarh()) || ColisionUsando_BoundingBox2(ObjetoHabitante->retornarX(), ObjetoHabitante->retornarY(), ObjetoHabitante->retornarW(), ObjetoHabitante->retornarH(), objeto_camion->retornarX(),
					objeto_camion->retornarX(), objeto_camion->retornarw(), objeto_camion->retornarh()))
			{
				ObjetoHabitante->Pared();
			}
			ObjetoHabitante->mover(canvas, DW, DH);
		}
	}
}

int Juego2::Get_Can_Arr_Ali()
{
	return objeto_Vec_Aliado->get_N();
}

void Juego2::Auxilio()
{
	Random^ R = gcnew Random();
	int in_aux = R->Next(0, objeto_Vec_Habitantes->get_N());
	ObjetoHabitante = objeto_Vec_Habitantes->get(in_aux);
	ObjetoHabitante->Pedir_Ayuda();
}

int Juego2::retornar_puntaje()
{
	return ObjetoLider->Get_Puntaje();
}