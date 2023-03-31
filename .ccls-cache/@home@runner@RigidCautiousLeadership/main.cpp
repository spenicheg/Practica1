#include <iostream>
#include <string>
#include <list>

class Articulo {
public:
    std::string nombre;
    int id;
    double precio;
    bool disponibilidad;
    std::string tipoC;
    
    Articulo(std::string nombre, int id, double precio, bool disponibilidad, std::string tipoC) : nombre(nombre), id(id), precio(precio), disponibilidad(disponibilidad), tipoC(tipoC){}
};

class Inventario {
public:
    std::list<Articulo*> articulos;
    int size = 0;
      
    void agregar(Articulo* articulo) {
        articulos.push_back(articulo);
        size = size + 1;
    }

    void modificar(int id, std::string nuevo_nombre, double nuevo_precio, bool nueva_dis) {
        for (Articulo* articulo : articulos) {
            if (articulo->id == id) {
                articulo->nombre = nuevo_nombre;
                articulo->precio = nuevo_precio;
                articulo->disponibilidad = nueva_dis;
                break;
            }
        }
    }

    void eliminar(int id) {
        articulos.remove_if([id](Articulo* articulo) { return articulo->id == id; });
      size= size-1;
    }

    Articulo* buscar(int id) {
        for (Articulo* articulo : articulos) {
            if (articulo->id == id) {
                return articulo;
            }
        }
    }
};

void mostrar_articulos(Inventario& inventario) {
    std::cout << "Articulos:\n";
    for (Articulo* articulo : inventario.articulos) {
           std::cout << "ID: " << articulo->id << ", Nombre: " << articulo->nombre << ", Precio: $" << articulo->precio << ", Disponible: " << articulo->disponibilidad << ", Tipo: " << articulo->tipoC << "\n";
        }
    }
    

int main() {
    Inventario deportivo;
    Inventario tecnologia;
    Inventario inventario;
    Inventario extranjero;
    std::list<Articulo*> carrito;
    int opcion, id, tipo;
    int opcion2, opcion3;
    std::string nombre;
    double precio;
    bool disponibilidad;
    std::string tipoC;
    while (true) {
        std::cout<<"BIENVENIDO A ";
        std::cout << "EAFI-ZON\n1. Coordinador\n2. Cliente\n3. Salir\n";
        std::cin >> opcion;

        if (opcion == 1) {
            std::cout << "1. Agregar articulo\n2. Modificar articulo\n3. Eliminar articulo\n4. Volver\n";
            std::cin >> opcion2;

            if (opcion2 == 1) {
                std::cout << "Tipo de Articulo: ";
                std::cin >> tipoC;
                std::string clase1= "deportivo"; 
                std::string clase2 = "tecnologico";
                
                if(tipoC == clase1){
                  std::cout << "Nombre: ";
                  std::cin >> nombre;
                  std::cout << "ID: ";
                  std::cin >> id;
                  std::cout << "Precio: ";
                  std::cin >> precio;
                  std::cout << "Disponibilidad: ";
                  std::cin >> disponibilidad;
                  inventario.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                  deportivo.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                }
                if(tipoC == "extranjero"){
                  double precioUsuario;
                  std::cout << "Nombre: ";
                  std::cin >> nombre;
                  std::cout << "ID: ";
                  std::cin >> id;
                  std::cout << "Precio: ";
                  std::cin >> precioUsuario;
                  precio = precioUsuario+(precioUsuario/10);
                  std::cout << "Disponibilidad: ";
                  std::cin >> disponibilidad;
                  inventario.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                  extranjero.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                }
                if(tipoC == clase2){
                  std::cout << "Nombre: ";
                  std::cin >> nombre;
                  std::cout << "ID: ";
                  std::cin >> id;
                  std::cout << "Precio: ";
                  std::cin >> precio;
                  std::cout << "Disponibilidad: ";
                  std::cin >> disponibilidad;
                  inventario.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                  tecnologia.agregar(new Articulo(nombre, id, precio, disponibilidad, tipoC));
                }
                } 
            } else if (opcion2 == 2) {
                std::cout << "ID del articulo: ";
                std::cin >> id;
                std::cout << "Nuevo nombre: ";
                std::cin >> nombre;
                std::cout << "Nuevo precio: ";
                std::cin >> precio;
                std::cout<<"Disponibilidad";
                std::cin >> disponibilidad;

                inventario.modificar(id, nombre, precio, disponibilidad);
            } else if (opcion2 == 3) {
                std::cout << "ID del articulo: ";
                std::cin >> id;

                inventario.eliminar(id);
            
        } else if (opcion == 2) {
            std::cout << "1. Comprar articulo\n2. Pagar\n3. Volver\n";
            std::cin >> opcion3;

            if (opcion3 == 1) {
                mostrar_articulos(deportivo);
                mostrar_articulos(tecnologia);
                mostrar_articulos(extranjero);
                std::cout << "ID del articulo: ";
                std::cin >> id;
                Articulo* articulo = inventario.buscar(id);
                double total = 0;
                total += articulo->precio;
                std::cout<<"Articulo agregado al carrito"<< "\n";
                std::cout<<"Este es su total hasta ahora: "<< total<<"\n";
                if (articulo) {
                    carrito.push_back(articulo);
                }
            } else if (opcion3 == 2) {
                std::cout<<"Pago realizado";
                }
            }
        else if(opcion==3){
          break;
        }
        }
    }

