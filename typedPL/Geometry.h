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

#ifdef _USE_CONSTANT_ // ��������� ��������
// ����������
#define PI 3.14159265358979323846264338327950288 // ����� ��
#define _PI_2_ 6.283185307179586 // ����� 2 ��
#define I = -1 // ������ �������
#define _SQRT_2_ 1.41421356237309504880168872420969808 // ������ 2
#define _SQRT_3_ 1.73205080756887729352744634150587237 // ������ 3
#define _SQRT_5_ 2.23606797749978969 // ������ 5
#define E 2.7182818284590452353602874713526625 // ����� ������ (��������� ������)
#define _LG_2_ 1.44269504088896340736 // �������� 2
#define _LG_10_ 0.434294481903251827651 // �������� 10
#define _LN_2_ 0.693147180559945309417232121458 // ����������� LOG 2
#define _LN_10_ 2.30258509299404568401799145468 // ����������� LOG 10
#define M 0.57721566490153286060651209008240243 // ��������� (���������� ������)
#define LPS 0.66274341934918158097474209710925290 // ������ �������
#define _GOLD_R_ 1.61803398874989484820458683436563812 // ������� �������
// ������ ����������
#define APERI 1.20205690315959428539973816151144999 // �����
#define KINKLEN 1.2824271291006226368753425688697917 // ���������� �������� � ���������
#define CATALAN 0.915965594177219015054603514932384110774 // ���������� ��������
#define CAENA 0.64341054629 // ��������� �����
#define DOTTY 0.73908513321516064165531208767387340 // ����� �����
#define DICKMAN 0.624329988543550870992936 // ���������� ������� (�������)
#define SOLDNER 1.451369234883381050283968485892027 // ��������� ��������
#define TREFETENA 0.70258 // ��������� ����� (���������)
#define TWINS 0.66016181584686957392781211001455577 // ��������� ������� ���������
#define TWINS_B 1.902160583104 // ��������� ������� ��������� �� �����
#define F 4.66920160910299067185320382046620161 // ���������� �����������
#define KHINCHIN 2.685452001065 // ���������� �������

#endif

using namespace std;

// ������� ����������, �������� � ������� �����

namespace GeometryLIB_Figure {

    // ��������� �����

    // 1. �����������

    inline double Triangle2D_P_MiddleLine(double a_2, double b_2, double c_2) // �������� �� ������� ������
    {
        return 2 * a_2 + 2 * b_2 + 2 * c_2;
    }

