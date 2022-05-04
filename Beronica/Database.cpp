#include "pch.h"
#include "Database.h"
#include <iostream>
using namespace std;


Database::Database() {
	this->cadenaConexion = "datasource=localhost; username=root; password='daniela11'; database=mydatabase;";
	this->conn = gcnew MySqlConnection(this->cadenaConexion);
	this->conn->Open();
	if (this->conn != nullptr) {
		Console::Write("Connectado!");
	}
}


void Database::insertar(int id, String^ carnet, String^ nombre, String^ apellidos, String^ dir, int t,bool sexo, String^ email, DateTime fecha)
{
	String^ sql = "insert into estudiantes (id_estudiante, carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento)";
	String^ query = sql + "values('" + id + "', '" + carnet + "', '" + nombre + "', '" + apellidos + "', '" + dir + "', '" + t + "', '" + sexo + "', '" + email + "', '" + fecha + "')";
	MySqlCommand^ cursor = gcnew MySqlCommand(query, this->conn);
	try
	{
		cursor->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		e->Message;
	}
}


void Database::editar(String^ref,String^ carnet, String^ nombre, String^ apellidos, String^ dir, int t,bool sexo, String^ email, DateTime fecha)
{
	String^ sql = "update estudiantes  set carnet='"+carnet+"', nombres='"+nombre+"', apellidos='"+apellidos+"', direccion='"+dir+"'";
	String^ query = sql +  "telefono='"+t+"', genero='"+sexo+"', email='"+email+"', fecha_nacimiento='"+fecha+"' where Nombre='"+ref+"'";
	MySqlCommand^ cursor = gcnew MySqlCommand(query, this->conn);
	try
	{
		cursor->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		Console::WriteLine(e->Message);
	}
}

void Database::consulta()
{
	String^ sql = "select * from estudiantes";
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->conn);
	MySqlDataReader^ reader;
	reader = cursor->ExecuteReader();
	if (reader->HasRows)
	{
		while (reader->Read()) {
			Console::WriteLine(reader->GetString(0) + " - " + reader->GetString(1) + " - " + reader->GetString(2) + " - " + reader->GetString(3));
		}
	}
	else {
		Console::Write("Vacio");
	}
}

void Database::eliminar(String^ ref) {
	String^ sql = "delete from estudiantes where nombres = '" + ref + "'";
	MySqlCommand^ cursor = gcnew MySqlCommand(sql, this->conn);
	try
	{
		Console::WriteLine("Eliminiado");
	}
	catch (Exception^ e)
	{
		Console::Write(e->Message);
	}

}












