#include "linq.hpp"
#include <assert.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <math.h>
#include <iostream>

using linq::from;

void from_to_vector() {
    std::vector<int> xs = { 1, 2, 3 };
    std::vector<int> res = from(xs.begin(), xs.end()).to_vector();
    assert(res == xs);
}

void from_select() {
    const int xs[] = { 1, 2, 3 };
    std::vector<int> res = from(xs, xs + 3).select([](int x) { return x + 5; }).to_vector();
    std::vector<int> expected = { 6, 7, 8 };
    assert(res == expected);
}

void from_drop_select() {
    const int xs[] = { 1, 2, 3 };
    std::vector<int> res = from(xs, xs + 3).drop(1).select([](int x) { return x + 5; }).to_vector();
    std::vector<int> expected = { 7, 8 };
    assert(res == expected);
}

/*
 * MY TESTS
 */

void from_until() {
    std::vector<double>v{1.1, -9.0, 100, 37.7};
    std::vector<double> res = from(v.begin(), v.end())
            .until([](double x){ return x >= 100; })
            .to_vector();
    std::vector<double> expected = {1.1, -9.0};
    assert(res == expected);
}

void from_until_1() {
    std::vector<double>v{1.1, -9.0, 100, 37.7};
    std::vector<double> res = from(v.begin(), v.end())
            .until([](double n){ return n == -9.0; })
            .to_vector();
    std::vector<double> expected = {1.1};
    assert(res == expected);
}

void from_until_eq() {
    std::vector<int>v{11, -90, 100, 377};
    std::vector<int> res = from(v.begin(), v.end())
            .until_eq(-90)
            .to_vector();
    std::vector<int> expected = {11};
    assert(res == expected);
}

void from_take() {
    std::vector<char>v{'1', 'a', 'o', '8'};
    std::vector<char> res = from(v.begin(), v.end())
            .take(3)
            .to_vector();
    std::vector<char> expected = {'1', 'a', 'o'};
    assert(res == expected);
}

void from_drop() {
    std::stringstream iss("-101 94 116 100 0");
    std::stringstream oss;
    std::istream_iterator<int> in(iss), eof;
    std::ostream_iterator<double> out(oss, "\n");

    from(in, eof)
            .drop(1000)
            .copy_to(out);
    assert(oss.str() == "");
}

void from_until_3() {
    std::stringstream iss("1.0 94.0 -16.0 110.0 0.0");
    std::stringstream oss;
    std::istream_iterator<double> in(iss), eof;
    std::ostream_iterator<int> out(oss, " ");

    from(in, eof)
            .drop(2)
            .until([](double x){ return x > 10000.0; })
            .copy_to(out);
    assert(oss.str() == "-16 110 0 ");
}

void from_where_1() {
    std::vector<int>v{1, -1110, 1, -312415, -7, 1, -89, -30};
    std::vector<int> res = from(v.begin(), v.end())
            .where([](int x){ return x < 0; })
            .where([](int x){ return x < -10; })
            .where([](int x){ return x < -87; })
            .where([](int x){ return x > -1111; })
            .to_vector();
    std::vector<int> expected = {-1110, -89};
    assert(res == expected);
}

void from_where_2() {
    std::vector<int>v{};
    std::vector<int> res = from(v.begin(), v.end())
            .where([](int x){ return x < 1726730; })
            .where([](int x){ return x < -178120; })
            .to_vector();
    std::vector<int> expected{};
    assert(res == expected);
}

/*
 * TESTS - EXAMPLES
 */

void example1() {
    int xs[] = { 1, 2, 3, 4, 5 };

    std::vector<int> res =
            from(xs, xs + 5)  // Взять элементы xs
                    .select([](int x) { return x * x; })  // Возвести в квадрат
                    .where_eq(25)    // Оставить только значения != 25
                    .where([](int x) { return x > 3; })   // Оставить только значения > 3
                    .drop(2)          // Убрать два элемента из начала
                    .to_vector();     // Преобразовать результат в вектор

    std::vector<int> expected = { 16 };
    assert(res == expected);
}

void example2() {
    std::stringstream ss("1 2 3 -1 4");
    std::istream_iterator<int> in(ss), eof;
    std::vector<int> res =
            from(in, eof)  // Взять числа из входного потока
                    .take(4)       // Не более четырёх чисел
                    .until_eq(-1)  // Перестать читать после прочтения -1
                    .to_vector();  // Получить список считанных чисел

    std::vector<int> expected = { 1, 2, 3 };
    assert(expected == res);

    int remaining;
    assert(ss >> remaining);
    assert(remaining == 4);
}

void example3() {
    int xs[] = { 1, 2, 3, 4, 5 };

    std::vector<double> res =
            from(xs, xs + 5)  // Взять элементы xs
                    .select<double>([](int x) { return sqrt(x); })  // Извлечь корень
                    .to_vector();     // Преобразовать результат в вектор

    assert(res.size() == 5);
    for (std::size_t i = 0; i < res.size(); i++) {
        assert(fabs(res[i] - sqrt(xs[i])) < 1e-9);
    }
}

void example4() {
    std::stringstream iss("4 16");
    std::stringstream oss;
    std::istream_iterator<int> in(iss), eof;
    std::ostream_iterator<double> out(oss, "\n");

    from(in, eof)    // Взять числа из входного потока
            .select([](int x) { return static_cast<int>(sqrt(x) + 1e-6); })  // Извлечь из каждого корень
            .copy_to(out);  // Вывести на экран

    assert(oss.str() == "2\n4\n");
}

int main() {
    from_to_vector();
    from_select();
    from_drop_select();

    //MY_TESTS
    from_until();
    from_until_1();
    from_until_eq();
    from_take();
    from_drop();
    from_until_3();
    from_where_1();
    from_where_2();

    //EXAMPLE
    example1();
    example2();
    example3();
    example4();

    std::cout << "OK\n";

    return 0;
}