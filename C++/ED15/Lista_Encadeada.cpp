/**
 * @author Davi Ferreira Puddo
 */

#include "../puddo.hpp"
#include "../io.hpp"

/* template <typename T>
class Cell
{
    private:

    T data;
    Cell* link;

    public:

    // Constructor
    Cell (T value, Cell* ptr)
    {
        this->data = value;
        this->link = ptr;
    }

    // Return Cell data
    T getData()
    {
        return (data);
    }

    // Set Cell data
    void setData(T x)
    {
        data = x;
    }

    // Return Cell link
    Cell* getLink()
    {
        return (link);
    }

    // Set Cell link
    void setLink (Cell* x)
    {
        link = x;
    }

    // Show all linked Cells from origin data
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

    // Set all linked Cells from origin to 0 and desconnect them
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

    // Add Cell to the end
    void PushBack (T value)
    {
        if (link)
        {
            link->PushBack(value);
        }
        else
        {
            link = new Cell<T> (value, null);
        }
    }

    // Add [n] Cells to the end
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

    // Remove last Cell
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

    // Add Cell to the start
    void PushFront (T value)
    {
        link = new Cell<T> (data, link);
        data = value;
    }

    // Remove first Cell
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

    // Return the number of Cells
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

    // Add Cell in the middle
    void PushMid (T value)
    {
        Cell *ptr = null;
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
            Cell *b = new Cell<T>(value, ptr->link);
            ptr->link = b;
        }
    }

    // Remove middle Cell
    void PopMid ()
    {
        Cell *ptr = null;
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
        Cell *ptr = null;
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
        Cell *ptr = null;
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

    Cell* find (T value)
    {
        Cell *ptr = null;
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

typedef Cell<int >* ref_int_Cell ;
typedef Cell<char>* ref_char_Cell;

void m_01 (void)
{
    println ("\nInt Cell");

    Cell<int> a(0, null);

    a.AddCells(7);
    a.print();
    a.free();

    pause("Press <ENTER> to exit. ");
}

void m_02 (void)
{
    println ("\nChar Cell");

    // Create first Cell
    ref_char_Cell a = new Cell<char>('0', null);

    // Create inicial data
    a->AddCells(3);
    a->WriteCells();
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

    ref_char_Cell f = a->find('2');
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