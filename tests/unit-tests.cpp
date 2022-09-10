#include "math.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace Gorilla;
using namespace Gorilla::Math;

static void gassert(bool condition, const char *test)
{
    if (!condition)
    {
        fprintf(stderr, "%s\n", test);
        abort();
    }
}
#define TEST(_condition_) gassert(_condition_, #_condition_);

void test_vector2()
{
    auto v1 = Vector2f();
    TEST(v1.get_x() == 0.0f);
    TEST(v1.get_y() == 0.0f);
    TEST(v1[0] == 0.0f);
    TEST(v1[1] == 0.0f);

    auto v2 = Vector2f::ONE;
    TEST(v2.get_x() == 1.0f);
    TEST(v2.get_y() == 1.0f);
    TEST(v2[0] == 1.0f);
    TEST(v2[1] == 1.0f);

    v1.set(0.0f, 0.0f);
    TEST(v1.get_x() == 0.0f);
    TEST(v1.get_y() == 0.0f);

    v1.set_x(1.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 0.0f);

    v1.set_y(1.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);

    v1.add_x(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 1.0f);

    v1.add_y(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 2.0f);

    v1.add(1.0f, 2.0f);
    TEST(v1.get_x() == 3.0f);
    TEST(v1.get_y() == 4.0f);

    v1.sub_x(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 4.0f);

    v1.sub_y(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 3.0f);

    v1.sub(1.0f, 2.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1 == Vector2f::ONE);

    v1.mul_x(0.5f);
    TEST(v1.get_x() == 0.5f);
    TEST(v1.get_y() == 1.0f);

    v1.mul_y(2.0f);
    TEST(v1.get_x() == 0.5f);
    TEST(v1.get_y() == 2.0f);

    v1.mul(2.0f, 0.5f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);

    v1.div_x(0.5f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 1.0f);

    v1.div_y(2.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 0.5f);

    v1.div(2.0f, 0.5f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);

    v1.set(4.0f, 2.0f);
    TEST(v1.cross(v2) == -2.0f);
    TEST(v1.dot(v2) == 6.0f);
    TEST(v1.length_square() == 20.0f);
    TEST(v1.length() == sqrtf(20.0f));

    v1.normalize();
    TEST((int32_t)(v1[0]*10000)  == 8944);
    TEST((int32_t)(v1[1]*10000)  == 4472);
}

void test_vector3()
{
    auto v1 = Vector3f();
    TEST(v1.get_x() == 0.0f);
    TEST(v1.get_y() == 0.0f);
    TEST(v1.get_z() == 0.0f);
    TEST(v1[0] == 0.0f);
    TEST(v1[1] == 0.0f);
    TEST(v1[2] == 0.0f);

    auto v2 = Vector3f::ONE;
    TEST(v2.get_x() == 1.0f);
    TEST(v2.get_y() == 1.0f);
    TEST(v2.get_z() == 1.0f);
    TEST(v2[0] == 1.0f);
    TEST(v2[1] == 1.0f);
    TEST(v2[2] == 1.0f);

    v1.set(0.0f, 0.0f, 0.0f);
    TEST(v1.get_x() == 0.0f);
    TEST(v1.get_y() == 0.0f);
    TEST(v1.get_z() == 0.0f);

    v1.set_x(1.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 0.0f);
    TEST(v1.get_z() == 0.0f);

    v1.set_y(1.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 0.0f);

    v1.set_z(1.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 1.0f);

    v1.add_x(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 1.0f);

    v1.add_y(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 2.0f);
    TEST(v1.get_z() == 1.0f);

    v1.add_z(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 2.0f);
    TEST(v1.get_z() == 2.0f);

    v1.add(1.0f, 2.0f, 3.0f);
    TEST(v1.get_x() == 3.0f);
    TEST(v1.get_y() == 4.0f);
    TEST(v1.get_z() == 5.0f);

    v1.sub_x(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 4.0f);
    TEST(v1.get_z() == 5.0f);

    v1.sub_y(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 3.0f);
    TEST(v1.get_z() == 5.0f);

    v1.sub_z(1.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 3.0f);
    TEST(v1.get_z() == 4.0f);

    v1.sub(1.0f, 2.0f, 3.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 1.0f);
    TEST(v1 == Vector3f::ONE);

    v1.mul_x(0.5f);
    TEST(v1.get_x() == 0.5f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 1.0f);

    v1.mul_y(2.0f);
    TEST(v1.get_x() == 0.5f);
    TEST(v1.get_y() == 2.0f);
    TEST(v1.get_z() == 1.0f);

    v1.mul_z(3.0f);
    TEST(v1.get_x() == 0.5f);
    TEST(v1.get_y() == 2.0f);
    TEST(v1.get_z() == 3.0f);

    v1.mul(2.0f, 0.5f, 2.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 6.0f);

    v1.div_x(0.5f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 6.0f);

    v1.div_y(2.0f);
    TEST(v1.get_x() == 2.0f);
    TEST(v1.get_y() == 0.5f);
    TEST(v1.get_z() == 6.0f);

    v1.div(2.0f, 0.5f, 6.0f);
    TEST(v1.get_x() == 1.0f);
    TEST(v1.get_y() == 1.0f);
    TEST(v1.get_z() == 1.0f);

    v1.set(4.0f, 2.0f, 3.0f);
    TEST(v1.cross(v2) == Vector3f());
    TEST(v1.dot(v2) == 8.5f);
    TEST(v1.length_square() == 29.0f);
    TEST(v1.length() == sqrtf(29.0f));

    v1.normalize();
    TEST((int32_t)(v1[0]*10000)  == 8944);
    TEST((int32_t)(v1[1]*10000)  == 4472);
    TEST((int32_t)(v1[2]*10000)  == 4472);
}

int32_t main(int32_t argc, const char *argv[])
{
    static const struct
    {
        const char *name;
        void (*callback)();
    } tests[] =
    {
        {"vector2",    &test_vector2},
        {"vector3",    &test_vector3},
    };

    const char *unit_test_name = argc < 2 ? nullptr: argv[1];
    const uint32_t test_count = sizeof(tests) / sizeof(*tests);
    for(uint32_t i = 0; i < test_count; i++)
    {
        bool execute_test = unit_test_name == nullptr || strcmp(tests[i].name, unit_test_name) == 0;
        if(execute_test)
        {
            tests[i].callback();
            if(unit_test_name)
                return 0;
        }
    }

    return 0;
}
