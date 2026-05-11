#include <iostream>
#include <windows.h>
#include "gestionar.h"

using namespace std;

int main() {
	system("mode con: cols=150 lines=40");
	int		id_legajo = 0; // identificador del usuario
	if (gestionarSecuenciaBienvenida()) 
		if (gestionarSecuenciaLogin(id_legajo)) 
			gestionarSecuenciaMenuPrincipal(id_legajo);
	
	return 0;
}
