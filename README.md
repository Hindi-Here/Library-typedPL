Библиотека для языка программирования С++

TypedPL предоставляет набор функций для работы с массивами, строками, файлами, консолью, геометрическими фигурами и выражениями в С++.

Документацию к библиотеке вы можете найти среди файлов проекта (typedPL Documentation.pdf). Каждый раздел был подробно описан с примерами использования методов и функций библиотеки. Помимо этого, вы можете прочитать историю развития, описанную в конце документации, где описаны все изменения, обновления, а также баги, которые были замечены.

**Модули:**
- Geometry.h;
- FPFC.h.

**Разделы:**
- GeometyLIB_Figure;
- GeometryLIB_Expression; 
- FunctionalLIB_Array;
- FunctionalLIB_String;
- FunctionalLIB_File;
- FunctionalLIB_CustomConsole.

  ```
TEST(GroupBy, CountTaxes)
{
    struct Tax {
        std::string name;
        int amount_1;
        int amount_2;

        bool operator ==(const Tax & tax) const {
            return name == tax.name
                && amount_1 == tax.amount_1
                && amount_2 == tax.amount_2;
        }
    };

    std::vector<Tax> taxes = {
        {"tax 1", 1, 1},
        {"tax 2", 1, 1},
        {"tax 1", 2, 2},
        {"tax 3", 3, 3},
        {"tax 1", 4, 4},
    };

    Tax ans[] = {
        {"tax 1", 7, 7},
        {"tax 2", 1, 1},
        {"tax 3", 3, 3},
    };

    auto dst = from(taxes)
        .groupBy([](const Tax & a){return a.name;})
        .select([](const auto & pair){ // use of auto here needs c++14
            return Tax {
                pair.first,
                pair.second.sum([](const Tax & a){return a.amount_1;}),
                pair.second.sum([](const Tax & a){return a.amount_2;})
            };
        });

    CheckRangeEqArray(dst, ans);
}
```

**Раздел Geometry** специализируется на работе с геометрическими фигурами, нахождении их периметра, площади, объемов и поверхностей (используются общие формулы). Также имеется директива констант _USE_CONSTANT_, которая является расширением для _USE_MATH_DEFINES (имеет больше коснтант для разделов общей и высшей математики). Возможно базовая работа с векторами и комплексными числами.

**Раздел FPFC** предоставляет инструенты для работы с контейнерами, строками, файлами, консолью. Более подробно о функциях данного блока вы можете узнать в документации проекта.

**P.S** Код во многих местах не оптимизирован, а некоторые функции могут работать не совсем так, как планировалось. Если есть какие-либо идеи касательно новых функций или другие предложения - обязательно обращайтесь
