#include <iostream>
#include <string>

class Figure {
protected:
	int sidse_count;
	std::string name;

	Figure(int sidse_count, const std::string& name): sidse_count (sidse_count), name (name){}
public:
	int get_sides_count() const {
		return sidse_count;
	}
	std::string get_name() const {
		return name;
	}
	virtual void print_info() const = 0;
};

class Triangle : public Figure
{
private:
	double a, b, c;
	double A, B, C;

public:
	Triangle(double a, double b, double c, double A, double B, double C)
		: Figure(3, "Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }
	double get_A() const { return A; }
	double get_B() const { return B; }
	double get_C() const { return C; }

	void print_info() const override {
		std::cout << get_name() << ":\n";
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
	}
};
	class Quadrangle : public Figure {
	protected:
		double a, b, c, d;
		double A, B, C, D;

	public:
		Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D): Figure(4, "Четырехугольник"), a(a), b(b),c(c),d(d),A(A),B(B),C(C),D(D){}
		
		double get_a() const { return a; }
		double get_b() const { return b; }
		double get_c() const { return c; }
		double get_d() const { return d; }
		double get_A() const { return A; }
		double get_B() const { return B; }
		double get_C() const { return C; }
		double get_D() const { return D; }

		void print_info() const override {
			std::cout << get_name() << ":\n";
			std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
			std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
		}
	};

	class RightTriangle : public Triangle {
	public:
		RightTriangle(double a, double b, double c, double A, double B)
			: Triangle(a, b, c, A, B, 90) {
			name = "Прямоугольный треугольник";
		}
	};

	class EquilateralTriangle : public Triangle {
	public:
		EquilateralTriangle(double side)
			: Triangle(side, side, side, 60, 60, 60) {
			name = "Равносторонний треугольник";
		}
	};

	class IsoscelesTriangle : public Triangle {
	public:
		IsoscelesTriangle(double a, double b, double A, double B)
			: Triangle(a, b, a, A, B, A) {
			name = "Равнобедренный треугольник";
		}
	};

	class Rectangle : public Quadrangle {
	public:
		Rectangle(double a, double b)
			: Quadrangle(a, b, a, b, 90, 90, 90, 90) {
			name = "Прямоугольник";
		}
	};

	class Square : public Quadrangle {
	public:
		Square(double side)
			: Quadrangle(side, side, side, side, 90, 90, 90, 90) {
			name = "Квадрат";
		}
	};

	class Parallelogram : public Quadrangle {
	public:
		Parallelogram(double a, double b, double A, double B)
			: Quadrangle(a, b, a, b, A, B, A, B) {
			name = "Параллелограмм";
		}
	};

	class Rhombus : public Quadrangle {
	public:
		Rhombus(double side, double A, double B)
			: Quadrangle(side, side, side, side, A, B, A, B) {
			name = "Ромб";
		}
	};

	void print_info(const Figure* figure) {
		figure->print_info();
	}

	int main() {
		Triangle t(10, 20, 30, 50, 60, 70);
		RightTriangle rt(10, 20, 30, 50, 60);
		IsoscelesTriangle it(10, 20, 50, 60);
		EquilateralTriangle et(30);

		Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
		Rectangle r(10, 20);
		Square s(20);
		Parallelogram p(20, 30, 30, 40);
		Rhombus rh(30, 30, 40);

		print_info(&t);
		print_info(&rt);
		print_info(&it);
		print_info(&et);

		print_info(&q);
		print_info(&r);
		print_info(&s);
		print_info(&p);
		print_info(&rh);

		return 0;
	}


