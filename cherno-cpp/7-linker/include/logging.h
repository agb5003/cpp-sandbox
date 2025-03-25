/* Even with #pragma once, double-linking errors can still occur. With multiple translation units,
 * it is possible to #include a .h file multiple times in different translation units, which will
 * cause the linker to find multiple definitions of the same function.
 * 
 * This is why it is good practice to *not* write the implementation of the function in a header
 * file, as it may get #included by multiple files. Instead, the implementation is put into a .cpp
 * file, and only the function declaration/signature is in a header file. This way there's only one
 * definition of the function, but it can be used by multiple other .cpp files.
*/

#pragma once

void Log(const char* message);

// MOVE THIS TO logging.cpp
// static void Log(const char* message) {
//     std::cout << message << std::endl;
// }
