#pragma once

#include "includes.h"

bool injectdll(DWORD processId, const std::wstring& dllPath);

namespace Project1 {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainMenus
	/// </summary>
	public ref class mainMenus : public System::Windows::Forms::Form
	{
	private:
		String^ selectedCheat;
	private:
		int opacityIncrement = 1;  // Шаг изменения прозрачности
		int targetOpacity = 255;    // Целевая прозрачность
		System::Windows::Forms::Timer^ fadeInTimer;
	public:
		mainMenus(void) 
		{
			InitializeComponent();
			fadeInTimer = gcnew System::Windows::Forms::Timer();
			fadeInTimer->Interval = 20;
			fadeInTimer->Tick += gcnew System::EventHandler(this, &mainMenus::fadeInTimer_Tick);
			this->Opacity = 0;
			fadeInTimer->Start();
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainMenus::mainForm_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &mainMenus::mainForm_MouseUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &mainMenus::mainForm_MouseMove);

		}

	private:
		bool mouseDown;
		Point lastLocation;


	private: System::Void fadeInTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->Opacity < 1.0)
		{
			this->Opacity += 0.05; // Измените этот параметр по вашему усмотрению
		}
		else
		{
			fadeInTimer->Stop(); // Остановите таймер после завершения анимации
		}
	}

	private:

			// Показать PictureBox1 и скрыть PictureBox2
			void ShowPictureBox1AndHidePictureBox2() {
				pictureBox2->Show();
				pictureBox3->Hide();
			}

			// Показать PictureBox2 и скрыть PictureBox1
			void ShowPictureBox2AndHidePictureBox1() {
				pictureBox2->Hide();
				pictureBox3->Show();
			}

	private: void InjectCheat(String^ selectedCheat) {
		if (!isProcessRunning(L"steam.exe")) {
			if (!LaunchSteamIfNeeded(true)) {
				::MessageBox(nullptr, L"Failed to launch Steam. Exiting.", L"Information", MB_OK | MB_ICONINFORMATION);
			}
		}


		DWORD steamProcessId = FindSteamProcess();

		if (steamProcessId != 0) {
			::MessageBox(nullptr, L"Working... Please wait", L"Information", MB_OK | MB_ICONINFORMATION);

			wstring steamModulePath;
			wstring csgoModulePath;

			if (selectedCheat == L"otc2legacy") {
				steamModulePath = L"C:\\otc2legacy\\steam_module.dll";
			}
			else if (selectedCheat == L"pandora") {
				steamModulePath = L"C:\\pandora\\steam_module.dll";
			}

			if (!fileExists(steamModulePath)) {
				cout << "steam_module.dll not found. Downloading..." << endl;

				if (!directoryExists(L"C:\\pandora")) {
					cout << "Creating directory: C:\\pandora" << endl;
					if (!createDirectory(L"C:\\pandora")) {
						cout << "Failed to create directory C:\\pandora" << endl;
					}
				}

				if (!directoryExists(L"C:\\otc2legacy")) {
					cout << "Creating directory: C:\\otc2legacy" << endl;
					if (!createDirectory(L"C:\\otc2legacy")) {
						cout << "Failed to create directory C:\\otc2legacy" << endl;

					}
				}

				wstring steamModuleUrl;

				if (selectedCheat == L"otc2legacy") {
					steamModuleUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/6IMrD72BBrt3Aw"; // Замените на реальный URL
				}
				else if (selectedCheat == L"pandora") {
					steamModuleUrl = L"https://cdn.discordapp.com/attachments/1162646365785038920/1173198845790916708/steam_module.dll?ex=65631591&is=6550a091&hm=4987826f069d6c3c07f276b83f09ea4ab7ff2870fd77972deb88882f09467137&"; // Замените на реальный URL для Pandora
				}

				if (downloadFile(steamModuleUrl, steamModulePath)) {
					cout << "steam_module.dll downloaded successfully." << endl;
				}
				else {
					cout << "Failed to download steam_module.dll." << endl;

				}
			}

			Sleep(8000);
			if (injectdll(steamProcessId, steamModulePath)) {
				cout << "steam_module.dll injected successfully into Steam." << endl;
			}
			else {
				cout << "Failed to inject steam_module.dll into Steam." << endl;
			}
		}
		else {
			cout << "Steam.exe process not found. Exiting." << endl;

		}

		::MessageBox(nullptr, L"Start CS:GO", L"Information", MB_OK | MB_ICONINFORMATION);

		DWORD csgoProcessId = waitForProcess(L"csgo.exe");

		if (csgoProcessId != 0) {
			cout << "csgo.exe process started with PID: " << csgoProcessId << ". Injecting cheat DLL in 5 seconds..." << endl;

			wstring cheatDllPath;

			if (selectedCheat == L"otc2legacy") {
				cheatDllPath = L"C:\\otc2legacy\\cheat.dll";
			}
			else if (selectedCheat == L"pandora") {
				cheatDllPath = L"C:\\pandora\\cheat.dll";
			}

			if (!fileExists(cheatDllPath)) {
				cout << "Cheat DLL not found. Downloading..." << endl;

				if (!directoryExists(L"C:\\pandora")) {
					cout << "Creating directory: C:\\pandora" << endl;
					if (!createDirectory(L"C:\\pandora")) {
						cout << "Failed to create directory C:\\pandora" << endl;

					}
				}

				if (!directoryExists(L"C:\\otc2legacy")) {
					cout << "Creating directory: C:\\otc2legacy" << endl;
					if (!createDirectory(L"C:\\otc2legacy")) {
						cout << "Failed to create directory C:\otc2legacy" << endl;

					}
				}


				wstring cheatDllUrl;

				if (selectedCheat == L"otc2legacy") {
					cheatDllUrl = L"https://getfile.dokpub.com/yandex/get/https://disk.yandex.ru/d/1fIlq7rnEHD7Lw"; // Замените на реальный URL
				}
				else if (selectedCheat == L"pandora") {
					cheatDllUrl = L"https://cdn.discordapp.com/attachments/1162646365785038920/1173307228460163183/cheat2.dll?ex=65637a82&is=65510582&hm=e3c646ea2f61ee90431ee8664e615398902c5b6e2fe80ec88ad5b2e173eee3cf&"; // Замените на реальный URL для Pandora
				}

				if (downloadFile(cheatDllUrl, cheatDllPath)) {
					cout << "Cheat DLL downloaded successfully." << endl;
				}
				else {
					cout << "Failed to download Cheat DLL." << endl;

				}
			}

			Sleep(5000);
			if (injectdll(csgoProcessId, cheatDllPath)) {
				cout << "Cheat DLL injected successfully into csgo.exe." << endl;
			}
			else {
				cout << "Failed to inject Cheat DLL into csgo.exe." << endl;
			}
		}
		else {
			cout << "csgo.exe process not found. Exiting." << endl;

		}
	}

	private:
		System::String^ labelText;
		System::String^ labelText2;

