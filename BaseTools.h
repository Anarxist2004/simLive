#pragma once

namespace BaseTools {
    struct Point2d {
        float x, y;
        Point2d() : x(0.0f), y(0.0f) {}
        Point2d(float x_val, float y_val) : x(x_val), y(y_val) {}

        // Функция для вычисления расстояния до другой точки
        float distanceTo(const Point2d& other) const {
            float dx = x - other.x;
            float dy = y - other.y;
            return std::sqrt(dx * dx + dy * dy);
        }
    };

    inline float generateRandomFloat() {
        return (static_cast<float>(rand()) / RAND_MAX) * 200.0f - 100.0f;
    }

    inline int generateRandomInt() {
        return rand() % 101;
    }

   

    
}


