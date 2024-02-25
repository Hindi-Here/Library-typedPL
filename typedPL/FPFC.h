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

#include <random> // ��� ������� ������ ��������
random_device rd;
mt19937 gen(rd());

#ifdef _MSC_VER
#if _MSC_VER >= 1910 // �������� ������ MSVC ��� �++17 � ����
#ifndef NOMINMAX
#define NOMINMAX // ���������� ���������� � ��������� windows.h
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // ���������� ������ ���������� windows.h
#endif
#endif
#endif

#include <windows.h> // ������ ��� FunctionalLIB_CustomConsole
#include <shellapi.h>
#include <stdlib.h>
#include <sstream>

#include <regex> // ���������� ���������

#include <sys/stat.h> // ���������� �����

// Array �������

namespace FunctionalLIB_Array {

    // 1. �����

    template<typename T> double Sum(T arg) { // ����� ������������ ���������� ���������
        return arg;
    }

    template<typename T, typename... Args> double Sum(T arg, Args... args) {
        return arg + Sum(args...);
    }

    template<typename T> double Sum(vector<T> arr) { // ����� ��������� ������� �������������
        static T result = 0;
        for (int i = 0; i < arr.size(); i++)
            result += arr[i];

        return result;
    }

    template<typename T, size_t N> double Sum(T(&arr)[N]) { // ����� ��������� ������� ������������
        static T result = 0;
        for (int i = 0; i < N; i++)
            result += arr[i];

        return result;
    }

    template<typename T, size_t N> double Sum(array<T, N> arr) { // ����� ��������� ������� ���� array<T,N>
        static T result = 0;
        for (int i = 0; i < N; i++)
            result += arr[i];

        return result;
    }



    // 2. ������� ��������

    template<typename T> double Avg(T arg) { // ������� ������������ ���������� ���������
        return arg;
    }

    template<typename T, typename... Args> double Avg(T arg, Args... args) {
        return (arg + Avg(args...)) / (sizeof...(args) + 1);
    }

    template<typename T> double Avg(vector<T> arr) { // ������� ��������� ������� �������������
        static double result = 0;
        for (int i = 0; i < arr.size(); i++)
            result += arr[i];

        return result / arr.size();
    }

    template<typename T, size_t N> double Avg(T(&arr)[N]) { // ������� ��������� ������� ������������
        static double result = 0;

        for (int i = 0; i < N; i++)
            result += arr[i];

        return result / N;
    }

    template<typename T, size_t N> double Avg(array<T, N> arr) { // ������� ��������� ������� ���� array<T,N>
        static double result = 0;

        for (int i = 0; i < N; i++)
            result += arr[i];

        return result / N;
    }



    // 3. ��������

    template<typename T> T Max(T arg) { // ������������ �������� ������������ ���������� ���������
        return arg;
    }

    template<typename T, typename... Args> T Max(T arg, Args... args) {
        T maxArg = Max(args...);
        return (arg > maxArg) ? arg : maxArg;
    }

