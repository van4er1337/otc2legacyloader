
#include "includes.h"
#include "mainMenus.h"
#include "registerandlogin.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mainForm_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mainForm_MouseUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mainForm_MouseMove);

		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ LoginBox;
	private: System::Windows::Forms::TextBox^ PasswordBox;
	private:
		bool mouseDown;
		Point lastLocation;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ Exit;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->LoginBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Exit = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat Black", 12, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 22);
			this->label1->TabIndex = 0;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 500", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(51, 173);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Retry;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatAppearance->BorderSize = 2;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 500", 11.25F));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(51, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(172, 39);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Register";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// LoginBox
			// 
			this->LoginBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->LoginBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LoginBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->LoginBox->ForeColor = System::Drawing::Color::Snow;
			this->LoginBox->Location = System::Drawing::Point(50, 86);
			this->LoginBox->Multiline = true;
			this->LoginBox->Name = L"LoginBox";
			this->LoginBox->Size = System::Drawing::Size(141, 25);
			this->LoginBox->TabIndex = 3;
			this->LoginBox->TextChanged += gcnew System::EventHandler(this, &MyForm::LoginBox_TextChanged);
			// 
			// PasswordBox
			// 
			this->PasswordBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->PasswordBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PasswordBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->PasswordBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->PasswordBox->ForeColor = System::Drawing::SystemColors::Info;
			this->PasswordBox->Location = System::Drawing::Point(51, 126);
			this->PasswordBox->MaxLength = 16;
			this->PasswordBox->Multiline = true;
			this->PasswordBox->Name = L"PasswordBox";
			this->PasswordBox->PasswordChar = '*';
			this->PasswordBox->Size = System::Drawing::Size(140, 25);
			this->PasswordBox->TabIndex = 3;
			this->PasswordBox->TextChanged += gcnew System::EventHandler(this, &MyForm::PasswordBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat Black", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(47, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 22);
			this->label2->TabIndex = 0;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// Exit
			// 
			this->Exit->AutoSize = true;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(221, 9);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(36, 37);
			this->Exit->TabIndex = 4;
			this->Exit->Text = L"×";
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 700", 6.25F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(48, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 10);
			this->label3->TabIndex = 5;
			this->label3->Text = L"username";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 700", 6.25F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(49, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 10);
			this->label4->TabIndex = 5;
			this->label4->Text = L"password";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(16, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(47, 54);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(80, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 19);
			this->label5->TabIndex = 7;
			this->label5->Text = L"otc2loader";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->flowLayoutPanel1->Location = System::Drawing::Point(51, 109);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(140, 2);
			this->flowLayoutPanel1->TabIndex = 8;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel1_Paint);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->flowLayoutPanel2->Location = System::Drawing::Point(51, 149);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(140, 2);
			this->flowLayoutPanel2->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(269, 261);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->PasswordBox);
			this->Controls->Add(this->LoginBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ForeColor = System::Drawing::Color::Snow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CustomizeButtonAppearance(button1);
		button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
		CustomizeButtonAppearance(button2);
		button2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
		CustomizeButtonAppearance(button2);
		button2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
		RoundCorners(LoginBox);
		RoundCorners(PasswordBox);
		RoundCorners(this);

	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void LoginBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void PasswordBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Получение введенного имени пользователя и пароля
		std::string username = msclr::interop::marshal_as<std::string>(LoginBox->Text);
		std::string password = msclr::interop::marshal_as<std::string>(PasswordBox->Text);

		// Вызов функции регистрации
		if (Project1::registerUserForm(username, password)) {
			// Регистрация прошла успешно, создайте экземпляр новой формы
			Project1::mainMenus^ newForm = gcnew Project1::mainMenus();

			// Скрыть текущую форму
			this->Hide();

			// Показать новую форму
			newForm->Show();
		}
		else {
			// Регистрация не удалась, выполните необходимые действия
			// например, вывод сообщения об ошибке
			MessageBox::Show("Failed to register user.");
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		// Получение введенного имени пользователя и пароля
		std::string username = msclr::interop::marshal_as<std::string>(LoginBox->Text);
		std::string password = msclr::interop::marshal_as<std::string>(PasswordBox->Text);

		// Вызов функции регистрации
		if (Project1::authenticateUserForm(username, password)) {
			// Регистрация прошла успешно, создайте экземпляр новой формы
			Project1::mainMenus^ newForm = gcnew Project1::mainMenus();


			// Скрыть текущую форму
			this->Hide();

			// Показать новую форму
			newForm->Show();
		}
		else {
			// Регистрация не удалась, выполните необходимые действия
			// например, вывод сообщения об ошибке
			MessageBox::Show("Failed to authenticateUserForm user.");
		}
	}

		   // Добавьте этот метод в private секцию вашего mainForm класса
private: System::Void RoundCorners(System::Windows::Forms::Form^ form) {
	System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
	int radius = 5; // Установите желаемый радиус закругления

	// Добавляем дуги для каждого угла формы
	path->AddArc(0, 0, radius * 2, radius * 2, 180, 90); // Верхний левый угол
	path->AddArc(form->Width - radius * 2, 0, radius * 2, radius * 2, 270, 90); // Верхний правый угол
	path->AddArc(form->Width - radius * 2, form->Height - radius * 2, radius * 2, radius * 2, 0, 90); // Нижний правый угол
	path->AddArc(0, form->Height - radius * 2, radius * 2, radius * 2, 90, 90); // Нижний левый угол

	path->CloseFigure();

	form->Region = gcnew System::Drawing::Region(path);
	delete path;
}


	private: System::Void button1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Button^ button = dynamic_cast<Button^>(sender);

		if (button != nullptr) {
			int radius = 2; // Установите желаемый радиус закругления

			Drawing2D::GraphicsPath^ path = gcnew Drawing2D::GraphicsPath();
			path->AddArc(0, 0, radius * 2, radius * 2, 180, 90);
			path->AddArc(button->Width - radius * 2, 0, radius * 2, radius * 2, 270, 90);
			path->AddArc(button->Width - radius * 2, button->Height - radius * 2, radius * 2, radius * 2, 0, 90);
			path->AddArc(0, button->Height - radius * 2, radius * 2, radius * 2, 90, 90);
			path->CloseFigure();

			button->Region = gcnew Drawing::Region(path);
			delete path;
		}
	}

		   private: System::Void CustomizeButtonAppearance(System::Windows::Forms::Button^ button) {
			   button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   button->FlatAppearance->BorderSize = 0;
			   button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(25, 25, 25);
			   button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(20, 20, 20);
		   }

private: System::Void mainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = true;
	lastLocation = e->Location;
}

private: System::Void mainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = false;
}

private: System::Void mainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (mouseDown) {
		this->Location = Point(this->Location.X + (e->X - lastLocation.X), this->Location.Y + (e->Y - lastLocation.Y));
	}
}


private: System::Void RoundCorners(System::Windows::Forms::Control^ control) {
	System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
	int radius = 3; // Установите желаемый радиус закругления

	// Добавляем дуги только сверху
	path->AddArc(0, 0, radius * 2, radius * 2, 180, 90);
	path->AddArc(control->Width - radius * 2, 0, radius * 2, radius * 2, 270, 90);

	// Прямая линия вниз
	path->AddLine(control->Width, 0, control->Width, control->Height);

	// Прямая линия влево
	path->AddLine(control->Width, control->Height, 0, control->Height);

	path->CloseFigure();

	control->Region = gcnew System::Drawing::Region(path);
	delete path;
}


	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	};
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
};