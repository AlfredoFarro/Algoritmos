#pragma once
#include "Juego2.h"
#include "FINALIZAR.h"
#include <time.h>

namespace ProyectofinalC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyFormN2
	/// </summary>
	public ref class MyFormN2 : public System::Windows::Forms::Form
	{
	public:
		MyFormN2(int N_A, int N_Ag, int N_Hab, int T_s)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Tiempo = T_s + clock() / 1000;
			Taux = 0;
			objeto_Juego2 = new Juego2(this->Size.Width, this->Size.Height, N_A, N_Ag, N_Hab);
			objeto_Juego2->Ag_NPC();
			//cargar el fondo
			fondo = gcnew Bitmap(gcnew System::String("Imagenes/Nivel2.png"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyFormN2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblT;
	protected:
	private: System::Windows::Forms::Label^ lblptj;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Label^ lblPuntaje;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Direccion TeclaPulsada;
		Juego2* objeto_Juego2;
		//para el fondo
		Bitmap^ fondo;
		//N_aliados, N_agentes, N_habitantes, tiempo
		int Tiempo;
		int Taux;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblT = (gcnew System::Windows::Forms::Label());
			this->lblptj = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->lblPuntaje = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// lblT
			// 
			this->lblT->AutoSize = true;
			this->lblT->Location = System::Drawing::Point(656, 9);
			this->lblT->Name = L"lblT";
			this->lblT->Size = System::Drawing::Size(0, 13);
			this->lblT->TabIndex = 7;
			// 
			// lblptj
			// 
			this->lblptj->AutoSize = true;
			this->lblptj->Location = System::Drawing::Point(548, 9);
			this->lblptj->Name = L"lblptj";
			this->lblptj->Size = System::Drawing::Size(13, 13);
			this->lblptj->TabIndex = 6;
			this->lblptj->Text = L"0";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(601, 9);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(48, 13);
			this->lblTiempo->TabIndex = 5;
			this->lblTiempo->Text = L"Tiempo: ";
			// 
			// lblPuntaje
			// 
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Location = System::Drawing::Point(495, 9);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Size = System::Drawing::Size(46, 13);
			this->lblPuntaje->TabIndex = 4;
			this->lblPuntaje->Text = L"Puntaje:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyFormN2::timer1_Tick);
			// 
			// MyFormN2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(703, 543);
			this->Controls->Add(this->lblT);
			this->Controls->Add(this->lblptj);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->lblPuntaje);
			this->Name = L"MyFormN2";
			this->Text = L"HELPIXEL";
			this->Load += gcnew System::EventHandler(this, &MyFormN2::MyFormN2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyFormN2::MyFormN2_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyFormN2::MyFormN2_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyFormN2_Load(System::Object^ sender, System::EventArgs^ e) 
	{
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		ofstream archivo("Puntaje.txt");
		archivo << objeto_Juego2->retornar_puntaje();
		//se crea el canvas
		Graphics^ Canvas = this->CreateGraphics();

		//se reserva memoria para el buffer
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

		//Creamos canvas dentro del espacio del buffer usando el canvas del formulario
		BufferedGraphics^ buffer = espacioBuffer->Allocate(Canvas, this->ClientRectangle);

		//A partir de aqui todos los dibujos se hacen en el canvas del buffer::BufferedGraphics^ buffer
		buffer->Graphics->DrawImage(fondo, 0, 0, Rectangle(0, 0, this->Size.Width, this->Size.Height), GraphicsUnit::Pixel);

		objeto_Juego2->MoverLider(buffer->Graphics, TeclaPulsada);
		objeto_Juego2->mostrar_casa(buffer->Graphics);
		objeto_Juego2->mostrar_camion(buffer->Graphics);
		objeto_Juego2->MoverAliado(buffer->Graphics);
		objeto_Juego2->MoverAgente(buffer->Graphics);
		objeto_Juego2->MoverHabitante(buffer->Graphics);
		lblptj->Text = objeto_Juego2->retornar_puntaje().ToString();
		lblT->Text = (Tiempo - clock() / 1000).ToString();
		if (Taux == 0)
		{
			Taux = Tiempo - clock() / 1000;
		}
		else
		{
			if (Taux - 30 == Tiempo - clock() / 1000)
			{
				if (objeto_Juego2->retornar_e_casa() == true || objeto_Juego2->retornar_e_camion() == true)
				{
					FINALIZAR^ objeto_finalizar = gcnew FINALIZAR(false);
					this->Visible = false;
					timer1->Enabled = false;
					objeto_finalizar->ShowDialog();
					delete objeto_finalizar;
					this->Close();
				}
				else
				{
					objeto_Juego2->Cambiar_e_casa(true);
					objeto_Juego2->cambiar_e_camion(true);
					Taux = 0;
				}
			}
		}
		if (objeto_Juego2->retornar_puntaje() > 100)
		{
			FINALIZAR^ objeto_finalizar = gcnew FINALIZAR(true);
			this->Visible = false;
			timer1->Enabled = false;
			objeto_finalizar->ShowDialog();
			delete objeto_finalizar;
			this->Close();
		}
		if (Tiempo - clock() / 1000 <= 0)
		{
			FINALIZAR^ objeto_finalizar = gcnew FINALIZAR(false);
			this->Visible = false;
			timer1->Enabled = false;
			objeto_finalizar->ShowDialog();
			delete objeto_finalizar;
			this->Close();
		}

		//lbl1->Text = objeto_Vec_Aliado->get_N().ToString();
		//dibujar en el formulario 
		buffer->Render(Canvas);

		//Eliminamos
		delete buffer;
		delete espacioBuffer;
		delete Canvas;
		archivo.close();
	}
	private: System::Void MyFormN2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		TeclaPulsada = Direccion::Ninguno;
		if (e->KeyCode == Keys::Up) TeclaPulsada = Direccion::Arriba;
		if (e->KeyCode == Keys::Down) TeclaPulsada = Direccion::Abajo;
		if (e->KeyCode == Keys::Right) TeclaPulsada = Direccion::Derecha;
		if (e->KeyCode == Keys::Left) TeclaPulsada = Direccion::Izquierda;
		objeto_Juego2->Cam_Dir_Lider(TeclaPulsada);
	}
	private: System::Void MyFormN2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		if (e->KeyChar == 'J' || e->KeyChar == 'j')
		{
			if (objeto_Juego2->Get_Can_Arr_Ali() < 4)
			{
				objeto_Juego2->Ag_Aliado();
			}
		}
		if (e->KeyChar == 'K' || e->KeyChar == 'k')
		{
			objeto_Juego2->Auxilio();
		}
	}
};
}
