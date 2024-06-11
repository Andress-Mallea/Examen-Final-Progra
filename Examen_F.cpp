#include "Examen_F.h"

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
                year2 = "";
                month2 = "";
                days2 = "";
                event2 = "";
                guion3 =' ';
                guion4 =' ';
                espacio = ' ';
            int p = 0;
            for(int t = 0; t < date2.size(); ++t){
            if(date2[t] == '-'||date2[t] == ' '){
                p += 1;
                if(p == 1){
                    guion3 = '-';
                }
                else if(p == 2){
                    guion4 = '-';
                }
                else if(p == 3){
                    espacio = ' ';
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
            if(year2.size() <= 5 && month2.size() <= 3 && days2.size() <= 3 ){
                add(year2, guion3, month2, guion4, days2, espacio, event2);
            }
              else{
                for(int y = 0; y < year2.size(); ++y){
                    if(year2[y] < 48 || year2[y] > 57){
                        cout << "Wrong date format: " << year2 + guion3 + month2 + guion4 + days2 << endl;
                             break;
                    }
                 }
            
            for(int y = 0; y < month2.size(); ++y){
                if(month2[y] < 48 || month2[y] > 57){
                    cout << "Wrong date format: " << year2 + guion3 + month2 + guion4 + days2 << endl;
                    break;
                }
            }
            for(int y = 0; y < days2.size(); ++y){
                if(days2[y] < 48 || days2[y] > 57){
                    cout << "Wrong date format: " << year2 + guion3 + month2 + guion4 + days2 << endl;
                    break;
                }
            }
                if(guion3 != 45 || guion4 != 45){
                cout << "Wrong date format: " << year2 + guion3 + month2 + guion4 + days2 << endl;}
            }
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
        else if(Comandos_V[i] != "Add" && Comandos_V[i] != "Del" && Comandos_V[i] != "Find" && Comandos_V[i] != "Print")
        cout << "Unknown command:" << Comandos_V[i] << endl;
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
            Date_Check(Fechas);
            if(Variable_Control_2 == Fechas.size() - 1){
                Fechas_V.push_back(Fechas);
            }
            Comandos_V.push_back(Comando);
            cin.clear();
        }
    }