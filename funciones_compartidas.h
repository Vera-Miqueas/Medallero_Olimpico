#include <windows.h>
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

#ifndef FUNCIONES_COMPARTIDAS_H
#define FUNCIONES_COMPARTIDAS_H
void	establecerCoordenadasPosicion(SHORT xInicio, SHORT yInicio);
void	imprimirCaracterRepetido(int caracter, int veces);
void	limpiarAreaRecuadroEnCoordenadas(int xInicio, int yInicio, int ancho, int alto);
void	configurarVisibilidadCursor(bool mostrarCursor);
void	cambiarColorTextoFondo(int colorTexto, int colorFondo);
void	mostrarDibujoLineaRectaEnCoordenadas(int ancho);
void	mostrarDibujoRecuadroEnCoordenadas(int xInicio, int yInicio, int ancho, int alto);
void	mostrarDibujoLineaTituloEnCoordenadas(int xInicio, int yInicio);
void	mostrarMensajeDespedida(int xInicio, int yInicio);
void	mostrarDibujoOpcionSeleccionada(int xInicio, int yInicio, int ancho, int alto);
void	borrarInterfazMenu();
void	mostrarInterfazCargaExitosa();
void	convertidorAEntero(int&, string);
string	NombreArchivo(const tm& fecha);
void 	numeroPagina(int, int, int, int);
#endif
