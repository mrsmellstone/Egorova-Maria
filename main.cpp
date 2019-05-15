#include <iostream>

using namespace std;

class Vector3D{
protected:
    double pos[3];
public:
    Vector3D(double x = 0, double y = 0, double z = 0){
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
    }
    double& operator[](int i){
        return pos[i];
    }
    double operator[](int i) const{
        return pos[i];
    }

    Vector3D operator+(const Vector3D a) const{
        Vector3D c;
        for (int i = 0; i < 3; i++) {
            c.pos[i] = a.pos[i] + pos[i];
        }
        return c;
    }
    Vector3D operator-(const Vector3D a) const{
        Vector3D c;
        for (int i = 0; i < 3; i++) {
            c.pos[i] = pos[i] - a.pos[i];
        }
        return c;
    }

    friend Vector3D operator*(const double a, const Vector3D b){
        Vector3D c;
        for (int i = 0; i < 3; i++) {
            c.pos[i] = a * b.pos[i];
        }
        return c;
    }

    Vector3D operator*(const double a) const{
        Vector3D c;
        for (int i = 0; i < 3; i++) {
            c.pos[i] = a * pos[i];
        }
        return c;
    }

    double operator*(const Vector3D a) const{
        double c = 0;
        for (int i = 0; i < 3; i++) {
            c += a.pos[i] * pos[i];
        }
        return c;
    }

    friend ostream& operator<<(ostream& out, const Vector3D a){
        out << a.pos[0] << ' ' << a.pos[1] << ' ' << a.pos[2];
        return out;
    }

    friend istream& operator>>(istream& in, Vector3D a){
        in >> a.pos[0] >> a.pos[1] >> a.pos[2];
        return in;
    }

};

class Matrix3D{
protected:
    double matr[3][3];
public:
    Matrix3D(){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                matr[i][j] = 0;
    }
    const double* operator[](int i) const{
        return matr[i];
    }
    double* operator[](int i){
        return matr[i];
    }
    double Determinant() const{
        double c;
        c = matr[0][0]*(matr[1][1]*matr[2][2]-matr[2][1]*matr[1][2]) - matr[0][1]*(matr[1][0]*matr[2][2]-matr[2][0]*matr[1][2]) + matr[0][2]*(matr[1][0]*matr[1][2] - matr[1][1]*matr[2][0]);
        return c;
    }
    Matrix3D operator+(const Matrix3D a) const{
        Matrix3D c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                c[i][j] = a[i][j] + matr[i][j];
            }
        }
        return c;
    }

    Matrix3D operator-(const Matrix3D a) const{
        Matrix3D c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                c[i][j] = matr[i][j] - a[i][j];
            }
        }
        return c;
    }

    friend Matrix3D operator*(const double a, const Matrix3D b) {
        Matrix3D c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                c[i][j] = a * b[i][j];
            }
        }
        return c;
    }

    Matrix3D operator*(const double a) const{
        Matrix3D c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                c[i][j] = a * matr[i][j];
            }
        }
        return c;
    }

    Vector3D operator*(const Vector3D b) const{
        Vector3D c;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                c[i] = c[i] + matr[i][j] * b[j];
            }
        }
        return c;
    }
    Matrix3D operator*(const Matrix3D b) const{
        Matrix3D c;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++)
                    c.matr[i][j] += matr[i][k] * b.matr[k][j];
            }
        }
        return c;
    }
};

int main()
{
    Vector3D a(1, 3, 5), b, c;
    double r = 2;
    c = r * a;
    cout << r * a << endl << a * r;
//    Matrix3D matrix;
//    double d = 2;
//    for(int i = 0; i < 3; i++)
//        for(int j = 0; j < 3; j++)
//            matrix.matr[i][j] = i + j;
//    Matrix3D matrix1 = matrix * matrix;
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++)
//            cout << matrix1.matr[i][j] << ' ';
//        cout << endl;
//    }
    return 0;
}
