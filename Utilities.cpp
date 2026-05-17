#include "Utilities.hpp"
#include <iostream>

namespace Utils {

    // מציאת הנקודה הקרובה ביותר לראשית הצירים מתוך מערך נקודות
    Geometry::Point findClosestToOrigin(Geometry::Point points[], int size) {
        // הגנה מפני מקרה קצה של מערך ריק או גודל לא תקין
        if (size <= 0) return Geometry::Point{0.0, 0.0};

        Geometry::Point origin{0.0, 0.0};
        Geometry::Point closest = points[0];
        double minDistance = Geometry::distance(closest, origin);

        // מעבר על המערך ועדכון הנקודה הקרובה ביותר
        for (int i = 1; i < size; ++i) {
            double currentDistance = Geometry::distance(points[i], origin);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                closest = points[i];
            }
        }
        return closest;
    }

    // יצירת אובייקט מעגל באמצעות אתחול ישיר של הנקודה והרדיוס
    Geometry::Circle createCircle(double centerX, double centerY, double radius) {
        Geometry::Point center{centerX, centerY};
        return Geometry::Circle{center, radius};
    }

    // חישוב ממוצע של מערך מספרים (ה-const מבטיח שהמערך המקורי מוגן משינויים)
    double calculateAverage(const double arr[], int size) {
        // הגנה מפני חלוקה באפס במקרה של גודל 0
        if (size <= 0) return 0.0;

        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum / size;
    }

} // namespace Utils