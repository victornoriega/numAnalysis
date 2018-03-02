/*Name: VANO-.cpp
Author: Victor Ariel Noriega Ortiz
Description:
Date:
*/

#include <cstdlib>
#include <iostream>
#include <limits>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>
#include "fparser.hh"
#include <windows.h>



#define MAX 100

int CapturaEntradaEntero();

void MuroTextoParser();


void GestionaPolinomioNewton(char &opc);


void GestionaJacobi(char &opc);

void GestionaGaussSeidel(char &opc);

float **CrearArreglo(int ren, int col);

void GestionaJacobi(const char &opc);



void LiberaArreglo(float **&A);

long double  Redondea(long double numero, int cifras);

void GestionaGaussPivoteo(char &opc);

void GestionaGauss(char &opc);

float** ProductoMatriz(float **A, float **B, int ren, int col2,int ren2);


void GestionaRegresion(char &);

bool MenuPrincipal(char&);
void MenuLineal(char &opc);
void MenuNoLineal(char &opc);
void MenuAjustes(char &opc);
void MenuIntegracion(char &opc);
void GestionaBiseccion(char &opc);
void GestionaReglaFalsa(char &opc);

void GestionaPuntoFijo(char &opc);

void GestionaNewton(char &opc);

void GestionaSecante(char &opc);

void GestionaTrapecios(char &);

void GestionaSimpson(char &);

void GestionaGaussJordan(char &opc);



#define MAX_COL 10
#define MAX_REN 10
void ImprimeMatriz(double A[][MAX_COL], int ren, int col);



double CapturaEntradaReal();




enum MENU_PRINC{SALIR=48,NO_LIN,LIN,AJUSTES,INTEGRACION};

using namespace std;

int main()
{
    char opc;
    bool salir=MenuPrincipal(opc);
    if(!salir){
        system("cls");
        cout << "TANTO ESFUERZO PARA NADA." <<endl;
        system("pause");
        return 0;
    }
}

/*******************************************************************************************************************************************************/
bool MenuPrincipal(char &opcion)
{
    system("cls");
    opcion='\0';
    cout << "\t\t\tMen\xA3 principal." << endl<<endl<<endl;

    cout << "An\xA0lisis num\x82rico." << endl<<endl;

    cout << "0) Salir." << endl;
    cout << "1) Soluci\xA3n de sistemas no lineales." << endl;
    cout << "2) Soluci\xA3n de sistemas lineales." << endl;
    cout << "3) Ajustes de curvas." << endl;
    cout << "4) Integraci\xA3n num\x82rica." << endl;
    while(opcion!='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4'){
        opcion=getch();
    }

    char opcMenus;
    switch(opcion){
        case SALIR:
            return false;
        case NO_LIN:
            MenuNoLineal(opcMenus);
            break;
        case LIN:
            MenuLineal(opcMenus);
            break;
        case AJUSTES:
            MenuAjustes(opcMenus);
            break;
        case INTEGRACION:
            MenuIntegracion(opcMenus);
            break;
    }
    return true;
}

/*******************************************************************************************************************************************************/

int CapturaEntradaEntero()
{

	int n;
    do{
        cin >> n;

        if(cin.bad()){
            cout << "Error irrecuperable." << endl;
            exit(1);
        }
        if(cin.fail()){
            cout << "Error. No es un n\xA3mero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            cout << "Introduzca de nuevo: ";
            continue;
        }

        return n;
    }while(true);
}

/********************************************************************************************************************************************************/

double CapturaEntradaReal()
{
    double n;
    do{
        cin >> n;

        if(cin.bad()){
            cout << "Error irrecuperable." << endl;
            exit(1);
        }
        if(cin.fail()){
            cout << "Error. No es un n\xA3mero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            cout << "Introduzca de nuevo: ";
            continue;
        }

        return n;
    }while(true);
}

/*******************************************************************************************************************************************************/

void MenuLineal(char &opcion)
{
    system("cls");
    cout << "Men\xA3 sistemas lineales." << endl<<endl<<endl;
    cout << "0) Regresar al men\xA3 principal." << endl;
    cout << "1) Eliminaci\xA2n gaussiana simple." << endl;
    cout << "2) Eliminaci\xA2n gaussiana con pivoteo parcial." << endl;
    cout << "3) Gauss-Jordan." << endl;
    cout << "4) Jacobi." << endl;
    cout << "5) Gauss-Seidel." << endl;
    cout << "6) Factorizaci\xA2n LU." <<endl;
    while(opcion!='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5'){
        opcion=getch();
    }

    enum OPCIONES{REGRESAR=48,GAUSS,GAUSS_PIV,GAUSS_JORDAN,JACOBI,SEIDEL,LU};

    switch(opcion){
        case REGRESAR:
            MenuPrincipal(opcion);
            break;
        case GAUSS:
            GestionaGauss(opcion);
            break;
        case GAUSS_PIV:
            GestionaGaussPivoteo(opcion);
            break;
        case GAUSS_JORDAN:
            GestionaGaussJordan(opcion);
            break;
        case JACOBI:
            GestionaJacobi(opcion);
            break;
        case SEIDEL:
            GestionaGaussSeidel(opcion);
            break;

    }
}

/*******************************************************************************************************************************************************/

void MenuNoLineal(char &opcion)
{
    system("cls");
    cout << "Men\xA3 sistemas no lineales." << endl << endl << endl;
    cout<< "0) Regresar al men\xA3 principal" << endl;
    cout << "1) Bisecci\xA2n." << endl;
    cout << "2) Regla falsa." << endl;
    cout << "3) Punto fijo." << endl;
    cout << "4) Newton-Raphson." << endl;
    cout << "5) Secante." << endl;
    while(opcion!='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5'){
        opcion=getch();
    }

    enum OPCIONES{REGRESAR=48,BISECCION,REGLA,PUNTO,NEWTON,SECANTE};

    switch(opcion){
        case REGRESAR:
            MenuPrincipal(opcion);
            break;
        case BISECCION:
            GestionaBiseccion(opcion);
            break;
        case REGLA:
            GestionaReglaFalsa(opcion);
            break;
        case PUNTO:
            GestionaPuntoFijo(opcion);
            break;
        case NEWTON:
            GestionaNewton(opcion);
            break;
        case SECANTE:
            GestionaSecante(opcion);
            break;
    }

}

/*******************************************************************************************************************************************************/

void MenuAjustes(char &opcion)
{
    system("cls");
    cout << "Men\xA3 sistemas no lineales." << endl << endl << endl;
    cout<< "0) Regresar al men\xA3 principal" << endl;
    cout << "1) Interpolaci\xA2n con diferencias divididas de Newton." << endl;
    cout << "2) Interpolaci\xA2n con Lagrange." << endl;
    cout << "3) Regresi\xA2n polinomial."<< endl;
    while(opcion!='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4'){
        opcion=getch();
    }

    enum OPCIONES{REGRESAR=48,NEWTON,LAGRANGE,POLINOMIAL};

    switch(opcion){
        case REGRESAR:
            MenuPrincipal(opcion);
            break;
        case NEWTON:
            GestionaPolinomioNewton(opcion);
            break;
        case LAGRANGE:
            break;
        case POLINOMIAL:
            GestionaRegresion(opcion);
            break;
    }
}

/*******************************************************************************************************************************************************/

void MenuIntegracion(char &opcion)
{
    system("cls");
    cout << "Men\xA3 integraci\xA2n num\x82rico."<<endl;
    cout << "0) Regresar al men\xA3 principal." << endl;
    cout << "1) Trapecios." << endl;
    cout << "2) Reglas de Simpson." << endl;
    while(opcion!='0' && opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4'){
        opcion=getch();
    }

    enum OPCIONES{REGRESAR=48,TRAPECIOS,SIMPSON};

    switch(opcion){
        case REGRESAR:
            MenuPrincipal(opcion);
            break;
        case TRAPECIOS:
            GestionaTrapecios(opcion);
            break;
        case SIMPSON:
            GestionaSimpson(opcion);
            break;
    }
}

/*********************************************************************************************************************************************************/

