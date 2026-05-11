#include <ctime>
#include <fstream>
#include "funciones_compartidas.h"
#include "gestionar.h"
#include "competidores.h"
using namespace std;

//	Funcion que generan y cargan Archivo
void	GenerarArchivo(archivoCompetencia & Archivo){
	time_t ahora;
	time(&ahora);
	tm *temp = localtime(&ahora);
	Archivo.fechaCreacion = *temp;
	
	string Nombre = NombreArchivo(Archivo.fechaCreacion);
	
	ofstream f;
	
	f.open(Nombre, ios::binary);
	
	f.write((char *) &Archivo, sizeof(archivoCompetencia));
	f.close();
}
void	rellenarConMenos1DeporteMedallas(archivoCompetencia & Archivo) {
	for (int i = 0; i < 87; i++) {
		for (int j = 0; j < 3; j++) {
			Archivo.deporte_medallas[i][j] = -1;
		}
	}
}
void	generarCompetencia(archivoCompetencia & Archivo) {
	srand(time(NULL));
	int nArreglo, nMax, Auxiliar;
	
	for (int i = 0; i < 87; i++) {
		nMax = 4 + rand() % 13;  // Número de países que competirán (entre 4 y 16)
		Auxiliar = nArreglo = 0;
		
		for (int i=0; i<87;i++) {
			int nMax = 4 + rand() % (13);
			nArreglo = 0;
			
			while (nArreglo<nMax) {
				do {
					Auxiliar = 0;
					// Se le asigna un valor aleatorio entre 1 y 196 a cada pais
					Archivo.competencia[i].paises[nArreglo] = 1 + rand() % (197);
					
					if (Archivo.competencia[i].paises[nArreglo] / 197 == 1) {
						Archivo.competencia[i].paises[nArreglo]--;
					}
					
					for (int o = 0; o < 87; o++) {
						if ((nArreglo != o) and (Archivo.competencia[i].paises[nArreglo] == Archivo.competencia[i].paises[o])) {
							Auxiliar = 1;
						}
					}
					
				} while(Auxiliar==1);
				
				nArreglo++;
			}
		}
		// Se le asigna el tamaño logico, osea la cantidad de paises cargados
		Archivo.competencia[i].tl = nMax;
	}
}
int 	generarNumeroAleatorio() {
	return rand() % 100;  // Números entre 0 y 99
}
bool	BuscarArchivo(int AAAA, int MM, int DD, int HH, int MIN , int SS, archivoCompetencia & Archivo){
	string Nombre;
	bool encontro;
	
	string anio = to_string(AAAA); 
	string mes =  to_string(MM);
	string dia = to_string(DD);
	
	string hora = to_string(HH);
	string min = to_string(MIN);
	string seg = to_string(SS);
	
	Nombre = anio + "-" + mes + "-" + dia + "-" + hora + "-" + min + "-" + seg + ".bin";
	
	ifstream f;
	
	f.open(Nombre, ios::binary);
	
	if (f.fail()){
		encontro = false;
	}
	else{
		f.read((char *) &Archivo, sizeof(archivoCompetencia));
		f.close();
		encontro = true;
	}
	
	return encontro;
}
bool	estaCargadoDeporteMedallas(archivoCompetencia Archivo) {
	bool retorno = false;
	for (int i = 0; i < 87; i++) {
		if (Archivo.deporte_medallas[i][0] != -1) {
			retorno = true;
		}
	}
	return retorno;
}
// DIBUJOS
void 	uno(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " / |";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|";
}
void 	dos(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |_  )";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  / / ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /___|";
}
void 	equis(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << " __  __";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " "<< char(92) <<" "<< char(92) <<"/ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  >  < ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /_/"<< char(92) << "_" << char(92);
}
void 	titulo_GenerarCompetencia(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "   ____                                   ____                           _                  _       " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "  / ___| ___ _ __   ___ _ __ __ _ _ __   / ___|___  _ __ ___  _ __   ___| |_ ___ _ __   ___(_) __ _ " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " | |  _ / _ "<< char(92) <<" '_ "<< char(92) <<" / _ "<< char(92) <<" '__/ _` | '__| | |   / _ "<< char(92) <<"| '_ ` _ "<< char(92) <<"| '_ "<< char(92) <<" / _ "<< char(92) <<" __/ _ "<< char(92) <<" '_ "<< char(92) <<" / __| |/ _` |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << " | |_| |  __/ | | |  __/ | | (_| | |    | |__| (_) | | | | | | |_) |  __/ ||  __/ | | | (__| | (_| |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "  "<< char(92) <<"____|"<< char(92) <<"___|_| |_|"<< char(92) <<"___|_|  "<< char(92) <<"__,_|_|     "<< char(92) <<"____"<< char(92) <<"___/|_| |_| |_| .__/ "<< char(92) <<"___|"<< char(92) <<"__"<< char(92) <<"___|_| |_|"<< char(92) <<"___|_|"<< char(92) <<"__,_|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << "                                                             |_|                                    " << endl;
}
void	titulo_GenerandoCompetencia(int xInicio, int yInicio) {
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " _____                           _        _____                   _               _     " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "|   __|___ ___ ___ ___ ___ ___ _| |___   |     |___ _____ ___ ___| |_ ___ ___ ___|_|___ " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << "|  |  | -_|   | -_|  _| .'|   | . | . |  |   --| . |     | . | -_|  _| -_|   |  _| | .'|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "|_____|___|_|_|___|_| |__,|_|_|___|___|  |_____|___|_|_|_|  _|___|_| |___|_|_|___|_|__,|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "                                                         |_|                            " << endl;
}
void 	titulo_CargarCompetencia(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "   ____                              ____                           _                  _       " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "  / ___|__ _ _ __ __ _  __ _ _ __   / ___|___  _ __ ___  _ __   ___| |_ ___ _ __   ___(_) __ _ " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " | |   / _` | '__/ _` |/ _` | '__| | |   / _ "<< char(92) <<"| '_ ` _ "<< char(92) <<"| '_ "<< char(92) <<" / _ "<< char(92) <<" __/ _ "<< char(92) <<" '_ "<< char(92) <<" / __| |/ _` |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << " | |__| (_| | | | (_| | (_| | |    | |__| (_) | | | | | | |_) |  __/ ||  __/ | | | (__| | (_| |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "  "<< char(92) <<"____"<< char(92) <<"__,_|_|  "<< char(92) <<"__, |"<< char(92) <<"__,_|_|     "<< char(92) <<"____"<< char(92) <<"___/|_| |_| |_| .__/ "<< char(92) <<"___|"<< char(92) <<"__"<< char(92) <<"___|_| |_|"<< char(92) <<"___|_|"<< char(92) <<"__,_|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << "                 |___/                                  |_|                                    " << endl;
}
void 	dibujo_RecuadroMatriz(int xInicio, int yInicio) {
	//1er linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 10);
	cout << char(218);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(194);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(194);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(191);
	
	//2da Linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 11);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	
	//3ta linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 12);
	cout << char(195);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(197);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(197);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(180);
	
	//4ta Linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 13);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	
	//5ra Linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 14);
	cout << char(195);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(197);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(197);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(180);
	
	//6ta Linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 15);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	cout << char(32) << char(32) << char(32) << char(32);
	cout << char(179);
	
	//7ma Linea
	establecerCoordenadasPosicion(xInicio + 31, yInicio + 16);
	cout << char(192);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(193);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(193);
	cout << char(196) << char(196) << char(196) << char(196);
	cout << char(217);
}
void 	dibujo_Matriz(int matriz[3][3], int xInicio, int yInicio) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			// Posicionar el cursor en la consola
			COORD coord;
			coord.X = xInicio + j * 5;  // Ajusta la posición horizontal de los números
			coord.Y = yInicio + i * 2;  // Ajusta la posición vertical de los números
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			
			// Mostrar el número con formato de dos dígitos (si es menor a 10, agregar un '0' delante)
			cout << (matriz[i][j] < 10 ? "0" : "") << matriz[i][j];
		}
	}
}
void	animacion_Matriz(int xInicio, int yInicio, int duracionSeg) {
	srand(time(0));  // Semilla para los números aleatorios
	
	// Matriz de velocidades (en milisegundos) asignada manualmente para cada número
	int velocidades[3][3] = {
		// tiempos en milisegundos para los números
		{60, 50, 60},  // Fila 1
	{70, 50, 40},  // Fila 2
		{40, 60, 40}   // Fila 3
	};
	
	int matriz[3][3];       // Matriz de 3x3 para almacenar los números
	
	// Inicializar la matriz con números aleatorios
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matriz[i][j] = generarNumeroAleatorio();  // Generar el primer número
		}
	}
	
	int ciclos = duracionSeg * 1000;  // Duración total en milisegundos
	
	for (int t = 0; t < ciclos; t += 50) {  // El bucle principal se ejecuta en intervalos de 50 ms
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				// Verificar si es momento de actualizar el número basado en la velocidad específica
				if (t % velocidades[i][j] == 0) {
					matriz[i][j] = generarNumeroAleatorio();  // Generar un nuevo número
				}
			}
		}
		
		// Mostrar la matriz actualizada
		dibujo_Matriz(matriz, xInicio + 38, yInicio + 12);
		Sleep(50);  // Pausa de 50 ms entre cada ciclo
	}
	
	limpiarAreaRecuadroEnCoordenadas(xInicio + 24, yInicio + 20, 41, 1);
	establecerCoordenadasPosicion(xInicio + 27, yInicio + 20);
	cambiarColorTextoFondo(2, 0);
	cout << "¡Competencia Generada Exitosamente!";
	cambiarColorTextoFondo(7, 0);
	establecerCoordenadasPosicion(xInicio + 30, yInicio + 22);
	Sleep(1000);
	cout << "(Presione ENTER para Continuar)";
}
// Opciones (Color, Recuadro, Texto)
void 	opcion1_nuevaCompetencia(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	uno(desdeX+10, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Nueva Competencia";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcion2_cargarCompetencia(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	dos(desdeX+9, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Cargar Competencia";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcionX_regresar(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 52, 7);
	
	// Texto
	equis(desdeX+7, desdeY+1);
	establecerCoordenadasPosicion(desdeX+17, desdeY+3);
	cout << "Regresar al Menu Principal";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
	
//	Funcion para capturar el ingreso de la fecha de cargar competencia
void 	capturarEntradaFecha(int& AAAA, int& MM, int& DD, int& HH, int& MIN , int& SS, char& tipo) {
	string bufferEntrada;  // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char ch = '0', temp;   // Variable para almacenar el carácter ingresado por el usuario y el último carácter
	int dato = 0;           // Variable que indica el número de caracteres ingresados
	int x = 63;             // Variable para almacenar la coordenada horizontal (posición del cursor)
	
	establecerCoordenadasPosicion(67, 20);
	cout << "/";
	establecerCoordenadasPosicion(70, 20);
	cout << "/";
	establecerCoordenadasPosicion(73, 20);
	cout << " - ";
	establecerCoordenadasPosicion(78, 20);
	cout << ":";
	establecerCoordenadasPosicion(81, 20);
	cout << ":";
	
	establecerCoordenadasPosicion(x, 20);
	
	// Bucle principal para capturar la entrada
	while (ch != '\r') { // Enter para finalizar
		ch = _getch();
		temp = ch;
		
		// Validar si el carácter es un dígito y no se excede la cantidad de numeros validos
		if (isdigit(ch) && dato < 14) {
			// Ajustar el cursor para saltar los separadores
			if (dato == 4 or dato == 6 or dato == 10 or dato == 12) {
				establecerCoordenadasPosicion(++x, 20);
			} else if (dato == 8) {
				x += 3;
				establecerCoordenadasPosicion(x, 20);
			}
			// Mostrar el carácter y agregarlo al buffer
			cout << ch;
			bufferEntrada += ch;
			dato++;
			x++;
		}
		// Manejar la tecla de borrar
		else if (ch == 8 && dato > 0) { // Backspace y al menos un carácter ingresado
			// Borrar el carácter en el buffer y en pantalla
			establecerCoordenadasPosicion(--x, 20);
			cout << " ";
			establecerCoordenadasPosicion(x, 20);
			
			dato--;
			bufferEntrada.erase(dato, 1);
			
			if (dato == 4 || dato == 6) {
				x--;
			} else if (dato == 8) {
				x -= 3;
			} else if (dato == 10 || dato == 12) {
				x--;
			}
		}
		// Si se presiona 'X' o 'x', salir del ciclo
		else if (ch == 'X' || ch == 'x') {
			temp = ch;
			ch = '\r';  // Cambiar ch a Enter para salir del ciclo
		}
		else if (ch == '\r' and dato < 14) {
			ch = 0; // para que no envie una respuesta incompleta
		}
	}
	
	tipo = temp;
	
	if (ch != 'X' or ch != 'x') {
		long long int valor = 0;
		for (char c : bufferEntrada) valor = valor * 10 + (c - '0');
		
		AAAA = valor / 10000000000;
		valor %= 10000000000;
		
		MM = valor / 100000000;
		valor %= 100000000;
		
		DD = valor / 1000000;
		valor %= 1000000;
		
		HH = valor / 10000;
		valor %= 10000;
		
		MIN = valor / 100;
		SS = valor % 100;
	}
}
//	Funciones que imprimen una interfaz
void 	Interfaz_GenerarCompetencia(){
	titulo_GenerarCompetencia(25, 6);
	
	opcion1_nuevaCompetencia(49, 13, false);
	opcion2_cargarCompetencia(76, 13, false);
	opcionX_regresar(49, 22, false);
}
void	Interfaz_GenerarNuevaCompetencia() {
	borrarInterfazMenu();
	
	//Recuadro Interior
	mostrarDibujoRecuadroEnCoordenadas(28, 10, 94, 22);
	
	//Dibujo Matriz
	dibujo_RecuadroMatriz(36, 8);
	
	// Generando Matriz Titulo
	establecerCoordenadasPosicion(65, 27);
	titulo_GenerandoCompetencia(31, 11);
	
	// Mensaje de Espera
	establecerCoordenadasPosicion(55, 27);
	cout << "(Espere un momento, no tardara demasiado)";
	
	animacion_Matriz(31, 7, 3);
}
void 	Interfaz_GenerarNuevaCompetenciaConExito(archivoCompetencia & Archivo) {
	int legajo = Archivo.legajo,
		ano = Archivo.fechaCreacion.tm_year + 1900,
		mes = Archivo.fechaCreacion.tm_mon + 1,
		dia = Archivo.fechaCreacion.tm_mday,
		hora = Archivo.fechaCreacion.tm_hour,
		min = Archivo.fechaCreacion.tm_min,
		seg = Archivo.fechaCreacion.tm_sec;
	
	limpiarAreaRecuadroEnCoordenadas(30, 23, 80, 6);
	
	establecerCoordenadasPosicion(58, 24);
	cambiarColorTextoFondo(2, 0);
	cout << "¡Competencia Encontrada y Cargada!" << endl;
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(48, 26);
	cout << "Legajo: " << legajo << endl;
	establecerCoordenadasPosicion(66, 26);
	cout << "Fecha: " << ano << "/" << mes << "/" << dia << endl;
	establecerCoordenadasPosicion(88, 26);
	cout << "Hora: " << hora << ":" << min << ":" << seg << endl;
	
	establecerCoordenadasPosicion(60, 29);
	cout << "(Presione ENTER para Regresar)" << endl;
}
void 	Interfaz_CargarCompetencia(){
	borrarInterfazMenu();
	
	//Recuadro Interior - Original(28, 10, 94, 22)
	mostrarDibujoRecuadroEnCoordenadas(25, 8, 100, 24);
	titulo_CargarCompetencia(27, 9);
	
	// Recuadro Solicitar Fecha
	establecerCoordenadasPosicion(58, 18);
	cout << "Ingrese la Fecha de la Competencia" << endl;
	mostrarDibujoRecuadroEnCoordenadas(50, 19, 50, 3);
	establecerCoordenadasPosicion(55, 22);
	cout << "Año - Mes - Dia | Hora - Minuto - Segundo" << endl;
	establecerCoordenadasPosicion(52, 24);
	cout << "Incluir 0 delante de los digitos menores a 10" << endl;
	establecerCoordenadasPosicion(58, 26);
	cout << "Presione 'X' para regresar al menu" << endl;
	
}
void	Interfaz_CompetenciaNoEncontrada() {
	limpiarAreaRecuadroEnCoordenadas(30, 23, 80, 6);
	
	establecerCoordenadasPosicion(62, 25);
	cambiarColorTextoFondo(4, 0);
	cout << "Competencia NO Encontrada!";
	cambiarColorTextoFondo(7, 0);
	establecerCoordenadasPosicion(60, 27);
	cout << "(Presione ENTER para regresar)";
}
//	Funciones generales de gestion principal
void	InteraccionEleccion_MenuGenerarCompetencia(char& opcionSeleccionada) {
	bool seleccionada = false; // Variable que indica si se ingreso una opcion antes de presionar enter
	char opcion; // Variable para almacenar temporalmente la opcion ingresada
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '1':
			opcion1_nuevaCompetencia(49, 13, true);
			opcion2_cargarCompetencia(76, 13, false);
			opcionX_regresar(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '1';
			break;
		case '2':
			opcion1_nuevaCompetencia(49, 13, false);
			opcion2_cargarCompetencia(76, 13, true);
			opcionX_regresar(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case 'X':
			opcion1_nuevaCompetencia(49, 13, false);
			opcion2_cargarCompetencia(76, 13, false);
			opcionX_regresar(49, 22, true);
			
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void 	Interaccion_MenuGenerarCompetencia(int id_legajo, bool & continuar_menu, bool & SeguirALaSiguienteOpcion, archivoCompetencia & Archivo){
	char opcionSeleccionada; // Variable para almacenar el caracter ingresado
	bool puedeSalir = false;
	
	do {
		Interfaz_GenerarCompetencia();
		InteraccionEleccion_MenuGenerarCompetencia(opcionSeleccionada);
		
		if (opcionSeleccionada == '1') {
			Interfaz_GenerarNuevaCompetencia();
			
			Archivo.legajo = id_legajo;
			GenerarArchivo(Archivo);
			generarCompetencia(Archivo);
			rellenarConMenos1DeporteMedallas(Archivo);
			
			while (_getch() != 13);
			
			borrarInterfazMenu();
			
			continuar_menu = false;
			puedeSalir = true;
		}
		else if (opcionSeleccionada == '2') {
			// Variables para almacenar la fecha de creacion del archivo
			int AAAA = 0,
				MM = 0,
				DD = 0,
				HH = 0,
				MIN = 0,
				SS = 0;
			char tipo; // Variable para indicar se se volvio con x o con enter
			
			Interfaz_CargarCompetencia();
			capturarEntradaFecha(AAAA, MM, DD, HH, MIN, SS, tipo);
			
			if (BuscarArchivo(AAAA, MM, DD, HH, MIN, SS, Archivo)) {
				Interfaz_GenerarNuevaCompetenciaConExito(Archivo);
				
				if (estaCargadoDeporteMedallas(Archivo)) {
					SeguirALaSiguienteOpcion = true;
				}
				
				continuar_menu = false;
				puedeSalir = true;
				
				while (_getch() != 13);
			}
			else if (tipo == '\r') {
				Interfaz_CompetenciaNoEncontrada();
				
				while (_getch() != 13);
			}
			
			borrarInterfazMenu();
		}
		else if (opcionSeleccionada == 'X' or opcionSeleccionada == 'x') {
			puedeSalir = true;
		}
		
	} while(!(puedeSalir));
}
void	gestionarSecuenciaMenuGenerarCompetencia(int id_legajo, bool & continuar_menu, bool & SeguirALaSiguienteOpcion, archivoCompetencia & Archivo) {
	Interaccion_MenuGenerarCompetencia(id_legajo, continuar_menu, SeguirALaSiguienteOpcion, Archivo);
}
