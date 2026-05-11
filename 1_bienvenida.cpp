#include "funciones_compartidas.h"

//	Funciones para la creación de elementos gráficos en la consola
void	mostrarMensajeBienvenidaEnCoordenadas(int xInicio, int yInicio) {
	xInicio = xInicio + 10; // Ajusta la posición horizontal de inicio
	//	Dibuja la primera línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	imprimirCaracterRepetido(254, 5); imprimirCaracterRepetido(255, 4); imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 2); 
	imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 3);
	imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 6);
	imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 4); imprimirCaracterRepetido(255, 6); imprimirCaracterRepetido(254, 4); imprimirCaracterRepetido(255, 6); imprimirCaracterRepetido(254, 2);
	//	Espera 0.1 segundo antes de imprimir la siguiente linea
	Sleep(100);
	//	Dibuja la segunda línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 6);
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,7);
	imprimirCaracterRepetido(254,3); imprimirCaracterRepetido(255,1); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,3); 
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,7); imprimirCaracterRepetido(254, 3); imprimirCaracterRepetido(255, 1); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255, 5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5);
	imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 1); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 4); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2);
	imprimirCaracterRepetido(255, 5); imprimirCaracterRepetido(254, 2);
	//	Espera 0.1 segundo antes de imprimir la siguiente linea
	Sleep(100);
	//	Dibuja la tercera línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 7);
	imprimirCaracterRepetido(254,5); imprimirCaracterRepetido(255,6); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,5); imprimirCaracterRepetido(255,4); imprimirCaracterRepetido(254,6); 
	imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,5); imprimirCaracterRepetido(255,4);
	imprimirCaracterRepetido(254,6); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2);
	imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2);
	//	Espera 0.1 segundo antes de imprimir la siguiente linea
	Sleep(100);
	//	Dibuja la cuarta línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 8);
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2);
	imprimirCaracterRepetido(255,7); imprimirCaracterRepetido(254,6); imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,3); 
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,7); imprimirCaracterRepetido(254,6); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2);
	imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,3); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); 
	imprimirCaracterRepetido(254, 2);
	//	Espera 0.1 segundo antes de imprimir la siguiente linea
	Sleep(100);
	//	Dibuja la quinta línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 9);
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); 
	imprimirCaracterRepetido(255,7); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,1); imprimirCaracterRepetido(254,3); imprimirCaracterRepetido(255,4); imprimirCaracterRepetido(254,4); imprimirCaracterRepetido(255,4); 
	imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,7); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,1); imprimirCaracterRepetido(254,3); imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); 
	imprimirCaracterRepetido(255,5); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,1); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,4); imprimirCaracterRepetido(254,2); imprimirCaracterRepetido(255,2);
	imprimirCaracterRepetido(254,2);
	//	Espera 0.1 segundo antes de imprimir la siguiente linea
	Sleep(100);
	//	Dibuja la sexta línea del mensaje de bienvenida
	establecerCoordenadasPosicion(xInicio, yInicio + 10);
	imprimirCaracterRepetido(254, 5); imprimirCaracterRepetido(255, 4); imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); 
	imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 5); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 5);
	imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 2); imprimirCaracterRepetido(254, 2); imprimirCaracterRepetido(255, 3); 
	imprimirCaracterRepetido(254, 6); imprimirCaracterRepetido(255, 3); imprimirCaracterRepetido(254, 4); imprimirCaracterRepetido(255, 6); imprimirCaracterRepetido(254, 4); imprimirCaracterRepetido(255, 6); 
	imprimirCaracterRepetido(254, 2);
}
void	mostrarMensajeMedalleroOlimpicoEnCoordenadas(int xInicio, int yInicio) {
	//	Posiciona el cursor en coordenadas e imprime las lineas del titulo
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " _______            __         __  __                        _______  __  __                   __" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);	
	cout << "|   |   |.-----..--|  |.---.-.|  ||  |.-----..----..-----.  |       ||  ||__|.--------..-----.|__|.----..-----." << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << "|       ||  -__||  _  ||  _  ||  ||  ||  -__||   _||  _  |  |   -   ||  ||  ||        ||  _  ||  ||  __||  _  |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "|__|_|__||_____||_____||___._||__||__||_____||__|  |_____|  |_______||__||__||__|__|__||   __||__||____||_____|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "                                                                                       |__|" << endl;
}
void	mostrarDibujoMedallaEnCoordenadas(int xInicio, int yInicio) {
	cambiarColorTextoFondo(1, 0); // Fondo negro, texto azul
	establecerCoordenadasPosicion(xInicio - 1, yInicio - 1);
	cout << " ######          ######" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " ######        ######" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "  ######      ###### " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << "   ######    ######  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "     ############    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "       ########      " << endl;
	cambiarColorTextoFondo(6, 0); // Fondo negro, texto amarillo
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << "       ########      " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 6);
	cout << "     ##  ___   ##    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 7);
	cout << "    #   // ||    #   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 8);
	cout << "   #       ||     #  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 9);
	cout << "   #       ||     #  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 10);
	cout << "    #      ||    #   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 11);
	cout << "     ##        ##    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 12);
	cout << "       ########      " << endl;
	cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
}
void	mostrarDibujoAnillosOlimpiadasEnCoordenadas(int colorTexto, int xInicio, int yInicio) {
	cambiarColorTextoFondo(colorTexto, 0);
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "    ##########          ##########          ##########     " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "  ##          ##      ##          ##      ##          ##    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " ##            ##    ##            ##    ##            ##   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "##              ##  ##              ##  ##              ##  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << "##              ##  ##              ##  ##              ##  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << "##            ##########          ##########            ##  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 6);
	cout << " ##         ## ##    ## ##      ## ##    ## ##         ##   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 7);
	cout << "  ##       ## ##      ## ##    ## ##      ## ##       ##    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 8);
	cout << "    ##########          ##########          ##########      " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 9);
	cout << "          ##              ##  ##              ##  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 10);
	cout << "          ##              ##  ##              ##  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 11);
	cout << "           ##            ##    ##            ##   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 12);
	cout << "            ##          ##      ##          ##    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 13);
	cout << "              ##########          ##########      " << endl;
}
//	Funcion que imprime una interfaz
void	mostrarInterfazBienvenida() {
	//	Muestra un recuadro que servirá como contenedor para la interfaz de bienvenida
	mostrarDibujoRecuadroEnCoordenadas(10, 5, 130, 30);
	//	Muestra el mensaje de bienvenida en una posicion específica dentro del recuadro
	mostrarMensajeBienvenidaEnCoordenadas(19, 12);
}
//	Funcion que "borra" (imprimen espacios en la consola)
void	borrarInterfazInterna() {
	//	Borra la interfaz interna de la pantalla dejando solamente el recuadro
	limpiarAreaRecuadroEnCoordenadas(11, 6, 128, 28);
}
//	Funcion que imprime y procesa la interaccion con el usuario
void	mostrarInterfazYProcesarInteraccionMedalleroOlimpico(int xInicio, int yInicio) {
	// Colores para los anillos olímpicos: azul, blanco, rojo, amarillo, verde
	int colores[] = {1, 7, 4, 6, 2};
	bool valor_while = true; // Control del bucle para mostrar los anillos
	// Muestra un recuadro alrededor de la pantalla
	mostrarDibujoRecuadroEnCoordenadas(10, 5, 130, 30);
	// Muestra el título del medallero olímpico
	mostrarMensajeMedalleroOlimpicoEnCoordenadas(xInicio, yInicio);
	// Muestra imágenes de medallas en dos posiciones
	mostrarDibujoMedallaEnCoordenadas(xInicio, yInicio + 8);
	mostrarDibujoMedallaEnCoordenadas(xInicio + 90, yInicio + 8);
	// Establece la posición inicial del cursor
	establecerCoordenadasPosicion(60, 33);
	// Muestra un mensaje al usuario para presionar ENTER para continuar
	cout << "(Presione ENTER para continuar)";
	// Bucle para mostrar los anillos olímpicos con diferentes colores
	while (valor_while) {
		int i = 0;  // Inicializar contador para controlar el ciclo for
		// Control del ciclo for manualmente
		while (i < 5 and valor_while) {
			int color = colores[i];
			mostrarDibujoAnillosOlimpiadasEnCoordenadas(color, xInicio + 27, yInicio + 7);
			Sleep(700);
			// Verifica si se ha presionado una tecla y que esta sea Enter
			if (kbhit() && getch() == 13) { // 13 es el código ASCII para Enter
				valor_while = false; // Salir del bucle while
			}
			i++;
		}
	}
	// Restaura los colores del texto y del fondo a blanco sobre fondo negro
	cambiarColorTextoFondo(7, 0);
}
//	Funciones generales de gestion principal
bool	gestionarSecuenciaBienvenida() {
	//	Oculta el cursor para la presentación limpia
	configurarVisibilidadCursor(false);
	//	Muestra la interfaz de bienvenida
	mostrarInterfazBienvenida();
	//	Espera 0.5 segundos para que el usuario vea la pantalla de bienvenida
	Sleep(500);
	//	Borra la interfaz interna para limpiar el área de bienvenida
	borrarInterfazInterna();
	//	Muestra la interfaz y procesa la interacción del medallero olímpico
	mostrarInterfazYProcesarInteraccionMedalleroOlimpico(19, 9);
	//	Borra la interfaz interna después de procesar el medallero olímpico
	borrarInterfazInterna();
	return true; // Retorna true indicando que la secuencia de bienvenida fue exitosa
}