    inline double Triangle2D_P_TwoSide(double a, double b, double angle) // �������� �� ���� �������� � ����
    {
        double angleR = angle * M_PI / 180.0;
        return a + b + sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(angleR));
    }

    inline double Triangle2D_P_Isosceles(double a, double b) // �������� ���������������
    {
        return 2 * b + a;
    }

    inline double Triangle2D_P_Isosceles_HeightAndMain(double a, double h) // �������� ��������������� �� ������ � ���������
    {
        return a + 2 * sqrt(pow(a / 2, 2) + pow(h, 2));
    }

    inline double Triangle2D_P_Isosceles_HeightAndSide(double a, double h) // �������� ��������������� �� ������ � ��������
    {
        return 2 * a + 2 * sqrt(pow(a, 2) - pow(h, 2));
    }



    // 2. �������

    inline double Square2D_P(double a) // �������� �� �������
    {
        return 4 * a;
    }

    inline double Square2D_P_Diagonal(double d) // �������� �� ���������
    {
        return 2 * sqrt(2) * d;
    }

    inline double Square2D_P_FromS(double S) // �������� �� �������
    {
        return 4 * sqrt(S);
    }

    inline double Square2D_P_CircleOut(double R) // �������� �� ��������� ����������
    {
        return 4 * sqrt(2) * pow(R, 2);
    }

    inline double Square2D_P_CircleIn(double r) // �������� �� ��������� ����������
    {
        return 8 * r;
    }



    // 3. �������������

    inline double Rentangle2D_P(double a, double b) // �������� �� ��������
    {
        return 2 * (a + b);
    }

    inline double Rentangle2D_P_Diagonal(double a, double d) // �������� �� ��������
    {
        return 2 * (a + sqrt(pow(d, 2) - pow(a, 2)));
    }



    // 4. ��������������

    inline double Parallelogram2D_P(double a, double b) // �������� �� ��������
    {
        return 2 * (a + b);
    }

    inline double Parallelogram2D_P_Diagonal(double a, double d1, double d2) { // �������� ��������������� �� ���������
        double sqr = 2 * pow(d1, 2) + 2 * pow(d2, 2) - 4 * pow(a, 2);
        return 2 * a + sqrt(sqr);
    }

    inline double Parallelogram2D_P_Corner(double a, double h, double angle) { // �������� ����� ����, �������, ������
        return 2 * (a + (h / sin(angle * M_PI / 180)));
    }



    // 5. ����

    inline double Rhombus2D_P(double a) // �������� �����
    {
        return 4 * a;
    }

    inline double Rhombus2D_P_Diagonal(double d1, double d2) // �������� ����� �� ���������
    {
        return 2 * sqrt(pow(d1, 2) + pow(d2, 2));
    }



    // 6. ������

    inline double CircleHole2D_P(double r, double R) // �������� ������
    {
        return 2 * M_PI * (R + r);
    }



    // 7. �������������� ����������

    inline double Polygon2D_P(double a, double n) // �������� ����������� ��������������
    {
        return a * n;
    }



    // ������� �����

    // 1. ����������� S

    inline double Triangle2D(double a, double h) // ������� ������������
    {
        return (a * h) / 2;
    }

    inline double Triangle2D_TwoSide(double a, double b, double angle) // ������� �� 2 �������� � ����
    {
        double angleR = angle * M_PI / 180.0;
        return (a * b * sin(angleR)) / 2;
    }

    inline double Triangle2D_AllSide(double a, double b, double c) // �� ���� ��������
    {
        double P = (a + b + c) / 2;
        return sqrt(P * (P - a) * (P - b) * (P - c));
    }

    inline double Triangle2D_CircleOut(double a, double b, double c, double R) // ������� �� �������� � ��������� ����������
    {
        return (a * b * c) / (4 * R);
    }

    inline double Triangle2D_CircleIn(double a, double b, double c, double R) // ������� �� �������� � ��������� ����������
    {
        double P = (a + b + c) / 2;
        return P * R;
    }

    // �������������� ������������

    inline double Triangle2D_Equilateral_Height(double h) // �� ������ ��������������� ������������
    {
        return pow(h, 2) / sqrt(3);
    }

    inline double Triangle2D_Equilateral_AllSide(double a) // �� ���� ��������
    {
        return sqrt(3) * pow(a, 2) / 4;
    }

    inline double Triangle2D_Equilateral_CircleOut(double R) // �� �������� � ��������� ����������
    {
        return (3 * sqrt(3) * pow(R, 2)) / 4;
    }

    inline double Triangle2D_Equilateral_CircleIn(double R) // �� �������� � ��������� ����������
    {
        return 3 * sqrt(3) * pow(R, 2);
    }

    // �������������� �����������

    inline double Triangle2D_Isosceles_AllSide(double a, double b) // �� ������ ��������������� ������������
    {
        return b / 4 * sqrt(4 * pow(a, 2) - pow(b, 2));
    }



    // 2. ������� S

    inline double Square2D(double a) // ������� ��������
    {
        return pow(a, 2);
    }

    inline double Square2D_Diagonal(double d) // ������� �������� � ��������� ����������
    {
        return pow(d, 2) / 2;
    }



    // 3. ������������� S

    inline double Rentangle2D(double a, double b) // ������� ��������������
    {
        return a * b;
    }

    inline double Rentangle2D_Diagonal(double a, double d) // ������� �������������� � ��������� ����������
    {
        return a * sqrt(pow(d, 2) - pow(a, 2));
    }

    inline double Rentangle2D_DiagonalAndCorner(double d, double angle) // ������� �������������� � ��������� + �����
    {
        double angleR = angle * M_PI / 180.0;
        return (pow(d, 2) * sin(angleR)) / 2;
    }



    // 4. �������������� S 

    inline double Parallelogram2D(double a, double h) { // ������� ��������������� 
        return a * h;
    }

    inline double Parallelogram2D_Corner(double a, double b, double angle) // ������� ��������������� � ���������� ��������� � �����
    {
        double angleR = angle * M_PI / 180.0;
        return a * b * sin(angleR);
    }

    inline double Parallelogram2D_DiagonalAndCorner(double d1, double d2, double angle) // ������� ��������������� � ��������� + �����
    {
        double angleR = angle * M_PI / 180.0;
        return (d1 * d2 * sin(angleR)) / 2;
    }



    // 5. ���� S

    inline double Rhombus2D(double a, double h) // ������� �����
    {
        return a * h;
    }

    inline double Rhombus2D_Corner(double a, double angle) // ������� ����� �� ������� � ����
    {
        double angleR = angle * M_PI / 180.0;
        return pow(a, 2) * sin(angleR);
    }

    inline double Rhombus2D_Diagonal(double d1, double d2) // ������� ����� �� ����������
    {
        return (d1 * d2) / 2;
    }



    // 6. �������� S

    inline double Trapezoid2D(double a, double b, double h) // ������� ��������
    {
        return ((a + b) * h) / 2;
    }

    inline double Trapezoid2D_AllSide(double a, double b, double c, double d) // ������� �������� �� ������ 
    {
        double P = (a + b + c + d) / 2;
        return ((a + b) / abs(a - b)) * sqrt((P - a) * (P - b) * (P - a - c) * (P - a - d));
    }

    inline double Trapezoid2D_Diagonal(double d1, double d2, double angle) // ������� �������� �� ���������
    {
        double angleR = angle * M_PI / 180.0;
        return (d1 * d2 * sin(angleR)) / 2;
    }

    inline double Trapezoid2D_MiddleLine(double MidLine, double h) // ������� �������� �� ������� ����� � ������
    {
        return MidLine * h;
    }



    // 7. ���� S

    inline double Circle2D(double r) // ������� ����� �� �������
    {
        return M_PI * pow(r, 2);
    }

    inline double Circle2D_Diameter(double d) // ������� ����� �� ��������
    {
        return M_PI * (pow(d, 2) / 4);
    }

    inline double Circle2D_CircleLength(double L) // ������� ����� �� ����� ����������
    {
        return pow(L, 2) / (4 * M_PI);
    }

    inline double Circle2D_Part(double R, double angle) // ������� ������ ����� �����
    {
        return M_PI * pow(R, 2) * (angle / 360);
    }



    // 8. ������ S

    inline double CircleHole2D(double r, double R) // ������� ������
    {
        return M_PI * (pow(R, 2) - pow(r, 2));
    }

    inline double CircleHole2D_Diameter(double d, double D) // ������� ������ ����� �������
    {
        return (M_PI / 4) * (pow(D, 2) - pow(d, 2));
    }



    // 9. ������������� ������� ������� ������ "�����������" ��������������

    inline double Polygon2D_Apophemera(double P, double A) // ���������� �� ��������� � ���������
    {
        return 0.5 * P * A;
    }

    inline double Polygon2D_Side(double a, double n) // ���������� �� ������� � ���������� ������
    {
        return (n * pow(a, 2)) / (4 * tan(M_PI / n));
    }

    inline double Polygon2D_CircleIn(double r, double n) // ���������� �� ��������� ����������
    {
        double angle = 180.0 / n;
        double radians = angle * M_PI / 180.0;
        return n * pow(r, 2) * tan(radians);
    }

    inline double Polygon2D_CircleOut(double r, double n) // ���������� �� ��������� ����������
    {
        double angle = 360.0 / n;
        double radians = angle * M_PI / 180.0;
        return (n * pow(r, 2) / 2) * sin(radians);
    }



    // 10. ������������� S

    inline double Hexagon2D_Side(double a) // ������� �������������� �� �������
    {
        return (3 * sqrt(3) * pow(a, 2)) / 2;
    }

    inline double Hexagon2D_CircleOut(double R) // ������� �������������� �� ��������� ����������
    {
        return (3 * sqrt(3) * pow(R, 2)) / 2;
    }

    inline double Hexagon2D_CircleIn(double R) // ������� �������������� �� ��������� ����������
    {
        return sqrt(3) * pow(R, 2);
    }

    inline double Hexagon2D_Diagonal(double D) // ������� �������������� �� ���������
    {
        return (3 * sqrt(3) * pow(D, 2)) / 8;
    }

    inline double Hexagon2D_ShortDiagonal(double D) // ������� �������������� �� �������� ���������
    {
        return (sqrt(3) * pow(D, 2)) / 2;
    }

    inline double Hexagon2D_Perimetr(double P) // ������� �������������� �� ���������
    {
        return (3 * sqrt(3) * pow(P / 6, 2)) / 2;
    }



    // 11. �������������� S

    inline double Octagon2D_Side(double a) // ������� ��������������� �� �������
    {
        return 2 * pow(a, 2) * (sqrt(2) + 1);
    }

    inline double Octagon2D_CircleOut(double R) // ������� ��������������� �� ��������� ����������
    {
        return 2 * pow(R, 2) * sqrt(2);
    }

    inline double Octagon2D_CircleIn(double R) // ������� ��������������� �� ��������� ����������
    {
        return 8 * pow(R, 2) * (sqrt(2) - 1);
    }



    // ������

    // 1. ������������

    inline double Triangle3D(double S, double h) // ����� ������������ (��������)
    {
        return (S * h) / 3;
    }

    inline double Triangle3D_Equilateral(double a) // ����� ��������������� ������������ (���������� ��������)
    {
        return sqrt(2) * pow(a, 3) / 12;
    }

    // 2. ������

    inline double Cone3D(double r, double h) // ����� ������
    {
        return M_PI * pow(r, 2) * h / 3;
    }

    inline double Cone3D_Part(double R1, double R2, double h) // ����� ���������� ������
    {
        double fig = h * (pow(R1, 2) + R1 * R2 + pow(R2, 2));
        return (M_PI * fig) / 3;
    }

    // 3. ��������� ������ 

    inline double Square3D(double a) // ����� �������� (���)
    {
        return pow(a, 3);
    }

    inline double Rentangle3D(double a, double b, double h) // ����� �������������� (������������� ��������������)
    {
        return a * b * h;
    }

    inline double Parallelogram3D(double s, double h) { // ����� ��������������� (��������������)
        return s * h;
    }

    inline double Cilinder3D(double r, double h) // ����� ��������
    {
        return M_PI * pow(r, 2) * h;
    }

    inline double Hexagon3D(double a, double h) // ����� �������������� �� �������
    {
        return 3 * sqrt(3) / 2 * pow(a, 2) * h;
    }

    // 4. ���� � ������

    inline double Circle3D(double r) // ����� ����� �� ������� (���)
    {
        return (4 * (M_PI * pow(r, 3))) / 3;
    }

    inline double Circle3D_Diameter(double d) // ����� ����� �� �������� (���)
    {
        return M_PI * (pow(d, 3)) / 6;
    }

    inline double Circle3D_CircleLength(double L) // ����� ����� �� ����� ���������� (���)
    {
        return pow(L, 3) / 6 * pow(M_PI, 2);
    }

    inline double CircleHole3D(double h, double R) // ����� ������
    {
        return M_PI * pow(R, 2) * h;
    }

    // 5. ��������

    inline double Pyramid3x3D(double a, double h)// ����� �������� �� 3 ����
    {
        return (h * pow(a, 2)) / (4 * sqrt(3));
    }

    inline double Pyramid4x3D(double a, double h) // ����� �������� �� 4 ����
    {
        return (pow(a, 2) * h) / 3;
    }

    inline double Pyramid5x3D(double a, double h) // ����� �������� �� 6 �����
    {
        double baseArea = (5 * a * a) / (4 * tan(M_PI / 5));
        double volume = (baseArea * h) / 3;
        return volume;
    }

    inline double Pyramid6x3D(double a, double h) // ����� �������� �� 6 �����
    {
        return sqrt(3) / 2 * h * pow(a, 2);
    }

    inline double PyramidNx3D(double a, double h, double count_angle) //N �������� ��������
    {
        double angleR = 180.0 * M_PI / 180.0;
        return (count_angle * h * pow(a, 2)) / (12 * tan(angleR / count_angle));
    }

    // 6. ������

    inline double Prism3x3D(double a, double h) // ����� ����������� ������
    {
        return sqrt(3) / 4 * pow(a, 2) * h;
    }

    inline double Prism4x3D(double a, double h) // ����� ������ �� 4 ����
    {
        return pow(a, 2) * h;
    }

    inline double Prism5x3D(double a, double h) // ����� ������ �� 5 �����
    {
        return (5 * a * a * h) / (4 * tan(M_PI / 5));
    }

    inline double Prism6x3D(double a, double h) // ����� ������ �� 6 �����
    {
        return (sqrt(3) * 3 / 2) * pow(a, 2) * h;
    }



    // ������� ����������� �������� �����

    inline double Square3D_S_Side(double a) // ������� ����������� ���� �� �������
    {
        return 6 * pow(a, 2);
    }

    inline double Square3D_S_Diagonal(double d) // ������� ���� �� ���������
    {
        return 6 * d / sqrt(2);
    }

    inline double Rentangle3D_S_Side(double a, double b, double h) // ������� ����������� ��������������
    {
        return 2 * a * b + a * h + b * h;
    }

    inline double Circle3D_S_Radius(double R) // ������� ����������� ���� �� �������
    {
        return 4 * M_PI * pow(R, 2);
    }

    inline double Circle3D_S_Diagonal(double D) // ������� ����������� ���� �� ���������
    {
        return M_PI * pow(D, 2);
    }

    inline double Cone3D_SPart(double R, double l) // ������� ����������� ����� ������
    {
        return M_PI * R * l;
    }

    inline double Cone3D_SFull(double R, double l) // ������� ����������� ������
    {
        return M_PI * R * (R + l);
    }

    inline double Cilinder3D_SPart(double R, double h) // ������� ����������� ����� ��������
    {
        return 2 * M_PI * R * h;
    }

    inline double Cilinder3D_SFull(double R, double h) // ������� ����������� ����� ��������
    {
        return 2 * M_PI * R * (R + h);
    }



    // ���� �������:

    // ����� ����������

    inline double LengthCircle_Radius(double R) // �� �������
    {
        return 2 * M_PI * R;
    }

    inline double LengthCircle_Diametr(double D) // �� ��������
    {
        return M_PI * D;
    }

    inline double LengthCircle_FromS(double S) // �� ������� �����
    {
        return sqrt(4 * M_PI * S);
    }



    // ALL FIGURE

    inline double Figure2D_Points(initializer_list<double> args) { // ������� ����� ������ �� ������
        std::vector<double> points(args);

        // ��������, ��� ���������� ����� ������ ������ 2
        if (points.size() % 2 != 0) {
            return 0;
        }

        // ���������� ������� �� ���������� x � y
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

        // ���������� ������� � �������������� ������� ������
        double area = 0.0;
        for (int i = 0; i < x.size(); i++) {
            area += (x[i] * y[(static_cast<unsigned long long>(i) + 1) % x.size()] - 
                x[(static_cast<unsigned long long>(i) + 1) % x.size()] * y[i]);
        }
        area /= 2.0;

        return abs(area);
    }

    inline double Figure2D_Sides(initializer_list<double> args) { // ������� ����� ������ �� �������
        vector<double> sides(args);

        // ��������, ��� ���������� ����� ����� ��� ������ 3
        if (sides.size() < 3) {
            return 0;
        }

        double P(0);
        for (int i = 0; i < sides.size(); i++)
            P += sides[i];

        P /= 2; // ���������� �������������

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

    double Vector_Length(double vecLen1, double vecLen2, double angle) { // ����� ������� �� ������ �������� � ����
        double radians= 180.0 * M_PI / 180.0; 
        return pow(vecLen1, 2) + pow(vecLen2, 2) - 2 * vecLen1 * vecLen2 * cos(radians);
    }

    double Vector_ScalarMultiplication (double vecLen1, double vecLen2, double angle) { // ����� ������� �� ������ �������� � ����
        double radians = 180.0 * M_PI / 180.0;
        return vecLen1 * vecLen2 * cos(radians);
    }

    // ����� ��������

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
         
        double Vector_Length() { // ����� �������
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
        }

        double Vector_Length(VectorExpression& newVector) { // ����� �� ������ ������ � �����
            return sqrt(pow(newVector.x - x, 2) + pow(newVector.y - y, 2) + pow(newVector.z - z, 2));
        }

        double Get_Cos(VectorExpression& newVector) { // �������� ���� ��������
            double first = x * newVector.x + y * newVector.y + z * newVector.z;
            double second = sqrt(pow(x, 2) + pow(y,2) + pow(x,2)) * sqrt(pow(newVector.x,2) + pow(newVector.y,2) + pow(newVector.z,2));
            return first / second;
        }

        double Triangle2D_VectorMultiplication(VectorExpression& newVector) const { // ������� �� ���������� ���������
            double X = y * newVector.z - z * newVector.y;
            double Y = (x * newVector.z - z * newVector.x) * -1;
            double Z = x * newVector.y - y * newVector.x;
            return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2)) * 0.5;
        }

        bool Equals(VectorExpression& newVector) const{ // ��������� ��������
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

        VectorExpression Vector_Multiplication(double K) { // * �� �����
            return VectorExpression(x * K, y * K, z * K);
        }

        VectorExpression Vector_VectorMultiplication(VectorExpression& newVector) { // ��������� ������������
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