#pragma once
#include "Celulabase.h"

class Celloflowsize : public Celulabase {

private:

	int R, G, B;


	int nivel;
public:

	Celloflowsize(int px, int py, int pdx, int pdy, int pancho, int plargo, int pR, int pG, int pB) {

		x = px;
		y = py;
		dx = pdx;
		dy = pdy;
		ancho = pancho;
		largo = plargo;
		R = pR;
		G = pG;
		B = pB;
		masa = ancho + largo;
		nivel = 1;
	}

	void dibujar(Graphics^g, int pnivel) {
		nivel = pnivel;
		SolidBrush ^miBrocha = gcnew SolidBrush(Color::FromArgb(R, G, B));
		g->FillEllipse(miBrocha, x, y, ancho, largo);
		g->DrawString(masa.ToString(), gcnew Font("Impact", 6), Brushes::White, x + ancho / 2 - ancho / 5, y + largo / 2 - largo / 5);
	}

	void mover(Graphics ^g)
	{
		if (x + dx + ancho > g->VisibleClipBounds.Width || x + dx<0)
			dx = dx * -1;

		if (y + dy + largo> g->VisibleClipBounds.Height || y + dy<0)
			dy = dy * -1;
		x = x + dx;
		y = y + dy;
	}
};