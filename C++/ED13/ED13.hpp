
class Contato
{
    private:
    std::string name;
    Matrix <std::string> phone;
    
    public:

    ~Contato()
    {}

    Contato ()
    {
        name   = "";
        phone.init(2,1);
        for (int i = 0; i < phone.getrows(); i++)
        {
            phone.set(i, 0, "99999-9999");
        }
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
            while (i < size && result)
            {
                if (i == 5)
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
        phone.set(n, 0, data);
        if (!this->CheckPhone(n))
        {
            println ("ERRO: Telefone invalido. ");
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
        for (int i = 0; i < 2; i++)
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
        for (int i = 0; i < 2; i++)
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
        for (int i = 0; i < 2; i++)
        {
            std::string tmp = "";
            file >> tmp;
            phone.set(i, 0, tmp);
            if (!this->CheckPhone(1))
            {
                println ("ERRO: Telefone invalido. ");
                phone.set(i, 0, "99999-9999");
            }
        }
        file.close();
    }

};