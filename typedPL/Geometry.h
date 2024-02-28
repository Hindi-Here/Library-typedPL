#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <initializer_list>
#include <array>
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef _USE_CONSTANT_ // директива констант
// МАТЕМАТИКА
#define PI 3.14159265358979323846264338327950288 // число ПИ
#define _PI_2_ 6.283185307179586 // число 2 ПИ
#define I = -1 // мнимая единица
#define _SQRT_2_ 1.41421356237309504880168872420969808 // корень 2
#define _SQRT_3_ 1.73205080756887729352744634150587237 // корень 3
#define _SQRT_5_ 2.23606797749978969 // корень 5
#define E 2.7182818284590452353602874713526625 // число Эйлера (константа Непера)
#define _LG_2_ 1.44269504088896340736 // логарифм 2
#define _LG_10_ 0.434294481903251827651 // логарифм 10
#define _LN_2_ 0.693147180559945309417232121458 // натуральный LOG 2
#define _LN_10_ 2.30258509299404568401799145468 // натуральный LOG 10
#define M 0.57721566490153286060651209008240243 // Маскерони (постоянная Эйлера)
#define LPS 0.66274341934918158097474209710925290 // предел Лапласа
#define _GOLD_R_ 1.61803398874989484820458683436563812 // золотое сечение
// ВЫСШАЯ МАТЕМАТИКА
#define APERI 1.20205690315959428539973816151144999 // Апери
#define KINKLEN 1.2824271291006226368753425688697917 // постоянная Глейшера — Кинкелина
#define CATALAN 0.915965594177219015054603514932384110774 // постоянная Каталана
#define CAENA 0.64341054629 // константа Каэна
#define DOTTY 0.73908513321516064165531208767387340 // число Дотти
#define DICKMAN 0.624329988543550870992936 // постоянная Голубма (Дикмана)
#define SOLDNER 1.451369234883381050283968485892027 // константа Солднера
#define TREFETENA 0.70258 // константа Эмбри (Трефетена)
#define TWINS 0.66016181584686957392781211001455577 // константа простых близнецов
#define TWINS_B 1.902160583104 // константа простых близнецов по Бруно
#define F 4.66920160910299067185320382046620161 // постоянная Фейгенбаума
#define KHINCHIN 2.685452001065 // постоянная Хинчина

#endif

using namespace std;

// Формулы периметров, площадей и объемов фигур

namespace GeometryLIB_Figure {

    // Периметры фигур

    // 1. Треугольник

    inline double Triangle2D_P_MiddleLine(double a_2, double b_2, double c_2) // периметр по средним линиям
    {
        return 2 * a_2 + 2 * b_2 + 2 * c_2;
    }