private: System::Windows::Forms::Label^ Exit;
private: System::Windows::Forms::Label^ label1;

private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::PictureBox^ pictureBox3;

private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;


	private: System::Windows::Forms::Button^ selectedButton = nullptr;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainMenus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button3;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainMenus::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat Black", 12, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"otc2loader";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 700", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(13, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"main menu";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 900", 11.25F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(2, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 29);
			this->button1->TabIndex = 8;
			this->button1->Text = L"otc2legacy";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &mainMenus::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 900", 11.25F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(2, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 29);
			this->button2->TabIndex = 8;
			this->button2->Text = L"pandora";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &mainMenus::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 900", 11.25F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(184, 204);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 35);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Load";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &mainMenus::button3_Click);
			// 
			// Exit
			// 
			this->Exit->AutoSize = true;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Exit->Location = System::Drawing::Point(332, 9);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(36, 37);
			this->Exit->TabIndex = 10;
			this->Exit->Text = L"×";
			this->Exit->Click += gcnew System::EventHandler(this, &mainMenus::Exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 5.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(222, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 9);
			this->label1->TabIndex = 7;
			this->label1->Text = L"last update: 17.12.2021";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 700", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(138, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Лучший чит на CS:GO 2018";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(33, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(43, 53);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Museo Sans Cyrl 900", 15.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(127, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 19);
			this->label5->TabIndex = 7;
			this->label5->Text = L"otc2legacy";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(151, 57);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(113, 129);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(151, 56);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(130, 129);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->flowLayoutPanel1->Location = System::Drawing::Point(120, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1, 265);
			this->flowLayoutPanel1->TabIndex = 12;
			// 
			// mainMenus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(380, 261);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"mainMenus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"mainMenus";
			this->Load += gcnew System::EventHandler(this, &mainMenus::mainMenus_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowPictureBox2AndHidePictureBox1();
		

		// Изменяем текст
		labelText = L"otc2legacy";
		labelText2 = L"Самый лучший чит для CS:GO 2018";

		// Присваиваем новый текст метке
		label5->Text = labelText;
		label4->Text = labelText2;


		// Если была выбрана другая кнопка, снимаем выделение с предыдущей
		if (selectedButton != nullptr && selectedButton != button1) {
			selectedButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(26, 24, 34);
			selectedButton->FlatAppearance->BorderSize = 1;
		}

		// Выбираем чит
		selectedCheat = L"otc2legacy";

		// Устанавливаем стиль кнопки при нажатии
		button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(110, 65, 226);
		button1->FlatAppearance->BorderSize = 2;

		// Сохраняем текущую выбранную кнопку
		selectedButton = button1;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		ShowPictureBox1AndHidePictureBox2();

		// Изменяем текст
		labelText = L"Pandora";
		labelText2 = L"Самый худший чит для CS:GO 2018";

		// Присваиваем новый текст метке
		label5->Text = labelText;
		label4->Text = labelText2;
		// Если была выбрана другая кнопка, снимаем выделение с предыдущей
		if (selectedButton != nullptr && selectedButton != button2) {
			selectedButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(26, 24, 34);
			selectedButton->FlatAppearance->BorderSize = 1;
		}

		// Выбираем чит
		selectedCheat = L"pandora";

		// Устанавливаем стиль кнопки при нажатии
		button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(110, 65, 226);
		button2->FlatAppearance->BorderSize = 2;

		// Сохраняем текущую выбранную кнопку
		selectedButton = button2;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// Проверяем, выбран ли чит перед инжекцией
		if (selectedCheat != L"") {
			// Вызываем метод для инжекции с выбранным именем чита
			InjectCheat(selectedCheat);
		}
		else {
			// Если чит не выбран, выводим сообщение об ошибке или предупреждение
			MessageBox::Show(L"Please select a cheat before loading.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
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

private: System::Void mainMenus_Load(System::Object^ sender, System::EventArgs^ e) {
	CustomizeButtonAppearance(button1);
	button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainMenus::button1_Paint);
	CustomizeButtonAppearance(button1);
	button2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainMenus::button1_Paint);
	CustomizeButtonAppearance(button1);
	button3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainMenus::button1_Paint);
	RoundCorners(this);
	fadeInTimer->Start();
}
private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
