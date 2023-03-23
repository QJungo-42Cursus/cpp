#pragma once
#ifndef COLOR_H
# define COLOR_H

class Color{
public:

    static const std::string& RED(void)
    {
		static const char* str = "\033[1;31m";
        return str;
    }

private:
	Color();
}

namespace color {
	const char* RED = "\033[1;31m";
	const char* GREEN = "\033[1;32m";
	const char* YELLOW = "\033[1;33m";
	const char* BLUE = "\033[1;34m";
	const char* MAGENTA = "\033[1;35m";
	const char* CYAN = "\033[1;36m";
	const char* BOLD = "\033[1m";
	const char* RESET = "\033[0m";
}

#endif /* COLOR_H */
