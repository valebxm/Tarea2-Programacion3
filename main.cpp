#include <iostream>
#include <vector>
#include <string>

#include "all_true.h"
#include "apply_to_all.h"
#include "comparator.h"
#include "dimensions.h"
#include "invoke_multiple.h"
#include "max_static.h"
#include "printer_specialized.h"
#include "static_array.h"
#include "sum_variadic.h"
#include "tuple_printer.h"

#include "concepts.h"
#include "sum.h"
#include "mean.h"
#include "variance.h"
#include "max.h"
#include "transform_reduce.h"
#include "variadic.h"

struct Vector3D {
    double x, y, z;
    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& o) const { return {x+o.x, y+o.y, z+o.z}; }
    Vector3D operator-(const Vector3D& o) const { return {x-o.x, y-o.y, z-o.z}; }
    Vector3D operator*(const Vector3D& o) const { return {x*o.x, y*o.y, z*o.z}; }
    Vector3D operator/(std::size_t n)     const { return {x/n,   y/n,   z/n};   }

    bool operator<(const Vector3D& o) const {
        return (x*x+y*y+z*z) < (o.x*o.x+o.y*o.y+o.z*o.z);
    }
    bool operator>(const Vector3D& o) const { return o < *this; }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }
};

struct Coordenada {
    double lat, lon;
    Coordenada(double lat = 0, double lon = 0) : lat(lat), lon(lon) {}

    Coordenada operator+(const Coordenada& o) const { return {lat+o.lat, lon+o.lon}; }


    friend std::ostream& operator<<(std::ostream& os, const Coordenada& c) {
        return os << "[" << c.lat << ", " << c.lon << "]";
    }
};

int main() {

    std::cout << "=== CoreNumeric - tipos fundamentales ===" << std::endl;

    std::vector<double> datos{1.0, 2.0, 3.0, 4.0};
    std::cout << "sum:              " << core_numeric::sum(datos)      << std::endl; // 10
    std::cout << "mean:             " << core_numeric::mean(datos)     << std::endl; // 2.5
    std::cout << "variance:         " << core_numeric::variance(datos) << std::endl; // 1.25

    std::vector<double> data2{1.0, 2.7, 0.3};
    std::cout << "max:              " << core_numeric::max(data2)      << std::endl; // 2.7

    auto tr = core_numeric::transform_reduce(datos, [](double x){ return x * x; });
    std::cout << "transform_reduce: " << tr                            << std::endl; // 30

    std::vector<int> enteros{10, 20, 30};
    std::cout << "sum(int):         " << core_numeric::sum(enteros)    << std::endl; // 60
    std::cout << "mean(int):        " << core_numeric::mean(enteros)   << std::endl; // 20
    std::cout << "max(int):         " << core_numeric::max(enteros)    << std::endl; // 30

    std::cout << "\n=== Variadic ===" << std::endl;

    auto s1 = core_numeric::sum_variadic(1, 2, 33, 4);
    auto s2 = core_numeric::mean_variadic(0.1, 2.0, 3.0, 4.0);
    auto s3 = core_numeric::variance_variadic(1.0, 2.0, 3.0, 4.0);
    auto s4 = core_numeric::max_variadic(1, 2, 3, 4);

    std::cout << "sum_variadic(1,2,33,4):              " << s1 << std::endl; // 40
    std::cout << "mean_variadic(0.1,2,3,4):            " << s2 << std::endl; // 2.275
    std::cout << "variance_variadic(1.0,2.0,3.0,4.0): " << s3 << std::endl; // 1.25
    std::cout << "max_variadic(1,2,3,4):               " << s4 << std::endl; // 4

    std::cout << "\n=== Clases propias ===" << std::endl;

    std::vector<Vector3D> vv{
        {1.0, 0.0, 0.0},
        {0.0, 2.0, 0.0},
        {0.0, 0.0, 3.0}
    };
    std::cout << "[Vector3D] sum:      " << core_numeric::sum(vv)      << std::endl;
    std::cout << "[Vector3D] mean:     " << core_numeric::mean(vv)     << std::endl;
    std::cout << "[Vector3D] variance: " << core_numeric::variance(vv) << std::endl;
    std::cout << "[Vector3D] max:      " << core_numeric::max(vv)      << std::endl;

    std::vector<Coordenada> vc{ {10.0, 20.0}, {30.0, 40.0} };
    std::cout << "[Coordenada] sum:    " << core_numeric::sum(vc)      << std::endl;

    std::cout << "\n=== Herramientas de clase ===" << std::endl;

    std::cout << "all_true(T,T,F): " << utils::logic::all_true(true, true, false) << std::endl;

    printer<bool>::print(true);
    printer<std::vector<int>>::print({1, 2, 3});

    constexpr int m = compile_time::max_static<7, 3>();
    std::cout << "max_static<7,3>: " << m << std::endl;

    constexpr int vol = geometry::meta::dimensions<3, 4, 5>::total();
    std::cout << "dimensions<3,4,5>: " << vol << std::endl;

    static_array<int, 4> arr{10, 20, 30, 40};
    std::cout << "static_array[2]: " << arr[2] << std::endl;

    std::cout << "apply_to_all: ";
    meta::utility::apply_to_all([](int x){ std::cout << x << " "; }, 1, 2, 3);
    std::cout << std::endl;

    std::cout << "invoke_multiple: ";
    functional::meta::invoke_multiple(
        []{ std::cout << "A "; },
        []{ std::cout << "B "; },
        []{ std::cout << "C "; }
    );
    std::cout << std::endl;

    bool cmp = algorithms::utility::comparator<std::less>::compare(3, 7);
    std::cout << "comparator<less>(3,7): " << cmp << std::endl;

    auto tupla = std::make_tuple(42, 3.14, "hola");
    std::cout << "tuple: ";
    meta::utility::tuple_printer<int, double, const char*>::print(tupla, std::cout);
    std::cout << std::endl;

    return 0;
}
