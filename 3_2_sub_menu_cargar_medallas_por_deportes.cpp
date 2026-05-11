#include "funciones_compartidas.h"
#include "competidores.h"
#include "gestionar.h"
#include "deportes.h"
#include "paises.h"
#include <algorithm> // para min
using namespace std;

///	SUB MENU CARGAR MEDALLAS POR DEPORTES
//	Funciones para la creación de elementos gráficos en la consola
void	mostrarMensajeMenuCargarMedallasEnCoordenadas(int desdeX, int desdeY) {
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "   ___                          __  __        _      _ _                           ___                    _       ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << "  / __|__ _ _ _ __ _ __ _ _ _  |  "<< char(92) <<"/  |___ __| |__ _| | |__ _ ___  _ __  ___ _ _  |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | (__/ _` | '_/ _` / _` | '_| | |"<< char(92) <<"/| / -_) _` / _` | | / _` (_-< | '_ "<< char(92) <<"/ _ "<< char(92) <<" '_| | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_)";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << "  "<< char(92) <<"___"<< char(92) <<"__,_|_| "<< char(92) <<"__, "<< char(92) <<"__,_|_|   |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"__,_/__/ | .__/"<< char(92) <<"___/_|   |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___|";
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "               |___/                                              |_|                      |_|                    ";
}
void	regresarMenu(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << " __  __";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " "<< char(92) <<" "<< char(92) <<"/ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  >  < ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /_/"<< char(92) << "_" << char(92);
}
void	cargarInvidividual(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " / |";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|";
}
void	cargarColectivo(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |_  )";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  / / ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /___|";
}
void	opcion1(int desdeX, int desdeY, bool seleccionada){
	if (seleccionada) 
		cambiarColorTextoFondo(3,0);
	else {
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	cargarInvidividual(desdeX+10, desdeY+1);
	establecerCoordenadasPosicion(desdeX+3, desdeY+6);
	cout << "Cargar Individuales";
	cambiarColorTextoFondo(7,0);
}
void	opcion2(int desdeX, int desdeY, bool seleccionada){
	if(seleccionada) 
		cambiarColorTextoFondo(3,0);
	else{
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	cargarColectivo(desdeX+9, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Cargar Colectivos";
	cambiarColorTextoFondo(7,0);
}
void	opcionX(int desdeX, int desdeY, bool seleccionada){
	if(seleccionada) 
		cambiarColorTextoFondo(3,0);
	else{
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 52, 7);
	regresarMenu(desdeX+7, desdeY+1);
	establecerCoordenadasPosicion(desdeX+17, desdeY+3);
	cout << "Regresar al Menu Principal";
	cambiarColorTextoFondo(7,0);
}
//	Funciones que imprimen una interfaz
void	mostrarInterfazMenuCargarMedallasOpciones() {
	// Opcion 1 - Carga Individual
	opcion1(49, 13, false);
	// Opcion 2 - Carga Colectivos
	opcion2(76, 13, false);
	// Opcion X - Regresar al Menu Principal
	opcionX(49, 22, false);
}
void	mostrarInterfazMenuCargarMedallas() {
	mostrarMensajeMenuCargarMedallasEnCoordenadas(17, 6);
	mostrarInterfazMenuCargarMedallasOpciones();
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionEleccionOpcionesMenuCargarMedallas(char& opcionSeleccionada) { // actualizar
	bool seleccionada = false; // Variable que indica si se ingreso una opcion antes de presionar enter
	char opcion; // Variable para almacenar la opcion momentanea
	
	do {	
		opcion = toupper(_getch());
		switch (opcion) {
		case '1':
			// Opcion 1 - Carga Individual
			opcion1(49, 13, true);
			// Opcion 2 - Carga Colectivos
			opcion2(76, 13, false);
			// Opcion X - Regresar al Menu Principal
			opcionX(49, 22, false);
			seleccionada = true;
			opcionSeleccionada = '1';
			break;
		case '2':
			// Opcion 1 - Carga Individual
			opcion1(49, 13, false);
			// Opcion 2 - Carga Colectivos
			opcion2(76, 13, true);
			// Opcion X - Regresar al Menu Principal
			opcionX(49, 22, false);
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case 'X':
			// Opcion 1 - Carga Individual
			opcion1(49, 13, false);
			// Opcion 2 - Carga Colectivos
			opcion2(76, 13, false);
			// Opcion X - Regresar al Menu Principal
			opcionX(49, 22, true);
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void	procesarInteraccionMenuCargarMedallas(bool & puedeSeguir, archivoCompetencia & Archivo) {
	char opcionSeleccionada; // Variable para almacenar la opcion ingresada por el usuario
	
	do {
		mostrarInterfazMenuCargarMedallas();
		procesarInteraccionEleccionOpcionesMenuCargarMedallas(opcionSeleccionada);
		if (opcionSeleccionada == '1') {
			gestionarSecuenciaCargaDeporteIndividual(puedeSeguir, Archivo);
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '2') {
			gestionarSecuenciaCargaDeporteColectivo(puedeSeguir, Archivo);
			borrarInterfazMenu();
		}
	} while(opcionSeleccionada != 'X');
}
//	Funciones generales de gestion principal
void	gestionarSecuenciaMenuCargarMedallas(bool & puedeSeguir, archivoCompetencia & Archivo) {
	procesarInteraccionMenuCargarMedallas(puedeSeguir, Archivo);
}
///  CARGA DE MEDALLAS POR DEPORTE
//	Funciones para la creación de elementos gráficos en la consola
void 	deportesIndividualesIMG(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  ___                    _            ___         _ _     _    _           _        ";
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << " |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ___ |_ _|_ _  __| (_)_ _(_)__| |_  _ __ _| |___ ___";
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_|_-<  | || ' "<< char(92) <<"/ _` | "<< char(92) <<" V / / _` | || / _` | / -_|_-<";
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << " |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___/__/ |___|_||_"<< char(92) <<"__,_|_|"<< char(92) <<"_/|_"<< char(92) <<"__,_|"<< char(92) <<"_,_"<< char(92) <<"__,_|_"<< char(92) <<"___/__/";
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "          |_|                                                                       ";
}
void 	deportesColectivosIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___                    _             ___     _        _   _            ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ___  / __|___| |___ __| |_(_)_ _____ ___";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_|_-< | (__/ _ "<< char(92) <<" / -_) _|  _| "<< char(92) <<" V / _ (_-<";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___/__/  "<< char(92) <<"___"<< char(92) <<"___/_"<< char(92) <<"___"<< char(92) <<"__|"<< char(92) <<"__|_|"<< char(92) <<"_/"<< char(92) <<"___/__/";	
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "          |_|                                                            ";
}
void 	paisesParticipando(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___      __             ___          _   _    _                    _     ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " | _ "<< char(92) <<"__ _/_/___ ___ ___ | _ "<< char(92) <<"__ _ _ _| |_(_)__(_)_ __  __ _ _ _  __| |___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " |  _/ _` | (_-</ -_|_-< |  _/ _` | '_|  _| / _| | '_ "<< char(92) <<"/ _` | ' "<< char(92) <<"/ _` / _ "<< char(92);
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_| "<< char(92) <<"__,_|_/__/"<< char(92) <<"___/__/ |_| "<< char(92) <<"__,_|_|  "<< char(92) <<"__|_"<< char(92) <<"__|_| .__/"<< char(92) <<"__,_|_||_"<< char(92) <<"__,_"<< char(92) <<"___/";
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "                                                 |_|                       ";
}
void	cuadroIDCargar(int xInicio, int yInicio){
	// Recuadro - Ingrese el ID
	mostrarDibujoRecuadroEnCoordenadas(xInicio + 42, yInicio + 25, 46, 3);
	// Texto - Ingrese el ID
	establecerCoordenadasPosicion(xInicio + 46, yInicio + 26);
	cout << "Ingrese el ID del Deporte a Cargar: ";
}
void	numeroPagina4(int pag, int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio + 101, yInicio + 26);
	cout << "Pagina: " << pag << " de 4";
}
void 	numeroPagina3(int pag, int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio + 101, yInicio + 26);
	cout << "Pagina: "<< pag << " de 3";
}
void	pasarPagIMG(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio + 15, yInicio + 26);
	cout << char(174) << " " << char(175);
	cout << " (Para Desplazarse)";
}
void	regresarConX(int xInicio, int yInicio) {
	establecerCoordenadasPosicion(xInicio + 16, yInicio + 26);
	cout << "X  (Para Regresar)";
}
void	listadoPaisesParticipando(int cantidad, int indice_del_deporte, archivoCompetencia & Archivo){
	int columnas = (cantidad + 3) / 4, // Variable que almacena el calculo de cuántas columnas son necesarias
		inicio, // Variable para almacenar el indice inicial de la columna actual
		fin, // Variable para almacenar el indice final de la columna actual
		vertical, // Variable de incremento vertical para cada país en la columna
		xInicio; // Variable para calcular la posición horizontal de la fila
	
	for (int j = 0; j < columnas; j++) {
		inicio = j * 4; // Índice inicial de la columna actual
		fin = min(inicio + 4, cantidad); // Índice final de la columna actual
		
		if(cantidad <= 4){
			if (j == 0) xInicio = 68;
		}
		else if (cantidad <= 8){
			if (j == 0) xInicio = 52;
			else if (j == 1) xInicio = 82;
		}
		else if(cantidad <= 12){
			if (j == 0) xInicio = 39;
			else if (j == 1) xInicio = 68;
			else if (j == 2) xInicio = 97;
		}
		else if(cantidad <= 16){
			if (j == 0) xInicio = 22;
			else if (j == 1) xInicio = 54;
			else if (j == 2) xInicio = 84;
			else if (j == 3) xInicio = 112;
		}
		
		for (int i = inicio; i < fin; i++) {
			// Incremento vertical para cada país en la columna
			vertical = (i - inicio) * 2;
			// Imprime el indice, si es menor a 10 imprime un 0
			// para que ocupe dos digitos el indice
			establecerCoordenadasPosicion(xInicio, 16 + vertical);
			if (i < 9) cout << "0";
			cout << i + 1 << " | ";
			// Imprime el país correspondiente
			imprimirPais(Archivo.competencia[indice_del_deporte].paises[i]);
			// Pausa para animación
			Sleep(80);
		}
	}
}
void	listadoDeportes(int pagina, char tipo) {	
	int desde, // Variable para almacenar el índice inicial del rango de deportes a mostrar en esta página.
		medio, // Variable para indicar el índice donde se separan los deportes en dos columnas.
		hasta, // Variable para indicar el índice final del rango de deportes a mostrar en esta página.
		desdeX_izq, // Variable para almacenar la coordenada X para la columna izquierda, utilizada al imprimir deportes en la consola.
		desdeX_der, // Variable para almacenar la coordenada X para la columna derecha, utilizada al imprimir deportes en la consola.
		saltoDeLinea = 0; // Variable para controlar la posición vertical de cada línea al imprimir los deportes.
	switch (pagina) {
	case 1:
		desde = 0;
		medio = 7;
		hasta = 14;
		if (tipo == 'i') {
			desdeX_izq = 28;
			desdeX_der = 77;
		}
		else if (tipo == 'c') {
			desdeX_izq = 37;
			desdeX_der = 87;
		}
		break;
	case 2:
		desde = 14;
		medio = 21;
		hasta = 28;
		if (tipo == 'i') {
			desdeX_izq = 30;
			desdeX_der = 79;
		}
		else if (tipo == 'c') {
			desdeX_izq = 23;
			desdeX_der = 85;
		}
		break;
	case 3:
		desde = 28;
		if (tipo == 'i') {
			medio = 35;
			hasta = 42;
			desdeX_izq = 30;
			desdeX_der = 80;
		}
		else if (tipo == 'c') {
			medio = 34;
			desdeX_izq = 66;
		}
		break;
	case 4:
		desde = 42;
		medio = 49;
		hasta = 53;
		desdeX_izq = 35;
		desdeX_der = 98;
		break;
	}
	for (int i = desde; i < medio; i++){
		establecerCoordenadasPosicion(desdeX_izq, 14 + saltoDeLinea);
		// Imprime el indice, si es menor a 10 imprime un 0
		// para que ocupe dos digitos el indice
		if (i < 9) cout << "0";
		cout << i + 1 << " | ";
		//Imprime el tipo de deporte
		if (tipo == 'i') impDeportesInd(i);
		else if (tipo == 'c') impDeportesCol(i);
		// Le suma 2 para que el siguiente se imprima mas abajo
		// dando asi un salto de linea
		saltoDeLinea += 2;
		// Se para un poco para dar un efecto de animacion 
		Sleep(60);
	}
	
	saltoDeLinea = 0;
	
	if ((tipo == 'c' and pagina != 3) or (tipo == 'i')) {
		for (int i = medio; i < hasta; i++){
			establecerCoordenadasPosicion(desdeX_der, 14 + saltoDeLinea);
			// Imprime el indice, si es menor a 10 imprime un 0
			// para que ocupe dos digitos el indice
			if (i < 9) cout << "0";
			cout << i + 1 << " | ";
			//Imprime el tipo de deporte
			if (tipo == 'i') {
				impDeportesInd(i);
			}
			else if (tipo == 'c') {
				impDeportesCol(i);
			}
			// Le suma 2 para que el siguiente se imprima mas abajo
			// dando asi un salto de linea
			saltoDeLinea += 2;
			// Se para un poco para dar un efecto de animacion 
			Sleep(60);
		}
	}
}
//	Funciones que imprimen una interfaz
void	mostrarInterfazMenuCargarDeportes(char tipo) {
	if (tipo == 'i') {
		deportesIndividualesIMG(35, 6);
		numeroPagina4(1, 10, 5);
	}
	else if (tipo == 'c') {
		deportesColectivosIMG(40, 6);
		numeroPagina3(1, 10, 5);
	}
	listadoDeportes(1, tipo);
	cuadroIDCargar(10, 5);
	pasarPagIMG(10, 4);
	regresarConX(10, 6);
}
void 	mostrarInterfazPaisesParticipando(int indice_del_deporte, archivoCompetencia & Archivo) {
	mostrarDibujoRecuadroEnCoordenadas(48, 28, 17, 4);
	establecerCoordenadasPosicion(54, 29);
	cout << "PLATA";
	establecerCoordenadasPosicion(54, 27);
	cout << "-    -";
	
	cambiarColorTextoFondo(6, 0);
	mostrarDibujoRecuadroEnCoordenadas(65, 27, 19, 5);
	establecerCoordenadasPosicion(73, 28);
	cout << "ORO";
	establecerCoordenadasPosicion(72, 26);
	cout << "-    -";
	cambiarColorTextoFondo(7, 0);
	
	cambiarColorTextoFondo(12,0);
	mostrarDibujoRecuadroEnCoordenadas(84, 29, 16, 3);
	establecerCoordenadasPosicion(89, 30);
	cout << "BRONCE";
	establecerCoordenadasPosicion(89, 28);
	cout << "-    -";
	cambiarColorTextoFondo(7,0);
	
	paisesParticipando(37, 6);
	establecerCoordenadasPosicion(22, 13);
	cout << "Deporte: ";
	
	impDeporte(indice_del_deporte);
	regresarConX(10, 4);
	listadoPaisesParticipando(Archivo.competencia[indice_del_deporte].tl, indice_del_deporte, Archivo);
}
//	Funciones para ingresar caracteres por el usuario
int		capturarEntradaDeporte(char tipo) {
	string	bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char	ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	bool	primerDigitoNoEsCero = false; // Variable para indicar si el primer digito es cero
	int 	id = 0, // Variable para almacenar el id a un tipo entero para luego retornarla
		paginaActual = 1; // Variable para indicar la pagina que se imprime en la consola
	
	do { //	Bucle para permitir la entrada de id hasta que se presione ENTER
		ch = _getch(); // Captura la entrada del usuario
		
		if (ch == 'x' or ch == 'X') {
			bufferEntrada = '0';
			ch = '\r';
		}
		// Si se ingrela la flecha izquierda (75 en código ASCII extendido)
		else if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			if (tipo == 'i') {
				numeroPagina4(paginaActual, 10, 5);
			}
			else if (tipo == 'c') {
				numeroPagina3(paginaActual, 10, 5);
			}
			limpiarAreaRecuadroEnCoordenadas(11, 12, 120, 18);
			listadoDeportes(paginaActual, tipo);
		}
		// Si se ingrela la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and tipo == 'i' and paginaActual != 4) {
			paginaActual++;
			numeroPagina4(paginaActual, 10, 5);
			limpiarAreaRecuadroEnCoordenadas(11, 12, 120, 18);
			listadoDeportes(paginaActual, tipo);
		}
		else if (ch == 77 and tipo == 'c' and paginaActual != 3) {
			paginaActual++;
			numeroPagina3(paginaActual, 10, 5);
			limpiarAreaRecuadroEnCoordenadas(11, 12, 120, 18);
			listadoDeportes(paginaActual, tipo);
		}
		else if ((bufferEntrada.size() < 1) and (isdigit(ch))) {
			establecerCoordenadasPosicion(92, 31);
			if (primerDigitoNoEsCero) { // Si ya se ha ingresado un primer dígito diferente de cero
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			}
			else if (ch != '0') { // Si el primer dígito ingresado no es cero
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
				primerDigitoNoEsCero = true; // Permite que se ingresen ceros despues del primer dígito
			}
		}
		else if (bufferEntrada.size() == 1 and isdigit(ch) and ((tipo == 'i' and ((bufferEntrada >= "1" and bufferEntrada <= "4") or (bufferEntrada == "5" and ch < '4'))) or 
				 (tipo == 'c' and ((bufferEntrada >= "1" and bufferEntrada <= "2") or (bufferEntrada == "3" and ch < '5'))))) {
			establecerCoordenadasPosicion(93, 31);
			cout << ch;
			bufferEntrada += ch; // Añade el dígito al buffer
		}
		else if (ch == 8) { // Si se presiona la tecla de retroceso
			if (bufferEntrada.size() == 1) {
				establecerCoordenadasPosicion(93, 31);
				//	Borra el último caracter en la consola
				cout << "\b \b"; // Mueve el cursor hacia atrás, imprime un espacio, y luego mueve el cursor hacia atrás de nuevo
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				// Si el buffer queda vacío
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false; // Nuevamente restringe la entrada de ceros como primer dígito
			}
			else if (bufferEntrada.size() == 2) {
				establecerCoordenadasPosicion(94, 31);
				//	Borra el último caracter en la consola
				cout << "\b \b"; // Mueve el cursor hacia atrás, imprime un espacio, y luego mueve el cursor hacia atrás de nuevo
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				// Si el buffer queda vacío
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false; // Nuevamente restringe la entrada de ceros como primer dígito
			}
		}
	} while (ch != '\r' or bufferEntrada.empty());
	
	//	Convierte bufferEntrada en un número entero
	convertidorAEntero(id, bufferEntrada);
	
	return id;
}
int		capturarEntradaIdPaisPosible(int indice_del_deporte, int posicion, archivoCompetencia & Archivo) {
	string	bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char	ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	bool	primerDigitoNoEsCero = false; // Variable para indicar si el primer digito es cero
	int 	id = 0, // Variable para almacenar el id a un tipo entero para luego retornarla
		ch_entero; // Variable para convertir el caracter a tipo entero
	
	do {//	Bucle para permitir la entrada de id hasta que se presione ENTER
		ch = _getch(); // Captura la entrada del usuario
		ch_entero = (ch - '0');
		
		if (ch == 'x' or ch == 'X') {
			bufferEntrada = "-1";
			ch = '\r';
		}
		else if (Archivo.competencia[indice_del_deporte].tl < 10) {
			if ((bufferEntrada.size() == 0) and (ch_entero <= Archivo.competencia[indice_del_deporte].tl)) {
				switch(posicion) {
				case 0: establecerCoordenadasPosicion(74, 26); break;
				case 1: establecerCoordenadasPosicion(56, 27); break;
				case 2: establecerCoordenadasPosicion(91, 28); break;
				}
				if (isdigit(ch)) { // Verifica si el caracter es un número y si aun no se han ingresado mas de 1 dígitos
					if (primerDigitoNoEsCero) { // Si ya se ha ingresado un primer dígito diferente de cero
						cout << ch;
						bufferEntrada += ch; // Añade el dígito al buffer
					} else if (ch != '0') { // Si el primer dígito ingresado no es cero
						cout << ch;
						bufferEntrada += ch; // Añade el dígito al buffer
						primerDigitoNoEsCero = true; // Permite que se ingresen ceros despues del primer dígito
					}
				}
			}
			else if ((bufferEntrada.size() == 1) and (ch == 8)) {
				// Borra el último caracter en la consola moviendo
				// el cursor hacia atrás, imprime un espacio, y luego
				// mueve el cursor hacia atrás de nuevo
				cout << "\b \b";
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				// Si el buffer queda vacío nuevamente restringe
				// la entrada de ceros como primer dígito
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false;
			}
		}
		else {
			if ((bufferEntrada.size() == 0) and (isdigit(ch))) {
				switch(posicion) {
				case 0: establecerCoordenadasPosicion(74, 26); break;
				case 1: establecerCoordenadasPosicion(56, 27); break;
				case 2: establecerCoordenadasPosicion(91, 28); break;
				}
				if (primerDigitoNoEsCero) { // Si ya se ha ingresado un primer dígito diferente de cero
					cout << ch;
					bufferEntrada += ch; // Añade el dígito al buffer
				} else if (ch != '0') { // Si el primer dígito ingresado no es cero
					cout << ch;
					bufferEntrada += ch; // Añade el dígito al buffer
					primerDigitoNoEsCero = true; // Permite que se ingresen ceros despues del primer dígito
				}
			}
			else if ((bufferEntrada == "1") and (ch_entero <= (Archivo.competencia[indice_del_deporte].tl % 10)) and isdigit(ch)) {
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			}
			else if (((bufferEntrada.size() == 1) or (bufferEntrada.size() == 2)) and (ch == 8)) {
				// Borra el último caracter en la consola moviendo
				// el cursor hacia atrás, imprime un espacio, y luego
				// mueve el cursor hacia atrás de nuevo
				cout << "\b \b";
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				// Si el buffer queda vacío nuevamente restringe
				// la entrada de ceros como primer dígito
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false;
			}
		}
	} while (ch != '\r' or bufferEntrada.empty());
	
	if (bufferEntrada == "-1") id = -1;
	else convertidorAEntero(id, bufferEntrada);
	
	return id;
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionMenuCargarDeporte(bool & puedeSeguir, char tipo, archivoCompetencia & Archivo) {
	bool continuar_menu = true; // Indica si el menu principal debe continuar mostrandose
	int	deporteSeleccionadoLogico, // Variable para almacenar el id del deporte seleccionado de los 87 que hay, siendo del 1 al 87
		deporteSeleccionadoReal, // Variable para almacenar el indice real del deporte, siendo del 0 al 86
		paisSeleccionado, // Variable para almacenar temporalmente el numero de posicion del pais respecto al deporte
		temp[3];
	bool guardarDatos = true;
	
	do {
		borrarInterfazMenu();
		
		mostrarInterfazMenuCargarDeportes(tipo);
		
		deporteSeleccionadoLogico = capturarEntradaDeporte(tipo);
		
		if (deporteSeleccionadoLogico == 0) {
			continuar_menu = false;
		}
		else {
			deporteSeleccionadoReal = convertidorIdDeporte(deporteSeleccionadoLogico, tipo) - 1;
			borrarInterfazMenu();
			mostrarInterfazPaisesParticipando(deporteSeleccionadoReal, Archivo);
			
			for (int i = 0; i < 3; i++) {
				paisSeleccionado = capturarEntradaIdPaisPosible(deporteSeleccionadoReal, i, Archivo);
				// 0 es igual a no haber completado el podio por lo tanto no se tiene
				// que cargar ninguno y se tiene que volver al menu anterior
				if (paisSeleccionado == -1) {
					i = 3; // para salir del bucle
					guardarDatos = false;
				}
				else {
					guardarDatos = true;
					temp[i] = paisSeleccionado;
				}
			}
			
			if (guardarDatos) {
				for (int i = 0; i < 3; i++) {
					Archivo.deporte_medallas[deporteSeleccionadoReal][i] = Archivo.competencia[deporteSeleccionadoReal].paises[temp[i] - 1];
				}
				puedeSeguir = true;
				mostrarInterfazCargaExitosa();
				while (_getch() != 13);
			}
		}
	} while(continuar_menu);
}
//	Funciones generales de gestion principal
void	gestionarSecuenciaCargaDeporteIndividual(bool & puedeSeguir, archivoCompetencia & Archivo) {
	procesarInteraccionMenuCargarDeporte(puedeSeguir, 'i', Archivo);
}
void	gestionarSecuenciaCargaDeporteColectivo(bool & puedeSeguir, archivoCompetencia & Archivo) {
	procesarInteraccionMenuCargarDeporte(puedeSeguir, 'c', Archivo);
}
