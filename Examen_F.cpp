#include "Examen_F.h"
#include "Funciones_Adicionales.cpp"
using namespace std;
void add(string año,char guion1, string mes, char guion2, string dia, char espacio, string evento){
    mes_to_add = stoi(mes);
    dia_to_add = stoi(dia);
    if(mes_to_add >=1 && mes_to_add <= 12 && dia_to_add >=1 && dia_to_add <=31 && guion1 == '-' && guion2 == '-'){
    fecha_to_add = año + "-" + mes + "-" + dia;
    events[evento] = fecha_to_add;
    }
    }
    
void print(map<string, string> m) {
    for(const auto& item : m) {
        if(item.second > "0"){
        string fechas = item.second;
        string año_con_zeros, mes_con_zeros, dia_con_zeros;
        Variable_Control_4 = 0;
        for(int i = 0; i < fechas.size(); ++i){
            if(fechas[i] == '-'){
                Variable_Control_4 += 1;
            }
            else if(fechas[i] != '-' && Variable_Control_4 < 1){
                año_con_zeros += fechas[i];
            }
            else if(fechas[i] != '-' && Variable_Control_4 < 2){
                mes_con_zeros += fechas[i];
            }
            else if( Variable_Control_4 == 2){
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
    Evento_a_Eliminar = "";
    Variable_Control_3 = 0;
    for(int i = 0; i < Eventos_a_Eliminar.size(); i++){
        if(Variable_Control_3 == 1){
            Evento_a_Eliminar += Eventos_a_Eliminar[i];
        }
        else if(Eventos_a_Eliminar[i] == ' '){
            Variable_Control_3 += 1;
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
                string date_to_add = Fechas_V[i];
                year_to_add = "";
                month_to_add = "";
                day_to_add = "";
                event_to_add = "";
                guion_to_add_1 =' ';
                guion_to_add_2 =' ';
                espacio_to_add = ' ';
            int p = 0;
            for(int t = 0; t < date_to_add.size(); ++t){
            if(date_to_add[t] == '-'||date_to_add[t] == ' '){
                p += 1;
                if(p == 1){
                    guion_to_add_1 = '-';
                }
                else if(p == 2){
                    guion_to_add_2 = '-';
                }
                else if(p == 3){
                    espacio_to_add = ' ';
                }
            }
            else if(date_to_add[t] != '-' && p < 1){
                year_to_add += date_to_add[t];
            }
            else if(date_to_add[t] != '-' && p < 2){
                month_to_add += date_to_add[t];
            }
            else if(date_to_add[t] != ' ' && p < 3){
                day_to_add += date_to_add[t];
            }
            else if(p == 3){
                event_to_add += date_to_add[t];
            }
            }
            if(year_to_add.size() <= 5 && month2.size() <= 3 && days2.size() <= 3 ){
                add(year_to_add, guion_to_add_1, month_to_add, guion_to_add_2, day_to_add, espacio_to_add, event_to_add);
            }
            }
            
        else if(Comandos_V[i] == "Del"){
            events_to_delet = Fechas_V[i];
            Del_Event(events_to_delet);
            
        }
        else if(Comandos_V[i] == "Find"){
            date_to_find = Fechas_V[i];
            Find(date_to_find);
        }
        else if(Comandos_V[i] == "Print"){
            print(events);
        }
        else if(Comandos_V[i] != "Add" && Comandos_V[i] != "Del" && Comandos_V[i] != "Find" && Comandos_V[i] != "Print" && Comandos_V[i] != "\n"){
        string check_space = Comandos_V[i];
        if(check_space != ""){
        cout << "Unknown command:" << Comandos_V[i] << endl;}}
    }
    }
void BD(){
        cout << "Input 5 to exit" << endl;
        while(getline(cin, Command)){
            if(Command == "5"){
                break;}
            string Comando, Fechas;
            int k = 0;
            for(int i = 0 ; i < Command.size(); ++i){
                if(Command[i] == ' '){
                k +=1;
                    if(k > 0 && k != 1){
                        Fechas += ' ';
                    }
                }
                else if(Command[i] != ' ' && k == 0){
                Comando += Command[i];
                }
                else if(k > 0){
                Fechas += Command[i];
                }
            }
            if( Fechas != ""){
                Date_Check(Fechas);
                if(Variable_Control_2 == date_to_check.size() - 1){
                    Fechas_V.push_back(Fechas);
                }
                else if (Variable_Control_2 != date_to_check.size() - 1){
                    break;
                }
            }
            Comandos_V.push_back(Comando);
            cin.clear();
        }
    }