void GestionaBiseccion(char &opc)
{
    string fDeX;

    FunctionParser fparser;
    system("cls");
    cout << "Bisecci\xA2n. Resuelve sistema de ecuaciones no lineales." << endl;

    MuroTextoParser();

    cout<<"Funci\xA2n:"<<endl;

    while(true){
        cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        cout << string(res+7, ' ') << "^\n" << fparser.ErrorMsg() << "\n\n";
    }

    double a,b;
    cout << "Intervalo:"<<endl;
    cout << "a: ";
    a=CapturaEntradaReal();
    cout << "b: ";
    b=CapturaEntradaReal();


    double fa,fpm, pm,fb;
    double *ptr_b=&b;

    double *ptr_a=&a;


    fb=fparser.Eval(ptr_b);

    fa=fparser.Eval(ptr_a);
    while(fa*fb>0){
        cout << "Elija otro intervalo. Es posible que no haya ra\xA1z o haya m\xA0s de una." << endl;
        cout << "Intervalo:"<<endl;
        cout << "a: ";
        a=CapturaEntradaReal();
        cout << "b: ";
        b=CapturaEntradaReal();
        fb=fparser.Eval(ptr_b);

        fa=fparser.Eval(ptr_a);
    }

    char tol;
    double tolerancia;
    int cifras;
    cout << "Calcular error por tolerancia (T) o mediante cifras significativas(C): ";
    while(tol!='t' && tol!='T' && tol!='c' && tol!='C'){
        tol=getch();
    }
    cout << endl;
    if(tol=='t' || tol=='T'){
        cout << "Tolerancia: ";
        tolerancia=CapturaEntradaReal();
        while(tolerancia<=0){
            cout <<"Tolerancia fuera de rango. Ingresa nuevamente." << endl;
            cout << "Tolerancia: ";
            tolerancia=CapturaEntradaReal();
        }
    }

    if(tol=='c' || tol=='c'){
        cout <<" Cifras significativas: ";
        cifras=CapturaEntradaEntero();
        while(cifras<=1){
            cout << "Se recomienda otro n\xA3mero de cifras." << endl;
            cout << "Cifras: ";
            cifras=CapturaEntradaEntero();
        }
    }
    system("cls");

    cout << char(179) << left << setw(3) <<"n"<<setw(15) <<"an"<<setw(15)<<"bn"<<setw(15)<<"f(a)"<<setw(15)<<"f(pn)"<<setw(15)<<"Error"<<char(179)<<endl;


    pm=(a+b)/2;
    double *ptr_pm=&pm;
    fpm=fparser.Eval(ptr_pm);

    cout << char(179) << left << setw(3)<<"1"<<setw(15) <<a << setw(15) << b << setw(15) <<fa<<setw(15) << fpm <<setw(15)<<"-------"<<char(179)<<endl;

    double error=2;
    int cont=2;
    while((tol=='t' || tol=='T') ? error> tolerancia : error > 5*(pow(10,-cifras)) ){
        fa*fpm<0 ? b=pm : a=pm;
        error=abs(((a+b)/2-pm)/((a+b)/2));
        pm=(a+b)/2;
        fa=fparser.Eval(ptr_a);
        fpm=fparser.Eval(ptr_pm);
        cout << char(179) << left << setw(3)<<cont <<setw(15) <<a << setw(15) << b << setw(15) <<fa<<setw(15) << fpm <<setw(15)<<error<<char(179)<<endl;
        cont++;
    }

    if(tol=='c' || tol=='C') cout << "Se encontr\xA2 una ra\xA1z aproximada en "<<setprecision(cifras)<<pm<<endl;

    system("pause");
    MenuNoLineal(opc);

}

/*********************************************************************************************************************************************************/

void GestionaReglaFalsa(char &opc)
{
    system("cls");
    cout << "Sistemas no lineales con regla falsa." << endl;

    MuroTextoParser();


    string fDeX,gDeX;

    FunctionParser fparser;

    while(true){
        cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        cout << string(res+7, ' ') << "^\n" << fparser.ErrorMsg() << "\n\n";
    }

    double a,b;
    cout << "Intervalo:"<<endl;
    cout << "a: ";
    a=CapturaEntradaReal();
    cout << "b: ";
    b=CapturaEntradaReal();

    double tolerancia;

    cout << "Tolerancia: ";
    tolerancia=CapturaEntradaReal();
    while(tolerancia<=0){
        cout <<"Tolerancia fuera de rango. Ingresa nuevamente." << endl;
        cout << "Tolerancia: ";
        tolerancia=CapturaEntradaReal();
    }

    system("cls");

    cout <<char(179)<< left << setw(3) << "n" << setw(10) << "an" << setw(10) << "bn" << setw(10) << "cn" << setw(10) << "f(a)"<< setw(11) <<"f(c)"<< setw(11) << "Error" <<char(179) << endl;



    double *ptr_a=&a;
    double *ptr_b=&b;

    double fa=fparser.Eval(ptr_a);
    double fb=fparser.Eval(ptr_b);

    double c=a-((fa)*(b-a))/(fb-fa);
    double *ptr_c=&c;
    double fc=fparser.Eval(ptr_c);

    cout << char(179) << left << setw(3) << "1" << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << fa << setw(10) << fc << setw(11) << "-----" << char(179) << endl;

    double error=2;
    int cont=2;
    while(error > tolerancia){

        fa*fc<0 ? b=c : a=c;
        error=abs(((a-((fa)*(b-a))/(fb-fa))-c)/(a-((fa)*(b-a))/(fb-fa)));
        c=a-((fa)*(b-a))/(fb-fa);
        fa=fparser.Eval(ptr_a);
        fc=fparser.Eval(ptr_c);
        fb=fparser.Eval(ptr_b);
        cout << char(179) << left << setw(3) << cont << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << fa << setw(10) << fc << setw(11) << error << char(179) << endl;
        cont++;
    }

    cout << "Se encontr\xA2 una ra\xA1z aproximada en "<<c<<endl;

    system("pause");
    MenuNoLineal(opc);

}

/*******************************************************************************************************************************************************/

void GestionaPuntoFijo(char &opc)
{
    system("cls");
    cout << "Sistemas no lineales. M\xA2todo de punto fijo." << endl;
    cout << "Se solicitan 2 funciones (f y g) para encontrar la ra\xA1z de f." << endl;

    string fDeX,gDeX;
    MuroTextoParser();

    FunctionParser fparser;

    while(true)
    {
		std::cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparser.ErrorMsg() << "\n\n";
    }
    while(true)
    {
        cout << "g(x) = ";
        getline(cin, gDeX);
        if(cin.fail()) return ;

        int res = fparser.Parse(gDeX, "x");
        if(res < 0) break;

        cout << string(res+7, ' ') << "^\n"
                  << fparser.ErrorMsg() << "\n\n";
    }

    cout << "Intervalo: "<<endl;
    double a,b;
    cout << "a: ";
    a=CapturaEntradaReal();
    cout << "b: ";
    b=CapturaEntradaReal();


    while(a>=b){
        cout << "En el intervalo, a no debe ser mayor o igual a b." << endl;
        cout << "a: ";
        a=CapturaEntradaReal();
        cout << "b: ";
        b=CapturaEntradaReal();
    }

    int k;
    cout << "Iteraciones: ";
    k=CapturaEntradaEntero();
    while(k<1){
        cout << "Fuera de rango. Ingresa nuevamente." << endl;
        cout << "Iteraciones: ";
        k=CapturaEntradaEntero();
    }


    double tol;
    cout << "Tolerancia: ";
    tol=CapturaEntradaReal();
    while(tol<0 || tol>1){
        cout << "Se recomienda usar otra tolerancia. Ingresa nuevamente" << endl;
        cout << "Tolerancia." << endl;
        tol=CapturaEntradaReal();
    }

    double p;

    cout << char(179) << left <<setw(3) <<  "n" << setw(12) << "p" << setw(12) << "f(pn)" << setw(12) << "Error" <<char(179) << endl;

    double *ptr_p=&p;


    p=(b-a)/2;

    double fp=fparser.Eval(ptr_p);
    double *ptr_fp=&fp;

    cout << char(179) << left << setw(3) << "1" << setw(12) << p << setw(12) << fp << setw(12) << "--------" << char(179) << endl;

    double error=2;
    bool funciono=true;
    for(int i=2; i < k+1 && error>tol ; i++){
        p=fparser.Eval(ptr_fp);
        error=abs((fparser.Eval(ptr_fp)-fp)/fparser.Eval(ptr_fp));
        fp=fparser.Eval(ptr_fp);
        cout << char(179) << left << setw(3) <<  i << setw(12) << p << setw(12) << fp << setw(12) << error<< char(179) << endl;
        if(i>=k+1){
            funciono=false;
        }
    }

    if(funciono) cout << "Se encontr\xA2 una ra\xA1z en " << p << " aproximadamente." << endl;
    else cout << "No se encontr\xA2 ra\xA1z. Pruebe otro intervalo u otra funci\xA2n g." << endl;


    system("pause");
    MenuNoLineal(opc);

}
/********************************************************************************************************************************/

void GestionaNewton(char &opc)
{
    system("cls");
    cout << "Sistemas no lineales. M\x82todo Newton-Raphson." << endl;

    MuroTextoParser();

    string fDeX,gDeX;

    FunctionParser fparser;
    FunctionParser gparser;

    cout << "Funci\xA2n: ";

    while(true)
    {
		std::cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparser.ErrorMsg() << "\n\n";
    }
    cout << "Derivada: "<< endl;
    while(true)
    {
		std::cout << "f'(x) = ";
        std::getline(std::cin, gDeX);
        if(std::cin.fail()) return ;

        int res = gparser.Parse(gDeX, "x");
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << gparser.ErrorMsg() << "\n\n";
    }

    double a;
    cout << "Valor inicial: ";
    a=CapturaEntradaReal();

    double tol;
    cout << "Tolerancia: ";
    tol=CapturaEntradaReal();


    cout << "Iteraciones: ";
    int k=CapturaEntradaEntero();
    while(k<1){
        cout << "Fuera de rango." << endl;
        cout << "Iteraciones: ";
        k=CapturaEntradaEntero();
    }

    cout << char(179) << left << setw(3) << "n" << setw(12) << "xn" << setw(12) << "f(x)" << setw(12) << "f'(x)" << setw(12) << "Error" << char(179) <<  endl;

    double *ptr_a=&a;
    double fa=fparser.Eval(ptr_a);

    double dfa=gparser.Eval(ptr_a);

    cout << char(179) << left << setw(3) << 0 << setw(12) << a << setw(12) << fa << setw(12) << dfa << char(179) << setw(10) << "-----" <<  endl;
    double error=1;
    int cont=1;
    while(error>tol && cont <=k){
        error=abs(((a-(fa/dfa))-a)/((a-(fa/dfa))));
        a=a-(fa/dfa);
        fa=fparser.Eval(ptr_a);
        dfa=gparser.Eval(ptr_a);

        cout << char(179) << left << setw(3) << cont << setw(12) << a << setw(12) << fa << setw(12) << dfa << char(179) << setw(12) << error <<  endl;


        cont++;
    }

    cout << "Se encontr\xA2 una soluci\xA2n aproximada en " << a <<endl;

    system("pause");
    MenuNoLineal(opc);

}

/*******************************************************************************************************************************************************/

