#include <iostream>
#include <cmath>

struct Vector3f {
    float x, y, z;

    Vector3f operator+(const Vector3f& vec) const {
        return {x + vec.x, y + vec.y, z + vec.z};
    }

    Vector3f operator-(const Vector3f& vec) const {
        return {x - vec.x, y - vec.y, z - vec.z};
    }

    Vector3f operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

    friend Vector3f operator*(float scalar, const Vector3f& vec) {
        return vec * scalar;
    }

    Vector3f operator/(float scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    float operator*(const Vector3f& vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    Vector3f operator-() const {
        return {-x, -y, -z};
    }

    Vector3f operator+() const {
        return *this;
    }

    bool operator==(const Vector3f& vec) const {
        return x == vec.x && y == vec.y && z == vec.z;
    }

    bool operator!=(const Vector3f& vec) const {
        return !(*this == vec);
    }

    Vector3f& operator+=(const Vector3f& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    Vector3f& operator-=(const Vector3f& vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        return *this;
    }

    Vector3f& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3f& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3f& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector3f& vec) {
        is >> vec.x >> vec.y >> vec.z;
        return is;
    }
};

float squaredNorm(const Vector3f& a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float norm(const Vector3f& a) {
    return std::sqrt(squaredNorm(a));
}

void normalize(Vector3f& a) {
    float n = norm(a);
    if (n != 0) {
        a /= n;
    }
}
