#include "fitness.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// === Clase UserProfile ===
UserProfile::UserProfile(double e, double p, double a, const string& g)
    : edad(e), peso(p), altura(a), genero(g) {}

double UserProfile::getEdad() const { return edad; }
double UserProfile::getPeso() const { return peso; }
double UserProfile::getAltura() const { return altura; }
string UserProfile::getGenero() const { return genero; }

void UserProfile::setEdad(double e) { edad = e; }
void UserProfile::setPeso(double p) { peso = p; }
void UserProfile::setAltura(double a) { altura = a; }
void UserProfile::setGenero(const string& g) { genero = g; }

// === Namespace Fitness ===
namespace Fitness {

double calcularBMR(const UserProfile& user) {
    if (user.getGenero() == "hombre") {
        return 88.362 + (13.397 * user.getPeso()) +
                        (4.799 * user.getAltura()) -
                        (5.677 * user.getEdad());
    } else if (user.getGenero() == "mujer") {
        return 447.593 + (9.247 * user.getPeso()) +
                         (3.098 * user.getAltura()) -
                         (4.330 * user.getEdad());
    } else {
        cerr << "Género inválido.\n";
        return 0;
    }
}

double calcularTMR(const UserProfile& user, int actividad) {
    double tmr;

    if (user.getGenero() == "hombre")
        tmr = 10 * user.getPeso() + 6.25 * user.getAltura() - 5 * user.getEdad() + 5;
    else if (user.getGenero() == "mujer")
        tmr = 10 * user.getPeso() + 6.25 * user.getAltura() - 5 * user.getEdad() - 161;
    else {
        cerr << "Género inválido.\n";
        return 0;
    }

    switch (actividad) {
        case 1: return tmr * 1.2;
        case 2: return tmr * 1.375;
        case 3: return tmr * 1.55;
        case 4: return tmr * 1.725;
        case 5: return tmr * 1.9;
        default:
            cerr << "Actividad inválida.\n";
            return 0;
    }
}

void mostrarRutina(const string dias[], const string rutina[]) {
    cout << left << setw(12) << "Día" << " | Rutina" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 7; i++) {
        cout << left << setw(12) << dias[i] << "| " << rutina[i] << endl;
    }
}

void preguntarMostrarRutina(const string dias[], const string rutina[]) {
    char ans;
    cout << "¿Le gustaría ver una tabla semanal de ejercicios? (Y/N): ";
    cin >> ans;
    ans = tolower(ans);
    if (ans == 'y') {
        mostrarRutina(dias, rutina);
    }
}

}
