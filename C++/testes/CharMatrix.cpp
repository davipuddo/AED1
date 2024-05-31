
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
    std::string str = "";
    std::string result = "";
    std::string t = "12";
    std::string t2 = "12";
    std::getline(std::cin, str);

    std::ofstream file;
    file.open("TESTE.TXT");
    file << "1234" << std::endl;
    file << str << std::endl;
    file << "4321" << std::endl;

    file.close();

    std::ifstream file2;
    file2.open ("TESTE.TXT");

    file2 >> result;
    std::getline(file2, t);
    std::getline(file2, t);
    file2 >> t2;
    std::cout << "r: " << result << std::endl;
    std::cout << "t: [" << t << "]" << std::endl;
    std::cout << "t2: [" << t2 << "]" << std::endl;
    file2.close();

    pause("Aperte <ENTER>");
    return(0);
}