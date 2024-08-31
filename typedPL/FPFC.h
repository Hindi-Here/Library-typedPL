#pragma once
#include <iostream>

#include <vector> 
#include <deque>
#include <set>
#include <algorithm>

#include <string> 
#include <fstream> 
#include <sys/stat.h>

#include <windows.h> 
#include <shellapi.h>
#include <stdlib.h>
#include <sstream>

#include <regex> 

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#include <random> // random generation for clas List
random_device rd;
mt19937 gen(rd());

#ifdef _MSC_VER // delete C++20 version errors in Windows.h
#if _MSC_VER >= 1910 
#ifndef NOMINMAX
#define NOMINMAX 
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 
#endif
#endif
#endif

namespace FunctionalLIB_Array {

    // List container

    template <class T> class List {
    protected:
        deque<T> value;
    public:
        List() = default;
        List(size_t S) { value.resize(S); }
        List(initializer_list<T> P) : value(P) { }
        ~List() = default;

        typename deque<T>::iterator begin() { return value.begin(); } // iterators for interactive with standart methods
        typename deque<T>::iterator end() { return value.end(); }

        inline int First() { return 0; } // constant  return 0
        inline int Count() { return (int)value.size(); } // return size array
        inline T FirstElement() { return value[0]; } // return First elem
        inline T LastElement() { return value[value.size() - 1]; } // return Last elem

        T& operator[](int index) { return value[index]; } // indexing array : arr[0] = T 

        List& operator+(T arg) { // operators + - * / % for argument or List array
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+(List<T>& arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-(List<T>& arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*(List<T>& arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/(T arg) {
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/(List<T>& arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] /= arg[i];

            return *this;
        }

        List& operator%(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator+=(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] += arg;

            return *this;
        }

        List& operator+=(List<T> arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arg[i];

            return *this;
        }

        List& operator-=(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] -= arg;

            return *this;
        }

        List& operator-=(List<T> arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arg[i];

            return *this;
        }

        List& operator*=(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] *= arg;

            return *this;
        }

        List& operator*=(List<T> arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arg[i];

            return *this;
        }

        List& operator/=(T arg) {
            if (arg == 0)
                value.clear();

            for (int i = 0; i < value.size(); i++)
                value[i] /= arg;

            return *this;
        }

        List& operator/=(List<T> arg) {
            int mAx = max((int)value.size(), (int)arg.Count());
            value.resize(mAx); arg.Resize(mAx);
            for (int i = 0; i < mAx; i++)
                if (arg[i] != 0)
                    value[i] /= arg[i];

            return *this;
        }

        List& operator%=(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] = fmod(value[i], arg);

            return *this;
        }

        List& operator=(T arg) {
            for (int i = 0; i < value.size(); i++)
                value[i] = arg;

            return *this;
        }

        List& operator++() { // increment all Elem
            for (int i = 0; i < value.size(); i++)
                value[i] += 1;

            return *this;
        }

        List& operator--() { // decrement all Elem
            for (int i = 0; i < value.size(); i++)
                value[i] -= 1;

            return *this;
        }


        inline double Sum() { // return sum
            double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result;
        }

        inline double Avg() { // return average 
            double result = 0;
            for (int i = 0; i < value.size(); i++)
                result += value[i];

            return result / value.size();
        }

        inline T Max() { // return MAX Elem
            T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result < value[i])
                    result = value[i];

            return result;
        }

        inline T Min() { // return MIN Elem
            T result = value[0];
            for (int i = 1; i < value.size(); i++)
                if (result > value[i])
                    result = value[i];

            return result;
        }

        inline T GetElement(size_t index) { // return Elen by index
            return value[index];
        }

        inline T Median() { // return central Elem in array
            return value[value.size() / 2];
        }

        inline void Clear() { // clear values in array
            value.clear();
        }

        List<char> ToCharArray(string text) { // create char array from text
            List<char> arr;
            for (int i = 0; i < text.length(); i++)
                arr.Add(text[i]);

            return arr;
        }

        inline List<string> Split(string text, char text_spl) { // function for substring
            List<string> arr;
            string str;
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == text_spl)
                {
                    arr.Add(str);
                    str.clear();
                }
                else
                {
                    str += text[i];
                }
            }
            arr.Add(str);

