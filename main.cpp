#include <iostream>
using namespace std;

class Responsi
{
    friend istream &operator>>(istream &in, Responsi &A);
    friend ostream &operator<<(ostream &out, Responsi &A);
private:
    int a, b, x, y;
public:
    int Faktorial(int fak); // fungsi faktorial
    int kombinasi(int hasil);
};

istream &operator>>(istream &in, Responsi &A)
{
    cout<<"Yuya ingin membeli 4 makanan dan 2 minuman kesukaannya tetapi ia hanya diizinkan membeli 1 makanan dan 1 minuman oleh ibunya";
    cout<<"\nBerapa banyak cara Yuya membeli makanan dan minuman tersebut??\n";
    cout<<"Makanan yang diinginkan Yuya: "; in>>A.a;
    cout<<"Minuman yang diinginkan Yuya: "; in>>A.b;
    cout<<"Makanan yang dibolehkan dibeli hanya: "; in>>A.x;
    cout<<"Minuman yang dibolehkan dibeli hanya: "; in>>A.y;

    return in;
}

ostream &operator<<(ostream &out, Responsi &A)
{
    int banyakCara;
    out<<"\t\t==========Penyelesaian==========\n";
    out<<"Karena tidak ditenukan urutan pengambilannya maka menggunakan kombinasi: \n";
    out<<"Banyak cara untuk membeli makanan dan minuman tersebut adalah: ";
    out<<A.kombinasi(banyakCara);
    return out;
}

int Responsi::kombinasi(int hasil)
{
    int n,r,z; // deklarasi variabel untuk total dan selisih
    n = a + b; // n total makanan dan minuman kesukaan
    z = x + y; // z total yang diizinkan dibeli

    r = n - z;
    hasil = Faktorial(n) / (Faktorial(z)*Faktorial(r)); // rumus dari kombinasi
    
    return hasil;

}

int Responsi::Faktorial(int fak)
{
    if(fak==0 || fak==1)
        return 1;
    else
        return fak*Faktorial(fak-1);
}

int main(){
    Responsi obj;
    cin>>obj;
    cout<<obj;
}