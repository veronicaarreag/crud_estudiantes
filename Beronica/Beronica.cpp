#include "pch.h"
#include "Database.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Database^ data = gcnew Database();
    DateTime date = DateTime::Now;
    //data->insertar(2, "0901", "Vanesa", "Hernandez", "11 Av", 59621085, true, "olstertecn", date);
    data->consulta();
    return 0;
}