    inline double Triangle2D_P_TwoSide(double a, double b, double angle) // периметр по двум сторонам и углу
    {
        double angleR = angle * M_PI / 180.0;
        return a + b + sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(angleR));
    }

    inline double Triangle2D_P_Isosceles(double a, double b) // периметр равнобедренного
    {
        return 2 * b + a;
    }

    inline double Triangle2D_P_Isosceles_HeightAndMain(double a, double h) // периметр равнобедренного по высоте и основанию
    {
        return a + 2 * sqrt(pow(a / 2, 2) + pow(h, 2));
    }

    inline double Triangle2D_P_Isosceles_HeightAndSide(double a, double h) // периметр равнобедренного по высоте и сторонам
    {
        return 2 * a + 2 * sqrt(pow(a, 2) - pow(h, 2));
    }



    // 2. Квадрат

    inline double Square2D_P(double a) // периметр по стороне
    {
        return 4 * a;
    }

    inline double Square2D_P_Diagonal(double d) // периметр по диагонале
    {
        return 2 * sqrt(2) * d;
    }

    inline double Square2D_P_FromS(double S) // периметр от площади
    {
        return 4 * sqrt(S);
    }

    inline double Square2D_P_CircleOut(double R) // периметр по описанной окружности
    {
        return 4 * sqrt(2) * pow(R, 2);
    }

    inline double Square2D_P_CircleIn(double r) // периметр по вписанной окружности
    {
        return 8 * r;
    }



    // 3. Прямоугольник

    inline double Rentangle2D_P(double a, double b) // периметр по сторонам
    {
        return 2 * (a + b);
    }

    inline double Rentangle2D_P_Diagonal(double a, double d) // периметр по сторонам
    {
        return 2 * (a + sqrt(pow(d, 2) - pow(a, 2)));
    }



    // 4. Параллелограмм

    inline double Parallelogram2D_P(double a, double b) // периметр по сторонам
    {
        return 2 * (a + b);
    }

    inline double Parallelogram2D_P_Diagonal(double a, double d1, double d2) { // периметр параллелограмма по диагонали
        double sqr = 2 * pow(d1, 2) + 2 * pow(d2, 2) - 4 * pow(a, 2);
        return 2 * a + sqrt(sqr);
    }

    inline double Parallelogram2D_P_Corner(double a, double h, double angle) { // периметр через угол, сторону, высоту
        return 2 * (a + (h / sin(angle * M_PI / 180)));
    }



    // 5. Ромб

    inline double Rhombus2D_P(double a) // периметр ромба
    {
        return 4 * a;
    }

    inline double Rhombus2D_P_Diagonal(double d1, double d2) // периметр ромба по диагонали
    {
        return 2 * sqrt(pow(d1, 2) + pow(d2, 2));
    }



    // 6. Кольцо

    inline double CircleHole2D_P(double r, double R) // периметр кольца
    {
        return 2 * M_PI * (R + r);
    }



    // 7. Многоугольники правильные

    inline double Polygon2D_P(double a, double n) // периметр правильного многоугольника
    {
        return a * n;
    }



    // Площади фигур

    // 1. Треугольник S

    inline double Triangle2D(double a, double h) // площадь треугольника
    {
        return (a * h) / 2;
    }

    inline double Triangle2D_TwoSide(double a, double b, double angle) // формула по 2 сторонам и углу
    {
        double angleR = angle * M_PI / 180.0;
        return (a * b * sin(angleR)) / 2;
    }

    inline double Triangle2D_AllSide(double a, double b, double c) // по трем сторонам
    {
        double P = (a + b + c) / 2;
        return sqrt(P * (P - a) * (P - b) * (P - c));
    }

    inline double Triangle2D_CircleOut(double a, double b, double c, double R) // формула по сторонам и описанной окружности
    {
        return (a * b * c) / (4 * R);
    }

    inline double Triangle2D_CircleIn(double a, double b, double c, double R) // формула по сторонам и вписанной окружности
    {
        double P = (a + b + c) / 2;
        return P * R;
    }

    // Равносторонние треугольники

    inline double Triangle2D_Equilateral_Height(double h) // по высоте равностороннего треугольника
    {
        return pow(h, 2) / sqrt(3);
    }

    inline double Triangle2D_Equilateral_AllSide(double a) // по трем сторонам
    {
        return sqrt(3) * pow(a, 2) / 4;
    }

    inline double Triangle2D_Equilateral_CircleOut(double R) // по сторонам и описанной окружности
    {
        return (3 * sqrt(3) * pow(R, 2)) / 4;
    }

    inline double Triangle2D_Equilateral_CircleIn(double R) // по сторонам и вписанной окружности
    {
        return 3 * sqrt(3) * pow(R, 2);
    }

    // Равнобедренный треугольник

    inline double Triangle2D_Isosceles_AllSide(double a, double b) // по высоте равностороннего треугольника
    {
        return b / 4 * sqrt(4 * pow(a, 2) - pow(b, 2));
    }



    // 2. Квадрат S

    inline double Square2D(double a) // площадь квадрата
    {
        return pow(a, 2);
    }

    inline double Square2D_Diagonal(double d) // площадь квадрата с известной диагональю
    {
        return pow(d, 2) / 2;
    }



    // 3. Прямоугольник S

    inline double Rentangle2D(double a, double b) // площадь прямоугольника
    {
        return a * b;
    }

    inline double Rentangle2D_Diagonal(double a, double d) // площадь прямоугольника с известной диагональю
    {
        return a * sqrt(pow(d, 2) - pow(a, 2));
    }

    inline double Rentangle2D_DiagonalAndCorner(double d, double angle) // площадь прямоугольника с диагональ + уголь
    {
        double angleR = angle * M_PI / 180.0;
        return (pow(d, 2) * sin(angleR)) / 2;
    }



    // 4. Параллелограмм S 

    inline double Parallelogram2D(double a, double h) { // площадь параллелограмма 
        return a * h;
    }

    inline double Parallelogram2D_Corner(double a, double b, double angle) // площадь параллелограмма с известными сторонами и углом
    {
        double angleR = angle * M_PI / 180.0;
        return a * b * sin(angleR);
    }

    inline double Parallelogram2D_DiagonalAndCorner(double d1, double d2, double angle) // площадь параллелограмма с диагональ + уголь
    {
        double angleR = angle * M_PI / 180.0;
        return (d1 * d2 * sin(angleR)) / 2;
    }



    // 5. Ромб S

    inline double Rhombus2D(double a, double h) // площадь ромба
    {
        return a * h;
    }

    inline double Rhombus2D_Corner(double a, double angle) // площадь ромба по стороне и углу
    {
        double angleR = angle * M_PI / 180.0;
        return pow(a, 2) * sin(angleR);
    }

    inline double Rhombus2D_Diagonal(double d1, double d2) // площадь ромба по диагоналям
    {
        return (d1 * d2) / 2;
    }



    // 6. Трапеция S

    inline double Trapezoid2D(double a, double b, double h) // площадь трапеции
    {
        return ((a + b) * h) / 2;
    }

    inline double Trapezoid2D_AllSide(double a, double b, double c, double d) // площадь трапеции по Герону 
    {
        double P = (a + b + c + d) / 2;
        return ((a + b) / abs(a - b)) * sqrt((P - a) * (P - b) * (P - a - c) * (P - a - d));
    }

    inline double Trapezoid2D_Diagonal(double d1, double d2, double angle) // площадь трапеции по диагонали
    {
        double angleR = angle * M_PI / 180.0;
        return (d1 * d2 * sin(angleR)) / 2;
    }

    inline double Trapezoid2D_MiddleLine(double MidLine, double h) // площадь трапеции по средней линии и высоте
    {
        return MidLine * h;
    }



    // 7. Круг S

    inline double Circle2D(double r) // площадь круга по радиусу
    {
        return M_PI * pow(r, 2);
    }

    inline double Circle2D_Diameter(double d) // площадь круга по диаметру
    {
        return M_PI * (pow(d, 2) / 4);
    }

    inline double Circle2D_CircleLength(double L) // площадь круга по длине окружности
    {
        return pow(L, 2) / (4 * M_PI);
    }

    inline double Circle2D_Part(double R, double angle) // площадь только части круга
    {
        return M_PI * pow(R, 2) * (angle / 360);
    }



    // 8. Кольцо S

    inline double CircleHole2D(double r, double R) // площадь кольца
    {
        return M_PI * (pow(R, 2) - pow(r, 2));
    }

    inline double CircleHole2D_Diameter(double d, double D) // площадь кольца через диаметр
    {
        return (M_PI / 4) * (pow(D, 2) - pow(d, 2));
    }



    // 9. Универсальная формула площади любого "правильного" многоугольника

    inline double Polygon2D_Apophemera(double P, double A) // нахождение по апофемере и периметру
    {
        return 0.5 * P * A;
    }

    inline double Polygon2D_Side(double a, double n) // нахождение по стороне и количеству сторон
    {
        return (n * pow(a, 2)) / (4 * tan(M_PI / n));
    }

    inline double Polygon2D_CircleIn(double r, double n) // нахождение по вписанной окружности
    {
        double angle = 180.0 / n;
        double radians = angle * M_PI / 180.0;
        return n * pow(r, 2) * tan(radians);
    }

    inline double Polygon2D_CircleOut(double r, double n) // нахождение по описанной окружности
    {
        double angle = 360.0 / n;
        double radians = angle * M_PI / 180.0;
        return (n * pow(r, 2) / 2) * sin(radians);
    }



    // 10. Шестиугольник S

    inline double Hexagon2D_Side(double a) // площадь шестиугольника по стороне
    {
        return (3 * sqrt(3) * pow(a, 2)) / 2;
    }

    inline double Hexagon2D_CircleOut(double R) // площадь шестиугольника по описанной окружности
    {
        return (3 * sqrt(3) * pow(R, 2)) / 2;
    }

    inline double Hexagon2D_CircleIn(double R) // площадь шестиугольника по вписанной окружности
    {
        return sqrt(3) * pow(R, 2);
    }

    inline double Hexagon2D_Diagonal(double D) // площадь шестиугольника по диагонали
    {
        return (3 * sqrt(3) * pow(D, 2)) / 8;
    }

    inline double Hexagon2D_ShortDiagonal(double D) // площадь шестиугольника по короткой диагонали
    {
        return (sqrt(3) * pow(D, 2)) / 2;
    }

    inline double Hexagon2D_Perimetr(double P) // площадь шестиугольника по периметру
    {
        return (3 * sqrt(3) * pow(P / 6, 2)) / 2;
    }



    // 11. Восьмиугольник S

    inline double Octagon2D_Side(double a) // площадь восьмиугольника по стороне
    {
        return 2 * pow(a, 2) * (sqrt(2) + 1);
    }

    inline double Octagon2D_CircleOut(double R) // площадь восьмиугольника по описанной окружности
    {
        return 2 * pow(R, 2) * sqrt(2);
    }

    inline double Octagon2D_CircleIn(double R) // площадь восьмиугольника по вписанной окружности
    {
        return 8 * pow(R, 2) * (sqrt(2) - 1);
    }



    // Объемы

    // 1. Треугольники

    inline double Triangle3D(double S, double h) // объем треугольника (тетраэдр)
    {
        return (S * h) / 3;
    }

    inline double Triangle3D_Equilateral(double a) // объем равностороннего треугольника (правильный тетраэдр)
    {
        return sqrt(2) * pow(a, 3) / 12;
    }

    // 2. Конусы

    inline double Cone3D(double r, double h) // объем конуса
    {
        return M_PI * pow(r, 2) * h / 3;
    }

    inline double Cone3D_Part(double R1, double R2, double h) // объем усеченного конуса
    {
        double fig = h * (pow(R1, 2) + R1 * R2 + pow(R2, 2));
        return (M_PI * fig) / 3;
    }

    // 3. Отдельные фигуры 

    inline double Square3D(double a) // объем квадрата (куб)
    {
        return pow(a, 3);
    }

    inline double Rentangle3D(double a, double b, double h) // объем прямоугольника (прямоугольный параллелипипед)
    {
        return a * b * h;
    }

    inline double Parallelogram3D(double s, double h) { // объем параллелограмма (паралеллипипед)
        return s * h;
    }

    inline double Cilinder3D(double r, double h) // объем цилиндра
    {
        return M_PI * pow(r, 2) * h;
    }

    inline double Hexagon3D(double a, double h) // объем шестиугольника по стороне
    {
        return 3 * sqrt(3) / 2 * pow(a, 2) * h;
    }

    // 4. Круг и кольцо

    inline double Circle3D(double r) // объем круга по радиусу (шар)
    {
        return (4 * (M_PI * pow(r, 3))) / 3;
    }

    inline double Circle3D_Diameter(double d) // объем круга по диаметру (шар)
    {
        return M_PI * (pow(d, 3)) / 6;
    }

    inline double Circle3D_CircleLength(double L) // объем круга по длина окружности (шар)
    {
        return pow(L, 3) / 6 * pow(M_PI, 2);
    }

    inline double CircleHole3D(double h, double R) // объем кольца
    {
        return M_PI * pow(R, 2) * h;
    }

    // 5. Пирамиды

    inline double Pyramid3x3D(double a, double h)// объем пирамиды на 3 угла
    {
        return (h * pow(a, 2)) / (4 * sqrt(3));
    }

    inline double Pyramid4x3D(double a, double h) // объем пирамиды на 4 угла
    {
        return (pow(a, 2) * h) / 3;
    }

    inline double Pyramid5x3D(double a, double h) // объем пирамиды на 6 углов
    {
        double baseArea = (5 * a * a) / (4 * tan(M_PI / 5));
        double volume = (baseArea * h) / 3;
        return volume;
    }

    inline double Pyramid6x3D(double a, double h) // объем пирамиды на 6 углов
    {
        return sqrt(3) / 2 * h * pow(a, 2);
    }

    inline double PyramidNx3D(double a, double h, double count_angle) //N угольная пирамида
    {
        double angleR = 180.0 * M_PI / 180.0;
        return (count_angle * h * pow(a, 2)) / (12 * tan(angleR / count_angle));
    }

    // 6. Призмы

    inline double Prism3x3D(double a, double h) // объем треугольной призмы
    {
        return sqrt(3) / 4 * pow(a, 2) * h;
    }

    inline double Prism4x3D(double a, double h) // объем призмы на 4 угла
    {
        return pow(a, 2) * h;
    }

    inline double Prism5x3D(double a, double h) // объем призмы на 5 углов
    {
        return (5 * a * a * h) / (4 * tan(M_PI / 5));
    }

    inline double Prism6x3D(double a, double h) // объем призмы на 6 углов
    {
        return (sqrt(3) * 3 / 2) * pow(a, 2) * h;
    }



    // Площадь поверхности объемных фигур

    inline double Square3D_S_Side(double a) // площадь поверхности куба по стороне
    {
        return 6 * pow(a, 2);
    }

    inline double Square3D_S_Diagonal(double d) // площадь куба по диагонали
    {
        return 6 * d / sqrt(2);
    }

    inline double Rentangle3D_S_Side(double a, double b, double h) // площадь поверхности прямоугольника
    {
        return 2 * a * b + a * h + b * h;
    }

    inline double Circle3D_S_Radius(double R) // площадь поверхности шара по радиусу
    {
        return 4 * M_PI * pow(R, 2);
    }

    inline double Circle3D_S_Diagonal(double D) // площадь поверхности шара по диагонали
    {
        return M_PI * pow(D, 2);
    }

    inline double Cone3D_SPart(double R, double l) // площади поверхности части конуса
    {
        return M_PI * R * l;
    }

    inline double Cone3D_SFull(double R, double l) // площади поверхности конуса
    {
        return M_PI * R * (R + l);
    }

    inline double Cilinder3D_SPart(double R, double h) // площадь поверхности части цилиндра
    {
        return 2 * M_PI * R * h;
    }

    inline double Cilinder3D_SFull(double R, double h) // площадь поверхности части цилиндра
    {
        return 2 * M_PI * R * (R + h);
    }



    // Иные формулы:

    // длина окружности

    inline double LengthCircle_Radius(double R) // по радиусу
    {
        return 2 * M_PI * R;
    }

    inline double LengthCircle_Diametr(double D) // по диаметру
    {
        return M_PI * D;
    }

    inline double LengthCircle_FromS(double S) // по площади круга
    {
        return sqrt(4 * M_PI * S);
    }



    // ALL FIGURE

    inline double Figure2D_Points(initializer_list<double> args) { // площадь любой фигуры по точкам
        std::vector<double> points(args);

        // Проверка, что количество точек вершин кратно 2
        if (points.size() % 2 != 0) {
            return 0;
        }

        // Разделение вектора на координаты x и y
        vector<double> x;
        vector<double> y;
        for (int i = 0; i < points.size(); i++) {
            if (i % 2 == 0) {
                x.push_back(points[i]);
            }
            else {
                y.push_back(points[i]);
            }
        }

        // Вычисление площади с использованием формулы Гаусса
        double area = 0.0;
        for (int i = 0; i < x.size(); i++) {
            area += (x[i] * y[(static_cast<unsigned long long>(i) + 1) % x.size()] - 
                x[(static_cast<unsigned long long>(i) + 1) % x.size()] * y[i]);
        }
        area /= 2.0;

        return abs(area);
    }

    inline double Figure2D_Sides(initializer_list<double> args) { // площадь любой фигуры по площади
        vector<double> sides(args);

        // Проверка, что количество точек равно или больше 3
        if (sides.size() < 3) {
            return 0;
        }

        double P(0);
        for (int i = 0; i < sides.size(); i++)
            P += sides[i];

        P /= 2; // нахождение полупериметра

        double area = P - sides[0];
        for (int i = 1; i < sides.size(); i++) {
            area *= (P - sides[i]);
        }

        return sqrt(area);
    }

    vector<double> ProgressionA(double firstElem, int stepCount, double stepValue) {
        vector<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem += stepValue;
            arr.push_back(firstElem);
        }
        return arr;
    }

    vector<double> ProgressionG(double firstElem, int stepCount, double stepValue) {
        vector<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem *= stepValue;
            arr.push_back(firstElem);
        }
        return arr;
    }

}

