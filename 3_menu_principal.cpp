#include "funciones_compartidas.h"
#include "gestionar.h"
#include "competidores.h"
#include <fstream>

void	GuardarArchivo(archivoCompetencia & Archivo){
	ofstream f;
	
	f.open(NombreArchivo(Archivo.fechaCreacion), ios::binary);
	f.write((char *) &Archivo, sizeof(archivoCompetencia));
	f.close();
}
//	Funciones para la creación de elementos gráficos en la consola
void	mostrarMensajeMenuPrincipalEnCoordenadas(int xInicio, int yInicio) {
	//	Posiciona el cursor en la coordenada (xInicio, yInicio) e imprime el mensaje
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " _______                         ______        __               __                __" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "|   |   |.-----..-----..--.--.  |   __ |.----.|__|.-----..----.|__|.-----..---.-.|  |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << "|       ||  -__||     ||  |  |  |    __/|   _||  ||     ||  __||  ||  _  ||  _  ||  |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "|__|_|__||_____||__|__||_____|  |___|   |__|  |__||__|__||____||__||   __||___._||__|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "                                                                   |__|" << endl;	
}
void	mostrarMensajeSalirDeLaApp(int xInicio, int yInicio) {
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 6);
	cout << " ___       _ _          _       _          _        _ _            _  __     ___ " << endl;
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 7);
	cout << "/ __| __ _| (_)_ _   __| |___  | |__ _    /_" << char(92) << "  _ __| (_)__ __ _ __(_)/_/ _ _|__ " << char(92) << endl;
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 8);
	cout << char(92) << "__ "<< char(92) <<"/ _` | | | '_| / _` / -_) | / _` |  / _ " << char(92) << "| '_ " << char(92) << " | / _/ _` / _| / _ " << char(92) << " ' " << char(92) << " /_/" << endl;
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 9);
	cout << "|___/" << char(92) << "__,_|_|_|_|   " << char(92) << "__,_" << char(92) << "___| |_" << char(92) << "__,_| /_/ " << char(92) << "_" << char(92) << " .__/_|_" << char(92) << "__" << char(92) << "__,_" << char(92) << "__|_" << char(92) << "___/_||_(_) " << endl;
	establecerCoordenadasPosicion(xInicio + 2, yInicio + 10);
	cout << "                                              |_|                                " << endl;
	//SI
	establecerCoordenadasPosicion(xInicio + 27, yInicio + 13);
	cout << " ___ ___ " << endl;
	establecerCoordenadasPosicion(xInicio + 27, yInicio + 14);
	cout << "/ __|_ _|" << endl;
	establecerCoordenadasPosicion(xInicio + 27, yInicio + 15);
	cout << char(92) <<"__ "<< char(92) <<"| | " << endl;
	establecerCoordenadasPosicion(xInicio + 27, yInicio + 16);
	cout << "|___/___|" << endl;
	//NO
	establecerCoordenadasPosicion(xInicio + 47, yInicio + 13);
	cout << " _  _  ___  " << endl;
	establecerCoordenadasPosicion(xInicio + 47, yInicio + 14);
	cout << "| " << char(92) << "| |/ _ " << char(92) <<" " << endl;
	establecerCoordenadasPosicion(xInicio + 47, yInicio + 15);
	cout << "| .` | (_) |" << endl;
	establecerCoordenadasPosicion(xInicio + 47, yInicio + 16);
	cout << "|_|"<< char(92) <<"_|"<< char(92) <<"___/ " << endl;
}
void	mostrarDibujoOpcionSeleccionadaSalirDeApp(int xInicio, int yInicio, int ancho, int alto){
	//Laterales
	establecerCoordenadasPosicion(xInicio, yInicio);
	for (int i = 0; i < alto - 1; i++){
		establecerCoordenadasPosicion(xInicio, yInicio + i);
		cout << char(186); // |
		establecerCoordenadasPosicion(xInicio + ancho - 1, yInicio + i);
		cout << char(186); // |
	}
	// Parte de Abajo
	establecerCoordenadasPosicion(xInicio, yInicio + alto - 1);
	cout << char(200); // L
	for (int i = 0; i < ancho - 2; i++){
		cout << char(205); // -
	}
	cout << char(188); // L invertida
}
//	Funciones para ingresar caracteres por el usuario
bool	capturarEntradaSalirDeLaApp() {
	bool seleccionada = false, // Variable para usar como condicion del while que indica si una opcion fue seleccionada o no
		retorno; // Variable que retorna true si se quiere salir del programa o false en caso contrario
	char opcionSeleccionada, // Variable que almacena la opcion seleccionada
		opcion; // Variable que almacena temporalmente la opcion seleccionada
	
	do {
		opcion = toupper(_getch());
		switch (opcion) {
		case 'S':
			limpiarAreaRecuadroEnCoordenadas(78, 24, 13, 1);
			mostrarDibujoOpcionSeleccionadaSalirDeApp(57, 24, 13, 1);
			seleccionada = true;
			opcionSeleccionada = 'S';
			break;
		case 'N':
			limpiarAreaRecuadroEnCoordenadas(57, 24, 13, 1);
			mostrarDibujoOpcionSeleccionadaSalirDeApp(78, 24, 13, 1);
			seleccionada = true;
			opcionSeleccionada = 'N';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
	
	if (opcionSeleccionada == 'S') {
		retorno = true;
	}
	else if (opcionSeleccionada == 'N') {
		retorno = false;
	}
	
	return retorno;
}
//	Funciones que imprimen una interfaz
void	mostrarInterfazMenuPrincipal() {
	mostrarMensajeMenuPrincipalEnCoordenadas(32, 6);
	mostrarDibujoLineaTituloEnCoordenadas(26, 6);
}
void	mostrarAnimacionBarraDeCargaEnCoordenadas(int pasosTotales, int pasoDeDesaceleracion, int velocidadRapidaMs, int velocidadLentaMs, int xInicio, int yInicio)  { // mover para que quede en el centro
	char caracteresDeCarga[] = "|/-\\"; // Arreglo que guarda los caracteres que se mostraran en la carga
	int indiceDeCaracter = 0; // Variable que almacena la posicion que se muestra del arreglo
	const int anchoDeBarra = 50; // Variable que define el ancho de barra
	
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "Cargando: [";
	for (int i = 0; i < anchoDeBarra; ++i) {
		cout << " ";
	}
	cout << "]";
	for (int paso = 0; paso <= pasosTotales; ++paso) {
		int progreso = (paso * anchoDeBarra) / pasosTotales;
		establecerCoordenadasPosicion(xInicio, yInicio);
		cout << "Cargando: [";
		
		for (int i = 0; i < progreso; ++i) {
			cout << "#";
		}
		for (int i = progreso; i < anchoDeBarra; ++i) {
			cout << " ";
		}
		
		cout << "] " << caracteresDeCarga[indiceDeCaracter] << " " << (paso * 100) / pasosTotales << "%";
		indiceDeCaracter = (indiceDeCaracter + 1) % 4;
		
		int delayMs;
		if (paso < pasoDeDesaceleracion) {
			delayMs = velocidadRapidaMs;  // Velocidad rápida para los primeros pasos
		} else {
			delayMs = velocidadLentaMs;   // Velocidad más lenta para los pasos restantes
		}
		Sleep(delayMs);
	}
	//para que desaparezca una vez cargado por completoo
	Sleep(250);
	limpiarAreaRecuadroEnCoordenadas(xInicio, yInicio, 69, 1);
	
	establecerCoordenadasPosicion(xInicio+27, yInicio);
	cout << "Completado!" << endl;
	Sleep(500);
	limpiarAreaRecuadroEnCoordenadas(xInicio, yInicio, 69, 1);
}
void	mostrarInterfazMenuPrincipalOpcionesSoloOpcion_1() {
	establecerCoordenadasPosicion(62, 15);
	cout << "1. Generar Competencia" << endl;
	
	cambiarColorTextoFondo(8, 0); // EFECTO CASCADA COLOR GRIS (Deshabilitado)
	
	establecerCoordenadasPosicion(62, 18);
	cout << "2. Cargar Medallas por Deporte" << endl;
	
	establecerCoordenadasPosicion(62, 21);
	cout << "3. Mostrar Medallero" << endl;
	
	establecerCoordenadasPosicion(62, 24);
	cout << "4. Mostrar Estadísticas" << endl;
	
	cambiarColorTextoFondo(7, 0); // EFECTO CASCADA COLOR Normal (Habilitado)
	
	establecerCoordenadasPosicion(62, 27);
	cout << "X. Salir de la Aplicación" << endl;
	
	establecerCoordenadasPosicion(38, 31);
	cout << "(Presione 1, 2, 3, 4 o X y luego ENTER para ingresar a la opcion que desee)" << endl;
}
void	mostrarInterfazMenuPrincipalOpcionesSoloOpcion_2() {
	cambiarColorTextoFondo(8, 0);
	
	establecerCoordenadasPosicion(62, 15);
	cout << "1. Generar Competencia" << endl;
	
	cambiarColorTextoFondo(7, 0); // EFECTO CASCADA COLOR Normal (Habilitado)
	
	establecerCoordenadasPosicion(62, 18);
	cout << "2. Cargar Medallas por Deporte" << endl;
	
	cambiarColorTextoFondo(8, 0); // EFECTO CASCADA COLOR GRIS (Deshabilitado)
	
	establecerCoordenadasPosicion(62, 21);
	cout << "3. Mostrar Medallero" << endl;
	
	establecerCoordenadasPosicion(62, 24);
	cout << "4. Mostrar Estadísticas" << endl;
	
	cambiarColorTextoFondo(7, 0); // EFECTO CASCADA COLOR Normal (Habilitado)
	
	establecerCoordenadasPosicion(62, 27);
	cout << "X. Salir de la Aplicación" << endl;
	
	establecerCoordenadasPosicion(39, 31);
	cout << "(Presione 1, 2, 3 o X y luego ENTER para ingresar a la opcion que desee)" << endl;
}
void	mostrarInterfazMenuPrincipalOpcionesSoloOpcion_2_3() {
	
	cambiarColorTextoFondo(8, 0); // EFECTO CASCADA COLOR GRIS (Deshabilitado)
	
	establecerCoordenadasPosicion(62, 15);
	cout << "1. Generar Competencia" << endl;
	
	cambiarColorTextoFondo(7, 0); // EFECTO CASCADA COLOR Normal (Habilitado)
	
	establecerCoordenadasPosicion(62, 18);
	cout << "2. Cargar Medallas por Deporte" << endl;
	
	establecerCoordenadasPosicion(62, 21);
	cout << "3. Mostrar Medallero" << endl;
	
	establecerCoordenadasPosicion(62, 24);
	cout << "4. Mostrar Estadísticas" << endl;
	
	establecerCoordenadasPosicion(62, 27);
	cout << "X. Salir de la Aplicación" << endl;
	
	establecerCoordenadasPosicion(39, 31);
	cout << "(Presione 1, 2, 3 o X y luego ENTER para ingresar a la opcion que desee)" << endl;
}
void	mostrarInterFazDespedidaDesdeLaApp() {
	//	Borra lo que se mostro
	limpiarAreaRecuadroEnCoordenadas(32, 11, 85, 17);
	//	Muestra la despedida
	mostrarMensajeDespedida(42, 15);
	//	Mantiene la interfaz anterior 1 segundo
	Sleep(1000);
	//	Borra todo lo impreso en la pantalla de la consola
	system("cls");
}
void	mostrarInterfazSalirDeLaApp() {
	limpiarAreaRecuadroEnCoordenadas(31, 10, 87, 19);
	mostrarDibujoRecuadroEnCoordenadas(31, 10, 87, 19);
	mostrarMensajeSalirDeLaApp(32, 6);
	establecerCoordenadasPosicion(58, 26);
	cout << "(Presione 'S' o 'N' y luego ENTER)" << endl;
}
//	Funciones que "borran" (impriman espacios en la consola)
void	borrarInterfazMenuGenerarCompetencia() {
	limpiarAreaRecuadroEnCoordenadas(23, 6, 104, 26);
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_1(char& opcionSeleccionada) {
	bool seleccionada = false; // para saber si se toco una opcion antes de presionar enter
	char opcion; // opcion momentanea
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '1':
			limpiarAreaRecuadroEnCoordenadas(59, 16, 2, 13);
			mostrarDibujoOpcionSeleccionada(59, 14, 2, 3);
			seleccionada = true;
			opcionSeleccionada = '1';
			break;
		case 'X':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 12);
			mostrarDibujoOpcionSeleccionada(59, 26, 2, 3);
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void	procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_2(char& opcionSeleccionada) {
	bool seleccionada = false; // para saber si se toco una opcion antes de presionar enter
	char opcion; // opcion momentanea
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '2':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 3);
			mostrarDibujoOpcionSeleccionada(59, 17, 2, 3);
			limpiarAreaRecuadroEnCoordenadas(59, 20, 2, 9);
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case 'X':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 12);
			mostrarDibujoOpcionSeleccionada(59, 26, 2, 3);
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void	procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_2_3(char& opcionSeleccionada) {
	bool seleccionada = false; // para saber si se toco una opcion antes de presionar enter
	char opcion; // opcion momentanea
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '2':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 3);
			mostrarDibujoOpcionSeleccionada(59, 17, 2, 3);
			limpiarAreaRecuadroEnCoordenadas(59, 20, 2, 9);
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case '3':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 6);
			limpiarAreaRecuadroEnCoordenadas(59, 23, 2, 6);
			mostrarDibujoOpcionSeleccionada(59, 20, 2, 3);
			seleccionada = true;
			opcionSeleccionada = '3';
			break;
		case '4':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 9);
			mostrarDibujoOpcionSeleccionada(59, 23, 2, 3);
			limpiarAreaRecuadroEnCoordenadas(59, 26, 2, 3);
			seleccionada = true;
			opcionSeleccionada = '4';
			break;
		case 'X':
			limpiarAreaRecuadroEnCoordenadas(59, 14, 2, 12);
			mostrarDibujoOpcionSeleccionada(59, 26, 2, 3);
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
bool	procesarInteraccionSalirDeLaApp(archivoCompetencia & Archivo) {
	bool salirDeLaAplicacion = false; // Variable que indica la opcion indicada
	mostrarInterfazSalirDeLaApp();
	if (capturarEntradaSalirDeLaApp()){ 
		salirDeLaAplicacion = true;
	}
	if (!salirDeLaAplicacion) limpiarAreaRecuadroEnCoordenadas(31, 7, 87, 22);
	return salirDeLaAplicacion;
}
void	procesarInteraccionMenuPrincipal(int id_legajo) {
	bool	continuar_menu = true, // Variable que indica si el menu principal debe continuar mostrandose
		salirDeLaApp = false, // Variable que indica si se quiere salir de la applicacion
		puedeSeguir = false, // Variable que indica si se puede acceder a la opcion tres
		SeguirALaSiguienteOpcion = false; // Variable que indica si al cargar un archivo este esta inicializado su deporte_medallas
	char	opcionSeleccionada; // Variable para almacenar la opcion seleccionada por el usuario
	
	archivoCompetencia Archivo;
	
	do {
		configurarVisibilidadCursor(false);
		mostrarInterfazMenuPrincipal();
		mostrarInterfazMenuPrincipalOpcionesSoloOpcion_1();
		procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_1(opcionSeleccionada);
		if (opcionSeleccionada == '1') {
			borrarInterfazMenuGenerarCompetencia();
			gestionarSecuenciaMenuGenerarCompetencia(id_legajo, continuar_menu, SeguirALaSiguienteOpcion, Archivo);
			borrarInterfazMenuGenerarCompetencia();
		} else if (opcionSeleccionada == 'X') {
			if (procesarInteraccionSalirDeLaApp(Archivo)) {
				mostrarInterFazDespedidaDesdeLaApp();
				salirDeLaApp = true;
				continuar_menu = false;
			}
		}
	} while(continuar_menu);
	
	if ((!salirDeLaApp) and !(SeguirALaSiguienteOpcion)) {
		do {
			configurarVisibilidadCursor(false);
			mostrarInterfazMenuPrincipal();
			mostrarInterfazMenuPrincipalOpcionesSoloOpcion_2();
			procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_2(opcionSeleccionada);
			if (opcionSeleccionada == '2') {
				borrarInterfazMenu();
				gestionarSecuenciaMenuCargarMedallas(puedeSeguir, Archivo);
				borrarInterfazMenu();
			} else if (opcionSeleccionada == 'X') {
				if (procesarInteraccionSalirDeLaApp(Archivo)) {
					mostrarInterFazDespedidaDesdeLaApp();
					GuardarArchivo(Archivo);
					salirDeLaApp = true;
					puedeSeguir = true; // Para salir de la app
				}
			}
		} while(!puedeSeguir);
	}
	
	if (!salirDeLaApp) {
		continuar_menu = true;
		do {
			configurarVisibilidadCursor(false);
			mostrarInterfazMenuPrincipal();
			mostrarInterfazMenuPrincipalOpcionesSoloOpcion_2_3();
			procesarInteraccionEleccionOpcionesMenuPrincipalSoloOpcion_2_3(opcionSeleccionada);
			if (opcionSeleccionada == '2') {
				borrarInterfazMenu();
				gestionarSecuenciaMenuCargarMedallas(puedeSeguir, Archivo);
				borrarInterfazMenu();
			} else if (opcionSeleccionada == '3') {
				borrarInterfazMenu();
				gestionarSecuenciaMenuMostrarMedallero(Archivo);
				borrarInterfazMenu();
			} else if (opcionSeleccionada == '4') {
				borrarInterfazMenu();
				gestionarSecuenciaMenuMostrarEstadisticas(Archivo);
				borrarInterfazMenu();
			} else if (opcionSeleccionada == 'X') {
				if (procesarInteraccionSalirDeLaApp(Archivo)) {
					mostrarInterFazDespedidaDesdeLaApp();
					GuardarArchivo(Archivo);
					continuar_menu = false;
				}
			}
		} while(continuar_menu);
	}
}
//	Funciones generales de gestion principal
void	gestionarSecuenciaMenuPrincipal(int id_legajo) {
	mostrarAnimacionBarraDeCargaEnCoordenadas(100, 75, 20, 100, 42, 21);
	procesarInteraccionMenuPrincipal(id_legajo);
}

