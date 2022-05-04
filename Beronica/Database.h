#pragma once
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace std;
ref class Database
{
private:
	String^ cadenaConexion;
	MySqlConnection^ conn;
public:
	Database();
	void insertar(int, String^, String^, String^, String^,int,bool, String^, DateTime);
	void consulta();
	void eliminar(String^);
	void editar(String^, String^, String^, String^, String^,int,bool, String^, DateTime);
};

