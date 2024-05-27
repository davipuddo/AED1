
class Contato
{
    private:
    std::string name;
    Array <int> phone;
    
    public:

    ~Contato()
    {}

    Contato ()
    {
        name   = "";
        phone.init(2);
    }

    int GetPhone(int n)
    {
        int tmp = 0;
        if (this->CheckPhone(n))
        {
            tmp = phone.get(n);
        }
        return (tmp);
    }

    void SetPhone(int data, int n)
    {
        phone.set(n, data);
        if (!this->CheckPhone(n))
        {
            println ("ERRO: Telefone invalido. ");
            phone.set(n, 999999999);
        }
    }

    bool CheckPhone(int n)
    {
        bool result = false;
        int tmp = phone.get(n);
        if (tmp >= 100000000 && tmp <= 999999999)
        {
            result = true;
        }
        return (result);
    }

    std::string GetName()
    {
        return(name);
    }

    void SetName(std::string x)
    {
        name = x;
    }

    bool CheckName()
    {
        bool result = true;
        int x = 0;
        int size = name.length();
        while (x < size && result)
        {
            result = ( (name[x] >= 'a' && name[x] <= 'z') || (name[x] >= 'A' && name[x] <= 'Z'));
            x++;
        }
        return (result);
    }

    void print()
    {
        std::cout << "Name: " << name << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cout << "Telefone " << (i+1) << ": " << phone[i] << std::endl; 
        }
    }

    void fwrite(std::string fileName)
    {
        std::ofstream file;
        file.open(fileName);
        if (!this->CheckName())
        {
            println ("ERRO: Nome invalido. ");
        }
        else
        {
            std::cout << name << std::endl;
            file << name << std::endl;
        }
        for (int i = 0; i < 2; i++)
        {
            if (!this->CheckPhone(i))
            {
                println ("ERRO: Telefone invalido. ");
            }
            else
            {
                file << phone[i] << std::endl;
            }
        }
        file.close();
    }

    void fread(std::string fileName)
    {
        std::ifstream file;
        file.open(fileName);
        file >> name;
        if (!this->CheckName())
        {
            println ("ERRO: Nome invalido. ");
            name = "";
        }
        for (int i = 0; i < 2; i++)
        {
            file >> phone[i];
            if (!this->CheckPhone(1))
            {
                println ("ERRO: Telefone invalido. ");
                phone[i] = 999999999;
            }
        }
        file.close();
    }

};