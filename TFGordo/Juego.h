#pragma once
#include "Celulabase.h"
#include <vector>
#include "Fondo.h"
#include "CJugador.h"
#include "Cellbigsize.h"
#include "Celloflowsize.h"
#include "CelulaVirus.h"
#include "Almacenador.h"
#include "Division.h"
class Juego {

private:
	Jugador * objugador;
	vector<Cellbigsize*>*veccelulabigsize;
	vector<Celloflowsize*>*veccelulalowsize;
	vector<CelulaVirus*>*vecccelulavirus;
	vector<Almacenador*>* vecalmacenador;
	vector<Almacenador*>* vecalmacenador2;
	vector<Division*>* vecdivision;
	Fondo* objfondo;
	int nivel;
	int R, G, B;
	int vidas;
	int tiempo;
	int muertos;
	int numdivision;
public:

	Juego(int pvidas, int ptiempo) {
		srand(time(NULL));
		objugador = new Jugador();
		vecccelulavirus = new vector<CelulaVirus*>;
		veccelulalowsize = new vector<Celloflowsize*>;
		veccelulabigsize = new vector<Cellbigsize*>;
		vecalmacenador = new vector<Almacenador*>;
		vecalmacenador2 = new vector<Almacenador*>;
		vecdivision = new vector<Division*>;
		objfondo = new Fondo();
		nivel = 1;
		vidas = pvidas;
		tiempo = ptiempo;
		muertos = 0;
		numdivision = 8;
	}

	void setTIEMPO(float ptiempo) {
		tiempo = ptiempo;
	}

	float getTIEMPO() {
		return tiempo;
	}

	void dibujar(Graphics^ g, Bitmap^ imgkirby, Bitmap^ fondo) {
		objfondo->dibujar(g, fondo);
		objugador->dibujarjugador(g, imgkirby);
		g->DrawString("Vidas:  " + vidas.ToString(), gcnew Font("Impact", 12), Brushes::White, 40, 0);
		g->DrawString("Tiempo:  " + tiempo.ToString(), gcnew Font("Impact", 12), Brushes::White, 250, 0);
		g->DrawString("Divsiones:  " + numdivision.ToString(), gcnew Font("Impact", 12), Brushes::White, 460, 0);
		for (int i = 0; i < vecccelulavirus->size(); i++)
		{
			vecccelulavirus->at(i)->dibujar(g);
		}

		for (int i = 0; i < veccelulalowsize->size(); i++)
		{
			veccelulalowsize->at(i)->dibujar(g, nivel);
		}

		for (int i = 0; i < veccelulabigsize->size(); i++)
		{
			veccelulabigsize->at(i)->dibujar(g);
		}

		for (int i = 0; i < vecdivision->size(); i++)
		{
			vecdivision->at(i)->dibujar(g, imgkirby);
		}
	
	}

	void moverj(Keys e, Graphics^ g)
	{
		objugador->moverjugador(e, g);
	}

	void movercelulas(Graphics^ g) {
		for (int i = 0; i < veccelulalowsize->size(); i++)
		{
			veccelulalowsize->at(i)->mover(g);
		}

		for (int i = 0; i < veccelulabigsize->size(); i++)
		{
			veccelulabigsize->at(i)->mover(g);
		}

		for (int i = 0; i < vecdivision->size(); i++)
		{
			vecdivision->at(i)->mover(g);
		}

	}

