class Contato
{
    private:
    std::string name;
    std::string phone1;
    std::string phone2;

    public:

    ~Contato()
    {}

    Contato ()
    {
        name   = "";
        phone1 = "";
        phone2 = "";
    }

    std::string GetPhone(int x)
    {
        std::string tmp = "";
        if (x == 1)
        {
            tmp = phone1;
        }
        else if (x == 2)
        {
            tmp = phone2;
        }
        else
        {
            println ("ERRO: Telefone invalido. ");
        }
        return(tmp);
    }

    void SetPhone1(std::string data, int x)
    {
        std::string tmp = "";
        if (x == 1)
        {
            phone1 = data;
        }
        else if (x == 2)
        {
            phone2 = data;
        }
        else
        {
            println ("ERRO: Telefone invalido. ");
        }
    }

    bool CheckPhone(int x)
    {
        bool result = false;
        int i = 0;
        if(x == 1)
        {
            int size = phone1.length();
            if (size > 8 && size < 11)
            {
                result = true;
                while (i < size && result)
                {   
                    if (i == 5)
                    {
                        result = (phone1[i] == '-');
                    }
                    else
                    {
                        result = (result && phone1[i] >= '0' && phone1[i] <= '9');
                    }
                    i++;
                }
            }
        }
        else if (x == 2)
        {
            int size = phone2.length();
            if (size > 8 && size < 11)
            {
                result = true;
                while (i < size && result)
                {   
                    if (i == 5)
                    {
                        result = (phone2[i] == '-');
                    }
                    else
                    {
                        result = (result && phone2[i] >= '0' && phone2[i] <= '9');
                    }
                    i++;
                }
            }
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
        std::cout << "Phone1: " << phone1 << std::endl;
        std::cout << "Phone2: " << phone2 << std::endl;
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
        if (!this->CheckPhone(1))
        {
            println ("ERRO: Telefone invalido. ");
        }
        else
        {
            file << phone1 << std::endl;
        }
        if (!this->CheckPhone(2))
        {
            println ("ERRO: Telefone invalido. ");
        }
        else
        {
            file << phone2 << std::endl;
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
        file >> phone1;
        if (!this->CheckPhone(1))
        {
            println ("ERRO: Telefone invalido. ");
            phone1 = "";
        }
        file >> phone2;
        if (!this->CheckPhone(2))
        {
            println ("ERRO: Telefone invalido. ");
            phone2 = "";
        }
        file.close();
    }

};