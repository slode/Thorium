#include "../include/UnitTest++.h"
#include "../include/ReportAssert.h"

#include "../src/vector2d.h"


namespace {

    TEST(BasicVectorFunctionality)
    {
        Vector2D a(0,0), b(3,4), c(-3, -4);

        CHECK(a != b);
        CHECK(a.x + a.y == 0);

        CHECK(b.length() == 5);
        CHECK_EQUAL(b.lengthSq(), b.length()*b.length());
        CHECK(a.length() == 0);
        CHECK(c.length() > 0);

        CHECK(a.isZero());
        CHECK(!b.isZero());

        Vector2D d(b);
        CHECK(d == b);

    }
    TEST(CompoundOperatorTests)
    {
        Vector2D a(0,0), b(3,4), c(-3, -4);

        a += a;
        CHECK(a.length() == 0);

        b.zero();
        CHECK(b.length() == 0);

        c = c;
        CHECK(c.length() == 5);

        b.x = 3, b.y = 4;
        b += c;
        CHECK(b.length() == 0);
    }
    TEST(MathTests)
    {
        Vector2D a(0,0), b(0,1), c(1,0);
        a.normalize();
        CHECK(a.length() == 0);
        CHECK(b.dot(c) == 0);
        CHECK(b.cross(c) == -1);
        CHECK(c.cross(b) == 1);
    }

}