namespace GeometryLIB_Expression {

    // Vector expression

    double Vector_Length(double vecLen1, double vecLen2, double angle) { // длина вектора по длинам векторов и углу
        double radians= 180.0 * M_PI / 180.0; 
        return pow(vecLen1, 2) + pow(vecLen2, 2) - 2 * vecLen1 * vecLen2 * cos(radians);
    }

    double Vector_ScalarMultiplication (double vecLen1, double vecLen2, double angle) { // длина вектора по длинам векторов и углу
        double radians = 180.0 * M_PI / 180.0;
        return vecLen1 * vecLen2 * cos(radians);
    }

    // Класс векторов

    class VectorExpression {

    private:
        double x = NULL, y = NULL, z = NULL;
    public:
        VectorExpression(array<double,3> arg) { x = arg[0]; y = arg[1]; z = arg[2]; }
        VectorExpression(double x, double y, double z) : x(x), y(y), z(z) {  }
        VectorExpression(double x, double y) : x(x), y(y) {  }

        double Get_X() const {
            return x;
        }

        double Get_Y() const {
            return y;
        }

        double Get_Z() const {
            return z;
        }

        string Get_Expression() const {
            stringstream ss;
            if(z != NULL)
                ss << "{" << x << "," << y << "," << z << "}";
            else
                ss << "{" << x << "," << y << "}";

            return ss.str();
        }
         
