#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	UltrahapticsStandalone::MainForm form;
	Application::Run(%form);
}

delegate void UpdateDelegate();
void UltrahapticsStandalone::MainForm::hapticsChange()
{
	UpdateDelegate^ updateAction = gcnew UpdateDelegate(this, &MainForm::updateAllControlValues);//  &MainWindow::enableButtons);
	this->BeginInvoke(updateAction);
	//updateAllControlValues();
}
