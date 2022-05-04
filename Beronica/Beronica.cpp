#include "pch.h"
#include "Database.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Database^ data = gcnew Database();
    DateTime date = DateTime::Now;
    data->insertar(2, "0901", "Vanesa", "Hernandez", "11 Av", 59621085, true, "vane_@gmail.com", date);
    data->consulta();
    data->editar("Vanesa", "10107", "Oscar", "Juarez", "15 Av", 69854522, false, "oscar_51@gmail.com", date);
    data->consulta();
    data->eliminar("Oscar");
    data->consulta();
    return 0;
}
