//853355

#include "../puddo.hpp"
#include "../io.hpp"

template <typename T>
class cell
{
    private:
    public:

    T data;
    cell* link;

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
                link->data = 0;
                link = null;
            }
        }
    }

    void PushFront (T value)
    {
        link = new cell<T> (data, link);
        data = value;
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
                link->data = 0;
                link = null;
            }
        }
    }
};

typedef cell<int >* ref_int_cell ;
typedef cell<char>* ref_char_cell;

void m_01 (void)
{
    println ("\ncelula inteira");
    ref_int_cell a = null;
    ref_int_cell back = null;

    ref_int_cell b = new cell<int> (1, null);

    a = b;
    back = a;

    for (int i = 2; i < 7; i++)
    {
        b = new cell<int> (i, null);

        back->link = b;
        back = b;
    }
    a->print();

    a->free();
    a = null;
    back = null;
    b = null;

    pause("Aperte <ENTER> para sair. ");
}

void m_02 (void)
{
    println ("\ncelula de caracteres");
    ref_char_cell a = null;
    ref_char_cell back = null;

    ref_char_cell b = new cell<char>('#', null);

    a = b;
    back = a;

    for (int i = 0; i < 5; i++)
    {
        b = new cell<char>(ReadChar(""), null);

        back->link = b;
        back = b;
    }
    std::cout << std::endl;
    a->print();

    a->PushBack('@');
    a->print();
    a->PushFront('@');
    a->print();
    a->PopFront();
    a->print();

    a->free();
    a = null;
    b = null;
    back = null;

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