#pragma once
#include "math.h"
#include "iostream"
#include <vector>
#include "Entity.h"


class Quadtree {
public:
    struct Rectangle {
        float x_min, y_min, x_max, y_max;

        Rectangle(float xmin, float ymin, float xmax, float ymax)
            : x_min(xmin), y_min(ymin), x_max(xmax), y_max(ymax) {
        }

        bool contains(const Point2d& p) const {
            return p.x >= x_min && p.x <= x_max && p.y >= y_min && p.y <= y_max;
        }

        bool intersects(const Point2d& center, float radius) const {
            float closestX = std::fmax(x_min, std::fmin(center.x, x_max));
            float closestY = std::fmax(y_min, std::fmin(center.y, y_max));
            Point2d closestPoint(closestX, closestY);
            return center.distanceTo(closestPoint) <= radius;
        }
    };

private:
    Rectangle boundary;
    std::vector<Entity*> entities;  // ’раним указатели на Entity
    Quadtree* nw = nullptr;
    Quadtree* ne = nullptr;
    Quadtree* sw = nullptr;
    Quadtree* se = nullptr;
    int capacity;

    void subdivide() {
        double x_mid = (boundary.x_min + boundary.x_max) / 2;
        double y_mid = (boundary.y_min + boundary.y_max) / 2;

        nw = new Quadtree(Rectangle(boundary.x_min, boundary.y_min, x_mid, y_mid), capacity);
        ne = new Quadtree(Rectangle(x_mid, boundary.y_min, boundary.x_max, y_mid), capacity);
        sw = new Quadtree(Rectangle(boundary.x_min, y_mid, x_mid, boundary.y_max), capacity);
        se = new Quadtree(Rectangle(x_mid, y_mid, boundary.x_max, boundary.y_max), capacity);
    }

    bool removeFromQuadrant(Entity* entity) {
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            if (*it == entity) {
                entities.erase(it);
                return true;
            }
        }
        return false;
    }

    void cleanUp() {
        // ≈сли квадрант пуст и дочерние квадранты тоже пусты, то очистить их
        if (entities.empty() && nw == nullptr && ne == nullptr && sw == nullptr && se == nullptr) {
            delete nw;
            delete ne;
            delete sw;
            delete se;
            nw = ne = sw = se = nullptr;
        }
    }

public:
    Quadtree(Rectangle rect, int cap) : boundary(rect), capacity(cap) {}

    bool insert(Entity* entity) {
        if (!boundary.contains(entity->position())) {
            return false;
        }

        if (entities.size() < capacity) {
            entities.push_back(entity);
            return true;
        }

        if (!nw) {
            subdivide();
        }

        if (nw->insert(entity)) return true;
        if (ne->insert(entity)) return true;
        if (sw->insert(entity)) return true;
        if (se->insert(entity)) return true;

        return false;
    }

    bool remove(Entity* entity) {
        // ≈сли объект не находитс€ в пределах границ квадрата, его нельз€ удалить
        if (!boundary.contains(entity->position())) {
            return false;
        }

        if (removeFromQuadrant(entity)) {
            cleanUp();
            return true;
        }

        // ≈сли не в текущем квадранте, пытаемс€ удалить в дочерних квадрантах
        if (nw && nw->remove(entity)) return true;
        if (ne && ne->remove(entity)) return true;
        if (sw && sw->remove(entity)) return true;
        if (se && se->remove(entity)) return true;

        return false;
    }

    void queryRange(const Point2d& center, double radius, std::vector<Entity*>& result) {
        if (!boundary.intersects(center, radius)) {
            return;
        }

        for (const auto& e : entities) {
            if (center.distanceTo(e->position()) <= radius) {
                result.push_back(e);
            }
        }

        if (nw) nw->queryRange(center, radius, result);
        if (ne) ne->queryRange(center, radius, result);
        if (sw) sw->queryRange(center, radius, result);
        if (se) se->queryRange(center, radius, result);
    }
};
