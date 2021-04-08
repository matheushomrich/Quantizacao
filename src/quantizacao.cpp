//
//  main.cpp
//  PPMLoader
//
//  Created by Márcio Sarroglia Pinho on 05/04/21.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
class RGB{
    public:
    unsigned int r,g,b;
};

RGB Imagem[1000][1000];

unsigned int Largura, Altura;


// Utilize esta matriz 3D para realizar a contagem das cores
// Lembre-se de zerar a matriz antes de iniciar.
unsigned int ContadoresRGB[255][255][255];

void SalvaPPM(const char *nome)
{
    int x,y;

    ofstream arquivo;

    arquivo.open(nome, ios::out);


    arquivo << "P3" << endl;
    arquivo << Largura << " " << Altura << endl;
    arquivo << 255 << endl;
    for(y=Altura-1; y>=0; y--)
    {
        for(x=0; x<Largura; x++)
        {
            arquivo << " " <<  Imagem[y][x].r << " " <<  Imagem[y][x].g << " " << Imagem[y][x].b;

        }
        arquivo << endl;
    }
}

void CarregaPPM(const char *nome)
{
    int x,y;

    string dummy;

    ifstream arquivo;

    arquivo.open(nome, ios::in);
    if (!arquivo)
    {
        cout << "Arquivo inexistente." << endl;
        exit (1);
    }


    arquivo >> dummy;

    if (dummy != "P3")
    {
        cout << "Formato Invalido" << endl;
        exit (1);
    }
    arquivo >> Largura;
    if ((Largura < 0) || (Largura>900))
    {
        cout << "Largura Invalida" << endl;
        exit (2);
    }
    arquivo >> Altura;
    if ((Altura < 0) || (Altura>900))
    {
        cout << "Altura Invalida" << endl;
        exit (3);
    }

    arquivo >> dummy;
    if (dummy != "255")
    {
        cout << "Formato Invalido" << endl;
        exit (4);
    }
    for(y=Altura-1; y>=0; y--)
    {
        for(x=0; x<Largura; x++)
        {
            arquivo >> Imagem[y][x].r >> Imagem[y][x].g >> Imagem[y][x].b;
        }
    }
}


int main(int argc, const char * argv[]) {

    CarregaPPM("Colegio.ppm");
    SalvaPPM("Copia-Colegio.ppm");
    return 0;
}