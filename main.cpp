#include <iostream>
#include <array>
//#include <functional>
#include <vector>
#include <iomanip>
#include <string>


using namespace std;

template <typename T, size_t M, size_t N>
class matrix{
private:
    array <array<T, M>, N> macierz;
public:

    void printMatrix(){
        for(auto rzad:macierz){
            cout<<endl;
            for(auto value:rzad){
                cout<<setw(12)<< value<<"|";
            }
        }
        cout<<endl;
    }

    matrix() {                                                                                  //konstruktor domyslny
        if (M < 1) {
            throw std::underflow_error { "liczba wierszy mniejsza niz jeden" };
        }
        if (N < 1) {
            throw std::underflow_error { "liczba kolumn mniejsza niz jeden" };
        }
    }

    matrix (matrix& a){                                                                         //konstruktor kopiujacy
        for(int i=0; i<macierz.size(); ++i){
            for(int j=0; j<macierz[i].size(); ++j){
                macierz[i][j] = a.macierz[i][j];
            }
        }
    }

    matrix(T x){                                                                                //konstruktor jakis tam
        for(auto &rzad:macierz){
            for(auto &value:rzad){
                value=x;
            }
        }
    }

    matrix operator+(T a){                                                                      //przeladowanie operatora + z liczba
        matrix wynik;
        for(int i=0; i<macierz.size(); ++i){
            for(int j=0; j<macierz[i].size(); ++j){
                wynik.macierz[i][j] = macierz[i][j] +a;
            }
        }
        return wynik;
    }

    matrix operator*(T a){                                                                      //przeladowanie operatora * z liczba
        matrix wynik;
        for(int i=0; i<macierz.size(); ++i){
            for(int j=0; j<macierz[i].size(); ++j){
                wynik.macierz[i][j] = macierz[i][j] *a;
            }
        }
        return wynik;
    }



    matrix operator +(matrix m1){                                                               //przeladowanie operatora + z druga macierza
        matrix wynik;
        for(int i=0; i<macierz.size(); ++i){
            for(int j=0; j<macierz[i].size(); ++j){
                wynik.macierz[i][j] = macierz[i][j] + m1.macierz[i][j];
            }
        }
        return wynik;
    }

    matrix operator *(matrix m1){                                                               //przeladowanie operatora * z druga macierza
        matrix wynik;
        for(int i=0; i<macierz.size(); ++i){
            for(int j=0; j<macierz[i].size(); ++j){
                wynik.macierz[i][j] = macierz[i][j] * m1.macierz[i][j];
            }
        }
        return wynik;
    }
};


int main()
{
    matrix<int, 3,3> m1(5.5);
    matrix<int, 3,3> m2(1.2);
    matrix<int, 3,3> m3(0);
    matrix<int, 2,2> m4;
    m1.printMatrix();
    m2.printMatrix();
    m2=m1+2.3+3.7;
    m1=m2*10.5;
    m1.printMatrix();
    m2.printMatrix();
    m3=m1+m2;
    m3.printMatrix();
    m3=m1*m2;
    m3.printMatrix();
    matrix<int, 3,3> m5(m3);
    m5.printMatrix();
    m4.printMatrix();
    cout << "Hello World!" << endl;
    return 0;
}
