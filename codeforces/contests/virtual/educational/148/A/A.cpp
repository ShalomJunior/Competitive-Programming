#include <complex>
#include <iostream>
#include <vector>

typedef std::complex<double> Complex;
typedef std::vector<Complex> Polynomial;

const double PI = 3.14159265358979323846;

// Recursive FFT function
void fft(Polynomial& poly, bool inverse = false) {
    int n = poly.size();
    if (n <= 1) {
        return;
    }

    Polynomial even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.push_back(poly[i]);
        }
        else {
            odd.push_back(poly[i]);
        }
    }

    fft(even, inverse);
    fft(odd, inverse);

    double angle = 2 * PI / n * (inverse ? -1 : 1);
    Complex w(1);
    Complex wn(cos(angle), sin(angle));

    for (int k = 0; k < n / 2; k++) {
        Complex t = w * odd[k];
        Complex u = even[k];

        poly[k] = u + t;
        poly[k + n / 2] = u - t;

        if (inverse) {
            poly[k] /= 2;
            poly[k + n / 2] /= 2;
        }

        w *= wn;
    }
}

// Polynomial multiplication using FFT
Polynomial multiplyPolynomials(const Polynomial& A, const Polynomial& B) {
    int size = 1;
    while (size < A.size() + B.size()) {
        size <<= 1;
    }

    Polynomial paddedA(size, 0);
    Polynomial paddedB(size, 0);

    for (int i = 0; i < A.size(); i++) {
        paddedA[i] = A[i];
    }

    for (int i = 0; i < B.size(); i++) {
        paddedB[i] = B[i];
    }

    fft(paddedA);
    fft(paddedB);

    Polynomial result(size);
    for (int i = 0; i < size; i++) {
        result[i] = paddedA[i] * paddedB[i];
    }

    fft(result, true);

    return result;
}

// Utility function to print a polynomial
void printPolynomial(const Polynomial& poly) {
    for (const Complex& coeff : poly) {
        std::cout << coeff.real() << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Polynomial A = { 1, 2, 3 };  // Coefficients of A: 1 + 2x + 3x^2
    Polynomial B = { 4, 5, 6 };  // Coefficients of B: 4 + 5x + 6x^2

    Polynomial result = multiplyPolynomials(A, B);

    std::cout << "Result: ";
    printPolynomial(result);

    return 0;
}
