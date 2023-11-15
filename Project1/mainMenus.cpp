#include "mainMenus.h"

#include "includes.h"





namespace Project1 {
	using namespace System;
	using namespace System::Windows::Forms;



	[STAThreadAttribute]
		int mainmenus(cli::array < String^>^ args) {
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		Project1::mainMenus form;
		Application::Run(% form);

		// Возвращаем 0, чтобы указать успешное завершение программы
		return 0;
	}
}

