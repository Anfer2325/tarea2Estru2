#include "ArchivoItem.h";
#include "ContadorTiempo.h";

int main() {
	ArchivoItem item;
	ContadorTiempo timer;
	timer.start();
	item.buscarSecuencial("PEDRO");
	timer.stop();
	cout << " Tiempo LINEAL: " <<timer.elapsedSeconds()<<endl;
	timer.start();
	item.buscarBinario("PEDRO"); 
	timer.stop();
	cout << " Tiempo BINARIO: " << timer.elapsedSeconds() << endl;
	
	
}
