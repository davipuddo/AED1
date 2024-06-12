//853355

#include "../puddo.hpp"
#include "../io.hpp"

class cell
{
    private:
    public:

    int data;
    cell* link;

    cell (int value, cell* ptr)
    {
        this->data = value;
        this->link = ptr;
    }

    int getData()
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

    void PushBack()
    {
        
    }
};

typedef cell* ref_cell;

int main (void)
{
    println ("celula");
    ref_cell a = null;
    ref_cell back = a;

    ref_cell b = new cell (1, null);

    a = b;
    back = a;

    b = new cell (2, null);

    back->link = b;
    back = b;

    b = new cell (3, null);

    back->link = b;
    back = b;

    ref_cell tmp = a;
    while (b)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->link;
    }
    
    pause("Aperte <ENTER> para sair. ");
    return (0);
}