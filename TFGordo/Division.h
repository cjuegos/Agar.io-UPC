#pragma once
#include "Celulabase.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Division : public Celulabase {

private:
	int vidas;
	int puntaje;
	string nombre;

public:

	Division(int px, int py, int pancho, int plargo, int pdx, int pdy) {
		x = px;
		y = py;
		ancho = pancho;
		largo = plargo;
		dx = pdx;
		dy = pdy;
		masa = largo + ancho;
	}
	void dibujar(Graphics ^g, Bitmap^ imgkirby) {
		masa = largo + ancho;
		Rectangle Origen = Rectangle(0, 0, 564, 564);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgkirby, Destino, Origen, GraphicsUnit::Pixel);
		g->DrawString(masa.ToString(), gcnew Font("Impact", 6), Brushes::White, x + ancho / 2 - ancho / 5, y + largo / 2 - largo / 5);
	}

	void mover(Graphics ^g) {
		if (x + dx + ancho > g->VisibleClipBounds.Width || x + dx<0)
			dx = dx * -1;

		if (y + dy + largo> g->VisibleClipBounds.Height || y + dy<0)
			dy = dy * -1;
		x = x + dx;
		y = y + dy;
	}

};