void GestionaSecante(char &opc)
{

    system("cls");
    cout << "Sistemas no lineales. M\x82todo de la secante." << endl;

    cout << "Se solicitar\xA0 una funci\xA2n y dos valores para calcular la ra\xA1z." << endl;

    string fDeX;

    FunctionParser fparser;

    cout << "Funci\xA2n: ";

    while(true)
    {
		std::cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparser.ErrorMsg() << "\n\n";
    }

    cout << "Primer valor inicial: ";
    double a=CapturaEntradaReal();
    cout << "Segundo valor inicial: ";
    double b=CapturaEntradaReal();

    cout << "Iteraciones: ";
    int k=CapturaEntradaEntero();
    while(k<1){
        cout << "Fuera de rango. Ingrese nuevamente." << endl;
        cout << "Iteraciones: ";
        k=CapturaEntradaEntero();
    }

    cout << "Tolerancia: ";
    double tol;
    tol=CapturaEntradaEntero();

    tol=0.00005;
    while(tol<0 || tol>1){
        cout << "Se recomienda ingresar una tolerancia distinta." << endl;
        cout << "Tolerancia: ";
        tol=CapturaEntradaEntero();
    }

    cout << char(179) << left << setw(3) << "n" << setw(12) << "xn" << setw(12) << "f(x)" << setw(12) << "Error" << char(179) <<  endl;

    double p;

    double *ptr_a=&a;
    double *ptr_b=&b;
    double *ptr_p=&p;

    double fa=fparser.Eval(ptr_a);
    double fb=fparser.Eval(ptr_b);
    double error=abs((fb-fa)/fb);

    double fp;

    cout << char(179) << left << setw(3) << "0" << setw(18) << a << setw(18) << fa << setw(18) << "------" << char(179) <<  endl;

    cout << char(179) << left << setw(3) << "1" << setw(18) << b << setw(18) << fb << setw(18) << error << char(179) <<  endl;


    int cont=2;

    while(cont <= k && error>tol){

        p=b-(((b-a)*(fb))/(fb-fa));


        error=abs((p-b)/p);

        a=b;
        b=p;

        fp=fparser.Eval(ptr_p);
        fa=fparser.Eval(ptr_a);
        fb=fparser.Eval(ptr_b);

        cout << char(179) << left << setw(3) << cont << setw(18) << p << setw(18) << fp << setw(18) << error << char(179) <<  endl;
        cont++;
    }

    cout << "Se encontr\xA2 una aproximaci\xA2n a la ra\xA1z en "<< p << endl;
    system("pause");
    MenuNoLineal(opc);
}

/***************************************************************************************************************************************************/

void GestionaGauss(char &opc)
{
    int orden, col,p,cifras;
	double  Matriz[MAX_REN][MAX_COL] ,sol[MAX_COL], tol;
	ifstream lectura;

	system("cls");

	char nombreArchivo[90];

	cout<<"Programa que implementa el algoritmo de Eliminaci\xA2n Gaussiana Simple con\nsustituci\xA2n"<<
		" hacia atr\xA0s para resolver matrices aumentadas."<<endl;

	cout << "Formato para matriz aumentada: "<<endl<<endl;

    cout << "n       			Primera linea para el orden de la matriz" << endl;
    cout << "a11x1 a12x2 a13x3 b1" << endl;
    cout << "a21x1 a22x2 a23x3 b2 " << endl;
    cout << "a31x1 a32x2 a33x3 b3" << endl;
    cout << "a41x1 a42x2 a43x3 b4" << endl << endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);

    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }

	cout<<"Cifras significativas: ";
	cifras=CapturaEntradaReal();
	while(cifras<1){
		cout<<"Deben ser al menos un cifras significativas."<<endl;
		cout<<"Cifras: ";
		cifras=CapturaEntradaReal();
	}

	cout<<"Tolerancia para el error: ";
	tol=CapturaEntradaReal();
	while(tol<0){
		cout<<"La tolerancia debe ser un valor no negativo. Ingresa nuevamente."<<endl;
		cout<<"Tolerancia: ";
		tol=CapturaEntradaReal();
	}

	//lee el archivo, almacenando cada entrada de la matriz en el arreglo bid, y aplicando redondeo
	lectura>>orden;
	col=orden+1;
	for(int i=0;i<orden;i++){
		for(int j=0;j<col;j++){
			lectura>>Matriz[i][j];
			Matriz[i][j]=Redondea(Matriz[i][j],cifras);
		}
	}

	bool Funciona=false;
	float aux;
	float mij;
	for(int i=0; i < orden-1; i++){
		p=i;
		for(int j=p; j < orden; j++){
			if(Matriz[j][i]!=0){
				Funciona=true;
				break;
				p=j;
			}
		}

		ImprimeMatriz(Matriz,orden,col);
		Sleep(1000);
		cout << endl << endl << endl;

		if(!Funciona){
			cout << "No se puede encontrar soluci\xA2n a este sistema. "<< endl;
			system("pause");
			return ;
		}

		if(p!=i){
			for(int k=0 ; k < orden + 1 ; k++){
				aux=Matriz[p][k];
				Matriz[p][k]=Matriz[i][k];
				Matriz[i][k]=aux;
			}
		}

		for(int j=i+1; j < orden  ; j++){
			mij=Matriz[j][i]/Matriz[i][i];
			for(int k=0; k < orden+1; k++){
				Matriz[j][k]-=mij*Matriz[i][k];
			}
		}

		ImprimeMatriz(Matriz,orden,col);
		Sleep(1000);
		cout << endl << endl;

	}

    sol[orden-1]=Redondea(Matriz[orden-1][col-1]/Matriz[orden-1][col-2],cifras);

	//calcula cada una de las soluciones

	float suma=0;
	for(int i=orden-2;i>=0;--i){
       suma=0;
       for(int j=i+1;j<col-1;++j) {
            suma += Redondea(Matriz[i][j]*sol[j],cifras);
       }
       sol[i]=Redondea((Matriz[i][orden]-suma)/Matriz[i][i],cifras);
    }

	cout<< endl << endl << endl;
	lectura.close();

	for(int i=0;i<col-1;i++) cout<<"x"<<i+1<<"="<<Redondea(sol[i],cifras)<<endl;

    cout << endl<< endl;
    system("pause");
    MenuPrincipal(opc);

}

/*******************************************************************************************************************************************************/

long double  Redondea(long double numero, int cifras)
{
	int exponente=0,signo=1;

	if (numero==0) return 0;

	if(numero<0){
		signo=-1;
		numero=-numero;
	}

	while(numero>1){
		numero/=10;
		exponente+=1;
	}
	numero*=pow(10,cifras);
	numero=round(numero);
	numero*=pow(10,exponente-cifras);


	if(numero<=1 && numero>0){
		numero*=pow(10,cifras);
		numero=round(numero);
		numero*=pow(10,exponente-cifras);
	}

	return numero*signo;

}

/*******************************************************************************************************************************************************/


void ImprimeMatriz(double A[][MAX_COL], int ren, int col)
{
	for(int i=0; i < ren; i++){
		cout <<char(179);
		for(int j=0; j < col; j++){
			cout <<setw(13) << A[i][j];
		}
		cout << char(179) << endl;
	}
}
/*******************************************************************************************************************************************************/

void GestionaGaussPivoteo(char &opc)
{
    int orden, col,p,cifras;
	double  Matriz[MAX_REN][MAX_COL] ,sol[MAX_COL], tol;
	ifstream lectura;

	char nombreArchivo[90];

	system("cls");

	cout<<"Programa que implementa el algoritmo de Eliminaci\xA2n Gaussiana Simple con\nsustituci\xA2n"<<
		" hacia atr\xA0s para resolver matrices aumentadas."<<endl;

	cout << "Formato para matriz aumentada: "<<endl<<endl;

    cout << "n       			Primera linea para el orden de la matriz" << endl;
    cout << "a11x1 a12x2 a13x3 b1" << endl;
    cout << "a21x1 a22x2 a23x3 b2 " << endl;
    cout << "a31x1 a32x2 a33x3 b3" << endl;
    cout << "a41x1 a42x2 a43x3 b4" << endl << endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);

    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }

	cout<<"Cifras significativas: ";
	cifras=CapturaEntradaReal();
	while(cifras<1){
		cout<<"Deben ser al menos un cifras significativas."<<endl;
		cout<<"Cifras: ";
		cifras=CapturaEntradaReal();
	}

	cout<<"Tolerancia para el error: ";
	tol=CapturaEntradaReal();
	while(tol<0){
		cout<<"La tolerancia debe ser un valor no negativo. Ingresa nuevamente."<<endl;
		cout<<"Tolerancia: ";
		tol=CapturaEntradaReal();
	}

	//lee el archivo, almacenando cada entrada de la matriz en el arreglo bid, y aplicando redondeo
	lectura>>orden;
	col=orden+1;
	for(int i=0;i<orden;i++){
		for(int j=0;j<col;j++){
			lectura>>Matriz[i][j];
			Matriz[i][j]=Redondea(Matriz[i][j],cifras);
		}
	}



	double aux;
	int signoDet=1;
	col=orden+1;

    double mayor;
    int renMayor;


	bool Funciona=false;
	float mij;

	ImprimeMatriz(Matriz,orden,col);
	cout << endl << endl;
	Sleep(1000);

	for(int i=0; i < orden-1; i++){
		p=i;
		for(int j=p; j < orden; j++){
			if(Matriz[j][i]!=0){
				Funciona=true;
				break;
				p=j;
			}
		}

		mayor=Matriz[i][i];
        for( int j=i ; j < orden-1 ; j++){
            if(Matriz[j+1][i]> mayor){
                renMayor=j+1;
            }
        }

        if(renMayor!=i){
            for(int j=0; j < orden+1; j++){
                aux=Matriz[i][j];
                Matriz[i][j]=Matriz[renMayor][j];
                Matriz[renMayor][j]=aux;
            }
        }

		ImprimeMatriz(Matriz,orden,col);
		Sleep(1000);
		cout << endl << endl << endl;

		if(!Funciona){
			cout << "No se puede encontrar soluci\xA2n a este sistema. "<< endl;
			system("pause");
			return ;
		}

		if(p!=i){
			for(int k=0 ; k < orden + 1 ; k++){
				aux=Matriz[p][k];
				Matriz[p][k]=Matriz[i][k];
				Matriz[i][k]=aux;
			}
		}

		for(int j=i+1; j < orden  ; j++){
			mij=Matriz[j][i]/Matriz[i][i];
			for(int k=0; k < orden+1; k++){
				Matriz[j][k]-=mij*Matriz[i][k];
			}
		}

		ImprimeMatriz(Matriz,orden,col);
		Sleep(1000);
		cout << endl << endl;

	}

    double det=1;
    for(int i=0;i<orden;i++){
		det*=Matriz[i][i];
	}

	//aqui calculo el signo del determinante, con el que despues aplicare valor absoluto. Y nada mas
	det*=pow(-1,signoDet);
	cout<<"El determinante es "<<det<<endl;

	char opcion;
	if(tol>abs(det)) cout<<"La matriz est\xA0 bien condicionada. Estas son las soluciones:"<<endl;
	else{
		cout<<"La matriz, desafortunadamente, est\xA0 mal condicionada."<<endl;
		do{
			cout<<"Quieres resolverla a\xA3n as\xA1? (s/n): ";
			cin>>opcion;
			if(opcion=='n'|| opcion=='N'){
				cout<<"Gracias por usar el programa."<<endl;
				system("pause");
				return ;
			}
			if(opcion=='s'|| opcion=='S') break;
		}while(true);
	}
    sol[orden-1]=Redondea(Matriz[orden-1][col-1]/Matriz[orden-1][col-2],cifras);

	//calcula cada una de las soluciones

	float suma=0;
	for(int i=orden-2;i>=0;--i){
       suma=0;
       for(int j=i+1;j<col-1;++j) {
            suma += Redondea(Matriz[i][j]*sol[j],cifras);
       }
       sol[i]=Redondea((Matriz[i][orden]-suma)/Matriz[i][i],cifras);
    }

	cout<< endl << endl << endl;
	lectura.close();

	for(int i=0;i<col-1;i++) cout<<"x"<<i+1<<"="<<Redondea(sol[i],cifras)<<endl;
    system("pause");
    MenuPrincipal(opc);

}