    template<typename T> T Max(vector<T> arr) { // ������������ �������� ��������� ������� �������������
        static T result = arr[0];
        for (int i = 1; i < arr.size(); i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Max(T(&arr)[N]) { // ������������ �������� ��������� ������� ������������
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Max(array<T, N> arr) { // ������������ �������� ��������� ������� ���� array<T,N>
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result < arr[i])
                result = arr[i];

        return result;
    }




    // 4. �������

    template<typename T> T Min(T arg) { // ����������� �������� ������������ ���������� ���������
        return arg;
    }

    template<typename T, typename... Args> T Min(T arg, Args... args) {
        T minArg = Min(args...);
        return (arg < minArg) ? arg : minArg;
    }

    template<typename T> T Min(vector<T> arr) { // ����������� �������� ��������� ������� �������������
        static T result = arr[0];
        for (int i = 1; i < arr.size(); i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Min(T(&arr)[N]) { // ����������� �������� ��������� ������� ������������
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }

    template<typename T, size_t N> T Min(array<T, N> arr) { // ����������� �������� ��������� ������� ���� array<T,N>
        static T result = arr[0];

        for (int i = 0; i < N; i++)
            if (result > arr[i])
                result = arr[i];

        return result;
    }



    // 5 ����������

    template<typename T> T Sort(vector<T>& arr) { // ���������� ������� �������������
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

    template<typename T, size_t N> T Sort(T(&arr)[N]) { // ���������� ������� ������������
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

    template<typename T, size_t N> T Sort(array<T, N>& arr) { // ���������� ������� ���� array<T,N>
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

    string Sort(vector<string>& arr) { // ���������� STRING ������� �������������
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

    template<size_t N> string Sort(string(&arr)[N]) { // ���������� STRING ������� ������������
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

    template<size_t N> string Sort(array<string, N>& arr) { // ���������� STRING ������� ���� array<T,N>
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



    // 6. ������ Reverse

    template<typename T> T Converse(vector<T>& arr) { // ��������� ������� �������������
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

    template<typename T, size_t N> T Converse(T(&arr)[N]) { // ��������� ������� ������������
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

    template<typename T, size_t N> T Converse(array<T, N>& arr) { // ��������� ������� ���� array<T,N>
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

    string Converse(vector<string>& arr) { // ��������� STRING ������� �������������
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

    template<size_t N> string Converse(string(&arr)[N]) { // ��������� STRING ������� ������������
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

    template<size_t N> string Converse(array<string, N>& arr) { // ��������� STRING ������� ���� array<T,N>
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



    // 7. ��������

    double Inversion(double arg) { // �������� �����
        return arg * -1;
    }

    template<typename T> double Inversion(vector<T>& arr) { // �������� ������� �������������
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }

    template<typename T, size_t N> double Inversion(T(&arr)[N]) { // �������� ������� ������������
        for (int i = 0; i < N; i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }

    template<typename T, size_t N> double Inversion(array<T, N>& arr) { // �������� ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] != 0)
                arr[i] *= -1;

        return 0;
    }



    // 8. Random ������ INT  

    template<typename T> int RandInt(T min, T max) { // ��������� ����� �����
        uniform_int_distribution<> generation(min, max);
        return generation(gen);
    }

    template<typename T> int RandInt(T min, T max, vector<T>& arr) { // ��������� ������ ������������� ����
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> int RandInt(T min, T max, T(&arr)[N]) { // ��������� ������ ������������ ����
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> int RandInt(T min, T max, array<T, N>& arr) { // ��������� ������ ���� array<T,N>
        uniform_int_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    // Random ������ DOUBLE

    template<typename T> double RandDouble(T min, T max) { // ��������� ������������ �����
        uniform_real_distribution<> generation(min, max);
        return generation(gen);
    }

    template<typename T> double RandDouble(T min, T max, vector<T>& arr) { // ��������� ������ ������������� ����
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < arr.size(); i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> double RandDouble(T min, T max, T(&arr)[N]) { // ��������� ������ ������������ ����
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }

    template<typename T, size_t N> double RandDouble(T min, T max, array<T, N>& arr) { // ��������� ������ ���� array<T,N>
        uniform_real_distribution<> generation(min, max);
        for (int i = 0; i < N; i++)
            arr[i] = generation(gen);

        return 0;
    }



    // 9. �������

    template<typename T> T Median(vector<T>& arr) { // ������� ��� ���������� �������
        return arr[arr.size() / 2];
    }

    template<typename T, size_t N> T Median(T(&arr)[N]) { // ������� ��� ������������ �������
        return arr[N / 2];
    }

    template<typename T, size_t N> T Median(array<T, N>& arr) { // ������� ��� ������� ���� array<T,N>
        return arr[N / 2];
    }



    // 10. ���������� �������

    template<typename T> T Fill(vector<T>& arr, T value) { //  ���������� ���������� �������
        for (int i = 0; i < arr.size(); i++)
            arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T Fill(T(&arr)[N], T value) { // ���������� ������������ �������
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T Fill(array<T, N>& arr, T value) { // ���������� ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return 0;
    }

    string Fill(vector<string>& arr, string value) { //  ���������� STRING ���������� �������
        for (int i = 0; i < arr.size(); i++)
            arr[i] = value;

        return "";
    }

    template<size_t N> string Fill(string(&arr)[N], string value) { // ���������� STRING ������������ �������
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return "";
    }

    template<size_t N> string Fill(array<string, N>& arr, string value) { // ���������� STRING ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            arr[i] = value;

        return "";
    }

    // ���������� ����� �������

    template<typename T> T FillPart(vector<T>& arr, T value, int start, int end) { //  ���������� ����� ���������� �������
        for (int i = 0; i < arr.size(); i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T FillPart(T(&arr)[N], T value, int start, int end) { // ���������� ����� ������������ �������
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    template<typename T, size_t N> T FillPart(array<T, N>& arr, T value, int start, int end) { // ���������� ����� ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return 0;
    }

    string FillPart(vector<string>& arr, string value, int start, int end) { //  ���������� STRING ����� ���������� �������
        for (int i = 0; i < arr.size(); i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }

    template<size_t N> string FillPart(string(&arr)[N], string value, int start, int end) { // ���������� STRING ����� ������������ �������
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }

    template<size_t N> string FillPart(array<string, N>& arr, string value, int start, int end) { // ���������� STRING ����� ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            if (i >= start - 1 and i <= end - 1)
                arr[i] = value;

        return "";
    }



    // 11. ������ �������� �������

    template<typename T> T Change(vector<T>& arr, T found, T replace) { //  Replace ���������� �������
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    template<typename T, size_t N> T Change(T(&arr)[N], T found, T replace) { // Replace ������������ �������
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    template<typename T, size_t N> T Change(array<T, N>& arr, T found, T replace) { // Replace ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return 0;
    }

    string Change(vector<string>& arr, string found, string replace) { //  Replace STRING ���������� �������
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }

    template<size_t N> string Change(string(&arr)[N], string found, string replace) { // Replace STRING ������������ �������
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }

    template<size_t N> string Change(array<string, N>& arr, string found, string replace) { // Replace STRING ������� ���� array<T,N>
        for (int i = 0; i < N; i++)
            if (arr[i] == found)
                arr[i] = replace;

        return "";
    }



    // 12. ����������� ��������

    template<typename T> vector<T> Union(vector<T>& arr1, vector<T>& arr2) { //  ����������� ��������� ��������
        vector<T> result = {};
        for (int i = 0; i < arr1.size(); i++)
            result.push_back(arr1[i]);

        for (int i = 0; i < arr2.size(); i++)
            result.push_back(arr2[i]);

        return result;
    }



    // 13. ���������� ����� �������

    template<typename T> int Lgth(vector<T>& arr) { // ��� ������������� �������
        int len = (int)arr.size();
        return len;
    }

    template<typename T, size_t N> int Lgth(T(&arr)[N]) { // ��� ������������ �������
        return N;
    }

    template<typename T, size_t N> int Lgth(array<T, N>& arr) { // ��� ������� ���� array<T,N>
        return N;
    }



    // 14. ���������� �������� �������

    template<typename T> vector<T> Add(vector<T>& arr, T value) { // ���������� ��� ������������� �������
        arr.push_back(value);
        return arr;
    }

    template<typename T, size_t N> vector<T> Add(T(&arr)[N], T value) { // ���������� ��� ������������ �������
        vector<T> result;
        for (size_t i = 0; i < N; i++) {
            result.push_back(arr[i]);
        }
        result.push_back(value);
        return result;
    }

    template<typename T, size_t N> array<T, N + 1> Add(array<T, N>& arr, T value) { // ���������� ��� ������� ���� array<T,N>
        array<T, N + 1> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = arr[i];
        }
        result[N] = value;
        return result;
    }

    vector<string> Add(vector<string>& arr, string value) { // ���������� STRING ��� ������������� �������
        arr.push_back(value);
        return arr;
    }

    template<size_t N> vector<string> Add(string(&arr)[N], string value) { // ���������� STRING ��� ������������ �������
        vector<string> result;
        for (size_t i = 0; i < N; i++) {
            result.push_back(arr[i]);
        }
        result.push_back(value);
        return result;
    }

    template<size_t N> array<string, N + 1> Add(array<string, N>& arr, string value) { // ���������� STRING ��� ������� ���� array<T,N>
        array<string, N + 1> result;
        for (size_t i = 0; i < N; i++) {
            result[i] = arr[i];
        }
        result[N] = value;
        return result;
    }



    // 15. LINQ imitation

    template<typename T> bool LINQ_OPERATION(T arg, string operation, T paramIF) { // LINQ ���������
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

    template<typename T> vector<T> LINQ_OPERATION(vector<T>& arr, string operation, T paramIF) // LINQ �������
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

    vector<string> LINQ_OPERATION(vector<string>& arr, string operation, string paramIF) // LINQ STRING �������
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



    // ����� List (�������������) �������

    template <class T> class List { // ���������� �������
    protected:
        deque<T> value;
        struct structure {};
    public:
        List() {}
        List(size_t S) { value.resize(S); }
        List(initializer_list<T> P) { value = P; } // �����������-���������� ������
        ~List() {}

        typename deque<T>::iterator begin() { return value.begin(); } // ���������� ������ �������
        typename deque<T>::iterator end() { return value.end(); } // ���������� ����� �������

        inline int First() { return 0; }
        inline int Last() { return (int)value.size(); }
        inline T FirstElement() { return value[0]; }
        inline T LastElement() { return value[value.size() - 1]; } 

        T& operator[](int index) { return value[index]; } // ���������� ������� �� ��������

        List& operator+(T arg) { // �������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+(List<T>& arg) { //  �������� List ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-(T arg) { // ��������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-(List<T>& arg) { //  ��������� List ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*(T arg) { // ��������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*(List<T>& arg) { //  ��������� List ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/(T arg) { // ������� ������� �������� �� ��������
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/(List<T>& arg) { //  ������� List ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] /= arg[i];

            return *this;
        }

        List& operator%(T arg) { // ������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator+=(T arg) { // �������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+=(List<T> arg) { // �������� ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-=(T arg) { // ��������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-=(List<T> arg) { // ��������� ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*=(T arg) { // ��������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*=(List<T> arg) { // ��������� ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/=(T arg) { // ������� ������� �������� �� ��������
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/=(List<T> arg) { // ������� ��������
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                if(arg[i] != 0)
                    value[i] /= arg[i];

            return *this;
        }

        List& operator%=(T arg) { // ������� ������� �������� �� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator=(T arg) { // ������������ � ������� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] = arg;

            return *this;
        }

        List& operator++() { // ��������� ������� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] += 1;

            return *this;
        }

        List& operator--() { // ��������� ������� ��������
            for (int i = 0; i < value.size(); i++)
                value[i] -= 1;

            return *this;
        }



        inline int Count() { return (int)value.size(); } // ��������� ����� �������

        inline double Sum() { // ����� ��������� List �������
            static double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result;
        }

        inline double Avg() { // ������� ��������� List �������
            static double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result / value.size();
        }

        inline T Max() { // ������������ �������� ��������� List �������
            static T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result < value[i])
                    result = value[i];

            return result;
        }

        inline T Min() { // ����������� �������� ��������� List �������
            static T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result > value[i])
                    result = value[i];

            return result;
        }

        inline T GetElement(size_t index) { // ��������� �������� �� �������
            return value[index];
        }

        inline T Median() { // ������� ��� List �������
            return value[value.size() / 2];
        }

        inline void Clear() { // ������� �������
            value.clear();
        }

        List<char> ToCharArray(string text) { // ��������� ������ �� ���������� ������
            List<char> arr;
            for (int i = 0; i < text.length(); i++)
                arr.Add(text[i]);

            return arr;
        }

        inline List<string> Split(string text, char text_spl) { // ��������� ������ �� ���������
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

        inline bool Search(T V) { // ����� ��������
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

        inline bool Search(initializer_list<T> V) { // ����� �� ������ ��������
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

        inline bool Equals(List<T> V) { // ��������� ��������
            List<T> arr = V;
            bool flag = true;

            if (value.size() != arr.Count()) // �������� �� �����������
                flag = false;
            else
            {
                for (int i = 0; i < value.size(); i++) // �������� �� ��������
                {
                    if (value[i] != arr[i])
                    {
                        flag = false; break;
                    }
                }
            }
            return flag;
        }

        string ToString() { // ��������������� ������� � ������
            stringstream ss;
            for (int i = 0; i < value.size(); i++)
                ss << value[i];

            return ss.str();
        }

        List& Sort() { // ���������� List �������
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

        List& Converse() { // ��������� List �������
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

        template <typename X = T> // �������� ���������
        typename enable_if<is_arithmetic<X>::value, List<X>>::type Inversion() {

           for (int i = 0; i < value.size(); i++) {
                if (value[i] != 0)
                    value[i] = -value[i];
           }

            return *this;
        }

        List& RandInt(int min, int max) { // ��������� List ������
            uniform_int_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& RandDouble(double min, double max) { // ��������� List ������
            uniform_real_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& Fill(T V) { //  ���������� List �������
            for (int i = 0; i < value.size(); i++)
                value[i] = V;

            return *this;
        }

        List& FillPart(T V, int start, int end) { //  ���������� ����� List �������
            for (int i = 0; i < value.size(); i++)
                if (i >= start - 1 and i <= end - 1)
                    value[i] = V;

            return *this;
        }

        List& Change(T found, T replace) { //  Replace List �������
            for (int i = 0; i < value.size(); i++)
                if (value[i] == found)
                    value[i] = replace;

            return *this;
        }

        List& Union(List<T>& arr2) { //  ����������� List ��������
            List<T> arr = arr2;
            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy() { //  ����������� List ��������
            vector<T> arr = value;
            for (int i = 0; i < arr.size(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy(int length) { //  ����������� N ��� List ��������
            vector<T> arr = value;
            for (int len = 0; len < length; len++)
            {
                for (int i = 0; i < arr.size(); i++)
                    value.push_back(arr[i]);
            }

            return *this;
        }

         List& Add(T V) { // ���������� �������� � List ������
            value.push_back(V);
            return *this;
        }

         List& Add(initializer_list<T> P) { // ���������� ������ ���������
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& AddFirst(T V) { // ���������� �������� � ������
             value.push_front(V);
             return *this;
         }

         List& AddFirst(initializer_list<T> P) { // ���������� ������ ��������� � ������
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_front(arr[i]);

             return *this;
         }

         List& RemoveFirst() { // �������� ������
             value.pop_front();
             return *this;
         }

         List& RemoveLast() { // �������� �����
             value.pop_back();
             return *this;
         }
          
         List& NewList(initializer_list<T> P) { // ���������� ������� �� N ��������
             value.clear();
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& NewList(List<T> P) { // ���������� ������� �� ������ ������
             value.clear();
             List<T> arr = P;
             for (int i = 0; i < arr.Count(); i++)
                 value.push_back(arr[i]);

             return *this;
         }

         List& DeleteByIndex(int index) { // �������� �� �������
             value.erase(value.begin() + index);
             return *this;
         }

         List& DeleteByIndex(int start, int end) { // �������� �� ������ ���������
             for (int i = end; i >= start; i--) {
                 value.erase(value.begin() + i);
             }

             return *this;
         }

         List& DeleteByArgs(T arg) { // �������� �� ��������
             for (int i = 0; i < value.size(); i++)
                 if (value[i] == arg)
                     value.erase(value.begin() + i);

             return *this;
         }

         List& DeleteByArgs(initializer_list<T> args) { // �������� �� ������ ��������
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

         List& DeleteByArgs(List<T> args) { // �������� �� ������ �������� List �������
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

         List& CutStart(int length) { // ������� � ������ �������
             value.erase(value.begin(), value.begin() + length);

             return *this;
         }

         List& CutEnd(int length) { // ������� � ����� �������
             value.erase(value.end() - length, value.end());

             return *this;
         }

         List& Unique() { // �������� ������������� ��������
             set<T> arr;

             for (auto s : value)
                 arr.insert(s);

             value.clear();

             for (auto s : arr)
                 value.push_front(s); 

             return *this;
         }

         List& Addition(List<T> arg) { // �������� ��������
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] += arg[i];

             return *this;
         }

         List& Subtract(List<T> arg) { // ��������� ��������
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] -= arg[i];

             return *this;
         }

         List& Multiplication (List<T> arg) { // ��������� ��������
             int mAx = max((int)value.size(), (int)arg.Count());
             value.resize(mAx);
             for (int i = 0; i < mAx; i++)
                 value[i] *= arg[i];

             return *this;
         }

         List& Divide(List<T> arg) { // ������� ��������
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

// String �������

namespace FunctionalLIB_String {

    class String : FunctionalLIB_Array::List<char>, FunctionalLIB_Array::List<string> {
    private:
        string newSTR;
        friend String ToTypedPL_String() {};
    public:
        String() {};
        String(const char* value) { newSTR = (string)value; };
        ~String() {}

        friend ostream& operator<<(ostream& os, const String& str) { // ����� �� ����� ����� cout
            os << str.newSTR;
            return os;
        }

        friend istream& operator>>(istream& input, String& str) { // ���� ���������� ����� cin
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



        template <typename T> String ToTypedPL_String(T str) {}; // ��������� �������

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



        void Print() const { // ����� �� ����� ������
            cout << newSTR;
        }

        void Print(const char* text) const { // ����� �� ����� ������
            cout << newSTR << text;
        }

        void Print(string text) const { // ����� �� ����� ������
            cout << newSTR << text;
        }

        void Print(String text) const { // ����� �� ����� ������
            cout << newSTR << text;
        }

        string ToString() const { // ��������������� � ������ string �� ���� ������
           return string(newSTR);
        }

        template <typename T> string ToString(T arg) { // ��������������� ��������� � ������
            stringstream ss;
            ss << newSTR << arg;
            return ss.str();
        }

        template <typename T> string ToString(initializer_list<T> arg) { // ��������������� ������ � ������
            List<T> arr = arg;
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arr.Count(); i++)
                ss << arr[i];

            return ss.str();
        }

        template <typename T> string ToString(List<T> arg)  { // ��������������� ������� � ������
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arg.Count(); i++)
                ss << arg[i];

            return ss.str();
        }
        
        int Length() { return (int)newSTR.length(); } // ����� ������

        void Clear() { newSTR.clear(); } // ������� ������

        bool Search(char symbol) { // ����� �� �������
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

        bool Search(string text) { // ����� �� ������
            size_t pos = newSTR.find(text);
            if (pos != string::npos)
                return true;
            else
                return false;
        }

        bool Search(initializer_list<char> arg) { // ����� �� ������ ��������
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

        bool Search(List<char> arg) { // ����� �� ������ ��������
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

        int SearchCount(char symbol) { // ������� ���������� �� �������
            static int Count = 0;
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    Count++;

            return Count;
        }

        int SearchCount(string text) { // ������� ���������� �� ������
            static int count = 0;
            size_t pos = newSTR.find(text);
            while (pos != string::npos) {
                count++;
                pos = newSTR.find(text, pos + 1);
            }
            return count;
        }

        int SearchCount(initializer_list<char> arg) { // ����� �� ������ ��������
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

        int SearchCount(List<char> arg) { // ����� �� ������ ��������
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

        bool Equals(string text) { // �������� �� ��������������
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

        bool EqualsMax(string text) { // ��������� �� ��������������
            if (newSTR.length() > text.length())
                return true;
            else
                return false;
        }

        bool EqualsMin(string text) { // ��������� �� �������������
            if (newSTR.length() < text.length())
                return true;
            else
                return false;
        }

        bool Equals(String text) { // �������� �� ��������������
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

        bool EqualsMax(String text) { // ��������� �� ��������������
            if (newSTR.length() > text.Length())
                return true;
            else
                return false;
        }

        bool EqualsMin(String text) { // ��������� �� �������������
            if (newSTR.length() < text.Length())
                return true;
            else
                return false;
        }

        char GetFirstElement() { // �������� ������ ������ ������
            return newSTR[0];
        }

        char GetLastElement() { // �������� ��������� ������
            return newSTR[newSTR.length() - 1];
        }

        char GetElement(int index) { // ��������� �������� �������
            for (int i = 0; i < newSTR.length(); i++)
                if (i == index)
                    return newSTR[i];
        }

        List<char> ToCharArray() { // ��������� ������ �� �������
            List<char> arr;
            for (int i = 0; i < newSTR.length(); i++)
                arr.Add(newSTR[i]);

            return arr;
        }

        List<string> Split(char symbol) { // ��������� ������ �� ���������
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
        
        String& Reverse() { reverse(newSTR.begin(), newSTR.end()); return *this; } // �������� ������

        String& Replace(char found, char replace) { // ������ �������� ������
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == found)
                    newSTR[i] = replace;

            return *this;
        }

        String& Add(string arg) { // ���������� ��������
            newSTR += arg;
            return *this;
        }

        String& Add(char symbol) { // ���������� �������
            newSTR.push_back(symbol);
            return *this;
        }

        template <typename T> String& Add(initializer_list<T> arg) { // �������� ������
            List<T> arr = arg;
            for (int i = 0; i < arr.Count(); i++)
                newSTR += to_string(arr[i]);

            return *this;
        }

        String& AddSymbol(char symbol) { // ���������� �������
            newSTR.push_back(symbol);
            return *this;
        }

        String& NewString(string arg) { // �������������� ������
            newSTR = arg;
            return *this;
        }
  
        String& SwapString(String& text) { // �������� ������
            String temp = *this;
            *this = text;
            text = temp; 
            return *this; 
        }

        String& CutStart(int length) { // ������� � ������ �������
            newSTR.erase(newSTR.begin(), newSTR.begin() + length);
            return *this;
        }

        String& CutEnd(int length) { // ������� � ����� �������
            newSTR.erase(newSTR.end() - length, newSTR.end());
            return *this;
        }
        
        String& CutRange(int start, int end) { // ������� � ���������
            newSTR.erase(start, end);
            return *this;
        }

        String& RemoveSymbol(char symbol) { // �������� �������
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    newSTR[i] = NULL;

            return *this;
        }

        String& Remove(char symbol) { // �������� �������
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    newSTR[i] = NULL;

            return *this;
        }

        String& Remove(initializer_list<char> arg) { // �������� ����� ��������
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

        String& Remove(List<char> arg) { // �������� ������� ��������
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

        String& Remove_LastSymbol() { // �������� ���������� ������� �������
            newSTR.pop_back();
            return *this;
        }

        String& Remove_FirstSymbol() { // �������� ������� ������� �������
            newSTR = newSTR.substr(1);
            return *this;
        }

        String& RemoveA_z() { // ������ ����������� �������
            regex regex("[a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return* this;
        }

        String& Remove�_�() { // ������ ������� �������
            regex regex("[�-��-�]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveNum() { // ������ ��� �������� �������
            regex regex("[0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveAnother() {
            regex regex("[[:punct:]�]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptA_z() { // �������� ������ ����. �������
            regex regex("[^a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& Except�_�() { // �������� ������ ������� �������
            regex regex("[^�-��-�]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptNum() { // �������� ������ �����
            regex regex("[^0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Remove(string str) { // �������� �� ����������� ���������
            regex regex(str);
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Replace(string str, string replace) { // ������ �� ��������
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

// File �������

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

        void FileOpen() { // �������� ����������, ������, �����    
                LPCWSTR result = ConvertTo(str);
                ShellExecute(NULL, L"open", result, NULL, NULL, SW_SHOW);
        }

        File& FileMove(string moveIN) { // ����������� �����
            LPCWSTR thisPath = ConvertTo(str);
            LPCWSTR nextPath = ConvertTo(moveIN);
            MoveFile(thisPath, nextPath);
            return *this;
        }

        File& FileCreate() { // �������� �����
            ofstream write(str);
            write << "";
            return *this;
        }

        void FileRemove() { // �������� �����
            LPCWSTR newSTR = ConvertTo(str);
            DeleteFile(newSTR);
        }

        File& FileRename(string newName) { // �������������� �����
            if (rename(str.c_str(), newName.c_str()) == 0)  {}
            return *this;
        }

        List<string> ReadAllLines() { // ���������� �����
            ifstream read(str);
            List<string> arr; string line;
            while (getline(read, line))
                arr.Add(line);

            return arr;
        }

        vector<string> ReadAllLines_Vector() { // ���������� ����� ��� �������
            ifstream read(str);
            vector<string> arr; string line;
            while (getline(read, line))
                arr.push_back(line);

            return arr;
        }

        string ReadAllText() { // ���������� ����� ������
            ifstream read(str);
            string a; string line;
            while (getline(read, line))
                a += line;

            return a;
        }

        template <typename T> File& WriteAllText(T text) { // ������ ������
            ofstream write(str);
            write << text;
            return *this;
        }

        template <typename T> File& WriteAllText(T text, string format) { // ������ ������ � ��������������
            ofstream write(str);
            write << text << format;
            return *this;
        }

        template <typename T> File& WriteAllLines(List<T> arr) { // ������ ������� ������ ���������
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

        template <typename T> File& AppendAllText(T text) { // ���������� ������
            ofstream write(str, ios::app);
            write << text;
            return *this;
        }

        template <typename T> File& AppendAllText(T text, string format) { // ���������� ������ � ��������
            ofstream write(str, ios::app);
            write << text << format;
            return *this;
        }

        template <typename T> File& AppendAllLines(List<T> arr) { // ���������� ������ �� �������
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
  
        // ���������� � �����

        double GetBitSize() { // ��������� �������� ����� � ������ ��������
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

   

        string GetFileName() { // ��������� ����� �����
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

        string GetFilePath() { // ��������� ���� � �����
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

        string GetFileExtension() { // ��������� ���������� �����
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

        int GetFileDepth() { // ��������� �������
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

    // ��������� ������ (�� ���� �������� ��������� ������)

    template <class T> void ThisBold(T Text) { // ������ ����� (������ ��������)
        cout << "\033[1m" << Text << "\033[0m";
    }

    template <class T> void ThisNormal(T Text) { // ������� ����� (������ ��������)
        cout << "\033[0m" << Text << "\033[0m";
    }

    template <class T> void ThisLine(T Text) { // ������������ ����� (������ ��������)
        cout << "\033[4m" << Text << "\033[0m";
    }

    template <class T> void ThisRGB(T Text, int R, int G, int B) { // RGB ��������� ������
            cout << "\033[38;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    template <class T> void ThisForegroundRGB(T Text, int R, int G, int B) { // ���������� ������ � ���� � ������
        cout << "\033[48;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    void Clear() {  // ������� ����������� �������
        system("cls");
    }

    void Close() { // �������� �������
        exit(0);
    }




    class ConsoleSetting {
    
    private:
        HANDLE hConsole{};

        int Red = 0, Green = 0, Blue = 0;

        void BG_COLOR() { // ����� ��� ����������� ����� �������
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

        // ����� Window

        ConsoleSetting& WindowShow(bool visible) { // ������ / �������� ����� Window 
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

        ConsoleSetting& WindowMaxShow(bool visible) { // ������ / �������� ������ ������������ �� ������ �� window �����
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

        ConsoleSetting& WindowMinShow(bool visible) { // ������ / �������� ������ ������������ �� ������ �� window �����
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

        ConsoleSetting& WindowCloseShow(bool visible) { // ������ / �������� ������ �������� ����� �� ������ �� window �����
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

        ConsoleSetting& WindowPanelShow(bool visible) { // ������ ��� �������� ��� ������ �� window �����
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

        ConsoleSetting& Title(const char* title) { // ����������� ��������� �������
            char command[100];
            strcpy_s(command, "title ");
            strcat_s(command, title);
            system(command);

            return *this;
        }

        ConsoleSetting& Icon(const char* path) { // ������ ����������
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

        ConsoleSetting& ScrollBarShow(bool visible) { // ������ / �������� ��������� ������ ���������
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

        ConsoleSetting& PositionConsole(int X, int Y) { // ������� ������� �� ������
            HWND consoleWindow = GetConsoleWindow();
            SetWindowPos(consoleWindow, NULL, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

            return *this;
        }

        ConsoleSetting& FullScreen() { // ����������� ������� �� ���������� ������
            HWND console = GetConsoleWindow();
            ShowWindow(console, SW_MAXIMIZE);

            return *this;
        }

        ConsoleSetting& Resize(bool can) { // ������ / ���������� �� ������ ��������� �������� �������
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

        ConsoleSetting& Size(int X, int Y) { // ������� �������
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SMALL_RECT windowSize = { 0, 0, (SHORT)X, (SHORT)Y };
            SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

            return *this;
        }

        ConsoleSetting& SizePixel(int X, int Y) { // ��������� ���� � ��������
            HWND console = GetConsoleWindow();
            RECT rect;
            GetWindowRect(console, &rect);

            MoveWindow(console, rect.left, rect.top, X, Y, TRUE);

            return *this;
        }

        ConsoleSetting& MaxSize(int X, int Y) { // ������������ ������ �������
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD bufferSize = { (SHORT)X, (SHORT)Y };

            SetConsoleScreenBufferSize(hConsole, bufferSize);

            return *this;
        }

        inline int GetConsoleSize_X() { // ��������� �������� ������� �� X
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            return Width;
        }

        inline int GetConsoleSize_Y() { // ��������� �������� ������� �� Y
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            return Height;
        }

        inline int GetConsoleSizePixel_X() { // ��������� �������� ������� �� X � ��������
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleWidth = consoleRect.right - consoleRect.left;
            return consoleWidth;
        }

        inline int GetConsoleSizePixel_Y() { // ��������� �������� ������� �� Y � ��������
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleHeight = consoleRect.bottom - consoleRect.top;
            return consoleHeight;
        }

        ConsoleSetting& ChangeEncode() { // ����� ���������
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

        inline int GetEncode() { // ��������� �������� ���������
            return GetConsoleCP();
        }



        // ������ ����� (���������� ������������)

        ConsoleSetting& Opacity(double opacity) { // ������������ �������

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

        ConsoleSetting& TextBG_Color() { // ����������� ��� ���������� ������ � ���� ����
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

        ConsoleSetting& TextColor(int R, int G, int B) { // ����������� ����� ������ ������� �� ���
            cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& TextColor(string hexColor) { // ����������� ����� ������ ������� �� �����
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

        ConsoleSetting& ForegroundColor(int R, int G, int B) { // ����������� ����� ������� ���� ������ ������� �� ���
            cout << "\033[48;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& ForegroundColor(string hexColor) { // �����������  ����� ������� ���� ������ ������� �� �����
            int r, g, b;
            sscanf_s(hexColor.c_str(), "%02x%02x%02x", &r, &g, &b);
            cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";

            return *this;
        }

        ConsoleSetting& BackgroundColor(int R, int G, int B) { // ����������� ����� ���������� ������� �� ���
            CONSOLE_SCREEN_BUFFER_INFOEX info{};
            info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfoEx(hConsole, &info);

            info.ColorTable[0] = RGB(R, G, B);

            SetConsoleScreenBufferInfoEx(hConsole, &info);

            return *this;
        }

        ConsoleSetting& BackgroundColor(string hexColor) { // ����������� ����� ���������� ������� �� �����
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

        ConsoleSetting& FontFamily(string name) { // ����������� ����� ���������� ������� �� �����

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            int size = MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, nullptr, 0);
            wstring wname(size, 0);
            MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, &wname[0], size);

            wcscpy_s(fontInfo.FaceName, wname.c_str()); // ��� ������
            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& FontSize(int size) { // ����������� ����� ���������� ������� �� �����

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            fontInfo.dwFontSize.X = size; 
            fontInfo.dwFontSize.Y = size; 

            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& Bold() { // ������ ����� ���� ������� (�� �������� � ������ � RGB ��� HEX)
            cout << "\033[1m";

            return *this;
        }

        ConsoleSetting& Line() { // ������������ ����� ���� �������
            cout << "\033[4m";

            return *this;
        }

        ConsoleSetting& Normal() { // ������� ����� ���� ������� (�� �������� � ������ � RGB ��� HEX)
            cout << "\033[0m";

            return *this;
        }

        ConsoleSetting& PositionCursor(int X, int Y) { // ����������� ������� ������� � �������
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD position{};
            position.X = X;
            position.Y = Y;
            SetConsoleCursorPosition(hConsole, position);

            return *this;
        }

        inline int GetCursorPosition_X() { // ���������� �������� ������� ������� �� X
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.X;
        }

        inline int GetCursorPosition_Y() {  // ���������� �������� ������� ������� �� Y
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.Y;
        }

    };



    // ����� ��������

    class Animation : ConsoleSetting {
    private:
        int ZERO = 0;
    public:
        string LEFT = "LEFT";
        string RIGHT = "RIGHT";
        string UP = "UP";
        string DOWN = "DOWN";

        Animation& AnimationText(string text, int time) { // �������� ������
            for (int i = 0; i < text.length(); i++) {
                cout << text[i]; Sleep(time);
            }
            return *this;
        }

        void ConsoleFadeIn(int time) { // ��������� �������
            for (int i = 0; i < 100; i++)
            {
                static double op = 0.0;
                Opacity(op += 0.01);
                Sleep(time / 100);
            }
        }

        void ConsoleFadeOut(int time) { // ������������ �������
            for (int i = 0; i < 100; i++)
            {
                static double op = 1.0;
                Opacity(op -= 0.01);
                Sleep(time / 100);
            }
        }

        void Console_LeftToRigth(int X, int Y) { // ������� (�������������) ��������� ������� ����� �������
            Size(ZERO, Y);
            for (int i = 0; i < X; i++)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_RightToLeft(int X, int Y) { // ������� (�������������) ��������� ������� ������ ������
            Size(X, Y);
            for (int i = X; i != 0; i--)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_UpToDown(int X, int Y) { // ������� (�������������) ��������� ������� ������ ����
            Size(X, ZERO);
            for (int i = 0; i < Y; i++)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_DownToUp(int X, int Y) { // ������� (�������������) ��������� ������� ����� �����
            Size(X, Y);
            for (int i = Y; i != 0; i--)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_CustomAnimate(int X0, int X1, int Y0, int Y1, int time, string direction) { // ��������� ��������
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