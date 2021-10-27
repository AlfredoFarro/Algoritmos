#pragma once

namespace ProyectofinalC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(int lvl)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			lvlE = lvl;
			
			if (lvlE == 1)
			{
				ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion1.png"));
			}
			else
			{
				ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion1A.png"));
			}
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btnpg3;
	private: System::Windows::Forms::Button^ btnpg2;
	private: System::Windows::Forms::Button^ btnpg1;
	private: System::Windows::Forms::Timer^ timerInstru;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Bitmap^ ins_fondo;
	private: System::Windows::Forms::Button^ btnGo;
		   int lvlE;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnpg3 = (gcnew System::Windows::Forms::Button());
			this->btnpg2 = (gcnew System::Windows::Forms::Button());
			this->btnpg1 = (gcnew System::Windows::Forms::Button());
			this->timerInstru = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnGo = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(703, 35);
			this->panel1->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel2->Controls->Add(this->btnGo);
			this->panel2->Controls->Add(this->btnpg3);
			this->panel2->Controls->Add(this->btnpg2);
			this->panel2->Controls->Add(this->btnpg1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 508);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(703, 35);
			this->panel2->TabIndex = 3;
			// 
			// btnpg3
			// 
			this->btnpg3->FlatAppearance->BorderSize = 9;
			this->btnpg3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnpg3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnpg3->Location = System::Drawing::Point(352, 9);
			this->btnpg3->Name = L"btnpg3";
			this->btnpg3->Size = System::Drawing::Size(28, 23);
			this->btnpg3->TabIndex = 6;
			this->btnpg3->Text = L"3";
			this->btnpg3->UseVisualStyleBackColor = true;
			this->btnpg3->Click += gcnew System::EventHandler(this, &Instrucciones::btnpg3_Click_1);
			// 
			// btnpg2
			// 
			this->btnpg2->FlatAppearance->BorderSize = 0;
			this->btnpg2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnpg2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnpg2->Location = System::Drawing::Point(318, 9);
			this->btnpg2->Name = L"btnpg2";
			this->btnpg2->Size = System::Drawing::Size(28, 23);
			this->btnpg2->TabIndex = 5;
			this->btnpg2->Text = L"2";
			this->btnpg2->UseVisualStyleBackColor = true;
			this->btnpg2->Click += gcnew System::EventHandler(this, &Instrucciones::btnpg2_Click);
			// 
			// btnpg1
			// 
			this->btnpg1->FlatAppearance->BorderSize = 0;
			this->btnpg1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnpg1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnpg1->Location = System::Drawing::Point(283, 9);
			this->btnpg1->Name = L"btnpg1";
			this->btnpg1->Size = System::Drawing::Size(29, 23);
			this->btnpg1->TabIndex = 4;
			this->btnpg1->Text = L"1";
			this->btnpg1->UseVisualStyleBackColor = true;
			this->btnpg1->Click += gcnew System::EventHandler(this, &Instrucciones::btnpg1_Click_1);
			// 
			// timerInstru
			// 
			this->timerInstru->Enabled = true;
			this->timerInstru->Interval = 500;
			this->timerInstru->Tick += gcnew System::EventHandler(this, &Instrucciones::timerInstru_Tick);
			// 
			// btnGo
			// 
			this->btnGo->FlatAppearance->BorderSize = 9;
			this->btnGo->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnGo->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnGo->Location = System::Drawing::Point(624, 9);
			this->btnGo->Name = L"btnGo";
			this->btnGo->Size = System::Drawing::Size(67, 23);
			this->btnGo->TabIndex = 7;
			this->btnGo->Text = L"GO";
			this->btnGo->UseVisualStyleBackColor = true;
			this->btnGo->Click += gcnew System::EventHandler(this, &Instrucciones::btnGo_Click);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->ClientSize = System::Drawing::Size(703, 543);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->Load += gcnew System::EventHandler(this, &Instrucciones::Instrucciones_Load);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Instrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		private: System::Void btnpg1_Click_1(System::Object^ sender, System::EventArgs^ e) 
			{
				if (lvlE == 1)
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion1.png"));
				}
				else
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion1A.png"));
				}
			}
		private: System::Void btnpg2_Click(System::Object^ sender, System::EventArgs^ e)
			{
				if (lvlE == 1)
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion2.png"));
				}
				else
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion2A.png"));
				}
			}
		private: System::Void btnpg3_Click_1(System::Object^ sender, System::EventArgs^ e) 
			{
				if (lvlE == 1)
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion3.png"));
				}
				else
				{
					ins_fondo = gcnew Bitmap(gcnew System::String("Imagenes/Instruccion3A.png"));
				}
			}
		private: System::Void timerInstru_Tick(System::Object^ sender, System::EventArgs^ e) 
			{
			Graphics^ Canvas = this->CreateGraphics();

			//se reserva memoria para el buffer
			BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

			//Creamos canvas dentro del espacio del buffer usando el canvas del formulario
			BufferedGraphics^ buffer = espacioBuffer->Allocate(Canvas, this->ClientRectangle);

			//A partir de aqui todos los dibujos se hacen en el canvas del buffer::BufferedGraphics^ buffer
			buffer->Graphics->DrawImage(ins_fondo, 0, 0, Rectangle(0, 0, this->Size.Width, this->Size.Height), GraphicsUnit::Pixel);
			buffer->Render(Canvas);
			delete buffer;
			delete espacioBuffer;
			delete Canvas;
			}
private: System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
};
}
