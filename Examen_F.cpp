// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;
int year, month, day, events_deleted;
int Salida = 0;
string event, date, deleted_date, deleted_event, events_to_delet;
char guio1, guio2;
map<string, string> events;
map<string, string> :: iterator it ;
map<string, string> :: iterator it2 ;
vector<string> Events;
void add(int año,char guion1, int mes, char guion2, int dia, string evento){
    if(mes < 1 || mes > 12){
        cout << "Month value is invalid: " + to_string(mes) << endl;
    }
    else if(dia < 1 || dia > 31){
        cout << "Day value is invalid: " + to_string(dia) << endl;
    }
    else if(mes >=1 && mes <= 12 && dia >=1 && dia <=31 && guion1 == '-' && guion2 == '-'){
        string años = to_string(año);
        string meses = to_string(mes); 
        string dias = to_string(dia);
    string fecha = años + "-" + meses + "-" + dias;
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
        cout << año_con_zeros << "-" << mes_con_zeros << "-" << dia_con_zeros << " " << item.first << endl;
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
int main() {
    // Write C++ code here
    cout << "Elija un comado a ingresar"<< endl;
    cout << "1.- Add Fecha de evento" << endl;
    cout << "2.- Delete Fecha de evento" << endl;
    cout << "3.- Delete varias fechas de eventos"<< endl;
    cout << "4.- Find Fecha de evento" << endl;
    cout << "5.- Print Mostrar las fechas de eventos" << endl;
    cout << "6.- Exit" << endl;
    int comando;
    while(comando != 6){
        cin.ignore(10, '\n');
    cin >> comando;
    if(comando == 6){
            break;
        }
    switch(comando){
        case 1:
        cout << "Add ";
        cin >> year>>guio1>>month>>guio2>>day>>event;
        add(year, guio1, month, guio2, day, event);
        break;
        case 2:
        cout << "Del ";
        cin.ignore();
        getline(cin, events_to_delet);
        Del_Event(events_to_delet);
        break;
        case 3:
        cout << "Del ";
        break;
        case 4:
        cout << "Find ";
        cin >> date;
        Find(date);
        break;
        case 5:
            cout << "Print" << endl;
            print(events);
            break;
        default:
        cout << "Unknown command: " << comando << endl;
            
    }
    }
    return 0;
}