# include <iostream>
# include <cstdlib>

using namespace std;

void printMatrix(float matrix[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

/* Issue: As passing by reference, modifying c in foo will 
 * modify the original values in main scope. In this case,
 * b and c point to the same memory address, so setting
 * c[i] to 0.0 will also clear b, giving incorrect results.
 */
void foo(float A[6][6], float b[6], float c[6]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        c[i] = 0.0f;
        for (j = 0; j < 6; j++) {
            c[i] += A[i][j] * b[j];
	}
    }
}

/* Fix: Store results of matrix multiplication in temp
 * array as to not inadvertantyl overwrite b, then at
 * completion of multiplication, transfer results to c.
 */
void fooFixed(float A[6][6], float b[6], float c[6]) {
    float product[6]; // Store results in temp array

    int i,j;
    for (i = 0; i < 6; i++) {
        product[i] = 0.0f;
	for (j = 0; j < 6; j++) {
            product[i] += A[i][j] * b[j];
	}
    }

    // Copy results to output array
    for (i = 0; i < 6; i++) {
        c[i] = product[i];
    }

}

// Main function for context and testing
int main() {
    float F[6][6] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    float x[6] = {5,5,5,5,5,5};
    float x2[6] = {5,5,5,5,5,5};

    cout << "Inputs:" << endl;
    printMatrix(x, 6);
    printMatrix(x2, 6);

    foo(F, x, x);
    fooFixed(F, x2, x2);

    cout << "Outputs:" << endl;
    printMatrix(x, 6);
    printMatrix(x2, 6);

    return 0;
}