            return arr;
        }

        inline bool Search(T arg) { // search value in array
            bool flag = false;
            for (int i = 0; i < value.size(); i++)
            {
                if (value[i] == arg)
                {
                    flag = true;
                    break;
                }
            }
            return flag;
        }

        inline bool Search(initializer_list<T> list) {
            List<T> arr = list;
            bool flag = false;
            for (int i = 0; i < value.size(); i++)
            {
                for (int j = 0; j < arr.Count(); j++)
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

        int SearchCount(T arg) { // search coincidences in array
            int Count = 0;
            for (int i = 0; i < value.size(); i++)
                if (value[i] == arg)
                    Count++;

            return Count;
        }

        int SearchCount(initializer_list<T> list) {
            List<T> arr = list;
            int Count = 0;
            for (int i = 0; i < value.size(); i++)
            {
                for (int j = 0; j < arr.Count(); j++)
                {
                    if (value[i] == arr[j])
                    {
                        Count++;
                        continue;
                    }
                }
            }
            return Count;
        }

        inline bool Equals(List<T> arr_list) { // comparison arr & arr
            bool flag = true;

            if (value.size() != arr_list.Count())
                flag = false;
            else
            {
                for (int i = 0; i < value.size(); i++)
                {
                    if (value[i] != arr_list[i])
                    {
                        flag = false; break;
                    }
                }
            }
            return flag;
        }

        string ToString() { // convert array in text
            stringstream ss;
            for (int i = 0; i < value.size(); i++)
                ss << value[i];

            return ss.str();
        }

        List& Resize(int size) { // change size array
            value.resize(size);
            return *this;
        }

        List& Sort() { // sort 0...3...11...
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

        List& Converse() { // Reverse array
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

        template <typename X = T> // inversion only numbers
        typename enable_if<is_arithmetic<X>::value, List<X>>::type Inversion() {

            for (int i = 0; i < value.size(); i++) {
                if (value[i] != 0)
                    value[i] = -value[i];
            }

            return *this;
        }

        List& RandInt(int min, int max) { // rand methods
            uniform_int_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& RandDouble(double min, double max) {
            uniform_real_distribution<> generation(min, max);
            for (int i = 0; i < value.size(); i++)
                value[i] = generation(gen);

            return *this;
        }

        List& Fill(T arg) { // fill the array with values
            for (int i = 0; i < value.size(); i++)
                value[i] = arg;

            return *this;
        }

        List& FillPart(T arg, int start, int end) { // fill range
            for (int i = 0; i < value.size(); i++)
                if (i >= start - 1 and i <= end - 1)
                    value[i] = arg;

            return *this;
        }

        List& Change(T found, T replace) { // replace values in array
            for (int i = 0; i < value.size(); i++)
                if (value[i] == found)
                    value[i] = replace;

            return *this;
        }

        List& Union(List<T>& arr_list) { // arr = arr + arr
            List<T> arr = arr_list;
            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy() { // copy array : arr = arr + arr
            List<T> arr;
            for (auto s : value)
                arr.Add(s);

            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& Copy(int length) { // copy N count
            List<T> arr = value;
            for (int len = 0; len < length; len++)
            {
                for (int i = 0; i < arr.size(); i++)
                    value.push_back(arr[i]);
            }

            return *this;
        }

        List& Add(T arg) { // add argument, list to array
            value.push_back(arg);
            return *this;
        }

        List& Add(initializer_list<T> list) {
            List<T> arr = list;
            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& AddFirst(T arg) {  // add in start argument, list
            value.push_front(arg);
            return *this;
        }

        List& AddFirst(initializer_list<T> list) {
            List<T> arr = list;
            for (int i = 0; i < arr.Count(); i++)
                value.push_front(arr[i]);

            return *this;
        }

        List& RemoveFirst() { // delete Elem from the start
            value.pop_front();
            return *this;
        }

        List& RemoveLast() { // delete Elem from the end
            value.pop_back();
            return *this;
        }

        List& NewList(initializer_list<T> list) {
            value.clear();
            List<T> arr = list;
            for (int i = 0; i < arr.Count(); i++)
                value.push_back(arr[i]);

            return *this;
        }

        List& NewList(List<T> arr_list) { // clear last array and fill new array
            value.clear();

            for (int i = 0; i < arr_list.Count(); i++)
                value.push_back(arr_list[i]);

            return *this;
        }

        List& DeleteByIndex(int index) {  // delete Elem by index number or range
            value.erase(value.begin() + index);
            return *this;
        }

        List& DeleteByIndex(int start, int end) {
            for (int i = end; i >= start; i--) {
                value.erase(value.begin() + i);
            }

            return *this;
        }

        List& DeleteByArgs(T arg) { // delete argument or list arguments from array
            for (int i = 0; i < value.size(); i++)
                if (value[i] == arg)
                    value.erase(value.begin() + i);

            return *this;
        }

        List& DeleteByArgs(initializer_list<T> list) {
            for (auto it = value.begin(); it != value.end(); ) {
                if (find(list.begin(), list.end(), *it) != list.end()) {
                    it = value.erase(it);
                }
                else {
                    ++it;
                }
            }

            return *this;
        }

        List& DeleteByArgs(List<T> arr_list) {
            for (auto it = value.begin(); it != value.end(); ) {
                if (find(arr_list.begin(), arr_list.end(), *it) != arr_list.end()) {
                    it = value.erase(it);
                }
                else {
                    ++it;
                }
            }

            return *this;
        }

        List& CutStart(int length) { // cut from the start array
            value.erase(value.begin(), value.begin() + length);

            return *this;
        }

        List& CutEnd(int length) { // cut from the end array
            value.erase(value.end() - length, value.end());

            return *this;
        }

        List& Unique() { // clear repeat Elem
            set<T> arr;

            for (auto s : value)
                arr.insert(s);

            value.clear();

            for (auto s : arr)
                value.push_front(s);

            return *this;
        }

        List& Addition(List<T> arr_list) { // arr + arr
            int mAx = max((int)value.size(), (int)arr_list.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] += arr_list[i];

            return *this;
        }

        List& Subtract(List<T> arr_list) { // arr - arr
            int mAx = max((int)value.size(), (int)arr_list.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] -= arr_list[i];

            return *this;
        }

        List& Multiplication(List<T> arr_list) { // arr * arr
            int mAx = max((int)value.size(), (int)arr_list.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                value[i] *= arr_list[i];

            return *this;
        }

        List& Divide(List<T> arr_list) { // arr / arr
            int mAx = max((int)value.size(), (int)arr_list.Count());
            value.resize(mAx);
            for (int i = 0; i < mAx; i++)
                if (arr_list[i] != 0)
                    value[i] /= arr_list[i];

            return *this;
        }

        vector<T> ToVector() { // convert List to vector
            vector<T> arr;
            for (int i = 0; i < value.size(); i++)
                arr.push_back(value[i]);

            return arr;
        }

    };

    template <typename T>
    List<T> ToTypedPL_List(vector<T> vect) { // convert vector to List
        List<T> arr;
        for (int i = 0; i < vect.size(); i++)
            arr.Add(vect[i]);

        return arr;
    }

    List<double> ProgressionA(double firstElem, int stepCount, double stepValue) { // arifmetic progression
        FunctionalLIB_Array::List<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem += stepValue;
            arr.Add(firstElem);
        }
        return arr;
    }

    List<double> ProgressionG(double firstElem, int stepCount, double stepValue) { // geometry progression
        FunctionalLIB_Array::List<double> arr = { firstElem };
        for (int i = 1; i < stepCount; i++)
        {
            firstElem *= stepValue;
            arr.Add(firstElem);
        }
        return arr;
    }

}

// String function

namespace FunctionalLIB_String {

    class String {
    private:
        string newSTR;
    public:
        String() = default;
        String(const char* value) { newSTR = (string)value; };
        String(string value) : newSTR(value) { }
        ~String() = default;

        friend ostream& operator<<(ostream& os, const String& str) { // output string
            os << str.newSTR;
            return os;
        }

        friend istream& operator>>(istream& input, String& str) { // cin >> string
            input >> str.newSTR;
            return input;
        }

        bool operator!=(const String& str) { return newSTR != str.newSTR; } // for IF operators

        bool operator==(const String& str) { return newSTR == str.newSTR; }

        bool operator>=(const String& str) { return newSTR >= str.newSTR; }

        bool operator>(const String& str) { return newSTR > str.newSTR; }

        bool operator<=(const String& str) { return newSTR <= str.newSTR; }

        bool operator<(const String& str) { return newSTR < str.newSTR; }



        String& operator=(const char* str) { newSTR = str; return *this; } // Str1 = "text"

        String& operator=(char symbol) { stringstream ss; ss << symbol; newSTR = ss.str(); return *this; } // Str[0] = 'S'

        String& operator=(const string& str) { newSTR = str; return *this; } // Str1 = str2

        template <typename T>  String& operator=(T arg) { newSTR = to_string(arg); return *this; } // Str1 = T



        String& operator+=(char symbol) { stringstream ss; ss << symbol; newSTR += ss.str(); return *this; } // Str += 'S'

        String& operator+=(const char* str) { newSTR += str; return *this; } // Str += "text

        String& operator+=(const string& str) { newSTR += str; return *this; }  // Str += str

        String& operator+=(const String& text) { string txt = text.ToString(); newSTR += txt; return *this; } // Str += Str

        template <typename T>  String& operator+=(T arg) { newSTR += to_string(arg); return *this; } // Str += T



        String& operator[](int index) { newSTR = newSTR[index]; return *this; }



        String& operator+(char symbol) { stringstream ss; ss << symbol; newSTR += ss.str(); return *this; } // Str += 'S'

        String& operator+(const char* str) { newSTR += str; return *this; } // Str + "text"

        String& operator+(const string& str) { newSTR += str; return *this; } // Str + str

        String& operator+(const String& text) {
            newSTR += text.ToString();
            return *this;
        } // Str + Str

        template <typename T>  String& operator+(T arg) { newSTR += to_string(arg); return *this; } // Str + T



        template <typename T> String ToTypedPL_String(T str) { newSTR = str; return newSTR; }

        String& operator-(int len) { newSTR.erase(newSTR.end() - len, newSTR.end()); return *this; } // Str - 2 = S

        String& operator-(char symbol) {
            String str = ToTypedPL_String(newSTR); str.Replace(symbol, NULL);
            newSTR = str.ToString(); return *this;
        } // Str - 't' = Sr

        String& operator-(const char* text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos)
                newSTR.replace(pos, strlen(text), "");

            return *this;
        }

        String& operator-(const string& text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos) {
                newSTR.replace(pos, text.length(), "");
            }
            return *this;
        }

        String& operator-(const String& text) {
            string s = text.ToString();
            size_t pos = newSTR.find(s);
            if (pos != string::npos) {
                newSTR.replace(pos, s.length(), "");
            }
            return *this;
        }



        String& operator/(int KF) {
            if (KF == 0) { newSTR.clear(); }
            newSTR.erase(newSTR.end() - newSTR.length() / KF, newSTR.end()); return *this;
        } // Str / 0,1 = NULL



        void Print() const { // outpur String 
            cout << newSTR;
        }

        void Print(const char* text) const {
            cout << newSTR << text;
        }

        void Print(const string& text) const {
            cout << newSTR << text;
        }

        void Print(const String& text) const {
            cout << newSTR << text;
        }

        string ToString() const {  // convert String in string
            return string(newSTR);
        }

        template <typename T> string ToString(T arg) {
            stringstream ss;
            ss << newSTR << arg;
            return ss.str();
        }

        template <typename T> string ToString(initializer_list<T> arg) {
            FunctionalLIB_Array::List<T> arr = arg;
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arr.Count(); i++)
                ss << arr[i];

            return ss.str();
        }

        template <typename T> string ToString(FunctionalLIB_Array::List<T> arg) {
            stringstream ss;
            ss << newSTR;
            for (int i = 0; i < arg.Count(); i++)
                ss << arg[i];

            return ss.str();
        }

        int Length() { return (int)newSTR.length(); } // return symbols count

        void Clear() { newSTR.clear(); } // cleat text

        bool Search(char symbol) { // search values in text
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

        bool Search(const string& text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos)
                return true;
            else
                return false;
        }

        bool Search(initializer_list<char> arg) {
            FunctionalLIB_Array::List<char> arr = arg;
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

        bool Search(const FunctionalLIB_Array::List<char>& arg) {
            FunctionalLIB_Array::List<char> arr = arg;
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

        int SearchCount(char symbol) { // search coincidences count
            int Count = 0;
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    Count++;

            return Count;
        }

        int SearchCount(const string& text) {
            int count = 0;
            size_t pos = newSTR.find(text);
            while (pos != string::npos) {
                count++;
                pos = newSTR.find(text, pos + 1);
            }
            return count;
        }

        int SearchCount(initializer_list<char> arg) {
            FunctionalLIB_Array::List<char> arr = arg;
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

        int SearchCount(const FunctionalLIB_Array::List<char>& arg) {
            FunctionalLIB_Array::List<char> arr = arg;
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

        bool Equals(const string& text) { // comparison arr & arr
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

        bool EqualsMax(const string& text) {
            if (newSTR.length() > text.length())
                return true;
            else
                return false;
        }

        bool EqualsMin(const string& text) {
            if (newSTR.length() < text.length())
                return true;
            else
                return false;
        }

        bool Equals(const String& text) {
            bool flag = true;
            string txt = text.ToString();
            if (newSTR.length() != txt.length())
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

        bool EqualsMax(const String& text) {
            if (newSTR.length() > text.ToString().length())
                return true;
            else
                return false;
        }

        bool EqualsMin(const String& text) {
            if (newSTR.length() < text.ToString().length())
                return true;
            else
                return false;
        }

        char GetFirstElement() { // return First symbol
            return newSTR[0];
        }

        char GetLastElement() { // return Last symbol
            return newSTR[newSTR.length() - 1];
        }

        char GetElement(int index) { // get Elem by index
            for (int i = 0; i < newSTR.length(); i++)
                if (i == index)
                    return newSTR[i];

            return '0';
        }

        FunctionalLIB_Array::List<char> ToCharArray() { // create List array from text
            FunctionalLIB_Array::List<char> arr;
            for (int i = 0; i < newSTR.length(); i++)
                arr.Add(newSTR[i]);

            return arr;
        }

        FunctionalLIB_Array::List<string> Split(char symbol) { // function for substring
            FunctionalLIB_Array::List<string> arr;
            string str;
            for (int i = 0; i < newSTR.length(); i++)
            {
                if (newSTR[i] == symbol)
                {
                    arr.Add(str);
                    str.clear();
                }
                else
                {
                    str += newSTR[i];
                }
            }
            arr.Add(str);

            return arr;
        }

        String& ToUpper() { // to Upper symbols
            transform(newSTR.begin(), newSTR.end(), newSTR.begin(), ::toupper);
            return *this;
        }

        String& ToLower() { // to Lower symbols
            transform(newSTR.begin(), newSTR.end(), newSTR.begin(), ::tolower);
            return *this;
        }

        String& Reverse() { reverse(newSTR.begin(), newSTR.end()); return *this; }

        String& Replace(char found, char replace) {
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == found)
                    newSTR[i] = replace;

            return *this;
        }

        String& Add(const string& arg) { // add symbols in text
            newSTR += arg;
            return *this;
        }

        String& Add(char symbol) {
            newSTR.push_back(symbol);
            return *this;
        }

        template <typename T> String& Add(initializer_list<T> arg) {
            FunctionalLIB_Array::List<T> arr = arg;
            for (int i = 0; i < arr.Count(); i++)
                newSTR += to_string(arr[i]);

            return *this;
        }

        String& NewString(const string& arg) { // clear last string and create new
            newSTR = arg;
            return *this;
        }

        String& SwapString(String& text) { // swap string : A = B, B = A
            String temp = *this;
            *this = text;
            text = temp;
            return *this;
        }

        String& CutStart(int length) { // cut symbols from the start, end, or range
            newSTR.erase(newSTR.begin(), newSTR.begin() + length);
            return *this;
        }

        String& CutEnd(int length) {
            newSTR.erase(newSTR.end() - length, newSTR.end());
            return *this;
        }

        String& CutRange(int start, int end) {
            newSTR.erase(start, end);
            return *this;
        }

        String& Remove(char symbol) {
            for (int i = 0; i < newSTR.length(); i++)
                if (newSTR[i] == symbol)
                    newSTR[i] = NULL;

            return *this;
        }

        String& Remove(initializer_list<char> arg) {
            FunctionalLIB_Array::List<char> arr = arg;
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

        String& Remove(FunctionalLIB_Array::List<char> arg) {
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

        String& Remove(const String& text) {
            string s = text.ToString();
            size_t pos = newSTR.find(s);
            if (pos != string::npos) {
                newSTR.replace(pos, s.length(), "");
            }
            return *this;
        }

        String& Remove(const string& text) {
            size_t pos = newSTR.find(text);
            if (pos != string::npos) {
                newSTR.replace(pos, text.length(), "");
            }
            return *this;
        }

        String& Remove_LastSymbol() { // delete Last symbol from text
            newSTR.pop_back();
            return *this;
        }

        String& Remove_FirstSymbol() { // delete First symbol from text
            newSTR = newSTR.substr(1);
            return *this;
        }

        String& RemoveA_z() { // delete group symbols from text
            regex regex("[a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& RemoveА_я() {
            regex regex("[а-яА-Я]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveNum() {
            regex regex("[0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& RemoveAnother() {
            regex regex("[[:punct:]№]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptA_z() { // delete everything except method group symbols
            regex regex("[^a-zA-Z]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptА_я() {
            regex regex("[^а-яА-Я]");
            newSTR = regex_replace(newSTR, regex, "");
            return*this;
        }

        String& ExceptNum() {
            regex regex("[^0-9]");
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Remove(string str) { // expression delete
            regex regex(str);
            newSTR = regex_replace(newSTR, regex, "");
            return *this;
        }

        String& Regular_Replace(const string& str, const string& replace) { // replace in regular expression
            regex regex(str);
            newSTR = regex_replace(newSTR, regex, replace);
            return *this;
        }

    };

    template <typename T> String ToTypedPL_String(T str) { // convert string to String
        stringstream ss;
        ss << str;
        return ss.str().c_str();
    }

}

// File function

namespace FunctionalLIB_File {
    class File {
    private:
        string str;
        struct stat fileStat {};

        LPCWSTR ConvertTo(const string& inputStr) {
            int size_needed = MultiByteToWideChar(CP_ACP, 0, inputStr.c_str(), -1, NULL, 0);
            wchar_t* wstr = new wchar_t[size_needed];
            MultiByteToWideChar(CP_ACP, 0, inputStr.c_str(), -1, wstr, size_needed);
            return wstr;
        }

    public:
        File() = default;
        File(const char* text) : str(text) { }
        File(string text) : str(text) { }
        File(FunctionalLIB_String::String text) : str(text.ToString()) {  }
        ~File() = default;

        void FileOpen() {  // open program, file, link  
            LPCWSTR result = ConvertTo(str);
            ShellExecute(NULL, L"open", result, NULL, NULL, SW_SHOW);
        }

        File& FileMove(const string& moveIN) {  // file change location
            LPCWSTR thisPath = ConvertTo(str);
            LPCWSTR nextPath = ConvertTo(moveIN);
            MoveFile(thisPath, nextPath);
            return *this;
        }

        File& FileCreate() { // create new file 
            ofstream write(str);
            write << "";
            return *this;
        }

        void FileRemove() { // delete existing file
            LPCWSTR newSTR = ConvertTo(str);
            DeleteFile(newSTR);
        }

        File& FileRename(const string& newName) { // rename existing file
            if (rename(str.c_str(), newName.c_str()) == 0) {}
            return *this;
        }

        FunctionalLIB_Array::List<string> ReadAllLines() { // create List<string> array, where index = line in file
            ifstream read(str);
            FunctionalLIB_Array::List<string> arr; string line;
            while (getline(read, line))
                arr.Add(line);

            return arr;
        }

        vector<string> ReadAllLines_Vector() { // create vector<string> array, where index = line in file
            ifstream read(str);
            vector<string> arr; string line;
            while (getline(read, line))
                arr.push_back(line);

            return arr;
        }

        string ReadAllText() { // create string from file content
            ifstream read(str);
            string a; string line;
            while (getline(read, line))
                a += line;

            return a;
        }

        template <typename T> File& WriteAllText(T text) { // write info in file
            ofstream write(str);
            write << text;
            return *this;
        }

        template <typename T> File& WriteAllText(T text, string format) {
            ofstream write(str);
            write << text << format;
            return *this;
        }

        template <typename T> File& WriteAllLines(FunctionalLIB_Array::List<T> arr) { // write info in file and go to new line
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

        template <typename T> File& AppendAllText(T text) { // add info in file
            ofstream write(str, ios::app);
            write << text;
            return *this;
        }

        template <typename T> File& AppendAllText(T text, string format) {
            ofstream write(str, ios::app);
            write << text << format;
            return *this;
        }

        template <typename T> File& AppendAllLines(FunctionalLIB_Array::List<T> arr) {
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

        // Information about File

        double GetBitSize() {
            double size(0);
            if (stat(str.c_str(), &fileStat) == 0)
                size = fileStat.st_size * 8;

            return size;
        }

        double GetByteSize() {
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

        string GetFileName() {
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

        string GetFilePath() {
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

        string GetFileExtension() {
            fstream fs(str);
            if (fs.is_open())
            {
                size_t lastDot = str.find_last_of('.');
                if (lastDot != std::string::npos) {
                    return str.substr(lastDot + 1);
                }
            }
            return "";
        }

        int GetFileDepth() {
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

    template <class T> void ThisBold(T Text) {  // B
        cout << "\033[1m" << Text << "\033[0m";
    }

    template <class T> void ThisNormal(T Text) { // normal
        cout << "\033[0m" << Text << "\033[0m";
    }

    template <class T> void ThisLine(T Text) { // U
        cout << "\033[4m" << Text << "\033[0m";
    }

    template <class T> void ThisRGB(T Text, int R, int G, int B) { // RGB
        cout << "\033[38;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    template <class T> void ThisForegroundRGB(T Text, int R, int G, int B) { // background text
        cout << "\033[48;2;" << R << ";" << G << ";" << B << "m" << Text << "\033[0m";
    }

    void Clear() {
        system("cls");
    }

    void Close() {
        exit(0);
    }

    // class for setting console

    class ConsoleSetting {

    private:
        HANDLE hConsole{};

        int Red = 0, Green = 0, Blue = 0;

        void BG_COLOR() {
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

        // Window

        ConsoleSetting& WindowShow(bool visible) {
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

        ConsoleSetting& WindowMaxShow(bool visible) {
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

        ConsoleSetting& WindowMinShow(bool visible) {
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

        ConsoleSetting& WindowCloseShow(bool visible) {
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

        ConsoleSetting& WindowPanelShow(bool visible) {
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

        ConsoleSetting& Title(const char* title) {
            char command[100];
            strcpy_s(command, "title ");
            strcat_s(command, title);
            system(command);

            return *this;
        }

        ConsoleSetting& Icon(const char* path) {
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

        ConsoleSetting& ScrollBarShow(bool visible) {
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

        ConsoleSetting& PositionConsole(int X, int Y) {
            HWND consoleWindow = GetConsoleWindow();
            SetWindowPos(consoleWindow, NULL, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

            return *this;
        }

        ConsoleSetting& FullScreen() {
            HWND console = GetConsoleWindow();
            ShowWindow(console, SW_MAXIMIZE);

            return *this;
        }

        ConsoleSetting& Resize(bool can) {
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

        ConsoleSetting& Size(int X, int Y) {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SMALL_RECT windowSize = { 0, 0, (SHORT)X, (SHORT)Y };
            SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

            return *this;
        }

        ConsoleSetting& SizePixel(int X, int Y) {
            HWND console = GetConsoleWindow();
            RECT rect;
            GetWindowRect(console, &rect);

            MoveWindow(console, rect.left, rect.top, X, Y, TRUE);

            return *this;
        }

        ConsoleSetting& MaxSize(int X, int Y) {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD bufferSize = { (SHORT)X, (SHORT)Y };

            SetConsoleScreenBufferSize(hConsole, bufferSize);

            return *this;
        }

        inline int GetConsoleSize_X() {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            return Width;
        }

        inline int GetConsoleSize_Y() {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            return Height;
        }

        inline int GetConsoleSizePixel_X() {
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleWidth = consoleRect.right - consoleRect.left;
            return consoleWidth;
        }

        inline int GetConsoleSizePixel_Y() {
            HWND consoleWindow = GetConsoleWindow();
            RECT consoleRect;

            GetWindowRect(consoleWindow, &consoleRect);
            int consoleHeight = consoleRect.bottom - consoleRect.top;
            return consoleHeight;
        }

        ConsoleSetting& ChangeEncode() {
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

        inline int GetEncode() {
            return GetConsoleCP();
        }

        // Console

        ConsoleSetting& Opacity(double opacity) {

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

        ConsoleSetting& TextBG_Color() {
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

        ConsoleSetting& TextColor(int R, int G, int B) {
            cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& TextColor(const string& hexColor) {
            unsigned int r = std::stoi(hexColor.substr(1, 2), nullptr, 16);
            unsigned int g = std::stoi(hexColor.substr(3, 2), nullptr, 16);
            unsigned int b = std::stoi(hexColor.substr(5, 2), nullptr, 16);
            cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";

            return *this;
        }

        ConsoleSetting& TextColor(int color) { // Random Color - standart color table
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, color);

            return *this;
        }

        ConsoleSetting& ForegroundColor(int R, int G, int B) {
            cout << "\033[48;2;" << R << ";" << G << ";" << B << "m";

            return *this;
        }

        ConsoleSetting& ForegroundColor(const string& hexColor) {
            unsigned int r = std::stoi(hexColor.substr(1, 2), nullptr, 16);
            unsigned int g = std::stoi(hexColor.substr(3, 2), nullptr, 16);
            unsigned int b = std::stoi(hexColor.substr(5, 2), nullptr, 16);
            cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";

            return *this;
        }

        ConsoleSetting& BackgroundColor(int R, int G, int B) {
            CONSOLE_SCREEN_BUFFER_INFOEX info{};
            info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

            HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfoEx(hConsole, &info);

            info.ColorTable[0] = RGB(R, G, B);

            SetConsoleScreenBufferInfoEx(handleConsole, &info);

            return *this;
        }

        ConsoleSetting& BackgroundColor(const string& hexColor) {
            CONSOLE_SCREEN_BUFFER_INFOEX info{};
            info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

            HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfoEx(handleConsole, &info);

            unsigned int r = std::stoi(hexColor.substr(1, 2), nullptr, 16);
            unsigned int g = std::stoi(hexColor.substr(3, 2), nullptr, 16);
            unsigned int b = std::stoi(hexColor.substr(5, 2), nullptr, 16);
            info.ColorTable[0] = RGB(r, g, b);

            SetConsoleScreenBufferInfoEx(hConsole, &info);

            return *this;
        }

        ConsoleSetting& FontFamily(const string& name) {

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            int size = MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, nullptr, 0);
            wstring wname(size, 0);
            MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, &wname[0], size);

            wcscpy_s(fontInfo.FaceName, wname.c_str());
            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& FontSize(int size) {

            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_FONT_INFOEX fontInfo{};
            fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
            GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            fontInfo.dwFontSize.X = size;
            fontInfo.dwFontSize.Y = size;

            SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

            return *this;
        }

        ConsoleSetting& Bold() {
            cout << "\033[1m";

            return *this;
        }

        ConsoleSetting& Line() {
            cout << "\033[4m";

            return *this;
        }

        ConsoleSetting& Normal() {
            cout << "\033[0m";

            return *this;
        }

        ConsoleSetting& PositionCursor(int X, int Y) {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD position{};
            position.X = X;
            position.Y = Y;
            SetConsoleCursorPosition(hConsole, position);

            return *this;
        }

        inline int GetCursorPosition_X() {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.X;
        }

        inline int GetCursorPosition_Y() {
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            COORD cursorPosition = csbi.dwCursorPosition;
            return cursorPosition.Y;
        }

    };

    // Animation

    class Animation : ConsoleSetting {
    private:
        int ZERO = 0;
    public:
        string LEFT = "LEFT";
        string RIGHT = "RIGHT";
        string UP = "UP";
        string DOWN = "DOWN";

        Animation& AnimationText(const string& text, int time) {
            for (int i = 0; i < text.length(); i++) {
                cout << text[i]; Sleep(time);
            }
            return *this;
        }

        void ConsoleFadeIn(int time) {
            for (int i = 0; i < 100; i++)
            {
                double op = 0.0;
                Opacity(op += 0.01);
                Sleep(time / 100);
            }
        }

        void ConsoleFadeOut(int time) {
            for (int i = 0; i < 100; i++)
            {
                double op = 1.0;
                Opacity(op -= 0.01);
                Sleep(time / 100);
            }
        }

        void Console_LeftToRigth(int X, int Y) {
            Size(ZERO, Y);
            for (int i = 0; i < X; i++)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_RightToLeft(int X, int Y) {
            Size(X, Y);
            for (int i = X; i != 0; i--)
            {
                Size(i, Y);
                Sleep((DWORD)0.75);
            }
        }

        void Console_UpToDown(int X, int Y) {
            Size(X, ZERO);
            for (int i = 0; i < Y; i++)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_DownToUp(int X, int Y) {
            Size(X, Y);
            for (int i = Y; i != 0; i--)
            {
                Size(X, i);
                Sleep((DWORD)0.75);
            }
        }

        void Console_CustomAnimate(int X0, int X1, int Y0, int Y1, int time, const string& direction) { // custom animation
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