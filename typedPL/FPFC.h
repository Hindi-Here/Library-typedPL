#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

using namespace std;

#include <random> // для седьмой функии массивов
random_device rd;
mt19937 gen(rd());

#ifdef _MSC_VER
#if _MSC_VER >= 1910 // Проверка версии MSVC для С++17 и выше
#ifndef NOMINMAX
#define NOMINMAX // Исключение конфликтов с макросами windows.h
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Уменьшение объема заголовков windows.h
#endif
#endif
#endif

#include <windows.h> // инклюд для FunctionalLIB_CustomConsole
#include <shellapi.h>
#include <stdlib.h>
#include <sstream>

#include <regex> // регулярные выражения

#include <sys/stat.h> // статистика файла

// Array функции

namespace FunctionalLIB_Array {

    // 1. Сумма

    template<typename T> double Sum(T arg) { // сумма неизвестного количества элементов
        return arg;
    }

    template<typename T, typename... Args> double Sum(T arg, Args... args) {
        return arg + Sum(args...);
    }

    template<typename T> double Sum(vector<T> arr) { // сумма элементов массива динамического
        static T result = 0;
        for (int i = 0; i < arr.size(); i++)
            result += arr[i];

        return result;
    }

    template<typename T, size_t N> double Sum(T(&arr)[N]) { // сумма элементов массива статического
        static T result = 0;
        for (int i = 0; i < N; i++)
            result += arr[i];

        return result;
    }

    template<typename T, size_t N> double Sum(array<T, N> arr) { // сумма элементов массива типа array<T,N>
        static T result = 0;
        for (int i = 0; i < N; i++)
            result += arr[i];

        return result;
    }



    // 2. Среднее значение

    template<typename T> double Avg(T arg) { // среднее неизвестного количества элементов
        return arg;
    }

    template<typename T, typename... Args> double Avg(T arg, Args... args) {
        return (arg + Avg(args...)) / (sizeof...(args) + 1);
    }

    template<typename T> double Avg(vector<T> arr) { // среднее элементов массива динамического
        static double result = 0;
        for (int i = 0; i < arr.size(); i++)
            result += arr[i];

        return result / arr.size();
    }

    template<typename T, size_t N> double Avg(T(&arr)[N]) { // среднее элементов массива статического
        static double result = 0;

        for (int i = 0; i < N; i++)
            result += arr[i];

        return result / N;
    }

    template<typename T, size_t N> double Avg(array<T, N> arr) { // среднее элементов массива типа array<T,N>
        static double result = 0;

        for (int i = 0; i < N; i++)
            result += arr[i];

        return result / N;
    }



    // 3. Максимум

    template<typename T> T Max(T arg) { // максимальное значение неизвестного количества элементов
        return arg;
    }

    template<typename T, typename... Args> T Max(T arg, Args... args) {
        T maxArg = Max(args...);
        return (arg > maxArg) ? arg : maxArg;
    }

