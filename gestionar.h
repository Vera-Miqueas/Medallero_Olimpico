#include "competidores.h"
#ifndef GESTIONAR_H
#define GESTIONAR_H
bool	gestionarSecuenciaBienvenida();
bool	gestionarSecuenciaLogin(int);
void	gestionarSecuenciaMenuCargarMedallas(bool &, archivoCompetencia &);
void	gestionarSecuenciaMenuMostrarMedallero(archivoCompetencia);
void	gestionarSecuenciaMenuGenerarCompetencia(int, bool &, bool &, archivoCompetencia &);
void	gestionarSecuenciaCargaDeporteIndividual(bool &, archivoCompetencia &);
void	gestionarSecuenciaCargaDeporteColectivo(bool &, archivoCompetencia &);
void	gestionarSecuenciaMenuPrincipal(int);
void	gestionarSecuenciaMostrarMedalleroPorPais(archivoCompetencia);
void	gestionarSecuenciaMostrarMedalleroPorDeporte(archivoCompetencia);
void	gestionarSecuenciaMostrarMedalleroTOP(archivoCompetencia);
void	gestionarSecuenciaMenuMostrarEstadisticas(archivoCompetencia);
#endif