/*******************************************************************************************************************************************************/

void GestionaTrapecios(char &opc)
{

    string fDeX,gDeX;

    FunctionParser fparser;
    system("cls");
    cout<<"Programa que integra num\x82ricamente una funci\xA2n f en un intervalo [a,b]."<<endl;
	cout<<"Este programa utiliza la regla trapezoidal, por lo que se le pedir\xA0\n"
		"un n\xA3mero de particiones."<<endl;
	char opcion='0';
	cout<<"\xA8Se conoce la funci\xA2n?(S/N): ";
	opcion=getch();
	cout<<"\n";

	while(opcion!='S' && opcion!='s' && opcion!='N' && opcion!='n'){
		cout<<"Ingrese nuevamente."<<endl;
		cout<<"\xA8Se conoce la funci\xA2n?(S/N): ";
		opcion=getch();
		cout<<"\n";
	}

	if(opcion=='S' || opcion=='s'){
		system("cls");
		MuroTextoParser();
		cout<<"Funci\xA2n: ";

		while(true){
        cout << "f(x) = ";
        std::getline(std::cin, fDeX);
        if(std::cin.fail()) return ;

        int res = fparser.Parse(fDeX, "x");
        if(res < 0) break;

        cout << string(res+7, ' ') << "^\n" << fparser.ErrorMsg() << "\n\n";
        }

		int part;

		cout<<"Particiones: ";
		part=CapturaEntradaEntero();
		while(part<1){
			cout<<"Ingrese un valor v\xA0lido."<<endl;
			cout<< "Particiones: ";
			part=CapturaEntradaEntero();
		}

		float a,b;
		cout<<"Intervalo de integraci\xA2n [a,b]"<<endl;
		cout<<"a: ";
		a=CapturaEntradaReal();
		cout<<"b: ";
		b=CapturaEntradaReal();

		while(a>=b){
			system("cls");
			cout<<"Error. 'b' es el fin del intervalo de integraci\xA2n."<<endl;
			cout<<"Intervalo de integraci\xA2n [a,b]"<<endl;
			cout<<"a: ";
			a=CapturaEntradaReal();
			cout<<"b: ";
			b=CapturaEntradaReal();
		}


        double puntosX[part+1];

        float h=(b-a)/part;

        for(int i=0;i < part+1; i++){
            puntosX[i]=a+i*h;
        }

        float eval[part+1];
        for(int i=0; i < part+1 ; i++){
            eval[i]=fparser.Eval(puntosX+i);
        }

        float sumas=0;
        for(int i=1;i<part;i++) sumas+=2*eval[i];
		sumas+=eval[0];
		sumas+=eval[part];


		float area=((puntosX[part]-puntosX[0]))*(sumas)/(2*part);

		cout<<"La integral de esta funci\xA2n es "<<area<<endl;
	}
	else{
		fstream lectura;
		char nombreArchivo[MAX];
		system("cls");
		cout << "Los puntos se capturar\xA0n por archivo de la siguiente manera:"<<endl;
		cout<<"m"<<endl;
		cout<<"x1 y1"<<endl;
		cout<<"x2 y2"<<endl;
		cout<<"x3 y3"<<endl;
		cout<<"  ."<<endl;
		cout<<"  ."<<endl;
		cout<<"  ."<<endl;
		cout<<"xn yn"<<endl;

		cout<<"Siendo m el n\xA3mero de puntos. Los puntos deben aparecer de menor a mayor."<<endl;


		do{
	        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
	        cin >> nombreArchivo;

	    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);



	    lectura.open(nombreArchivo);
	    if(!lectura){
	      cout << "Error: no se pudo abrir el archivo..." << endl;
	      system("pause");
	      return ;
	    }else cout<<"Se abri\xA2 correctamente el archivo."<<endl;

	    int m;
	    lectura>>m;
	    while(m<1){
	    	cout <<"En el archivo se encontr\xA2 un n\xA3mero inv\xA0lido de puntos. Ingrese nuevamente por teclado."<< endl;
	    	cout << "N\xA3mero de puntos: ";
	    	m=CapturaEntradaEntero();
		}

		float puntos[MAX], eval[MAX];
		for(int i=0;i<m;i++){
			lectura>>puntos[i];
			lectura>>eval[i];
		}
		lectura.close();


		bool IgualEspaciados=true;
		float wspacio=puntos[1]-puntos[0];
		for( int i=1; i < m-1 ;i++ ){
			if ( abs( ( puntos[i+1] - puntos[i] - wspacio) )> 0.005){

				IgualEspaciados = false;
				break;
			}
		}
		if(!IgualEspaciados){
			cout<<"Los espacios entre los puntos no son iguales. Cambie los valores en el archivo y vuelva a abrir el programa."<<endl;
			system("pause");
			return ;
		}
		int part=m-1;

		float sumas=0;
		for(int i=1;i<part;i++) sumas+=2*eval[i];
		sumas+=eval[0];
		sumas+=eval[part];


		float area=((puntos[part]-puntos[0]))*(sumas)/(2*part);

		cout<<"La integral de esta funci\xA2n es "<<area<<endl;

	}
	system("pause");
	MenuPrincipal(opc);
}

/*******************************************************************************************************************************************************/

