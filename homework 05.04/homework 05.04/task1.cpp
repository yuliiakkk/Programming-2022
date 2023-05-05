//#include <iostream>
//#include <iomanip>
//#include <sstream>
//#include <cmath>
//#include <fstream>
//
//using namespace std;
//
//string Modified(double (*func)(double), double* arr, int size) {
//    ostringstream os;
//    os << fixed << setprecision(2);
//
//    os << "|    i   |      a[i]     |    modified a[i]   |\n";
//    os << string(32, '-') << '\n';
//
//    for (int i = 0; i < size; i++) {
//        double modified = func(arr[i]);
//
//        os << "|" << setw(8) << i << " |" << setw(15) << arr[i] << " |" << setw(19) << modified << " |\n";
//    }
//
//    return os.str();
//}
//
//int main() {
//    const int SIZE = 5;
//    double arr[SIZE] = { 1.5, 2.3, -4.7, 0.8, 5.1 };
//
//    ofstream output_file("output.txt");
//
//    output_file << "Modified array (x^2):\n" << Modified([](double x) { return x * x; }, arr, SIZE) << '\n';
//    output_file << "Modified array (sin(x) + cos(x) - tan(x)):\n" << Modified([](double x) { return sin(x) + cos(x) - tan(x); }, arr, SIZE) << '\n';
//    output_file << "Modified array (round(x)):\n" << Modified([](double x) { return round(x); }, arr, SIZE) << '\n';
//
//    output_file.close();
//
//    return 0;
//}
