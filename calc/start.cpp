#include <iostream>
#include <stdlib.h>
#include <math.h> 


using std::endl;
using std::cout;

class Coordenada {

	private:

		std::string coordenada_nombre;
		std::string tipo_coordenada;

		std::coor1;
		std::coor2;
		std::coor3;

		int id;

		bool point_assigned = false;

	public:

		Coordenada(const std::string& coordenada_nombre, const int id_coor){
			this -> coordenada_nombre = coordenada_nombre;
			this -> tipo_coordenada;

			this -> coor1;
			this -> coor2;
			this -> coor3;

			this -> id = id_coor;
		}

		void asignar_tipo(const std::string& tipo_coordenada){
			tipo_coordenada = tipo_coordenada;
		}

		void registrar(const std:string& coordenadas){

			this -> coor1 = coor1;
			this -> coor2 = coor2;
			this -> coor3 = coor3;
		}

		void existe_ptoControl(const int id_coor){
			search(id_coor);
		}	

		std::string get_tipo_coordenada(){
			return tipo_coordenada;
		}
};

class puntoControl {
	private:

		std::string tipo:
		std::string name;
		std::string id;
		std::string location;

		bool estatico = true;

	public:

		puntoControl(){
			this -> id;

			this -> name;

			this -> location;

		}


		void asignar_coordenada(const int id_coor){
			//si existe una coordenada, notificar

			


		}

}

class Perfil {

	private:

		std::string nivelacion_tipo;
		std::string sub_tipo_nivelacion;

		bool setted_data = false;
		

	public:

		Perfil(const std::string& nivelacion_tipo) {

			this -> nivelacion_tipo= nivelacion_tipo;
			this -> sub_tipo_nivelacion;
		}

		std::string get_tipo_nivelacion(){
			return nivelacion_tipo;
		}

		std::string get_sub_tipo(){
			return sub_tipo_nivelacion;
		}

		void asignar_sub_tipo(const std::string& nuevo){
			this -> sub_tipo_nivelacion = nuevo;
		}

		void set_data(){
			setted_data = true;
		}

};

int main(){

	Perfil nuevoPerfil("geometrica");

	nuevoPerfil.asignar_sub_tipo("simple");

	cout << nuevoPerfil.get_tipo_nivelacion() << endl;
	cout << nuevoPerfil.get_sub_tipo() << endl;
	return 0;
}

