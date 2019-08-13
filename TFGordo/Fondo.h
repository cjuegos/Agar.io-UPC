#pragma once

#include <iostream>
#include "Celulabase.h"
using namespace System;

class Fondo : public Celulabase

{
private:

public:
	Fondo() {
		x = 0;
		y = 0;
		ancho = 1100;
		largo = 900;
	}

	void dibujar(Graphics ^g, Bitmap^ imgkirby) {

		Rectangle Origen = Rectangle(0, 0, 608, 342);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgkirby, Destino, Origen, GraphicsUnit::Pixel);
	}
};