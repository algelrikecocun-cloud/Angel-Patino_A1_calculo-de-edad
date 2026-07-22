/******************************************************************************
programador = Angel_Enrique_Patiño_Urbina
profesor = Francisco_Ortega_Rivera
Actividad = 1_Calculo_de_edad_C++
*******************************************************************************/

// LIBRERIAS A UTILIZAR

#include <iostream>               // Libreria de lectura y emision de datos
#include <ctime>                 // Libreria de acceso a fecha y hora actual 
#include <chrono>               // Libreria de manejo de información de tiempo, como calculos

int main() { 
    
        
// DECLARACIÓN DE VARIABLES
    
     int dia_nac = 0;        // Se declara variable "dia_nac", de formato  entero y valor inicial 0, almacena el dia de nacimiento del usuario
     int mes_nac = 0;        // Se declara variable "mes_nac", de formato  entero y valor inicial 0, tendrá el mes de nacimiento del cliente
     int año_nac = 0;        // Se declara variable "año_nac", de formato  entero y valor inicial 0, resguarda el año de nacimiento del usuario
     int año_edad = 0;       // Se declara variable "año_edad", de formato entero y valor inicial 0, calcula la edad del usuario a fecha actual
     int año_mayoria = 0;    // Se declara variable "año_mayoria", de formato entero y valor inicial 0,estima el año en el que cliente cumplio o                          cumplirá la mayoria de edad (18 años)
     int años_espera = 0;    // Se declara variable "años_espera", de formato entero y valor inicial 0, de ser menor de edad, dictamina el tiempo                         restante para la mayoria de edad.
     std::string name;       // Se declara variable "name", de formato string o texto, almacena el nombre del usuario para personalización.
     
     
// OBTENER RAIZ DE TIEMPO ACTUAL DE SISTEMA LOCAL
     
     auto now = std::chrono::system_clock::now();                        //Se le pide al reloj local la informacion de la fecha actual, pero se                                                                      recibe un dato inentendible o "crudo".
     std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);    //Esta linea traduce lo recibido por sistema local a un formato                                                                             estandar time_t, es un numero entero del total de segundos desde                                                                          1/enero/1970 hasta la actualidad
    
 // CONVERTIR A ESTRUCTURA TM; UN LENGUAJE HUMANAMENTE ENTENDIBLE
   
    std::tm* local_time = std::localtime(&now_time_t);  // Se traduce el formato time_t en formato tm, mientras que std::tm asigna cada dato (dia,                                                    mes, año) en variables diferentes.

// ACCEDER A LOS DATOS INDIVIDUALES DE LA FECHA ACTUAL
    
    int dia_hoy = local_time->tm_mday;
    int mes_hoy = local_time->tm_mon + 1;           // los meses son contados 0-11, se hace +1 para que coincida con el modelo conocido 1-12.
    int año_hoy = local_time->tm_year + 1900;       // los años son contados desde 1900 (126 a dia de hoy) por lo qque se hace +1900 para coincidir                                                 con el año del calendario gregoriano 2026 a la fecha

// IMPRESION DE RESULTADO DE LA FECHA ACTUAL EN CONSOLA 
    std::cout << "Fecha actual: " << dia_hoy << "/" << mes_hoy << "/" << año_hoy << std::endl;  // se imprime la fecha actual traducida a lenguaje                                                                                            y calendario usado habitualmente: el gregoriano
    
    
// DIALOGO CON USUARIO PARA LA OBTENCIÓN Y ALMACENADO DE INFORMACIÓN
    std::cout << "Bienvenido al sistema bancario, por favor, introduce tu nombre: " << std::endl;  // pide al usuario su nombre
    std::cin >> name;                                                                              // Almacena lo escrito en variable name
    std::cout << "De acuerdo, "<<name <<" Anota tu dia de nacimiento: " << std::endl;              // Solicita el dia de nacimiento del cliente
    std::cin >> dia_nac;                                                                           // Almacena el valor anotado en dia_nac
    std::cout << "mes de nacimiento (numero de mes): " << std::endl;                               // pide el mes de nacimiento del usuario
    std::cin >> mes_nac;                                                                           // resguarda el valor numerico en mes_nac
    std::cout << "año de nacimiento: " << std::endl;                                               // pide al usuario su año de nacimiento
    std::cin >> año_nac;                                                                           // almacena lo escrito en año_nac
    
// OBTENCION DE VARIABLES DERIVADAS DE LAS ANTERIORES
    año_edad = año_hoy - año_nac;                             // se realiza una igualacion: el año_nac será igual al restante del año de hoy                                                                (obtenido antes del dialogo) menos el año de nacimiento del usuario
    año_mayoria = año_nac + 18;                   // se establece que el año de la mayoria es igual a la suma del año de nacimiento del usuario                                                 mas 18, siendo este ultimo un valor constante.
    
    años_espera = año_mayoria - año_hoy;            // Se calcula la espera en años que el usuario debe llevar a cabo para ser mayor de edad, se                                                 obtiene restando la mayoria de edad al año actual, esa diferencia se asigna a la variable                                                  año_espera
     
// PROCESOS INTERNOS MEDIANTE CICLOS IF-ELSE
    if (mes_nac > mes_hoy || (mes_nac == mes_hoy && dia_nac > dia_hoy))  {   // se establece que: "si el mes de nac. ES MENOR que el mes actual" O                                                                         BIEN "Si el mes de nacimiento ES IGUAL al mes actual Y TAMBIEN el                                                                          dia de nacimiento ES MAYOR al dia actual" procede con la accion if,                                                                         de ser contrario a lo redactado, hacer caso omiso; seria actuar                                                                            bajo el else, pero al evitarlo, se continua como si nada.                                                                                  (NOTA: "||" es compuerta logica or, "&&" es compuerta lógica and, "                                                                         ==" es para comparar, recordando que "=" es para asignar valores) 
       
        año_edad = año_edad - 1;         //  La accion if, si la condicion previa es verdadera, la variable año_edad es reasignada de valor, siendo                                  lo que poseia -1, se justifica porque las condiciones previas son en las que el año acual aun no se                                     cierra, por ende, no se cuenta como un año de edad mas, es hasta que se llega y supera el cumpleaños
        
    }
   
// IMPRESION DE LAS VARIABLES OBTENIDAS AUTOMATICAMENTE PARA MAYOR TRANSPARENCIA DE LOS PROCESOS 
    std::cout << "año para la mayoria de edad = " << año_mayoria << std::endl;    // linea de dialogo anexando variable año_mayoria entre "<<".
    std::cout << "Edad calculada: " << año_edad <<" años."<< std::endl;          // linea de dialogo anexando variable año_edad entre "<<".
    
// IMPRESIÓN DE RESULTADO SEGÚN LOS PROCESOS PREVIOS
    if (año_edad < 18) {                                                  //se abre ciclo if, con la condicion si el año edad ES MENOR que 18.
        
        std::cout << "aun eres menor de edad, debes esperar: "<<años_espera<<" años." << std::endl; //Se imprime este mensaje que anexa la variable                                                                                           años_espera a modo de complemento curioso. 
    }
    else {                                                                                //Else es un "De no cumplirse la condición".
        std::cout << "Muy bien, eres mayor de edad, puedes continuar"  << std::endl;    //Se imprime mensaje de mayoria, porque aqui usuario es                                                                                  igual o mayor de 18 años según lo proporcionado en                                                                                     dialogo previo.
        
    }
    
    
   return 0;   //Se regresan los valores a cero para dar por finalizada la tarea del sistema
}
    










