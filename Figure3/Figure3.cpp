/*
В этом задании вы добавите в вашу иерархию классов больше функциональности.

Теперь ваши фигуры должны уметь немного больше:

выводить информацию о себе;
проверять правильность своих данных.
Ваши фигуры:

фигура (количество сторон равно 0);
треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль, а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.

Информация о фигуре включает в себя:

название фигуры;
количество сторон;
длины её сторон, если есть;
величины её углов, если есть;
является ли фигура правильной.
Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонструйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.

Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных функций и переопределений. Используйте вызов базовой версии метода.

Ваша задача — работать с экземплярами дочерних классов полиморфно, то есть с помощью указателя на базовый класс.
*/

#include <iostream>
#include <string>


class Shape
{
public:
	Shape()
	{
		name = "Shape:";
		FTrue = true;
		sides = 0;
	}
	void print_info()
	{
		std::cout << name << '\n';
		std::cout << (check() ? "Correct" : "Incorrect");
		std::cout << '\n';
		printSides();
		printAngles();
	}
protected:
	std::string name;
	bool FTrue;
	int sides;
	virtual void printSides()
	{
		std::cout << "Sides: " << sides << '\n';
		std::cout << '\n';
	};
	virtual void printAngles() {};
	virtual bool check() { return FTrue; };
};



class Triangle : public Shape
{
public:
	Triangle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
		name = "Triangle:";
	}
	Triangle() { a = b = c = A = B = C = 0; };
protected:
	void printSides() override
	{
		std::cout << "Number of sides: " << sides << '\n';
		std::cout << "Sides: " << "a = " << a << ", " << "b = " << b << ", " << "c = " << c << '\n';
		std::cout << "Angles: " << "A = " << A << ", " << "B = " << B << ", " << "C = " << C << "\n";
		std::cout << '\n';
	}
	bool check() override
	{
		if ((A + B + C) == 180)
			return true;
		else return false;
	}
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
};

// Прямоугольный треугольник
class RTriagnle : public Triangle
{
public:
	RTriagnle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
		name = "Right triangle:";
	}
protected:
	bool check() 
	{
		if (C == 90)
			return Triangle::check();
		else return 0;
	}
};

// равнобедренный треугольник
class IStriangle : public Triangle
{
public:
	IStriangle(int a, int b, int c,  int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
		name = "Isosceles triangle:";
	}
protected:
	bool check()
	{
		if (a == c && A == C)
			return Triangle::check();
		else return 0;
	}
};

//равносторенний треугольник
class EQtriangle : public Triangle
{
public:
	EQtriangle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
		name = "Equilateral triangle:";
	}
protected:
	bool check()
	{
		if (a == b && b == c && A == 60 && A == B && B == C)
			return Triangle::check();
		else return 0;
	}
};

// базовый класс четырехугольника
class Quadrilateral : public Shape
{
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides = 4;
		name = "Quadrilateral:";
	}
	Quadrilateral()
	{
		a = b = c = d = A = B = C = D = 0;
	}
protected:
	void printSides() override
	{
		std::cout << "Number of sides: " << sides << '\n';
		std::cout << "Sides: " << "a = " << a << ", " << "b = " << b << ", " << "c = " << c << ", " << "d = " << d << '\n';
		std::cout << "Angles: " << "A = " << A << ", " << "B = " << B << ", " << "C = " << C << ", " << "D = " << D << '\n';
		std::cout << '\n';
	}
	bool check() override
	{
		if ((A + B + C + D) == 360)
			return true;
		else return false;
	}
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;
};

// Параллелограмм
class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides = 4;
		name = "Parallelogram:";
	}
	Parallelogram() { a = b = c = d = A = B = C = D = 0; }
protected:
	bool check()
	{
		if (a == c && b == d && A == C && B == D)
			return Quadrilateral::check();
		else return 0;
	}
};

// Прямоугольник 
class Rectangle : public Parallelogram
{
public:
	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides = 4;
		name = "Rectangle:";
	}
	Rectangle() { a = b = c = d = A = B = C = D = 0; }
protected:
	bool check()
	{
		if (a == c && b == d && A == 90 && B == A && C == A && D == A)
			return Quadrilateral::check();
		else return 0;
	}
};

// Ромб
class Rhomb : public Parallelogram
{
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides = 4;
		name = "Rhomb:";
	}
protected:
	bool check()
	{
		if (a == b && b == c && c == d && A == C && B == D)
			return Quadrilateral::check();
		else return 0;
	}
};

// Квадрат
class Square : public Rectangle
{
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides = 4;
		name = "Square:";
	}
protected:
	bool check()
	{
		if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90)
			return Quadrilateral::check();
		else return 0;
	}
};


void print(Shape& shape)
{
	shape.print_info();
}

Shape shape;
Triangle triang(10, 20, 30, 50, 60, 70);

RTriagnle rtriangle(10, 20, 30, 50, 60, 90);
RTriagnle rtriangle2(10, 20, 30, 50, 40, 90);

IStriangle istriangle(10, 20, 10, 50, 60, 50);
EQtriangle eqtriangle(30, 30, 30, 60, 60, 60);


Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
Rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);
Square square(20, 20, 20, 20, 90, 90, 90, 90);

int main()
{
	print(shape);

	print(triang);
	print(rtriangle);
	print(rtriangle2);
	print(istriangle);
	print(eqtriangle);

	print(quadrilateral);
	print(parallelogram);
	print(rectangle);
	print(rhomb);

	return 0;
}



