#include "funciones_compartidas.h"
#include "gestionar.h"
#include "competidores.h"
#include "paises.h"
#include "deportes.h"
#include <algorithm>

using namespace std;
///	FUNCIONES COMPARTIDAS ENTRE TODAS
//	Funciones de ordenamiento
void	merge(int medallasIdDeLosPaises[], int medallasOro[], int medallasPlata[], int medallasBronce[], int inicio1, int final1, int inicio2, int final2) {
	int i, j, k, c_paises[196], c_oro[196], c_plata[196], c_bronce[196];
	i = inicio1;
	j = inicio2;
	k = 0;
	
	while (i <= final1 and j <= final2) {
		if (medallasOro[i] == medallasOro[j]) {
			if (medallasPlata[i] == medallasPlata[j]) {
				if (medallasBronce[i] > medallasBronce[j]) {
					c_paises[k] = medallasIdDeLosPaises[i];
					c_oro[k] = medallasOro[i];
					c_plata[k] = medallasPlata[i];
					c_bronce[k++] = medallasBronce[i++];
				}
				else {
					c_paises[k] = medallasIdDeLosPaises[j];
					c_oro[k] = medallasOro[j];
					c_plata[k] = medallasPlata[j];
					c_bronce[k++] = medallasBronce[j++];
				}
			}
			else if (medallasPlata[i] > medallasPlata[j]) {
				c_paises[k] = medallasIdDeLosPaises[i];
				c_oro[k] = medallasOro[i];
				c_plata[k] = medallasPlata[i];
				c_bronce[k++] = medallasBronce[i++];
			}
			else {
				c_paises[k] = medallasIdDeLosPaises[j];
				c_oro[k] = medallasOro[j];
				c_plata[k] = medallasPlata[j];
				c_bronce[k++] = medallasBronce[j++];
			}
		}
		else if (medallasOro[i] > medallasOro[j]) {
			c_paises[k] = medallasIdDeLosPaises[i];
			c_oro[k] = medallasOro[i];
			c_plata[k] = medallasPlata[i];
			c_bronce[k++] = medallasBronce[i++];
		}
		else {
			c_paises[k] = medallasIdDeLosPaises[j];
			c_oro[k] = medallasOro[j];
			c_plata[k] = medallasPlata[j];
			c_bronce[k++] = medallasBronce[j++];
		}
	}
	while (i <= final1) {
		c_paises[k] = medallasIdDeLosPaises[i];
		c_oro[k] = medallasOro[i];
		c_plata[k] = medallasPlata[i];
		c_bronce[k++] = medallasBronce[i++];
	}
	while (j <= final2) {
		c_paises[k] = medallasIdDeLosPaises[j];
		c_oro[k] = medallasOro[j];
		c_plata[k] = medallasPlata[j];
		c_bronce[k++] = medallasBronce[j++];
	}
	
	for (k = 0; k < final2 - inicio1 + 1; k++){
		medallasIdDeLosPaises[inicio1 + k] = c_paises[k];
		medallasOro[inicio1 + k] = c_oro[k];
		medallasPlata[inicio1 + k] = c_plata[k];
		medallasBronce[inicio1 + k] = c_bronce[k];
	}
}
void	mergesort(int medallasIdDeLosPaises[], int medallasOro[], int medallasPlata[], int medallasBronce[], int inicio, int finall) {
	if (finall - inicio != 0) {
		mergesort(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, inicio, (inicio + finall) / 2);
		mergesort(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, (inicio + finall) / 2 + 1, finall);
		merge(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, inicio, (inicio + finall) / 2, (inicio + finall) / 2 + 1, finall);
	}
}
void 	pasarPagIMGMedalleroPorPaises(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX+19, desdeY+26);
	cout << char(174) << "  " << char(175);
	establecerCoordenadasPosicion(desdeX+12, desdeY+27);
	cout << "(Para Desplazarse)";
}
void 	regresarIMGMedalleroPorPaises(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX+18, desdeY+26);
	cout << " X ";
	establecerCoordenadasPosicion(desdeX+12, desdeY+27);
	cout << "(Para Regresar)";
}
/// MOSTRAR MEDALLERO POR DEPORTE
void	imprimirListaPaisesPodioDelDeporte(int desdeX, int desdeY, int indice_del_deporte, archivoCompetencia Archivo){
	int color, // Variable para almacenar el color de la letra segun la medalla
		espacios = 0, // Variable de incremento para la cordenada de la columna para saltos de linea
		contador = 0, // Variable para contar la cantidad de deportes cargados
		OROdeportesCargados[87] = {-1}, // Arreglo para almacenar los deportes cargados
		PLATAdeportesCargados[87] = {-1}, // Arreglo para almacenar los deportes cargados
		BRONCEdeportesCargados[87] = {-1}; // Arreglo para almacenar los deportes cargados
	
	// Recuadro de Ventana
	mostrarDibujoRecuadroEnCoordenadas(desdeX - 10, desdeY - 2, 80, 17);
	// Recuadro del Titulo
	mostrarDibujoRecuadroEnCoordenadas(desdeX - 5, desdeY, 70, 3);
	// Titulo
	establecerCoordenadasPosicion(desdeX - 3, desdeY + 1);
	cout << "PUESTO";
	establecerCoordenadasPosicion(desdeX + 6, desdeY + 1);
	cout << "PAIS";
	establecerCoordenadasPosicion(desdeX + 42, desdeY + 1);
	cout << "RESULTADOS";
	
	// Calcula la cantidad de deportes cargados
	for (int i = 0; i < 87; i++) {
		if (Archivo.deporte_medallas[i][0] != -1) {
			OROdeportesCargados[contador] = Archivo.deporte_medallas[i][0];
			PLATAdeportesCargados[contador] = Archivo.deporte_medallas[i][1];
			BRONCEdeportesCargados[contador] = Archivo.deporte_medallas[i][2];
			contador++;
		}
	}
	
	// Muestra los 3 paises cargados en el deporte
	for (int i = 0; i < 3 ; i++) {
		Sleep(200);
		// Establecer el color según la posición
		if (i == 0) color = 6;  // Oro
		else if (i == 1) color = 7;  // Plata
		else if (i == 2) color = 12;  // Bronce
		// Para los Números
		establecerCoordenadasPosicion(desdeX - 1, desdeY + 4 + espacios);
		cambiarColorTextoFondo(color, 0);
		cout << "0" << (i + 1);
		// Para el País
		establecerCoordenadasPosicion(desdeX + 6, desdeY + 4 + espacios);
		if (i == 0) imprimirPais(OROdeportesCargados[indice_del_deporte - 1]);
		else if (i == 1) imprimirPais(PLATAdeportesCargados[indice_del_deporte - 1]);
		else if (i == 2) imprimirPais(BRONCEdeportesCargados[indice_del_deporte - 1]);
		
		// Para la cantidad de medallas - ORO
		establecerCoordenadasPosicion(desdeX + 39, desdeY + 4 + espacios);
		if (i == 0) cout << "Ha Ganado el ORO!";  // Oro
		else if (i == 1) cout << "Ha Ganado la PLATA!";  // Plata
		else if (i == 2) cout << "Ha Ganado el BRONCE!";  // Bronce
		espacios += 2; // Aumentar espacio para la siguiente línea
		contador++;
	}
	cambiarColorTextoFondo(7, 0); // Reset color
}
void	imprimirListaDeportes(int desdeX, int desdeY, int pagina, archivoCompetencia Archivo){
	int cantidadPaginas, // Variable para almacenar la cantidad de paginas
		cantidad = 0, // Variable para almacenar la cantidad de deportes cargados
		vertical = 0, // Variable de incremento vertical para cada deporte en la columna
		contador = 0, // Variable para contar la cantidad de deportes cargados
		desde = pagina * 7 - 7, // Variable para almacenar los limites del bucle que muestra los deportes
		hasta = pagina * 7, // Variable para almacenar los limites del bucle que muestra los deportes
		numeroDeporteDeListaCargada = (pagina - 1) * 7, // Variable para almacenar la posicion desde cuanto arranca a mostrar los deportes segun la pagina actual
		deportesCargados[87] = {-1}; // Arreglo para almacenar los deportes cargados
	
	mostrarDibujoRecuadroEnCoordenadas(desdeX+63, desdeY+7, 19, 3);
	// Calcula la cantidad de deportes cargados
	for (int i = 0; i < 87; i++) {
		if (Archivo.deporte_medallas[i][0] != -1) {
			deportesCargados[contador] = i;
			contador++;
			cantidad++;
		}
	}
	
	// Calcula la cantidad de paginas que se van a mostrar
	if (cantidad % 7 != 0) cantidadPaginas = (cantidad / 7) + 1;
	else cantidadPaginas = (cantidad / 7);
	// Muestra el numero de la pagina actual
	numeroPagina(pagina, cantidadPaginas, desdeX + 65, desdeY + 8);
	// Si esta en la ultima pag
	if (pagina == cantidadPaginas) {
		if (hasta > cantidad) hasta = cantidad;
	}
	// Muestra los deportes seleccionado de la pagina actual
	for (int i = desde; i < hasta; i++) {
		establecerCoordenadasPosicion(53, 15 + vertical);
		// Imprime el indice, si es menor a 10 imprime un 0
		// para que ocupe dos digitos el indice
		if(i<9) cout << "0";
		cout << i+1 << " | ";
		// Imprime el deporte correspondiente
		imprimirDeporte(deportesCargados[numeroDeporteDeListaCargada] + 1);
		// Para que se imprima con saltos de linea
		vertical += 2;
		// Para que imprima el siguiente deporte (si es que hay)
		numeroDeporteDeListaCargada++;
		// Pausa para animación
		Sleep(60);
	}
}
void 	medalleroPorDeporteIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  __  __        _      _ _                               ___                    _       ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |  "<< char(92) <<"/  |___ __| |__ _| | |___ _ _ ___   _ __  ___ _ _  |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |"<< char(92) <<"/| / -_) _` / _` | | / -_) '_/ _ "<< char(92) <<" | '_ "<< char(92) <<"/ _ "<< char(92) <<" '_| | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_)";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"___|_| "<< char(92) <<"___/ | .__/"<< char(92) <<"___/_|   |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___|";
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "                                        |_|                      |_|                    ";
	/*"<< char(92) <<"*/
}
void 	cuadroIDCargarPorDeporte(int desdeX, int desdeY){
	// Recuadro - Ingrese el ID
	mostrarDibujoRecuadroEnCoordenadas(desdeX+42, desdeY+23, 46, 3);
	// Texto - Ingrese el ID
	establecerCoordenadasPosicion(desdeX+46, desdeY+24);
	cout << "Ingrese el ID del Deporte a Cargar: ";
}
//	Funcion que imprime una interfaz
void	mostrarInterfazMostrarMedalleroPorDeporte() {
	medalleroPorDeporteIMG(30, 6);
	regresarIMGMedalleroPorPaises(5, 4);
	pasarPagIMGMedalleroPorPaises(106, 4);
	cuadroIDCargarPorDeporte(10, 7);
}
void 	mostrarInterfazPodioDelDeporte() {
	limpiarAreaRecuadroEnCoordenadas(35, 10, 80, 20);
	mostrarDibujoRecuadroEnCoordenadas(63, 24, 21, 3);
	establecerCoordenadasPosicion(64, 25);
	cout << "ENTER (Para Cerrar)";
}
//	Funciones de calculos
int		capturarEntradaPorDeporte(archivoCompetencia Archivo) {
	string bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	bool primerDigitoNoEsCero = false, // Variable para indicar si el primer digito es cero
		sePuedeBorrar; //Variable para indicar que, si bufferEntrada tiene contenido, se puede borrar
	int	cantidadPaginas, // Variable para almacenar la cantidad de paginas
		ch_entero, // Variable para convertir el caracter a tipo entero
		id = 0, // Variable para almacenar el id a un tipo entero para luego retornarla
		cantidad = 0, // Variable para almacenar la cantidad de deportes cargados
		paginaActual = 1; // Variable para indicar la pagina que se imprime en la consola
	
	// Calcula la cantidad de deportes cargados
	for (int i = 0; i < 87; i++) {
		if (Archivo.deporte_medallas[i][0] != -1) cantidad++;
	}
	// Calcula la cantidad de paginas que se van a mostrar
	if (cantidad % 7 != 0) cantidadPaginas = (cantidad / 7) + 1;
	else cantidadPaginas = (cantidad / 7);
	
	//	Bucle para permitir la entrada de id hasta que se presione ENTER
	do {
		// Mismo caracter en distintas tipo de variables
		ch = _getch(); // Variable char
		ch_entero = (ch - '0'); // Variable int
		
		if (ch == 'x' or ch == 'X') {
			bufferEntrada = "-1";
			ch = '\r';
		}
		// Si se ingresa la flecha izquierda (75 en código ASCII extendido)
		else if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			limpiarAreaRecuadroEnCoordenadas(11, 12, 120, 18);
			imprimirListaDeportes(2, 4, paginaActual, Archivo);
		}
		// Si se ingresa la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and paginaActual != cantidadPaginas) {
			paginaActual++;
			limpiarAreaRecuadroEnCoordenadas(11, 12, 120, 18);
			imprimirListaDeportes(2, 4, paginaActual, Archivo);
		}
		// Si la cantidad de deportes cargados es menor a 9
		else if ((cantidad < 10) and (ch_entero <= cantidad and bufferEntrada.size() < 1) and (isdigit(ch))) {
			establecerCoordenadasPosicion(92, 31);
			if (primerDigitoNoEsCero) { // Si ya se ha ingresado un primer dígito diferente de cero
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			} else if (ch != '0') { // Si el primer dígito ingresado no es cero
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
				primerDigitoNoEsCero = true; // Permite que se ingresen ceros despues del primer dígito
			}
		}
		// Si la cantidad de deportes cargados es mayor o igual a 10
		else if ((cantidad >= 10) and (isdigit(ch))) {
			if (bufferEntrada.empty()) {
				establecerCoordenadasPosicion(92, 31);
				if (primerDigitoNoEsCero) { // Si ya se ha ingresado un primer dígito diferente de cero
					cout << ch;
					bufferEntrada += ch; // Añade el dígito al buffer
				} else if (ch != '0') { // Si el primer dígito ingresado no es cero
					cout << ch;
					bufferEntrada += ch; // Añade el dígito al buffer
					primerDigitoNoEsCero = true; // Permite que se ingresen ceros despues del primer dígito
				}
			}
			else if (bufferEntrada.size() == 1 and ((bufferEntrada[0] - '0') < (cantidad / 10) or ((bufferEntrada[0] - '0') == (cantidad / 10) and ch_entero <= cantidad % 10))) {
				establecerCoordenadasPosicion(93, 31);
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
				
			}
		}
		else if (ch == 8) {
			sePuedeBorrar = false;
			switch (bufferEntrada.size()) {
			case 1:
				establecerCoordenadasPosicion(93, 31); 
				sePuedeBorrar = true;
				break;
			case 2:
				establecerCoordenadasPosicion(94, 31);
				sePuedeBorrar = true;
				break;
			}
			if (sePuedeBorrar) {
				//	Borra el último caracter en la consola
				cout << "\b \b"; // Mueve el cursor hacia atrás, imprime un espacio, y luego mueve el cursor hacia atrás de nuevo
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				// Si el buffer queda vacío
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false; // Nuevamente restringe la entrada de ceros como primer dígito
			}
		}
	} while (ch != '\r' or bufferEntrada.empty());
	
	if (bufferEntrada == "-1") id = -1; 
	else convertidorAEntero(id, bufferEntrada); //	Convierte bufferEntrada en un número entero
	
	return id;
}
//	Funcion que imprime y procesa la interaccion con el usuario
void	procesarInteraccionMostrarMedalleroPorDeporte(archivoCompetencia Archivo) {
	bool	continuar_menu = true; // Variable para indicar si el menu principal debe continuar mostrandose
	int		dato; // Variable para almacenar el deporte seleccionado
	
	do {
		borrarInterfazMenu();
		mostrarInterfazMostrarMedalleroPorDeporte();
		imprimirListaDeportes(2, 4, 1, Archivo);
		dato = capturarEntradaPorDeporte(Archivo);
		if (dato == -1) continuar_menu = false;
		else {
			mostrarInterfazPodioDelDeporte();
			imprimirListaPaisesPodioDelDeporte(45, 13, dato, Archivo);
			while (_getch() != 13);
		}
	} while(continuar_menu);
}
///	MOSTRAR MEDALLERO POR PAIS
//	Funciones para la creación de elementos gráficos en la consola
void 	medalleroPorPaisesIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  __  __        _      _ _                               ___      __   ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |  "<< char(92) <<"/  |___ __| |__ _| | |___ _ _ ___   _ __  ___ _ _  | _ "<< char(92) <<"__ _/_/___";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |"<< char(92) <<"/| / -_) _` / _` | | / -_) '_/ _ "<< char(92) <<" | '_ "<< char(92) <<"/ _ "<< char(92) <<" '_| |  _/ _` | (_-<";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"___|_| "<< char(92) <<"___/ | .__/"<< char(92) <<"___/_|   |_| "<< char(92) <<"__,_|_/__/";
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "                                        |_|                            ";
}
//	Funcion que imprime una interfaz
void	mostrarInterfazMostrarMedalleroPorPais() {
	// Titulo - Medallero por Paises
	medalleroPorPaisesIMG(39, 6);
	// Recuadro
	mostrarDibujoRecuadroEnCoordenadas(117, 11, 20, 3);
	// Pasar Pag Flechas
	pasarPagIMGMedalleroPorPaises(106, 4);
	// Regresar
	regresarIMGMedalleroPorPaises(5, 4);
	// Recuadro de las posiciones
	mostrarDibujoRecuadroEnCoordenadas(35, 11, 80, 3);
	// Titulos dentro del recuadro
	establecerCoordenadasPosicion(40, 12);
	cout << "PUESTO";
	establecerCoordenadasPosicion(51, 12);
	cout << "PAIS";
	establecerCoordenadasPosicion(79, 12);
	cout << "ORO";
	establecerCoordenadasPosicion(88, 12);
	cout << "PLATA";
	establecerCoordenadasPosicion(98, 12);
	cout << "BRONCE";
	establecerCoordenadasPosicion(108, 12);
	cout << "TOTAL";
}
//	Funciones de calculos
void 	listadoPaisesConMedallas(int medallasIdDeLosPaises[], int medallasOro[], int medallasPlata[], int medallasBronce[], int paginaactual, int paises_con_medallas) {
	int inicio = (paginaactual - 1) * 10,
		finall = min(paises_con_medallas, paginaactual * 10),
		espacios = 0;
	
	for (int i = inicio; i < finall; i++) {
		if (i < paises_con_medallas) {
			Sleep(60);
			int color = 7; // Color por defecto (blanco)
			// Establecer el color según la posición
			if (i == 0) color = 6;  // Oro
			else if (i == 1) color = 8;  // Plata
			else if (i == 2) color = 12;  // Bronce
			// Para los Números
			establecerCoordenadasPosicion(42, 14 + espacios);
			cambiarColorTextoFondo(color, 0);
			cout << (i < 9 ? "0" : "") << i + 1;
			// Para el País
			establecerCoordenadasPosicion(51, 14 + espacios);
			imprimirPais(medallasIdDeLosPaises[i]);
			// Para la cantidad de medallas
			establecerCoordenadasPosicion(80, 14 + espacios);
			cout << medallasOro[i];
			establecerCoordenadasPosicion(90, 14 + espacios);
			cout << medallasPlata[i];
			establecerCoordenadasPosicion(100, 14 + espacios);
			cout << medallasBronce[i];
			establecerCoordenadasPosicion(110, 14 + espacios);
			cout << medallasOro[i] + medallasPlata[i] + medallasBronce[i];
			// Reset color
			cambiarColorTextoFondo(7, 0);
			espacios += 2; // Aumentar espacio para la siguiente línea
		}
	}
}
void	capturarEntrada(int paises_con_medallas, int medallasIdDeLosPaises[], int medallasOro[], int medallasPlata[], int medallasBronce[])  {
	int	paginaActual = 1, // Indica la pagina que se imprime en la consola
		paginas = paises_con_medallas / 10; // Variable para almacenar la cantidad minima de grupos de 10 paises
	char	ch = '0'; // Captura cada caracter ingresado (inicializado a '0' para seguir en el bucle)
	// Si hay paises que no llegan en conjunto un grupo de 10, sumamos un grupo adicional
	if (paises_con_medallas % 10 != 0) paginas++;
	numeroPagina(1, paginas, 119, 12);
	listadoPaisesConMedallas(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, 1, paises_con_medallas);
	//	Bucle para permitir la entrada de id hasta que se presione ENTER
	do {
		ch = _getch(); // Captura la entrada del usuario
		
		// Si se ingrela la flecha izquierda (75 en código ASCII extendido)
		if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			numeroPagina(paginaActual, paginas, 119, 12);
			limpiarAreaRecuadroEnCoordenadas(42, 14, 74, 20);
			listadoPaisesConMedallas(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, paginaActual, paises_con_medallas);
		}
		// Si se ingrela la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and paginaActual != paginas) {
			paginaActual++;
			numeroPagina(paginaActual, paginas, 119, 12);
			limpiarAreaRecuadroEnCoordenadas(42, 14, 74, 20);
			listadoPaisesConMedallas(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, paginaActual, paises_con_medallas);
		}
	} while (ch != 'x' and ch != 'X');
}
//	Funcion que imprime y procesa la interaccion con el usuario
void	procesarInteraccionMostrarMedalleroPorPais(archivoCompetencia Archivo) {
	bool paisConMedalla[196] = {false}; // Arreglo para indicar si el pais en la posicion del arreglo tiene o no al menos una medalla
	int idPais, // Variable para almacenar temporalmente el id del pais dentro de deporte_medallas
		paises_con_medallas = 0, // Variable para almacenar la cantidad total de paises con al menos una medalla
		medallasIdDeLosPaises[196], // Arreglo para almacenar los id de cada pais
		medallasOro[196] = {0}, // Arreglo para almacenar la cantidad de medallas de oro de cada pais
		medallasPlata[196] = {0}, // Arreglo para almacenar la cantidad de medallas de plata de cada pais
		medallasBronce[196] = {0}; // Arreglo para almacenar la cantidad de medallas de bronce de cada pais
	// Inserta el id de cada pais en su respectiva posicion
	for (int i = 0; i < 196; i++) medallasIdDeLosPaises[i] = i;
	// Realiza los calculos indicados
	for (int i = 0; i < 87; i++) {
		for (int j = 0; j < 3; j++) {
			idPais = Archivo.deporte_medallas[i][j];
			if (idPais != -1) {
				switch (j) {
				case 0: medallasOro[idPais]++; break;
				case 1: medallasPlata[idPais]++; break;
				case 2: medallasBronce[idPais]++; break;
				}
				if (!(paisConMedalla[idPais])) {
					paisConMedalla[idPais] = true;
					paises_con_medallas++;
				}
			}
		}
	}
	mergesort(medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce, 0, 195);
	borrarInterfazMenu();
	mostrarInterfazMostrarMedalleroPorPais();
	capturarEntrada(paises_con_medallas, medallasIdDeLosPaises, medallasOro, medallasPlata, medallasBronce) ;
}
///	MOSTRAR TOP MEDALLERO
//	Funciones para la creación de elementos gráficos en la consola
void 	pasarPagIMGTOP(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX+19, desdeY+26);
	cout << char(174) << "  " << char(175);
	establecerCoordenadasPosicion(desdeX+12, desdeY+27);
	cout << "(Para Desplazarse)";
}
void 	mostrarTopIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  __  __        _                  _____ ___  ___ _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |  "<< char(92) <<"/  |___ __| |_ _ _ __ _ _ _  |_   _/ _ "<< char(92) <<"| _ (_)";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |"<< char(92) <<"/| / _ (_-<  _| '_/ _` | '_|   | || (_) |  _/_ ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|  |_"<< char(92) <<"___/__/"<< char(92) <<"__|_| "<< char(92) <<"__,_|_|     |_| "<< char(92) <<"___/|_| (_)";
}
void 	TopIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _____ ___  ___ _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |_   _/ _ "<< char(92) <<"| _ (_)";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "   | || (_) |  _/_ ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << "   |_| "<< char(92) <<"___/|_| (_)";
}
void 	numerosIMG(int desdeX, int desdeY, int digito){
	switch(digito){
	case 0:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "   __  ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << "  /  "<< char(92) <<" ";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " | () |";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << "  "<< char(92) <<"__/ ";
		break;
	case 1:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  _ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " / |";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " | |";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " |_|";
		break;
	case 2:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ___ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " |_  )";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << "  / / ";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " /___|";
		break;
	case 3:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ____";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " |__ /";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << "  |_ "<< char(92) <<"";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " |___/";
		break;
	case 4:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  _ _  ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " | | | ";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " |_  _|";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << "   |_| ";
		break;
	case 5:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ___ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " | __|";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " |__ "<< char(92) <<"";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " |___/";
		break;
	case 6:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "   __ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << "  / / ";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " / _ "<< char(92) <<"";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " "<< char(92) <<"___/";
		break;
	case 7:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ____ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " |__  |";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << "   / / ";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << "  /_/  ";
		break;
	case 8:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ___ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " ( _ )";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " / _ "<< char(92) <<"";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << " "<< char(92) <<"___/";
		break;
	case 9:
		establecerCoordenadasPosicion(desdeX, desdeY);
		cout << "  ___ ";
		establecerCoordenadasPosicion(desdeX, desdeY+1);
		cout << " / _ "<< char(92) <<"";
		establecerCoordenadasPosicion(desdeX, desdeY+2);
		cout << " "<< char(92) <<"_, /";
		establecerCoordenadasPosicion(desdeX, desdeY+3);
		cout << "  /_/ ";
		break;
	}
}
//	Funcion que imprime una interfaz
void 	digitosTOPIMG(int desdeX, int desdeY, int digito1, int digito2, int digito3){
	// Hay IFs para posicionar correctamente los digitos
	if(digito1 == 0 and digito2 == 0 and digito3 <= 9){ // del 01 al 09 | posicion
		// Titulo
		TopIMG(desdeX-20, desdeY);
		// Digitos
		numerosIMG(desdeX, desdeY, digito2);
		numerosIMG(desdeX+7, desdeY, digito3);
	}
	else if(digito1 == 0 and digito2 == 1 and digito3 <= 9){ // del 10 al 19 | posicion
		// Titulo
		TopIMG(desdeX-20, desdeY);
		// Digitos
		numerosIMG(desdeX, desdeY, digito2);
		numerosIMG(desdeX+4, desdeY, digito3);
	}
	else if(digito1 == 0 and digito2 <= 9 and digito3 <= 9){ // del 20 al 99 | posicion
		// Titulo
		TopIMG(desdeX-20, desdeY);
		// Digitos
		numerosIMG(desdeX, desdeY, digito2);
		numerosIMG(desdeX+6, desdeY, digito3);
	}
	else if(digito1 == 1 and digito2 == 0 and digito3 <= 9){ // del 100 al 109
		// Titulo
		TopIMG(desdeX-23, desdeY);
		// Digitos
		numerosIMG(desdeX+7, desdeY, digito3);
		numerosIMG(desdeX+1, desdeY, digito2);
		numerosIMG(desdeX-2, desdeY, digito1);
	}
	else if(digito1 == 1 and digito2 == 1 and digito3 == 0){ // 110
		// Titulo
		TopIMG(desdeX-23, desdeY);
		// Digitos
		numerosIMG(desdeX+5, desdeY, digito3);
		numerosIMG(desdeX+2, desdeY, digito2);
		numerosIMG(desdeX-2, desdeY, digito1);
	}
	else if(digito1 == 1 and digito2 == 1 and digito3 >= 1 and digito3 <= 9) { // 111 al 119
		// Titulo
		TopIMG(desdeX-23, desdeY);
		// Digitos
		numerosIMG(desdeX+5, desdeY, digito3);
		numerosIMG(desdeX+1, desdeY, digito2);
		numerosIMG(desdeX-3, desdeY, digito1);
	}
	else if(digito1 == 1 and digito2 <=9 and digito3 <= 9){ // del 120 al total
		// Titulo
		TopIMG(desdeX-23, desdeY);
		// Digitos
		numerosIMG(desdeX+6, desdeY, digito3);
		numerosIMG(desdeX+1, desdeY, digito2);
		numerosIMG(desdeX-3, desdeY, digito1);
	}
}		
void	mostrarInterfazMostrarMedalleroPorTOP(int top_ingresado) {
	int digito1 = top_ingresado / 100, // Variable para almacenar el primer digito del top
		digito2 = (top_ingresado / 10)%10, // Variable para almacenar el segundo digito del top
		digito3 = top_ingresado % 10; // Variable para almacenar el tercer digito del top
	
	digitosTOPIMG(80, 6, digito1, digito2, digito3);
	pasarPagIMGTOP(100, 4);
	regresarIMGMedalleroPorPaises(5, 4);
	mostrarDibujoRecuadroEnCoordenadas(45, 10, 60, 3);
	
	establecerCoordenadasPosicion(49, 11);
	cout << "PUESTO";
	establecerCoordenadasPosicion(60, 11);
	cout << "PAIS";
	establecerCoordenadasPosicion(96, 11);
	cout << "TOTAL";
}
//	Funciones de ordenamiento
void	mergeTOP(int medallasIdDeLosPaises[], int cantidadMedallasIdDeLosPaises[], int inicio1, int final1, int inicio2, int final2) {
	int i, j, k, c_paises[196], c_medallasPaises[196];
	i = inicio1;
	j = inicio2;
	k = 0;
	
	while (i <= final1 and j <= final2) {
		if (cantidadMedallasIdDeLosPaises[i] > cantidadMedallasIdDeLosPaises[j]) {
			c_paises[k] = medallasIdDeLosPaises[i];
			c_medallasPaises[k++] = cantidadMedallasIdDeLosPaises[i++];
		}
		else {
			c_paises[k] = medallasIdDeLosPaises[j];
			c_medallasPaises[k++] = cantidadMedallasIdDeLosPaises[j++];
		}
	}
	while (i <= final1) {
		c_paises[k] = medallasIdDeLosPaises[i];
		c_medallasPaises[k++] = cantidadMedallasIdDeLosPaises[i++];
	}
	while (j <= final2) {
		c_paises[k] = medallasIdDeLosPaises[j];
		c_medallasPaises[k++] = cantidadMedallasIdDeLosPaises[j++];
	}
	
	for (k = 0; k < final2 - inicio1 + 1; k++){
		medallasIdDeLosPaises[inicio1 + k] = c_paises[k];
		cantidadMedallasIdDeLosPaises[inicio1 + k] = c_medallasPaises[k];
	}
}
void	mergesortTOP(int medallasIdDeLosPaises[], int cantidadMedallasIdDeLosPaises[], int inicio, int finall) {
	if (finall - inicio != 0) {
		mergesortTOP(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, inicio, (inicio + finall) / 2);
		mergesortTOP(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, (inicio + finall) / 2 + 1, finall);
		mergeTOP(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, inicio, (inicio + finall) / 2, (inicio + finall) / 2 + 1, finall);
	}
}
//	Funciones de calculos
int		capturarEntradaTOP(archivoCompetencia Archivo) {
	string bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	char ch = '0'; // Variable para almacenar el caracter ingresado por el usuario
	bool primerDigitoNoEsCero = false, // Variable para indicar si el primer digito es cero
		continuar = true; // Variable para indicar si se puede salir (solamente cuando se ingrese un top que exista)
	int	id = 0, // Variable para almacenar el top ingresado
		cantidad = 0, // Variable para almacenar la cantidad de paises cargados
		pais1, // Variable para almacenar temporalmente el id del pais con la medalla de oro (si es que esta cargado)
		pais2, // Variable para almacenar temporalmente el id del pais con la medalla de plata (si es que esta cargado)
		pais3; // Variable para almacenar temporalmente el id del pais con la medalla de bronce (si es que esta cargado)
	
	bool paisContado[196] = {false};
	
	for (int i = 0; i < 87; i++) {
		if (Archivo.deporte_medallas[i][0] != -1) {
			pais1 = Archivo.deporte_medallas[i][0];  // Oro
			pais2 = Archivo.deporte_medallas[i][1];  // Plata
			pais3 = Archivo.deporte_medallas[i][2];  // Bronce
			
			// Verifica si al menos un país tiene una medalla
			if (!paisContado[pais1]) {
				paisContado[pais1] = true; 
				cantidad++;
			}
			if (!paisContado[pais2]) {
				paisContado[pais2] = true;
				cantidad++; 
			}
			if (!paisContado[pais3]) {
				paisContado[pais3] = true; 
				cantidad++; 
			}
		}
	}
	
	do {
		id = 0;
		primerDigitoNoEsCero = false;
		bufferEntrada.clear();
		
		//	Bucle para permitir la entrada de id hasta que se presione ENTER
		do {
			ch = _getch(); // Captura la entrada del usuario
			
			if ((bufferEntrada.size() == 0) and (isdigit(ch))) {
				establecerCoordenadasPosicion(101, 18);
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
			else if ((bufferEntrada.size() == 1) and (isdigit(ch))) {
				establecerCoordenadasPosicion(102, 18);
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			}
			else if ((bufferEntrada.size() == 2) and (isdigit(ch) and (ch < '7')  and bufferEntrada.at(0) == '1')) {
				establecerCoordenadasPosicion(103, 18);
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			}
			else if ((ch == 8) and !(bufferEntrada.size() == 0)) { // Si se presiona la tecla de retroceso
				//	Borra el último caracter en la consola
				cout << "\b \b"; // Mueve el cursor hacia atrás, imprime un espacio, y luego mueve el cursor hacia atrás de nuevo
				
				//	Elimina el último caracter del bufferEntrada
				bufferEntrada.pop_back();
				
				// Si el buffer queda vacío
				if (bufferEntrada.empty()) primerDigitoNoEsCero = false; // Nuevamente restringe la entrada de ceros como primer dígito
			}
		} while (ch != '\r' or bufferEntrada.empty());
		
		//	Convierte bufferEntrada en un número entero
		convertidorAEntero(id, bufferEntrada);
		
		if (id <= cantidad) continuar = false;
		else {
			establecerCoordenadasPosicion(47, 23);
			cout << "(El top solicitado excede la cántidad de paises cargados)";
			establecerCoordenadasPosicion(101, 18);
			cout << "   ";
		}
	} while (continuar);
	
	return id;
}
void	listadoPaisesTOP(int paginaActual, int top_ingresado, int medallasIdDeLosPaises[], int cantidadMedallasIdDeLosPaises[]) {
	int paginasCompletas = top_ingresado / 10, // Variable para almacenar la cantidad total de paginas usadas completamente
		restoPaises = top_ingresado % 10, // Variable para almacenar la cantidad de paises restantes
		finall, // Variable para almacenar hasta que pais se muestra en pantalla
		espacios = 0, // Variable para almacenar la ubicacion en la columna del pais a mostrar
		contador = paginaActual * 10 - 10; // Variable para almacenar el id del pais a mostrar
	
	// Calcula el finall basado en la página actual
	if (paginaActual <= paginasCompletas) finall = 9;
	else if ((paginaActual == paginasCompletas + 1) && restoPaises > 0) finall = restoPaises - 1;
	
	for(int i = 0; i <= finall; i++) {
		Sleep(60);
		// Para los Números
		establecerCoordenadasPosicion(51, 13 + espacios);
		if(i < 9) cout << "0"; // Añadir 0 a los números menores de 10
		cout << contador + 1;
		// Para el País
		establecerCoordenadasPosicion(60, 13 + espacios);
		imprimirPais(medallasIdDeLosPaises[contador]);
		// Para la cantidad de medallas
		establecerCoordenadasPosicion(97, 13 + espacios);
		cout << cantidadMedallasIdDeLosPaises[contador];
		// Restaurar color al default
		cambiarColorTextoFondo(7, 0);
		espacios += 2;
		contador++;
	}
}
void	capturarEntradaListaTOP(int top_ingresado, archivoCompetencia Archivo) {
	char ch = '0'; // Variable para almacenar temporalmente cada caracter ingresado (inicializado a '0' para seguir en el bucle)
	bool paisConMedalla[196] = {false}; // Arreglo para indicar si el pais en la posicion del arreglo tiene o no al menos una medalla
	int	paginaActual = 1, // Variable para indica la pagina que se imprime en la consola
		paginas = top_ingresado / 10, // Variable para almacenar la cantidad minima de grupos de 10
		idPais, // Variable para almacenar temporalmente el id del pais dentro de deporte_medallas
		medallasIdDeLosPaises[196], // Arreglo para almacenar los id de cada pais
		cantidadMedallasIdDeLosPaises[196] = {0}, // Arreglo para almacenar la cantidad de medallas de cada pais
		paises_con_medallas = 0; // Variable para almacenar la cantidad total de paises con al menos una medalla
	
	// Calcula si hay un residuo, sumamos un grupo adicional
	if (top_ingresado % 10 != 0) paginas++;
	
	numeroPagina(1, paginas, 114, 11);
	mostrarDibujoRecuadroEnCoordenadas(43, 14, 64, 9);
	mostrarTopIMG(46, 16);
	limpiarAreaRecuadroEnCoordenadas(42, 13, 65, 20);
	
	// Calculo el top y su posicion
	for (int i = 0; i < 196; i++) medallasIdDeLosPaises[i] = i;
	for (int i = 0; i < 87; i++) {
		for (int j = 0; j < 3; j++) {
			idPais = Archivo.deporte_medallas[i][j];
			if (idPais != -1) {
				if (!(paisConMedalla[idPais])) {
					paisConMedalla[idPais] = true;
					paises_con_medallas++;
				}
				cantidadMedallasIdDeLosPaises[idPais]++;
			}
		}
	}
	mergesortTOP(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, 0, 195);
	//  Muestra el top
	listadoPaisesTOP(1, top_ingresado, medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises);
	//	Bucle para permitir la entrada de id hasta que se presione ENTER
	do {
		ch = _getch(); // Captura la entrada del usuario
		// Si se ingrela la flecha izquierda (75 en código ASCII extendido)
		if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			numeroPagina(paginaActual, paginas, 114, 11);
			limpiarAreaRecuadroEnCoordenadas(42, 13, 60, 20);
			listadoPaisesTOP(paginaActual, top_ingresado, medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises);
		}
		// Si se ingrela la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and paginaActual != paginas) {
			paginaActual++;
			numeroPagina(paginaActual, paginas, 114, 11);
			limpiarAreaRecuadroEnCoordenadas(42, 13, 60, 20);
			listadoPaisesTOP(paginaActual, top_ingresado, medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises);
		}
	} while (ch != 'x' and ch != 'X');
}
//	Funcion que imprime y procesa la interaccion con el usuario
void	procesarInteraccionIngresarTOP(int & top_ingresado, archivoCompetencia Archivo) {
	bool paisConMedalla[196] = {false}; // Arreglo para indicar si el pais en la posicion del arreglo tiene o no al menos una medalla
	int idPais, // Variable para almacenar temporalmente el id del pais dentro de deporte_medallas
		paises_con_medallas = 0; // Variable para almacenar la cantidad total de paises con al menos una medalla
	
	mostrarDibujoRecuadroEnCoordenadas(43, 14, 64, 9);
	mostrarTopIMG(46, 16);
	
	for (int i = 0; i < 87; i++) {
		for (int j = 0; j < 3; j++) {
			idPais = Archivo.deporte_medallas[i][j];
			if (idPais != -1) {
				if (!(paisConMedalla[idPais])) {
					paisConMedalla[idPais] = true;
					paises_con_medallas++;
				}
			}
		}
	}
	
	if (paises_con_medallas == 1) {
		establecerCoordenadasPosicion(60, 13);
		cout << "Actualmente hay 1 pais cargado";
	}
	else {
		establecerCoordenadasPosicion(59, 13);
		cout << "Actualmente hay " << paises_con_medallas << " paises cargados";
	}
	
	top_ingresado = capturarEntradaTOP(Archivo);
}
void	procesarInteraccionMostrarMedalleroTOP(archivoCompetencia Archivo) {
	int top_ingresado; // Variable para almacenar el top ingresado
	borrarInterfazMenu();
	procesarInteraccionIngresarTOP(top_ingresado, Archivo);
	borrarInterfazMenu();
	mostrarInterfazMostrarMedalleroPorTOP(top_ingresado);
	capturarEntradaListaTOP(top_ingresado, Archivo);
}
///	FUNCIONES GENERALES DE GESTION PRINCIPAL
void	gestionarSecuenciaMostrarMedalleroPorPais(archivoCompetencia Archivo) {
	procesarInteraccionMostrarMedalleroPorPais(Archivo);
}
void	gestionarSecuenciaMostrarMedalleroPorDeporte(archivoCompetencia Archivo) {
	procesarInteraccionMostrarMedalleroPorDeporte(Archivo);
}
void	gestionarSecuenciaMostrarMedalleroTOP(archivoCompetencia Archivo) {
	procesarInteraccionMostrarMedalleroTOP(Archivo);
}
/// SUB MENU MOSTRAR MEDALLERO
//	Funciones para la creación de elementos gráficos en la consola
void	medalleroIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  __  __        _      _ _             ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |  "<< char(92) <<"/  |___ __| |__ _| | |___ _ _ ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |"<< char(92) <<"/| / -_) _` / _` | | / -_) '_/ _ "<< char(92);
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"___|_| "<< char(92) <<"___/";
	establecerCoordenadasPosicion(desdeX, desdeY+4);
	cout << "";
}
void	equisIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << " __  __";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " "<< char(92) <<" "<< char(92) <<"/ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  >  < ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /_/"<< char(92) << "_" << char(92);
}
void	unoIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " / |";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|";
}
void	dosIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |_  )";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  / / ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /___|";
}
void	tresIMG(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ____";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |__ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  |_ "<< char(92);
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |___/";
}
void	opcion1_3(int desdeX, int desdeY, bool seleccionada){
	if (seleccionada) cambiarColorTextoFondo(3,0);
	else cambiarColorTextoFondo(7,0);
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 17, 9);
	unoIMG(desdeX+6, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Por País";
	cambiarColorTextoFondo(7,0);
}
void	opcion2_3(int desdeX, int desdeY, bool seleccionada){
	if(seleccionada) 
		cambiarColorTextoFondo(3,0);
	else{
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 17, 9);
	dosIMG(desdeX+5, desdeY+1);
	establecerCoordenadasPosicion(desdeX+3, desdeY+6);
	cout << "Por Deporte";
	cambiarColorTextoFondo(7,0);
}
void	opcion3_3(int desdeX, int desdeY, bool seleccionada){
	if(seleccionada) 
		cambiarColorTextoFondo(3,0);
	else{
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 17, 9);
	tresIMG(desdeX+5, desdeY+1);
	establecerCoordenadasPosicion(desdeX+2, desdeY+6);
	cout << "TOP Medallero";
	cambiarColorTextoFondo(7,0);
}
void	opcionX_3(int desdeX, int desdeY, bool seleccionada){
	if(seleccionada) 
		cambiarColorTextoFondo(3,0);
	else{
		cambiarColorTextoFondo(7,0);
	}
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 53, 7);
	equisIMG(desdeX+8, desdeY+1);
	establecerCoordenadasPosicion(desdeX+18, desdeY+3);
	cout << "Regresar al Menu Principal";
	cambiarColorTextoFondo(7,0);
}
//	Funciones que imprimen una interfaz
void	mostrarInterfazMenuMostrarMedallero() {
	medalleroIMG(56, 7);
	// Opcion 1 - Medallero por Pais
	opcion1_3(49, 13, false);
	// Opcion 2 - Medallero por Deporte
	opcion2_3(67, 13, false);
	// Opcion 3 - TOP Medallero
	opcion3_3(85, 13, false);
	// Opcion X - Regresar al Menu Principal
	opcionX_3(49, 22, false);
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionEleccionOpcionesMenuMostrarMedallero(char& opcionSeleccionada)  {
	bool seleccionada = false; // Variable para indicar si se ingreso una opcion antes de presionar enter
	char opcion; // Variable para almacenar temporalmente la opcion ingresada
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '1':
			// Opcion 1 - Medallero por Pais
			opcion1_3(49, 13, true);
			// Opcion 2 - Medallero por Deporte
			opcion2_3(67, 13, false);
			// Opcion 3 - TOP Medallero
			opcion3_3(85, 13, false);
			// Opcion X - Regresar al Menu Principal
			opcionX_3(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '1';
			break;
		case '2':
			// Opcion 1 - Medallero por Pais
			opcion1_3(49, 13, false);
			// Opcion 2 - Medallero por Deporte
			opcion2_3(67, 13, true);
			// Opcion 3 - TOP Medallero
			opcion3_3(85, 13, false);
			// Opcion X - Regresar al Menu Principal
			opcionX_3(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case '3':
			// Opcion 1 - Medallero por Pais
			opcion1_3(49, 13, false);
			// Opcion 2 - Medallero por Deporte
			opcion2_3(67, 13, false);
			// Opcion 3 - TOP Medallero
			opcion3_3(85, 13, true);
			// Opcion X - Regresar al Menu Principal
			opcionX_3(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '3';
			break;
		case 'X':
			// Opcion 1 - Medallero por Pais
			opcion1_3(49, 13, false);
			// Opcion 2 - Medallero por Deporte
			opcion2_3(67, 13, false);
			// Opcion 3 - TOP Medallero
			opcion3_3(85, 13, false);
			// Opcion X - Regresar al Menu Principal
			opcionX_3(49, 22, true);
			
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void	procesarInteraccionMenuMostrarMedallero(archivoCompetencia Archivo) {
	char	opcionSeleccionada; // Variable para almacenar la opcion seleccionada por el usuario
	
	do {
		mostrarInterfazMenuMostrarMedallero();
		procesarInteraccionEleccionOpcionesMenuMostrarMedallero(opcionSeleccionada);
		if (opcionSeleccionada == '1') {
			gestionarSecuenciaMostrarMedalleroPorPais(Archivo);
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '2') {
			gestionarSecuenciaMostrarMedalleroPorDeporte(Archivo);
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '3') {
			gestionarSecuenciaMostrarMedalleroTOP(Archivo);
			borrarInterfazMenu();
		} 
	} while(opcionSeleccionada != 'X');
}
//	Funciones generales de gestion principal
void	gestionarSecuenciaMenuMostrarMedallero(archivoCompetencia Archivo) {
	procesarInteraccionMenuMostrarMedallero(Archivo);
}

