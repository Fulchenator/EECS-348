/*
Lab 13
Q1. Is there a fault in the program? If so, locate it and explain.
    Yes there is a fault in the program and it is at: int i = 1.
    It skips the first lecture so any absence on the first day is not counted.

Q2. Define a test case that does not execute the fault.
    It is impossible to create a valid test case that does not execute the fault, 
    because the loop always runs for i = 1 through 9.

Q3. Test case that executes the fault but does not result in an error state.
    A test case like [1,0,0,0,0,0,0,0,0,0] executes the faulty line but does not cause an error 
    state because skipping the first lecture does not change the absence count. 
    Both the correct and buggy functions return true.

Q4. Test case that results in an error state but not a failure.
    A test case like [0,0,0,0,1,1,1,1,1,1] causes an incorrect internal absent
    count but still produces the same final output. Both versions say the student fails, so there is an error state but no failure.
Q5. Test case that results in a failure.
    A test case like [0,0,0,1,1,1,1,1,1,1] results in a failure because the correct function returns true but the buggy function returns false.
    The skipped first absence leads to a wrong decision, producing incorrect external behavior.
*/

#include <iostream>
#include <vector>

bool fail_lecture_buggy(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < static_cast<int>(attendance_records.size()); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}
bool fail_lecture_correct(const std::vector<int>& attendance_records) {
    int absent_count = 0;

    for (int i = 0; i < static_cast<int>(attendance_records.size()); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

void print_result(const std::vector<int>& record, const std::string& name) {
    bool buggy = fail_lecture_buggy(record);
    bool correct = fail_lecture_correct(record);

    std::cout << name << ":\n";
    std::cout << "  Attendance: ";
    for (int v : record) {
        std::cout << v << " ";
    }
    std::cout << "\n";
    std::cout << "  Buggy result: " << buggy << "\n";
    std::cout << "  Correct result: " << correct << "\n";
    std::cout << "\n";
}

int main() {
    std::vector<int> test_Q3 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int> test_Q4 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    std::vector<int> test_Q5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    print_result(test_Q3, "Q3 (fault executed, no error state)");
    print_result(test_Q4, "Q4 (error state, no failure)");
    print_result(test_Q5, "Q5 (failure)");

    return 0;
}
