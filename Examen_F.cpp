#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;
int year, month, day;
string event;
char guio1, guio2;
map<string, string> events;
void add(int año,char guion1, int mes, char guion2, int dia, string evento){
    
    if(mes < 1 || mes > 12){
        cout << "Month value is invalid" << endl;
    }
    else if(dia < 1 || dia > 31){
        cout << "Day value is invalid" << endl;
    }
    else if(mes >=1 && mes <= 12 && dia >=1 && dia <=31 && guion1 == '-' && guion2 == '-'){
        string año_con_zeros = to_string(año);
        string mes_con_zeros = to_string(mes); 
        string dia_con_zeros = to_string(dia);
        if(año_con_zeros.size() == 3){
        string año_con_zeros = "0" + to_string(año);
        }
        else if(año_con_zeros.size() == 2){
        string año_con_zeros = "00" + to_string(año);
        }
        else if(año_con_zeros.size() == 1){
        string año_con_zeros = "000" + to_string(año);
        }
        if(mes_con_zeros.size() ==  1){
        string mes_con_zeros = "0" + to_string(mes);
        }
        if( dia_con_zeros.size() == 1){
        string dia_con_zeros = "0" + to_string(dia);
        }
    string fecha = año_con_zeros + "-" + mes_con_zeros + "-" + dia_con_zeros;
    events[evento] = fecha;
    }
}
void print_reversed_map(map<string, string> m) {
    for(const auto& item : m) {
        cout << item.first << " " << item.second << endl;
    }
}
int main() {
    // Write C++ code here
    cin >> year>>guio1>>month>>guio2>>day>>event;
    add(year, guio1, month, guio2, day, event);
    print_reversed_map(events);
    return 0;
}
