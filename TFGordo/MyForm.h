#pragma once
#include "Juego.h"
namespace TFGordo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Graphics ^ g;
		int nivel;
		BufferedGraphics^ buffer;
		Bitmap^ imgkirby;
		Bitmap^ fondo;
		bool rojo;
		float cooldown;
		int tiempo;
		int x;
		int y;
		int ancho;
		int largo;
		String^ nombre;
		int muertos;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;




			 Juego * juego;
	
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(113, 48);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(12, 393);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 50);
			this->pictureBox5->TabIndex = 8;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(12, 449);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 50);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 337);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 50);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 275);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 56);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// timer3
			// 
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(99, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(402, 79);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Finalizado";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(172, 193);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 23);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Puntaje (masa):";
			this->label2->UseCompatibleTextRendering = true;
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(172, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 23);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Jugador:";
			this->label3->UseCompatibleTextRendering = true;
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(172, 236);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 23);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Muertos:";
			this->label4->UseCompatibleTextRendering = true;
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(354, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 23);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Jugador:";
			this->label5->UseCompatibleTextRendering = true;
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(354, 193);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 23);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Jugador:";
			this->label6->UseCompatibleTextRendering = true;
			this->label6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(354, 236);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 23);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Jugador:";
			this->label7->UseCompatibleTextRendering = true;
			this->label7->Visible = false;
			// 
			// timer4
			// 
			this->timer4->Interval = 80;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(172, 275);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 23);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Vidas:";
			this->label8->UseCompatibleTextRendering = true;
			this->label8->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(354, 275);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 23);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Vidas:";
			this->label9->UseCompatibleTextRendering = true;
			this->label9->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(209, 170);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 20);
			this->textBox1->TabIndex = 19;
			this->textBox1->Text = L"Ingrese su nombre";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(-2, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(576, 79);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Programacion 2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(209, 219);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 20);
			this->textBox2->TabIndex = 21;
			this->textBox2->Text = L"Ingrese el numero de vidas";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(209, 262);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(102, 20);
			this->textBox3->TabIndex = 22;
			this->textBox3->Text = L"Ingrese el tiempo (s)";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(349, 337);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (juego->getvidas() <= 0 || juego->getpuntaje() <= 0)
		{
			buffer->Graphics->Clear(this->BackColor);
			buffer->Render(g);

			label5->Text = nombre;
			label6->Text = juego->getpuntaje().ToString();
			label7->Text = muertos.ToString();
			label9->Text = juego->getvidas().ToString();

			label1->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			label4->Visible = true;
			label5->Visible = true;
			label6->Visible = true;
			label7->Visible = true;
			label8->Visible = true;
			label9->Visible = true;

			timer1->Enabled = false;
			timer2->Enabled = false;
			timer3->Enabled = false;
		}
		if (juego->getmuertos() > 15)
		{
			juego->pasarnivel();
			nivel = juego->get_nivel();
			if (nivel == 2)
			{
				fondo = gcnew Bitmap(pictureBox3->Image);
			}
			if (nivel == 3)
			{
				fondo = gcnew Bitmap(pictureBox4->Image);
			}
			if (nivel == 4)
			{
				fondo = gcnew Bitmap(pictureBox5->Image);
			}
			juego->agregarVirus();
			muertos = muertos + juego->getmuertos();
			juego->setmuertos(0);
		}
		buffer->Graphics->Clear(this->BackColor);
		juego->dibujar(buffer->Graphics, imgkirby, fondo);
		buffer->Render(g);
		juego->movercelulas(g);
		juego->colisionar();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	
		juego->moverj(e->KeyData, g);
		if (e->KeyData == Keys::Space)
		{
			juego->dividirpoder();
		}

		if (e->KeyData == Keys::X)
		{
			if (juego->seborra())
			{
				timer4->Enabled = true;
				cooldown = 1;
				x = juego->xvirus() - 1;
				y = juego->yvirus() - 1;
				ancho = juego->anchovirus();
				largo = juego->largovirus();
			}
		}
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (juego->getTIEMPO() <= 0)
		{
			
		}
		if (nivel == 1)
		{
			timer2->Interval = 3000;
		}
		if (nivel == 2)
		{
			timer2->Interval = 2000;
		}

		if (nivel == 3)
		{
			timer2->Interval = 1500;
		}

		if (nivel == 4)
		{
			timer2->Interval = 1000;
		}

		juego->agregarCelulas();
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (tiempo <= 0)
		{
			buffer->Graphics->Clear(this->BackColor);
			buffer->Render(g);

			label5->Text = nombre;
			label6->Text = juego->getpuntaje().ToString();
			label7->Text = juego->getmuertos().ToString();
			label9->Text = juego->getvidas().ToString();

			label1->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			label4->Visible = true;
			label5->Visible = true;
			label6->Visible = true;
			label7->Visible = true;
			label8->Visible = true;
			label9->Visible = true;

			timer1->Enabled = false;
			timer2->Enabled = false;
			timer3->Enabled = false;
		}
		tiempo = tiempo - 1;
		cooldown = cooldown - 1;
		juego->setTIEMPO(tiempo);
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {

	if (cooldown > 0)
	{

		if (rojo == true)
		{
			g->FillEllipse(Brushes::Red, x, y, ancho, largo);
			ancho = ancho + 1;
			largo = largo + 1;
			rojo = !rojo;
		}
		else
		{
			g->FillEllipse(Brushes::White, x, y, ancho, largo);
			ancho = ancho + 1;
			largo = largo + 1;
			rojo = !rojo;
		}
	}
	else
	{
		juego->borrarvirus();
		timer4->Enabled = false;
	}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (textBox1->Text->Length!=0 || textBox2->Text->Length != 0 || textBox3->Text->Length != 0)
		{
			int vidas= int::Parse(textBox2->Text);
			tiempo = int::Parse(textBox3->Text);
			if (vidas > 0 && tiempo > 0)
			{
				nombre = textBox1->Text;
				label10->Visible = false;
				textBox1->Visible = false;
				textBox1->Enabled = false;
				textBox2->Visible = false;
				textBox2->Enabled = false;
				textBox3->Visible = false;
				textBox3->Enabled = false;
				juego = new Juego(vidas, tiempo);

				nivel = juego->get_nivel();
				imgkirby = gcnew Bitmap(pictureBox1->Image);
				fondo = gcnew Bitmap(pictureBox2->Image);
				imgkirby->MakeTransparent(imgkirby->GetPixel(1, 1));
				BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
				buffer = context->Allocate(g, this->ClientRectangle);
				juego->agregarVirus();

				timer1->Enabled = true;
				timer2->Enabled = true;
				timer3->Enabled = true;

				button1->Enabled = false;
				button1->Visible = false;
			}
			else
			{
				MessageBox::Show("Ingrese numeros donde debe");
			}
		}
		else
		{
			MessageBox::Show("Ingrese Datos Correctos");
		}

	}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
