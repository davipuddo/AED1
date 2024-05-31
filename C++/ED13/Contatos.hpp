
class Contato
{
    private:
    std::string name;               // Nome
    Array <std::string> phone;      // Telefones
    int phones;                     // Quantidade de telefones
    Matrix <std::string> adress;    // Enderecos
    int adressX;                    // Quantidade de tipos de endereco
    int adressY;                    // Quantidade de enderecos para cada tipo
    
    public:

    /**
     * Destrutor
    */
    ~Contato()
    {}

    /**
     * Construtor
    */
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
                adress.set(x, y, "N/A");
            }
        }
    }

    /** 
     * @returns Quantidade de tipos de endereco
    */
    int GetAdressX (void)
    {
        return (adressX);
    }

    /**
     * @returns Quantidade de enderecos do contato para cada tipo 
    */
    int GetAdressY (void)
    {
        return (adressY);
    }

    /** @returns Quantidade de telefones do contato
     * 
    */
    int GetPhones(void)
    {
        return (phones);
    }

    /** Adiciona [n] telefones ao contato
     *  @param Numero de telefones a serem adicionados
    */
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

        //tmp.free();  <--- Nao funciona

        // Inicializar dados novos
        for (int x = r; x < phones; x++)
        {
            phone.set(x, "99999-9999");
        }
    }
    
    /** Verifica se um telefone e valido
     *  @param Posicao do telefone no array
     *  @returns Valor booleano referente a verificacao
    */
    bool CheckPhone(int n)
    {
        bool result = true;
        std::string tmp = phone.get(n);
        int size = phones;
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

    /** Retornar telefone
     *  @param Posicao do telefone no array
     *  @example [Telefone1.GetPhone(0) || Telefone2.GetPhone(1)] 
     *  @returns Numero de telefone do objeto
    */
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

    /** Guardar um numero de telefone no objeto
     *  @param Posicao do telefone no array
     *  @param Dados do telefone
    */
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
        }
    }

    /** 
     * @returns Nome do objeto
    */
    std::string GetName()
    {
        return(name);
    }

    /** Verificar se o nome do objeto e valido
     *  @returns Valor booleano referente a verificacao
    */
    bool CheckName()
    {
        bool result = false;
        if (name != "" && name != " ")
        {
            result = true;
            int i = 0;
            int size = name.length();
            while (i < size)
            {
                result = ( result && ((name[i] >= 'a' && name[i] <= 'z') ||  
                                      (name[i] >= 'A' && name[i] <= 'Z') ||
                                       name[i] == ' '));
                i++;
            }
        }
        return (result);
    }

    /** Definir o nome do objeto
     *  @param Nome
    */
    void SetName(std::string data)
    {
        name = data;
        if (!this->CheckName())
        {
            println ("ERRO: Nome invalido. ");
        }
    }

    /**  
     * @param Tipo de endereco
     * @param Posicao do endereco
     * @returns Endereco do objeto na posicao fornecida
    */
    std::string GetAdress(int n, int x)
    {
        return (adress.get(n, x));
    }

    /** Verificar se um endereco e valido
     *  @param Tipo de endereco
     *  @param Posicao do endereco
     *  @returns Valor booleano referente a verificacao
    */
    bool CheckAdress(int x, int y)
    {
        bool result = true;
        result = (result && adress.get(x, y) != "");
        if (!result)
        {
            println ("ERRO: Endereco invalido. ");
        }
        return (result);
    }

    /** Adicionar [n] enderecos ao objeto
     *  @param Quantidade de enderecos a serem adicionados
     *  @note Essa quantidade sera adicionada para todos os tipos de endereco
    */
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

    /** Definir dados de um endereco
     *  @param Tipo de endereco
     *  @param Posicao do endereco
     *  @param Dados do endereco
    */
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
 
    /** Verificar se todos os elementos do objeto sao validos
     *  @returns Valor booleano referente a verificacao
    */
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

    /** Mostrar todos os elementos do objeto
     * 
    */
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

    /** Gravar dados do objeto em um arquivo
     *  @param Nome do arquivo
    */
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

    /** Ler dados de um objeto de um arquivo
     *  @param Nome do arquivo
    */
    void fread(std::string fileName)
    {
        std::fstream file;
        int Nnum = 0;
        int Pnum = 0;
        int AXnum = 0;
        int AYnum = 0;
        
        file.open(fileName, std::ios::in);

        file >> Nnum;
        file >> Pnum;
        file >> AXnum;
        file >> AYnum;

        this->phone.init (Pnum);
        this->adress.init(AXnum, AYnum);
                                        
                                        // Aparentemente existe algum tipo de problema ao usar [getline]
        std::getline(file, name);       // apos o uso de [>>] em um arquivo. A solucao atual e o uso de
        std::getline(file, name);       // duas leituras com [getline] 
        if (!this->CheckName())         
        {
            println ("ERRO: Nome invalido. ");
            name = "";
        }

        phones = Pnum;
        std::string tmp = "";
        for (int i = 0; i < Pnum; i++)
        {
            std::getline(file, tmp);
            phone.set(i, tmp);
            if (!this->CheckPhone(i))
            {
                println ("ERRO: Telefone invalido. ");
                phone.set(i, "99999-9999");
            }
        }
        adressX = AXnum;
        adressY = AYnum;
        tmp = "";
        for (int x = 0; x < AXnum; x++)
        {
            for (int y = 0; y < AYnum; y++)
            {
                std::getline(file, tmp);
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