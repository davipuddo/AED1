/**
 * @author Davi Ferreira Puddo
 */

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

    // Return cell data
    T getData()
    {
        return (data);
    }

    // Set cell data
    void setData(T x)
    {
        data = x;
    }

    // Return cell link
    cell* getLink()
    {
        return (link);
    }

    // Set cell link
    void setLink (cell* x)
    {
        link = x;
    }

    // Show all linked cells from origin data
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

    // Set all linked cells from origin to 0 and desconnect them
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

    // Add cell to the end
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

    // Remove last cell
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

    // Add cell to the start
    void PushFront (T value)
    {
        link = new cell<T> (data, link);
        data = value;
        std::cout << "added: " << data << std::endl;
    }

    // Remove first cell
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

    // Return the number of cells
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

    // Add cell in the middle
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

    // Remove middle cell
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

    // Add [n] cells to the end
    void AddCells (int n)
    {
        if (link)
        {
            link->AddCells(n);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                this->PushBack(ReadT<T>(""));
            }
            std::cout << std::endl;
        }
    }

};

typedef cell<int >* ref_int_cell ;
typedef cell<char>* ref_char_cell;

void m_01 (void)
{
    println ("\nInt cell");

    ref_int_cell a = new cell<int> (1, null);

    for (int i = 2; i < 7; i++)
    {
        a->PushBack(i);
    }

    a->print();

    a->free();
    a = null;

    pause("Press <ENTER> to exit. ");
}

void m_02 (void)
{
    println ("\nChar cell");

    // Create first cell
    ref_char_cell a = new cell<char>('#', null);

    // Create inicial data
    a->AddCells(3);
    println ("");

    // Change data
    a->print();

    a->PushBack('@');
    a->print();

    a->PushFront('@');
    a->print();

    a->PopFront();
    a->print();

    a->PopBack();
    a->print();

    a->PushMid('@');
    a->print();

    a->PopMid();
    a->print();

    // Free data
    a->free();
    a = null;

    pause("Press <ENTER> to exit");
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