void GestionaSimpson(char &opc)
{
    string fDeX;

    FunctionParser fparser;

    do{
        char salir='\0';
        system("cls");
        cout<<"Programa que integra num\x82ricamente una funci\xA2n f en un intervalo [a,b]."<<endl;
        cout<<"Este programa utiliza la regla de Simpson, por lo que se le pedir\xA0\n"
            "un n\xA3mero de particiones."<<endl;

        cout<<"Presione 0 para salir del programa.\nDe lo contrario presione cualquier otra tecla." << endl;
        salir=getch();
        if(salir=='0'){
            cout<<"Gracias por usar el programa." << endl;
            system("pause");
            break;
        }

        system("cls");
        char opcion='0';
        cout<<"\xA8Se conoce la funci\xA2n?(S/N): ";
        opcion=getch();
        cout<<"\n";

        while(opcion!='S' && opcion!='s' && opcion!='N' && opcion!='n'){
            cout<<"Ingrese nuevamente."<<endl;
            cout<<"\xA8Se conoce la funci\xA2n?(S/N): ";
            opcion=getch();
            cout<<"\n";
        }

        if(opcion=='S' || opcion=='s'){
            system("cls");
            MuroTextoParser();

            cout<<"Funci\xA2n: "<<endl;

            while(true){
                cout << "f(x) = ";
                std::getline(std::cin, fDeX);
                if(std::cin.fail()) return ;

                int res = fparser.Parse(fDeX, "x");
                if(res < 0) break;

                cout << string(res+7, ' ') << "^\n" << fparser.ErrorMsg() << "\n\n";
            }

            cout<<endl;
            int part;

            cout<<"Particiones (al menos 3): ";
            part=CapturaEntradaEntero();
            while(part<3){
                cout<<"Ingrese un valor v\xA0lido. Para este m\x82todo se requieren al menos 3 particiones."<<endl;
                cout<< "Particiones: ";
                part=CapturaEntradaEntero();
            }

            float a,b;
            cout<<"Intervalo de integraci\xA2n [a,b]"<<endl;
            cout<<"a: ";
            a=CapturaEntradaReal();
            cout<<"b: ";
            b=CapturaEntradaReal();

            while(a>=b){
                system("cls");
                cout<<"Error. 'b' es el fin del intervalo de integraci\xA2n."<<endl;
                cout<<"Intervalo de integraci\xA2n [a,b]"<<endl;
                cout<<"a: ";
                a=CapturaEntradaReal();
                cout<<"b: ";
                b=CapturaEntradaReal();
            }

            double puntosX[part+1];

            float h=(b-a)/part;

            for(int i=0;i < part+1; i++){
                puntosX[i]=a+i*h;
            }

            float eval[part+1];
            for(int i=0; i < part+1 ; i++){
                eval[i]=fparser.Eval(puntosX+i);
            }

            if(part%2==0){
                float sumas=0;

                for(int i=1;i<part;i+=2) {
                    sumas+=4*eval[i];
                }

                for(int i=2;i<part-1;i+=2){
                    sumas+=2*eval[i];
                }
                sumas+=eval[0];

                sumas+=eval[part];

                float area=((puntosX[part]-puntosX[0]))*(sumas)/(3*part);
                cout<<"La integral de esta funci\xA2n es "<<area<<endl;

            }else{
                float sumas=0;

                for(int i=1;i<part-3;i+=2) {
                    sumas+=4*eval[i];
                }

                for(int i=2;i<part-4;i+=2){
                    sumas+=2*eval[i];
                }

                sumas+=eval[part-3]+eval[0];

                sumas/=3*part;

                sumas+= ((eval[part-3]+3*eval[part-2]+3*eval[part-1]+eval[part])/(8*part))*3;


                float area=((puntosX[part]-puntosX[0]))*(sumas);
                cout<<"La integral de esta funci\xA2n es "<<area<<endl;
            }


        }
        else{
            fstream lectura;
            char nombreArchivo[MAX];
            system("cls");
            cout << "Los puntos se capturar\xA0n por archivo de la siguiente manera:"<<endl;
            cout<<"m"<<endl;
            cout<<"x1 y1"<<endl;
            cout<<"x2 y2"<<endl;
            cout<<"x3 y3"<<endl;
            cout<<"  ."<<endl;
            cout<<"  ."<<endl;
            cout<<"  ."<<endl;
            cout<<"xn yn"<<endl;

            cout<<"Siendo m el n\xA3mero de puntos. Los puntos deben aparecer de menor a mayor."<<endl;


            do{
                cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
                cin >> nombreArchivo;

            }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);



            lectura.open(nombreArchivo);
            if(!lectura){
              cout << "Error: no se pudo abrir el archivo..." << endl;
              system("pause");
              return ;
            }else cout<<"Se abri\xA2 correctamente el archivo."<<endl;

            int m;
            lectura>>m;
            while(m<1){
                cout <<"En el archivo se encontr\xA2 un n\xA3mero inv\xA0lido de puntos. Ingrese nuevamente por teclado."<< endl;
                cout << "N\xA3mero de puntos: ";
                m=CapturaEntradaEntero();
            }

            float puntos[MAX], eval[MAX];
            for(int i=0;i<m;i++){
                lectura>>puntos[i];
                lectura>>eval[i];
            }
            lectura.close();


            bool IgualEspaciados=true;
            float wspacio=puntos[1]-puntos[0];
            for( int i=1; i < m-1 ;i++ ){
                if ( abs( ( puntos[i+1] - puntos[i] - wspacio) )> 0.005){

                    IgualEspaciados = false;
                    break;
                }
            }
            if(!IgualEspaciados){
                cout<<"Los espacios entre los puntos no son iguales. Cambie los valores en el archivo y vuelva a abrir el programa."<<endl;
                system("pause");
                return ;
            }
            int part=m-1;

            if(part%2==0){
                float sumas=0;

                for(int i=1;i<part;i+=2) {
                    sumas+=4*eval[i];
                }

                for(int i=2;i<part-1;i+=2){
                    sumas+=2*eval[i];
                }
                sumas+=eval[0];

                sumas+=eval[part];

                float area=((puntos[part]-puntos[0]))*(sumas)/(3*part);
                cout<<"La integral de esta funci\xA2n es "<<area<<endl;

            }else{
                float sumas=0;

                for(int i=1;i<part-3;i+=2) {
                    sumas+=4*eval[i];
                }

                for(int i=2;i<part-4;i+=2){
                    sumas+=2*eval[i];
                }

                sumas+=eval[part-3]+eval[0];

                sumas/=3*part;

                sumas+= ((eval[part-3]+3*eval[part-2]+3*eval[part-1]+eval[part])/(8*part))*3;


                float area=((puntos[part]-puntos[0]))*(sumas);
                cout<<"La integral de esta funci\xA2n es "<<area<<endl;
            }
        }

        system("pause");
    }while(true);

	system("pause");
	MenuPrincipal(opc);
}

/*******************************************************************************************************************************************************/

void GestionaRegresion(char &opc)
{
    ifstream lectura;
	char nombreArchivo[100];
	system("cls");
	cout << "Programa que encuentra el polinomio de grado n que ajusta un conjunto de puntos dados." << endl;

	cout << "Grado del polinomio: ";
	int grado=CapturaEntradaEntero();
	while(grado<1 || grado>100){
		cout<<"El grado debe ser entre 1 y 100. Ingresa nuevamente." << endl;
		cout<<"Grado del polinomio: ";
		grado=CapturaEntradaEntero();
	}
	system("cls");
	cout<<"Polinomio de grado "<<grado<<endl;

	cout << "Los puntos se capturar\xA0n por archivo de la siguiente manera:"<<endl;
	cout<<"m"<<endl;
	cout<<"x1 y1"<<endl;
	cout<<"x2 y2"<<endl;
	cout<<"x3 y3"<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"xn yn"<<endl;

	cout<<"Siendo m el n\xA3mero de puntos."<<endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);



    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }else cout<<"Se abri\xA2 correctamente el archivo."<<endl;

    int m;
    lectura>>m;
    while(m<1){
    	cout <<"En el archivo se encontr\xA2 un n\xA3mero inv\xA0lido de puntos. Ingrese nuevamente por teclado."<< endl;
    	cout << "N\xA3mero de puntos: ";
    	m=CapturaEntradaEntero();
	}

	float puntos[MAX], eval[MAX];
	for(int i=0;i<m;i++){
		lectura>>puntos[i];
		lectura>>eval[i];
	}
	lectura.close();

	system("cls");

	cout<<"Se resolver\xA0 esta matriz de coeficientes que corresponden a los coeficientes del polinomio a encontrar." << endl;

	float **Matriz=CrearArreglo(grado+1,grado+1);

	for(int i=0; i < grado+1 ; i++){
		for(int j = 0; j < grado+1; j ++ ){
			Matriz[i][j]=0;
		}
	}
	int aux;
	for(int i=0;i<grado+1;i++){
		for(int j=i, aux=0; aux < grado+1 ;j++, aux++){
			for(int k=0;k<m;k++) {
				Matriz[i][aux]+=pow(puntos[k],j);
			}
		}

	}


	for(int i = 0; i < grado +1 ; i++){
		cout << char(179);
		for(int j=0 ; j < grado+1 ; j++){
			cout << setw(10) << Matriz[i][j];
		}
		cout <<char(179) << endl;
	}

	cout << endl;

	int col=2*grado+2;

	float **MatrizInversa=CrearArreglo(grado+1,col);

	for(int i=0; i < grado+1 ; i++){
		for(int j = 0; j < col; j ++ ){
			MatrizInversa[i][j]=0;
		}
	}


	for(int i = 0 ; i < grado+1; i++){
		for(int j= 0 ; j < grado+1; j++){
			MatrizInversa[i][j]=Matriz[i][j];
		}

	}



	for(int i = 0 ; i < grado+1; i++){
		for(int j= grado+1+i ; j < grado+2+i  ; j++){
			MatrizInversa[i][j]=1;
			break;
		}
	}

	bool Funciona=false;
	float mij;
	int p;


	for(int i=0; i < grado+1 ; i++){
		p=i;
		//Verifica que no haya 0s en toda una columna
		for(int j=p; j < grado+1; j++){
			if(MatrizInversa[j][i]!=0){
				Funciona=true;
				break;
				p=j;
			}
		}



		if(!Funciona){
			cout << "No se puede encontrar soluci\xA2n a este sistema. "<< endl;
			system("pause");
			return ;
		}
		//Si habia un 0 en la columna i se hace un intercambio en donde  se encontro
		if(p!=i){
			for(int k=0 ; k < col  ; k++){
				aux=MatrizInversa[p][k];
				MatrizInversa[p][k]=MatrizInversa[i][k];
				MatrizInversa[i][k]=aux;
			}
		}

		for(int j=i+1; j < grado + 1 ; j++){
			mij=MatrizInversa[j][i]/MatrizInversa[i][i];
			for(int k=0; k < col-i ; k++){
				MatrizInversa[j][k]-=mij*MatrizInversa[i][k];
			}
		}


	}

	float div;

	for(int i=0 ; i < grado ; i++){


		div=MatrizInversa[grado-i][grado-i];

		for(int k=grado - i ; k < col ; k++){
			MatrizInversa[grado-i][k]/=div;
		}

		for(int k= 0 ; k < grado -i ; k++){

			div=-MatrizInversa[k][grado-i];
			for(int j=grado-i ; j < col; j++){
				MatrizInversa[k][j]+=MatrizInversa[grado-i][j]*div;

			}

		}

	}

	div=MatrizInversa[0][0];
	for(int j =0; j < col ;j++)	MatrizInversa[0][j]/=div;


	for(int i = 0 ; i < grado +1 ; i++){
		for(int j=0 ; j < grado+1 ; j++) MatrizInversa[i][j]=MatrizInversa[i][j+grado+1];
	}


	cout << "Cuya inversa es :" << endl<< endl;
	for(int j =0; j < grado+1;j++){
		cout << char(179);
		for(int k=0; k < grado+1 ;k++){
			cout << setw(10) << MatrizInversa[j][k] ;
		}
		cout << char(179) << endl;
	}



	float **MatrizXY=CrearArreglo(grado+1,1);

	for(int i=0; i < 1 ; i++){
		for(int j = 0; j < grado+1; j ++ ){
			MatrizXY[i][j]=0;
		}
	}

	for(int i=0;i<grado+1;i++){
		for(int k=0;k<m;k++){
			MatrizXY[i][0]+=pow(puntos[k],i)*eval[k];
		}
	}

	float **Coeficientes=CrearArreglo(grado+1,1);

	Coeficientes=ProductoMatriz(MatrizInversa,MatrizXY,grado+1,1,grado+1);
	cout << endl << endl;



	cout<<endl<<endl<<"Segundo lado de la ecuaci\xA2n:"<<endl;
	cout<<char(179);
    for(int i=0;i<grado+1;i++) cout<< setw(10)<<MatrizXY[i][0];
    cout<<char(179)<<endl<<endl;
    cout << endl << endl;

    for(int i = 0 ; i < grado +1 ; i++) cout << char(179) << setw(10) << Coeficientes[i][0] << char(179)<< endl;

    cout << "f(x) = "<< Coeficientes[0][0];
	for(int i = 1 ; i < grado +1 ; i++){
		if(Coeficientes[i][0]>0) cout << " + " << Coeficientes[i][0] << " x^"<<i;
		else cout << Coeficientes[i][0] << "x^" << i;
	}

	cout << endl << endl;

	system("pause");
	MenuPrincipal(opc);

}

