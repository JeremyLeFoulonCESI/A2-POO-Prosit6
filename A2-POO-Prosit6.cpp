#include "pch.h"
#include "MyForm.h"
#include "Password.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;


const char* user = "root";
const char* ip = "127.0.0.1";
const char* db_name = "a2_poo_prosit6";


[STAThreadAttribute]
int main(array<String^>^ args)
{
	/*String^ connect_string = gcnew String("server=");
	connect_string = String::Concat(connect_string, gcnew String(ip));
	connect_string = String::Concat(connect_string, gcnew String(";uid="));
	connect_string = String::Concat(connect_string, gcnew String(user));
	connect_string = String::Concat(connect_string, gcnew String(";pwd="));
	connect_string = String::Concat(connect_string, gcnew String(password));
	connect_string = String::Concat(connect_string, gcnew String(";database="));
	connect_string = String::Concat(connect_string, gcnew String(db_name));


	MySqlConnection^ conn = gcnew MySqlConnection();
	conn->ConnectionString = connect_string;
	conn->Open();

	MySqlCommand^ cmd = conn->CreateCommand();

	cmd->CommandText = "select * from exempleCpp";
	cmd->Prepare();
	MySqlDataReader^ reader = cmd->ExecuteReader();
	reader->Read();
	Console::WriteLine(reader);

	conn->Close();*/

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	P6new::MyForm monFormulaire;
	Application::Run(% monFormulaire);
}

