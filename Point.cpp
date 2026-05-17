#include "Point.hpp"
#include <cmath>     // ספריה לחישובים מתמטיים כמו שורש (sqrt) וחוזקה (pow)
#include <iostream>  // ספריה להדפסות (cout)

using namespace std; // מאפשר לנו לכתוב cout במקום std::cout

namespace Geometry {

    double distance(Point p1, Point p2) {
        // חישוב ההפרש בציר ה-X ובציר ה-Y
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        
        // החזרת השורש של סכום הריבועים
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
     void printPoint(Point point) {
        // הדפסה מדויקת של הפורמט שנדרש
        cout << "(" << point.x << "," << point.y << ")";
    }

     } // סגירת מרחב השמות Geometry