	void agregarCelulas()
	{
		int anchol = 5 + rand() % ((15 + 1) - 1);
		int largol = anchol;
		int anchop = 2 + rand() % ((10 + 1) - 1);
		int largop = anchop;
		if (nivel == 1)
		{
			int x = rand() % 500;
			int y = rand() % 500;
			int dx = rand() % 6 + 1;
			int dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Cellbigsize* aux = new Cellbigsize(x, y, dx, dy, anchol, largol, R, G, B);
			veccelulabigsize->push_back(aux);
			x = rand() % 500;
			y = rand() % 500;
			dx = rand() % 6 + 1;
			dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Celloflowsize* aux2 = new Celloflowsize(x, y, dx, dy, anchop, largop, R, G, B);
			veccelulalowsize->push_back(aux2);
		}
		if (nivel == 2)
		{
			int x = rand() % 500;
			int y = rand() % 500;
			int dx = rand() % 6 + 1;
			int dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Cellbigsize* aux = new Cellbigsize(x, y, dx, dy, anchop*1.5, largop*1.5, R, G, B);
			veccelulabigsize->push_back(aux);
			x = rand() % 500;
			y = rand() % 500;
			dx = rand() % 6 + 1;
			dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Celloflowsize* aux2 = new Celloflowsize(x, y, dx, dy, anchop + 2, largop + 2, R, G, B);
			veccelulalowsize->push_back(aux2);
		}
		if (nivel == 3)
		{
			int x = rand() % 500;
			int y = rand() % 500;
			int dx = rand() % 6 + 1;
			int dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Cellbigsize* aux = new Cellbigsize(x, y, dx, dy, anchop * 3, largop * 3, R, G, B);
			veccelulabigsize->push_back(aux);
			x = rand() % 500;
			y = rand() % 500;
			dx = rand() % 6 + 1;
			dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Celloflowsize* aux2 = new Celloflowsize(x, y, dx, dy, anchop + 4, largop + 4, R, G, B);
			veccelulalowsize->push_back(aux2);
		}


		if (nivel == 4)
		{
			int x = rand() % 500;
			int y = rand() % 500;
			int dx = rand() % 6 + 1;
			int dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Cellbigsize* aux = new Cellbigsize(x, y, dx, dy, anchop*4.5, largop*4.5, R, G, B);
			veccelulabigsize->push_back(aux);
			x = rand() % 500;
			y = rand() % 500;
			dx = rand() % 6 + 1;
			dy = rand() % 6 + 1;
			R = rand() % 225;
			G = rand() % 225;
			B = rand() % 225;

			Celloflowsize* aux2 = new Celloflowsize(x, y, dx, dy, anchop + 6, largop + 6, R, G, B);
			veccelulalowsize->push_back(aux2);
		}
	}

