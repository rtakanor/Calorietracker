#include <iostream>
#include "fitness.h"

using namespace std;

int main() {
    double edad, peso, altura;
    string genero;

    cout << "Ingrese sus datos personales:\n";
    cout << "Edad: "; cin >> edad;
    cout << "Peso (kg): "; cin >> peso;
    cout << "Altura (cm): "; cin >> altura;
    cout << "Género (hombre/mujer): "; cin >> genero;

    UserProfile user(edad, peso, altura, genero);

    int opcion;
    do {
        cout << "\n¿Qué desea consultar? (-1 para salir)\n";
        cout << "1) Calorías para dieta en volumen\n";
        cout << "2) Calorías para dieta en definición\n";
        cout << "3) Ver mi BMR\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int actividad;
                cout << "\nSeleccione su nivel de actividad física:\n";
                cout << "1) Sedentario\n2) Ligero\n3) Moderado\n4) Intenso\n5) Muy intenso\n";
                cin >> actividad;

                double tmr = Fitness::calcularTMR(user, actividad);
                cout << "Calorías diarias para volumen: " << tmr << " cal.\n";

                string dias[7] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
                string rutinaVolumen[7] = {
                    "Pecho Pesado", "Espalda y Trapecio", "Piernas Cuadriceps", "Hombros y Abs",
                    "Brazos", "Full Body Carga", "Descanso o Caminata"
                };
                Fitness::preguntarMostrarRutina(dias, rutinaVolumen);
                break;
            }

            case 2: {
                int actividad;
                cout << "\nSeleccione su nivel de actividad física:\n";
                cout << "1) Sedentario\n2) Ligero\n3) Moderado\n4) Intenso\n5) Muy intenso\n";
                cin >> actividad;

                double tmr = Fitness::calcularTMR(user, actividad);
                cout << "Calorías diarias para definición: " << tmr << " cal.\n";

                string dias[7] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
                string rutinaDefinicion[7] = {
                    "HIIT + Abs", "Cardio y Piernas", "Full Body Circuit", "Boxeo o Funcional",
                    "Cardio Largo", "Ligero + Core", "Descanso Activo"
                };
                Fitness::preguntarMostrarRutina(dias, rutinaDefinicion);
                break;
            }

            case 3: {
                double bmr = Fitness::calcularBMR(user);
                cout << "Su BMR es: " << bmr << " cal/día en reposo.\n";
                break;
            }

            case -1:
                cout << "Gracias por usar el programa. ¡Hasta pronto!\n";
                break;

            default:
                cout << "Opción no válida.\n";
        }

    } while (opcion != -1);

    return 0;
}
