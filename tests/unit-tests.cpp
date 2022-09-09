#include "math.hpp"

using namespace Gorilla;
using namespace Gorilla::Math;

static void log(LogLevel level, const char *filepath, uint32_t line, ...)
{
    static const char* level_names[] = {
        "Message",
        "Warning",
        "Error",
        "Assert"
    };
    static THREAD_LOCAL char buffer[256];

    // format user log
    va_list arguments;
    va_start(arguments, line);
    const char* format = va_arg(arguments, const char*);
    int32_t length = VSPRINTF(buffer, format, arguments);
    va_end(arguments);

    // early exist
    if (length >= 256)
    {
        log(LogLevel::WARNING, filepath, line, "log skipped because too long");
        return;
    }

    // display log
    std::FILE *stream = level == LogLevel::MESSAGE ? stdout : stderr;
    fprintf(stream, "[%s] %s:%u: %s\n", level_names[(uint32_t)level], filepath, line, buffer);

    // stop execution when asserting
    if (level == LogLevel::ASSERT)
        abort();
}
#define LOG_ASSERT(_condition_, ...) if(!(_condition_)) { gassert(FORMAT_FILEPATH(__FILE__), __LINE__, __VA_ARGS__); }
#define TEST(_condition_) LOG_ASSERT(_condition_, #_condition_);

void test_hash()
{
    TEST(Hash::generate("gorilla") == 3689041125);
    TEST(Hash::generate("gorilla") == Hash::generate("gorilla", 7));
}

struct A
{
    Signal<bool, uint32, const char*> events;
};
struct B
{
    void on_event(bool a, uint32 b, const char *c)
    {
        boolean = a;
        integer = b;
        string = c;
    }
    bool boolean;
    uint32 integer;
    const char *string;
};
void test_signal()
{
    A a;
    B b;
    memset(&b, 0, sizeof(b));

    a.events.send(true, 1337, "foo");
    TEST(b.boolean == false);
    TEST(b.integer == 0);
    TEST(b.string == nullptr);

    a.events.connect(&b, &B::on_event);
    a.events.send(true, 1337, "foo");
    TEST(b.boolean == true);
    TEST(b.integer == 1337);
    TEST(strcmp(b.string, "foo") == 0);
    memset(&b, 0, sizeof(b));

    a.events.disconnect_all();
    a.events.send(true, 1337, "foo");
    TEST(b.boolean == false);
    TEST(b.integer == 0);
    TEST(b.string == nullptr);
}

class Foo {};
void test_singleton()
{
    TEST(Singleton<Foo>::is_created() == false);
    Singleton<Foo>::create();
    TEST(Singleton<Foo>::is_created() == true);
    Singleton<Foo>::destroy();
    TEST(Singleton<Foo>::is_created() == false);
}

void test_hash_map()
{
    HashMap<int, int> values;

    values.add(1, 10);
    values.add(10, 100);
    values.add(100, 1000);
    TEST(values.get_size() == 3);
    TEST(values[1] == 10);
    TEST(values[10] == 100);
    TEST(values[100] == 1000);

    int array_results[3] = {0,0,0};
    int *results = array_results;
    HashMap<int, int>::Iterator it = values.get_first();
    HashMap<int, int>::Iterator it_end = values.get_last();
    while (it != it_end)
    {
        *results++ = it.get_value();
        ++it;
    }
    TEST(array_results[0] + array_results[1] + array_results[2] == 1110);

    values.clear();
    TEST(values.is_empty() == true);
}

void test_vector()
{
    Vector<int> values;

    TEST(values.is_empty() == true);
    TEST(values.get_size() == 0)
    TEST(values.get_capacity() == 0);

    values.add(18);
    TEST(values.is_empty() == false);
    TEST(values.get_size() == 1)
    TEST(values.get_capacity() > 1);
    TEST(values[0] == 18);

    values.resize(8, 1337);
    TEST(values.get_size() == 8)
    TEST(values.get_capacity() >= 8);
    TEST(values[0] == 1337);

    values.insert(2, 1338);
    TEST(values.get_size() == 9)
    TEST(values[2] == 1338);

    TEST(values.find_index(1338) == 2)
    values.remove_index(2);
    TEST(values.find_index(1338) == (uint32)-1);

    values.clear();
    TEST(values.is_empty() == true);
    TEST(values.get_capacity() > 0);

    values.expand(1);
    TEST(values.get_size() == 1);

    values.expand_to(128, 88);
    TEST(values.get_size() == 129)
    TEST(values.get(88) == 88);

    values.clear();
    values.add(3); values.add(2); values.add(1); values.add(0);
    for (uint32 i = 0; i < 4; ++i)
        TEST(values[i] == 3-i);
    values.sort();
    for (uint32 i = 0; i < 4; ++i)
        TEST(values[i] == i);

    int stack_array[4] = { 1, 3, 3, 7 };
    values.set_buffer(stack_array, 2, 4, false);
    TEST(values.get_size() == 2);
    TEST(values.get_capacity() == 4);
    TEST(values[1] == 3);
}


void test_time()
{
    int64 start = Time::get_performance_counter();
    Thread::sleep(1000);
    TEST(Time::get_elapsed_time(start, Time::get_performance_counter()) >= 1000.f);
}

int32 main(int32 argc, const char *argv[])
{
    static const struct
    {
        const char *name;
        void (*callback)();
    } tests[] =
    {
        {"hash",        &test_hash},
        {"signal",      &test_signal},
        {"singleton",   &test_singleton},
        {"hash_map",  &test_hash_map},
        {"vector",    &test_vector},
        {"time",      &test_time},
    };

    const char *unit_test_name = argc < 2 ? nullptr: argv[1];
    const uint32 test_count = sizeof(tests) / sizeof(*tests);
    for(uint32 i = 0; i < test_count; i++)
    {
        bool execute_test = unit_test_name == nullptr || strcmp(tests[i].name, unit_test_name) == 0;
        if(execute_test)
        {
            //ProfilerItem item(tests[i].name);
            tests[i].callback();
            //PROFILE_STOP(TEST);
            if(unit_test_name)
                return 0;
        }
    }

    return 0;
}