/*******************************************************************************************************************************************************/



float** ProductoMatriz(float **A, float **B, int ren, int col2,int ren2)
{
	float** P=CrearArreglo(ren,col2);
	for(int i=0;i<ren;i++){
		for(int j=0;j<col2;j++){
			for(int k=0;k<ren2;k++){
				P[i][j]+=A[i][k]*B[k][j];
			}
		}
	}

	return P;
}

/*******************************************************************************************************************************************************/

float **CrearArreglo(int ren, int col)
{
	float **A;

	A=new(nothrow) float *[ren];
	if(A==NULL) return A;

	A[0]=new (nothrow) float [ren*col];

	if(A[0]==NULL){
		LiberaArreglo(A);
		return A;
	}

	for(int i=1; i < ren;i++){
		A[i]=A[i-1]+col;
	}
	return A;
}

/*******************************************************************************************************************************************************/

void LiberaArreglo(float **&A)
{
	if(*A!=NULL)delete[] *A;
	delete [] A;
}

/*******************************************************************************************************************************************************/

void GestionaGaussJordan(char &opc)
{
    system("cls");
    int orden, col,p,cifras;
	double  Matriz[MAX_REN][MAX_COL] , tol;
	ifstream lectura;

	char nombreArchivo[90];

	system("cls");

	cout<<"Programa que implementa el algoritmo de Gauss-Jordan"<<
		" para resolver matrices aumentadas."<<endl;

	cout << "Formato para matriz aumentada: "<<endl<<endl;

    cout << "n       			Primera linea para el orden de la matriz" << endl;
    cout << "a11x1 a12x2 a13x3 b1" << endl;
    cout << "a21x1 a22x2 a23x3 b2 " << endl;
    cout << "a31x1 a32x2 a33x3 b3" << endl;
    cout << "a41x1 a42x2 a43x3 b4" << endl << endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);

    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }

	cout<<"Cifras significativas: ";
	cifras=CapturaEntradaReal();
	while(cifras<1){
		cout<<"Deben ser al menos un cifras significativas."<<endl;
		cout<<"Cifras: ";
		cifras=CapturaEntradaReal();
	}

	cout<<"Tolerancia para el error: ";
	tol=CapturaEntradaReal();
	while(tol<0){
		cout<<"La tolerancia debe ser un valor no negativo. Ingresa nuevamente."<<endl;
		cout<<"Tolerancia: ";
		tol=CapturaEntradaReal();
	}

	//lee el archivo, almacenando cada entrada de la matriz en el arreglo bid, y aplicando redondeo
	lectura>>orden;
	col=orden+1;
	for(int i=0;i<orden;i++){
		for(int j=0;j<col;j++){
			lectura>>Matriz[i][j];
			Matriz[i][j]=Redondea(Matriz[i][j],cifras);
		}
	}

	for(int i=0;i<orden;i++){
        cout << char(179);
		for(int j=0;j<col;j++){
			cout <<setw(12) <<  Matriz[i][j];
		}
		cout << char(179) << endl;
	}cout << endl << endl;
	Sleep(1000);

	int grado=orden-1;

	col=2*grado+2;

    float **B=CrearArreglo(orden,1);

    for( int i = 0 ; i < orden ; i++) B[i][0] =Matriz[i][orden];


	float **MatrizInversa=CrearArreglo(grado+1,col);

	for(int i=0; i < grado+1 ; i++){
		for(int j = 0; j < col; j ++ ){
			MatrizInversa[i][j]=0;
		}
	}


	for(int i = 0 ; i < grado+1; i++){
		for(int j= 0 ; j < grado+1; j++){
			MatrizInversa[i][j]=Matriz[i][j];
		}

	}


    float aux;

	for(int i = 0 ; i < orden; i++){
		for(int j= orden+i ; ; j++){
			MatrizInversa[i][j]=1;
			break;
		}
	}

	for(int i=0;i<orden;i++){
        cout << char(179);
		for(int j=0;j<col;j++){
			cout <<setw(12) <<  MatrizInversa[i][j];
		}
		cout << char(179) << endl;
	}cout << endl << endl;
	Sleep(1000);

	bool Funciona=false;
	float mij;


	for(int i=0; i < grado+1 ; i++){
		p=i;
		//Verifica que no haya 0s en toda una columna
		for(int j=p; j < grado+1; j++){
			if(MatrizInversa[j][i]!=0){
				Funciona=true;
				break;

			}
		}


        for(int j=0 ; j < grado+1; j++){
            cout << char(179);
            for(int k= 0 ; k < col; k++){
                cout  << setw(12) << MatrizInversa[j][k];
            }
            cout << char(179) << endl;
        }cout << endl << endl;
        Sleep(1000);


		if(!Funciona){
			cout << "No se puede encontrar soluci\xA2n a este sistema. "<< endl;
			system("pause");
			return ;
		}
		//Si habia un 0 en la columna i se hace un intercambio en donde  se encontro
		if(p!=i){
			for(int k=0 ; k < col  ; k++){
				aux=MatrizInversa[p][k];
				MatrizInversa[p][k]=MatrizInversa[i][k];
				MatrizInversa[i][k]=aux;
			}
		}

		for(int j=i+1; j < grado + 1 ; j++){
			mij=MatrizInversa[j][i]/MatrizInversa[i][i];
			for(int k=0; k < col-i ; k++){
				MatrizInversa[j][k]-=mij*MatrizInversa[i][k];
			}
		}


	}

	float div;

	for(int i=0 ; i < grado ; i++){


		div=MatrizInversa[grado-i][grado-i];

		for(int k=grado - i ; k < col ; k++){
			MatrizInversa[grado-i][k]/=div;
		}

		for(int k= 0 ; k < grado -i ; k++){

			div=-MatrizInversa[k][grado-i];
			for(int j=grado-i ; j < col; j++){
				MatrizInversa[k][j]+=MatrizInversa[grado-i][j]*div;

			}

		}
		for(int j=0 ; j < grado+1; j++){
            cout << char(179);
            for(int k= 0 ; k < col; k++){
                cout  << setw(12) << MatrizInversa[j][k];
            }
            cout << char(179) << endl;
        }cout << endl << endl;
        Sleep(1000);

	}

	div=MatrizInversa[0][0];
	for(int j =0; j < col ;j++)	MatrizInversa[0][j]/=div;

	for(int j=0 ; j < grado+1; j++){
        cout << char(179);
        for(int k= 0 ; k < col; k++){
            cout  << setw(12) << MatrizInversa[j][k];
        }
        cout << char(179) << endl;
    }
    Sleep(1000);


	for(int i = 0 ; i < grado +1 ; i++){
		for(int j=0 ; j < grado+1 ; j++) MatrizInversa[i][j]=MatrizInversa[i][j+grado+1];
	}

    cout << "Matriz inversa." << endl<< endl;
    for(int j=0 ; j < grado+1; j++){
        cout << char(179);
        for(int k= 0 ; k < orden; k++){
            cout  << setw(12) << MatrizInversa[j][k];
        }
        cout << char(179) << endl;
    }cout << endl << endl;
    Sleep(1000);

    float **X=CrearArreglo(orden,1);

    for(int i= 0 ; i < orden ; i++) X[i][0] =0;



    //X=ProductoMatriz(MatrizInversa,B,orden,1,orden);

    for(int i=0;i<orden;i++){
		for(int j=0;j<1;j++){
			for(int k=0;k<orden;k++) X[i][0]+=MatrizInversa[i][k]*B[k][j];
		}
	}
    cout << endl;

    cout << "Soluciones: " << endl << endl;
    for(int i = 0 ; i < orden; i++) cout << char(179) << left << setw(10) << X[i][0] << char(179) << endl;



    system("pause");
    MenuPrincipal(opc);
}


/************************************************************************************************************************************************/

