#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct TestCase {
    string id;
    int age;
    double income;
    int credit_score;
    string employment;
    string expected;
    string actual;
    string status;
};

string evaluateLoan(int age, double income, int credit_score, string employment) {
    if (age < 18 || age > 65) return "Invalid Input";
    if (income < 5.0 || income > 500.0) return "Invalid Input";
    if (credit_score < 300 || credit_score > 850) return "Invalid Input";
    if (employment != "C" && employment != "F") return "Invalid Input";

    string risk;
    if (credit_score >= 300 && credit_score <= 500) risk = "High";
    else if (credit_score >= 501 && credit_score <= 700) risk = "Medium";
    else risk = "Low";

    if (risk == "High") return "REJECT";
    if (income < 15.0) {
        if (employment == "C" && risk == "Low") return "MANUAL REVIEW";
        return "REJECT";
    } else {
        if (risk == "Low" || risk == "Medium") {
            if (employment == "C") return "APPROVE";
            else if (employment == "F") return "MANUAL REVIEW";
        }
    }
    return "REJECT";
}

int main() {
    vector<TestCase> tests = {
        {"TC 01", 17, 50.0, 750, "C", "Invalid Input", "", ""},
        {"TC 02", 66, 50.0, 750, "C", "Invalid Input", "", ""},
        {"TC 03", 30, 4.9, 750, "C", "Invalid Input", "", ""},
        {"TC 04", 30, 500.1, 750, "C", "Invalid Input", "", ""},
        {"TC 05", 30, 50.0, 299, "C", "Invalid Input", "", ""},
        {"TC 06", 30, 50.0, 851, "C", "Invalid Input", "", ""},
        {"TC 07", 30, 50.0, 750, "X", "Invalid Input", "", ""},
        
        {"TC 08 (R1)", 18, 5.0, 500, "C", "REJECT", "", ""},
        {"TC 09 (R1)", 65, 500.0, 300, "F", "REJECT", "", ""},
        {"TC 10 (R2)", 30, 14.9, 501, "C", "REJECT", "", ""},
        {"TC 11 (R3)", 35, 10.0, 600, "F", "REJECT", "", ""},
        {"TC 12 (R4)", 40, 15.0, 700, "C", "APPROVE", "", ""},
        {"TC 13 (R5)", 25, 25.5, 650, "F", "MANUAL REVIEW", "", ""},
        {"TC 14 (R6)", 45, 12.0, 701, "C", "MANUAL REVIEW", "", ""},
        {"TC 15 (R7)", 50, 8.5, 750, "F", "REJECT", "", ""},
        {"TC 16 (R8)", 60, 100.0, 850, "C", "APPROVE", "", ""},
        {"TC 17 (R9)", 32, 15.1, 800, "F", "MANUAL REVIEW", "", ""}
    };

    cout << "====================== RUNNING TEST SUITE ======================" << endl << endl;

    int passedCount = 0;
    int failedCount = 0;

    for (auto& tc : tests) {
        tc.actual = evaluateLoan(tc.age, tc.income, tc.credit_score, tc.employment);
        
        if (tc.actual == tc.expected) {
            tc.status = "PASSED";
            passedCount++;
        } else {
            tc.status = "FAILED";
            failedCount++;
        }

        cout << "[" << tc.id << "] Input: (" 
             << tc.age << ", " 
             << fixed << setprecision(1) << tc.income << ", " 
             << tc.credit_score << ", " 
             << tc.employment << ") | Expected: " 
             << tc.expected << " | Actual: " 
             << tc.actual << " -> " 
             << tc.status << endl;
    }

    cout << "----------------------------------------------------------------" << endl;
    cout << "====================== SUMMARY REPORT ======================" << endl;
    cout << "Total Test Cases: " << tests.size() << endl;
    cout << "Passed          : " << passedCount << endl;
    cout << "Failed          : " << failedCount << endl;
    
    double successRate = (double)passedCount / tests.size() * 100;
    cout << "Success Rate    : " << fixed << setprecision(0) << successRate << "%" << endl;
    cout << "============================================================" << endl;

    return 0;
}