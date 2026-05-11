#include "funciones_compartidas.h"
#include "competidores.h"

//	Funciones para la creación de elementos gráficos en la consola
void	mostrarMensajeErrorDefinitivo(int xInicio, int yInicio) {
	//	Cambia el color del texto en rojo dejando el fondo negro
	cambiarColorTextoFondo(4, 0);
	
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " ________  _______     _______      ___   _______     " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "|_   __  ||_   __ "<< char(92) <<"   |_   __ "<< char(92) <<"   .'   `.|_   __ "<< char(92) <<"    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << "  | |_ "<< char(92) <<"_|  | |__) |    | |__) | /  .-.  "<< char(92) <<" | |__) |   " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "  |  _| _   |  __ /     |  __ /  | |   | | |  __ /    " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 4);
	cout << " _| |__/ | _| |  "<< char(92) <<" "<< char(92) <<"_  _| |  "<< char(92) <<" "<< char(92) <<"_"<< char(92) <<"  `-'  /_| |  "<< char(92) <<" "<< char(92) <<"_  " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 5);
	cout << "|________||____| |___||____| |___|`.___.'|____| |___| " << endl;
	
	//	Restablece el color predeterminado (blanco)
	cambiarColorTextoFondo(7, 0);
}
void	mostrarDibujoLineaHorizontalConInterseccionEnCoordenadas(int xInicio, int yInicio) {
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio - 17, yInicio + 25);
	cout << char(195); // Dibuja la intersección de la izquierda
	mostrarDibujoLineaRectaEnCoordenadas(128); // Linea horizontal
	cout << char(180); // Dibuja la intersección de la derecha
}
void	mostrarDibujoLineaVerticalConInterseccionEnCoordenadas(int xInicio, int yInicio) {
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 26, yInicio + 25);
	cout << char(194); // Parte superior
	
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 26, yInicio + 26);
	cout << char(179); // Linea vertical
	
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 26, yInicio + 27);
	cout << char(193); // Parte inferior
	
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 70, yInicio + 25);
	cout << char(194); // Parte superior
	
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 70, yInicio + 26);
	cout << char(179); // Linea vertical
	
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 70, yInicio + 27);
	cout << char(193); // Parte inferior
}
void	mostrarMensajeIntentosEnCoordenadas(int intentoNumero) {
	switch(intentoNumero) {
	case 1: // Actualiza la visualizacion para el primer intento
		establecerCoordenadasPosicion (23, 33); // Posiciona el cursor
		cambiarColorTextoFondo(0, 7); // Fondo blanco, texto negro
		cout << "    1 Intento     "; // Muestra el texto "1 Intento" en la interfaz
		
		establecerCoordenadasPosicion (66, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    2 Intento     "; // Muestra el texto "2 Intento" en la interfaz
		
		establecerCoordenadasPosicion (110, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    3 Intento     "; // Muestra el texto "3 Intento" en la interfaz
		break;
	case 2: // Actualiza la visualizacion para el segundo intento
		establecerCoordenadasPosicion (23, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    1 Intento     "; // Muestra el texto "1 Intento" en la interfaz
		
		establecerCoordenadasPosicion (66, 33); // Posiciona el cursor
		cambiarColorTextoFondo(0, 7); // Fondo blanco, texto negro
		cout << "    2 Intento     "; // Muestra el texto "2 Intento" en la interfaz
		
		establecerCoordenadasPosicion (110, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    3 Intento     "; // Muestra el texto "3 Intento" en la interfaz
		break;
	case 3: // Actualiza la visualizacion para el tercer intento
		establecerCoordenadasPosicion (23, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    1 Intento     "; // Muestra el texto "1 Intento" en la interfaz
		
		establecerCoordenadasPosicion (66, 33); // Posiciona el cursor
		cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
		cout << "    2 Intento     "; // Muestra el texto "2 Intento" en la interfaz
		
		establecerCoordenadasPosicion (110, 33); // Posiciona el cursor
		cambiarColorTextoFondo(0, 7); // Fondo blanco, texto negro
		cout << "    3 Intento     "; // Muestra el texto "3 Intento" en la interfaz
		break;
	}
	
	//	Restaura el color predeterminado de la consola
	cambiarColorTextoFondo(7, 0); // Fondo negro, texto blanco
}
void	mostrarMensajeInicioDeSesionEnCoordenadas(int xInicio, int yInicio) {
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << " _______         __        __              __           _______                __" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 1);
	cout << "|_     _|.-----.|__|.----.|__|.-----.  .--|  |.-----.  |     __|.-----..-----.|__|.-----..-----." << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 2);
	cout << " _|   |_ |     ||  ||  __||  ||  _  |  |  _  ||  -__|  |__     ||  -__||__ --||  ||  _  ||     |" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio + 3);
	cout << "|_______||__|__||__||____||__||_____|  |_____||_____|  |_______||_____||_____||__||_____||__|__|" << endl;
}
void	mostrarSeccionUsuarioEnCoordenadas(int xInicio, int yInicio) {
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 23, yInicio + 12);
	
	//	Muestra el texto "USUARIO: " en la interfaz
	cout << "USUARIO: ";
	
	//	Dibuja un recuadro con tamaño específico
	mostrarDibujoRecuadroEnCoordenadas(43, 20, 22, 3);
}
void	mostrarSeccionContrasenaEnCoordenadas(int xInicio, int yInicio) {
	//	Desplaza la posicion del cursor de la coordenada
	establecerCoordenadasPosicion(xInicio + 66, yInicio + 12);
	
	//	Muestra el texto "CONTRASEÑA: " en la interfaz
	cout << "CONTRASEÑA: ";
	
	//	Dibuja un recuadro con tamaño específico
	mostrarDibujoRecuadroEnCoordenadas(88, 20, 21, 3);
}
//	Funciones para calcular la contraseña
int		extraerDigitoEnPosicion(int numero, int posicion) {
	int	resultado, // Variable para guardar el último dígito
		numDigitos; // Variable para calcular el numero de dígitos del numero
	
	//	Calcula el número de dígitos en el número
	numDigitos = log10(numero) + 1;
	
	//	Verifica si la posicion solicitada es la del último dígito
	if (numDigitos == posicion) {
		//	Si es la última posición, extrae el último dígito
		resultado = numero % 10;
	}
	else {
		//	Si no, elimina el último dígito y llama recursivamente a la función con el número truncado
		resultado = extraerDigitoEnPosicion((numero - numero % 10) / 10, posicion);
	}
	
	return resultado; // Devuelve el dígito en la posición especificada
}
int		encontrarSiguienteCapicua(int numero) {
	int resultado; // Variable para guardar el numero capicúa
	
	//	Verifica si el primer y el tercer digito del número son iguales
	if (extraerDigitoEnPosicion(numero, 1) == extraerDigitoEnPosicion(numero, 3)) {
		resultado = numero; // Si son iguales, el número ya es capicúa
	}
	else {
		resultado = encontrarSiguienteCapicua(numero + 1); // Si no, llama recursivamente a la función sumando 1 al número
	}
	
	return resultado; // Devuelve el número capicúa encontrado
	
}
int		calcularContrasena(int idUsuario) {
	int	contrasena; // Variable para almacenar la contraseña generada
	
	if (idUsuario == 99999) { // si el ID del usuario es 99999, se le asigna automaticamente la contraseña correcta
		contrasena = 2027023; // la contraseña correcta
	}
	else {
		int	TresDigitos; // Combina tres dígitos extraídos del ID del usuario
		
		//	Extrae los dígitos en las posiciones 1, 3 y 5 del ID del usuario y los
		//	combina para formar un número de tres dígitos
		TresDigitos = 100 * extraerDigitoEnPosicion(idUsuario, 1) + 10 * extraerDigitoEnPosicion(idUsuario, 3) + extraerDigitoEnPosicion(idUsuario, 5);
		
		//	Calcula la contraseña utilizando una fórmula que involucra el año 2024,
		//	el siguiente número capicúa después de 'TresDigitos', y una combinacion
		//	de los dígitos en las posiciones 3, 4 y 5 del ID del usuario
		contrasena = 2024 * encontrarSiguienteCapicua(TresDigitos) + 100 * extraerDigitoEnPosicion(idUsuario, 3) + 10 * extraerDigitoEnPosicion(idUsuario, 4) + extraerDigitoEnPosicion(idUsuario, 5);
	}
	
	return contrasena; // Retorna la contraseña generada
}
//	Funciones para ingresar el usuario y contraseña
int		capturarEntradaContrasena (bool& reintentar_login_usuario) {
	string	bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char	ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	int		contrasena_ingresada = 0; // Variable para almacenar la contraseña en un tipo entero para luego retornarla
	bool	primerDigitoNoEsCero = false, // Variable para indicar si el primer digito es cero
		mostrar_numeros = false; // Variable para indicar si se muestran los numeros o asteriscos
	
	reintentar_login_usuario = false; // Reinicia el valor a false
	
	//	Bucle hasta que se presione Enter ('r')
	do {
		ch = _getch(); // Captura una tecla
		
		if (isdigit(ch) and bufferEntrada.size() < 7) {
			if (primerDigitoNoEsCero) { // si el primer digito no es un cero, permite imprimer cualquier digito incluido el cero ya que no va a ser el primer digito
				cout	<<	(mostrar_numeros ? ch : '*'); // si mostrar_numeros es true muestre el caracter, si no muestra "*"
				bufferEntrada += ch;
				
			}
			else if (ch != '0') {
				cout	<<	(mostrar_numeros ? ch : '*'); // si mostrar_numeros es true muestre el caracter, si no muestra "*"
				bufferEntrada += ch;
				primerDigitoNoEsCero = true; // deja que se impriman ceros, ya que no es mas el primer digito
			}
		}
		// Verifica si se quiere borrar
		else if ((ch == 8) and (!bufferEntrada.empty())){
			// Borra el ?ltimo car?cter en la consola
			cout << "\b \b";  // Mueve el cursor hacia atr?s, imprime un espacio, y luego mueve el cursor hacia atr?s de nuevo
			
			// Elimina el ultimo car?cter de la cadena
			bufferEntrada.pop_back();
			
			// Verifica si hay ningun numero
			if(bufferEntrada.empty()) primerDigitoNoEsCero = false; // vuelve a no dejar que se impriman ceros como primer digito
		}
		// Revela o no la contraseña
		if ((ch == 'V') or (ch == 'v')) {
			mostrar_numeros = !mostrar_numeros;
			for (unsigned long long i = 0; i < bufferEntrada.length(); ++i) 
				cout << "\b \b";
			cout << (mostrar_numeros ? bufferEntrada : string(bufferEntrada.length(), '*'));
		}
		//
		else if ((ch == 'X') or (ch == 'x')) {
			reintentar_login_usuario = true; // Para volver a ingresar un numero de usuario
			ch = '\r'; // Para salir del bucle
		}
	} while((ch != '\r') or bufferEntrada.empty());
	
	if (ch != 'X' or ch != 'x') {
		convertidorAEntero(contrasena_ingresada, bufferEntrada);
	}
	
	return contrasena_ingresada;
}
void	capturarEntradaIdUsuario(int& idUsuario) {
	string	bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char	ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	bool	primerDigitoNoEsCero = false; // Variable para indicar si el primer digito es cero
	
	idUsuario = 0; // 	Reinicia el valor a cero
	
	//	Bucle hasta que se presione Enter ('r')	
	while (ch != '\r') {
		ch = _getch(); // Captura una tecla
		if (isdigit(ch) and bufferEntrada.size() < 5) {
			if (primerDigitoNoEsCero) { // si el primer digito no es un cero, permite imprimer cualquier digito incluido el cero ya que no va a ser el primer digito
				cout <<	ch; // si mostrar_numeros es true muestre el caracter, si no muestra "*"
				bufferEntrada += ch;
				
			}
			else if (ch != '0') {
				cout <<	ch; // si mostrar_numeros es true muestre el caracter, si no muestra "*"
				bufferEntrada += ch;
				primerDigitoNoEsCero = true; // deja que se impriman ceros, ya que no es mas el primer digito
			}
		}
		else if ((ch == 8) and (!bufferEntrada.empty())){
			// Borra el ?ltimo car?cter en la consola
			cout << "\b \b";  // Mueve el cursor hacia atr?s, imprime un espacio, y luego mueve el cursor hacia atr?s de nuevo
			
			// Elimina el ultimo car?cter de la cadena
			bufferEntrada.pop_back();
			
			// Verifica si hay ningun numero
			if(bufferEntrada.empty()) primerDigitoNoEsCero = false; // vuelve a no dejar que se impriman ceros como primer digito
		}
	}
	
	//	Convierte el buffer de entrada en un número entero
	convertidorAEntero(idUsuario, bufferEntrada);
}
//	Funciones que imprimen una interfaz
void	mostrarInterfazErrorDefinitivo() {
	limpiarAreaRecuadroEnCoordenadas(31, 9, 87, 20);
	mostrarDibujoRecuadroEnCoordenadas(31, 9, 87, 20);
	mostrarMensajeErrorDefinitivo(48, 14);
	// Descripcion
	establecerCoordenadasPosicion(60, 23);
	cout << "¡Demasiados Intentos Fallidos!" << endl;
	establecerCoordenadasPosicion(54, 25);
	cout << "(Vuelva a Iniciar la App para Reintentar)" << endl;
}
void	mostrarInterfazLoginContrasena() {
	configurarVisibilidadCursor(false);
	//	Muestra el apartado de intentos de ingreso para la contraseña
	mostrarDibujoLineaHorizontalConInterseccionEnCoordenadas(27, 7);
	mostrarDibujoLineaVerticalConInterseccionEnCoordenadas(27, 7);
	mostrarMensajeIntentosEnCoordenadas(1);
	establecerCoordenadasPosicion(46, 25);
	cout << ">> Presiona la tecla 'X' para volver a ingresar el usuario.";
	establecerCoordenadasPosicion(45, 27);
	cout << ">> Presiona la tecla 'V' para mostrar u ocultar la contraseña.";
}
void	mostrarInterfazLogin() {
	//	Muestra el mensaje "inicio de sesion"
	mostrarMensajeInicioDeSesionEnCoordenadas(27, 7);
	//	Muestra una linea para el título "inicio de sesion"
	mostrarDibujoLineaTituloEnCoordenadas(27, 7);
	//	Muestra la seccion en donde se ingresa el nombre de usuario
	mostrarSeccionUsuarioEnCoordenadas(27, 7);
	//	Muestra la seccion en donde se ingresa la contraseña
	mostrarSeccionContrasenaEnCoordenadas(27, 7);
}
void	mostrarInterfazDespedida() {
	//	Borra lo que se mostro
	limpiarAreaRecuadroEnCoordenadas(32, 10, 85, 18);
	//	Muestra la despedida
	mostrarMensajeDespedida(42, 15);
	//	Mantiene la interfaz anterior 1 segundo
	Sleep(1000);
	//	Borra todo lo impreso en la pantalla de la consola
	system("cls");
}
//	Funciones que "borran" (impriman espacios en la consola)
void	borrarPosibleMensajeErrorUsuario(bool primer_error) {
	//	Verifica si se mostró un mensaje de error durante el proceso
	if (!primer_error)
		//	Borra el área donde se mostró el mensaje de error de ID de usuario
		limpiarAreaRecuadroEnCoordenadas(34, 28, 83, 1);
}
void	borrarInterfazLogin() {
	// Borra la interfaz interna de la pantalla dejando solamente al recuadro
	limpiarAreaRecuadroEnCoordenadas(11, 6, 128, 28);
	// Imprime lineas verticales y horizontales en los lugares
	// donde tiene que reemplazar las intersecciones
	establecerCoordenadasPosicion(10, 32);
	cout << char(179); // Linea vertical
	establecerCoordenadasPosicion(139, 32);
	cout << char(179); // Linea vertical
	establecerCoordenadasPosicion(53, 34);
	cout << char(196); // Linea horizontal
	establecerCoordenadasPosicion(97, 34);
	cout << char(196); // Linea horizontal
	configurarVisibilidadCursor(false);
}
void	actualizarPantallaParaIngresarUsuario() {
	configurarVisibilidadCursor(false);
	// Borra el área de la pantalla donde se mostraron mensajes o entradas anteriores
	limpiarAreaRecuadroEnCoordenadas(11, 23, 128, 11);
	limpiarAreaRecuadroEnCoordenadas(95, 21, 8, 1);
	// Redibuja el recuadro principal en la pantalla, preparando
	// la interfaz para el siguiente ingreso del usuario
	mostrarDibujoRecuadroEnCoordenadas(10, 5, 130, 30);
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionLoginUsuario(int& idUsuario, bool& primer_error) {
	bool	continuarIngreso = true; //	Variable para controlar la continuación
	do { //	Bucle que continúa hasta que se ingrese un ID de usuario válido
		//	Borra el área donde se mostró el intento anterior de ingresar el ID de usuario
		limpiarAreaRecuadroEnCoordenadas(51, 21, 5, 1);
		//	Posiciona el cursor para la entrada del ID de usuario
		establecerCoordenadasPosicion(51, 21);
		//	Muestra el cursor para indicar al usuario que puede escribir
		configurarVisibilidadCursor(true);
		//	Permite que el usuario ingrese su ID
		capturarEntradaIdUsuario(idUsuario);
		//	Verifica si el ID de usuario ingresado está dentro del rango válido (10000 a 99999)
		if (idUsuario >= 10000 and idUsuario <= 99999) {
			continuarIngreso = false; // Sale del bucle si el ID es válido
		}
		else if (primer_error){
			//	Si es la primero vez que se comente un error en el ingreso, muestra el mensaje de error
			configurarVisibilidadCursor(false);
			establecerCoordenadasPosicion(34, 28);
			cout << "El usuario ingresado no existe. Aseg?rate de que el nombre de usuario sea correcto." << endl;
			primer_error = false; // Cambia el estado de primer_error a false para que no se vuelva a reimprimir el mensaje de error
		}
	} while(continuarIngreso);
}
void	procesarInteraccionLoginContrasena(int idUsuario, bool& reintentar_login_usuario, bool& loginExitoso) {
	bool	continuarValidacion = true; // Variable para controlar el flujo del bucle while
	int		contrasena_generada, contrasena_ingresada, contador_intentos = 1;
	//	Reinicio de valores
	reintentar_login_usuario = false;
	loginExitoso = false;
	//	Bucle que permite hasta 3 intentos para ingresar la contraseña correcta
	while (continuarValidacion and contador_intentos <= 3) {
		//	Incrementa el contador de intentos
		contador_intentos++;
		//	Obtiene la contraseña generada para el usuario
		contrasena_generada = calcularContrasena(idUsuario);
		//	Posiciona el cursor para la entrada del ID de usuario
		establecerCoordenadasPosicion(95, 21);
		//	Muestra el cursor para indicar al usuario que puede escribir
		configurarVisibilidadCursor(true);
		//	Captura la contraseña ingresada por el usuario
		contrasena_ingresada = capturarEntradaContrasena(reintentar_login_usuario);
		//	Si el usuario decide reintentar el login, limpia las áreas necesarias y sale del bucle
		if (reintentar_login_usuario) {
			limpiarAreaRecuadroEnCoordenadas(11, 23, 128, 11);
			limpiarAreaRecuadroEnCoordenadas(95, 21, 8, 1);
			//	Muestra el mensaje de intentos restantes y limpia el área de entrada
			mostrarMensajeIntentosEnCoordenadas(contador_intentos);
			continuarValidacion = false;
		}
		//	Si la contraseña ingresada es correcta, marca el login como exitoso y sale del bucle
		else if (contrasena_generada == contrasena_ingresada) {
			loginExitoso = true;
			continuarValidacion = false;
		}
		//	Muestra el mensaje de intentos restantes y limpia el área de entrada
		mostrarMensajeIntentosEnCoordenadas(contador_intentos);
		limpiarAreaRecuadroEnCoordenadas(95, 21, 8, 1);
	}
}
bool	procesarInteraccionLogin(bool& loginExitoso, int id_legajo) {
	bool	reintentar_login_usuario; // Indica si se debe reintentar el login de usuario
	bool	primer_error = true; // Controla si el error ha sido mostrado una vez
	do {
		//	Procesa la interacción para ingresar el ID de usuario
		procesarInteraccionLoginUsuario(id_legajo, primer_error);
		//	Borra el posible mensaje de error del ID de usuario si se mostró
		borrarPosibleMensajeErrorUsuario(primer_error);
		//	Muestra la interfaz para ingresar la contraseña
		mostrarInterfazLoginContrasena();
		//	Procesa la interacción de la contraseña
		procesarInteraccionLoginContrasena(id_legajo, reintentar_login_usuario, loginExitoso);
		//	Si el usuario desea reingresar su ID, se borra la pantalla para ello
		if (reintentar_login_usuario) actualizarPantallaParaIngresarUsuario();
	} while(reintentar_login_usuario); // Repite el proceso si se necesita reintentar el login
	
	return loginExitoso; // Devuelve si el login fue exitoso
}
//	Funciones generales de gestion principal
bool	gestionarSecuenciaLogin(int id_legajo) {
	bool loginExitoso; // Indica si el login fue exitoso
	mostrarInterfazLogin(); // Muestra la interfaz de login
	//	Procesa la interacción del login y maneja el estado de éxito
	if (procesarInteraccionLogin(loginExitoso, id_legajo)) {
		borrarInterfazLogin(); // Borra la interfaz si el login fue exitoso
		Sleep(100); // Espera 0.1 segundos antes de seguir para mejorar la experiencia
	} else {
		//	Oculta el cursor para la presentación limpia
		configurarVisibilidadCursor(false);
		//	Muestra la interfaz grafica que indica el ultimo error de contraseña disponible que se tenia (al intentar ingresarla 3 veces)
		mostrarInterfazErrorDefinitivo();
		//	Mantiene la interfaz anterior 3 segundos
		Sleep(3000);
		//	Muestra la interfaz de despedida
		mostrarInterfazDespedida();
	}
	
	return loginExitoso; // Retorna el estado de éxito del login
}
