#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {


    Matrix m1(3,3,4);
    Matrix m2(3,3,4);
    Matrix* m3 = m1.addDynamic(m2);


    cout << m1 << endl ;
    cout << m2 << endl ;
    cout << *m3 << endl;

    //Matrix m2(3,4,4);

	//Test add static
    //Matrix m3 = m1.addStatic(m2);
    /*
    cout << m1 << endl;
    cout << "m2" << endl;
    cout << m2 << endl;
    cout << "m3" << endl;
    cout << m3 << endl;

    Matrix* m4 = m1.addDynamic(m2);

    cout << "m4" << endl;
    cout << *m4 << endl;

    delete m4;


*/
    return 0;


}
