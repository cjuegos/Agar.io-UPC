#pragma once
class Almacenador
{
	private:
		int posicion;
	public:
		Almacenador(int p)
		{
			posicion = p;
		}

		int getposicion()
		{
			return posicion;
		}

		void setposicion(int p)
		{
			posicion = p;
		}
};