        double Vector_Length() { // длина вектора
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
        }

        double Vector_Length(VectorExpression& newVector) { // длина по точкам начала и конца
            return sqrt(pow(newVector.x - x, 2) + pow(newVector.y - y, 2) + pow(newVector.z - z, 2));
        }

        double Get_Cos(VectorExpression& newVector) { // получить угол косинуса
            double first = x * newVector.x + y * newVector.y + z * newVector.z;
            double second = sqrt(pow(x, 2) + pow(y,2) + pow(x,2)) * sqrt(pow(newVector.x,2) + pow(newVector.y,2) + pow(newVector.z,2));
            return first / second;
        }

        double Triangle2D_VectorMultiplication(VectorExpression& newVector) const { // площадь по векторному умножению
            double X = y * newVector.z - z * newVector.y;
            double Y = (x * newVector.z - z * newVector.x) * -1;
            double Z = x * newVector.y - y * newVector.x;
            return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2)) * 0.5;
        }

        bool Equals(VectorExpression& newVector) const{ // сравнение векторов
            bool flag = false;
            if (x == newVector.x && y == newVector.y && z == newVector.z)
                flag = true;

            return flag;
        }

        bool EqualsMin(VectorExpression& newVector) const {
            bool flag = false;
            double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            if (length < newVector.Vector_Length())
                flag = true;

            return flag;
        }

        bool EqualsMax(VectorExpression& newVector) const {
            bool flag = false;
            double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
            if (length > newVector.Vector_Length())
                flag = true;

            return flag;
        }



        VectorExpression operator+=(VectorExpression& newVector) {
            return VectorExpression(x += newVector.x, y += newVector.y, z += newVector.z);
        }

        VectorExpression operator+(VectorExpression& newVector) {
            return VectorExpression(x + newVector.x, y + newVector.y, z + newVector.z);
        }

        VectorExpression operator-(VectorExpression& newVector) {
            return VectorExpression(x - newVector.x, y - newVector.y, z - newVector.z);
        }

        VectorExpression operator*(VectorExpression& newVector) {
            return VectorExpression(x * newVector.x, y * newVector.y, z * newVector.z);
        }

        VectorExpression operator*(double K) {
            return VectorExpression(x * K, y * K, z * K);
        }



        VectorExpression Vector_Addition(VectorExpression& newVector) { // +
            return VectorExpression(x + newVector.x, y + newVector.y, z + newVector.z);
        }

        VectorExpression Vector_Substract(VectorExpression& newVector) { // -
            return VectorExpression(x - newVector.x, y - newVector.y, z - newVector.z);
        }

        VectorExpression Vector_Multiplication(VectorExpression& newVector) { // *
            return VectorExpression(x * newVector.x, y * newVector.y, z * newVector.z);
        }

        VectorExpression Vector_Multiplication(double K) { // * на число
            return VectorExpression(x * K, y * K, z * K);
        }

        VectorExpression Vector_VectorMultiplication(VectorExpression& newVector) { // векторное произведение
            return VectorExpression(y * newVector.z - z * newVector.y, 
                                   (x * newVector.z - z * newVector.x) * -1, 
                                    x * newVector.y - y * newVector.x);
        }

    };

    // Complex expression

    class ComplexExpression {
    private:
        double a, b;
    public:
        ComplexExpression(double a, double b) : a(a), b(b) {};

        ComplexExpression operator+=(ComplexExpression& CPL) {
            return ComplexExpression(a += CPL.a, b += CPL.b);
        }
        ComplexExpression operator+(ComplexExpression& CPL) {
            return ComplexExpression(a + CPL.a, b + CPL.b);
        }
        ComplexExpression operator-(ComplexExpression& CPL) {
            return ComplexExpression(a - CPL.a, b - CPL.b);
        }
        ComplexExpression operator*(ComplexExpression& CPL) {
            return ComplexExpression((a * CPL.a) - (b * CPL.b), (a * CPL.b) + (b * CPL.a));
        }
        ComplexExpression operator/(ComplexExpression& CPL) {
            return ComplexExpression((a + b) * (CPL.a - CPL.b), (CPL.a + CPL.b) * (CPL.a - CPL.b));
        }

        ComplexExpression Complex_Addition(ComplexExpression& CPL) {
            return ComplexExpression(a + CPL.a, b + CPL.b);
        }
        ComplexExpression Complex_Substract(ComplexExpression& CPL) {
            return ComplexExpression(a - CPL.a, b - CPL.b);
        }
        ComplexExpression Complex_Multpiplication(ComplexExpression& CPL) {
            return ComplexExpression((a * CPL.a) - (b * CPL.b), (a * CPL.b) + (b * CPL.a));
        }
        ComplexExpression Complex_Divide(ComplexExpression& CPL) {
            return ComplexExpression((a + b) * (CPL.a - CPL.b), (CPL.a + CPL.b) * (CPL.a - CPL.b));
        }

        double Get_A() const {
            return a;
        }

        double Get_B() const {
            return b;
        }

        string Get_Expression() const {
            stringstream ss;
            if (b < 0)
                ss << a << " - " << b * -1 << "i";
            else
                ss << a << " + " << b << "i";

            return ss.str();
        }
    };

}