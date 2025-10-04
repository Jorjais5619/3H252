#include <iostream>
using namespace std;
class Empleado{
    private:
        char nombre[10];        //10B
        int edad;               //4B
        char direccion[255];    //255B
        int telefono;           //4B
                                //273 B TOTAL
    public:
    int LeerEdad(){
      return edad;
    }                            
};
int main(int arge,char const *argv[])
{
//TAMAÑOS DE MEMORIA ESTATICA

    //ENTEROS
  cout<<"Tamaño de int: "<<sizeof(int)<<endl;
  cout<<"Tamaño de long: "<<sizeof(long)<<endl;
  //PUNTO FLOTANTE
  cout<<"Tamaño de float: "<<sizeof(float)<<endl;
  cout<<"Tamaño de double: "<<sizeof(double)<<endl;
  //BYTES
  cout<<"Tamaño de char: "<<sizeof(char)<<endl;
  cout<<"Tamaño de byte: "<<sizeof(byte)<<endl;
  cout<<"Tamaño de bool: "<<sizeof(bool)<<endl;

Empleado empleados[10];//2 730 B
  cout<<"Tamaño Empleado: "<<sizeof(Empleado)<<endl;
  cout<<"Empleados: "<< empleados[0].LeerEdad() << endl;

  int a=64;
  char b=(char)a;
  cout<<b<<endl;

  return 0;
}