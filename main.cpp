#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

    /*******************************
    *   Tests Matrix
    *******************************/


    int modulo = 10;

    cout << "Default constructor\n";

    Matrix m1(3,3,modulo);
    cout << "m1 (modulo = " << modulo << ")\n" << m1 << endl;

    cout << "Copy constructor\n";

    Matrix m2(m1);

    cout << "m2 = m1\n" << m2 << endl;


    {
        cout << "Operation with static allocation \n\n";


        cout << "Static addition\n m3 = m1 + m2 \n";

        Matrix m3 = m1.addStatic(m2);
        cout << m3 << endl;

        cout << "Static subtraction\n m4 = m3 - m1\n";

        Matrix m4 = m3.subStatic(m1);
        cout << m4 << endl;

        cout << "Static multiplication\n m5 = m4 * m1 \n";

        Matrix m5 = m4.multiplyStatic(m1);
        cout << m5 << endl;

    }

    {
        //Operations with dynamic allocation

        cout << "Dynamic addition\n";

        Matrix *m3 = m1.addDynamic(m2);
        cout << *m3 << endl;

        cout << "Dynamic substraction\n";

        Matrix *m4 = m3->subDynamic(m1);
        cout << *m4 << endl;


        cout << "Dynamic multiplication\n";

        Matrix *m5 = m4->multiplyDynamic(m1);
        cout << *m5 << endl;


        delete m3;
        delete m4;
        delete m5;
    }

    {
        cout << "Operation on self" << endl;
        Matrix m1(3,3,modulo);
        //Matrix tmp = m1;
        Matrix m2(1,2,modulo);
        cout << m1 << endl << m2 << endl;


        cout << "Addition to self" << endl;
        m1.addSelf(m2);
        cout << m1 << endl;


        cout << "Substraction to self" << endl;
        //m1 = tmp;
        m1.subSelf(m2);
        cout << m1 << endl;


        //cout << tmp << endl;    //TODO pb constructeur copie
        cout << "Multiplication to self" << endl;
        //m1 = tmp;
        cout << m1 << endl << m2 << endl;
        m1.multiplySelf(m2);
        cout << m1 << endl << endl;
    }


    {
        cout << "Operation on different modulo should not work" << endl;
        Matrix m3(2,5,modulo);
        Matrix m4(5,2,30);

        //Static

        try {
            Matrix m5 = m3.addStatic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what()<< endl;
        }

        try {
            Matrix m5 = m3.subStatic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what() << endl;
        }

        try {
            Matrix m5 = m3.multiplyStatic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what()<< endl;
        }

        //Dynamic

        try {
            Matrix* m6 = m3.addDynamic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what()<< endl;
        }

        try {
            Matrix* m6 = m3.subDynamic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what()<< endl;
        }

        try {
            Matrix* m6 = m3.multiplyDynamic(m4);
        }catch(invalid_argument& ex){
            cout << "Exception catched : " << ex.what()<< endl;
        }
    }
    
    return 0;

}
