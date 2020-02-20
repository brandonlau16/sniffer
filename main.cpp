#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>


using namespace std;
void menu(string cadena, char* archivo);
void convertir_cadena();
string leer_campo(char* cadena, int tam);
string convertir_a_binario(char hexa);
int posicion = 0;
int  main(){
    int i = 0, len = 66;
    char outword[100],dOrigen[13],dDestino[13],tipo[5],cadena[65];
    bool cadena_binaria[206];
    ifstream archivo("ethernet_ipv4_icmp.bin", fstream::binary);

    while(!archivo.eof()){
        archivo.read((char*)&cadena[i],sizeof(char));
        i++;
    }
    archivo.close();
    i = 0;
    cadena[65] = '\0';

    if(cadena[len-1]=='\n')
        cadena[--len] = '\0';

    for(i = 0; i<len; i++){
        sprintf(outword+i*2, "%02X", cadena[i]);
    }
    for(i=0;i<12;i++){
        dOrigen[i]=outword[i];
    }
    for(int j=0;j<12;i++,j++){
        dDestino[j]=outword[i];
    }
    for(int k = 0;k < 4;i++,k++){
        tipo[k]=outword[i];
    }
    dOrigen[12] = '\0';
    dDestino[12] = '\0';
    tipo[4] = '\0';

    cout<<"Direccion Origen: "<<dOrigen<<endl;
    cout<<"Direccion Destino: "<<dDestino<<endl;
    cout<<"Tipo: ";
    menu(tipo,outword);
    cout<<endl;
    return 0;
}
string leer_campo(char* cadena, int tam){
    int i = posicion;
    string campo ="";
    int j = 0;
    char aux[4];
    for(;i<posicion+tam;i++,j++){
        campo += convertir_a_binario(cadena[i]);
    }
    return campo;
}
void menu(string cadena, char* archivo){
    if(cadena == "0800"){
    	cout << "hola"<< endl;
        posicion = 28;
        cout << "IPv4"<<endl;
        string tipo = leer_campo(archivo,1);
        posicion++;
        string tam = leer_campo(archivo,1);
        cout<<"Tipo "<<stoi(tipo,0,2)<<endl;
        cout<<"Tam "<<stoi(tam,0,2)<<endl;
    }
    else if(cadena == "0806"){
        cout << "ARP";
    }
    else if(cadena == "8035"){
        cout << "RARP";
    }
    else if(cadena == "86DD"){
        cout << "IPv6";
    }
}
string convertir_a_binario(char hexa){
    string campo;
    if (hexa == '0'){
        campo = "0000";
    }
    else if (hexa == '1'){
        campo = "0001";
    }
    else if (hexa == '2') {
        campo = "0010";
    }
    else if (hexa == '3') {
        campo = "0011";
    }
    else if (hexa == '4') {
        campo = "0100";
    }
    else if (hexa == '5') {
        campo = "0101";
    }
    else if (hexa == '6') {
        campo = "0110";
    }
    else if (hexa == '7') {
        campo = "0111";
    }
    else if (hexa == 'A') {
        campo = "1010";
    }else if (hexa == 'B') {
        campo = "1011";
    }else if (hexa == 'C') {
        campo = "1100";
    }else if (hexa == 'D') {
        campo = "1101";
    }else if (hexa == 'E') {
        campo = "1110";
    }else if (hexa == 'F') {
        campo = "1111";
    }
    return campo;
}
