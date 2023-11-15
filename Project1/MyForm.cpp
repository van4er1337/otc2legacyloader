
#include "includes.h"
#include "MyForm.h"


	
using namespace System; 
using namespace System::Windows::Forms;

namespace Project1 {
	using namespace System;
	using namespace System::Windows::Forms;


	[STAThreadAttribute]
		int main(cli::array < String^>^ args) {
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		Project1::MyForm form;
		Application::Run(% form);

		// Возвращаем 0, чтобы указать успешное завершение программы
		return 0;

	}
}

