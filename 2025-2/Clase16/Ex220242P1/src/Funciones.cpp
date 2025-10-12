//
// Created by Erasmo on 11/10/25.
//

#include "Funciones.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

void open_file_write(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

void imprimirLinea(ofstream &archivo, char car, int cant) {
    for (int i = 0; i < cant; i++)
        archivo.put(car);
    archivo << endl;
}

void leerImprimirNombre(ifstream &archDatos, ofstream &output,
                        char carDelim, int tam) {
    int cant = 0;
    char car;
    archDatos >> ws;
    while (true) {
        car = archDatos.get();
        if (car == carDelim) break;
        if (car == '_') car = ' ';
        output.put(car);
        cant++;
    }
    for (int i = 0; i < tam - cant; i++)
        output.put(' ');

}

void procesarRepartidor(int dist, char vehic, ifstream
&input_repartidores,
                        ofstream &output, double pagoRepartidor) {
    int dni, cod;
    char tipoVehic;
    input_repartidores.clear();
    input_repartidores.seekg(0, ios::beg);
    while (true) {
        input_repartidores >> dni;
        if (input_repartidores.eof()) {
            //output<<"REPARTIDOR: No hay repartidor asignado al distrito y tipo de vehiculo ";
            //cout<<setw(10)<<dist<<setw(3)<<vehic<<endl;
            break;
        }
        input_repartidores >> tipoVehic;
        while (input_repartidores.get() != ' ');
        input_repartidores >> cod;
        if (cod == dist and vehic == tipoVehic) {
            output << "REPARTIDOR: " << dni << " - ";
            break;
            leerImprimirNombre(input_repartidores, output, '\n', TAM_REPARTIDOR);
        } else
            while (input_repartidores.get() != '\n');
    }
    output << "PAGO TOTAL: " << setw(12) << pagoRepartidor << endl;
}

void buscarPlato(int plato, ifstream &archPlatos, ofstream &output,
                 double &precio, double &valDesc) {
    int cod, cant;
    char car;
    precio = valDesc = 0;
    archPlatos.clear();
    archPlatos.seekg(0, ios::beg);
    //11171   TORTA DE CHOCOLATE}   15.90   64   19.42%
    while (true) {
        archPlatos >> cod;
        if (archPlatos.eof()) break;
        if (cod == plato) {
            leerImprimirNombre(archPlatos, output, '}', TAM_PLATO);
            archPlatos >> precio >> cant;
            if (archPlatos.get() != '\n')
                archPlatos >> valDesc >> car;
            break;
        } else
            while (archPlatos.get() != '\n');
    }
}

void procesarPlatos(double valDescCli, ifstream &input_repartos, ifstream
&archPlatos, ofstream &output, double &totPagoCliente, double &totalPedSinDesc) {
    int cant, plato, num = 1;
    double precio, valDesc, subTotal = 0, desc, descTotal = 0, descCliente;
    totalPedSinDesc = 0;
    char c;
    //   8   77971   7   77549   7   53502   2   15592   3   15283   4   39864   7   77894   9   39695
    output<<fixed;
    output<<setprecision(2);
    while (true) {
        input_repartos >> cant >> plato;
        output << setw(6) << "" << setw(2) << num << ')' << setw(6) << plato << setw(3) << "";
        buscarPlato(plato, archPlatos, output, precio, valDesc);
        subTotal = precio * cant;
        desc = subTotal * valDesc / 100;

        output << setw(4) << cant << setw(10) << precio << setw(10) << subTotal <<
                    setw(15) << valDesc << "% - " << setw(6) << desc << endl;
        num++;
        totalPedSinDesc += subTotal;
        descTotal += desc;
        c = input_repartos.get();
        if (c == '\r') break; //Aca es \r o \n dependiendo del sistema operativo, en windows use \n
    }
    descCliente = totalPedSinDesc * valDescCli / 100;
    totPagoCliente = totalPedSinDesc - descTotal - descCliente;
    imprimirLinea(output, '-', TAM_LINEA);
    output << setw(5) << ' ' << "TOTAL PEDIDO SINDESCUENTOS:" << setw(12) << totalPedSinDesc << endl;
    output << setw(5) << ' ' << "DESCUENTO TOTAL POR PLATOS:" << setw(12) << descTotal << endl;
    output << setw(5) << ' ' << "DESCUENTO DEL CLIENTE:" << setw(12) << descCliente << endl;
    output << setw(5) << ' ' << "TOTAL PAGADO POR ELCLIENTE:" << setw(12) << totPagoCliente << endl;
}

void procesarRepartos(int dni, double valDescCli, char vehic,
                      ifstream &input_repartos, ifstream &archPlatos,
                      ifstream &input_repartidores, ofstream &output,
                      double &montoCliente, double &pagoRepartidor) {
    int pedido, dni_leido, num = 1;
    double totPagoCliente, totalPedSinDesc, totRepartidor = 0.0;
    pagoRepartidor = montoCliente = 0;
    input_repartos.clear();
    input_repartos.seekg(0, ios::beg);
    output << "REPARTOS: " << endl;
    while (true) {
        //Parte Estatica
        input_repartos >> pedido;
        if (input_repartos.eof()) break;
        input_repartos >> dni_leido;
        if (dni_leido == dni) {
            imprimirLinea(output, '-', TAM_LINEA);
            output << setfill('0') << setw(2) << num << setfill(' ') << ")PEDIDO:" << pedido << endl;
            output << setw(35) << "PLATO" << setw(45) << "CANTIDAD" << setw(8) << "PRECIO" << setw(10)
                        << "SUBTOTAL" << setw(15) << "DESCUENTO" << endl;
            pagoRepartidor += (totRepartidor);
            //Parte Dinamica
            procesarPlatos(valDescCli, input_repartos, archPlatos, output,
                           totPagoCliente, totalPedSinDesc);
            montoCliente += totPagoCliente;
            if (vehic == 'M')
                totRepartidor = totalPedSinDesc * 0.1;
            else
                totRepartidor = totalPedSinDesc * 0.05;
            output << setw(5) << ' ' << "PAGO AL REPARTIDOR:" << setw(12) <<
                        totRepartidor << endl;
            num++;
        } else
            //Ignorar
            //input_repartos.ignore(250, '\n');
            while (input_repartos.get() != '\n');
    }

}

void procesarRepartosDeClientes(const char *file_name_clientes,
                                const char *file_name_platos,
                                const char *file_name_repartidores,
                                const char *file_name_repartos,
                                const char *file_name_reporte) {
    int dni, dist;
    char vehic, desc, car;
    double valDescCli, montoCliente, pagoRepartidor, totalRecaudado, totalRepartidores;
    // Apertura de Archivos
    ifstream input_clientes; open_file_read(input_clientes, file_name_clientes);
    ifstream input_platos; open_file_read(input_platos, file_name_platos);
    ifstream input_repartidores; open_file_read(input_repartidores, file_name_repartidores);
    ifstream input_repartos; open_file_read(input_repartos, file_name_repartos);

    ofstream output; open_file_write(output, file_name_reporte);


    //Imprime Headers
    output << setprecision(2) << fixed;
    output << setw(90) << "EMPRESA DE REPARTOS A DOMICILIO TP S.A." << endl;
    output << setw(80) << "CLIENTES POR ATENDER" << endl;

    totalRecaudado = totalRepartidores = 0;

    while (true) {
        input_clientes >> dni;
        if (input_clientes.eof()) break;
        valDescCli = 0;
        imprimirLinea(output, '=', TAM_LINEA);
        output << "CLIENTE: " << dni << " - ";
        leerImprimirNombre(input_clientes, output, ']', TAM_CLIENTE);
        input_clientes >> dist;
        output << "DISTRITO: ";
        leerImprimirNombre(input_clientes, output, ' ', TAM_DISTRITO);
        input_clientes >> vehic >> desc;
        if (desc == 'S')
            input_clientes >> valDescCli >> car;
        if (vehic == 'M')
            output << "TIPO DE VEHICULO: Motocicleta ";
        else
            output << "TIPO DE VEHICULO: Bicicleta   ";
        output << setw(5) << ' ' << "DESCUENTO:"<<setw(8)<<valDescCli<<'%'<<endl;
        imprimirLinea(output, '-', TAM_LINEA);


        procesarRepartos(dni, valDescCli, vehic, input_repartos, input_platos,
                         input_repartidores,
                         output, montoCliente, pagoRepartidor);
        imprimirLinea(output, '-', TAM_LINEA);
        output << "MONTO TOTAL PAGADO POR EL CLIENTE:"<<setw(12)<<montoCliente<< endl;

        procesarRepartidor(dist, vehic, input_repartidores, output, pagoRepartidor);
        totalRecaudado += montoCliente;
        totalRepartidores += pagoRepartidor;
    }
    imprimirLinea(output, '=', TAM_LINEA);
    output << "TOTAL RECAUDADO POR LOS PEDIDOSSOLICITADOS:"<<setw(12)<<totalRecaudado << endl;
    output << "TOTAL A PAGAR A LOS REPARTIDORES:"<<setw(12)<<totalRepartidores << endl;
    imprimirLinea(output, '=', TAM_LINEA);
}