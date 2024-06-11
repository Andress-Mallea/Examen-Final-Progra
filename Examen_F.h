#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <string>

using namespace std;
int year, month, day, events_deleted;
int Salida = 0;
string event, date, deleted_date, deleted_event, events_to_delet, Comando, Fechas, year2, month2, days2, event2, comando2;
char guio1, guio2 ,guion4,guion3,espacio ;
map<string, string> events;
map<string, string> :: iterator it ;
map<string, string> :: iterator it2 ;
vector<string> Events;
vector<string>Comandos_V;
vector<string>Fechas_V;
map<string, int> comandos;

//Variable Funcion De Chequeo
int Variable_Control_1 = 0;
string Year_Prueba, Month_Prueba, Day_Prueba, Fecha_Prueba;
int Variable_Control_2 = 0;
//Funciones
void Date_Check(string Fecha);
void add(string año,char guion1, string mes, char guion2, string dia, char espacio, string evento);
void print(map<string, string> m);
void Find(string dates);
void Del_Event(string Eventos_a_Eliminar);
void Ejecucion_De_Comandos();
void BD();