#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	// std::cout が 1/0 の代わりに true/false を出力するように設定
	std::cout << std::boolalpha;

	// --- Test Case 1: [ご提示の例] シンプルな直角三角形 (第一象限) ---
	Point const a1(0.0f, 0.0f);
	Point const b1(10.0f, 0.0f);
	Point const c1(0.0f, 10.0f);
	std::cout << "\n--- Triangle 1: (0,0), (10,0), (0,10) [Right] ---" << std::endl;
	std::cout << "Test (Inside): (2.5, 2.5) ... Result: "
			  << bsp(a1, b1, c1, Point(2.5f, 2.5f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (-1, -1) ... Result: "
			  << bsp(a1, b1, c1, Point(-1.0f, -1.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Vertex a): (0, 0) ... Result: "
			  << bsp(a1, b1, c1, a1) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge bc): (5, 5) ... Result: "
			  << bsp(a1, b1, c1, Point(5.0f, 5.0f)) << " (Expected: false)" << std::endl;

	// --- Test Case 2: [ご提示の例] Y軸対称の二等辺三角形 (上向き) ---
	Point const a2(-5.0f, 0.0f);
	Point const b2(5.0f, 0.0f);
	Point const c2(0.0f, 5.0f);
	std::cout << "\n--- Triangle 2: (-5,0), (5,0), (0,5) [Isosceles] ---" << std::endl;
	std::cout << "Test (Inside): (0, 2) ... Result: "
			  << bsp(a2, b2, c2, Point(0.0f, 2.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (0, 6) ... Result: "
			  << bsp(a2, b2, c2, Point(0.0f, 6.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge ab): (0, 0) ... Result: "
			  << bsp(a2, b2, c2, Point(0.0f, 0.0f)) << " (Expected: false)" << std::endl;

	// --- Test Case 3: X軸対称 (下向き) ---
	Point const a3(-5.0f, 0.0f);
	Point const b3(5.0f, 0.0f);
	Point const c3(0.0f, -5.0f);
	std::cout << "\n--- Triangle 3: (-5,0), (5,0), (0,-5) [Pointing Down] ---" << std::endl;
	std::cout << "Test (Inside): (0, -2) ... Result: "
			  << bsp(a3, b3, c3, Point(0.0f, -2.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (0, 2) ... Result: "
			  << bsp(a3, b3, c3, Point(0.0f, 2.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge bc): (2.5, -2.5) ... Result: "
			  << bsp(a3, b3, c3, Point(2.5f, -2.5f)) << " (Expected: false)" << std::endl;

	// --- Test Case 4: X軸対称 (左向き) ---
	Point const a4(0.0f, 5.0f);
	Point const b4(0.0f, -5.0f);
	Point const c4(-10.0f, 0.0f);
	std::cout << "\n--- Triangle 4: (0,5), (0,-5), (-10,0) [Pointing Left] ---" << std::endl;
	std::cout << "Test (Inside): (-5, 0) ... Result: "
			  << bsp(a4, b4, c4, Point(-5.0f, 0.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (1, 0) ... Result: "
			  << bsp(a4, b4, c4, Point(1.0f, 0.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Vertex c): (-10, 0) ... Result: "
			  << bsp(a4, b4, c4, c4) << " (Expected: false)" << std::endl;

	// --- Test Case 5: 鈍角三角形 (Obtuse) ---
	Point const a5(0.0f, 0.0f);
	Point const b5(10.0f, 0.0f);
	Point const c5(1.0f, 5.0f); // 鈍角
	std::cout << "\n--- Triangle 5: (0,0), (10,0), (1,5) [Obtuse] ---" << std::endl;
	std::cout << "Test (Inside): (2, 2) ... Result: "
			  << bsp(a5, b5, c5, Point(2.0f, 2.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (5, -1) ... Result: "
			  << bsp(a5, b5, c5, Point(5.0f, -1.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Outside): (1, 6) ... Result: "
			  << bsp(a5, b5, c5, Point(1.0f, 6.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge ac): (0.5, 2.5) ... Result: "
			  << bsp(a5, b5, c5, Point(0.5f, 2.5f)) << " (Expected: false)" << std::endl;

	// --- Test Case 6: 全てマイナス座標 ---
	Point const a6(-10.0f, -10.0f);
	Point const b6(-2.0f, -10.0f);
	Point const c6(-6.0f, -2.0f);
	std::cout << "\n--- Triangle 6: (-10,-10), (-2,-10), (-6,-2) [All Negative] ---" << std::endl;
	std::cout << "Test (Inside): (-6, -8) ... Result: "
			  << bsp(a6, b6, c6, Point(-6.0f, -8.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (0, 0) ... Result: "
			  << bsp(a6, b6, c6, Point(0.0f, 0.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge ab): (-6, -10) ... Result: "
			  << bsp(a6, b6, c6, Point(-6.0f, -10.0f)) << " (Expected: false)" << std::endl;

	// --- Test Case 7: 非常に狭い（細い）三角形 ---
	Point const a7(0.0f, 0.0f);
	Point const b7(1.0f, 100.0f);
	Point const c7(2.0f, 0.0f);
	std::cout << "\n--- Triangle 7: (0,0), (1,100), (2,0) [Narrow] ---" << std::endl;
	std::cout << "Test (Inside): (1, 50) ... Result: "
			  << bsp(a7, b7, c7, Point(1.0f, 50.0f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (1, 101) ... Result: "
			  << bsp(a7, b7, c7, Point(1.0f, 101.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge ac): (1, 0) ... Result: "
			  << bsp(a7, b7, c7, Point(1.0f, 0.0f)) << " (Expected: false)" << std::endl;

	// --- Test Case 8: 非常に小さい（精密）な三角形 ---
	Point const a8(0.0f, 0.0f);
	Point const b8(0.1f, 0.0f);
	Point const c8(0.0f, 0.1f);
	std::cout << "\n--- Triangle 8: (0,0), (0.1,0), (0,0.1) [Small/Precision] ---" << std::endl;
	std::cout << "Test (Inside): (0.02f, 0.02f) ... Result: "
			  << bsp(a8, b8, c8, Point(0.02f, 0.02f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (0.1f, 0.1f) ... Result: "
			  << bsp(a8, b8, c8, Point(0.1f, 0.1f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge bc): (0.05f, 0.05f) ... Result: "
			  << bsp(a8, b8, c8, Point(0.05f, 0.05f)) << " (Expected: false)" << std::endl;

	// --- Test Case 9: 座標がオフセットした三角形 ---
	Point const a9(100.0f, 100.0f);
	Point const b9(110.0f, 100.0f);
	Point const c9(100.0f, 110.0f);
	std::cout << "\n--- Triangle 9: (100,100), (110,100), (100,110) [Offset] ---" << std::endl;
	std::cout << "Test (Inside): (102.5f, 102.5f) ... Result: "
			  << bsp(a9, b9, c9, Point(102.5f, 102.5f)) << " (Expected: true)" << std::endl;
	std::cout << "Test (Outside): (0, 0) ... Result: "
			  << bsp(a9, b9, c9, Point(0.0f, 0.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Edge bc): (105, 105) ... Result: "
			  << bsp(a9, b9, c9, Point(105.0f, 105.0f)) << " (Expected: false)" << std::endl;

	// --- Test Case 10: 縮退した三角形 ( collinear / 一直線) ---
	Point const a10(0.0f, 0.0f);
	Point const b10(5.0f, 5.0f);
	Point const c10(10.0f, 10.0f);
	std::cout << "\n--- Triangle 10: (0,0), (5,5), (10,10) [Degenerate/Collinear] ---" << std::endl;
	std::cout << "Test (On Line): (2, 2) ... Result: "
			  << bsp(a10, b10, c10, Point(2.0f, 2.0f)) << " (Expected: false)" << std::endl;
	std::cout << "Test (Off Line): (2, 3) ... Result: "
			  << bsp(a10, b10, c10, Point(2.0f, 3.0f)) << " (Expected: false)" << std::endl;

	return 0;
}