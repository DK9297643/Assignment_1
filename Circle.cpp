#include "Circle.hpp"
#include <iostream>
#include <numbers>

using namespace std;

namespace Geometry {

    // חישוב שטח המעגל (פאי כפול רדיוס בריבוע)
    double calculateArea(Circle circle) {
        return std::numbers::pi * circle.radius * circle.radius;
    }

    // חישוב היקף המעגל (2 כפול פאי כפול רדיוס)
    double calculateCircumference(Circle circle) {
        return 2 * std::numbers::pi * circle.radius;
    }

    // בדיקה אם נקודה בתוך המעגל (המרחק מהמרכז קטן או שווה לרדיוס)
    bool isPointInside(Circle circle, Point p) {
        return distance(circle.center, p) <= circle.radius;
    }

    // הדפסת המעגל בפורמט הנדרש תוך שימוש חוזר בפונקציית הדפסת הנקודה
    void printCircle(Circle circle) {
        cout << "Circle: center=";
        printPoint(circle.center);
        cout << ", radius=" << circle.radius;
    }

} // namespace Geometry