#include <iostream>
#include <time.h>
#include "funciones_compartidas.h"
void	convertidorAEntero(int& resultado, string bufferEntrada) {
	for (char c : bufferEntrada) resultado = resultado * 10 + (c - '0');
}
void	limpiarAreaRecuadroEnCoordenadas(int xInicio, int yInicio, int ancho, int alto) {
	//	Borra la parte superior del área
	establecerCoordenadasPosicion(xInicio, yInicio); // Mueve el cursor a la esquina superior izquierda del área
	cout << string(ancho, ' '); // Imprime una línea de espacios en blanco para borrar la parte superior
	
	//	Borra la parte inferior del área
	establecerCoordenadasPosicion(xInicio, yInicio + alto - 1); // Mueve el cursor a la esquina inferior izquierda del área
	cout << string(ancho, ' '); // Imprime una línea de espacios en blanco para borrar la parte inferior
	
	//	Borra los bordes laterales y el interior del área
	for (int i = 1; i < alto - 1; i++) {
		//	Borra el borde izquieda
		establecerCoordenadasPosicion(xInicio, yInicio + i); // Mueve el cursor a la posición del borde izquierdo en la fila actual
		cout << ' '; // Imprime un espacio en blanco para borrar el borde izquierdo
		
		//	Borra el borde derecho
		establecerCoordenadasPosicion(xInicio + ancho - 1, yInicio + i); // Mueve el cursor a la posición del borde derecho en la fila actual
		cout << ' '; // Imprime un espacio en blanco para borrar el borde derecho
		
		//	Borra el área interior
		establecerCoordenadasPosicion(xInicio + 1, yInicio + i); // Mueve el cursor a la posición inicial del área interior
		cout << string(ancho - 2, ' '); // Imprime una línea de espacios en blanco para borrar el área interior
	}
}
void	imprimirCaracterRepetido(int caracter, int veces) {
	//	Imprime el caracter repetido el número de veces espicificado
	for (int i = 0; i < veces; i++) {
		// Imprimee el caracter correspondientte al valor ASCII proporcionado por 'caracter'
		cout << char(caracter);
	}
}
void	establecerCoordenadasPosicion(SHORT xInicio, SHORT yInicio) {
	COORD cp = {xInicio, yInicio};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void	configurarVisibilidadCursor(bool mostrarCursor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = mostrarCursor;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void	cambiarColorTextoFondo(int colorTexto, int colorFondo) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (colorFondo << 4) | colorTexto);
}
void	mostrarDibujoLineaRectaEnCoordenadas(int ancho) {
	//	Dibuja la línea
	for(int i = 0; i < ancho; i++){
		cout << char(196); // Línea horizontal
	}
}
void	mostrarDibujoRecuadroEnCoordenadas(int xInicio, int yInicio, int ancho, int alto) {
	//	Declaración de variables
	int i; // Variable de control para los bucles
	
	//	Posiciona el cursor en la coordenada (xInicio, yInicio)
	establecerCoordenadasPosicion(xInicio, yInicio);
	
	//	Dibuja la línea superior
	cout << char(218); // Esquina superior izquierda
	mostrarDibujoLineaRectaEnCoordenadas(ancho - 2); // Linea horizontal
	cout << char(191); // Esquina superior derecha
	
	//	Dibuja los lados
	for (i = 1; i < alto - 1; i++) {
		establecerCoordenadasPosicion(xInicio, yInicio + i);
		cout << char(179); // Lado izquierdo
		establecerCoordenadasPosicion(xInicio + ancho - 1, yInicio + i);
		cout << char(179); // Lado derecho
	}
	
	//	Dibuja la línea inferior
	establecerCoordenadasPosicion(xInicio, yInicio + alto - 1);
	cout << char(192); // Esquina inferior izquierda
	mostrarDibujoLineaRectaEnCoordenadas(ancho - 2); // Linea horizontal
	cout << char(217); // Esquina inferior derecha
}
void	mostrarDibujoLineaTituloEnCoordenadas(int xInicio, int yInicio) {
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 5);
	
	//	Dibuja una línea horizontal de 92 caracteres de ancho.
	mostrarDibujoLineaRectaEnCoordenadas(92); // Linea horizontal
}
void	mostrarMensajeDespedida(int xInicio, int yInicio) {
	//	Establece la posición inicial del cursor
	establecerCoordenadasPosicion(xInicio, yInicio);
	
	//	Muestra el mensaje "Hasta pronto :("
	cout << "  _    _           _          _____                 _          __  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << " | |  | |         | |        |  __ "<< char(92) <<"               | |         "<< char(92) <<" "<< char(92) <<" " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " | |__| | __ _ ___| |_ __ _  | |__) | __ ___  _ __ | |_ ___   (_) |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << " |  __  |/ _` / __| __/ _` | |  ___/ '__/ _ "<< char(92) <<"| '_ "<< char(92) <<"| __/ _ "<< char(92) <<"    | |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << " | |  | | (_| "<< char(92) <<"__ "<< char(92) <<" || (_| | | |   | | | (_) | | | | || (_) |  _| |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << " |_|  |_|"<< char(92) <<"__,_|___/"<< char(92) <<"__"<< char(92) <<"__,_| |_|   |_|  "<< char(92) <<"___/|_| |_|"<< char(92) <<"__"<< char(92) <<"___/  (_) |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 6);
	cout << "                                                               /_/ " << endl;
}
void	mostrarDibujoOpcionSeleccionada(int xInicio, int yInicio, int ancho, int alto){
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
	// Arriba
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << char(201);
	
	for (int i = 0; i < ancho-1; i++) {
		cout << char(205);
	}
	// Lado
	for (int i = 1; i < alto-1; i++) {
		establecerCoordenadasPosicion(xInicio, yInicio + i);
		cout << char(186);
	}
	// Abajo
	establecerCoordenadasPosicion(xInicio, yInicio + alto - 1);
	cout << char(200); // L o algo asi
	for (int i = 0; i < ancho - 1; i++) {
		cout << char(205);
	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
}
void	borrarInterfazMenu() {
	//	Borra la interfaz interna de la pantalla dejando solamente al recuadro
	limpiarAreaRecuadroEnCoordenadas(11, 6, 128, 28);
}
void	mostrarInterfazCargaExitosa() {
	// Limpiar
	limpiarAreaRecuadroEnCoordenadas(43, 14, 64, 12);
	// Recuadro Interior
	mostrarDibujoRecuadroEnCoordenadas(43, 14, 64, 12);
	
	int xInicio = 47, yInicio = 15;
	
	// Imprimir "CARGA"
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  ___         _ _                                _     		";
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << " | _ \\___  __| (_)___   __ __ _ _ _ __ _ __ _ __| |___ 		";
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " |  _/ _ \\/ _` | / _ \\ / _/ _` | '_/ _` / _` / _` / _ \\		";
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << " |_| \\___/\\__,_|_\\___/ \\__\\__,_|_| \\__, \\__,_\\__,_\\___/		";
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "    _____ _(_) |_ ___ ___ __ _ _ __|___/ _ _| |_ ___   		";
	establecerCoordenadasPosicion(xInicio, yInicio + 5); // Aumenta el espacio para imprimir "EXITOSA" debajo de "CARGA"
	cout << "   / -_) \\ / |  _/ _ (_-</ _` | '  \\/ -_) ' \\  _/ -_)  		";
	establecerCoordenadasPosicion(xInicio, yInicio + 6);
	cout << "   \\___/_\\_\\_|\\__\\___/__/\\__,_|_|_|_\\___|_||_\\__\\___|  		";
	establecerCoordenadasPosicion(xInicio, yInicio + 8);
	cout << "             (Presione ENTER para regresar)";
}
string	NombreArchivo(const tm& fecha) {
	//Generamos los campos para el nombre del archivo
	string anio = to_string(fecha.tm_year + 1900); 
	string mes =  to_string(fecha.tm_mon + 1);
	string dia = to_string(fecha.tm_mday);
	
	string hora = to_string(fecha.tm_hour);
	string min = to_string(fecha.tm_min);
	string seg = to_string(fecha.tm_sec);
	
	string Nombre = anio + "-" + mes + "-" + dia + "-" + hora + "-" + min + "-" + seg + ".bin";
	
	return Nombre;
}
void 	numeroPagina(int pag,int cantPag, int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "Pagina: "<< pag << " de " << cantPag;
}
