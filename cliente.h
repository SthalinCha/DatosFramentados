#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <QStringList>
using namespace std;
class Cliente
{
private:

    string nombre;
    string apellido;
    string cedula;
    string direccion;
    string telefono;
    string email;

public:
    Cliente();
    Cliente(const string &textoCompleto);
    void procesoInformacion(const string &textoCompleto);
    string getCedula() const;
    void setCedula(string newCedula);
    string getNombre() const;
    void setNombre(const string &newNombre);
    string getApellido() const;
    void setApellido(const string &newApellido);
    string getDireccion() const;
    void setDireccion(const string &newDireccion);
    string getTelefono() const;
    void setTelefono(string newTelefono);
    string getEmail() const;
    void setEmail(const string &newEmail);

};

#endif // CLIENTE_H
