#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point.hpp"
#include "Circle.hpp"
#include "Utilities.hpp"

using namespace Geometry;
using namespace Utils;



// בדיקת מרחק בסיסי בין ראשית הצירים לנקודה ברביע הראשון
TEST_CASE("1. Distance - Origin to Point") {
    Point p1{0.0, 0.0}, p2{3.0, 4.0};
    CHECK(distance(p1, p2) == doctest::Approx(5.0));
}

// מקרה קצה: בדיקת מרחק של נקודה מעצמה (חייב להיות 0)
TEST_CASE("2. Distance - Same Point") {
    Point p1{5.5, -2.3};
    CHECK(distance(p1, p1) == doctest::Approx(0.0));
}

// בדיקת חישוב מרחק כאשר שתי הנקודות בעלות קואורדינטות שליליות
TEST_CASE("3. Distance - Negative Coordinates") {
    Point p1{-1.0, -1.0}, p2{-4.0, -5.0};
    CHECK(distance(p1, p2) == doctest::Approx(5.0));
}

// בדיקת מרחק בין שתי נקודות שנמצאות על קו אופקי ישר
TEST_CASE("4. Distance - Horizontal Line") {
    Point p1{1.0, 5.0}, p2{10.0, 5.0};
    CHECK(distance(p1, p2) == doctest::Approx(9.0));
}



// וידוא שפונקציית הדפסת נקודה רצה בצורה תקינה ללא קריסת מערכת
TEST_CASE("5. PrintPoint - Execution Check") {
    Point p{1.5, 2.5};
    printPoint(p); 
    CHECK(true);
}



// חישוב שטח מעגל עבור רדיוס סטנדרטי
TEST_CASE("6. Circle Area - Radius 5") {
    Point center{0.0, 0.0};
    Circle c{center, 5.0};
    CHECK(calculateArea(c) == doctest::Approx(78.5398163397));
}

// מקרה קצה: חישוב שטח מעגל עם רדיוס אפס (חייב להחזיר אפס)
TEST_CASE("7. Circle Area - Radius 0") {
    Point center{1.0, 1.0};
    Circle c{center, 0.0};
    CHECK(calculateArea(c) == doctest::Approx(0.0));
}

// חישוב שטח מעגל עבור מעגל יחידה (רדיוס 1)
TEST_CASE("8. Circle Area - Radius 1") {
    Point center{0.0, 0.0};
    Circle c{center, 1.0};
    CHECK(calculateArea(c) == doctest::Approx(3.14159265359));
}



// חישוב היקף מעגל עבור רדיוס סטנדרטי
TEST_CASE("9. Circle Circumference - Radius 5") {
    Point center{0.0, 0.0};
    Circle c{center, 5.0};
    CHECK(calculateCircumference(c) == doctest::Approx(31.4159265359));
}

// מקרה קצה: חישוב היקף מעגל עם רדיוס אפס (חייב להחזיר אפס)
TEST_CASE("10. Circle Circumference - Radius 0") {
    Point center{0.0, 0.0};
    Circle c{center, 0.0};
    CHECK(calculateCircumference(c) == doctest::Approx(0.0));
}


// בדיקה שנקודה שנמצאת בתוך המעגל אכן מזוהה בפנים 
TEST_CASE("11. Point Inside Circle - Strictly Inside") {
    Point center{0.0, 0.0};
    Circle c{center, 5.0};
    Point p{1.0, 1.0};
    CHECK(isPointInside(c, p) == true);
}

// מקרה קצה: בדיקה שנקודה שנמצאת בדיוק על שפת המעגל נחשבת בפנים 
TEST_CASE("12. Point Inside Circle - On Edge") {
    Point center{0.0, 0.0};
    Circle c{center, 5.0};
    Point p{5.0, 0.0};
    CHECK(isPointInside(c, p) == true);
}

// בדיקה שנקודה שנמצאת מחוץ למעגל אכן מזוהה בחוץ (false)
TEST_CASE("13. Point Inside Circle - Outside") {
    Point center{0.0, 0.0};
    Circle c{center, 5.0};
    Point p{5.1, 0.0};
    CHECK(isPointInside(c, p) == false);
}



// וידוא שפונקציית הדפסת מעגל רצה בצורה תקינה ללא קריסת מערכת
TEST_CASE("14. PrintCircle - Execution Check") {
    Point center{0.0, 0.0};
    Circle c{center, 2.0};
    printCircle(c); 
    CHECK(true);
}

// --- פונקציית createCircle ---

// וידוא תקינות של פונקציית יצירת מעגל והשמה נכונה של הפרמטרים
TEST_CASE("15. Create Circle - Validation") {
    Circle c = createCircle(2.0, -3.0, 4.5);
    CHECK(c.center.x == doctest::Approx(2.0));
    CHECK(c.center.y == doctest::Approx(-3.0));
    CHECK(c.radius == doctest::Approx(4.5));
}



// חישוב ממוצע של מערך המכיל מספרים חיוביים בלבד
TEST_CASE("16. Average - Positive Numbers") {
    double arr[] = {1.0, 2.0, 3.0, 4.0};
    CHECK(calculateAverage(arr, 4) == doctest::Approx(2.5));
}

// חישוב ממוצע של מערך מעורב עם מספרים חיוביים ושליליים
TEST_CASE("17. Average - Mixed Numbers") {
    double arr[] = {-10.0, 10.0, -5.0, 5.0};
    CHECK(calculateAverage(arr, 4) == doctest::Approx(0.0));
}

// מקרה קצה: וידוא החזרת 0 בחישוב ממוצע של מערך בגודל 0 (מניעת חלוקה באפס)
TEST_CASE("18. Average - Size Zero Edge Case") {
    double arr[] = {1.0};
    CHECK(calculateAverage(arr, 0) == doctest::Approx(0.0));
}



// מציאת הנקודה הקרובה ביותר לראשית מתוך מערך נקודות סטנדרטי
TEST_CASE("19. Closest to Origin - Basic Array") {
    Point p1{10.0, 10.0}, p2{1.0, 1.0}, p3{5.0, 5.0};
    Point arr[] = {p1, p2, p3};
    Point closest = findClosestToOrigin(arr, 3);
    CHECK(closest.x == doctest::Approx(1.0));
    CHECK(closest.y == doctest::Approx(1.0));
}

// מקרה קצה: וידוא החזרת נקודה מאופסת (0,0) כאשר גודל המערך הוא 0
TEST_CASE("20. Closest to Origin - Size Zero Edge Case") {
    Point arr[] = {{1.0, 1.0}};
    Point closest = findClosestToOrigin(arr, 0);
    CHECK(closest.x == doctest::Approx(0.0));
    CHECK(closest.y == doctest::Approx(0.0));
}