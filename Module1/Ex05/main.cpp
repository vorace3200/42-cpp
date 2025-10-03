#include <iostream>
#include <string>
#include "harl.hpp"

int main() {
    
    Harl* debug_log = new Harl;
    debug_log->complain("DEBUG");
    debug_log->complain("ERROR");
    return 0;
}