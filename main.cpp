#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>

void fillMemory() {
    std::size_t totalMemory = 0;
    std::size_t chunkSize = 1024 * 1024; // 1 MB
    void* ptr = nullptr;

    while (true) {
        ptr = malloc(chunkSize);
        if (ptr == nullptr) {
            std::cerr << "Failed to allocate more memory. Memory is likely full." << std::endl;
            break;
        }
        memset(ptr, 0, chunkSize); // Fill the allocated memory with zeros
        totalMemory += chunkSize;
        std::cout << "Allocated " << totalMemory / (1024 * 1024) << " MB so far." << std::endl;
    }
}

int main() {
    std::cout << "Press the right mouse button (M2) to start filling memory..." << std::endl;

    while (true) {
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) { // Check if right mouse button is pressed
            std::cout << "Right mouse button pressed. Filling memory..." << std::endl;
            fillMemory();
            break;
        }
        Sleep(100); // Sleep for 100ms to avoid high CPU usage
    }

    return 0;
}