	void agregarVirus()
	{
		if (nivel == 1)
		{
			int x, y;
			for (int i = 0; i < 5; i++)
			{
				x = rand() % 500;
				y = rand() % 500;
				CelulaVirus* aux = new CelulaVirus(x, y);
				vecccelulavirus->push_back(aux);
			}
		}
		if (nivel == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				int x = rand() % 500;
				int y = rand() % 500;
				CelulaVirus* aux = new CelulaVirus(x, y);
				vecccelulavirus->push_back(aux);
			}
		}
		if (nivel == 3)
		{
			for (int i = 0; i < 15; i++)
			{
				int x = rand() % 500;
				int y = rand() % 500;
				CelulaVirus* aux = new CelulaVirus(x, y);
				vecccelulavirus->push_back(aux);
			}
		}
		if (nivel == 4)
		{
			for (int i = 0; i < 20; i++)
			{
				int x = rand() % 500;
				int y = rand() % 500;
				CelulaVirus* aux = new CelulaVirus(x, y);
				vecccelulavirus->push_back(aux);
			}
		}
	}
	void pasarnivel()
	{
		nivel++;
		vecccelulavirus->clear();
		veccelulalowsize->clear();
		veccelulabigsize->clear();
	}
	int get_nivel()
	{
		return nivel;
	}

	void set_nivel(int pnivel)
	{
		nivel = pnivel;
	}

	bool haycolision(int x, int y, int ancho, int largo, int x2, int y2, int ancho2, int largo2)
	{
		if (
			((x + ancho >= x2 && x + ancho <= x2 + ancho2) || (x2 + ancho2 >= x && x2 + ancho2 <= x + ancho))
			&&
			((y + largo >= y2 && y + largo <= y2 + largo2) || (y2 + largo2 >= y && y2 + largo2 <= y + largo))
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void colisionar()
	{
		int x = objugador->getx();
		int y = objugador->gety();
		int ancho = objugador->getancho();
		int largo = objugador->getlargo();
		int masa = objugador->getmasa();

		for (int i = 0; i < vecccelulavirus->size(); i++)
		{
			if (haycolision(x, y, ancho, largo, vecccelulavirus->at(i)->getx(), vecccelulavirus->at(i)->gety(), vecccelulavirus->at(i)->getancho(), vecccelulavirus->at(i)->getlargo()))
			{
				if (masa > vecccelulavirus->at(i)->getmasa())
				{
					objugador->setancho(objugador->getancho() + 5);
					objugador->setlargo(objugador->getlargo() + 5);
					muertos++;
				}
				else
				{
					objugador->setancho(objugador->getancho() - 3);
					objugador->setlargo(objugador->getlargo() - 3);
					if (objugador->getmasa() <= 0)
						vidas = 0;
					else
					vidas--;
				}

				Almacenador* aux = new Almacenador(i);
				vecalmacenador->push_back(aux);
			}
		}
		//eliminar colisionados

			if (vecalmacenador->size() > 0)
			{
				for (int i = 0; i < vecalmacenador->size(); i++)
				{
					vecccelulavirus->erase(vecccelulavirus->begin() + vecalmacenador->at(i)->getposicion());
				}
				vecalmacenador->clear();
			}

 
		for (int i = 0; i < veccelulabigsize->size(); i++)
		{
			if (haycolision(x, y, ancho, largo, veccelulabigsize->at(i)->getx(), veccelulabigsize->at(i)->gety(), veccelulabigsize->at(i)->getancho(), veccelulabigsize->at(i)->getlargo()))
			{
				if (masa > veccelulabigsize->at(i)->getmasa())
				{
					
					objugador->setancho(objugador->getancho() + 5);
					objugador->setlargo(objugador->getlargo() + 5);		
					muertos++;
				}
				else
				{
					objugador->setancho(objugador->getancho() - 3);
					objugador->setlargo(objugador->getlargo() - 3);
					if (objugador->getmasa() <= 0)
						vidas = 0;
					else
						vidas--;
				}

				Almacenador* aux = new Almacenador(i);
				vecalmacenador->push_back(aux);
			}
		}
		//eliminar colisionados
		if (vecalmacenador->size() > 0)
		{
			for (int i = 0; i < vecalmacenador->size(); i++)
			{
				veccelulabigsize->erase(veccelulabigsize->begin() + vecalmacenador->at(i)->getposicion());
			}
			vecalmacenador->clear();
		}

		for (int i = 0; i < veccelulalowsize->size(); i++)
		{
			if (haycolision(x, y, ancho, largo, veccelulalowsize->at(i)->getx(), veccelulalowsize->at(i)->gety(), veccelulalowsize->at(i)->getancho(), veccelulalowsize->at(i)->getlargo()))
			{
				if (masa > veccelulalowsize->at(i)->getmasa())
				{
				
					objugador->setancho(objugador->getancho() + 5);
					objugador->setlargo(objugador->getlargo() + 5);
					muertos++;
				}
				else
				{
					objugador->setancho(objugador->getancho() - 3);
					objugador->setlargo(objugador->getlargo() - 3);
					if (objugador->getmasa() <= 0)
						vidas = 0;
					else
						vidas--;
				}
				Almacenador* aux = new Almacenador(i);
				vecalmacenador->push_back(aux);
			}
		}
		//eliminar colisionados
		if (vecalmacenador->size() > 0)
		{
			for (int i = 0; i < vecalmacenador->size(); i++)
			{
				veccelulalowsize->erase(veccelulalowsize->begin() + vecalmacenador->at(i)->getposicion());
			}
			vecalmacenador->clear();
		}

		//COLISIONAR CON LAS BALAS
		bool colision = false;
		for (int z = 0; z < vecdivision->size(); z++)
		{
			x = vecdivision->at(z)->getx();
			y = vecdivision->at(z)->gety();
			ancho = vecdivision->at(z)->getancho();
			largo = vecdivision->at(z)->getlargo();
			masa = vecdivision->at(z)->getmasa();

			for (int i = 0; i < vecccelulavirus->size(); i++)
			{
				if (!colision)
				{

					if (haycolision(x, y, ancho, largo, vecccelulavirus->at(i)->getx(), vecccelulavirus->at(i)->gety(), vecccelulavirus->at(i)->getancho(), vecccelulavirus->at(i)->getlargo()))
					{
						if (masa > vecccelulavirus->at(i)->getmasa())
						{
							objugador->setancho(objugador->getancho() + 5);
							objugador->setlargo(objugador->getlargo() + 5);
							muertos++;
						}

						Almacenador* aux = new Almacenador(i);
						vecalmacenador->push_back(aux);
						Almacenador* aux2 = new Almacenador(z);
						vecalmacenador2->push_back(aux2);
						colision = true;
					}
				}
			}
			//eliminar colisionados

			if (vecalmacenador->size() > 0)
			{
				for (int i = 0; i < vecalmacenador->size(); i++)
				{
					vecccelulavirus->erase(vecccelulavirus->begin() + vecalmacenador->at(i)->getposicion());
				}
				vecalmacenador->clear();
			}


			for (int i = 0; i < veccelulabigsize->size(); i++)
			{
				if (!colision)
				{
					if (haycolision(x, y, ancho, largo, veccelulabigsize->at(i)->getx(), veccelulabigsize->at(i)->gety(), veccelulabigsize->at(i)->getancho(), veccelulabigsize->at(i)->getlargo()))
					{
						if (masa > veccelulabigsize->at(i)->getmasa())
						{

							objugador->setancho(objugador->getancho() + 5);
							objugador->setlargo(objugador->getlargo() + 5);
							muertos++;
						}

						Almacenador* aux = new Almacenador(i);
						vecalmacenador->push_back(aux);
						Almacenador* aux2 = new Almacenador(z);
						vecalmacenador2->push_back(aux2);
						colision = true;
					}
				}
			}
			//eliminar colisionados
			if (vecalmacenador->size() > 0)
			{
				for (int i = 0; i < vecalmacenador->size(); i++)
				{
					veccelulabigsize->erase(veccelulabigsize->begin() + vecalmacenador->at(i)->getposicion());
				}
				vecalmacenador->clear();
			}

			for (int i = 0; i < veccelulalowsize->size(); i++)
			{
				if (!colision)
				{
					if (haycolision(x, y, ancho, largo, veccelulalowsize->at(i)->getx(), veccelulalowsize->at(i)->gety(), veccelulalowsize->at(i)->getancho(), veccelulalowsize->at(i)->getlargo()))
					{
						if (masa > veccelulalowsize->at(i)->getmasa())
						{

							objugador->setancho(objugador->getancho() + 5);
							objugador->setlargo(objugador->getlargo() + 5);
							muertos++;
						}
						Almacenador* aux = new Almacenador(i);
						vecalmacenador->push_back(aux);
						Almacenador* aux2 = new Almacenador(z);
						vecalmacenador2->push_back(aux2);
						colision = true;
					}
				}
			}
			//eliminar colisionados
			if (vecalmacenador->size() > 0)
			{
				for (int i = 0; i < vecalmacenador->size(); i++)
				{
					veccelulalowsize->erase(veccelulalowsize->begin() + vecalmacenador->at(i)->getposicion());
				}
				vecalmacenador->clear();
			}
		}
		if (vecalmacenador2->size() > 0)
		{
			for (int i = 0; i < vecalmacenador2->size(); i++)
			{
				vecdivision->erase(vecdivision->begin() + vecalmacenador2->at(i)->getposicion());
			}
			vecalmacenador2->clear();
		}

		//COLISIONAR CELULAS GRANDES
		for (int z = 0; z < veccelulabigsize->size(); z++)
		{
			x = veccelulabigsize->at(z)->getx();
			y = veccelulabigsize->at(z)->gety();
			ancho = veccelulabigsize->at(z)->getancho();
			largo = veccelulabigsize->at(z)->getlargo();
			masa = veccelulabigsize->at(z)->getmasa();

			for (int i = 0; i < veccelulalowsize->size(); i++)
			{
				if (haycolision(x, y, ancho, largo, veccelulalowsize->at(i)->getx(), veccelulalowsize->at(i)->gety(), veccelulalowsize->at(i)->getancho(), veccelulalowsize->at(i)->getlargo()))
				{
					if (masa > veccelulalowsize->at(i)->getmasa())
					{

						veccelulabigsize->at(z)->setancho(veccelulabigsize->at(z)->getancho() + 5);
						veccelulabigsize->at(z)->setlargo(veccelulabigsize->at(z)->getlargo() + 5);
					}
					Almacenador* aux = new Almacenador(i);
					vecalmacenador->push_back(aux);
				}
			}
			//eliminar colisionados
			if (vecalmacenador->size() > 0)
			{
				for (int i = 0; i < vecalmacenador->size(); i++)
				{
					veccelulalowsize->erase(veccelulalowsize->begin() + vecalmacenador->at(i)->getposicion());
				}
				vecalmacenador->clear();
			}
		}
	}
	
	void dividirpoder()
	{
		if (numdivision > 0 && objugador->getmasa()>2)
		{
			Division* aux = new Division(objugador->getx(), objugador->gety(), objugador->getancho()/2, objugador->getlargo()/2, objugador->getdxa()*3, objugador->getdya()* 3);
			objugador->setancho(objugador->getancho() / 2);
			objugador->setlargo(objugador->getlargo() / 2);
			vecdivision->push_back(aux);
			numdivision--;
		}
		
	}
	bool borrarvirus()
	{
		if (vecccelulavirus->size() > 1)
		{
			vecccelulavirus->erase(vecccelulavirus->begin() + 1);
			return true;
		}

		else
			return false;
	}

	bool seborra()
	{
		if (vecccelulavirus->size() > 1)
		{
			return true;
		}

		else
			return false;
	}

	//get puntaje o sea masa
	int getpuntaje()
	{
		return objugador->getmasa();
	}

	int getmuertos()
	{
		return muertos;
	}

	int xvirus()
	{
		return vecccelulavirus->at(1)->getx();
	}
	int yvirus()
	{
		return vecccelulavirus->at(1)->gety();
	}
	int anchovirus()
	{
		return vecccelulavirus->at(1)->getancho();
	}
	int largovirus()
	{
		return vecccelulavirus->at(1)->getlargo();
	}

	int getvidas()
	{
		return vidas;
	}

	void setvidas(int p)
	{
		vidas = p;
	}

	void setmuertos(int p)
	{
		muertos = p;
	}
};