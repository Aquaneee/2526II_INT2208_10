#include <iostream>
#include <string>
#include <vector>

using namespace std;

string classifyTriangle(int a, int b, int c) {
    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100) {
        return "Invalid Input";
    }
    
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        return "Not a Triangle";
    }
    
    if (a == b && b == c) {
        return "Equilateral";
    }
    else if (a == b || b == c || a == c) {
        return "Isosceles";
    }
    else {
        return "Scalene";
    }
}

struct TestCase {
    string id;
    int a, b, c;
    string expectedOutput;
};

int main() {
    vector<TestCase> testSuite = {
        {"TC 01", 0, 50, 50, "Invalid Input"},
        {"TC 02", 101, 50, 50, "Invalid Input"},
        {"TC 03", 50, 0, 50, "Invalid Input"},
        {"TC 04", 50, 50, 101, "Invalid Input"},
        {"TC 05", 50, 101, 50, "Invalid Input"},
        {"TC 06", 50, 50, 0, "Invalid Input"},
        
        {"TC 07", 10, 20, 50, "Not a Triangle"},
        {"TC 08", 1, 2, 3, "Not a Triangle"},
        {"TC 09", 50, 50, 50, "Equilateral"},
        {"TC 10", 100, 100, 100, "Equilateral"},
        {"TC 11", 50, 50, 40, "Isosceles"},
        {"TC 12", 40, 50, 50, "Isosceles"},
        {"TC 13", 50, 40, 50, "Isosceles"},
        {"TC 14", 3, 4, 5, "Scalene"},
        {"TC 15", 98, 99, 100, "Scalene"}
    };

    int passedCount = 0;
    int failedCount = 0;

    cout << "=================== RUNNING TEST SUITE ===================" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (const auto& tc : testSuite) {
        string actualOutput = classifyTriangle(tc.a, tc.b, tc.c);
        
        cout << "[" << tc.id << "] Input: (" << tc.a << ", " << tc.b << ", " << tc.c << ") | ";
        cout << "Expected: " << tc.expectedOutput << " | Actual: " << actualOutput << " -> ";

        if (actualOutput == tc.expectedOutput) {
            cout << "PASSED" << endl;
            passedCount++;
        } else {
            cout << "FAILED" << endl;
            failedCount++;
        }
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "=================== SUMMARY REPORT =======================" << endl;
    cout << "Total Test Cases: " << testSuite.size() << endl;
    cout << "Passed          : " << passedCount << endl;
    cout << "Failed          : " << failedCount << endl;
    cout << "Success Rate    : " << (passedCount * 100 / (int)testSuite.size()) << "%" << endl;
    cout << "==========================================================" << endl;

    return 0;
}