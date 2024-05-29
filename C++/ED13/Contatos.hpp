
class Contato
{
    private:
    std::string name;
    Array <std::string> phone;
    int phones;
    Matrix <std::string> adress;
    int adressX;
    int adressY;
    
    public:

    ~Contato()
    {}

    Contato ()
    {
        name   = "";

        phones = 1;
        phone.init(phones);
        for (int i = 0; i < phones; i++)
        {
            phone.set(i, "99999-9999");
        }

        adressX = 2;
        adressY = 1;
        adress.init(adressX, adressY);
        for (int x = 0; x < adressX; x++)
        {
            for (int y = 0; y < adressY; y++)
            {
                adress.set(x, y, "");
            }
        }
    }

    int GetAdressX (void)
    {
        return (adressX);
    }

    int GetAdressY (void)
    {
        return (adressY);
    }

    int GetPhones(void)
    {
        return (phones);
    }

    void AddPhone (int x)
    {
        Array <std::string> tmp(phone);

        phones += x;
        phone.init(phones);

        // Copiar dados antigos
        int r = tmp.getlength();
        for (int x = 0; x < r; x++)
        {
            phone.set(x, tmp.get(x));
        }
        //tmp.free();

        // Inicializar dados novos
        for (int x = r; x < phones; x++)
        {
            phone.set(x, "99999-9999");
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
            tmp = phone.get(n);
        }
        return (tmp);
    }

    bool CheckPhone(int n)
    {
        bool result = true;
        std::string tmp = phone.get(n);
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

    void SetPhone(int n, std::string data)
    {
        if (n > (phones-1))
        {
            std::cout << std::endl << "AVISO: O numero de telefones do contato e insuficiente." << std::endl;
            std::cout << "Serao adicionados [" << n << "] numeros de telefone ao contato. " << std::endl;
            int tmp = (n+1) - phones;
            this->AddPhone(tmp);
        }
        phone.set(n, data);
        if (!this->CheckPhone(n))
        {
            println ("\nERRO: Telefone invalido. ");
            phone.set(n, "99999-9999");
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
            name = "";
        }
    }

    std::string GetAdress(int n, int x)
    {
        return (adress.get(n, x));
    }

    bool CheckAdress(int x, int y)
    {
        bool result = true;
        result = (result && adress.get(x, y) != "");
        return (result);
    }

    void AddAdress(int n)
    {
        Matrix <std::string> tmp(0, 0);
        tmp.copy(adress);

        adress.init(adressX, n+adressY);
        adressY = adress.getcolumns();

        for (int x = 0; x < adressX; x++)
        {
            for (int y = 0; y < adressY; y++)
            {
                adress.set(x, y, "N/A");
            }
        }

        int tx = tmp.getrows();
        int ty = tmp.getcolumns();
        for (int x = 0; x < tx; x++)
        {
            for (int y = 0; y < ty; y++)
            {   
                adress.set(x, y, tmp.get(x, y));
            }   
        }
    }

    void SetAdress(int x, int y, std::string value)
    {
        if (x > 2)
        {
            println ("ERRO: Posicao invalida. ");
        }
        else
        {
            if (y > (adressY-1))
            {
                int tmp = (y+1) - adressY;
                std::cout << std::endl << "AVISO: O numero de enderecos do contato e insuficiente." << std::endl;
                std::cout << "Serao adicionados [" << tmp << "] enderecos ao contato. " << std::endl;
                AddAdress(tmp);
            }
            adress.set(x, y, value);
            if (!this->CheckAdress(x, y))
            {
                println ("ERRO: Dados invalidos. ");
                adress.set(x, y, "");
            }
        }
    }

    bool IsValid ()
    {
        bool result = false;

        result = CheckName();

        int i = 0;
        while (i < phones && result)
        {
            result = this->CheckPhone(i);
            i++;
        }

        i = 0;
        int y = 0;
        while (result && i < adressX)
        {
            while (result && y < adressY)
            {
                result = this->CheckAdress(i, y);
                y++;
            }
            i++;
        }
        return (result);
    }

    void print()
    {
        std::cout << std::endl << "Nome: " << name << std::endl;
        for (int i = 0; i < phones; i++)
        {
            std::string tmp = phone.get(i);
            std::cout << "Telefone " << (i+1) << ": " << tmp << std::endl; 
        }
        for (int x = 0; x < adressX; x++)
        {
            for (int y = 0; y < adressY; y++)
            {
                std::string tmp = adress.get(x, y);
                if (x == 0)
                {
                    std::cout << "Endereco Residencial " << (y+1) << ": " << tmp << std::endl;
                }
                else if (x == 1)
                {
                    std::cout << "Endereco Profissional " << (y+1) << ": " << tmp << std::endl;
                }
            } 
        }
    }

    void fwrite(std::string fileName)
    {
        std::ofstream file;
        file.open(fileName);
        if (!this->IsValid())
        {
            println ("ERRO: Dados invalidos. ");
        }
        else
        {
            // Dados
            file << 1 << std::endl;
            file << phones << std::endl;
            file << adressX << std::endl << adressY << std::endl;

            // Nome
            file << name << std::endl;

            // Telefone
            for (int i = 0; i < phones; i++)
            {
                file << phone.get(i) << std::endl;
            }

            // Endereco
            for (int x = 0; x < adressX; x++)
            {
                for (int y = 0; y < adressY; y++)
                {
                    file << adress.get(x, y) << std::endl;
                }
            }
        }
        file.close();
    }

    void fread(std::string fileName)
    {
        std::ifstream file;
        int Nnum = 0;
        int Pnum = 0;
        int AXnum = 0;
        int AYnum = 0;
        
        file.open(fileName);
        
        file >> Nnum;
        file >> Pnum;
        file >> AXnum;
        file >> AYnum;

        this->phone.init(Pnum);
        this->adress.init(AXnum, AYnum);

        file >> name;
        if (!this->CheckName())
        {
            println ("ERRO: Nome invalido. ");
            name = "";
        }
        for (int i = 0; i < Pnum; i++)
        {
            std::string tmp = "";
            file >> tmp;
            phone.set(i, tmp);
            if (!this->CheckPhone(i))
            {
                println ("ERRO: Telefone invalido. ");
                phone.set(i, "99999-9999");
            }
        }
        for (int x = 0; x < AXnum; x++)
        {
            for (int y = 0; y < AYnum; y++)
            {
                std::string tmp = "";
                file >> tmp;
                adress.set(x, y, tmp);
                if (!this->CheckAdress(x, y))
                {
                    println ("ERRO: Endereco invalido. ");
                    adress.set(x, y, "");
                }
            }
        }
        file.close();
    }

};