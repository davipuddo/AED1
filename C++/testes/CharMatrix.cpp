
#include "../puddo.hpp"

class Contatos
{
    private:
    std::string name;
    Array <std::string> telefone;
    int telefones;

    public:
    Contatos ()
    {
        name = "";
        telefone.init(1);
        telefone.set(0, "99999-9999");
        telefones = 1;
    }

    void SetTel (int n, std::string valor)
    {
        telefone.set(n, valor);
    }

    void SetName (std::string valor)
    {
        name = valor;
    }

    void AddTel (int n)
    {
        Array <std::string> tmp(telefone);
        telefones += n;
        telefone.init(telefones);

        int size = tmp.getlength();
        for (int i = 0; i < size; i++)
        {
            telefone.set(i, tmp.get(i));
        }

        for (int i = size; i < telefones; i++)
        {
            telefone.set(i, "99999-9999");
        }
    }

    void print ()
    {
        std::cout << std::endl << "Nome: " << name << std::endl;
        for (int i = 0; i < telefones; i++)
        {
            std::cout << "Telefone " << (i+1) << ": " << telefone.get(i) << std::endl;  
        }
    }
};


int main (void)
{
    Contatos pessoa1;
    pessoa1.SetTel(0, "12345");
    pessoa1.AddTel(2);
    pessoa1.SetTel(1, "54321");
    pessoa1.print();
    pause("Aperte <ENTER>");
    return(0);
}