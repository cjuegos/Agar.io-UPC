#pragma once
#include "Celulabase.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Jugador : public Celulabase {

private:
	int vidas;
	int puntaje;
	int dxalmacenado;
	int dyalmacenado;
public:

	Jugador() {
		x = 10;
		y = 10;
		ancho = 25;
		largo = 25;
		dx = 4;
		dy = 4;
		masa = largo + ancho;
		dxalmacenado = dx;
		dyalmacenado = dy;
	}
	~Jugador() {

	}

	void dibujarjugador(Graphics ^g, Bitmap^ imgkirby) {
		masa = largo + ancho;
		Rectangle Origen = Rectangle(0, 0, 564, 564);
		Rectangle Destino = Rectangle(x, y, ancho, largo);
		g->DrawImage(imgkirby, Destino, Origen, GraphicsUnit::Pixel);
		g->DrawString(masa.ToString(), gcnew Font("Impact", 6), Brushes::White, x + ancho / 2 - ancho / 5, y + largo / 2 - largo / 5);
	}

	void moverjugador(Keys e, Graphics ^g) {
		if (e == Keys::Right)
		{
			dx = 4;
			dxalmacenado = dx;
			dyalmacenado = 0;
			if (x + dx + ancho< g->VisibleClipBounds.Width)
			x = x + dx;
		}
		if (e == Keys::Left)
		{
			dx = -4;
			dxalmacenado = dx;
			dyalmacenado = 0;
			if (x + dx > 0)
			x = x + dx;
		}
		if (e == Keys::Up )
		{
			dy = -4;
			dxalmacenado = 0;
			dyalmacenado = dy;
			if (y + dy > 0)
			y = y + dy;
		}
		if (e == Keys::Down)
		{
			dy = 4;
			dxalmacenado = 0;
			dyalmacenado = dy;
			if(y + dy + largo < g->VisibleClipBounds.Height)
			y = dy + y;
		}
	}

	int getdxa()
	{
		return dxalmacenado;
	}

	int getdya()
	{
		return dyalmacenado;
	}

};