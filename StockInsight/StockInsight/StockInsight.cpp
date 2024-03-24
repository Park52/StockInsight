#include <iostream>
#include "common.hpp"
#include "logger.hpp"

int main()
{
    SILogger logger;
    if (true != logger.Initialize())
    {
        return 1;
    }

    logger.write(log_level::err, "Hello {}", "world");
    return 0;
}