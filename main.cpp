/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctime>
#include <chrono>

int main() { 
    
     int dia_nac = 0;
     int mes_nac = 0;
     int año_nac = 0;
     int año_edad = 0;
     int año_mayoria = 0;
     int años_espera = 0;
     std::string name;
     
     
       // Obtener tiempo actual
     auto now = std::chrono::system_clock::now();
     std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    
    // Convertir a estructura tm
    std::tm* local_time = std::localtime(&now_time_t);

    // Acceder a los componentes de fecha actual
    int dia_hoy = local_time->tm_mday;
    int mes_hoy = local_time->tm_mon + 1; // tm_mon es 0-11
    int año_hoy = local_time->tm_year + 1900; // tm_year es años desde 1900

    std::cout << "Fecha actual: " << dia_hoy << "/" << mes_hoy << "/" << año_hoy << std::endl;
    
    
    
    std::cout << "Bienvenido al sistema bancario, por favor, introduce tu nombre: " << std::endl;
    std::cin >> name;
    std::cout << "De acuerdo, "<<name <<" Anota tu dia de nacimiento: " << std::endl;
    std::cin >> dia_nac;
    std::cout << "mes de nacimiento (numero de mes): " << std::endl;
    std::cin >> mes_nac;
    std::cout << "año de nacimiento: " << std::endl;
    std::cin >> año_nac;
    
    año_edad = año_hoy - año_nac;
    año_mayoria = año_nac + 18;
    
    std::cout << "Edad calculada: " << año_edad <<" años."<< std::endl;
    
    if (mes_nac < mes_hoy || (mes_nac == mes_hoy && dia_nac > dia_hoy))  {
        año_edad = año_edad - 1;
        
        año_mayoria = año_nac + 18;
        años_espera = año_mayoria - año_hoy;
        
    }
    
    
    
        
    if (año_edad < 18) {
        std::cout << "aun eres menor de edad, debes esperar: "<<años_espera<<" años." << std::endl;
    }
    else { 
        std::cout << "Muy bien, eres mayor de edad, puedes continuar"  << std::endl;
        
    }
    
    
   return 0;     
}
    










