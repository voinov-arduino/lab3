//
//  main.cpp
//  info_lab_1
//
//  Created by Дмитрий Вискунов on 07.10.2022.
//
#include <iostream>
#include <cmath>
#define r 32 // Радиус круга
// Коэффиценты элипса
#define AA 21 // Коэффицент a
#define BB 35 // Коэффицент b
using namespace std;
int main() {
    goto MATH;
MATH:
    string ans;
    int x,x1,x2,x0okr,x0el;
    int y,y1,y2,y0okr,y0el,a,b,c;
    x1 = -23; // Пересечение круга с осью Х
    x2 = 35;  // Пересечение эллипса с осью X
    y2 = -35; // Высота эллипса
    y1 = 29;  // Высота круга
    // вычисляем центр окружности
    x = x1;
    y = 0;
    a = 1;
    b=-2*x;
    y0okr=y1-r;
    c=x*x+(y-y0okr)*(y-y0okr)-r*r;
    x0okr=(-b+sqrt(b*b-4*a*c))/(2*a);
    // вычисляем центр элипса
    x=x2;
    y=0;
    a=1;
    b=-2*x;
    y0el=0;
    x0el=x - AA;
    // вводим значиния X,Y
    cout << "Введите X :" << endl;
    cin >> x;
    cout << "Введите Y :" << endl;
    cin >> y;
    bool U1C = ((x-x0okr)*(x-x0okr)+(y-y0okr)*(y-y0okr)<r*r);
    bool U2E = (((x-x0el)*(x-x0el))/(AA*AA)+((y-y0el)*(y-y0el))/(BB*BB)<1);
    bool U1T = (x < 0 and y < 0);
    bool U2T = (x > 0 and y > 0);
    bool ULND = (((0,7)*x+(4,8))<=y);
    bool ULNU = (((0,7)*x+(4,8))>=y);
    if (U1T and not U2E and U1C and ULND) {
        // Проверяем условие если точка лежит в III четверти то она не лежит в эллипсе, но лежит в круге и ниже чем прямая
        cout << "Точка принадлежит закаршенным областям" << endl;
        cout << "Повторить операцию? Да/Нет" << endl;
        cin >> ans;}
    if (U2T and U1C and U2E and ULNU){
        // Проверяем условие если точка лежит в I четверти, то она лежит в круге и в эллипсе и выше чем прямая
        cout << "Точка принадлежит закрашенным областям" << endl;
        cout << "Повторить операцию? Да/Нет" << endl;
        cin >> ans;
    }else{
        cout << "Точка не принадлежит закрашенным областям" << endl;
        cout << "Повторить операцию? Да/Нет" << endl;
        cin >> ans;}
if(ans == "Да"){ // Проверяем ввод пользователя
    x = 0;
    y = 0;
    goto MATH;} // Возвращаемся в начало
    }
