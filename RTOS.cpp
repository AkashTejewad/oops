#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// Task structure
struct Task {
    int id;
    int period_ms;
    chrono::steady_clock::time_point last_run;
};

int main() {

    // Create 2 simple tasks
    Task task1 = {1, 1000, chrono::steady_clock::now()};
    Task task2 = {2, 2000, chrono::steady_clock::now()};

    while (true) {
        auto now = chrono::steady_clock::now();

        // Task 1
        if (chrono::duration_cast<chrono::milliseconds>(now - task1.last_run).count()
            >= task1.period_ms) {

            cout << "Running Task 1 (every 1 second)" << endl;
            task1.last_run = now;
        }

        // Task 2
        if (chrono::duration_cast<chrono::milliseconds>(now - task2.last_run).count()
            >= task2.period_ms) {

            cout << "Running Task 2 (every 2 seconds)" << endl;
            task2.last_run = now;
        }

        // Small delay (like RTOS tick)
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    return 0;
}
