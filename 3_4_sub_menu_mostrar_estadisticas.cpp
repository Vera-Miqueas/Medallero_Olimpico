#include "funciones_compartidas.h"
#include "competidores.h"
#include "gestionar.h"
#include "paises.h"
#include "deportes.h"
#include <iostream>
#include <cctype>
using namespace std;

/// PAISES PREMIADOS DEL DEPORTE
void 	pasarPag(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << char(174) << "  " << char(175) << " (Para Desplazarse)";
}
void 	regresar(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "X (Para Regresar)";
}
const char* deportess[] = {
	"Carreras de velocidad - 100 metros",
		"Carreras de velocidad - 200 metros",
		"Carreras de velocidad - 400 metros",
		"Carreras de medio fondo - 800 metros",
		"Carreras de medio fondo - 1500 metros",
		"Carreras de fondo - 5000 metros",
		"Carreras de fondo - 10000 metros",
		"Maratón (42.195 km)",
		"Carreras con vallas - 110 metros vallas (hombres)",
		"Carreras con vallas - 100 metros vallas (mujeres)",
		"Carreras con vallas - 400 metros vallas",
		"Carreras de relevos - 4x100 metros",
		"Carreras de relevos - 4x400 metros",
		"Marcha atlética - 20 km marcha",
		"Marcha atlética - 35 km marcha",
		"Saltos - Salto de altura",
		"Saltos - Salto con pértiga",
		"Saltos - Salto de longitud",
		"Saltos - Triple salto",
		"Lanzamientos - Lanzamiento de peso",
		"Lanzamientos - Lanzamiento de disco",
		"Lanzamientos - Lanzamiento de martillo",
		"Lanzamientos - Lanzamiento de jabalina",
		"Pruebas combinadas - Decatlón (hombres)",
		"Pruebas combinadas - Heptatlón (mujeres)",
		"Badminton",
		"Baloncesto",
		"Baloncesto 3x3",
		"Balonmano",
		"Béisbol",
		"Softbol",
		"Boxeo",
		"Ciclismo BMX",
		"Ciclismo de montaña",
		"Ciclismo de pista",
		"Ciclismo de ruta",
		"Escalada deportiva",
		"Esgrima",
		"Fútbol",
		"Gimnasia artística",
		"Gimnasia rítmica",
		"Trampolín",
		"Golf",
		"Halterofilia",
		"Hockey sobre césped",
		"Judo",
		"Karate",
		"Kata",
		"Kumite",
		"Lucha libre",
		"Lucha grecorromana",
		"Natación - Estilo libre - 50 metros",
		"Natación - Estilo libre - 100 metros",
		"Natación - Estilo libre - 200 metros",
		"Natación - Estilo libre - 400 metros",
		"Natación - Estilo libre - 800 metros",
		"Natación - Estilo libre - 1500 metros",
		"Natación - Estilo espalda - 100 metros",
		"Natación - Estilo espalda - 200 metros",
		"Natación - Estilo braza - 100 metros", // 60
		"Natación - Estilo braza - 200 metros",
		"Natación - Estilo mariposa - 100 metros",
		"Natación - Estilo mariposa - 200 metros",
		"Natación - Estilos combinados - 200 metros combinados",
		"Natación - Estilos combinados - 400 metros combinados",
		"Natación - Relevos - 4x100 metros libre",
		"Natación - Relevos - 4x200 metros libre",
		"Natación - Relevos - 4x100 metros estilos",
		"Natación en aguas abiertas - 10 km",
		"Natación artística", // 70
		"Pentatlón moderno",
		"Piragüismo en eslalon",
		"Piragüismo en sprint",
		"Remo",
		"Rugby 7",
		"Skateboarding",
		"Surf",
		"Taekwondo",
		"Tenis",
		"Tenis de mesa", // 80
		"Tiro con arco",
		"Tiro deportivo",
		"Triatlón",
		"Vela",
		"Voleibol de pista",
		"Voleibol de playa",
		"Waterpolo" // 87
};
bool 	filtrarPorLetra(char & letra, int indices[], int & cantidad, archivoCompetencia Archivo){
	bool existe = false;
	
	letra = toupper(letra);
	
	for (int i = 0; i < 87; i++){
		if ((Archivo.deporte_medallas[i][0] != -1) and (deportess[i][0] == letra)) {
			existe = true;
			indices[cantidad++] = i + 1;
		}
	}
	
	return existe;
}
void 	titulo_PaisesPremiadosDelDeporte(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  ___      __             ___               _         _             _     _   ___                    _       ";
	establecerCoordenadasPosicion(xInicio, yInicio+1);
	cout << " | _ "<< char(92) <<"__ _/_/___ ___ ___ | _ "<< char(92) <<"_ _ ___ _ __ (_)__ _ __| |___ ___  __| |___| | |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ";
	establecerCoordenadasPosicion(xInicio, yInicio+2);
	cout << " |  _/ _` | (_-</ -_|_-< |  _/ '_/ -_) '  "<< char(92) <<"| / _` / _` / _ (_-< / _` / -_) | | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_)";
	establecerCoordenadasPosicion(xInicio, yInicio+3);
	cout << " |_| "<< char(92) <<"__,_|_/__/"<< char(92) <<"___/__/ |_| |_| "<< char(92) <<"___|_|_|_|_"<< char(92) <<"__,_"<< char(92) <<"__,_"<< char(92) <<"___/__/ "<< char(92) <<"__,_"<< char(92) <<"___|_| |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___|";
	establecerCoordenadasPosicion(xInicio, yInicio+4);
	cout << "                                                                                      |_|                    ";
}
void 	barraInfo(char letra){
	mostrarDibujoRecuadroEnCoordenadas(13, 12, 124, 3);
	
	establecerCoordenadasPosicion(16, 13);
	cout << "Deporte: " << letra;
	establecerCoordenadasPosicion(67, 13);
	cambiarColorTextoFondo(6, 0);
	cout << "1 Puesto";
	cambiarColorTextoFondo(7, 0);
	establecerCoordenadasPosicion(90, 13);
	cout << "2 Puesto";
	establecerCoordenadasPosicion(113, 13);
	cambiarColorTextoFondo(12, 0);
	cout << "3 Puesto";
	cambiarColorTextoFondo(7, 0);
}
void 	ingresarLetra(){
	mostrarDibujoRecuadroEnCoordenadas(50, 18, 50, 3);
	establecerCoordenadasPosicion(52, 19);
	cout << "Ingrese una letra para filtrar los deportes: ";
}
void 	pantallaErrorDeporte(char letra){
	mostrarDibujoRecuadroEnCoordenadas(50, 14, 50, 11);
	establecerCoordenadasPosicion(70, 16);
	cambiarColorTextoFondo(4, 0);
	cout << "ERROR 404";
	cambiarColorTextoFondo(7, 0);
	establecerCoordenadasPosicion(57, 18);
	cout << "No Existen Deportes con la letra '" << letra << "'";
	establecerCoordenadasPosicion(67, 20);
	cout << "Pruebe con otra!";
	establecerCoordenadasPosicion(62, 23);
	cout << "(Presione X para Regresar)";
}
void 	imprimirListaFiltro(char letra, int paginaActual, int cantidad, int indices[], archivoCompetencia Archivo){
	int inicio = (paginaActual - 1) * 8,
		hasta = inicio + 8,
		j = 0;
	
	// Ajusta el índice final si supera el total de elementos
	if (hasta > cantidad) hasta = cantidad;
	
	for (int i = inicio; i < hasta; i++) {
		// Nombre del deporte
		establecerCoordenadasPosicion(16, 16 + j);
		imprimirDeporte(indices[i]);
		
		// 1er Puesto
		cambiarColorTextoFondo(6, 0);
		establecerCoordenadasPosicion(67, 16 + j);
		imprimirPais(Archivo.deporte_medallas[indices[i] - 1][0]);
		cambiarColorTextoFondo(7, 0);
		
		//2do Puesto
		establecerCoordenadasPosicion(90, 16 + j);
		imprimirPais(Archivo.deporte_medallas[indices[i] - 1][1]);
		
		// 3er Puesto
		cambiarColorTextoFondo(12, 0);
		establecerCoordenadasPosicion(113, 16 + j);
		imprimirPais(Archivo.deporte_medallas[indices[i] - 1][2]);
		cambiarColorTextoFondo(7, 0);
		
		j += 2;
	}
}
void	capturarEntradaPPDD(char letra, int cantidad, int indices[], archivoCompetencia Archivo)  {
	int	paginaActual = 1, // Indica la pagina que se imprime en la consola
		paginas = cantidad / 8; // Variable para almacenar la cantidad minima de grupos de 10 paises
	char	ch = '0'; // Captura cada caracter ingresado (inicializado a '0' para seguir en el bucle)
	
	// Si hay paises que no llegan en conjunto un grupo de 10, sumamos un grupo adicional
	if (cantidad % 8 != 0) paginas++;
	
	regresar(26, 32);
	numeroPagina(1, paginas, 65, 32);
	pasarPag(101, 32);
	barraInfo(letra);
	imprimirListaFiltro(letra, paginaActual, cantidad, indices, Archivo);

	//	Bucle para permitir la entrada de id hasta que se presione ENTER
	do {
		ch = _getch(); // Captura la entrada del usuario
		
		// Si se ingrela la flecha izquierda (75 en código ASCII extendido)
		if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			numeroPagina(paginaActual, paginas, 65, 32);
			limpiarAreaRecuadroEnCoordenadas(15, 15, 123, 17);
			
			imprimirListaFiltro(letra, paginaActual, cantidad, indices, Archivo);
		}
		// Si se ingrela la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and paginaActual != paginas) {
			paginaActual++;
			numeroPagina(paginaActual, paginas, 65, 32);
			limpiarAreaRecuadroEnCoordenadas(15, 15, 123, 17);
			
			imprimirListaFiltro(letra, paginaActual, cantidad, indices, Archivo);
		}
	} while (ch != 'x' and ch != 'X');
}
/// PAIS CON MAS MEDALLAS DE LOS DEPORTES INDIVIDUALES
void 	titulo_MasDeportesIndividuales(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "    _     ___                    _            ___         _ _     _    _           _        ";
	establecerCoordenadasPosicion(xInicio, yInicio+1);
	cout << "  _| |_  |   "<< char(92) <<" ___ _ __  ___ _ _| |_ ___ ___ |_ _|_ _  __| (_)_ _(_)__| |_  _ __ _| |___ ___";
	establecerCoordenadasPosicion(xInicio, yInicio+2);
	cout << " |_   _| | |) / -_) '_ "<< char(92) <<"/ _ "<< char(92) <<" '_|  _/ -_|_-<  | || ' "<< char(92) <<"/ _` | "<< char(92) <<" V / / _` | || / _` | / -_|_-<";
	establecerCoordenadasPosicion(xInicio, yInicio+3);
	cout << "   |_|   |___/"<< char(92) <<"___| .__/"<< char(92) <<"___/_|  "<< char(92) <<"__"<< char(92) <<"___/__/ |___|_||_"<< char(92) <<"__,_|_|"<< char(92) <<"_/|_"<< char(92) <<"__,_|"<< char(92) <<"_,_"<< char(92) <<"__,_|_"<< char(92) <<"___/__/";
	establecerCoordenadasPosicion(xInicio, yInicio+4);
	cout << "                  |_|                                                                       ";
}
void 	Interfaz_PaisConDeportesInd(int idPais, int medallas){
	borrarInterfazMenu();
	
	mostrarDibujoRecuadroEnCoordenadas(28, 12, 95, 18);
	titulo_MasDeportesIndividuales(29, 14);
	
	establecerCoordenadasPosicion(52, 22);
	cout << "El País con más Deportes Individuales es: ";
	
	cambiarColorTextoFondo(6, 0);
	imprimirPais(idPais);
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(52, 24);
	cout << "Consiguio un TOTAL de: ";
	cambiarColorTextoFondo(6, 0);
	cout << medallas << " Medallas";
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(62, 28);
	cout << "(Presione X para Regresar)";
	
	while (toupper(_getch()) != 'X');
}
void	calcularMayor(archivoCompetencia Archivo) {
	int medallas[196] = {0};
	
	// Lista de índices para filtrar
	int indicesFiltrados[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
			11, 14, 15, 16, 17, 18, 19, 20, 
			21, 22, 23, 24, 25, 33, 34, 35, 
			36, 37, 46, 48, 49, 50, 51, 52, 
			53, 54, 55, 56, 57, 58, 59, 60,
			61, 62, 63, 64, 71, 72, 73, 77,
			78, 80, 82
	};
	
	int idPais;
	
	// Calcular la cantidad de medallas por país solo para los índices filtrados
	for (int i = 0; i < 53; i++) {
		for (int j = 0; j < 3; j++) {
			idPais = Archivo.deporte_medallas[indicesFiltrados[i]-1][j];
			if (idPais >= 0 and idPais < 196)
				medallas[idPais]++;
		}
	}
	
	int mayor = medallas[0];
	int id = 0;
	
	for(int i=1; i<196; i++){
		if(medallas[i] > mayor){
			mayor = medallas[i];
			id = i;
		}
	}
	
	// Mostrar los resultados
	Interfaz_PaisConDeportesInd(id, mayor);
}
/// MEDALLAS DEL PAIS
void 	titulo_MedallasDelPais(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  __  __        _      _ _              _     _   ___      _    ";
	establecerCoordenadasPosicion(xInicio, yInicio+1);
	cout << " |  "<< char(92) <<"/  |___ __| |__ _| | |__ _ ___  __| |___| | | _ "<< char(92) <<"__ _(_)___";
	establecerCoordenadasPosicion(xInicio, yInicio+2);
	cout << " | |"<< char(92) <<"/| / -_) _` / _` | | / _` (_-< / _` / -_) | |  _/ _` | (_-<";
	establecerCoordenadasPosicion(xInicio, yInicio+3);
	cout << " |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"__,_/__/ "<< char(92) <<"__,_"<< char(92) <<"___|_| |_| "<< char(92) <<"__,_|_/__/";
}
void 	imprimirPaisLista(int desde, int hasta, int desdeX, int desdeY){
	for(int i=desde; i<hasta+1; i++){
		establecerCoordenadasPosicion(desdeX, desdeY++);
		cout << i + 1 << " - ";
		imprimirPais(i+1);
	}
}
void 	ingresarIDPais(){
	mostrarDibujoRecuadroEnCoordenadas(62, 28, 24, 3);
	establecerCoordenadasPosicion(64, 29);
	cout << "Ingrese el Pais: ";
}
void 	paginaPaises(int pag){
	if(pag == 1){
		imprimirPaisLista(0, 14, 30, 13);
		imprimirPaisLista(15, 29, 60, 13);
		imprimirPaisLista(30, 44, 90, 13);
	}
	else if(pag == 2){
		imprimirPaisLista(45, 59, 30, 13);
		imprimirPaisLista(60, 74, 60, 13);
		imprimirPaisLista(75, 89, 90, 13);
	}
	else if(pag == 3){
		imprimirPaisLista(90, 104, 30, 13);
		imprimirPaisLista(105, 119, 60, 13);
		imprimirPaisLista(120, 134, 90, 13);
	}
	else if(pag == 4){
		imprimirPaisLista(135, 149, 28, 13);
		imprimirPaisLista(150, 164, 60, 13);
		imprimirPaisLista(165, 179, 96, 13);
	}
	else if(pag == 5){
		imprimirPaisLista(180, 187, 45, 13);
		imprimirPaisLista(188, 195, 75, 13);
	}
}
int 	capturarIngreso() {
	int		paginaActual = 1, // Indica la pagina que se imprime en la consola
			id = 0;
	char	ch = '0'; // Captura cada caracter ingresado (inicializado a '0' para seguir en el bucle)
	string 	bufferEntrada; // Variable para almacenar temporalmente la contraseña ingresada por el usuario
	bool 	primerDigitoNoEsCero = false, // Variable para indicar si el primer digito es cero
			esX = false;
	
	limpiarAreaRecuadroEnCoordenadas(11, 10, 120, 20);
	numeroPagina(1, 5, 119, 12);
	titulo_MedallasDelPais(42, 6);
	ingresarIDPais();
	paginaPaises(paginaActual);
	establecerCoordenadasPosicion(61, 32);
	cout << "(Presione X para Regresar)";
	
	//	Bucle para permitir la entrada de id hasta que se presione ENTER
	do {
		ch = _getch(); // Captura la entrada del usuario
		
		// Si se ingrela la flecha izquierda (75 en código ASCII extendido)
		if (ch == 'x' or ch == 'X') {
			esX = true;
			ch = '\r';
		}
		else if (ch == 75 and paginaActual != 1) {
			paginaActual--;
			limpiarAreaRecuadroEnCoordenadas(11, 10, 120, 18);
			numeroPagina(paginaActual, 5, 119, 12);
			titulo_MedallasDelPais(42, 6);
			ingresarIDPais();
			paginaPaises(paginaActual);
			establecerCoordenadasPosicion(61, 32);
			cout << "(Presione X para Regresar)";
			
			switch (bufferEntrada.size()) {
			case 0: establecerCoordenadasPosicion(81, 29); break;
			case 1: establecerCoordenadasPosicion(82, 29); break;
			case 2: establecerCoordenadasPosicion(83, 29); break;
			}
		}
		// Si se ingrela la flecha derecha (77 en código ASCII extendido)
		else if (ch == 77 and paginaActual != 5) {
			paginaActual++;
			limpiarAreaRecuadroEnCoordenadas(11, 10, 120, 18);
			numeroPagina(paginaActual, 5, 119, 12);
			titulo_MedallasDelPais(42, 6);
			ingresarIDPais();
			paginaPaises(paginaActual);
			establecerCoordenadasPosicion(61, 32);
			cout << "(Presione X para Regresar)";
			
			switch (bufferEntrada.size()) {
			case 0: establecerCoordenadasPosicion(81, 29); break;
			case 1: establecerCoordenadasPosicion(82, 29); break;
			case 2: establecerCoordenadasPosicion(83, 29);break;
			}
		}
		else if ((bufferEntrada.size() == 0) and (isdigit(ch))) {
			establecerCoordenadasPosicion(81, 29);
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
			establecerCoordenadasPosicion(82, 29);
			cout << ch;
			bufferEntrada += ch; // Añade el dígito al buffer
		}
		else if ((bufferEntrada[0] == '1') and (bufferEntrada.size() == 2) and (isdigit(ch))) {
			if ((bufferEntrada[1] == '9' and ch < '7') or (bufferEntrada[1] != '9')) {
				establecerCoordenadasPosicion(83, 29);
				cout << ch;
				bufferEntrada += ch; // Añade el dígito al buffer
			}
		}
		else if ((ch == 8) and !(bufferEntrada.size() == 0)) { // Si se presiona la tecla de retroceso
			switch (bufferEntrada.size()) {
			case 1: establecerCoordenadasPosicion(82, 29); break;
			case 2: establecerCoordenadasPosicion(83, 29); break;
			case 3: establecerCoordenadasPosicion(84, 29);break;
			}
			
			//	Borra el último caracter en la consola
			cout << "\b \b"; // Mueve el cursor hacia atrás, imprime un espacio, y luego mueve el cursor hacia atrás de nuevo
			
			//	Elimina el último caracter del bufferEntrada
			bufferEntrada.pop_back();
			
			// Si el buffer queda vacío
			if (bufferEntrada.empty()) primerDigitoNoEsCero = false; // Nuevamente restringe la entrada de ceros como primer dígito
		}
		
	} while (ch != '\r');
	
	if (esX) {
		id = -1;
	}
	else {
		convertidorAEntero(id, bufferEntrada);
	}
	
	return id;
}
void 	medallasCant(int idPais, int medallas){
	borrarInterfazMenu();
	
	mostrarDibujoRecuadroEnCoordenadas(51, 15, 48, 10);
	
	establecerCoordenadasPosicion(57, 18);
	cambiarColorTextoFondo(6, 0);
	imprimirPais(idPais);
	cambiarColorTextoFondo(7, 0);
	establecerCoordenadasPosicion(57, 20);
	cout << "Consiguio un TOTAL de: ";
	cambiarColorTextoFondo(6, 0);
	cout << medallas << " Medallas";
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(62, 23);
	cout << "(Presione X para Regresar)";
	while (toupper(_getch()) != 'X');
}
/// PAIS CON MAS MEDALLAS
void	mergePaisConMasMedallas(int medallasIdDeLosPaises[], int cantidadMedallasIdDeLosPaises[], int inicio1, int final1, int inicio2, int final2) {
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
void	mergesortPaisConMasMedallas(int medallasIdDeLosPaises[], int cantidadMedallasIdDeLosPaises[], int inicio, int finall) {
	if (finall - inicio != 0) {
		mergesortPaisConMasMedallas(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, inicio, (inicio + finall) / 2);
		mergesortPaisConMasMedallas(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, (inicio + finall) / 2 + 1, finall);
		mergePaisConMasMedallas(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, inicio, (inicio + finall) / 2, (inicio + finall) / 2 + 1, finall);
	}
}
void 	titulo_PaisConMasMedallas(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  ___      _                            __      __  __        _      _ _         " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+1);
	cout << " | _ "<< char(92) <<"__ _(_)___  __ ___ _ _    _ __  _/_/ ___ |  "<< char(92) <<"/  |___ __| |__ _| | |__ _ ___" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+2);
	cout << " |  _/ _` | (_-< / _/ _ "<< char(92) <<" ' "<< char(92) <<"  | '  "<< char(92) <<"/ _` (_-< | |"<< char(92) <<"/| / -_) _` / _` | | / _` (_-<" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+3);
	cout << " |_| "<< char(92) <<"__,_|_/__/ "<< char(92) <<"__"<< char(92) <<"___/_||_| |_|_|_"<< char(92) <<"__,_/__/ |_|  |_"<< char(92) <<"___"<< char(92) <<"__,_"<< char(92) <<"__,_|_|_"<< char(92) <<"__,_/__/" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+4);
}
void 	Interfaz_paisConMasMedallas(int idPais, int medallas){
	borrarInterfazMenu();
	
	mostrarDibujoRecuadroEnCoordenadas(28, 12, 95, 18);
	titulo_PaisConMasMedallas(35, 14);
	
	establecerCoordenadasPosicion(52, 22);
	cout << "El País con más Medallas es: ";
	
	cambiarColorTextoFondo(6, 0);
	imprimirPais(idPais);
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(52, 24);
	cout << "Consiguio un TOTAL de: ";
	cambiarColorTextoFondo(6, 0);
	cout << medallas << " Medallas";
	cambiarColorTextoFondo(7, 0);
	
	establecerCoordenadasPosicion(62, 28);
	cout << "(Presione X para Regresar)";
}
///	FUNCIONES GENERALES DE GESTION PRINCIPAL
//	Funciones de ordenamiento
void 	gestionarSecuenciaMenuPaisConMasMedallas(archivoCompetencia Archivo) {
	int idPais, // Variable para almacenar temporalmente el id del pais dentro de deporte_medallas
		paisMax, // Variable para almacenar el id pais con mas medallas
		medallasMax, // Variable para almacenar la cantidad de medallas ganadas
		medallasIdDeLosPaises[196], // Arreglo para almacenar los id de cada pais
		cantidadMedallasIdDeLosPaises[196] = {0}; // Arreglo para almacenar la cantidad de medallas de cada pais
	
	// Calculo el top y su posicion
	for (int i = 0; i < 196; i++) medallasIdDeLosPaises[i] = i;
	for (int i = 0; i < 87; i++) {
		for (int j = 0; j < 3; j++) {
			idPais = Archivo.deporte_medallas[i][j];
			if (idPais != -1) {
				cantidadMedallasIdDeLosPaises[idPais]++;
			}
		}
	}
	mergesortPaisConMasMedallas(medallasIdDeLosPaises, cantidadMedallasIdDeLosPaises, 0, 195);
	
	paisMax = medallasIdDeLosPaises[0];
	medallasMax = cantidadMedallasIdDeLosPaises[0];

	Interfaz_paisConMasMedallas(paisMax, medallasMax);
}
void 	gestionarSecuenciaMenuMedallasDelPais(archivoCompetencia Archivo) {
	int idPais = capturarIngreso(),
		medallas = 0;
	
	if (idPais != -1) {
		for (int i = 0; i < 87; i++) {
			for (int j = 0; j < 3; j++) {
				if (Archivo.deporte_medallas[i][j] == idPais) {
					medallas++;
				}
			}
		}
		
		medallasCant(idPais, medallas);
	}
}
void 	gestionarSecuenciaMenuPaisConMasMedallasDeLosDeportesIndividuales(archivoCompetencia Archivo) {
	calcularMayor(Archivo);
}
void 	gestionarSecuenciaMenuPaisesPremiadosDelDeporte(archivoCompetencia Archivo) {
	int indices[87],
		cantidad = 0;
	
	// INGRESAR LETRA
	borrarInterfazMenu();
	ingresarLetra();
	char letra = _getch();
	borrarInterfazMenu();
	
	if (filtrarPorLetra(letra, indices, cantidad, Archivo)){
		titulo_PaisesPremiadosDelDeporte(20, 6);
		capturarEntradaPPDD(letra, cantidad, indices, Archivo);
	}
	else {
		pantallaErrorDeporte(letra);
		while (toupper(_getch()) != 'X');
	}
}
/// SUB MENU MOSTRAR ESTADISTICAS
//	Funciones para la creación de elementos gráficos en la consola
void 	titulo_MostrarEstadisticas(int xInicio, int yInicio){
	establecerCoordenadasPosicion(xInicio, yInicio);
	cout << "  _____     _            _ __    _   _               " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+1);
	cout << " | ____|___| |_ __ _  __| /_/___| |_(_) ___ __ _ ___ " << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+2);
	cout << " |  _| / __| __/ _` |/ _` | / __| __| |/ __/ _` / __|" << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+3);
	cout << " | |___"<< char(92) <<"__ "<< char(92) <<" || (_| | (_| | "<< char(92) <<"__ "<< char(92) <<" |_| | (_| (_| "<< char(92) <<"__ " << char(92) << endl;
	establecerCoordenadasPosicion(xInicio, yInicio+4);
	cout << " |_____|___/"<< char(92) <<"__"<< char(92) <<"__,_|"<< char(92) <<"__,_|_|___/"<< char(92) <<"__|_|"<< char(92) <<"___"<< char(92) <<"__,_|___/" << endl;
}
void 	equiss(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << " __  __";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " "<< char(92) <<" "<< char(92) <<"/ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  >  < ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /_/"<< char(92) << "_" << char(92);
}
void 	unoo(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " / |";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " | |";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |_|";
}
void 	doss(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ___ ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |_  )";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  / / ";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " /___|";
}
void 	tress(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  ____";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " |__ /";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << "  |_ "<< char(92);
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << " |___/";
}
void 	cuatro(int desdeX, int desdeY){
	establecerCoordenadasPosicion(desdeX, desdeY);
	cout << "  _ _  ";
	establecerCoordenadasPosicion(desdeX, desdeY+1);
	cout << " | | | ";
	establecerCoordenadasPosicion(desdeX, desdeY+2);
	cout << " |_  _|";
	establecerCoordenadasPosicion(desdeX, desdeY+3);
	cout << "   |_| ";
}
void 	opcion1_PaisConMasMedallas(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	unoo(desdeX+10, desdeY+1);
	establecerCoordenadasPosicion(desdeX+2, desdeY+6);
	cout << "País con mas Medallas";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcion2_MedallasDelPais(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	doss(desdeX+9, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Medallas del País";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcion3_PaisConMasDeportesInd(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	tress(desdeX+8, desdeY+1);
	establecerCoordenadasPosicion(desdeX+6, desdeY+6);
	cout << "País con mas" << endl;
	establecerCoordenadasPosicion(desdeX+2, desdeY+7);
	cout << "Deportes Individuales";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcion4_PaisesPremiadosDelDeporte(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 25, 9);
	
	// Texto
	cuatro(desdeX+8, desdeY+1);
	establecerCoordenadasPosicion(desdeX+4, desdeY+6);
	cout << "Países Premiados";
	establecerCoordenadasPosicion(desdeX+7, desdeY+7);
	cout << "del Deporte";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	opcionX_regresarr(int desdeX, int desdeY, bool seleccionada){
	// Cambiar el Color
	seleccionada ? cambiarColorTextoFondo(3,0) : cambiarColorTextoFondo(7,0);
	
	// Recuadro Exterior
	mostrarDibujoRecuadroEnCoordenadas(desdeX, desdeY, 52, 7);
	
	// Texto
	equiss(desdeX+8, desdeY+1);
	establecerCoordenadasPosicion(desdeX+17, desdeY+3);
	cout << "Regresar al Menú Principal";
	
	// Color Normal
	cambiarColorTextoFondo(7,0);
}
void 	mostrarEstadisticas(){
	borrarInterfazMenu();
	
	titulo_MostrarEstadisticas(48, 6);
	
	opcion1_PaisConMasMedallas(22, 13, false);
	opcion2_MedallasDelPais(49, 13, false);
	opcion3_PaisConMasDeportesInd(76, 13, false);
	opcion4_PaisesPremiadosDelDeporte(103, 13, false);
	opcionX_regresarr(49, 22, false);
}
//	Funciones que procesan la interaccion con el usuario
void	procesarInteraccionEleccionOpcionesMenuMostrarEstadisticas(char& opcionSeleccionada)  {
	bool seleccionada = false; // Variable para indicar si se ingreso una opcion antes de presionar enter
	char opcion; // Variable para almacenar temporalmente la opcion ingresada
	
	do {	
		opcion = toupper(_getch());
		
		switch (opcion) {
		case '1':
			opcion1_PaisConMasMedallas(22, 13, true);
			opcion2_MedallasDelPais(49, 13, false);
			opcion3_PaisConMasDeportesInd(76, 13, false);
			opcion4_PaisesPremiadosDelDeporte(103, 13, false);
			opcionX_regresarr(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '1';
			break;
		case '2':
			opcion1_PaisConMasMedallas(22, 13, false);
			opcion2_MedallasDelPais(49, 13, true);
			opcion3_PaisConMasDeportesInd(76, 13, false);
			opcion4_PaisesPremiadosDelDeporte(103, 13, false);
			opcionX_regresarr(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '2';
			break;
		case '3':
			opcion1_PaisConMasMedallas(22, 13, false);
			opcion2_MedallasDelPais(49, 13, false);
			opcion3_PaisConMasDeportesInd(76, 13, true);
			opcion4_PaisesPremiadosDelDeporte(103, 13, false);
			opcionX_regresarr(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '3';
			break;
		case '4':
			opcion1_PaisConMasMedallas(22, 13, false);
			opcion2_MedallasDelPais(49, 13, false);
			opcion3_PaisConMasDeportesInd(76, 13, false);
			opcion4_PaisesPremiadosDelDeporte(103, 13, true);
			opcionX_regresarr(49, 22, false);
			
			seleccionada = true;
			opcionSeleccionada = '4';
			break;
		case 'X':
			opcion1_PaisConMasMedallas(22, 13, false);
			opcion2_MedallasDelPais(49, 13, false);
			opcion3_PaisConMasDeportesInd(76, 13, false);
			opcion4_PaisesPremiadosDelDeporte(103, 13, false);
			opcionX_regresarr(49, 22, true);
			
			seleccionada = true;
			opcionSeleccionada = 'X';
			break;
		}
	} while ((opcion != '\r') || !seleccionada);
}
void	procesarInteraccionMenuMostrarEstadisticas(archivoCompetencia Archivo) {
	char	opcionSeleccionada; // Variable para almacenar la opcion seleccionada por el usuario
	
	do {
		mostrarEstadisticas();
		procesarInteraccionEleccionOpcionesMenuMostrarEstadisticas(opcionSeleccionada);
		if (opcionSeleccionada == '1') {
			gestionarSecuenciaMenuPaisConMasMedallas(Archivo);
			while (toupper(_getch()) != 'X');
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '2') {
			gestionarSecuenciaMenuMedallasDelPais(Archivo);
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '3') {
			gestionarSecuenciaMenuPaisConMasMedallasDeLosDeportesIndividuales(Archivo);
			borrarInterfazMenu();
		} else if (opcionSeleccionada == '4') {
			gestionarSecuenciaMenuPaisesPremiadosDelDeporte(Archivo);
			borrarInterfazMenu();
		} 
	} while(opcionSeleccionada != 'X');
}
//	Funciones generales de gestion principal
void 	gestionarSecuenciaMenuMostrarEstadisticas(archivoCompetencia Archivo) {
	procesarInteraccionMenuMostrarEstadisticas(Archivo);
}
