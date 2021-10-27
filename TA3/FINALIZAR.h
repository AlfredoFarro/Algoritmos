#pragma once

namespace ProyectofinalC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FINALIZAR
	/// </summary>
	public ref class FINALIZAR : public System::Windows::Forms::Form
	{
	public:
		FINALIZAR(bool Gano)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			A_Gano = Gano;
			if (A_Gano == true)
			{
				lblFINAL->Visible = true;
				pX = lblFINAL->Location.X;
				pY = lblFINAL->Location.Y;
			}
			else
			{
				lblPerd->Visible = true;
				pX = lblPerd->Location.X;
				pY = lblPerd->Location.Y;
			}

			pXC = lblCred->Location.X;
			pYC = lblCred->Location.Y;

			pXN = lblCreador->Location.X;
			pYN = lblCreador->Location.Y;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FINALIZAR()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblFINAL;
	protected:
	private: System::Windows::Forms::Label^ lblCred;
	private: System::Windows::Forms::Label^ lblCreador;
	private: System::Windows::Forms::Timer^ timerFinal;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lblPerd;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		bool A_Gano;
		int pX, pXC, pXN;
		int pY, pYC, pYN;
	private: System::Windows::Forms::Button^ btnInicio;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FINALIZAR::typeid));
			this->lblFINAL = (gcnew System::Windows::Forms::Label());
			this->lblCred = (gcnew System::Windows::Forms::Label());
			this->lblCreador = (gcnew System::Windows::Forms::Label());
			this->timerFinal = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblPerd = (gcnew System::Windows::Forms::Label());
			this->btnInicio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblFINAL
			// 
			this->lblFINAL->AutoSize = true;
			this->lblFINAL->BackColor = System::Drawing::Color::Transparent;
			this->lblFINAL->Font = (gcnew System::Drawing::Font(L"Impact", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFINAL->ForeColor = System::Drawing::Color::ForestGreen;
			this->lblFINAL->Location = System::Drawing::Point(232, 384);
			this->lblFINAL->Name = L"lblFINAL";
			this->lblFINAL->Size = System::Drawing::Size(258, 80);
			this->lblFINAL->TabIndex = 0;
			this->lblFINAL->Text = L"GANASTE";
			this->lblFINAL->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblFINAL->Visible = false;
			// 
			// lblCred
			// 
			this->lblCred->AutoSize = true;
			this->lblCred->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblCred->Location = System::Drawing::Point(329, 497);
			this->lblCred->Name = L"lblCred";
			this->lblCred->Size = System::Drawing::Size(62, 13);
			this->lblCred->TabIndex = 1;
			this->lblCred->Text = L"Creado por:";
			this->lblCred->Visible = false;
			// 
			// lblCreador
			// 
			this->lblCreador->AutoSize = true;
			this->lblCreador->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->lblCreador->Location = System::Drawing::Point(257, 521);
			this->lblCreador->Name = L"lblCreador";
			this->lblCreador->Size = System::Drawing::Size(212, 13);
			this->lblCreador->TabIndex = 2;
			this->lblCreador->Text = L"Jara Benites Quique Vladimir (U202022365)";
			this->lblCreador->Visible = false;
			// 
			// timerFinal
			// 
			this->timerFinal->Enabled = true;
			this->timerFinal->Interval = 200;
			this->timerFinal->Tick += gcnew System::EventHandler(this, &FINALIZAR::timerFinal_Tick);
			// 
			// lblPerd
			// 
			this->lblPerd->AutoSize = true;
			this->lblPerd->BackColor = System::Drawing::Color::Transparent;
			this->lblPerd->Font = (gcnew System::Drawing::Font(L"Impact", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPerd->ForeColor = System::Drawing::Color::Red;
			this->lblPerd->Location = System::Drawing::Point(232, 384);
			this->lblPerd->Name = L"lblPerd";
			this->lblPerd->Size = System::Drawing::Size(270, 80);
			this->lblPerd->TabIndex = 3;
			this->lblPerd->Text = L"PERDISTE";
			this->lblPerd->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblPerd->Visible = false;
			// 
			// btnInicio
			// 
			this->btnInicio->BackColor = System::Drawing::Color::Black;
			this->btnInicio->FlatAppearance->BorderSize = 9;
			this->btnInicio->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Silver;
			this->btnInicio->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnInicio->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnInicio->Location = System::Drawing::Point(305, 358);
			this->btnInicio->Name = L"btnInicio";
			this->btnInicio->Size = System::Drawing::Size(111, 23);
			this->btnInicio->TabIndex = 7;
			this->btnInicio->Text = L"VOLVER AL MENU";
			this->btnInicio->UseVisualStyleBackColor = false;
			this->btnInicio->Visible = false;
			this->btnInicio->Click += gcnew System::EventHandler(this, &FINALIZAR::btnpg3_Click);
			// 
			// FINALIZAR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(703, 543);
			this->Controls->Add(this->btnInicio);
			this->Controls->Add(this->lblPerd);
			this->Controls->Add(this->lblCreador);
			this->Controls->Add(this->lblCred);
			this->Controls->Add(this->lblFINAL);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FINALIZAR";
			this->Text = L"FINALIZAR";
			this->Load += gcnew System::EventHandler(this, &FINALIZAR::FINALIZAR_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FINALIZAR_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void timerFinal_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
	Graphics^ Canvas = this->CreateGraphics();

	//se reserva memoria para el buffer
	BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

	//Creamos canvas dentro del espacio del buffer usando el canvas del formulario
	BufferedGraphics^ buffer = espacioBuffer->Allocate(Canvas, this->ClientRectangle);

	//A partir de aqui todos los dibujos se hacen en el canvas del buffer::BufferedGraphics^ buffer
	
	if (A_Gano == true)
	{
		if (pY >= 160)
		{
			lblFINAL->Location = Point(pX, pY - 4);
			pY = lblFINAL->Location.Y;
		}
		else
		{	
			if (lblCreador->Visible == false)
			{
				lblCred->Visible = true;
				lblCreador->Visible = true;
			}
			if (pYC >= 269)
			{
				lblCred->Location = Point(pXC, pYC - 4);
				pYC = lblCred->Location.Y;
				lblCreador->Location = Point(pXN, pYN - 4);
				pYN = lblCreador->Location.Y;
			}
			else
			{
				timerFinal->Enabled = false;
				btnInicio->Visible = true;
			}
		}
	}
	else
	{
		if (pY >= 160)
		{
			lblPerd->Location = Point(pX, pY - 4);
			pY = lblPerd->Location.Y;
		}
		else
		{
			if(lblCreador->Visible==false)
			{
				lblCred->Visible = true;
				lblCreador->Visible = true;
			}

			if (pYC >= 269)
			{
				lblCred->Location = Point(pXC, pYC - 4);
				pYC = lblCred->Location.Y;
				lblCreador->Location = Point(pXN, pYN - 4);
				pYN = lblCreador->Location.Y;
			}
			else
			{
				timerFinal->Enabled = false;
				btnInicio->Visible = true;
			}
		}
	}
	
	buffer->Render(Canvas);
	delete buffer;
	delete espacioBuffer;
	delete Canvas;
	}
private: System::Void btnpg3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
};
}
