#include <iostream>
using namespace std;

class usuario
{
public:
    string name;

    int edad;
    string telefono;
    string password;

public:
    // Login
    bool login(string contra)
    {
        if (contra == password)
        {
            cout << "Iniciaste sesion" << endl;
            return true;
        }
        else
        {
            cout << "Password incorrecta" << endl;
            return false;
        }
    }

    // ChangePassword
    void cPassword(string cActual, string cnueva)
    {
        if (cActual == this->password)
        {
            setPassword(cnueva);
            cout << "Se cambió la password a " << this->password << endl;
        }
        else
        {
            cout << "La contraseña actual no coincide. No se cambió la password." << endl;
        }
    }

    // Cerrar sesion
    void logout()
    {
        cout << "Cerraste sesión XDXD" << endl;
    }

    // Setters
    void setPassword(string pass)
    {
        this->password = pass;
    }
};

class cliente : public usuario
{
public:
    int dinero;

    void comprar()
    {
        this->dinero = this->dinero - 1;
        cout << "COMPRASTE ALGO XDXD" << endl;
    }

    void reclamar()
    {
        this->dinero = this->dinero + 10;
        cout << "HACES UN RECLAMO :D" << endl;
    }

    void devolver()
    {
        this->dinero = this->dinero + 100;
        cout << "DEVUELVES ALGO IDK U.U" << endl;
    }
};

class vendedor : public usuario
{
public:
    int dinero;
    void vender()
    {
        this->dinero = this->dinero + 10;
        cout << "Vendes algo idk" << endl;
    }

    void actualizar()
    {
        this->dinero = this->dinero + 10;
        cout << "Vendes algo idk" << endl;
    }
};

int main()
{
    // Set
    cout << "Bienvenido, vendedor o cliente? (1.vendedor, 2. cliente )" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
        // VENDEDOR
        vendedor nVendedor;
        nVendedor.setPassword("uwu");
        cout << "Para iniciar sesion introduzca su password" << endl;
        string password;
        cin >> password;
        bool login = nVendedor.login(password);
        if (login == true)
        {
            cout << "Que desea hacer (1. cambiar password, 2 vender, 3 actualizar, 4 logout)" << endl;
            int opcion;
            cin >> opcion;
            if (opcion == 1)
            {
                cout << "Cambio de password. Introduzca su password actual" << endl;
                string newPass;
                cin >> password;
                cout << "Introduzca su nuevo password" << endl;
                cin >> newPass;
                nVendedor.cPassword(password, newPass);
            }
            if (opcion == 2)
            {
                nVendedor.actualizar();
            }

            if (opcion == 3)
            {
                nVendedor.vender();
            }

            if (opcion == 4)
            {
                nVendedor.logout();
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        // CLIENTE

        cliente nCliente;
        nCliente.setPassword("owo");
        cout << "Para iniciar sesion introduzca su password" << endl;
        string password;
        cin >> password;
        bool login = nCliente.login(password);
        if (login == true)
        {
            cout << "Que desea hacer (1. cambiar password, 2 comprar, 3 devolver, 4 logout)" << endl;
            int opcion;
            cin >> opcion;
            if (opcion == 1)
            {
                cout << "Cambio de password. Introduzca su password actual" << endl;
                string newPass;
                cin >> password;
                cout << "Introduzca su nuevo password" << endl;
                cin >> newPass;
                nCliente.cPassword(password, newPass);
            }
            if (opcion == 2)
            {
                nCliente.comprar();
            }

            if (opcion == 3)
            {
                nCliente.devolver();
            }

            if (opcion == 4)
            {
                nCliente.logout();
            }
        }
        else
        {
            return 0;
        }
    };

    return 0;
}
