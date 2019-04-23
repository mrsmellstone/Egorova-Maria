#include <iostream>

using namespace std;

class Vector3D{
public:
    double pos[3];
    Vector3D(double x = 0, double y = 0, double z = 0){
        pos[0] = x;
        pos[1] = y;
        pos[2]= z;
    }
    double operator[](int i){
        return pos[i];
    }
};

Vector3D operator+(Vector3D a, Vector3D b){
    Vector3D c;
    for (int i = 0; i < 3; i++) {
        c.pos[i] = a.pos[i] + b.pos[i];
    }
    return c;
}

Vector3D operator-(Vector3D a, Vector3D b){
    Vector3D c;
    for (int i = 0; i < 3; i++) {
        c.pos[i] = a.pos[i] - b.pos[i];
    }
    return c;
}

Vector3D operator*(double a, Vector3D b){
    Vector3D c;
    for (int i = 0; i < 3; i++) {
        c.pos[i] = a * b.pos[i];
    }
    return c;
}

Vector3D operator*(Vector3D b, double a){
    Vector3D c;
    c = a * b;
    return c;
}

double operator*(Vector3D b, Vector3D a){
    double c = 0;
    for (int i = 0; i < 3; i++) {
        c += a.pos[i] * b.pos[i];
    }
    return c;
}

ostream& operator<<(ostream& out, Vector3D a){
    out << a.pos[0] << ' ' << a.pos[1] << ' ' << a.pos[2];
    return out;
}

istream& operator>>(istream& in, Vector3D a){
    in >> a.pos[0] >> a.pos[1] >> a.pos[2];
    return in;
}

class Matrix3D{
public:
    double matr[3][3];
    Matrix3D(){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                matr[i][j] = 0;
    }
    double Determinant(){
        double c;
        c = matr[0][0]*(matr[1][1]*matr[2][2]-matr[2][1]*matr[1][2]) - matr[0][1]*(matr[1][0]*matr[2][2]-matr[2][0]*matr[1][2]) + matr[0][2]*(matr[1][0]*matr[1][2] - matr[1][1]*matr[2][0]);
        return c;
    }
};

Matrix3D operator+(Matrix3D a, Matrix3D b) {
    Matrix3D c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            c.matr[i][j] = a.matr[i][j] + b.matr[i][j];
        }
    }
    return c;
}

Matrix3D operator-(Matrix3D a, Matrix3D b) {
    Matrix3D c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            c.matr[i][j] = a.matr[i][j] - b.matr[i][j];
        }
    }
    return c;
}

Matrix3D operator*(double a, Matrix3D b) {
    Matrix3D c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            c.matr[i][j] = a * b.matr[i][j];
        }
    }
    return c;
}

Vector3D operator*(Matrix3D a, Vector3D b){
    Vector3D c;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c.pos[i] += a.matr[i][j] * b.pos[j];
        }
    }
    return c;
}
Matrix3D operator*(Matrix3D a, Matrix3D b) {
    Matrix3D c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++)
                c.matr[i][j] += a.matr[i][k] * b.matr[k][j];
        }
    }
    return c;
}

int main()
{
    Vector3D a(1, 3, 5), b, c;
    Matrix3D matrix;
    double d = 2;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matrix.matr[i][j] = i + j;
    Matrix3D matrix1 = matrix * matrix;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << matrix1.matr[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
