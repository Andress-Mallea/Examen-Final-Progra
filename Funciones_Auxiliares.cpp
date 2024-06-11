
#include "Examen_F.h"

void Date_Check(string a){
    int Variable_Control_1 = 0;
    for(int o = 0; o <= a.size(); ++o){
        if(a[0] == 45){
             Year_Prueba += a[0];
            for(int i =1; i < a.size() ; ++i){
                if(a[i] < 48 && a[i] > 57 && a[i] != '-'){
                    cout << "Wrong date format: " << a << endl;
                    Variable_Control_2 -= 1;
                    Year_Prueba = "";
                    break;
                }
                else if(a[i] != '-' && Variable_Control_1 == 0 && a[i] >= 48 && a[i] <=57){
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
        else if(a[0] == 43){
             Year_Prueba += a[0];
            for(int i =1; i < a.size() ; ++i){
                if(a[i] < 48 && a[i] > 57 && a[i] != '-'){
                    cout << "Wrong date format: " << a << endl;
                    Year_Prueba = "";
                    Variable_Control_2 -= 1;
                    break;
                }
                else if(a[i] != '-' && Variable_Control_1 == 0 && a[i] >= 48 && a[i] <=57){
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
        else if(a[o] >= 48 && a[o] <=57){
            Year_Prueba += a[0];
            for(int i =1; i < a.size() ; ++i){
                if(a[i] < 48 && a[i] > 57 && a[i] != '-'){
                    cout << "Wrong date format: " << a << endl;
                    Year_Prueba = "";
                    Variable_Control_2 -= 1;
                    break;
                }
                else if(a[i] != '-' && Variable_Control_1 == 0 && a[i] >= 48 && a[i] <=57){
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
        else if(a[0] < 48 || a[0] > 57){
            cout << "Wrong date format: " << a << endl;
            Variable_Control_2 -= 1;
            break;
        }
        if(Variable_Control_1 == 1){
            o += 1;
            if(a[o] >= 48 && a[o] <=57){
                for(int i = o; i < a.size() ; ++i){
                        if(a[i] < 48 && a[i] > 57 && a[i] != '-' && Variable_Control_1 == 1){
                            cout << "Wrong date format: " << a << endl;
                            Month_Prueba = "";
                            Variable_Control_2 -= 1;
                            break;
                        }
                        else if(a[i] != '-' && Variable_Control_1 == 1 && a[i] >= 48 && a[i] <=57){
                            Month_Prueba += a[i];
                            Variable_Control_2 += 1;
                            ++o;
                        }
                        else if(a[i] == '-' && Variable_Control_1 == 1){
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
            if(a[o] >= 48 && a[o] <=57){
                for(int i = o; i <= a.size() ; ++i){
                    if(a[i] < 48 && a[i] > 57 && a[i] != '-'){
                        cout << "Wrong date format: " << a << endl;
                        Day_Prueba = "";
                        Variable_Control_2 -= 1;
                        break;
                    }
                    else if(a[i] != '-' && Variable_Control_1 == 2 && a[i] >= 48 && a[i] <=57){
                        Day_Prueba += a[i];
                        Variable_Control_2 += 1;
                        ++o;
                    }
                    else if(a[i] == ' '){
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