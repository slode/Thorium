#ifndef VECTOR2D_H
#define VECTOR2D_H
    
#include <limits>
#include <cmath>

double epsilon = std::numeric_limits<double>::min();
double epsilonSq = epsilon*epsilon;

class Vector2D {
    public:
        double x, y;

        Vector2D ():x(0), y(0){}
        Vector2D (double a, double b):x(a), y(b){}
        ~Vector2D () {};

        inline void zero() { x=0, y=0; }
        inline bool isZero() { return (fabs(x+y) < epsilon*2); }

        double lengthSq() { return x*x+y*y; }
        double length() { return sqrt(x*x+y*y); }

        void normalize()
        {
            double magSq = this->lengthSq();
            if (magSq > epsilonSq) {
                this->x = (x*x) / magSq; 
                this->y = (y*y) / magSq; 
            }
        }

        void rotate(double angle)
        {
            double cf = cosf(angle), sf = sinf(angle);
            double xt = (x * cf) - (y * sf);
            double yt = (y * cf) + (x * sf);
            x = xt;
            y = yt;
        }

        double angle()
        {
            return atan2(y, x);
        }

        double dot(const Vector2D &other) const { return (x * other.x + y * other.y); }
        double cross(const Vector2D &other) const { return (x * other.y - y * other.x); }

        inline bool operator==(const Vector2D &other) {
            if (
                    fabs(this->x - other.x) < epsilon
                 && fabs(this->y - other.y) < epsilon
               ) {
                return true;
            }
            return false;
        }

        inline bool operator!=(const Vector2D &other) {
            return !(*this == other); 
        }

        // Copy overload
        inline Vector2D & operator=(const Vector2D &other) {
            if (this == &other) { return *this; }
            this->x = other.x;
            this->y = other.y;
            return *this;
        }
        // Compound operators
        inline Vector2D & operator+=(const Vector2D &w) { this->x += w.x; this->y += w.y; return *this; }
        inline Vector2D & operator-=(const Vector2D &w) { this->x -= w.x; this->y -= w.y; return *this; }
        inline Vector2D & operator*=(const Vector2D &w) { this->x *= w.x; this->y *= w.y; return *this; }
        inline Vector2D & operator/=(const Vector2D &w) { this->x /= w.x; this->y /= w.y; return *this; }

        inline Vector2D & operator*=(const double w) { this->x *= w; this->y *= w; return *this; }
        inline Vector2D & operator/=(const double w) { this->x /= w; this->y /= w; return *this; }

        // Binary operators
        inline const Vector2D & operator+(const Vector2D &w) const { return Vector2D(*this) += w; }
        inline const Vector2D & operator-(const Vector2D &w) const { return Vector2D(*this) -= w; }
        inline const Vector2D & operator*(const Vector2D &w) const { return Vector2D(*this) *= w; }
        inline const Vector2D & operator/(const Vector2D &w) const { return Vector2D(*this) /= w; }

        inline const Vector2D & operator*(const double w) const { return Vector2D(*this) *= w; }
        inline const Vector2D & operator/(const double w) const { return Vector2D(*this) /= w; }
};
#endif
