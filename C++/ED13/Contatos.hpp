
class Contato
{
    private:
    std::string name;
    Matrix <std::string> phone;
    int phones;
    
    public:

    ~Contato()
    {}

    Contato ()
    {
        name   = "";
        phones = 1;
        phone.init(phones, 1);
        for (int i = 0; i < phone.getrows(); i++)
        {
            phone.set(i, 0, "99999-9999");
        }
    }

    void AddPhone (int x)
    {
        Matrix <std::string> tmp(0, 0);
        tmp.copy(phone);

        phones += x;
        phone.init(phones, 1);

        // Copiar dados antigos
        int r = tmp.getrows();
        for (int x = 0; x < r; x++)
        {
            phone.set(x, 0, tmp.get(x, 0));
        }
        tmp.free();

        // Inicializar dados novos
        for (int x = r; x < phones; x++)
        {
            phone.set(x, 0, "99999-9999");
        }
    }

    int GetPhones()
    {
        return (phones);
    }

    std::string GetPhone(int n)
    {
        std::string tmp = "";
        if (!this->CheckPhone(n))
        {
            println ("ERRO: Telefone invalido. ");
        }
        else
        {
            tmp = phone.get(n, 0);
        }
        return (tmp);
    }

    bool CheckPhone(int n)
    {
        bool result = true;
        std::string tmp = phone.get(n, 0);
        int size = tmp.length();
        int i = 0;
        if (size < 9 || size > 11)
        {
            result = false;
        }
        else
        {
            int h = size - 5;
            while (i < size && result)
            {
                if (i == h)
                {
                    result = (tmp[i] == '-');
                }  
                else
                {
                    result = (result && (tmp[i] >= '0' && tmp[i] <= '9'));
                }
                i++;
            }
        }
        return (result);
    }

    void SetPhone(std::string data, int n)
    {
        if (n > (phones-1))
        {
            std::cout << std::endl << "AVISO: O numero de telefones do contato e insuficiente." << std::endl;
            std::cout << "Serao adicionados [" << n << "] numeros de telefone ao contato. " << std::endl;
            this->AddPhone(n);
        }
        phone.set(n, 0, data);
        if (!this->CheckPhone(n))
        {
            println ("\nERRO: Telefone invalido. ");
            phone.set(n, 0, "99999-9999");
        }
    }

    std::string GetName()
    {
        return(name);
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

    void SetName(std::string x)
    {
        name = x;
        if (!this->CheckName())
        {
            println ("ERRO: Nome invalido. ");
        }
    }

    bool IsValid ()
    {
        bool result = false;

        result = CheckName();

        int i = 0;
        while (i < phone.getrows() && result)
        {
            result = this->CheckPhone(i);
            i++;
        }
        return (result);
    }


    void print()
    {
        std::cout << std::endl << "Nome: " << name << std::endl;
        for (int i = 0; i < phones; i++)
        {
            std::string tmp = phone.get(i, 0);
            std::cout << "Telefone " << (i+1) << ": " << tmp << std::endl; 
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
        for (int i = 0; i < phones; i++)
        {
            if (!this->CheckPhone(i))
            {
                println ("ERRO: Telefone invalido. ");
            }
            else
            {
                file << phone.get(i, 0) << std::endl;
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
        for (int i = 0; i < phones; i++)
        {
            std::string tmp = "";
            file >> tmp;
            phone.set(i, 0, tmp);
            if (!this->CheckPhone(i))
            {
                println ("ERRO: Telefone invalido. ");
                phone.set(i, 0, "99999-9999");
            }
        }
        file.close();
    }

};