#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    // std::cout が 1/0 の代わりに true/false を出力するように設定
    std::cout << std::boolalpha;

    // --- Test Case 1: シンプルな直角三角形 ---
    // 頂点: a(0, 0), b(10, 0), c(0, 10)
    Point const a1(0.0f, 0.0f);
    Point const b1(10.0f, 0.0f);
    Point const c1(0.0f, 10.0f);

    std::cout << "--- Triangle 1: (0,0), (10,0), (0,10) ---" << std::endl;

    // 1. 完全に内側の点
    std::cout << "Test (Inside): (2.5, 2.5) ... Result: "
              << bsp(a1, b1, c1, Point(2.5f, 2.5f)) << " (Expected: true)" << std::endl;

    // 2. 完全に外側の点
    std::cout << "Test (Outside): (-1, -1) ... Result: "
              << bsp(a1, b1, c1, Point(-1.0f, -1.0f)) << " (Expected: false)" << std::endl;
    std::cout << "Test (Outside): (10, 10) ... Result: "
              << bsp(a1, b1, c1, Point(10.0f, 10.0f)) << " (Expected: false)" << std::endl;

    // 3. 頂点の上 (閾値)
    std::cout << "Test (Vertex a): (0, 0) ... Result: "
              << bsp(a1, b1, c1, a1) << " (Expected: false)" << std::endl;
    std::cout << "Test (Vertex b): (10, 0) ... Result: "
              << bsp(a1, b1, c1, b1) << " (Expected: false)" << std::endl;
    std::cout << "Test (Vertex c): (0, 10) ... Result: "
              << bsp(a1, b1, c1, c1) << " (Expected: false)" << std::endl;

    // 4. 辺の上 (閾値)
    std::cout << "Test (Edge ab): (5, 0) ... Result: "
              << bsp(a1, b1, c1, Point(5.0f, 0.0f)) << " (Expected: false)" << std::endl;
    std::cout << "Test (Edge ac): (0, 5) ... Result: "
              << bsp(a1, b1, c1, Point(0.0f, 5.0f)) << " (Expected: false)" << std::endl;
    std::cout << "Test (Edge bc): (5, 5) ... Result: "
              << bsp(a1, b1, c1, Point(5.0f, 5.0f)) << " (Expected: false)" << std::endl;

    // --- Test Case 2: 鈍角三角形 ---
    // 頂点: a(-5, 0), b(5, 0), c(0, 5)
    Point const a2(-5.0f, 0.0f);
    Point const b2(5.0f, 0.0f);
    Point const c2(0.0f, 5.0f);

    std::cout << "\n--- Triangle 2: (-5,0), (5,0), (0,5) ---" << std::endl;

    // 1. 完全に内側の点
    std::cout << "Test (Inside): (0, 2) ... Result: "
              << bsp(a2, b2, c2, Point(0.0f, 2.0f)) << " (Expected: true)" << std::endl;
    std::cout << "Test (Inside): (-2, 1) ... Result: "
              << bsp(a2, b2, c2, Point(-2.0f, 1.0f)) << " (Expected: true)" << std::endl;

    // 2. 完全に外側の点
    std::cout << "Test (Outside): (0, 6) ... Result: "
              << bsp(a2, b2, c2, Point(0.0f, 6.0f)) << " (Expected: false)" << std::endl;

    // 3. 辺の上 (閾値)
    std::cout << "Test (Edge ab): (0, 0) ... Result: "
              << bsp(a2, b2, c2, Point(0.0f, 0.0f)) << " (Expected: false)" << std::endl;
    std::cout << "Test (Edge ac): (-2.5, 2.5) ... Result: "
              << bsp(a2, b2, c2, Point(-2.5f, 2.5f)) << " (Expected: false)" << std::endl;

    return 0;
}