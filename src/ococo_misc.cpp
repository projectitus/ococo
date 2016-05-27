#include "ococo_misc.h"

void ococo::print_version(){
    std::cout << "Program: Ococo (online consensus caller, "
        << "http://github.com/karel-brinda/ococo)." << std::endl;
    std::cout << "Version: " << OCOCO_VERSION << std::endl;
    /* " ("
        << 8 * sizeof(OCOCO_BASIC_TYPE) << "bit variant"
        << ", counter size " << BITS_PER_COUNTER << "bits";

#ifdef DEBUGGING_MODE
    std::cerr << ", debugging mode";
#endif

#ifdef VERBOSE_VCF
    std::cerr << ", verbose VCF";
#endif

    std::cerr << ")." << std::endl;*/
}

void ococo::fatal_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[ococo:fatal-error]: ");
    vfprintf(stderr, format, args);
    va_end(args);
}

void ococo::error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[ococo:error]: ");
    vfprintf(stderr, format, args);
    va_end(args);
}

void ococo::warning(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[ococo:warning]: ");
    vfprintf(stderr, format, args);
    va_end(args);
}

void ococo::info(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "[ococo]: ");
    vfprintf(stderr, format, args);
    va_end(args);
}

bool ococo::file_exists(const std::string &fn) {
    FILE *file;

    file = fopen(fn.c_str(), "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}