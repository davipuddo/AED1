/**
 * @author Davi Ferreira Puddo
 */

#include "../puddo.hpp"
#include "../io.hpp"

/* template <typename T>
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
                std::cout << "Forneca elementos para a celula [" << n-i << "]: ";
                this->PushBack(ReadT<T>(" "));
            }
            std::cout << std::endl;
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
    void PushMid (T value)
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
            cell *b = new cell<T>(value, ptr->link);
            ptr->link = b;
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
            ptr->link->data = 0;
            delete (ptr->link);
            ptr->link = ptr->link->link; 
        }
    }

    void insert (T value, int p)
    {
        cell *ptr = null;
        if (link)
        {
            if (this->Count(0) < p)
            {
                println ("ERROR: Invalid position. ");
            }
            else
            {
                ptr = this;
                for (int i = 0; i < p; i++)
                {
                    ptr = ptr->link;
                }
                ptr->PushFront(value);
            }
        }
    }

    void remove (int p)
    {
        cell *ptr = null;
        if (link)
        {
            if (this->Count(0) < p)
            {
                println ("ERROR: Invalid position. ");
            }
            else
            {
                ptr = this;
                for (int i = 0; i < p; i++)
                {
                    ptr = ptr->link;
                }
                ptr->PopFront();
            }
        }
    }

    cell* find (T value)
    {
        cell *ptr = null;
        if (data == value)
        {
            ptr = this;
        }
        else if (link)
        {
            ptr = this;
            int c = Count(0);
            int i = 0;
            while (i < c && ptr->data != value)
            {
                i++;
                ptr = ptr->link;
            }
        }
        return (ptr);
    }

}; */

typedef cell<int >* ref_int_cell ;
typedef cell<char>* ref_char_cell;

void m_01 (void)
{
    println ("\nInt cell");

    cell<int> a(0, null);

    a.AddCells(7);
    a.print();
    a.free();

    pause("Press <ENTER> to exit. ");
}

void m_02 (void)
{
    println ("\nChar cell");

    // Create first cell
    ref_char_cell a = new cell<char>('0', null);

    // Create inicial data
    a->AddCells(3);
    println ("");

    // Change data
    println ("Data: \n");
    a->print();

    println ("PushBack: \n");
    a->PushBack('@');
    a->print();

    println ("PushFront: \n");
    a->PushFront('@');
    a->print();

    println ("PopFront: \n");
    a->PopFront();
    a->print();

    println ("PopBack: \n");
    a->PopBack();
    a->print();

    println ("PushMid: \n");
    a->PushMid('@');
    a->print();

    println ("PopMid: \n");
    a->PopMid();
    a->print();

    println ("Insert (1): \n");
    a->insert('=', 1);
    a->print();

    println ("Remove (1): \n");
    a->remove(1);
    a->print();

    ref_char_cell f = a->find('2');
    if (f == null)
    {
        println ("O valor nao foi encontrado. "); 
    }
    else
    {
        std::cout << "O valor [" << f->getData() << ']' << " foi encontrado. " << std::endl;
    }

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