#include <iostream>
#include <mysql.h>  
using namespace std;

int main() {
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "", "escuela", 3306, NULL, 0);

    if (conn) {
        cout << "Conexión exitosa" << endl;
    }
    else {
        cout << "Error en la conexión" << endl;
    }

    string nombre;
    int edad;
    char genero;
    float calificaciones;

    cout << "Ingrese nombre del estudiante: ";
    getline(cin, nombre);

    cout << "Ingrese edad del estudiante: ";
    cin >> edad;

    cout << "Ingrese género del estudiante (M/F): ";
    cin >> genero;

    cout << "Ingrese calificaciones del estudiante: ";
    cin >> calificaciones;

    string query = "INSERT INTO estudiantes (nombre, edad, genero, calificaciones) VALUES ('" + nombre + "', " + to_string(edad) + ", '" + genero + "', " + to_string(calificaciones) + ")";

    const char* q = query.c_str();

    mysql_query(conn, q);

    mysql_close(conn);

    return 0;
}