void GestionaJacobi( char &opc)
{
    system("cls");
    int orden, col;
	long double aux, Matriz[MAX_REN][MAX_COL], tol;
	ifstream lectura;

	char nombreArchivo[100];

	cout<<"Programa que implementa el algoritmo de Jacobi "<<
		"para resolver matrices aumentadas."<<endl;

	cout << "Formato para matriz aumentada: "<<endl<<endl;

    cout << "n       			Primera linea para el orden de la matriz" << endl;
    cout << "a11x1 a12x2 a13x3 b1" << endl;
    cout << "a21x1 a22x2 a23x3 b2 " << endl;
    cout << "a31x1 a32x2 a33x3 b3" << endl;
    cout << "a41x1 a42x2 a43x3 b4" << endl << endl;


	do{
        cout << "Nombre del archivo, puede incluir la ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);

    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }

	cout<<"Tolerancia para el error relativo porcentual: ";
	tol=CapturaEntradaReal();
	while(tol<0){
		cout<<"La tolerancia debe ser un valor no negativo. Ingresa nuevamente."<<endl;
		cout<<"Umbral: ";
		tol=CapturaEntradaReal();
	}
	lectura>>orden;
	while(orden<1 || orden>10){
		cout<<"El orden debe ser de al menos 1 y m\xA0ximo 10. En el archivo se encontr\xA2\n"<<
			" un valor no v\xA0lido. Ingresa nuevamente."<<endl;
		cout<<"Orden de la matriz: ";
		orden=CapturaEntradaEntero();
	}

	col=orden+1;
	for(int i=0;i<orden;i++){
		for(int j=0;j<col;j++){
			lectura>>Matriz[i][j];
		}
	}

	lectura.close();

	int colMayor,renMayor;
	bool NecesitaPermutar;
	float Mayor;

	int numMaxPerm=orden/2, cont=0;
	//Por cada par de renglones que tenga la matriz es permitido una sola permutacion.
	do{
		NecesitaPermutar=false;

		for(int i=0;i<orden;i++){
			renMayor=i;
			colMayor=0;
			for(int j=0;j<col-2;j++){
				Mayor=Matriz[renMayor][colMayor];
				//Busca el mayor de todos en el renglon
				if(Mayor<Matriz[i][j+1]) colMayor=j+1;
			}
				if(renMayor!=colMayor) {
					NecesitaPermutar=true;
					break;
				}

		}


		if(NecesitaPermutar){
			for(int j=0;j<col;j++){
				aux=Matriz[renMayor][j];
				Matriz[renMayor][j]=Matriz[colMayor][j];
				Matriz[colMayor][j]=aux;
			}
		}else break;


		cont++;
	}while(cont<=numMaxPerm);


	if(NecesitaPermutar){
		char opcion;
		cout<<"Se aplic\xA0 cambio de renglones para que la matriz pudiera converger,sin\n"<<
			"embargo, sigue sin ser linealmente dominante. Deseas continuar el proceso?"<<endl;
		cout<<"Presiona S para continuar. De lo contrario, cualquier tecla:";
		cin>>opcion;
		if(opcion!='S' &&  opcion!='s'){
			cout<<"Gracias por usar el programa."<<endl;
			system("pause");
			return ;
		}else{
			int iter;
			cout<<"M\xA3mero de iteraciones m\xA0ximas: ";
			iter=CapturaEntradaEntero();
			while(iter<1){
				cout<<"Error. El n\xA3mero de iteraciones debe ser al menos 1. Ingresa nuevamente."<<endl;
				cout<<"N\xA3mero de iteraciones: "<<endl;
				iter=CapturaEntradaEntero();
			}

            float puntosX[orden]={0};

            float eval[orden]={0};

            float guardar[orden]={0};
            float error[orden];

            cout<<"Se calcularon las siguientes soluciones: "<<endl;
            for(int k=0 ; k < iter ; k++){
                for(int i= 0 ; i < orden ; i++){
                    eval[i]=0;
                }
                for(int i=0;i < orden;i++){


                    for(int j= 0 ; j < orden ; j++){
                        if(j!=i) eval[i]-=Matriz[i][j]*puntosX[j];
                    }
                    eval[i]+=Matriz[i][orden];
                    eval[i]/=Matriz[i][i];

                    for(int j=0 ; j < orden ; j++) error[j] = abs((eval[j]-puntosX[j])/eval[j]);

                    guardar[i]=eval[i];
                }

                for(int i=0 ; i < orden ; i++){
                    puntosX[i]=guardar[i];
                }
            }

            for(int i = 0 ; i < orden ; i++ ){
                cout << "x" << i+1 <<" = " << puntosX[i] << endl;
            }


		}
	}else{
		cout<<"La matriz es diagonalmente dominante. Se proceder\xA0 a calcular las soluciones."<<endl;
		long double error[MAX_COL];

        float puntosX[orden]={0};

        float eval[orden]={0};

        float guardar[orden]={0};

        cout<<"Se calcularon las siguientes soluciones: "<<endl;
        for(int k=0 ; k < 5 ; k++){
            for(int i= 0 ; i < orden ; i++){
                eval[i]=0;
            }
            for(int i=0;i < orden;i++){


                for(int j= 0 ; j < orden ; j++){
                    if(j!=i) eval[i]-=Matriz[i][j]*puntosX[j];
                }
                eval[i]+=Matriz[i][orden];
                eval[i]/=Matriz[i][i];

                for(int j=0 ; j < orden ; j++) error[j] = abs((eval[j]-puntosX[j])/eval[j]);

                guardar[i]=eval[i];
            }

            for(int i=0 ; i < orden ; i++){
                puntosX[i]=guardar[i];
            }
        }

        for(int i = 0 ; i < orden ; i++ ){
            cout << "x" << i+1 <<" = " << puntosX[i] << endl;
        }


	}

	system("pause");
	MenuPrincipal(opc);
}


void GestionaGaussSeidel(char &opc)
{
    system("cls");
    cout << "Sistemas lineales. M\x82todo de Gauss-Seidel." << endl;

    int orden, col;
	long double aux, Matriz[MAX_REN][MAX_COL], tol;
	ifstream lectura;

	char nombreArchivo[100];

	cout << "Formato para matriz aumentada: "<<endl<<endl;

    cout << "n       			Primera linea para el orden de la matriz" << endl;
    cout << "a11x1 a12x2 a13x3 b1" << endl;
    cout << "a21x1 a22x2 a23x3 b2 " << endl;
    cout << "a31x1 a32x2 a33x3 b3" << endl;
    cout << "a41x1 a42x2 a43x3 b4" << endl << endl;


	do{
        cout << "Nombre del archivo, puede incluir la ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);

    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }

	cout<<"Tolerancia para el error relativo porcentual: ";
	tol=CapturaEntradaReal();
	while(tol<0){
		cout<<"La tolerancia debe ser un valor no negativo. Ingresa nuevamente."<<endl;
		cout<<"Umbral: ";
		tol=CapturaEntradaReal();
	}
	lectura>>orden;
	while(orden<1 || orden>10){
		cout<<"El orden debe ser de al menos 1 y m\xA0ximo 10. En el archivo se encontr\xA2\n"<<
			" un valor no v\xA0lido. Ingresa nuevamente."<<endl;
		cout<<"Orden de la matriz: ";
		orden=CapturaEntradaEntero();
	}

	col=orden+1;
	for(int i=0;i<orden;i++){
		for(int j=0;j<col;j++){
			lectura>>Matriz[i][j];
		}
	}

	lectura.close();

	int colMayor,renMayor;
	bool NecesitaPermutar;
	float Mayor;

	int numMaxPerm=orden/2, cont=0;
	//Por cada par de renglones que tenga la matriz es permitido una sola permutacion.
	do{
		NecesitaPermutar=false;

		for(int i=0;i<orden;i++){
			renMayor=i;
			colMayor=0;
			for(int j=0;j<col-2;j++){
				Mayor=Matriz[renMayor][colMayor];
				//Busca el mayor de todos en el renglon
				if(Mayor<Matriz[i][j+1]) colMayor=j+1;
			}
				if(renMayor!=colMayor) {
					NecesitaPermutar=true;
					break;
				}

		}


		if(NecesitaPermutar){
			for(int j=0;j<col;j++){
				aux=Matriz[renMayor][j];
				Matriz[renMayor][j]=Matriz[colMayor][j];
				Matriz[colMayor][j]=aux;
			}
		}else break;


		cont++;
	}while(cont<=numMaxPerm);


	if(NecesitaPermutar){
		char opcion;
		cout<<"Se aplic\xA0 cambio de renglones para que la matriz pudiera converger,sin\n"<<
			"embargo, sigue sin ser linealmente dominante. Deseas continuar el proceso?"<<endl;
		cout<<"Presiona S para continuar. De lo contrario, cualquier tecla:";
		cin>>opcion;
		if(opcion!='S' &&  opcion!='s'){
			cout<<"Gracias por usar el programa."<<endl;
			system("pause");
			return ;
		}else{
			int iter;
			cout<<"M\xA3mero de iteraciones m\xA0ximas: ";
			iter=CapturaEntradaEntero();
			while(iter<1){
				cout<<"Error. El n\xA3mero de iteraciones debe ser al menos 1. Ingresa nuevamente."<<endl;
				cout<<"N\xA3mero de iteraciones: "<<endl;
				iter=CapturaEntradaEntero();
			}

        float puntosX[orden]={0};

        float eval[orden]={0};

        float guardar[orden]={0};

        float error[orden];

        cout<<"Se calcularon las siguientes soluciones: "<<endl;
        for(int k=0 ; k < 5 ; k++){
            for(int i= 0 ; i < orden ; i++){
                eval[i]=0;
            }
            for(int i=0;i < orden;i++){


                for(int j= 0 ; j < orden ; j++){
                    if(j!=i) eval[i]-=Matriz[i][j]*puntosX[j];
                }
                eval[i]+=Matriz[i][orden];
                eval[i]/=Matriz[i][i];

                for(int j=0 ; j < orden ; j++) error[j] = abs((eval[j]-puntosX[j])/eval[j]);

                puntosX[i]=eval[i];
            }

        }

        for(int i = 0 ; i < orden ; i++ ){
            cout << "x" << i+1 <<" = " << puntosX[i] << endl;
        }


		}
	}else{
		cout<<"La matriz es diagonalmente dominante. Se proceder\xA0 a calcular las soluciones."<<endl;
		long double error[MAX_COL];

        float puntosX[orden]={0};

        float eval[orden]={0};

        float guardar[orden]={0};

        cout<<"Se calcularon las siguientes soluciones: "<<endl;
        for(int k=0 ; k < 5 ; k++){
            for(int i= 0 ; i < orden ; i++){
                eval[i]=0;
            }
            for(int i=0;i < orden;i++){


                for(int j= 0 ; j < orden ; j++){
                    if(j!=i) eval[i]-=Matriz[i][j]*puntosX[j];
                }
                eval[i]+=Matriz[i][orden];
                eval[i]/=Matriz[i][i];

                for(int j=0 ; j < orden ; j++) error[j] = abs((eval[j]-puntosX[j])/eval[j]);

                puntosX[i]=eval[i];
            }

        }

        for(int i = 0 ; i < orden ; i++ ){
            cout << "x" << i+1 <<" = " << puntosX[i] << endl;
        }


	}

	system("pause");
	MenuPrincipal(opc);

}


