#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name_;
public:
    Figure(std::string name) : name_(name) {}
    std::string get_name() { return name_; }
};
class Triangle : public Figure
{
private:
    int a_, b_, c_, A_, B_, C_;
public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name): a_(a), b_(b), c_(c), A_(A), B_(B), C_(C), Figure(name)
    {}
    int get_a() { return a_; };
    int get_b() { return b_; };
    int get_c() { return c_; };
    int get_A() { return A_; };
    int get_B() { return B_; };
    int get_C() { return C_; };
    
    void print()
    {
     std::cout << this->get_name() << '\n' << "Стороны: a = " << a_ << ", b = " << b_ << ", c = " << c_ << "\nУглы: A = "
      << A_ << ", B = " << B_ << ", C = " << C_ << std::endl << std::endl;
    }
};
class Right_triangle : public Triangle
{
public:
    Right_triangle(int a, int b, int c, int A, int B, std::string name, const int C = 90) : Triangle(a, b, c, A, B, C, name)
    {}
};

class Isosceles_triangle : public Triangle
{
public:
    Isosceles_triangle(int a, int b, int A, int B, std::string name) : Triangle(a, b, a, A, B, A, name) 
    {}
};

class Equilateral_triangle : public Triangle
{
public:
    Equilateral_triangle(int a, std::string name, const int A = 60) : Triangle(a, a, a, A, A, A, name) 
    {}
};

class Quadrilateral : public Figure
{
private:
    int a_, b_, c_, d_, A_, B_, C_, D_;
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : a_(a), b_(b), c_(c), d_(d), A_(A), B_(B), C_(C), D_(D), Figure(name)
    {}
    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_d() { return d_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    int get_D() { return D_; }
    void print()
    {
        std::cout << this->get_name() << '\n' << "Стороны: a = " << a_ << ", b = " << b_ << ", c = " << c_ << ", d = " << d_
            <<"\nУглы: A = "<< A_ << ", B = " << B_ << ", C = " << C_ << ", D = "<< D_ << std::endl << std::endl;
    }
};

class Quadrangle :public Quadrilateral
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Quadrilateral(a, b, c, d, A, B, C, D, name)
    {}
};

class Rectangle : public Quadrilateral
{

public:
    Rectangle(int a, int b, std::string name, const int C = 90) : Quadrilateral(a, b, a, b, C, C, C, C, name)
    {}
};

class Square : public Quadrilateral
{
public:
    Square(int a, std::string name, const int C = 90) : Quadrilateral(a,a,a,a,C,C,C,C, name)
    {}
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(int a, int b, int A, int B, std::string name) : Quadrilateral(a, b, a, b, A, B, A, B, name)
    {}
};

class Rhombus : public Quadrilateral
{
public:
    Rhombus(int a, int A, int B, std::string name) : Quadrilateral(a, a, a, a, A, B, A, B, name)
    {}
};
int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle treug(10, 20, 30, 50, 60, 70, "Треугольник: ");
    treug.print();
    Right_triangle ritr(10, 20, 30, 50, 60, "Прямоугольный треугольник: ");
    ritr.print();
    Isosceles_triangle istr(10, 20, 50, 60, "Равнобедренный треугольник: ");
    istr.print();
    Equilateral_triangle eqtr(30, "Равносторонний треугольник: ");
    eqtr.print();
    Quadrangle qudgle(10, 20, 30, 40, 50, 60, 70, 80, "Четырёхугольник: ");
    qudgle.print();
    Rectangle recgle(10, 20, "Прямоугольник: ");
    recgle.print();
    Square square(20, "Квадрат: ");
    square.print();
    Parallelogram prll(20, 30, 30, 40, "Параллелограмм: ");
    prll.print();
    Rhombus rhombus(30, 30, 40, "Ромб: ");
    rhombus.print();
}

