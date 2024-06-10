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
    
void add(string año,char guion1, string mes, char guion2, string dia, char espacio, string evento){
    int month = stoi(mes);
    int day = stoi(dia);
    if(month < 1 || month > 12){
        cout << "Month value is invalid: " + mes << endl;
    }
    else if(day < 1 || day > 31){
        cout << "Day value is invalid: " + dia << endl;
    }
    else if(month >=1 && month <= 12 && day >=1 && day <=31 && guion1 == '-' && guion2 == '-'){
    string fecha = año + "-" + mes + "-" + dia;
    events[evento] = fecha;
    }
}
void print(map<string, string> m) {
    for(const auto& item : m) {
        if(item.second > "0"){
        string fechas = item.second;
        string año_con_zeros, mes_con_zeros, dia_con_zeros;
        int p = 0;
        for(int i = 0; i < fechas.size(); ++i){
            if(fechas[i] == '-'){
                p += 1;
            }
            else if(fechas[i] != '-' && p < 1){
                año_con_zeros += fechas[i];
            }
            else if(fechas[i] != '-' && p < 2){
                mes_con_zeros += fechas[i];
            }
            else if( p == 2){
                dia_con_zeros += fechas[i];
            }
        }
        if(año_con_zeros.size() == 3){
        año_con_zeros = "0" + año_con_zeros;
        }
        else if(año_con_zeros.size() == 2){
        año_con_zeros = "00" + año_con_zeros;
        }
        else if(año_con_zeros.size() == 1){
        año_con_zeros = "000" + año_con_zeros;
        };
        if(mes_con_zeros.size() ==  1){
        mes_con_zeros = "0" + mes_con_zeros;
        };
        if(dia_con_zeros.size() == 1){
        dia_con_zeros = "0" + dia_con_zeros;
        };
        cout << año_con_zeros << "-" << mes_con_zeros << "-" << dia_con_zeros << "  " << item.first << endl;
        }
    }
}
void Find(string dates){
    for(auto it = events.begin(); it != events.end(); ++it){
        if(it->second == dates){
            cout << it-> first << endl;
        }
    }
}
void Del_Event(string Eventos_a_Eliminar){
    string Evento_a_Eliminar;
    int p = 0;
    for(int i = 0; i < Eventos_a_Eliminar.size(); i++){
        if(p == 1){
            Evento_a_Eliminar += Eventos_a_Eliminar[i];
        }
        else if(Eventos_a_Eliminar[i] == ' '){
            p += 1;
        }
    }
    if(Evento_a_Eliminar > "0"){
        it2 = events.find(Evento_a_Eliminar);
        if(events.count(Evento_a_Eliminar) > 0){
            events.erase (it2);
            cout << "Deleted successfully" << endl;
            }
        else{
            cout << "Event not found" << endl;
            }
    }   
    else{
        for(auto it3 = events.begin(); it3 != events.end();){
            if(it3->second == Eventos_a_Eliminar){
                events.erase(it3++);
                events_deleted += 1;
            }
            else{
                ++it3;
            }
       
        }
        cout << "Deleted " << events_deleted  << " events" << endl;
    }
    }
    void Ejecucion_De_Comandos(){
        comandos["Add"] = 1;
        comandos["Del"] = 2;
        comandos["Find"] = 3;
        comandos["Print"] = 4;
        comandos["Exit"] = 5;
        for(int i = 0; i < Comandos_V.size(); ++i){
            if(Comandos_V[i] == "Add"){
                string date2 = Fechas_V[i];
            int p = 0;
            for(int t = 0; t < date2.size(); ++t){
            if(date2[t] == '-'||date2[t] == ' '){
                p += 1;
                if(p == 1){
                    guion3 += '-';
                }
                else if(p == 2){
                    guion4 += '-';
                }
                else if(p == 3){
                    espacio += ' ';
                }
            }
            else if(date2[t] != '-' && p < 1){
                year2 += date2[t];
            }
            else if(date2[t] != '-' && p < 2){
                month2 += date2[t];
            }
            else if(date2[t] != ' ' && p < 3){
                days2 += date2[t];
            }
            else if(p == 3){
                event2 += date2[t];
            }
            }
            add(year2, guion3, month2, guion4, days2, espacio, event2);
        }
        else if(Comandos_V[i] == "Del"){
            events_to_delet = Fechas_V[i];
            Del_Event(events_to_delet);
        }
        else if(Comandos_V[i] == "Find"){
            date = Fechas_V[i];
            Find(date);
        }
        else if(Comandos_V[i] == "Print"){
            print(events);
        }
    }
    }
    void BD(){
        cout << "Input 5 to exit" << endl;
        while(getline(cin, comando2)){
            if(comando2 == "5"){
                break;}
            string Comando, Fechas;
            int k = 0;
            for(int i = 0 ; i < comando2.size(); ++i){
                if(comando2[i] == ' '){
                k +=1;
                    if(k > 0 && k != 1){
                        Fechas += ' ';
                    }
                }
                else if(comando2[i] != ' ' && k == 0){
                Comando += comando2[i];
                }
                else if(k > 0){
                Fechas += comando2[i];
                }
            }
            cout << Comando<< endl;
            cout << Fechas << endl;
            Comandos_V.push_back(Comando);
            Fechas_V.push_back(Fechas);
            cin.clear();
        }
    }

    
int main() {
    BD();
    Ejecucion_De_Comandos();
    return 0;
}