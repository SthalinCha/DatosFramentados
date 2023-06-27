#include "cliente.h"


Cliente::Cliente(const string &textoCompleto) {
   procesoInformacion(textoCompleto);
}


string Cliente::getCedula() const
{
    return cedula;
}

void Cliente::setCedula(string newCedula)
{
    cedula = newCedula;
}

string Cliente::getNombre() const
{
    return nombre;
}

void Cliente::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string Cliente::getApellido() const
{
    return apellido;
}

void Cliente::setApellido(const string &newApellido)
{
    apellido = newApellido;
}

string Cliente::getDireccion() const
{
    return direccion;
}

void Cliente::setDireccion(const string &newDireccion)
{
    direccion = newDireccion;
}

string Cliente::getTelefono() const
{
    return telefono;
}

void Cliente::setTelefono(string newTelefono)
{
    telefono = newTelefono;
}

string Cliente::getEmail() const
{
    return email;
}

void Cliente::setEmail(const string &newEmail)
{
    email = newEmail;
}
void Cliente::procesoInformacion(const string &textoCompleto) {
    // Divido textoCompleto en líneas
    QStringList lineas = QString::fromStdString(textoCompleto).split("\n");

    // Iterar sobre cada línea
    for (const QString &linea : lineas) {
        // Sirve para que el valor que este me tome si está unido así ":" oa si ": "
        // Me separa en 2 campos Nombres y Apellidos
        QRegExp regExp("[:][ ]?");
        QStringList campos = linea.split(regExp);

        if (campos.size() == 2) {
            string label = campos[0].trimmed().toStdString();
            string value = campos[1].trimmed().toStdString();

            // Es un condicional para que por si acaso me coloque diferente el formulario igual me toma los datos
            if (label == "Nombre completo" || label == "Nombres") {
                QStringList nombreCompleto = campos[1].split(QRegExp("[ ]+"), QString::SkipEmptyParts);
                if (nombreCompleto.size() >= 2) {
                    setNombre(nombreCompleto[0].trimmed().toStdString());
                    setApellido(nombreCompleto[nombreCompleto.size() - 1].trimmed().toStdString());
                }
            } else if (label == "Cédula" || label == "Cedula") {
                setCedula(value);
            } else if (label == "Dirección" || label == "Direccion") {
                setDireccion(value);
            } else if (label == "Teléfono" || label == "Telefono") {
                setTelefono(value);
            } else if (label == "Correo electrónico" || label == "Correo electronico" || label == "Email") {
                setEmail(value);
            }
        }
    }
}