void GestionaPolinomioNewton(char &opc)
{
    system("cls");
    cout << "Ajustes de curva. M\x82todo de diferencias divididas de Newton." << endl;

    ifstream lectura;
	char nombreArchivo[100];
	system("cls");
	cout << "Programa que encuentra el polinomio de grado n que ajusta un conjunto de puntos dados" << endl;
	cout << " mediante el m\x82todo de Diferencias Divididas de Newton." << endl;

	cout << "Grado del polinomio: ";
	int grado=CapturaEntradaEntero();
	while(grado<1 || grado>100){
		cout<<"El grado debe ser entre 1 y 100. Ingresa nuevamente." << endl;
		cout<<"Grado del polinomio: ";
		grado=CapturaEntradaEntero();
	}
	system("cls");
	cout<<"Polinomio de grado "<<grado<<endl;

	cout << "Los puntos se capturar\xA0n por archivo de la siguiente manera:"<<endl;
	cout<<"m"<<endl;
	cout<<"x1 y1"<<endl;
	cout<<"x2 y2"<<endl;
	cout<<"x3 y3"<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"xn yn"<<endl;

	cout<<"Siendo m el n\xA3mero de puntos."<<endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);



    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }else cout<<"Se abri\xA2 correctamente el archivo."<<endl;

    int m;
    lectura>>m;
    while(m<1){
    	cout <<"En el archivo se encontr\xA2 un n\xA3mero inv\xA0lido de puntos. Ingrese nuevamente por teclado."<< endl;
    	cout << "N\xA3mero de puntos: ";
    	m=CapturaEntradaEntero();
	}

	float puntos[MAX], eval[MAX];
	for(int i=0;i < m;i++){
		lectura>>puntos[i];
		lectura>>eval[i];
	}
	lectura.close();


    float B[MAX][MAX];
    for(int i= 0 ; i < m; i++){
        B[0][i]=puntos[i];
    }
    for(int i= 0 ; i < m ; i++){
        B[1][i]=eval[i];
    }
    int cont=1;
    for(int i = 2 ; i < m +1; i++){
        for(int j= 0 ; j < m-i+1 ; j++){
            B[i][j]=(B[i-1][j+1]-B[i-1][j])/(B[0][j+cont]-B[0][j]);
        }
        cont++;
    }

    cout << endl <<endl << "La funci\xA2n es:"  << endl;

    cout << "f(x)= " << B[1][0] << " ";


    for(int i = 1 ; i < grado+1 ; i++){
        if (B[i+1][0] >0 && B[i+1][0] != 1) cout <<"+ "<< B[i+1][0];

        if(B[i+1][0]<0 )   cout << B[i+1][0];

        if(B[i+1][0]==1) cout << "+ ";
        if(B[i+1][0]==0){
            i++;
            continue;
        }

        for(int j=0 ; j < i; j++){
            cout << "(x";
            if(puntos[j]>0) cout << "- " <<puntos[j]<<")";
            if(puntos[j]<0) cout << "+" <<abs(puntos[j]) <<")";
            if(puntos[j]==0) cout << ")";
        }
    }

    cout << "\n\nPunto en el que quiere evaluar: ";
    float punto=CapturaEntradaReal();

    float evaluacion=0;
    float multiplicatoria;
    evaluacion+=B[1][0];
    for(int i = 1 ; i < grado +1 ; i++){
        multiplicatoria=1;
        for(int j=0 ; j < i ; j++){
            multiplicatoria*=(punto-puntos[j]);
        }
        evaluacion+=B[i+1][0]*multiplicatoria;
    }
    cout << "La evaluaci\xA2n en este punto es: ";
    cout << "f("<<punto<<")= "<<evaluacion<<endl;

}


void GestionaPolinomioLagrange(char &opc)
{
    system("cls");
    cout << "Ajustes de curva. M\x82todo de diferencias divididas de Newton." << endl;

    ifstream lectura;
	char nombreArchivo[100];
	system("cls");
	cout << "Programa que encuentra el polinomio de grado n que ajusta un conjunto de puntos dados" << endl;
	cout << " mediante el m\x82todo de Diferencias Divididas de Newton." << endl;

	cout << "Grado del polinomio: ";
	int grado=CapturaEntradaEntero();
	while(grado<1 || grado>100){
		cout<<"El grado debe ser entre 1 y 100. Ingresa nuevamente." << endl;
		cout<<"Grado del polinomio: ";
		grado=CapturaEntradaEntero();
	}
	system("cls");
	cout<<"Polinomio de grado "<<grado<<endl;

	cout << "Los puntos se capturar\xA0n por archivo de la siguiente manera:"<<endl;
	cout<<"m"<<endl;
	cout<<"x1 y1"<<endl;
	cout<<"x2 y2"<<endl;
	cout<<"x3 y3"<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"  ."<<endl;
	cout<<"xn yn"<<endl;

	cout<<"Siendo m el n\xA3mero de puntos."<<endl;


	do{
        cout << "Nombre del archivo. Incluya su extensi\xA2n y su ruta: ";
        cin >> nombreArchivo;

    }while(nombreArchivo[0] != '\n' && strlen(nombreArchivo) > 90);



    lectura.open(nombreArchivo);
    if(!lectura){
      cout << "Error: no se pudo abrir el archivo..." << endl;
      system("pause");
      return ;
    }else cout<<"Se abri\xA2 correctamente el archivo."<<endl;

    int m;
    lectura>>m;
    while(m<1){
    	cout <<"En el archivo se encontr\xA2 un n\xA3mero inv\xA0lido de puntos. Ingrese nuevamente por teclado."<< endl;
    	cout << "N\xA3mero de puntos: ";
    	m=CapturaEntradaEntero();
	}

	float puntos[MAX], eval[MAX];
	for(int i=0;i < m;i++){
		lectura>>puntos[i];
		lectura>>eval[i];
	}
	lectura.close();


    float B[MAX][MAX];
    for(int i= 0 ; i < m; i++){
        B[0][i]=puntos[i];
    }
    for(int i= 0 ; i < m ; i++){
        B[1][i]=eval[i];
    }
    int cont=0;
    for(int i = 2 ; i < m +1; i++){
        for(int j= 0 ; j < grado +1; j++){
            if(j+2==i) cont++;
            B[2][j]=B[i-1][j]/(B[0][j]-B[j][cont]);
        }

    }

    cout << endl <<endl << "La funci\xA2n es:"  << endl;

    cout << "f(x)= " << B[1][0] << " ";


    for(int i = 1 ; i < grado+1 ; i++){
        if (B[i+1][0] >0 && B[i+1][0] != 1) cout <<"+ "<< B[i+1][0];

        if(B[i+1][0]<0 )   cout << B[i+1][0];

        if(B[i+1][0]==1) cout << "+ ";
        if(B[i+1][0]==0){
            i++;
            continue;
        }

        for(int j=0 ; j < i; j++){
            cout << "(x";
            if(puntos[j]>0) cout << "- " <<puntos[j]<<")";
            if(puntos[j]<0) cout << "+" <<abs(puntos[j]) <<")";
            if(puntos[j]==0) cout << ")";
        }
    }

    cout << "\n\nPunto en el que quiere evaluar: ";
    float punto=CapturaEntradaReal();

    float evaluacion=0;
    float multiplicatoria;
    evaluacion+=B[1][0];
    for(int i = 1 ; i < grado +1 ; i++){
        multiplicatoria=1;
        for(int j=0 ; j < i ; j++){
            multiplicatoria*=(punto-puntos[j]);
        }
        evaluacion+=B[i+1][0]*multiplicatoria;
    }
    cout << "La evaluaci\xA2n en este punto es: ";
    cout << "f("<<punto<<")= "<<evaluacion<<endl;

}


void MuroTextoParser()
{
    cout << "Para capturar correctamente la funci\xA2n, aseg\xA3rese de:"<<endl;
    cout << "Ingresar 'log(x)' para funciones logar\xA1tmicas." << endl;
    cout << "Funciones trigonom\x82tricas: "<<endl;
    cout << "Para la funci\xA2n seno 'sin(x)"<<endl;
    cout << "Para la funci\xA2n coseno 'cos(x)" << endl;
    cout << "Para tangente 'tan(x)" << endl;
    cout << "Para exponenciales 'exp(x)"<<endl;
    cout << "Para logaritmo base 10 'log10(x)" << endl;
    cout << "Para expresar un producto use '*'"<<endl;
    cout << "Para potencias use '^'"<<endl;
}