    template<typename T> T Max(vector<T> arr) { // максимальное значение элементов массива динамического
        static T result = arr[0];
        for (int i = 1; i < arr.size(); i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Max(T(&arr)[N]) { // максимальное значение элементов массива статического
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Max(array<T, N> arr) { // максимальное значение элементов массива типа array<T,N>
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }




    // 4. Минимум

    template<typename T> T Min(T arg) { // минимальное значение неизвестного количества элементов
        return arg;
    }

    template<typename T, typename... Args> T Min(T arg, Args... args) {
        T minArg = Min(args...);
        return (arg < minArg) ? arg : minArg;
    }

    template<typename T> T Min(vector<T> arr) { // минимальное значение элементов массива динамического
        static T result = arr[0];
        for (int i = 1; i < arr.size(); i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Min(T(&arr)[N]) { // минимальное значение элементов массива статического
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Min(array<T, N> arr) { // минимальное значение элементов массива типа array<T,N>
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }



    // 5 Сортировка

    template<typename T> T Sort(vector<T>& arr) { // сортировка массива динамического
        for (int i = 0; i < arr.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            auto temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return 0;
    }

    template<typename T, size_t N> T Sort(T(&arr)[N]) { // сортировка массива статического
        for (int i = 0; i < N - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return 0;
    }

    template<typename T, size_t N> T Sort(array<T, N>& arr) { // сортировка массива типа array<T,N>
        for (int i = 0; i < N - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return 0;
    }

    string Sort(vector<string>& arr) { // сортировка STRING массива динамического
        for (int i = 0; i < arr.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            string temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return "";
    }

    template<size_t N> string Sort(string(&arr)[N]) { // сортировка STRING массива статического
        for (int i = 0; i < N - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            string temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return "";
    }

    template<size_t N> string Sort(array<string, N>& arr) { // сортировка STRING массива типа array<T,N>
        for (int i = 0; i < N - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            string temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return "";
    }



    // 6. Массив Reverse

    template<typename T> T Converse(vector<T>& arr) { // переворот массива динамического
        int start = 0;
        int end = (int)arr.size() - 1;

        while (start < end) {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
         return 0;
    }

    template<typename T, size_t N> T Converse(T(&arr)[N]) { // переворот массива статического
        int start = 0;
        int end = N - 1;

        while (start < end) {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }

        return 0;
    }

    template<typename T, size_t N> T Converse(array<T, N>& arr) { // переворот массива типа array<T,N>
        int start = 0;
        int end = N - 1;
        while (start < end) {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }

        return 0;
    }

    string Converse(vector<string>& arr) { // переворот STRING массива динамического
        int start = 0;
        int end = (int)arr.size() - 1;

        while (start < end) {
            string temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
        return "";
    }

    template<size_t N> string Converse(string(&arr)[N]) { // переворот STRING массива статического
        int start = 0;
        int end = N - 1;
        while (start < end) {
            string temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }

        return "";
    }

    template<size_t N> string Converse(array<string, N>& arr) { // переворот STRING массива типа array<T,N>
        int start = 0;
        int end = N - 1;

        while (start < end) {
            string temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }

        return "";
    }



    // 7. Инверсия

    double Inversion(double arg) { // инверсия числа
        return arg * -1;
    }

    template<typename T> double Inversion(vector<T>& arr) { // инверсия массива динамического
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }

    template<typename T, size_t N> double Inversion(T(&arr)[N]) { // инверсия массива статического
        for (int i = 0; i < N; i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }

    template<typename T, size_t N> double Inversion(array<T, N>& arr) { // инверсия массива типа array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }



    // 8. Random Массив INT  

    template<typename T> int RandInt(T min, T max) { // рандомное целое число
        uniform_int_distribution<> generation(min, max);
        return generation(gen);
    }

    template<typename T> int RandInt(T min, T max, vector<T>& arr) { // рандомный массив динамического типа
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> int RandInt(T min, T max, T(&arr)[N]) { // рандомный массив статического типа
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> int RandInt(T min, T max, array<T, N>& arr) { // рандомный массив типа array<T,N>
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    // Random Массив DOUBLE

    template<typename T> double RandDouble(T min, T max) { // рандомное вещественное число
        uniform_real_distribution<> generation(min, max);
        return generation(gen);
    }

    template<typename T> double RandDouble(T min, T max, vector<T>& arr) { // рандомный массив динамического типа
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> double RandDouble(T min, T max, T(&arr)[N]) { // рандомный массив статического типа
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> double RandDouble(T min, T max, array<T, N>& arr) { // рандомный массив типа array<T,N>
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }



    // 9. Медиана

    template<typename T> T Median(vector<T>& arr) { // Медиана для векторного массива
        return arr[arr.size() / 2];
    }

    template<typename T, size_t N> T Median(T(&arr)[N]) { // Медиана для статического массива
        return arr[N / 2];
    }

    template<typename T, size_t N> T Median(array<T, N>& arr) { // Медиана для массива типа array<T,N>
        return arr[N / 2];
    }



    // 10. Заполнение массива

    template<typename T> T Fill(vector<T>& arr, T value) { //  Заполнение векторного массива
        for (int i = 0; i < arr.size(); i++)
            arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T Fill(T(&arr)[N], T value) { // Заполнение статического массива
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T Fill(array<T, N>& arr, T value) { // Заполнение массива типа array<T,N>
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return 0;
    }

    string Fill(vector<string>& arr, string value) { //  Заполнение STRING векторного массива
        for (int i = 0; i < arr.size(); i++)
            arr[i] = value;

        return "";
    }

    template<size_t N> string Fill(string(&arr)[N], string value) { // Заполнение STRING статического массива
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return "";
    }

    template<size_t N> string Fill(array<string, N>& arr, string value) { // Заполнение STRING массива типа array<T,N>
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return "";
    }

    // Заполнение части массива

    template<typename T> T FillPart(vector<T>& arr, T value, int start, int end) { //  Заполнение части векторного массива
        for (int i = 0; i < arr.size(); i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T FillPart(T(&arr)[N], T value, int start, int end) { // Заполнение части статического массива
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T FillPart(array<T, N>& arr, T value, int start, int end) { // Заполнение части массива типа array<T,N>
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    string FillPart(vector<string>& arr, string value, int start, int end) { //  Заполнение STRING части векторного массива
        for (int i = 0; i < arr.size(); i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }

    template<size_t N> string FillPart(string(&arr)[N], string value, int start, int end) { // Заполнение STRING части статического массива
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }

    template<size_t N> string FillPart(array<string, N>& arr, string value, int start, int end) { // Заполнение STRING части массива типа array<T,N>
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }



    // 11. Замена значений массива

    template<typename T> T Change(vector<T>& arr, T found, T replace) { //  Replace векторного массива
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    template<typename T, size_t N> T Change(T(&arr)[N], T found, T replace) { // Replace статического массива
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    template<typename T, size_t N> T Change(array<T, N>& arr, T found, T replace) { // Replace массива типа array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    string Change(vector<string>& arr, string found, string replace) { //  Replace STRING векторного массива
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }

    template<size_t N> string Change(string(&arr)[N], string found, string replace) { // Replace STRING статического массива
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }

    template<size_t N> string Change(array<string, N>& arr, string found, string replace) { // Replace STRING массива типа array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }



    // 12. Объединение массивов

    template<typename T> vector<T> Union(vector<T>& arr1, vector<T>& arr2) { //  Объединение векторных массивов
        vector<T> result = {};
        for (int i = 0; i < arr1.size(); i++)
            result.push_back(arr1[i]);

        for (int i = 0; i < arr2.size(); i++)
            result.push_back(arr2[i]);

        return result;
    }



    // 13. Вычисление длины массива

    template<typename T> int Lgth(vector<T>& arr) { // для динамического массива
        int len = (int)arr.size();
        return len;
    }

    template<typename T, size_t N> int Lgth(T(&arr)[N]) { // для статического массива
        return N;
    }

    template<typename T, size_t N> int Lgth(array<T, N>& arr) { // для массива типа array<T,N>
        return N;
    }



    // 14. Добавление элемента массива

    template<typename T> vector<T> Add(vector<T>& arr, T value) { // добавление для динамического массива
        arr.push_back(value);
        return arr;
    }

    template<typename T, size_t N> vector<T> Add(T(&arr)[N], T value) { // добавление для статического массива
        vector<T> result;
        for (size_t i = 0; i < N; i++) {
            result.push_back(arr[i]);
        }
        result.push_back(value);
        return result;
    }

    template<typename T, size_t N> array<T, N + 1> Add(array<T, N>& arr, T value) { // добавление для массива типа array<T,N>
        array<T, N + 1> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = arr[i];
        }
        result[N] = value;
        return result;
    }

    vector<string> Add(vector<string>& arr, string value) { // добавление STRING для динамического массива
        arr.push_back(value);
        return arr;
    }

    template<size_t N> vector<string> Add(string(&arr)[N], string value) { // добавление STRING для статического массива
        vector<string> result;
        for (size_t i = 0; i < N; i++) {
            result.push_back(arr[i]);
        }
        result.push_back(value);
        return result;
    }

    template<size_t N> array<string, N + 1> Add(array<string, N>& arr, string value) { // добавление STRING для массива типа array<T,N>
        array<string, N + 1> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = arr[i];
        }
        result[N] = value;
        return result;
    }



    // 15. LINQ imitation

    template<typename T> bool LINQ_OPERATION(T arg, string operation, T paramIF) { // LINQ аргумента
        if (operation == "=")
        {
            if (arg == paramIF)
                return true;
            else
                return false;
        }
        if (operation == "!=")
        {
            if (arg != paramIF)
                return true;
            else
                return false;
        }
        if (operation == ">")
        {
            if (arg > paramIF)
                return true;
            else
                return false;
        }
        if (operation == "<")
        {
            if (arg < paramIF)
                return true;
            else
                return false;
        }
        if (operation == ">=")
        {
            if (arg >= paramIF)
                return true;
            else
                return false;
        }
        if (operation == "<=")
        {
            if (arg <= paramIF)
                return true;
            else
                return false;
        }
        return 0;
    }

    template<typename T> vector<T> LINQ_OPERATION(vector<T>& arr, string operation, T paramIF) // LINQ массива
    {
        vector<T> result;

        if (operation == "=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] == paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "!=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] != paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == ">")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] > paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "<")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] < paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == ">=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] >= paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "<=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] <= paramIF)
                    result.push_back(arr[i]);
        }

        return result;
    }

    vector<string> LINQ_OPERATION(vector<string>& arr, string operation, string paramIF) // LINQ STRING массива
    {
        vector<string> result;

        if (operation == "=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] == paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "!=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] != paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == ">")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] > paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "<")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] < paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == ">=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] >= paramIF)
                    result.push_back(arr[i]);
        }
        if (operation == "<=")
        {
            for (int i = 0; i < arr.size(); i++)
                if (arr[i] <= paramIF)
                    result.push_back(arr[i]);
        }

        return result;
    }



    // класс List (динамического) массива

    template <class T> class List { // именование массива
    protected:
        deque<T> value;
        struct structure {};
    public:
        List() {}
        List(size_t S) { value.resize(S); }
        List(initializer_list<T> P) { value = P; } // конструктор-переменная класса
        ~List() {}

        typename deque<T>::iterator begin() { return value.begin(); } // считывание начала массива
        typename deque<T>::iterator end() { return value.end(); } // считывание конца массива

        inline int First() { return 0; }
        inline int Last() { return (int)value.size(); }
        inline T FirstElement() { return value[0]; }
        inline T LastElement() { return value[value.size() - 1]; } 

        T& operator[](int index) { return value[index]; } // считывание массива по индексам

        List& operator+(T arg) { // сложение каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+(List<T>& arg) { //  сложение List массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-(T arg) { // вычитание каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-(List<T>& arg) { //  вычитание List массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*(T arg) { // умножение каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*(List<T>& arg) { //  умножение List массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/(T arg) { // деление каждого элемента на аргумент
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/(List<T>& arg) { //  деление List массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] /= arg[i];

            return *this;
        }

        List& operator%(T arg) { // остаток каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator+=(T arg) { // сложение каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+=(List<T> arg) { // сложение массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-=(T arg) { // вычитание каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-=(List<T> arg) { // вычитание массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*=(T arg) { // умножение каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*=(List<T> arg) { // умножение массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/=(T arg) { // деление каждого элемента на аргумент
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/=(List<T> arg) { // деление массивов
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                if(arg[i] != 0)
                    value[i] /= arg[i];

            return *this;
        }

        List& operator%=(T arg) { // остаток каждого элемента на аргумент
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator=(T arg) { // присваивание к каждому элементу
            for (int i = 0; i < value.size(); i++)
                value[i] = arg;

            return *this;
        }

        List& operator++() { // инкримент каждого элемента
            for (int i = 0; i < value.size(); i++)
                value[i] += 1;

            return *this;
        }

        List& operator--() { // дикремент каждого элемента
            for (int i = 0; i < value.size(); i++)
                value[i] -= 1;

            return *this;
        }



        inline int Count() { return (int)value.size(); } // получение длины массива

        inline double Sum() { // сумма элементов List массива
            static double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result;
        }

        inline double Avg() { // среднее элементов List массива
            static double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result / value.size();
        }

        inline T Max() { // максимальное значение элементов List массива
            static T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result < value[i])
                    result = value[i];

            return result;
        }

        inline T Min() { // минимальное значение элементов List массива
            static T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result > value[i])
                    result = value[i];

            return result;
        }

        inline T GetElement(size_t index) { // получение элемента по индексу
            return value[index];
        }

        inline T Median() { // Медиана для List массива
            return value[value.size() / 2];
        }

        inline void Clear() { // очистка массива
            value.clear();
        }

        List<char> ToCharArray(string text) { // разбиение строки на символьный массив
            List<char> arr;
            for (int i = 0; i < text.length(); i++)
                arr.Add(text[i]);

            return arr;
        }

        inline List<string> Split(string text, char text_spl) { // разбиение строки на подстроки
            List<string> arr;
            string str;
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == text_spl)
                {
                    arr.Add(str);
                    str = "";
                }
                else
                {
                    str += text[i];
                }
            }
            arr.Add(str);

            return arr;
        }

        inline bool Search(T V) { // поиск значения
            bool flag = false;
            for (int i = 0; i < value.size(); i++)
            {
                if (value[i] == V)
                {
                    flag = true;
                    break;
                }
            }
            return flag;
        }

        inline bool Search(initializer_list<T> V) { // поиск по списку значений
            vector<T> arr = V; 
            bool flag = false;
            for (int i = 0; i < value.size(); i++)
            {
                for (int j = 0; j < arr.size(); j++)
                {
                    if (value[i] == arr[j])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            return flag;
        }

        inline bool Equals(List<T> V) { // сравнение массивов
            List<T> arr = V;
            bool flag = true;

            if (value.size() != arr.Count()) // проверка на размерность
                flag = false;
            else
            {
                for (int i = 0; i < value.size(); i++) // проверка на значения
                {
                    if (value[i] != arr[i])
                    {
                        flag = false; break;
                    }
                }
            }
            return flag;
        }

        string ToString() { // конвертирование массива в строку
            stringstream ss;
            for (int i = 0; i < value.size(); i++)
                ss << value[i];

            return ss.str();
        }

        List& Sort() { // сортировка List массива
            for (int i = 0; i < value.size() - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < value.size(); j++) {
                    if (value[j] < value[minIndex]) {
                        minIndex = j;
                    }
                }
                auto temp = value[i];
                value[i] = value[minIndex];
                value[minIndex] = temp;
            }
            return *this;
        }

        List& Converse() { // переворот List массива
            int start = 0;
            int end = (int)value.size() - 1;

            while (start < end) {
                T temp = value[start];
                value[start] = value[end];
                value[end] = temp;

                start++;
                end--;
            }
            return *this;
        }

        template <typename X = T> // инверсия численных
        typename enable_if<is_arithmetic<X>::value, List<X>>::type Inversion() {

           for (int i = 0; i < value.size(); i++) {
                if (value[i] != 0)
                    value[i] = -value[i];
           }

            return *this;
        }

        List& RandInt(int min, int max) { // рандомный List массив
            uniform_int_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& RandDouble(double min, double max) { // рандомный List массив
            uniform_real_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& Fill(T V) { //  Заполнение List массива
            for (int i = 0; i < value.size(); i++)
                value[i] = V;

            return *this;
        }

        List& FillPart(T V, int start, int end) { //  Заполнение части List массива
            for (int i = 0; i < value.size(); i++)
                if (i >= start - 1 and i <= end - 1)
                    value[i] = V;

            return *this;
        }

        List& Change(T found, T replace) { //  Replace List массива
            for (int i = 0; i < value.size(); i++)
                if (value[i] == found)
                    value[i] = replace;

            return *this;
        }

        List& Union(List<T>& arr2) { //  Объединение List массивов
            List<T> arr = arr2;
            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy() { //  копирование List массивов
            vector<T> arr = value;
            for (int i = 0; i < arr.size(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy(int length) { //  копирование N раз List массивов
            vector<T> arr = value;
            for (int len = 0; len < length; len++)
            {
                for (int i = 0; i < arr.size(); i++)
                    value.push_back(arr[i]);
            }

            return *this;
        }

         List& Add(T V) { // добавление элемента в List массив
            value.push_back(V);
            return *this;
        }

         List& Add(initializer_list<T> P) { // добавление списка элементов
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& AddFirst(T V) { // добавление элемента в начало
             value.push_front(V);
             return *this;
         }

         List& AddFirst(initializer_list<T> P) { // добавление списка элементов в начало
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_front(arr[i]);

             return *this;
         }

         List& RemoveFirst() { // удаление начала
             value.pop_front();
             return *this;
         }

         List& RemoveLast() { // удаление конца
             value.pop_back();
             return *this;
         }
          
         List& NewList(initializer_list<T> P) { // перезапись массива на N значения
             value.clear();
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& NewList(List<T> P) { // перезапись массива на другой массив
             value.clear();
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& DeleteByIndex(int index) { // удаление по индексу
             value.erase(value.begin() + index);
             return *this;
         }

         List& DeleteByIndex(int start, int end) { // удаление по индекс диапозону
             for (int i = end; i >= start; i--) {
                 value.erase(value.begin() + i);
             }

             return *this;
         }

         List& DeleteByArgs(T arg) { // удаление по значению
             for (int i = 0; i < value.size(); i++)
                 if (value[i] == arg)
                     value.erase(value.begin() + i);

             return *this;
         }

         List& DeleteByArgs(initializer_list<T> args) { // удаление по списку значений
             for (auto it = value.begin(); it != value.end(); ) {
                 if (find(args.begin(), args.end(), *it) != args.end()) {
                     it = value.erase(it);
                 }
                 else {
                     ++it;
                 }
             }

             return *this;
         }

         List& DeleteByArgs(List<T> args) { // удаление по списку значений List массива
             for (auto it = value.begin(); it != value.end(); ) {
                 if (find(args.begin(), args.end(), *it) != args.end()) {
                     it = value.erase(it);
                 }
                 else {
                     ++it;
                 }
             }

             return *this;
         }

         List& CutStart(int length) { // обрезка с начала массива
             value.erase(value.begin(), value.begin() + length);

             return *this;
         }

         List& CutEnd(int length) { // обрезка с конца массива
             value.erase(value.end() - length, value.end());

             return *this;
         }

         List& Unique() { // удаление повторяющихся символов
             set<T> arr;

             for (auto s : value)
                 arr.insert(s);

             value.clear();

             for (auto s : arr)
                 value.push_front(s); 

             return *this;
         }

         List& Addition(List<T> arg) { // сложение массивов
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] += arg[i];

             return *this;
         }

         List& Subtract(List<T> arg) { // вычитание массивов
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] -= arg[i];

             return *this;
         }

         List& Multiplication (List<T> arg) { // умножение массивов
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] *= arg[i];

             return *this;
         }

         List& Divide(List<T> arg) { // деление массивов
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 if(arg != 0)
                    value[i] /= arg[i];

             return *this;
         }

    };

    List<double> ProgressionA(double firstElem, int stepCount, double stepValue) {
        FunctionalLIB_Array::List<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem += stepValue;
            arr.Add(firstElem);
        }
        return arr;
    }

    List<double> ProgressionG(double firstElem, int stepCount, double stepValue) {
        FunctionalLIB_Array::List<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem *= stepValue;
            arr.Add(firstElem);
        }
        return arr;
    }

} 

// String функции

namespace FunctionalLIB_String {

    class String : FunctionalLIB_Array::List<char>, FunctionalLIB_Array::List<string> {
    private:
        string newSTR;
        friend String ToTypedPL_String() {};
    public:
        String() {};
        String(const char* value) { newSTR = (string)value; };
        ~String() {}

        friend ostream& operator<<(ostream& os, const String& str) { // вывод на экран через cout
            os << str.newSTR;
            return os;
        }

        friend istream& operator>>(istream& input, String& str) { // ввод переменной через cin
            input >> str.newSTR;
            return input;
        }

        bool operator!=(const String& str) { return newSTR != str.newSTR; }

        bool operator==(const String& str) { return newSTR == str.newSTR; }

        bool operator>=(const String& str) { return newSTR >= str.newSTR; }

        bool operator>(const String& str) { return newSTR > str.newSTR; }

        bool operator<=(const String& str) { return newSTR <= str.newSTR; }

        bool operator<(const String& str) { return newSTR < str.newSTR; }



        String& operator=(const char* str) { newSTR = str; return *this; } // Str1 = "text"

        String& operator=(char symbol) { stringstream ss; ss << symbol; newSTR = ss.str(); return *this; } // Str[0] = 'S'

        String& operator=(string str) { newSTR = str; return *this; } // Str1 = str2

        template <typename T>  String& operator=(T arg) { newSTR = to_string(arg); return *this; } // Str1 = T



        String& operator+=(char symbol) { stringstream ss; ss << symbol; newSTR += ss.str(); return *this; } // Str += 'S'

        String& operator+=(const char* str) { newSTR += str; return *this; } // Str += "text

        String& operator+=(string str) { newSTR += str; return *this; }  // Str += str

        String& operator+=(String text) { string txt = text.ToString(); newSTR += txt; return *this; } // Str += Str

        template <typename T>  String& operator+=(T arg) { newSTR += to_string(arg); return *this; } // Str += T



        String& operator[](int index) { newSTR = newSTR[index]; return *this; }



        String& operator+(char symbol) { stringstream ss; ss << symbol; newSTR += ss.str(); return *this; } // Str += 'S'

        String& operator+(const char* str) { newSTR += str; return *this; } // Str + "text"

        String& operator+(string str) { newSTR += str; return *this; } // Str + str

        String& operator+(String text) { string txt = text.ToString(); newSTR += txt.c_str(); return *this; } // Str + Str

        template <typename T>  String& operator+(T arg) { newSTR += to_string(arg); return *this; } // Str + T



        template <typename T> String ToTypedPL_String(T str) {}; // прототипы функций

        String& operator-(int len) { newSTR.erase(newSTR.end() - len, newSTR.end()); return *this; } // Str - 2 = S

        String& operator-(char symbol) { String str = ToTypedPL_String(newSTR); str.Replace(symbol, NULL); 
                                newSTR = str.ToString(); return *this; } // Str - 't' = Sr

        String& operator-(const char* text) {
            size_t pos = newSTR.find(text);
            string s = string(text);
            if (pos != string::npos) {
                newSTR.replace(pos, s.length(), "");
            }
            return *this;
        } // Str - St = r

        String& operator-(string text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos) {
                newSTR.replace(pos, text.length(), "");
            }
            return *this;
        } // Str - St = r

        String& operator-(String text) { 
            string s = text.ToString();
            size_t pos = newSTR.find(s);
            if (pos != string::npos) {
                newSTR.replace(pos, s.length(), "");
            }
            return *this;
        } // Str - St = r



        String& operator/(int KF) {
            if (KF == 0) { newSTR.clear(); }
            newSTR.erase(newSTR.end() - newSTR.length() / KF, newSTR.end()); return *this; } // Str / 1 = NULL



        void Print() const { // вывод на экран текста
            cout << newSTR;
        }

        void Print(const char* text) const { // вывод на экран текста
            cout << newSTR << text;
        }

        void Print(string text) const { // вывод на экран текста
            cout << newSTR << text;
        }

        void Print(String text) const { // вывод на экран текста
            cout << newSTR << text;
        }

        string ToString() const { // конвертирование в строку string из типа класса
           return string(newSTR);
        }

        template <typename T> string ToString(T arg) { // конвертирование аргумента в строку
            stringstream ss;
            ss << newSTR << arg;
            return ss.str();
        }

        template <typename T> string ToString(initializer_list<T> arg) { // конвертирование списка в строку
            List<T> arr = arg;
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arr.Count(); i++)
                ss << arr[i];

            return ss.str();
        }

        template <typename T> string ToString(List<T> arg)  { // конвертирование массива в строку
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arg.Count(); i++)
                ss << arg[i];

            return ss.str();
        }
        
        int Length() { return (int)newSTR.length(); } // длина строки

        void Clear() { newSTR.clear(); } // очистка строки

        bool Search(char symbol) { // поиск по символу
            bool flag = false;
            for (int i = 0; i < newSTR.length(); i++)
            {
                if (newSTR[i] == symbol)
                {
                    flag = true; break;
                }
            }
            return flag;
        }

        bool Search(string text) { // поиск по строке
            size_t pos = newSTR.find(text);
            if (pos != string::npos)
                return true;
            else
                return false;
        }

        bool Search(initializer_list<char> arg) { // поиск по списку значений
            vector<char> arr = arg;
            bool flag = false;
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arr.size(); j++)
                {
                    if (newSTR[i] == arr[j])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            return flag;
        }

        bool Search(List<char> arg) { // поиск по списку значений
            List<char> arr = arg;
            bool flag = false;
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arr.Count(); j++)
                {
                    if (newSTR[i] == arr[j])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            return flag;
        }

        int SearchCount(char symbol) { // подсчет совпадений по символу
            static int Count = 0;
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    Count++;

            return Count;
        }

        int SearchCount(string text) { // подсчет совпадений по строке
            static int count = 0;
            size_t pos = newSTR.find(text);
            while (pos != string::npos) {
                count++;
                pos = newSTR.find(text, pos + 1);
            }
            return count;
        }

        int SearchCount(initializer_list<char> arg) { // поиск по списку значений
            vector<char> arr = arg;
            int Count = 0;
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arr.size(); j++)
                {
                    if (newSTR[i] == arr[j])
                    {
                        Count++;
                        continue;
                    }
                }
            }
            return Count;
        }

        int SearchCount(List<char> arg) { // поиск по списку значений
            List<char> arr = arg;
            int Count = 0;
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arr.Count(); j++)
                {
                    if (newSTR[i] == arr[j])
                    {
                        Count++;
                        continue;
                    }
                }
            }
            return Count;
        }

        bool Equals(string text) { // проверка на равнозначность
            bool flag = true;

            if (newSTR.length() != text.length()) 
                flag = false;
            else
            {
                for (int i = 0; i < newSTR.size(); i++) 
                {
                    if (newSTR[i] != text[i])
                    {
                        flag = false; break;
                    }
                }
            }
            return flag;
        }

        bool EqualsMax(string text) { // сравнение на максимальность
            if (newSTR.length() > text.length())
                return true;
            else
                return false;
        }

        bool EqualsMin(string text) { // сравнение на минимальность
            if (newSTR.length() < text.length())
                return true;
            else
                return false;
        }

        bool Equals(String text) { // проверка на равнозначность
            bool flag = true;
            string txt = text.ToString();
            if (newSTR.length() != text.Length())
                flag = false;
            else
            {
                for (int i = 0; i < newSTR.size(); i++)
                {
                    if (newSTR[i] != txt[i])
                    {
                        flag = false; break;
                    }
                }
            }
            return flag;
        }

        bool EqualsMax(String text) { // сравнение на максимальность
            if (newSTR.length() > text.Length())
                return true;
            else
                return false;
        }

        bool EqualsMin(String text) { // сравнение на минимальность
            if (newSTR.length() < text.Length())
                return true;
            else
                return false;
        }

        char GetFirstElement() { // получить первый символ строки
            return newSTR[0];
        }

        char GetLastElement() { // получить последний символ
            return newSTR[newSTR.length() - 1];
        }

        char GetElement(int index) { // получение значения индекса
            for (int i = 0; i < newSTR.length(); i++)
                if (i == index)
                    return newSTR[i];
        }

        List<char> ToCharArray() { // разбиение строки на символы
            List<char> arr;
            for (int i = 0; i < newSTR.length(); i++)
                arr.Add(newSTR[i]);

            return arr;
        }

        List<string> Split(char symbol) { // разбиение строки на подстроки
            List<string> arr;
            string str;
            for (int i = 0; i <  newSTR.length(); i++)
            {
                if (newSTR[i] == symbol)
                {
                    arr.Add(str);
                    str = "";
                }
                else
                {
                    str += newSTR[i];
                }
            }
            arr.Add(str);

            return arr;
        }
        
        String& Reverse() { reverse(newSTR.begin(), newSTR.end()); return *this; } // разворот строки

        String& Replace(char found, char replace) { // замена символов строки
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == found)
                    newSTR[i] = replace;

            return *this;
        }

        String& Add(string arg) { // добавление значения
            newSTR += arg;
            return *this;
        }

        String& Add(char symbol) { // добавление символа
            newSTR.push_back(symbol);
            return *this;
        }

        template <typename T> String& Add(initializer_list<T> arg) { // добавить список
            List<T> arr = arg;
            for (int i = 0; i < arr.Count(); i++)
                newSTR += to_string(arr[i]);

            return *this;
        }

        String& AddSymbol(char symbol) { // добавление символа
            newSTR.push_back(symbol);
            return *this;
        }

        String& NewString(string arg) { // переназначение строки
            newSTR = arg;
            return *this;
        }
  
        String& SwapString(String& text) { // свапнуть строки
            String temp = *this;
            *this = text;
            text = temp; 
            return *this; 
        }

        String& CutStart(int length) { // обрезка с начала массива
            newSTR.erase(newSTR.begin(), newSTR.begin() + length);
            return *this;
        }

        String& CutEnd(int length) { // обрезка с конца массива
            newSTR.erase(newSTR.end() - length, newSTR.end());
            return *this;
        }
        
        String& CutRange(int start, int end) { // обрезка в диапазоне
            newSTR.erase(start, end);
            return *this;
        }

        String& RemoveSymbol(char symbol) { // удаление символа
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    newSTR[i] = NULL;

            return *this;
        }

        String& Remove(char symbol) { // удаление символа
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    newSTR[i] = NULL;

            return *this;
        }

        String& Remove(initializer_list<char> arg) { // удаление листа символов
            List<char> arr = arg;
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arr.Count(); j++)
                {
                    if (newSTR[i] == arr[j])
                        newSTR[i] = NULL;
                }
            }

            return *this;
        }

        String& Remove(List<char> arg) { // удаление массива символов
            for (int i = 0; i < newSTR.length(); i++)
            {
                for (int j = 0; j < arg.Count(); j++)
                {
                    if (newSTR[i] == arg[j])
                        newSTR[i] = NULL;
                }
            }

            return *this;
        }

        String& Remove(String text) {
            string s = text.ToString();
            size_t pos = newSTR.find(s);
            if (pos != string::npos) {
                newSTR.replace(pos, s.length(), "");
            }
            return *this;
        } 

        String& Remove(string text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos) {
                newSTR.replace(pos, text.length(), "");
            }
            return *this;
        }

        String& Remove_LastSymbol() { // удаление последнего символа символа
            newSTR.pop_back();
            return *this;
        }

        String& Remove_FirstSymbol() { // удаление первого символа символа
            newSTR = newSTR.substr(1);
            return *this;
        }

        String& RemoveA_z() { // убрать иностранные символы
            regex regex("[a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return* this;
        }

        String& RemoveА_я() { // убрать русские символы
            regex regex("[а-яА-Я]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveNum() { // убрать все числовые символы
            regex regex("[0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveAnother() {
            regex regex("[[:punct:]№]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptA_z() { // оставить только англ. символы
            regex regex("[^a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptА_я() { // оставить только русские символы
            regex regex("[^а-яА-Я]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptNum() { // оставить только числа
            regex regex("[^0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Remove(string str) { // удаление по регулярному выражению
            regex regex(str);
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Replace(string str, string replace) { // замена по регуляру
            regex regex(str);
            newSTR = regex_replace(newSTR, regex, replace);
            return *this;
        }

    };

    template <typename T> String ToTypedPL_String(T str) {
        stringstream ss;
        ss << str;
        return ss.str().c_str();
    }

}

// File функции

namespace FunctionalLIB_File {
    class File : FunctionalLIB_String::String{
    private:
        string str;
        struct stat fileStat {};

        LPCWSTR ConvertTo(string str) {
            int size_needed = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
            wchar_t* wstr = new wchar_t[size_needed];
            MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, size_needed);
            return wstr;
        }

    public:
        File(const char* text) { str = text; }
        File(string text) { str = text; }
        File(String text) { str = text.ToString(); }
        ~File() {}

        void FileOpen() { // открытие приложений, ссылок, всего    
                LPCWSTR result = ConvertTo(str);
                ShellExecute(NULL, L"open", result, NULL, NULL, SW_SHOW);
        }

        File& FileMove(string moveIN) { // перемещение файла
            LPCWSTR thisPath = ConvertTo(str);
            LPCWSTR nextPath = ConvertTo(moveIN);
            MoveFile(thisPath, nextPath);
            return *this;
        }

        File& FileCreate() { // создание файла
            ofstream write(str);
            write << "";
            return *this;
        }

        void FileRemove() { // удаление файла
            LPCWSTR newSTR = ConvertTo(str);
            DeleteFile(newSTR);
        }

        File& FileRename(string newName) { // переименование файла
            if (rename(str.c_str(), newName.c_str()) == 0)  {}
            return *this;
        }

        List<string> ReadAllLines() { // считывание линий
            ifstream read(str);
            List<string> arr; string line;
            while (getline(read, line))
                arr.Add(line);

            return arr;
        }

        vector<string> ReadAllLines_Vector() { // считывание линий для вектора
            ifstream read(str);
            vector<string> arr; string line;
            while (getline(read, line))
                arr.push_back(line);

            return arr;
        }

        string ReadAllText() { // считывание всего текста
            ifstream read(str);
            string a; string line;
            while (getline(read, line))
                a += line;

            return a;
        }

        template <typename T> File& WriteAllText(T text) { // запись текста
            ofstream write(str);
            write << text;
            return *this;
        }

        template <typename T> File& WriteAllText(T text, string format) { // запись текста с форматирование
            ofstream write(str);
            write << text << format;
            return *this;
        }

        template <typename T> File& WriteAllLines(List<T> arr) { // запись масисва данных построчно
            ofstream write(str);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }

        template <typename T> File& WriteAllLines(vector<T> arr) { 
            ofstream write(str);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }

        template <typename T, size_t N> File& WriteAllLines(T(&arr)[N]) {
            ofstream write(str);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }

        template <typename T> File& AppendAllText(T text) { // добавление данных
            ofstream write(str, ios::app);
            write << text;
            return *this;
        }

        template <typename T> File& AppendAllText(T text, string format) { // добавление данных с форматом
            ofstream write(str, ios::app);
            write << text << format;
            return *this;
        }

        template <typename T> File& AppendAllLines(List<T> arr) { // добавление данных по массиву
            ofstream write(str, ios::app);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }

        template <typename T> File& AppendAllLines(vector<T> arr) { 
            ofstream write(str, ios::app);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }

        template <typename T, size_t N> File& AppendAllLines(T(&arr)[N]) { 
            ofstream write(str, ios::app);
            for (auto s : arr)
                write << s << "\n";

            return *this;
        }
  
        // Информация о файле

        double GetBitSize() { // получение размеров файла в разных единицах
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = fileStat.st_size * 8;

            return size;
        }

        double GetByteSize()  { 
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = fileStat.st_size;

            return size;
        }

        double GetKBSize() { 
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = double(fileStat.st_size) / 1024;

            return size;
        }

        double GetMBSize() { 
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = double(fileStat.st_size) / 1024 / 1024;

            return size;
        }

        double GetGBSize() { 
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = double(fileStat.st_size) / 1024 / 1024 / 1024;

            return size;
        }

   

        string GetFileName() { // получение имени файла
            fstream fs(str);
            if (fs.is_open())
            {
                size_t lastSlash = str.find_last_of("/\\");
                if (lastSlash != string::npos) {
                    return str.substr(lastSlash + 1);
                }
            }
            return "";
        }

        string GetFilePath() { // получение пути к файлу
            fstream fs(str);
            if (fs.is_open())
            {
                size_t lastSlash = str.find_last_of("/\\");
                if (lastSlash != string::npos) {
                    return str.substr(0, lastSlash);
                }
            }
            return "";
        }

        string GetFileExtension() { // получение расширения файла
            fstream fs(str);
            if (fs.is_open())
            {
                size_t lastDot = str.find_last_of(".");
                if (lastDot != std::string::npos) {
                    return str.substr(lastDot + 1);
                }
            }
            return "";
        }

        int GetFileDepth() { // получение глубины
            fstream fs(str); int depth = 0;
            if (fs.is_open())
            {
                for (char c : str) {
                    if (c == '\\') {
                        depth++;
                    }
                }
            }
            return depth;
        }

    };
}

// Customize Console

namespace FunctionalLIB_CustomConsole {

    // Одиночные методы (не надо вызывать экземпляр класса)

    template <class T> void ThisBold(T Text) { // Жирный текст (только аргумент)
        cout << "\033[1m" << Text << "\033[0m";
    }

    template <class T> void ThisNormal(T Text) { // Простой текст (только аргумент)
        cout << "\033[0m" << Text << "\033[0m";
    }

    template <class T> void ThisLine(T Text) { // Подчеркнутый текст (только аргумент)
        cout << "\033[4m" << Text << "\033[0m";
    }

    template <class T> void ThisRGB(T Text, int R, int G, int B) { // RGB расцветка текста
            cout << "\033[38;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    template <class T> void ThisForegroundRGB(T Text, int R, int G, int B) { // перекраска текста в блок с цветом
        cout << "\033[48;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    void Clear() {  // Очистка содержимого консоли
        system("cls");
    }

    void Close() { // Закрытие консоли
        exit(0);
    }




    class ConsoleSetting {
    
    private:
        HANDLE hConsole{};

        int Red = 0, Green = 0, Blue = 0;

        void BG_COLOR() { // метод для определения цвета консоли
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

            WORD attributes = consoleInfo.wAttributes;
            int backgroundColor = (attributes & 0xF0) >> 4;

            CONSOLE_SCREEN_BUFFER_INFOEX consoleInfoEx{};
            consoleInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
            GetConsoleScreenBufferInfoEx(hConsole, &consoleInfoEx);

            COLORREF backgroundColorRGB = consoleInfoEx.ColorTable[backgroundColor];

            Red = GetRValue(backgroundColorRGB);
            Green = GetGValue(backgroundColorRGB);
            Blue = GetBValue(backgroundColorRGB);
        };
    public:

        // Рамка Window

        ConsoleSetting& WindowShow(bool visible) { // убрать / показать рамку Window 
            HWND console = GetConsoleWindow();
            if (!visible)
            {
                SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_BORDER);
                SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
            }
            else
            {
                SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) | WS_BORDER);
                SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
            }

            return *this;
        }

        ConsoleSetting& WindowMaxShow(bool visible) { // скрыть / показать кнопку растягивания по экрану на window рамке
            HWND consoleWindow = GetConsoleWindow();
            LONG_PTR style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
            if (!visible)
            {
                style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }
            else
            {
                style |= (WS_MAXIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }

            return *this;
        }

        ConsoleSetting& WindowMinShow(bool visible) { // скрыть / показать кнопку сворачивания по экрану на window рамке
            HWND consoleWindow = GetConsoleWindow();
            LONG_PTR style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
            if (!visible)
            {
                style &= ~(WS_MINIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }
            else
            {
                style |= (WS_MINIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }

            return *this;
        }

        ConsoleSetting& WindowCloseShow(bool visible) { // скрыть / показать кнопку закрытия формы по экрану на window рамке
            HWND consoleWindow = GetConsoleWindow();
            if (!visible)
            {
                HMENU systemMenu = GetSystemMenu(consoleWindow, FALSE);
                EnableMenuItem(systemMenu, SC_CLOSE, MF_GRAYED);
                DrawMenuBar(consoleWindow);
            }
            else
            {
                HMENU systemMenu = GetSystemMenu(consoleWindow, TRUE);
                EnableMenuItem(systemMenu, SC_CLOSE, MF_GRAYED);
                DrawMenuBar(consoleWindow);
            }

            return *this;
        }

        ConsoleSetting& WindowPanelShow(bool visible) { // скрыть ИЛИ показать все панели на window рамке
            HWND consoleWindow = GetConsoleWindow();
            LONG_PTR style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
            if (!visible)
            {
                style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);

                style &= ~(WS_MINIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);

                HMENU systemMenu = GetSystemMenu(consoleWindow, FALSE);
                EnableMenuItem(systemMenu, SC_CLOSE, MF_GRAYED);
                DrawMenuBar(consoleWindow);
            }
            else
            {
                style |= (WS_MAXIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);

                style |= (WS_MINIMIZEBOX | WS_SIZEBOX);
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);

                HMENU systemMenu = GetSystemMenu(consoleWindow, TRUE);
                EnableMenuItem(systemMenu, SC_CLOSE, MF_GRAYED);
                DrawMenuBar(consoleWindow);
            }
            return *this;
        }

        ConsoleSetting& Title(const char* title) { // конструктор заголовка консоли
            char command[100];
            strcpy_s(command, "title ");
            strcat_s(command, title);
            system(command);

            return *this;
        }

        ConsoleSetting& Icon(const char* path) { // иконка приложения
            int pathLength = (int)strlen(path) + 1;
            int bufferSize = MultiByteToWideChar(CP_UTF8, 0, path, pathLength, NULL, 0);
            wchar_t* widePath = new wchar_t[bufferSize];
            MultiByteToWideChar(CP_UTF8, 0, path, pathLength, widePath, bufferSize);

            HINSTANCE hInstance = GetModuleHandle(NULL);

            HICON hIcon = (HICON)LoadImage(hInstance, widePath, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

            SendMessage(GetConsoleWindow(), WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            SendMessage(GetConsoleWindow(), WM_SETICON, ICON_BIG, (LPARAM)hIcon);

            delete[] widePath;

            return *this;
        } 

        ConsoleSetting& ScrollBarShow(bool visible) { // убрать / показать видимость полосы прокрутки
            if (!visible)
            {
                HWND hWnd = GetConsoleWindow();
                ShowScrollBar(hWnd, SB_BOTH, FALSE);
                HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
                GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

                short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
                short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

                short scrBufferWidth = scrBufferInfo.dwSize.X;
                short scrBufferHeight = scrBufferInfo.dwSize.Y;

                COORD newSize{};
                newSize.X = scrBufferWidth;
                newSize.Y = winHeight;

                int Status = SetConsoleScreenBufferSize(hOut, newSize);
                if (Status == 0)
                {
                    cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
                    exit(Status);
                }
            }
            else
            {
                HWND hWnd = GetConsoleWindow();
                ShowScrollBar(hWnd, SB_VERT, TRUE);
            }

            return *this;
        }

        ConsoleSetting& PositionConsole(int X, int Y) { // позиция консоли на экране
            HWND consoleWindow = GetConsoleWindow();
            SetWindowPos(consoleWindow, NULL, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

            return *this;
        }

        ConsoleSetting& FullScreen() { // отображение консоли по разрешению экрана
            HWND console = GetConsoleWindow();
            ShowWindow(console, SW_MAXIMIZE);

            return *this;
        }

        ConsoleSetting& Resize(bool can) { // запрет / разрешение на ручное изменение размеров консоли
            HWND consoleWindow = GetConsoleWindow();
            LONG_PTR style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
            if (!can)
            {
                style &= ~WS_THICKFRAME;
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }
            else
            {
                style |= WS_THICKFRAME;
                SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
            }

            return *this;
        }

        ConsoleSetting& Size(int X, int Y) { // размеры консоли
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SMALL_RECT windowSize = { 0, 0, (SHORT)X, (SHORT)Y };
            SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

            return *this;
        }

        ConsoleSetting& SizePixel(int X, int Y) { // установка окна в пикселях
            HWND console = GetConsoleWindow();
            RECT rect;
            GetWindowRect(console, &rect);

            MoveWindow(console, rect.left, rect.top, X, Y, TRUE);

            return *this;
        }

        ConsoleSetting& MaxSize(int X, int Y) { // максимальный размер консоли
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD bufferSize = { (SHORT)X, (SHORT)Y };

            SetConsoleScreenBufferSize(hConsole, bufferSize);

            return *this;
        }

        inline int GetConsoleSize_X() { // получение размеров консоли по X
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            return Width;
        }

        inline int GetConsoleSize_Y() { // получение размеров консоли по Y
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            return Height;
        }

        inline int GetConsoleSizePixel_X() { // получение размеров консоли по X в пикселях
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleWidth = consoleRect.right - consoleRect.left;
            return consoleWidth;
        }

        inline int GetConsoleSizePixel_Y() { // получение размеров консоли по Y в пикселях
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleHeight = consoleRect.bottom - consoleRect.top;
            return consoleHeight;
        }

        ConsoleSetting& ChangeEncode() { // смена кодировки
            if (GetConsoleCP() == 1251)
            {
                SetConsoleCP(866);
                SetConsoleOutputCP(866);
            }
            else
            {
                SetConsoleCP(1251);
                SetConsoleOutputCP(1251);
            }
            return *this;
        }

        inline int GetEncode() { // получение значения кодировки
            return GetConsoleCP();
        }



        // Внутри рамки (консольное пространство)

        ConsoleSetting& Opacity(double opacity) { // прозрачность консоли

            if (opacity >= 0 && opacity <= 1)
            {
                opacity *= 255;
                BYTE op = (BYTE)opacity;
                HWND console = GetConsoleWindow();
                SetWindowLong(console, GWL_EXSTYLE, GetWindowLong(console, GWL_EXSTYLE) | WS_EX_LAYERED);
                SetLayeredWindowAttributes(console, 0, op, LWA_ALPHA);
            }

            return *this;
        }

        ConsoleSetting& TextBG_Color() { // конструктор для перекраски текста в цвет фона
            BG_COLOR();

            cout << "\033[38;2;" << Red << ";" << Green << ";" << Blue << "m";

            return *this;
        }

        inline int GetRedValue() {
            BG_COLOR();
            return Red;
        }
        inline int GetGreenValue() {
            BG_COLOR();
            return Green;
        }
        inline int GetBlueValue() {
            BG_COLOR();
            return Blue;
        }

        ConsoleSetting& TextColor(int R, int G, int B) { // конструктор цвета текста консоли по ргб
            cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& TextColor(string hexColor) { // конструктор цвета текста консоли по хексу
            int r, g, b;
            sscanf_s(hexColor.c_str(), "%02x%02x%02x", &r, &g, &b);
            cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";

            return *this;
        }

        ConsoleSetting& TextColor(int color) { // Random Color?
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, color);

            return *this;
        }

        ConsoleSetting& ForegroundColor(int R, int G, int B) { // конструктор цвета заднего фона текста консоли по ргб
            cout << "\033[48;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& ForegroundColor(string hexColor) { // конструктор  цвета заднего фона текста консоли по хексу
            int r, g, b;
            sscanf_s(hexColor.c_str(), "%02x%02x%02x", &r, &g, &b);
            cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";

            return *this;
        }

        ConsoleSetting& BackgroundColor(int R, int G, int B) { // конструктор цвета бекграунда консоли по ргб
            CONSOLE_SCREEN_BUFFER_INFOEX info{};
            info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfoEx(hConsole, &info);

            info.ColorTable[0] = RGB(R, G, B);

            SetConsoleScreenBufferInfoEx(hConsole, &info);

            return *this;
        }

        ConsoleSetting& BackgroundColor(string hexColor) { // конструктор цвета бекграунда консоли по хексу
            CONSOLE_SCREEN_BUFFER_INFOEX info{};
            info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfoEx(hConsole, &info);

            int r, g, b;
            sscanf_s(hexColor.c_str(), "%02x%02x%02x", &r, &g, &b);
            info.ColorTable[0] = RGB(r,g,b);

            SetConsoleScreenBufferInfoEx(hConsole, &info);

            return *this;
        }

        ConsoleSetting& FontFamily(string name) { // конструктор цвета бекграунда консоли по хексу

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            int size = MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, nullptr, 0);
            wstring wname(size, 0);
            MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, &wname[0], size);

            wcscpy_s(fontInfo.FaceName, wname.c_str()); // Имя шрифта
            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& FontSize(int size) { // конструктор цвета бекграунда консоли по хексу

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            fontInfo.dwFontSize.X = size; 
            fontInfo.dwFontSize.Y = size; 

            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& Bold() { // Жирный текст всей консоли (не работает в связке с RGB или HEX)
            cout << "\033[1m";

            return *this;
        }

        ConsoleSetting& Line() { // Подчеркнутый текст всей консоли
            cout << "\033[4m";

            return *this;
        }

        ConsoleSetting& Normal() { // Простой текст всей консоли (Не работает в связке с RGB или HEX)
            cout << "\033[0m";

            return *this;
        }

        ConsoleSetting& PositionCursor(int X, int Y) { // конструктор позиции курсора в консоли
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD position{};
            position.X = X;
            position.Y = Y;
            SetConsoleCursorPosition(hConsole, position);

            return *this;
        }

        inline int GetCursorPosition_X() { // возвращает значение позиции курсора по X
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.X;
        }

        inline int GetCursorPosition_Y() {  // возвращает значение позиции курсора по Y
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.Y;
        }

    };



    // класс анимации

    class Animation : ConsoleSetting {
    private:
        int ZERO = 0;
    public:
        string LEFT = "LEFT";
        string RIGHT = "RIGHT";
        string UP = "UP";
        string DOWN = "DOWN";

        Animation& AnimationText(string text, int time) { // анимация текста
            for (int i = 0; i < text.length(); i++) {
                cout << text[i]; Sleep(time);
            }
            return *this;
        }

        void ConsoleFadeIn(int time) { // появление консоли
            for (int i = 0; i < 100; i++)
            {
                static double op = 0.0;
                Opacity(op += 0.01);
                Sleep(time / 100);
            }
        }

        void ConsoleFadeOut(int time) { // исчезновение консоли
            for (int i = 0; i < 100; i++)
            {
                static double op = 1.0;
                Opacity(op -= 0.01);
                Sleep(time / 100);
            }
        }

        void Console_LeftToRigth(int X, int Y) { // плавное (псевдоплавное) появление консоли слева направо
            Size(ZERO, Y);
            for (int i = 0; i < X; i++)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_RightToLeft(int X, int Y) { // плавное (псевдоплавное) появление консоли справа налево
            Size(X, Y);
            for (int i = X; i != 0; i--)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_UpToDown(int X, int Y) { // плавное (псевдоплавное) появление консоли сверху вниз
            Size(X, ZERO);
            for (int i = 0; i < Y; i++)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_DownToUp(int X, int Y) { // плавное (псевдоплавное) появление консоли снизу вверх
            Size(X, Y);
            for (int i = Y; i != 0; i--)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_CustomAnimate(int X0, int X1, int Y0, int Y1, int time, string direction) { // кастомная анимация
            if (direction == "LEFT")
            {
                Size(X0, Y0);
                for (int i = X0; i < X1; i++)
                {
                    Size(i, Y0);
                    Sleep(time / (X1 - X0));
                }
            }
            if (direction == "RIGHT")
            {
                Size(X0, Y0);
                for (int i = X0; i != X1; i--)
                {
                    Size(i, Y0);
                    Sleep(time / (X0 - X1));
                }
            }
            if (direction == "UP")
            {
                Size(X0, Y0);
                for (int i = Y0; i < Y1; i++)
                {
                    Size(X0, i);
                    Sleep(time / (Y1 - Y0));
                }
            }
            if (direction == "DOWN")
            {
                Size(X0, Y0);
                for (int i = Y0; i != Y1; i--)
                {
                    Size(X0, i);
                    Sleep(time / (Y0 - Y1));
                }
            }
        }
        
    };

}