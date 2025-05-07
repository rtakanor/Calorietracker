#ifndef FITNESS_CALCULATOR_H
#define FITNESS_CALCULATOR_H

#include <string>
using namespace std;

class UserProfile {
private:
    double edad;
    double peso;
    double altura;
    string genero;

public:
    UserProfile(double e, double p, double a, const string& g);

    double getEdad() const;
    double getPeso() const;
    double getAltura() const;
    string getGenero() const;

    void setEdad(double e);
    void setPeso(double p);
    void setAltura(double a);
    void setGenero(const string& g);
};

namespace Fitness {
    double calcularBMR(const UserProfile& user);
    double calcularTMR(const UserProfile& user, int actividad);
    void mostrarRutina(const string dias[], const string rutina[]);
    void preguntarMostrarRutina(const string dias[], const string rutina[]);
}

#endif
