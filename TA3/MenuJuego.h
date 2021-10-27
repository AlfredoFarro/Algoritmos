#pragma once
#include "MyForm.h"
#include "MyFormN2.h"
#include "String.h"
#include "Instrucciones.h"
using namespace System;
using namespace System::Drawing;

namespace ProyectofinalC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuJuego
	/// </summary>
	public ref class MenuJuego : public System::Windows::Forms::Form
	{
	public:
		MenuJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			im_Fondo = gcnew Bitmap(gcnew System::String("Imagenes/menu.png"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ NumUDTime;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblHabi;
	private: System::Windows::Forms::Label^ lblAge;
	private: System::Windows::Forms::Label^ lblAli;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::NumericUpDown^ NumUDAli;
	private: System::Windows::Forms::NumericUpDown^ NumUDAge;
	private: System::Windows::Forms::NumericUpDown^ NumUDHabi;

	protected:



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		//fondo
		Bitmap^ im_Fondo;
	private: System::Windows::Forms::Timer^ timerMenu;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ lblLVL;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuJuego::typeid));
			this->NumUDTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblHabi = (gcnew System::Windows::Forms::Label());
			this->lblAge = (gcnew System::Windows::Forms::Label());
			this->lblAli = (gcnew System::Windows::Forms::Label());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->NumUDAli = (gcnew System::Windows::Forms::NumericUpDown());
			this->NumUDAge = (gcnew System::Windows::Forms::NumericUpDown());
			this->NumUDHabi = (gcnew System::Windows::Forms::NumericUpDown());
			this->timerMenu = (gcnew System::Windows::Forms::Timer(this->components));
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblLVL = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDAli))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDAge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDHabi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// NumUDTime
			// 
			this->NumUDTime->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumUDTime->Location = System::Drawing::Point(571, 247);
			this->NumUDTime->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->NumUDTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->NumUDTime->Name = L"NumUDTime";
			this->NumUDTime->Size = System::Drawing::Size(120, 20);
			this->NumUDTime->TabIndex = 18;
			this->NumUDTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(568, 221);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"TIEMPO EN SEGUNDOS";
			// 
			// lblHabi
			// 
			this->lblHabi->AutoSize = true;
			this->lblHabi->BackColor = System::Drawing::Color::Transparent;
			this->lblHabi->ForeColor = System::Drawing::Color::White;
			this->lblHabi->Location = System::Drawing::Point(568, 153);
			this->lblHabi->Name = L"lblHabi";
			this->lblHabi->Size = System::Drawing::Size(73, 13);
			this->lblHabi->TabIndex = 16;
			this->lblHabi->Text = L"N° Habitantes";
			// 
			// lblAge
			// 
			this->lblAge->AutoSize = true;
			this->lblAge->BackColor = System::Drawing::Color::Transparent;
			this->lblAge->ForeColor = System::Drawing::Color::White;
			this->lblAge->Location = System::Drawing::Point(568, 84);
			this->lblAge->Name = L"lblAge";
			this->lblAge->Size = System::Drawing::Size(61, 13);
			this->lblAge->TabIndex = 15;
			this->lblAge->Text = L"N° Agentes";
			// 
			// lblAli
			// 
			this->lblAli->AutoSize = true;
			this->lblAli->BackColor = System::Drawing::Color::Transparent;
			this->lblAli->ForeColor = System::Drawing::Color::White;
			this->lblAli->Location = System::Drawing::Point(571, 21);
			this->lblAli->Name = L"lblAli";
			this->lblAli->Size = System::Drawing::Size(56, 13);
			this->lblAli->TabIndex = 14;
			this->lblAli->Text = L"N° Aliados";
			// 
			// btnIniciar
			// 
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(585, 457);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(95, 34);
			this->btnIniciar->TabIndex = 13;
			this->btnIniciar->Text = L"INICIAR";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MenuJuego::btnIniciar_Click);
			// 
			// NumUDAli
			// 
			this->NumUDAli->BackColor = System::Drawing::SystemColors::Window;
			this->NumUDAli->Location = System::Drawing::Point(571, 47);
			this->NumUDAli->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->NumUDAli->Name = L"NumUDAli";
			this->NumUDAli->Size = System::Drawing::Size(120, 20);
			this->NumUDAli->TabIndex = 12;
			this->NumUDAli->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// NumUDAge
			// 
			this->NumUDAge->Location = System::Drawing::Point(571, 110);
			this->NumUDAge->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->NumUDAge->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NumUDAge->Name = L"NumUDAge";
			this->NumUDAge->Size = System::Drawing::Size(120, 20);
			this->NumUDAge->TabIndex = 11;
			this->NumUDAge->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// NumUDHabi
			// 
			this->NumUDHabi->Location = System::Drawing::Point(571, 179);
			this->NumUDHabi->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->NumUDHabi->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NumUDHabi->Name = L"NumUDHabi";
			this->NumUDHabi->Size = System::Drawing::Size(120, 20);
			this->NumUDHabi->TabIndex = 10;
			this->NumUDHabi->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// timerMenu
			// 
			this->timerMenu->Enabled = true;
			this->timerMenu->Interval = 500;
			this->timerMenu->Tick += gcnew System::EventHandler(this, &MenuJuego::timerMenu_Tick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(571, 306);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 19;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lblLVL
			// 
			this->lblLVL->AutoSize = true;
			this->lblLVL->BackColor = System::Drawing::Color::Transparent;
			this->lblLVL->ForeColor = System::Drawing::Color::White;
			this->lblLVL->Location = System::Drawing::Point(571, 287);
			this->lblLVL->Name = L"lblLVL";
			this->lblLVL->Size = System::Drawing::Size(38, 13);
			this->lblLVL->TabIndex = 20;
			this->lblLVL->Text = L"NIVEL";
			// 
			// MenuJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->ClientSize = System::Drawing::Size(703, 543);
			this->Controls->Add(this->lblLVL);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->NumUDTime);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblHabi);
			this->Controls->Add(this->lblAge);
			this->Controls->Add(this->lblAli);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->NumUDAli);
			this->Controls->Add(this->NumUDAge);
			this->Controls->Add(this->NumUDHabi);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MenuJuego";
			this->Text = L"MenuJuego";
			this->Load += gcnew System::EventHandler(this, &MenuJuego::MenuJuego_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDAli))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDAge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumUDHabi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if ((int)numericUpDown1->Value == 1)
		{
			MyForm^ forms;
			Instrucciones^ obj_inst = gcnew Instrucciones(1);
			this->Visible = false;
			timerMenu->Enabled = false;
			obj_inst->ShowDialog();
			forms = gcnew MyForm((int)NumUDAli->Value, (int)NumUDAge->Value, (int)NumUDHabi->Value, (int)NumUDTime->Value);
			forms->ShowDialog();
			delete forms;
			this->Visible = true;
			timerMenu->Enabled = true;
		}
		else
		{
			MyFormN2^ forms;
			Instrucciones^ obj_inst = gcnew Instrucciones(2);
			this->Visible = false;
			timerMenu->Enabled = false;
			obj_inst->ShowDialog();
			forms = gcnew MyFormN2((int)NumUDAli->Value, (int)NumUDAge->Value, (int)NumUDHabi->Value, (int)NumUDTime->Value);
			forms->ShowDialog();
			delete forms;
			this->Visible = true;
			timerMenu->Enabled = true;
		}

	}
private: System::Void MenuJuego_Load(System::Object^ sender, System::EventArgs^ e) 
{
}
private: System::Void timerMenu_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	Graphics^ Canvas = this->CreateGraphics();

	//se reserva memoria para el buffer
	BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

	//Creamos canvas dentro del espacio del buffer usando el canvas del formulario
	BufferedGraphics^ buffer = espacioBuffer->Allocate(Canvas, this->ClientRectangle);

	//A partir de aqui todos los dibujos se hacen en el canvas del buffer::BufferedGraphics^ buffer
	buffer->Graphics->DrawImage(im_Fondo, 0, 0, Rectangle(0, 0, this->Size.Width, this->Size.Height), GraphicsUnit::Pixel);
	buffer->Render(Canvas);
	delete buffer;
	delete espacioBuffer;
	delete Canvas;
}
};
}
