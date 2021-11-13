#include <iostream>
#include <cmath>
using namespace std;

bool eq(double d1, double d2, double eps = 0.001)
{
    return abs(d2 - d1) < eps;
}

struct Point
{
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void print(ostream &out) const
    {
        out << "(" << x << ", " << y << ")";
    }
};

ostream &operator<<(ostream &out, const Point &p)
{
    p.print(out);
    return out;
}

istream &operator>>(istream &in, Point &p)
{
    in >> p.x;
    in >> p.y;

    return in;
}

struct Line
{
    double A, B, C;

    Line(double A = 0, double B = 0, double C = 0) : A(A), B(B), C(C) {}

    Line(const Point &p1, const Point &p2)
    {
        B = p2.x - p1.x;
        A = p1.y - p2.y;
        C = -(A * p1.x + B * p1.y);
    }

    bool parallel(const Line &other) const
    {
        return eq(this->A * other.B, this->B * other.A) && this->A * other.C != other.A * this->C;
    }

    Line parallel(const Point &p)
    {
        return Line(this->A, this->B, -(this->A * p.x + this->B * p.y));
    }

    bool perpendicular(const Line &other) const
    {
        return eq(this->A * other.A, -(this->B * other.B));
    }

    Line perpendicular(const Point &p)
    {
        return Line(-this->B, this->A, this->B * p.x - this->A * p.y);
    }

    void print(ostream &out) const
    {
        out << A << "x + " << B << "y + " << C << " = 0";
    }
};

ostream &operator<<(ostream &out, const Line &l)
{
    l.print(out);
    return out;
}

istream &operator>>(istream &in, Line &l)
{
    in >> l.A;
    in >> l.B;
    in >> l.C;

    return in;
}
