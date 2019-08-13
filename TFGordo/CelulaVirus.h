#pragma once
#include "Celulabase.h"
using namespace System::Windows::Forms;

class CelulaVirus : public Celulabase {

private:


public:
	CelulaVirus(int px, int py) {
		x = px;
		y = py;
		ancho = 10;
		largo = 10;
	}
	void dibujar(Graphics ^ g) {
		g->FillEllipse(Brushes::Green, x, y, ancho, largo);
	}
};