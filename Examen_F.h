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
string event, date, deleted_date, deleted_event, Comando, Fechas, year2, month2, days2, event2, comando2;
char guio1, guio2;
map<string, string> events;
vector<string> Events;
vector<string>Comandos_V;
vector<string>Fechas_V;
vector<string>Events_Delted;
map<string, int> comandos;
//Variable Funcion Ejecucion_De_Comandos
char guion_to_add_1, guion_to_add_2, espacio_to_add ;
string date_to_add, year_to_add, month_to_add, day_to_add, event_to_add, date_to_find;
string events_to_delet;
//Variable Funcion BD
string Command;
//Variable Funcion De Chequeo
int Variable_Control_1 = 0;
string Year_Prueba, Month_Prueba, Day_Prueba, Fecha_Prueba, date_to_check;
int Variable_Control_2 = 0;
int Variable_Control_5 = 0;

//Variables Funcion Add
int mes_to_add, dia_to_add;
string fecha_to_add;

//Variables Funcion Del_Eventos
map<string, string> :: iterator it2 ;
string Evento_a_Eliminar;
int Variable_Control_3;

//Variables Funcion Find
map<string, string> :: iterator it ;

//Variables Funcion Print
string año_con_zeros, mes_con_zeros, dia_con_zeros, fechas;
int Variable_Control_4;
//Funciones
void Date_Check(string Fecha);
void add(string año,char guion1, string mes, char guion2, string dia, char espacio, string evento);
void print(map<string, string> m);
void Find(string dates);
void Del_Event(string Eventos_a_Eliminar);
void Ejecucion_De_Comandos();
void BD();