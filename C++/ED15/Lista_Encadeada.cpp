//853355

#include "../puddo.hpp"
#include "../io.hpp"

template <typename T>
class cell
{
    private:

    T data;
    cell* link;

    public:


    // Constructor
    cell (T value, cell* ptr)
    {
        this->data = value;
        this->link = ptr;
    }

    T getData()
    {
        return (data);
    }

    void setData(int x)
    {
        data = x;
    }

    cell* getLink()
    {
        return (link);
    }

    void setLink (cell* x)
    {
        link = x;
    }

    void print ()
    {
        std::cout << data << std::endl;
        if (link)
        {
            this->link->print();
        }
        else
        {
            std::cout << std::endl;
        }
    }

    void free ()
    {
        if (link)
        {
            this->link->free();
        }
        std::cout << "removed: " << this->data << std::endl;
        this->data = 0;
        this->link = null;
    }

    void PushBack (T value)
    {
        if (link)
        {
            link->PushBack(value);
        }
        else
        {
            link = new cell<T> (value, null);
            std::cout << "added: " << link->data << std::endl;
        }
    }

    void PopBack ()
    {
        if (link)
        {
            if (link->link)
            {
                link->PopBack();
            }
            else
            {
                std::cout << "removed: " << link->data << std::endl;
                link->data = 0;
                link = null;
            }
        }
    }

    void PushFront (T value)
    {
        link = new cell<T> (data, link);
        data = value;
        std::cout << "added: " << data << std::endl;
    }

    void PopFront ()
    {
        if (link)
        {
            data = link->data;
            if (link->link)
            {
                link->PopFront();
            }
            else
            {
                std::cout << "removed: " << link->data << std::endl;
                link->data = 0;
                link = null;
            }
        }
    }

    int Count (int x)
    {
        x++;
        if (link)
        {
            return this->link->Count(x);
        }
        else
        {
            return (x);
        }
    }

    void PushMid (int value)
    {
        cell *ptr = null;
        if (link)
        {
            int c = this->Count(0);
            int mid = ((double)c / 2.0);
            ptr = this;
            
            int w = (mid-2);
            for (int i = 0; i < w; i++)
            {
                ptr = ptr->link;
            }
            cell *b = new cell<T>(value, ptr->link->link);
            ptr->link->link = b;
            std::cout << "added: " << link->link->data << std::endl;
        }
    }

    void PopMid ()
    {
        cell *ptr = null;
        if (link)
        {
            int c = this->Count(0);
            int mid = ((double)c / 2.0);
            ptr = this;
            
            int w = (mid-1);
            for (int i = 0; i < w; i++)
            {
                ptr = ptr->link;
            }
            std::cout << "removed: " << ptr->link->data << std::endl;
            ptr->link->data = 0;
            ptr->link = ptr->link->link; 
        }
    }
};

typedef cell<int >* ref_int_cell ;
typedef cell<char>* ref_char_cell;

void m_01 (void)
{
    println ("\ncelula inteira");

    ref_int_cell a = new cell<int> (1, null);

    for (int i = 2; i < 7; i++)
    {
        a->PushBack(i);
    }

    a->print();

    a->free();
    a = null;

    pause("Aperte <ENTER> para sair. ");
}

void m_02 (void)
{
    println ("\ncelula de caracteres");

    ref_char_cell a = new cell<char>('#', null);

    // Criar dados iniciais
    for (int i = 0; i < 3; i++)
    {
        a->PushBack(ReadChar(""));
    } 
    println ("");   // Pular uma linha

    // Mostrar todos os dados
    a->print();

    // Adicionar um dado ao final
    a->PushBack('@');
    a->print();

    // Adicionar um dado ao inicio
    a->PushFront('@');
    a->print();

    // Remover primeiro dado
    a->PopFront();
    a->print();

    // Remover ultino dado
    a->PopBack();
    a->print();

    // Adicionar dado ao meio
    a->PushMid('@');
    a->print();

    // Remover dado do meio
    a->PopMid();
    a->print();

    // Liberar dados
    a->free();
    a = null;

    pause("Aperte <ENTER> para sair. ");
}

int main (void)
{
    int x = 0;
    do
    {

        println ("1 - m_01   2 - m_02\n");
        x = ReadInt("x : ");

        switch (x)
        {
            case 0:
              break;
            case 1: m_01();
              break;
            case 2: m_02();
              break;
            default: println("Opcao invalida.");
              break;
        }
    } while (x != 0);

    pause("Aperte <ENTER> para sair. ");
    return (0);
}