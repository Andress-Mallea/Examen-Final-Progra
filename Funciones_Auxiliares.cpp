
#include "Examen_F.h"

void Date_Check(string a){
    date_to_check = "";
    string Year_Prueba,  Month_Prueba, Day_Prueba, event_Prueba;
    Variable_Control_2 = 0;
    Variable_Control_5 = 0;
    for(int i = 0; i < a.size(); i++){
        if(Variable_Control_5 == 0){
            date_to_check += a[i];
        }
        if(a[i] == ' '){
            Variable_Control_5 += 1;
        }
    }
    Variable_Control_1 = 0;
    for(int o = 0; o <= date_to_check.size(); ++o){
        if(date_to_check[0] == 45){
             Year_Prueba += date_to_check[0];
            for(int i =1; i < date_to_check.size() ; ++i){
                if(date_to_check[i] < 48 && date_to_check[i] > 57 && date_to_check[i] != '-'){
                    cout << "Wrong date format: " << date_to_check << endl;
                    Variable_Control_2 -= 1;
                    Year_Prueba = "";
                    break;
                }
                else if(date_to_check[i] != '-' && Variable_Control_1 == 0 && date_to_check[i] >= 48 && date_to_check[i] <=57){
                    Year_Prueba += date_to_check[i];
                    Variable_Control_2 += 1;
                    ++o;
                }
                 else if(date_to_check[i] == '-' && Variable_Control_1 == 0){
                    Variable_Control_1 += 1;
                    Variable_Control_2 += 1;
                    ++o;
                }
            }
        }
        else if(date_to_check[0] == 43){
             Year_Prueba += date_to_check[0];
            for(int i =1; i < date_to_check.size() ; ++i){
                if(date_to_check[i] < 48 && date_to_check[i] > 57 && date_to_check[i] != '-'){
                    cout << "Wrong date format: " << date_to_check << endl;
                    Year_Prueba = "";
                    Variable_Control_2 -= 1;
                    break;
                }
                else if(date_to_check[i] != '-' && Variable_Control_1 == 0 && a[i] >= 48 && a[i] <=57){
                    Year_Prueba += a[i];
                    Variable_Control_2 += 1;
                    ++o;
                }
                 else if(a[i] == '-' && Variable_Control_1 == 0){
                    Variable_Control_1 += 1;
                    Variable_Control_2 += 1;
                    ++o;
                }
            }
        }
        else if(date_to_check[o] >= 48 && date_to_check[o] <=57){
            Year_Prueba += date_to_check[0];
            for(int i =1; i < date_to_check.size() ; ++i){
                if(date_to_check[i] < 48 && date_to_check[i] > 57 && date_to_check[i] != '-'){
                    cout << "Wrong date format: " << date_to_check << endl;
                    Year_Prueba = "";
                    Variable_Control_2 -= 1;
                    break;
                }
                else if(date_to_check[i] != '-' && Variable_Control_1 == 0 && date_to_check[i] >= 48 && date_to_check[i] <=57){
                    Year_Prueba += date_to_check[i];
                    Variable_Control_2 += 1;
                    ++o;
                }
                else if(date_to_check[i] == '-' && Variable_Control_1 == 0){
                    Variable_Control_1 += 1;
                    Variable_Control_2 += 1;
                    ++o;
                }
            }
        }
        else if(date_to_check[0] < 48 || date_to_check[0] > 57){
            cout << "Wrong date format: " << date_to_check << endl;
            Variable_Control_2 -= 1;
            break;
        }
        if(Variable_Control_1 == 1){
            o += 1;
            if(date_to_check[o] >= 48 && date_to_check[o] <=57){
                for(int i = o; i < date_to_check.size() ; ++i){
                        if(date_to_check[i] < 48 && date_to_check[i] > 57 && date_to_check[i] != '-' && Variable_Control_1 == 1){
                            cout << "Wrong date format: " << date_to_check << endl;
                            Month_Prueba = "";
                            Variable_Control_2 -= 1;
                            break;
                        }
                        else if(date_to_check[i] != '-' && Variable_Control_1 == 1 && date_to_check[i] >= 48 && date_to_check[i] <=57){
                            Month_Prueba += date_to_check[i];
                            Variable_Control_2 += 1;
                            ++o;
                        }
                        else if(date_to_check[i] == '-' && Variable_Control_1 == 1){
                            Variable_Control_1 += 1;
                            Variable_Control_2 += 1;
                            ++o;
                        }
                    }
                    int Month_Prueba2 = stoi(Month_Prueba);
                    if(Month_Prueba2 <= 0 || Month_Prueba2 > 12){
                        cout << "Month value is invalid: " << Month_Prueba << endl;
                        Variable_Control_2 -= 1;
                        break;    
                    }
            }
            else if (Variable_Control_1 == 1){
                cout << "Wrong date format: " << a << endl;
                Variable_Control_2 -= 1;
                break;
            }
        }
        if (Variable_Control_1 == 2)
        {
            if(date_to_check[o] >= 48 && date_to_check[o] <=57){
                for(int i = o; i <= date_to_check.size() ; ++i){
                    if(date_to_check[i] < 48 && date_to_check[i] > 57 && date_to_check[i] != '-'){
                        cout << "Wrong date format: " << a << endl;
                        Day_Prueba = "";
                        Variable_Control_2 -= 1;
                        break;
                    }
                    else if(date_to_check[i] != '-' && Variable_Control_1 == 2 && date_to_check[i] >= 48 && date_to_check[i] <=57){
                        Day_Prueba += date_to_check[i];
                        Variable_Control_2 += 1;
                        ++o;
                    }
                    else if(date_to_check[i] == ' '){
                        Variable_Control_1 += 1;
                        Variable_Control_2 += 1;
                        ++o;
                    }
                }
                int Day_Prueba2 = stoi(Day_Prueba);
                if(Day_Prueba2 <= 0 || Day_Prueba2 > 31){
                    cout << "Day value is invalid: " << Day_Prueba << endl;
                    Variable_Control_2 -= 1;
                    break;
                }
            }
            else{
                cout << "Wrong date format: " << a << endl;
                Variable_Control_2 -= 1;
                break;
            }
        }
        
    }
    
}