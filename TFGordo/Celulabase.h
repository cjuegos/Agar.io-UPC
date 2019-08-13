#pragma once
#include <iostream>
#include <stdlib.h> // srand, rand 
#include <time.h> // time
using namespace System;
using namespace System::Drawing;
using namespace std;

class Celulabase {

protected:
	int x;
	int y;
	int dy;
	int dx;
	int ancho;
	int largo;
	int color;
	double masa;

public:

	Celulabase() {
	}
	~Celulabase() {}
	int getx() { return x; }
	int gety() { return y; }
	int getdy() { return dy; }
	int getdx() { return dx; }
	int getancho() { return ancho; }
	int getlargo() { return largo; }
	int getcolor() { return color; }
	double getmasa() { return masa; }
	void setx(int px) {
		x = px;
	}

	void sety(int py) {
		y = py;
	}

	void setdy(int pdy) {
		dy = pdy;
	}

	void setdx(int pdx) {
		dx = pdx;
	}

	void setancho(int pancho) { ancho = pancho; }
	void setlargo(int plargo) { largo = plargo; }

	void setcolor(int pcolor) { color = pcolor; }

	void setmasa(int pmasa)
	{
		masa = pmasa;
	}
};